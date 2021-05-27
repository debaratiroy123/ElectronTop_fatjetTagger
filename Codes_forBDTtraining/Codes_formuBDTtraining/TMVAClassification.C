/// \file
/// \ingroup tutorial_tmva
/// \notebook -nodraw
/// This macro provides examples for the training and testing of the
/// TMVA classifiers.
///
/// As input data is used a toy-MC sample consisting of four Gaussian-distributed
/// and linearly correlated input variables.
/// The methods to be used can be switched on and off by means of booleans, or
/// via the prompt command, for example:
///
///     root -l ./TMVAClassification.C\(\"Fisher,Likelihood\"\)
///
/// (note that the backslashes are mandatory)
/// If no method given, a default set of classifiers is used.
/// The output file "TMVA.root" can be analysed with the use of dedicated
/// macros (simply say: root -l <macro.C>), which can be conveniently
/// invoked through a GUI that will appear at the end of the run of this macro.
/// Launch the GUI via the command:
///
///     root -l ./TMVAGui.C
///
/// You can also compile and run the example with the following commands
///
///     make
///     ./TMVAClassification <Methods>
///
/// where: `<Methods> = "method1 method2"` are the TMVA classifier names
/// example:
///
///     ./TMVAClassification Fisher LikelihoodPCA BDT
///
/// If no method given, a default set is of classifiers is used
///
/// - Project   : TMVA - a ROOT-integrated toolkit for multivariate data analysis
/// - Package   : TMVA
/// - Root Macro: TMVAClassification
///
/// \macro_output
/// \macro_code
/// \author Andreas Hoecker


#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"

#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"
#include "TMVA/TMVAGui.h"

int TMVAClassification( TString myMethodList = "" )
{
   // The explicit loading of the shared libTMVA is done in TMVAlogon.C, defined in .rootrc
   // if you use your private .rootrc, or run from a different directory, please copy the
   // corresponding lines from .rootrc

   // Methods to be processed can be given as an argument; use format:
   //
   //     mylinux~> root -l TMVAClassification.C\(\"myMethod1,myMethod2,myMethod3\"\)

   //---------------------------------------------------------------
   // This loads the library
   TMVA::Tools::Instance();

   // Default MVA methods to be trained + tested
   std::map<std::string,int> Use;

   // Cut optimisation
   Use["Cuts"]            = 0;
   Use["CutsD"]           = 0;
   Use["CutsPCA"]         = 0;
   Use["CutsGA"]          = 0;
   Use["CutsSA"]          = 0;
   //
   // 1-dimensional likelihood ("naive Bayes estimator")
   Use["Likelihood"]      = 0;
   Use["LikelihoodD"]     = 0; // the "D" extension indicates decorrelated input variables (see option strings)
   Use["LikelihoodPCA"]   = 0; // the "PCA" extension indicates PCA-transformed input variables (see option strings)
   Use["LikelihoodKDE"]   = 0;
   Use["LikelihoodMIX"]   = 0;
   //
   // Mutidimensional likelihood and Nearest-Neighbour methods
   Use["PDERS"]           = 0;
   Use["PDERSD"]          = 0;
   Use["PDERSPCA"]        = 0;
   Use["PDEFoam"]         = 0;
   Use["PDEFoamBoost"]    = 0; // uses generalised MVA method boosting
   Use["KNN"]             = 0; // k-nearest neighbour method
   //
   // Linear Discriminant Analysis
   Use["LD"]              = 0; // Linear Discriminant identical to Fisher
   Use["Fisher"]          = 0;
   Use["FisherG"]         = 0;
   Use["BoostedFisher"]   = 0; // uses generalised MVA method boosting
   Use["HMatrix"]         = 0;
   //
   // Function Discriminant analysis
   Use["FDA_GA"]          = 0; // minimisation of user-defined function using Genetics Algorithm
   Use["FDA_SA"]          = 0;
   Use["FDA_MC"]          = 0;
   Use["FDA_MT"]          = 0;
   Use["FDA_GAMT"]        = 0;
   Use["FDA_MCMT"]        = 0;
   //
   // Neural Networks (all are feed-forward Multilayer Perceptrons)
   Use["MLP"]             = 0; // Recommended ANN
   Use["MLPBFGS"]         = 0; // Recommended ANN with optional training method
   Use["MLPBNN"]          = 0; // Recommended ANN with BFGS training method and bayesian regulator
   Use["CFMlpANN"]        = 0; // Depreciated ANN from ALEPH
   Use["TMlpANN"]         = 0; // ROOT's own ANN
   Use["DNN_GPU"]         = 0; // CUDA-accelerated DNN training.
   Use["DNN_CPU"]         = 0; // Multi-core accelerated DNN.
   //
   // Support Vector Machine
   Use["SVM"]             = 0;
   //
   // Boosted Decision Trees
   Use["BDT"]             = 1; // uses Adaptive Boost
   Use["BDTG"]            = 1; // uses Gradient Boost
   Use["BDTB"]            = 0; // uses Bagging
   Use["BDTD"]            = 0; // decorrelation + Adaptive Boost
   Use["BDTF"]            = 0; // allow usage of fisher discriminant for node splitting
   //
   // Friedman's RuleFit method, ie, an optimised series of cuts ("rules")
   Use["RuleFit"]         = 0;
   // ---------------------------------------------------------------

   std::cout << std::endl;
   std::cout << "==> Start TMVAClassification" << std::endl;

   // Select methods (don't look at this code - not of interest)
   if (myMethodList != "") {
      for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

      std::vector<TString> mlist = TMVA::gTools().SplitString( myMethodList, ',' );
      for (UInt_t i=0; i<mlist.size(); i++) {
         std::string regMethod(mlist[i]);

         if (Use.find(regMethod) == Use.end()) {
            std::cout << "Method \"" << regMethod << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
            for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) std::cout << it->first << " ";
            std::cout << std::endl;
            return 1;
         }
         Use[regMethod] = 1;
      }
   }

   // --------------------------------------------------------------------------------------------------

   // Here the preparation phase begins

   // Read training and test data
   // (it is also possible to use ASCII format as input -> see TMVA Users Guide)
   TFile *input(0);
   TString fname;
   
   fname = "testmutop_thadv2_Jan2021Corr_19UL18.root";
   TFile *inputS1 = TFile::Open( fname ); 
   
   fname = "testmutop_tsemilepv2_Jan2021Corr_19UL18.root";
   TFile *inputS2 = TFile::Open( fname );

   fname = "testmutop_tdilepv2_Jan2021Corr_19UL18.root";
   TFile *inputS3 = TFile::Open( fname );

   fname = "testmutop_bqcd100to200lepv2_Jan2021.root";
   TFile *inputB1 = TFile::Open( fname );

   fname = "testmutop_bqcd200to300lepv2_Jan2021.root";
   TFile *inputB2 = TFile::Open( fname );

   fname = "testmutop_bqcd300to500lepv2_Jan2021.root";   
   TFile *inputB3 = TFile::Open( fname );

   fname = "testmutop_bqcd500to700lepv2_Jan2021.root";   
   TFile *inputB4 = TFile::Open( fname );

   fname = "testmutop_bqcd700to1000lepv2_Jan2021.root";
   TFile *inputB5 = TFile::Open( fname );

   fname = "testmutop_bqcd1000to1500lepv2_Jan2021.root";   
   TFile *inputB6 = TFile::Open( fname );

   fname = "testmutop_bqcd1500to2000lepv2_Jan2021.root";   
   TFile *inputB7 = TFile::Open( fname );

   fname = "testmutop_bqcd2000toInflepv2_Jan2021.root";
   TFile *inputB8 = TFile::Open( fname );

   /*
     if (!gSystem->AccessPathName( fname )) {
     input = TFile::Open( fname ); // check if file in local directory exists
     }
     else {
     TFile::SetCacheFileDir(".");
     input = TFile::Open("http://root.cern.ch/files/tmva_class_example.root", "CACHEREAD");
     }
   */

   if (!inputS1) {
      std::cout << "ERROR: could not open data file" << std::endl;
      exit(1);
   }
//   std::cout << "--- TMVAClassification       : Using input signal file: " << inputS->GetName() << std::endl;
//   std::cout << "--- TMVAClassification       : Using input signal file: " << inputB->GetName() << std::endl;
 
   // Register the training and test trees

  TTree *signalTree1     = (TTree*)inputS1->Get("leptop_mu");
  TTree *signalTree2     = (TTree*)inputS2->Get("leptop_mu");
  TTree *signalTree3     = (TTree*)inputS3->Get("leptop_mu");
  
  //TTree *signalTree4     = (TTree*)inputS4->Get("leptop_e");
  //TTree *signalTree5     = (TTree*)inputS5->Get("leptop_e");

  TTree *background1     = (TTree*)inputB1->Get("bq");
  TTree *background2     = (TTree*)inputB2->Get("bq");
  TTree *background3     = (TTree*)inputB3->Get("bq");
  TTree *background4     = (TTree*)inputB4->Get("bq");
  TTree *background5     = (TTree*)inputB5->Get("bq");
  TTree *background6     = (TTree*)inputB6->Get("bq");
  TTree *background7     = (TTree*)inputB7->Get("bq");
  TTree *background8     = (TTree*)inputB8->Get("bq");

   // Create a ROOT output file where TMVA will store ntuples, histograms, etc.
   //TString outfileName( "TMVA_elidvar_notallevts.root" );
  //TString outfileName( "TMVA_sv_ID_notallevtsrechkv4.root" );
  //TString outfileName( "TMVA_only7varsnomatchelORnopf.root" ); 
  //TString outfileName( "TMVA_mu_otto3var_atselectionv12pre.root" );
  //TString outfileName( "TMVA_muallvar_otto3var_mupfisocut_atselectionv12prev5.root" );

  TString outfileName( "TMVA_muJan2021Corr_TTbarUL18.root" );
  TFile* outputFile = TFile::Open( outfileName, "RECREATE" );

   // Create the factory object. Later you can choose the methods
   // whose performance you'd like to investigate. The factory is
   // the only TMVA object you have to interact with
   //
   // The first argument is the base of the name of all the
   // weightfiles in the directory weight/
   //
   // The second argument is the output file for the training results
   // All TMVA output can be suppressed by removing the "!" (not) in
   // front of the "Silent" argument in the option string
   TMVA::Factory *factory = new TMVA::Factory( "TMVAClassification", outputFile,
                                               "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification" );

   TMVA::DataLoader *dataloader=new TMVA::DataLoader("dataset");
   // If you wish to modify default settings
   // (please check "src/Config.h" to see all available global options)
   //
   //    (TMVA::gConfig().GetVariablePlotting()).fTimesRMS = 8.0;
   //    (TMVA::gConfig().GetIONames()).fWeightFileDir = "myWeightDirectory";

   // Define the input variables that shall be used for the MVA training
   // note that you may also use variable expressions, such as: "3*var1/var2*abs(var3)"
   // [all types of expressions that can also be parsed by TTree::Draw( "expression" )]
//   dataloader->AddVariable( "myvar1 := var1+var2", 'F' );

   dataloader->AddVariable("selpfjetAK8NHadF",'F');
   dataloader->AddVariable("selpfjetAK8neunhadfrac",'F');
   dataloader->AddVariable("selpfjetAK8subhaddiff",'F');
   dataloader->AddVariable("selpfjetAK8tau21", 'F');
   dataloader->AddVariable("selpfjetAK8chrad", 'F');
   dataloader->AddVariable("selpfjetAK8sdmass", 'F');
   //Muon ID variable
   dataloader->AddVariable("selpfjetAK8matchedmuonchi", 'F');
   dataloader->AddVariable("selpfjetAK8matchedmuonposmatch", 'F');
   dataloader->AddVariable("selpfjetAK8matchedmuontrkink", 'F');
   dataloader->AddVariable("selpfjetAK8matchedmuonsegcom", 'F');
   dataloader->AddVariable("selpfjetAK8matchedmuonhit", 'F');
   dataloader->AddVariable("selpfjetAK8matchedmuonmst", 'F');
   dataloader->AddVariable("selpfjetAK8matchedmuontrkvtx", 'F');
   dataloader->AddVariable("selpfjetAK8matchedmuondz", 'F');
   dataloader->AddVariable("selpfjetAK8matchedmuonpixhit", 'F');
   dataloader->AddVariable("selpfjetAK8matchedmuontrklay", 'F');
   dataloader->AddVariable("selpfjetAK8matchedmuonvalfrac", 'F');

   //Otto Variable
   dataloader->AddVariable("selpfjetAK8muinsubptrat", 'F');
   dataloader->AddVariable("selpfjetAK8muinsubmassrat", 'F');
   dataloader->AddVariable("selpfjetAK8muinsubinvmass", 'F');
   dataloader->AddVariable("selpfjetAK8muinsubIfarbyI0", 'F');
   dataloader->AddVariable("selpfjetAK8muinsubInearbyI0", 'F');
   
   //dataloader->AddVariable("selpfjetAK8matchedmupfiso", 'F');
   //dataloader->AddVariable("selpfjetAK8matchedmuonisLoose", 'F');
   //dataloader->AddVariable("selpfjetAK8matchedmuonisGoodGL", 'F');
   //dataloader->AddVariable("selpfjetAK8matchedmuonisMed", 'F');
   //dataloader->AddVariable("selpfjetAK8matchedmuonisMedPr", 'F');
   //dataloader->AddVariable("selpfjetAK8matchedmuonisTight", 'F');
   //dataloader->AddVariable("selpfjetAK8matchedmuonisHighPt", 'F');
   //dataloader->AddVariable("selpfjetAK8matchedmuonisHighPttrk", 'F');

   
   //dataloader->AddVariable("selpfjetAK8matchedeldxy_sv", 'F');
   //dataloader->AddVariable("selpfjetAK8matchedelID", 'F');
   /*
   dataloader->AddVariable("selpfjetAK8matchedelcleta", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelpt", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelsigmaieta", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelsigmaiphi", 'F');
   
   dataloader->AddVariable("selpfjetAK8matchedelr9full", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelsupcl_etaw", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelsupcl_phiw", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelhcaloverecal", 'F');
   
   
   dataloader->AddVariable("selpfjetAK8matchedelcloctftrkn", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelcloctftrkchi2", 'F');
   dataloader->AddVariable("selpfjetAK8matchedele1x5bye5x5", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelnormchi2", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelhitsmiss", 'F');
   dataloader->AddVariable("selpfjetAK8matchedeltrkmeasure", 'F');
   
   //dataloader->AddVariable("selpfjetAK8matchedelconvtxprob", 'F');
   
   dataloader->AddVariable("selpfjetAK8matchedelecloverpout", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelecaletrkmomentum", 'F');
   dataloader->AddVariable("selpfjetAK8matchedeldeltaetacltrkcalo", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelsupcl_preshvsrawe", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelpfisolsumphet", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelpfisolsumchhadpt", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelpfisolsumneuhadet", 'F');
   dataloader->AddVariable("selpfjetAK8matchedeletain", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelphiin", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelfbrem", 'F');
   dataloader->AddVariable("selpfjetAK8matchedeleoverp", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelhovere", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelRho", 'F');
   dataloader->AddVariable("selpfjetAK8matchedelptrel", 'F');
   */
   //dataloader->AddVariable("selpfjetAK8matchedelID", 'F');
/*

   dataloader->AddVariable("selpfjetAK8_bbyW_E", 'F');
   dataloader->AddVariable("selpfjetAK8_Kfactor", 'F');
*/
//   dataloader->AddVariable("selpfjetAK8DeepTag_TvsQCD", 'F');


   // but will appear in the final "TestTree" produced by TMVA. This TestTree will contain the
   // input variables, the response values of all trained MVAs, and the spectator variables

//   dataloader->AddSpectator( "spec1 := var1*2",  "Spectator 1", "units", 'F' );
//   dataloader->AddSpectator( "spec2 := var1*3",  "Spectator 2", "units", 'F' );


   // global event weights per tree (see below for setting event-wise weights)
   Double_t signalWeight     = 1.0;
   Double_t backgroundWeight = 1.0;
  
   Double_t signalWeight1    = 9.682989e-06;// For Legacy ReReco => 6.0408e-06;
   Double_t signalWeight2    = 11.60498e-06;// For Legacy ReReco => 6.0779e-06;
   Double_t signalWeight3    = 1.74297e-05; // For Legacy ReReco => 1.9050e-05;


   //Double_t signalWeight4    = 2.5814e-06;
   //Double_t signalWeight5    = 1.0789e-06;
   
   /*
   Double_t signalWeight1    = 6.19876e-06;
   Double_t signalWeight2    = 6.1407e-06;
   Double_t signalWeight3    = 0.00137325;
   Double_t signalWeight4    = 2.95151e-06;
   Double_t signalWeight5    = 1.32553e-06;
   */


   //Double_t backgroundWeight1 = 0.099526;
   //Double_t backgroundWeight2 = 0.00877594;
   //Double_t backgroundWeight3 = 0.00164102;
   /*
   Double_t backgroundWeight1 = 31.0407;
   Double_t backgroundWeight2 = 4.422;
   Double_t backgroundWeight3 = 1.382;
   Double_t backgroundWeight4 = 0.143;
   Double_t backgroundWeight5 = 0.1463;
   Double_t backgroundWeight6 = 0.0987;
   Double_t backgroundWeight7 = 0.0091;
   Double_t backgroundWeight8 = 0.00163;
   */

   //Double_t backgroundWeight1 = 29.148;
   //Double_t backgroundWeight1 = 29.831; //lesser files due to T2
   Double_t backgroundWeight1 = 29.344; //v12
   Double_t backgroundWeight2 = 4.14778; //
   //Double_t backgroundWeight2 = 4.27326; //lesser files due to T2
   Double_t backgroundWeight3 = 1.38188;                                                            
   Double_t backgroundWeight4 = 0.143509;                                                         
   //Double_t backgroundWeight4 = 0.14441; //lesser files due to T2
   Double_t backgroundWeight5 = 0.14635;                                                            
   Double_t backgroundWeight6 = 0.099526;                                                           
   Double_t backgroundWeight7 = 0.00877594;                                                         
   Double_t backgroundWeight8 = 0.00164102;

   // You can add an arbitrary number of signal or background trees
   // dataloader->AddSignalTree    ( signalTree,     signalWeight );
   //dataloader->AddSignalTree    ( signalTree1,     signalWeight1 );
   dataloader->AddSignalTree    ( signalTree2,     signalWeight2 );
   dataloader->AddSignalTree    ( signalTree3,     signalWeight3 );
   //dataloader->AddSignalTree    ( signalTree4,     signalWeight4 );
   //dataloader->AddSignalTree    ( signalTree5,     signalWeight5 );   

//   dataloader->AddBackgroundTree( background, backgroundWeight );
   //dataloader->AddBackgroundTree( background1, backgroundWeight1 );
   //dataloader->AddBackgroundTree( background2, backgroundWeight2 );
   dataloader->AddBackgroundTree( background3, backgroundWeight3 );
   dataloader->AddBackgroundTree( background4, backgroundWeight4 );
   dataloader->AddBackgroundTree( background5, backgroundWeight5 );
   dataloader->AddBackgroundTree( background6, backgroundWeight6 );
   dataloader->AddBackgroundTree( background7, backgroundWeight7 );
   dataloader->AddBackgroundTree( background8, backgroundWeight8 );


   // To give different trees for training and testing, do as follows:
   //     dataloader->AddSignalTree( signalTrainingTree, signalTrainWeight, "Training" );
   //     dataloader->AddSignalTree( signalTestTree,     signalTestWeight,  "Test" );

   // Use the following code instead of the above two or four lines to add signal and background
   // training and test events "by hand"
   // NOTE that in this case one should not give expressions (such as "var1+var2") in the input
   //      variable definition, but simply compute the expression before adding the event
   // ```cpp
   // // --- begin ----------------------------------------------------------
   // std::vector<Double_t> vars( 4 ); // vector has size of number of input variables
   // Float_t  treevars[4], weight;
   //
   // // Signal
   // for (UInt_t ivar=0; ivar<4; ivar++) signalTree->SetBranchAddress( Form( "var%i", ivar+1 ), &(treevars[ivar]) );
   // for (UInt_t i=0; i<signalTree->GetEntries(); i++) {
   //    signalTree->GetEntry(i);
   //    for (UInt_t ivar=0; ivar<4; ivar++) vars[ivar] = treevars[ivar];
   //    // add training and test events; here: first half is training, second is testing
   //    // note that the weight can also be event-wise
   //    if (i < signalTree->GetEntries()/2.0) dataloader->AddSignalTrainingEvent( vars, signalWeight );
   //    else                              dataloader->AddSignalTestEvent    ( vars, signalWeight );
   // }
   //
   // // Background (has event weights)
   // background->SetBranchAddress( "weight", &weight );
   // for (UInt_t ivar=0; ivar<4; ivar++) background->SetBranchAddress( Form( "var%i", ivar+1 ), &(treevars[ivar]) );
   // for (UInt_t i=0; i<background->GetEntries(); i++) {
   //    background->GetEntry(i);
   //    for (UInt_t ivar=0; ivar<4; ivar++) vars[ivar] = treevars[ivar];
   //    // add training and test events; here: first half is training, second is testing
   //    // note that the weight can also be event-wise
   //    if (i < background->GetEntries()/2) dataloader->AddBackgroundTrainingEvent( vars, backgroundWeight*weight );
   //    else                                dataloader->AddBackgroundTestEvent    ( vars, backgroundWeight*weight );
   // }
   // // --- end ------------------------------------------------------------
   // ```
   // End of tree registration

   // Set individual event weights (the variables must exist in the original TTree)
   // -  for signal    : `dataloader->SetSignalWeightExpression    ("weight1*weight2");`
   // -  for background: `dataloader->SetBackgroundWeightExpression("weight1*weight2");`
   dataloader->SetBackgroundWeightExpression( "weight" );

   // Apply additional cuts on the signal and background samples (can be different)
   TCut mycuts = ""; // for example: TCut mycuts = "abs(var1)<0.5 && abs(var2-0.5)<1";
   TCut mycutb = ""; // for example: TCut mycutb = "abs(var1)<0.5";

   // Tell the dataloader how to use the training and testing events
   //
   // If no numbers of events are given, half of the events in the tree are used
   // for training, and the other half for testing:
   //
   //    dataloader->PrepareTrainingAndTestTree( mycut, "SplitMode=random:!V" );
   //
   // To also specify the number of testing events, use:
   //
   //    dataloader->PrepareTrainingAndTestTree( mycut,
   //         "NSigTrain=3000:NBkgTrain=3000:NSigTest=3000:NBkgTest=3000:SplitMode=Random:!V" );
   dataloader->PrepareTrainingAndTestTree( mycuts, mycutb,
                                        "nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=NumEvents:!V" );

   // ### Book MVA methods
   //
   // Please lookup the various method configuration options in the corresponding cxx files, eg:
   // src/MethoCuts.cxx, etc, or here: http://tmva.sourceforge.net/optionRef.html
   // it is possible to preset ranges in the option string in which the cut optimisation should be done:
   // "...:CutRangeMin[2]=-1:CutRangeMax[2]=1"...", where [2] is the third input variable

   // Cut optimisation
   if (Use["Cuts"])
      factory->BookMethod( dataloader, TMVA::Types::kCuts, "Cuts",
                           "!H:!V:FitMethod=MC:EffSel:SampleSize=200000:VarProp=FSmart" );

   if (Use["CutsD"])
      factory->BookMethod( dataloader, TMVA::Types::kCuts, "CutsD",
                           "!H:!V:FitMethod=MC:EffSel:SampleSize=200000:VarProp=FSmart:VarTransform=Decorrelate" );

   if (Use["CutsPCA"])
      factory->BookMethod( dataloader, TMVA::Types::kCuts, "CutsPCA",
                           "!H:!V:FitMethod=MC:EffSel:SampleSize=200000:VarProp=FSmart:VarTransform=PCA" );

   if (Use["CutsGA"])
      factory->BookMethod( dataloader, TMVA::Types::kCuts, "CutsGA",
                           "H:!V:FitMethod=GA:CutRangeMin[0]=-10:CutRangeMax[0]=10:VarProp[1]=FMax:EffSel:Steps=30:Cycles=3:PopSize=400:SC_steps=10:SC_rate=5:SC_factor=0.95" );

   if (Use["CutsSA"])
      factory->BookMethod( dataloader, TMVA::Types::kCuts, "CutsSA",
                           "!H:!V:FitMethod=SA:EffSel:MaxCalls=150000:KernelTemp=IncAdaptive:InitialTemp=1e+6:MinTemp=1e-6:Eps=1e-10:UseDefaultScale" );

   // Likelihood ("naive Bayes estimator")
   if (Use["Likelihood"])
      factory->BookMethod( dataloader, TMVA::Types::kLikelihood, "Likelihood",
                           "H:!V:TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmoothBkg[1]=10:NSmooth=1:NAvEvtPerBin=50" );

   // Decorrelated likelihood
   if (Use["LikelihoodD"])
      factory->BookMethod( dataloader, TMVA::Types::kLikelihood, "LikelihoodD",
                           "!H:!V:TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=Decorrelate" );

   // PCA-transformed likelihood
   if (Use["LikelihoodPCA"])
      factory->BookMethod( dataloader, TMVA::Types::kLikelihood, "LikelihoodPCA",
                           "!H:!V:!TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=PCA" );

   // Use a kernel density estimator to approximate the PDFs
   if (Use["LikelihoodKDE"])
      factory->BookMethod( dataloader, TMVA::Types::kLikelihood, "LikelihoodKDE",
                           "!H:!V:!TransformOutput:PDFInterpol=KDE:KDEtype=Gauss:KDEiter=Adaptive:KDEFineFactor=0.3:KDEborder=None:NAvEvtPerBin=50" );

   // Use a variable-dependent mix of splines and kernel density estimator
   if (Use["LikelihoodMIX"])
      factory->BookMethod( dataloader, TMVA::Types::kLikelihood, "LikelihoodMIX",
                           "!H:!V:!TransformOutput:PDFInterpolSig[0]=KDE:PDFInterpolBkg[0]=KDE:PDFInterpolSig[1]=KDE:PDFInterpolBkg[1]=KDE:PDFInterpolSig[2]=Spline2:PDFInterpolBkg[2]=Spline2:PDFInterpolSig[3]=Spline2:PDFInterpolBkg[3]=Spline2:KDEtype=Gauss:KDEiter=Nonadaptive:KDEborder=None:NAvEvtPerBin=50" );

   // Test the multi-dimensional probability density estimator
   // here are the options strings for the MinMax and RMS methods, respectively:
   //
   //      "!H:!V:VolumeRangeMode=MinMax:DeltaFrac=0.2:KernelEstimator=Gauss:GaussSigma=0.3" );
   //      "!H:!V:VolumeRangeMode=RMS:DeltaFrac=3:KernelEstimator=Gauss:GaussSigma=0.3" );
   if (Use["PDERS"])
      factory->BookMethod( dataloader, TMVA::Types::kPDERS, "PDERS",
                           "!H:!V:NormTree=T:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=400:NEventsMax=600" );

   if (Use["PDERSD"])
      factory->BookMethod( dataloader, TMVA::Types::kPDERS, "PDERSD",
                           "!H:!V:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=400:NEventsMax=600:VarTransform=Decorrelate" );

   if (Use["PDERSPCA"])
      factory->BookMethod( dataloader, TMVA::Types::kPDERS, "PDERSPCA",
                           "!H:!V:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=400:NEventsMax=600:VarTransform=PCA" );

   // Multi-dimensional likelihood estimator using self-adapting phase-space binning
   if (Use["PDEFoam"])
      factory->BookMethod( dataloader, TMVA::Types::kPDEFoam, "PDEFoam",
                           "!H:!V:SigBgSeparate=F:TailCut=0.001:VolFrac=0.0666:nActiveCells=500:nSampl=2000:nBin=5:Nmin=100:Kernel=None:Compress=T" );

   if (Use["PDEFoamBoost"])
      factory->BookMethod( dataloader, TMVA::Types::kPDEFoam, "PDEFoamBoost",
                           "!H:!V:Boost_Num=30:Boost_Transform=linear:SigBgSeparate=F:MaxDepth=4:UseYesNoCell=T:DTLogic=MisClassificationError:FillFoamWithOrigWeights=F:TailCut=0:nActiveCells=500:nBin=20:Nmin=400:Kernel=None:Compress=T" );

   // K-Nearest Neighbour classifier (KNN)
   if (Use["KNN"])
      factory->BookMethod( dataloader, TMVA::Types::kKNN, "KNN",
                           "H:nkNN=20:ScaleFrac=0.8:SigmaFact=1.0:Kernel=Gaus:UseKernel=F:UseWeight=T:!Trim" );

   // H-Matrix (chi2-squared) method
   if (Use["HMatrix"])
      factory->BookMethod( dataloader, TMVA::Types::kHMatrix, "HMatrix", "!H:!V:VarTransform=None" );

   // Linear discriminant (same as Fisher discriminant)
   if (Use["LD"])
      factory->BookMethod( dataloader, TMVA::Types::kLD, "LD", "H:!V:VarTransform=None:CreateMVAPdfs:PDFInterpolMVAPdf=Spline2:NbinsMVAPdf=50:NsmoothMVAPdf=10" );

   // Fisher discriminant (same as LD)
   if (Use["Fisher"])
      factory->BookMethod( dataloader, TMVA::Types::kFisher, "Fisher", "H:!V:Fisher:VarTransform=None:CreateMVAPdfs:PDFInterpolMVAPdf=Spline2:NbinsMVAPdf=50:NsmoothMVAPdf=10" );

   // Fisher with Gauss-transformed input variables
   if (Use["FisherG"])
      factory->BookMethod( dataloader, TMVA::Types::kFisher, "FisherG", "H:!V:VarTransform=Gauss" );

   // Composite classifier: ensemble (tree) of boosted Fisher classifiers
   if (Use["BoostedFisher"])
      factory->BookMethod( dataloader, TMVA::Types::kFisher, "BoostedFisher",
                           "H:!V:Boost_Num=20:Boost_Transform=log:Boost_Type=AdaBoost:Boost_AdaBoostBeta=0.2:!Boost_DetailedMonitoring" );

   // Function discrimination analysis (FDA) -- test of various fitters - the recommended one is Minuit (or GA or SA)
   if (Use["FDA_MC"])
      factory->BookMethod( dataloader, TMVA::Types::kFDA, "FDA_MC",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=MC:SampleSize=100000:Sigma=0.1" );

   if (Use["FDA_GA"]) // can also use Simulated Annealing (SA) algorithm (see Cuts_SA options])
      factory->BookMethod( dataloader, TMVA::Types::kFDA, "FDA_GA",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=GA:PopSize=100:Cycles=2:Steps=5:Trim=True:SaveBestGen=1" );

   if (Use["FDA_SA"]) // can also use Simulated Annealing (SA) algorithm (see Cuts_SA options])
      factory->BookMethod( dataloader, TMVA::Types::kFDA, "FDA_SA",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=SA:MaxCalls=15000:KernelTemp=IncAdaptive:InitialTemp=1e+6:MinTemp=1e-6:Eps=1e-10:UseDefaultScale" );

   if (Use["FDA_MT"])
      factory->BookMethod( dataloader, TMVA::Types::kFDA, "FDA_MT",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=MINUIT:ErrorLevel=1:PrintLevel=-1:FitStrategy=2:UseImprove:UseMinos:SetBatch" );

   if (Use["FDA_GAMT"])
      factory->BookMethod( dataloader, TMVA::Types::kFDA, "FDA_GAMT",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=GA:Converger=MINUIT:ErrorLevel=1:PrintLevel=-1:FitStrategy=0:!UseImprove:!UseMinos:SetBatch:Cycles=1:PopSize=5:Steps=5:Trim" );

   if (Use["FDA_MCMT"])
      factory->BookMethod( dataloader, TMVA::Types::kFDA, "FDA_MCMT",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=MC:Converger=MINUIT:ErrorLevel=1:PrintLevel=-1:FitStrategy=0:!UseImprove:!UseMinos:SetBatch:SampleSize=20" );

   // TMVA ANN: MLP (recommended ANN) -- all ANNs in TMVA are Multilayer Perceptrons
   if (Use["MLP"])
      factory->BookMethod( dataloader, TMVA::Types::kMLP, "MLP", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:!UseRegulator" );

   if (Use["MLPBFGS"])
      factory->BookMethod( dataloader, TMVA::Types::kMLP, "MLPBFGS", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:TrainingMethod=BFGS:!UseRegulator" );

   if (Use["MLPBNN"])
      factory->BookMethod( dataloader, TMVA::Types::kMLP, "MLPBNN", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=60:HiddenLayers=N+5:TestRate=5:TrainingMethod=BFGS:UseRegulator" ); // BFGS training with bayesian regulators


   // Multi-architecture DNN implementation.
   if (Use["DNN_CPU"] or Use["DNN_GPU"]) {
      // General layout.
      TString layoutString ("Layout=TANH|128,TANH|128,TANH|128,LINEAR");

      // Training strategies.
      TString training0("LearningRate=1e-1,Momentum=0.9,Repetitions=1,"
                        "ConvergenceSteps=20,BatchSize=256,TestRepetitions=10,"
                        "WeightDecay=1e-4,Regularization=L2,"
                        "DropConfig=0.0+0.5+0.5+0.5, Multithreading=True");
      TString training1("LearningRate=1e-2,Momentum=0.9,Repetitions=1,"
                        "ConvergenceSteps=20,BatchSize=256,TestRepetitions=10,"
                        "WeightDecay=1e-4,Regularization=L2,"
                        "DropConfig=0.0+0.0+0.0+0.0, Multithreading=True");
      TString training2("LearningRate=1e-3,Momentum=0.0,Repetitions=1,"
                        "ConvergenceSteps=20,BatchSize=256,TestRepetitions=10,"
                        "WeightDecay=1e-4,Regularization=L2,"
                        "DropConfig=0.0+0.0+0.0+0.0, Multithreading=True");
      TString trainingStrategyString ("TrainingStrategy=");
      trainingStrategyString += training0 + "|" + training1 + "|" + training2;

      // General Options.
      TString dnnOptions ("!H:V:ErrorStrategy=CROSSENTROPY:VarTransform=N:"
                          "WeightInitialization=XAVIERUNIFORM");
      dnnOptions.Append (":"); dnnOptions.Append (layoutString);
      dnnOptions.Append (":"); dnnOptions.Append (trainingStrategyString);

      // Cuda implementation.
      if (Use["DNN_GPU"]) {
         TString gpuOptions = dnnOptions + ":Architecture=GPU";
         factory->BookMethod(dataloader, TMVA::Types::kDNN, "DNN_GPU", gpuOptions);
      }
      // Multi-core CPU implementation.
      if (Use["DNN_CPU"]) {
         TString cpuOptions = dnnOptions + ":Architecture=CPU";
         factory->BookMethod(dataloader, TMVA::Types::kDNN, "DNN_CPU", cpuOptions);
      }
   }

   // CF(Clermont-Ferrand)ANN
   if (Use["CFMlpANN"])
      factory->BookMethod( dataloader, TMVA::Types::kCFMlpANN, "CFMlpANN", "!H:!V:NCycles=200:HiddenLayers=N+1,N"  ); // n_cycles:#nodes:#nodes:...

   // Tmlp(Root)ANN
   if (Use["TMlpANN"])
      factory->BookMethod( dataloader, TMVA::Types::kTMlpANN, "TMlpANN", "!H:!V:NCycles=200:HiddenLayers=N+1,N:LearningMethod=BFGS:ValidationFraction=0.3"  ); // n_cycles:#nodes:#nodes:...

   // Support Vector Machine
   if (Use["SVM"])
      factory->BookMethod( dataloader, TMVA::Types::kSVM, "SVM", "Gamma=0.25:Tol=0.001:VarTransform=Norm" );

   // Boosted Decision Trees
   if (Use["BDTG"]) // Gradient Boost
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTG",
                           "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=2" );

   if (Use["BDT"])  // Adaptive Boost
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDT",
                           "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20" );

   if (Use["BDTB"]) // Bagging
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTB",
                           "!H:!V:NTrees=400:BoostType=Bagging:SeparationType=GiniIndex:nCuts=20" );

   if (Use["BDTD"]) // Decorrelation + Adaptive Boost
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTD",
                           "!H:!V:NTrees=400:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:SeparationType=GiniIndex:nCuts=20:VarTransform=Decorrelate" );

   if (Use["BDTF"])  // Allow Using Fisher discriminant in node splitting for (strong) linearly correlated variables
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTF",
                           "!H:!V:NTrees=50:MinNodeSize=2.5%:UseFisherCuts:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:SeparationType=GiniIndex:nCuts=20" );

   // RuleFit -- TMVA implementation of Friedman's method
   if (Use["RuleFit"])
      factory->BookMethod( dataloader, TMVA::Types::kRuleFit, "RuleFit",
                           "H:!V:RuleFitModule=RFTMVA:Model=ModRuleLinear:MinImp=0.001:RuleMinDist=0.001:NTrees=20:fEventsMin=0.01:fEventsMax=0.5:GDTau=-1.0:GDTauPrec=0.01:GDStep=0.01:GDNSteps=10000:GDErrScale=1.02" );

   // For an example of the category classifier usage, see: TMVAClassificationCategory
   //
   // --------------------------------------------------------------------------------------------------
   //  Now you can optimize the setting (configuration) of the MVAs using the set of training events
   // STILL EXPERIMENTAL and only implemented for BDT's !
   //
   //     factory->OptimizeAllMethods("SigEffAt001","Scan");
   //     factory->OptimizeAllMethods("ROCIntegral","FitGA");
   //
   // --------------------------------------------------------------------------------------------------

   // Now you can tell the factory to train, test, and evaluate the MVAs
   //
   // Train MVAs using the set of training events
   factory->TrainAllMethods();

   // Evaluate all MVAs using the set of test events
   factory->TestAllMethods();

   // Evaluate and compare performance of all configured MVAs
   factory->EvaluateAllMethods();

   // --------------------------------------------------------------

   // Save the output
   outputFile->Close();

   std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
   std::cout << "==> TMVAClassification is done!" << std::endl;

   delete factory;
   delete dataloader;
   // Launch the GUI for the root macros
   if (!gROOT->IsBatch()) TMVA::TMVAGui( outfileName );

   return 0;
}

int main( int argc, char** argv )
{
   // Select methods (don't look at this code - not of interest)
   TString methodList;
   for (int i=1; i<argc; i++) {
      TString regMethod(argv[i]);
      if(regMethod=="-b" || regMethod=="--batch") continue;
      if (!methodList.IsNull()) methodList += TString(",");
      methodList += regMethod;
   }
   return TMVAClassification(methodList);
}
