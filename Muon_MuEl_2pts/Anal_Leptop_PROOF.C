#define Anal_Leptop_PROOF_cxx
#include "Anal_Leptop_PROOF.h"
#include <TH2.h>
#include <TStyle.h>

//Taken from /home/deroy/t3store3/Electron_Latest_re_Oct/ElectronicTopTagger_CMS/Analysis/For_Data/Ejet_TTbar/

#define E_MU_TTBar
//#define E_Jets_TTBar
//#define Sample_JetHT
#define Data_MC

void Anal_Leptop_PROOF::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.
  // The tree argument is deprecated (on PROOF 0 is passed).
  
  TString option = GetOption();
}

void Anal_Leptop_PROOF::SlaveBegin(TTree * /*tree*/)
{
  //The SlaveBegin() function is called after the Begin() function.
  //When running with PROOF SlaveBegin() is called on each slave server.
  //The tree argument is deprecated (on PROOF 0 is passed).

  TString option = GetOption();
  OutFile = new TProofOutputFile("test.root");

  fileOut = OutFile->OpenFile("RECREATE");
  if ( !(fileOut = OutFile->OpenFile("RECREATE")) )
    {
      Warning("SlaveBegin", "problems opening file: %s/%s",
	      OutFile->GetDir(), OutFile->GetFileName());
    }
  
  isMC = true;
  isTT = true;
  isST = false;
  isDIB = false;
  isWJ = false;
  isDY = false;
  isbQCD = false;
  
  Tout = new TTree("leptop","leptop");
  Tout->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout->Branch("weight",&weight,"weight/F");
    
  hist_pfmet_1 = new TH1D("hist_PFMET_pass","hist_PFMET_pass",25,0,500);
  hist_pfmet_1->Sumw2();
 
  char name[1000];

  for(int dr=0; dr<14; dr++){
    char drname[1000], drtitle[1000];
    sprintf(drname,"hist_%s",drnames[dr]);
    sprintf(drtitle,"%s",drtitlenames[dr]);
    hist_dRdPhi[dr] = new TH1D(drname,drtitle,100,dr_low[dr],dr_high[dr]);
    hist_dRdPhi[dr]->Sumw2();
  }

  for(int init=0; init<17; init++){
    char namein[1000], nameinup[1000], nameindown[1000];
    char titlein[1000];
    if (init <= 2 || init > 6) {
      sprintf(namein,"hist_%s",initnames[init]);
      sprintf(titlein,"%s",titlenames[init]);
      hist_init[init] = new TH1D(namein,titlein,ini_nbins[init],ini_low[init],ini_up[init]);
      hist_init[init]->Sumw2();
      sprintf(nameinup,"hist_%s_puwup",initnames[init]);
      hist_initpuwup[init] = new TH1D(nameinup,titlein,ini_nbins[init],ini_low[init],ini_up[init]);
      hist_initpuwup[init]->Sumw2();
      sprintf(nameindown,"hist_%s_puwdown",initnames[init]);
      hist_initpuwdown[init] = new TH1D(nameindown,titlein,ini_nbins[init],ini_low[init],ini_up[init]);
      hist_initpuwdown[init]->Sumw2();
      sprintf(nameinup,"hist_%s_btagwup",initnames[init]);
      hist_initbtagwup[init] = new TH1D(nameinup,titlein,ini_nbins[init],ini_low[init],ini_up[init]);
      hist_initbtagwup[init]->Sumw2();
      sprintf(nameindown,"hist_%s_btagwdown",initnames[init]);
      hist_initbtagwdown[init] = new TH1D(nameindown,titlein,ini_nbins[init],ini_low[init],ini_up[init]);
      hist_initbtagwdown[init]->Sumw2();
    }
    else {
      sprintf(namein,"%s",initnames[init]);
      sprintf(titlein,"%s",titlenames[init]);
      hist_init[init] = new TH1D(namein,titlein,ini_nbins[init],ini_low[init],ini_up[init]);
      hist_init[init]->Sumw2();
      sprintf(nameinup,"hist_%s_puwup",initnames[init]);
      hist_initpuwup[init] = new TH1D(nameinup,titlein,ini_nbins[init],ini_low[init],ini_up[init]);
      hist_initpuwup[init]->Sumw2();
      sprintf(nameindown,"hist_%s_puwdown",initnames[init]);
      hist_initpuwdown[init] = new TH1D(nameindown,titlein,ini_nbins[init],ini_low[init],ini_up[init]);
      hist_initpuwdown[init]->Sumw2();
      sprintf(nameinup,"hist_%s_btagwup",initnames[init]);
      hist_initbtagwup[init] = new TH1D(nameinup,titlein,ini_nbins[init],ini_low[init],ini_up[init]);
      hist_initbtagwup[init]->Sumw2();
      sprintf(nameindown,"hist_%s_btagwdown",initnames[init]);
      hist_initbtagwdown[init] = new TH1D(nameindown,titlein,ini_nbins[init],ini_low[init],ini_up[init]);
      hist_initbtagwdown[init]->Sumw2();
    }
  }
  char lname[1000],ltitle[1000];
  sprintf(lname,"hist_%s",initnames[17]);
  sprintf(ltitle,"%s",titlenames[17]);
  hist_init[17] = new TH1D(lname,ltitle,ini_nbins[17],ini_low[17],ini_up[17]);
  hist_init[17]->Sumw2();

  for(int ihist=0; ihist<14; ihist++){
    
    char nameup[1000], namedown[1000];
    
    sprintf(name,"Obs_%s",obsnames[ihist]);
    hist_obs[ihist] = new TH1D(name,name,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
    hist_obs[ihist]->Sumw2();
    sprintf(nameup,"Obs_%s_puwup",obsnames[ihist]);
    hist_obspuwup[ihist] = new TH1D(nameup,nameup,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
    hist_obspuwup[ihist]->Sumw2();
    sprintf(namedown,"Obs_%s_puwdown",obsnames[ihist]);
    hist_obspuwdown[ihist] = new TH1D(namedown,namedown,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
    hist_obspuwdown[ihist]->Sumw2();
    sprintf(nameup,"Obs_%s_btagwup",obsnames[ihist]);
    hist_obsbtagwup[ihist] = new TH1D(nameup,nameup,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
    hist_obsbtagwup[ihist]->Sumw2();
    sprintf(namedown,"Obs_%s_btagwdown",obsnames[ihist]);
    hist_obsbtagwdown[ihist] = new TH1D(namedown,namedown,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
    hist_obsbtagwdown[ihist]->Sumw2();

    if (ihist<3) {
      sprintf(nameup,"Obs_%s_ljesup",obsnames[ihist]);
      hist_obsljesup[ihist] = new TH1D(nameup,nameup,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
      hist_obsljesup[ihist]->Sumw2();

      sprintf(namedown,"Obs_%s_ljesdown",obsnames[ihist]);
      hist_obsljesdown[ihist] = new TH1D(namedown,namedown,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
      hist_obsljesdown[ihist]->Sumw2();
  
      sprintf(nameup,"Obs_%s_ljerup",obsnames[ihist]);
      hist_obsljerup[ihist] = new TH1D(nameup,nameup,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
      hist_obsljerup[ihist]->Sumw2();

      sprintf(namedown,"Obs_%s_ljerdown",obsnames[ihist]);
      hist_obsljerdown[ihist] = new TH1D(namedown,namedown,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
      hist_obsljerdown[ihist]->Sumw2();
    }
    sprintf(name,"Obsmu_%s",obsnames_mu[ihist]);
    hist_obs_mu[ihist] = new TH1D(name,name,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
    hist_obs_mu[ihist]->Sumw2();
    sprintf(nameup,"Obsmu_%s_puwup",obsnames[ihist]);
    hist_obs_mupuwup[ihist] = new TH1D(nameup,nameup,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
    hist_obs_mupuwup[ihist]->Sumw2();
    sprintf(namedown,"Obsmu_%s_puwdown",obsnames[ihist]);
    hist_obs_mupuwdown[ihist] = new TH1D(namedown,namedown,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
    hist_obs_mupuwdown[ihist]->Sumw2();
    sprintf(nameup,"Obsmu_%s_btagwup",obsnames[ihist]);
    hist_obs_mubtagwup[ihist] = new TH1D(nameup,nameup,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
    hist_obs_mubtagwup[ihist]->Sumw2();
    sprintf(namedown,"Obsmu_%s_btagwdown",obsnames[ihist]);
    hist_obs_mubtagwdown[ihist] = new TH1D(namedown,namedown,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
    hist_obs_mubtagwdown[ihist]->Sumw2();

    if (ihist<3) {

      sprintf(nameup,"Obsmu_%s_ljesup",obsnames[ihist]);
      hist_obs_muljesup[ihist] = new TH1D(nameup,nameup,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
      hist_obs_muljesup[ihist]->Sumw2();

      sprintf(namedown,"Obsmu_%s_ljesdown",obsnames[ihist]);
      hist_obs_muljesdown[ihist] = new TH1D(namedown,namedown,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
      hist_obs_muljesdown[ihist]->Sumw2();

      sprintf(nameup,"Obsmu_%s_ljerup",obsnames[ihist]);
      hist_obs_muljerup[ihist] = new TH1D(nameup,nameup,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
      hist_obs_muljerup[ihist]->Sumw2();

      sprintf(namedown,"Obsmu_%s_ljerdown",obsnames[ihist]);
      hist_obs_muljerdown[ihist] = new TH1D(namedown,namedown,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
      hist_obs_muljerdown[ihist]->Sumw2();
    }

  }
  
  char title[1000];
  sprintf(name,"N_PV");
  sprintf(title,"# of Primary Vertices");
  hist_npv = new TH1D(name,title,100,-0.1,99.9);//80,-0.1,79.9);
  hist_npv->Sumw2();
  
  sprintf(name,"N_primv");
  sprintf(title,"# of loose Primary Vertices");
  hist_nprim = new TH1D(name,title,100,-0.1,99.9);
  hist_nprim->Sumw2();

  sprintf(name,"N_PU");
  sprintf(title,"# of Pileup Vertices");
  hist_npu = new TH1D(name,title,100,0,100);//80,-0.1,79.9);
  hist_npu->Sumw2();
  
  sprintf(name,"N_PV_sel_bjet");
  sprintf(title,"# of Primary Vertices");
  hist_npv_sel_bjet = new TH1D(name,title,100,-0.1,99.9);//80,-0.1,79.9);
  hist_npv_sel_bjet->Sumw2();
  
  sprintf(name,"N_PV_nopuwt");
  sprintf(title,"# of Primary Vertices");
  hist_npv_nopuwt = new TH1D(name,title,100,-0.1,99.9);
  hist_npv_nopuwt->Sumw2();
  
  sprintf(name,"N_PU_nopuwt");
  sprintf(title,"# of Pileup Vertices");
  hist_npu_nopuwt = new TH1D(name,title,100,-0.1,99.9);
  hist_npu_nopuwt->Sumw2();
  
  sprintf(name,"Counter_event");
  hist_event_count = new TH1D(name,title,2,-0.5,1.5);
  hist_event_count->Sumw2();
  
  sprintf(name,"NJets_AK8_bjet");
  sprintf(title,"# of AK8 jets");
  hist_njets_AK8_bjet = new TH1D(name,title,10,0.5,10.5);
  hist_njets_AK8_bjet->Sumw2();
  
  sprintf(name,"NJets_AK4_bjet");
  sprintf(title,"# of AK4 jets");
  hist_njets_AK4_bjet = new TH1D(name,title,10,0.5,10.5);
  hist_njets_AK4_bjet->Sumw2();
  
  sprintf(name,"NBJets_AK4_bjet");
  sprintf(title,"# of b tagged AK4 jets");
  hist_nbjets_AK4_bjet = new TH1D(name,title,10,0.5,10.5);
  hist_nbjets_AK4_bjet->Sumw2();

  hist_2D_msd_deepak8 = new TH2D("hist_2D_msd_deepak8","hist_2D_msd_deepak8",25,0,300,25,0,1);
  hist_2D_msd_deepak8->Sumw2();
  hist_2D_bpass_flavb = new TH2D("h2d_btagpass_flavb","h2d_btagpass_flavb",nobptbins,bptbins,nobetabins,betabins);
  hist_2D_bpass_flavb->Sumw2();
  hist_2D_bpass_flavc = new TH2D("h2d_btagpass_flavc","h2d_btagpass_flavc",nobptbins,bptbins,nobetabins,betabins);
  hist_2D_bpass_flavc->Sumw2();
  hist_2D_bpass_flavq = new TH2D("h2d_btagpass_flavq","h2d_btagpass_flavq",nobptbins,bptbins,nobetabins,betabins);
  hist_2D_bpass_flavq->Sumw2();
  hist_2D_ball_flavb = new TH2D("h2d_flavb","h2d_flavb",nobptbins,bptbins,nobetabins,betabins);
  hist_2D_ball_flavb->Sumw2();
  hist_2D_ball_flavc = new TH2D("h2d_flavc","h2d_flavc",nobptbins,bptbins,nobetabins,betabins);
  hist_2D_ball_flavc->Sumw2();
  hist_2D_ball_flavq = new TH2D("h2d_flavq","h2d_flavq",nobptbins,bptbins,nobetabins,betabins);
  hist_2D_ball_flavq->Sumw2();  

  hist_count = new TH1D("Counter","Counter",18,0.5,18.5);
  hist_count->Sumw2();  

  reader1 = new TMVA::Reader( "BDTG_Re" );
  reader1->AddVariable( "selpfjetAK8NHadF", &in_pfjetAK8NHadF);
  reader1->AddVariable( "selpfjetAK8neunhadfrac", &in_pfjetAK8neunhadfrac);
  reader1->AddVariable( "selpfjetAK8subhaddiff", &in_pfjetAK8subhaddiff);
  reader1->AddVariable( "selpfjetAK8tau21", &in_pfjetAK8tau21);
  reader1->AddVariable( "selpfjetAK8chrad", &in_pfjetAK8chrad);
  reader1->AddVariable( "selpfjetAK8sdmass", &in_pfjetAK8sdmass);
  reader1->AddVariable( "selpfjetAK8matchedeldxy_sv", &in_pfjetAK8eldxy_sv);
  reader1->AddVariable( "selpfjetAK8matchedelcleta", &in_pfjetAK8matchedelcleta);
  reader1->AddVariable("selpfjetAK8matchedelpt", &in_pfjetAK8matchedelpt);
  reader1->AddVariable("selpfjetAK8matchedelsigmaieta", &in_pfjetAK8matchedelsigmaieta);
  reader1->AddVariable("selpfjetAK8matchedelsigmaiphi", &in_pfjetAK8matchedelsigmaiphi);
  reader1->AddVariable("selpfjetAK8matchedelr9full", &in_pfjetAK8matchedelr9full);
  reader1->AddVariable("selpfjetAK8matchedelsupcl_etaw", &in_pfjetAK8matchedelsupcl_etaw);
  reader1->AddVariable("selpfjetAK8matchedelsupcl_phiw", &in_pfjetAK8matchedelsupcl_phiw);
  reader1->AddVariable("selpfjetAK8matchedelhcaloverecal", &in_pfjetAK8matchedelhcaloverecal);
  reader1->AddVariable("selpfjetAK8matchedelcloctftrkn", &in_pfjetAK8matchedelcloctftrkn);
  reader1->AddVariable("selpfjetAK8matchedelcloctftrkchi2", &in_pfjetAK8matchedelcloctftrkchi2);
  reader1->AddVariable("selpfjetAK8matchedele1x5bye5x5", &in_pfjetAK8matchedele1x5bye5x5);
  reader1->AddVariable("selpfjetAK8matchedelnormchi2", &in_pfjetAK8matchedelnormchi2);
  reader1->AddVariable("selpfjetAK8matchedelhitsmiss", &in_pfjetAK8matchedelhitsmiss);
  reader1->AddVariable("selpfjetAK8matchedeltrkmeasure", &in_pfjetAK8matchedeltrkmeasure);
  reader1->AddVariable("selpfjetAK8matchedelecloverpout", &in_pfjetAK8matchedelecloverpout);
  reader1->AddVariable("selpfjetAK8matchedelecaletrkmomentum", &in_pfjetAK8matchedelecaletrkmomentum);
  reader1->AddVariable("selpfjetAK8matchedeldeltaetacltrkcalo", &in_pfjetAK8matchedeldeltaetacltrkcalo);
  reader1->AddVariable("selpfjetAK8matchedelsupcl_preshvsrawe", &in_pfjetAK8matchedelsupcl_preshvsrawe);
  reader1->AddVariable("selpfjetAK8matchedelpfisolsumphet", &in_pfjetAK8matchedelpfisolsumphet);
  reader1->AddVariable("selpfjetAK8matchedelpfisolsumchhadpt", &in_pfjetAK8matchedelpfisolsumchhadpt);
  reader1->AddVariable("selpfjetAK8matchedelpfisolsumneuhadet", &in_pfjetAK8matchedelpfisolsumneuhadet);
  reader1->AddVariable("selpfjetAK8matchedeletain", &in_pfjetAK8matchedeletain);
  reader1->AddVariable("selpfjetAK8matchedelphiin", &in_pfjetAK8matchedelphiin);
  reader1->AddVariable("selpfjetAK8matchedelfbrem", &in_pfjetAK8matchedelfbrem);
  reader1->AddVariable("selpfjetAK8matchedeleoverp", &in_pfjetAK8matchedeleoverp);
  reader1->AddVariable("selpfjetAK8matchedelhovere", &in_pfjetAK8matchedelhovere);
  reader1->AddVariable("selpfjetAK8matchedelRho", &in_pfjetAK8matchedelRho);
  reader1->BookMVA("BDTG method", weightfile1);

  reader2 = new TMVA::Reader( "BDTG_Rnu" );
  reader2->AddVariable( "selpfjetAK8_bbyW_E", &in_pfjetAK8_bbyW_E);
  reader2->AddVariable( "selpfjetAK8_Kfactor", &in_pfjetAK8_Kfactor);
  reader2->BookMVA("BDTG method", weightfile2);
  
  reader3 = new TMVA::Reader( "BDTG_Rt" );
  reader3->AddVariable( "selpfjetAK8NHadF", &in_pfjetAK8NHadF);
  reader3->AddVariable( "selpfjetAK8neunhadfrac", &in_pfjetAK8neunhadfrac);
  reader3->AddVariable( "selpfjetAK8subhaddiff", &in_pfjetAK8subhaddiff);
  reader3->AddVariable( "selpfjetAK8tau21", &in_pfjetAK8tau21);
  reader3->AddVariable( "selpfjetAK8chrad", &in_pfjetAK8chrad);
  reader3->AddVariable( "selpfjetAK8sdmass", &in_pfjetAK8sdmass);
  reader3->BookMVA("BDTG method", weightfile3);
  
  reader4 = new TMVA::Reader( "BDTG_Rmu" );
  reader4->AddVariable( "selpfjetAK8NHadF", &in_pfjetAK8NHadF);
  reader4->AddVariable( "selpfjetAK8neunhadfrac", &in_pfjetAK8neunhadfrac);
  reader4->AddVariable( "selpfjetAK8subhaddiff", &in_pfjetAK8subhaddiff);
  reader4->AddVariable( "selpfjetAK8tau21", &in_pfjetAK8tau21);
  reader4->AddVariable( "selpfjetAK8chrad", &in_pfjetAK8chrad);
  reader4->AddVariable( "selpfjetAK8sdmass", &in_pfjetAK8sdmass);
  reader4->AddVariable("selpfjetAK8matchedmuonchi", &in_pfjetAK8matchedmuonchi);
  reader4->AddVariable("selpfjetAK8matchedmuonposmatch", &in_pfjetAK8matchedmuonposmatch);
  reader4->AddVariable("selpfjetAK8matchedmuontrkink", &in_pfjetAK8matchedmuontrkink);
  reader4->AddVariable("selpfjetAK8matchedmuonsegcom", &in_pfjetAK8matchedmuonsegcom);
  reader4->AddVariable("selpfjetAK8matchedmuonhit", &in_pfjetAK8matchedmuonhit);
  reader4->AddVariable("selpfjetAK8matchedmuonmst", &in_pfjetAK8matchedmuonmst);
  reader4->AddVariable("selpfjetAK8matchedmuontrkvtx", &in_pfjetAK8matchedmuontrkvtx);
  reader4->AddVariable("selpfjetAK8matchedmuondz", &in_pfjetAK8matchedmuondz);
  reader4->AddVariable("selpfjetAK8matchedmuonpixhit", &in_pfjetAK8matchedmuonpixhit);
  reader4->AddVariable("selpfjetAK8matchedmuontrklay", &in_pfjetAK8matchedmuontrklay);
  reader4->AddVariable("selpfjetAK8matchedmuonvalfrac", &in_pfjetAK8matchedmuonvalfrac);
  reader4->AddVariable("selpfjetAK8muinsubptrat", &in_pfjetAK8muinsubptrat);
  reader4->AddVariable("selpfjetAK8muinsubmassrat", &in_pfjetAK8muinsubmassrat);
  reader4->AddVariable("selpfjetAK8muinsubinvmass", &in_pfjetAK8muinsubinvmass);
  reader4->AddVariable("selpfjetAK8muinsubIfarbyI0", &in_pfjetAK8muinsubIfarbyI0);
  reader4->AddVariable("selpfjetAK8muinsubInearbyI0", &in_pfjetAK8muinsubInearbyI0);
  reader4->BookMVA("BDTG method", weightfile4);
}

Bool_t Anal_Leptop_PROOF::Process(Long64_t entry)
{
  // The Process() function is called for each entry in the tree (or possibly
  // keyed object in the case of PROOF) to be processed. The entry argument
  // specifies which entry in the currently loaded tree is to be processed.
  // It can be passed to either Anal_Leptop_PROOF::GetEntry() or TBranch::GetEntry()
  // to read either all or the required parts of the data. When processing
  // keyed objects with PROOF, the object is already loaded and is available
  // via the fObject pointer.
  //
  // This function should contain the "body" of the analysis. It can contain
  // simple or elaborate selection criteria, run algorithms on the data
  // of the event and typically fill histograms.
  //
  // The processing can be stopped by calling Abort().
  //
  // Use fStatus to set the return value of TTree::Process().
  //
  // The return value is currently not used.
  
  GetEntry(entry);
  if(isMC){
    weight = event_weight;
  }else{
    weight = 1;
  }
  Tout->Fill();

#ifdef Sample_JetHT
  
  ptcut = 550;
  DAK8_topcut = 0.920;
  
#endif
  
  int ngenelc = 0;
  int ngenmu = 0;
  int ngentau = 0;
  int ngenqg = 0;
  int ngenb = 0;
  
  TLorentzVector leptop4v[2];
  TLorentzVector leptop4v_daught[3][2];
  TLorentzVector hadtop4v[2];
  TLorentzVector hadtop4v_daught[3][2];
  int leptop_id_daught[2];
  
  if(isMC){

    for(int igen=0; igen<ngenparticles; igen++){
      if(abs(genpartstatus[igen])!=23 && genpartstatus[igen]!=1) continue;
      if(!(genpartfromhard[igen]) /*|| !(genpartfromhardbFSR[igen])*/) continue;

      if(abs(genpartpdg[igen])==11) {
        genelectronpt[ngenelc] = genpartpt[igen];
        genelectroneta[ngenelc] = genparteta[igen];
        genelectronphi[ngenelc] = genpartphi[igen];
        genelectronm[ngenelc] = genpartm[igen];
        ngenelc++;
      }
      if(abs(genpartpdg[igen])==13) {
        genmuonpt[ngenmu] = genpartpt[igen];
	genmuoneta[ngenmu] = genparteta[igen];
        genmuonphi[ngenmu] = genpartphi[igen];
        genmuonm[ngenmu] = genpartm[igen];
        ngenmu++;
      }
      if(abs(genpartpdg[igen])==15) {
	gentaupt[ngentau] = genpartpt[igen];
        gentaueta[ngentau] = genparteta[igen];
        gentauphi[ngentau] = genpartphi[igen];
        gentaum[ngentau] = genpartm[igen];
        ngentau++;
      }
      if((abs(genpartpdg[igen])>=1 && abs(genpartpdg[igen])<5)||(abs(genpartpdg[igen])==21)) {
        genqgpt[ngenqg] = genpartpt[igen];
        genqgeta[ngenqg] = genparteta[igen];
        genqgphi[ngenqg] = genpartphi[igen];
        genqgm[ngenqg] = genpartm[igen];
        ngenqg++;
      }
      if(abs(genpartpdg[igen])==5) {
        genbpt[ngenb] = genpartpt[igen];
        genbeta[ngenb] = genparteta[igen];
        genbphi[ngenb] = genpartphi[igen];
        genbm[ngenb] = genpartm[igen];
        ngenb++;
      }
    }
    ngenelectrons = ngenelc;
    ngenmuons = ngenmu;
    ngentaus = ngentau;
    ngenqgs = ngenqg;
    ngenbs = ngenb;
    int ngent = 0;

    for(int igen=0; igen<ngenparticles; igen++){

      if(abs(genpartstatus[igen])!=22) continue;
      if(!(genpartfromhard[igen])) continue;
      if(abs(genpartpdg[igen])!=6) continue;

      gentoppt[ngent] = genpartpt[igen];
      gentopeta[ngent] = genparteta[igen];
      gentopphi[ngent] = genpartphi[igen];
      gentopm[ngent] = genpartm[igen];
      gentopid[ngent] = igen;

      ngent++;
    }

    ngentops = ngent;
  }

  int top_dp[6];
  int idp = 0;
  int ndq = 0; int ndb = 0; int ndl = 0;
  int top_dqp[4] = {-1,-1,-1,-1};
  int top_dbp[2] = {-1,-1};
  int top_dlp[4] = {-1,-1,-1,-1};
  
  for(int igen=0; igen<ngenparticles; igen++){
    
    if(!(genpartstatus[igen]==23 || genpartstatus[igen]==1)) continue;
    if(!(genpartfromhard[igen])) continue;
    
    if(!((abs(genpartpdg[igen])>=1 && abs(genpartpdg[igen])<=5)||(abs(genpartpdg[igen])>=11 && abs(genpartpdg[igen])<=16))) continue;
    if(!(abs(genpartmompdg[igen])==6 || abs(genpartmompdg[igen])==24)) continue;
    top_dp[idp] = igen;
    if(abs(genpartpdg[igen])>=1 && abs(genpartpdg[igen])<5 && abs(genpartmompdg[igen])==24) {  top_dqp[ndq] = igen;  ndq++; }
    if(abs(genpartpdg[igen])>=11 && abs(genpartpdg[igen])<=16 && abs(genpartmompdg[igen])==24) {  top_dlp[ndl] = igen;  ndl++; }
    if(abs(genpartpdg[igen])==5 && abs(genpartmompdg[igen])==6) {  top_dbp[ndb] = igen;  ndb++; }
    idp++;
  }
  
  if(isMC && isTT){
    
    nleptop = nhadtop = -1;

    if(ndl==0) { nleptop = 0; }
    if(ndl==2) { nleptop = 1; }
    if(ndl==4) { nleptop = 2; }
    
    if(ndq==0) { nhadtop = 0; }
    if(ndq==2) { nhadtop = 1; }
    if(ndq==4) { nhadtop = 2; }
    
    for(int ilep=0; ilep<ndl; ilep++){
      for(int jlep=(ilep+1); jlep<ndl; jlep++){
	if((abs(abs(genpartpdg[top_dlp[ilep]])-abs(genpartpdg[top_dlp[jlep]]))==1) && (genpartpdg[top_dlp[ilep]]*genpartpdg[top_dlp[jlep]]<0) && (genpartmompdg[top_dlp[ilep]]==genpartmompdg[top_dlp[jlep]]))
	  {
	    genpartpair[top_dlp[ilep]] = top_dlp[jlep];
	    genpartpair[top_dlp[jlep]] = top_dlp[ilep];
	  }
      }
    }
    
    for(int iq=0; iq<ndq; iq++){
      for(int jq=(iq+1); jq<ndq; jq++){
	if( ( (abs(abs(genpartpdg[top_dqp[iq]])-abs(genpartpdg[top_dqp[jq]]))==1)||(abs(abs(genpartpdg[top_dqp[iq]])-abs(genpartpdg[top_dqp[jq]]))==3) ) && (genpartpdg[top_dqp[iq]]*genpartpdg[top_dqp[jq]]<0) && (genpartmompdg[top_dqp[iq]]==genpartmompdg[top_dqp[jq]]) )
	  {
	    genpartpair[top_dqp[iq]] = top_dqp[jq];
	    genpartpair[top_dqp[jq]] = top_dqp[iq];
	  }
      }
    }
    
    int ileptop = 0;
    int ihadtop = 0;
    
    if(nleptop>0){
      
      for(int ilep=0; ilep<ndl; ilep++){
	if(!((abs(genpartpdg[top_dlp[ilep]])==11 || abs(genpartpdg[top_dlp[ilep]])==13 || abs(genpartpdg[top_dlp[ilep]])==15) && genpartpair[top_dlp[ilep]]>=0)) continue;
	
	for(int ib=0; ib<ndb; ib++){
	  
	  if(genpartmompdg[top_dbp[ib]]*genpartmompdg[top_dlp[ilep]]>0){
	    TLorentzVector b4; b4.SetPtEtaPhiM(genpartpt[top_dbp[ib]],genparteta[top_dbp[ib]],genpartphi[top_dbp[ib]],genpartm[top_dbp[ib]]);
	    int ipar = top_dlp[ilep];
	    if(ipar>=0){
	      TLorentzVector q1; q1.SetPtEtaPhiM(genpartpt[ipar],genparteta[ipar],genpartphi[ipar],genpartm[ipar]);
	      int jpar = genpartpair[top_dlp[ilep]];
	      TLorentzVector q2; q2.SetPtEtaPhiM(genpartpt[jpar],genparteta[jpar],genpartphi[jpar],genpartm[jpar]);
	      leptop4v[ileptop] = (b4+q1+q2);
	      leptop4v_daught[0][ileptop] = q1;
	      leptop4v_daught[1][ileptop] = q2;
	      leptop4v_daught[2][ileptop] = b4;
	      leptop_id_daught[ileptop] = genpartpdg[top_dlp[ilep]];
	      
	      ileptop++;
	      break;
	    }
	  }
	  
	}
	if(ileptop>=nleptop) break;
      }
    }
    
    if(nhadtop>0){
      
      for(int iq=0; iq<ndq; iq++){
	
	if(!(( (abs(genpartpdg[top_dqp[iq]])==1) || (abs(genpartpdg[top_dqp[iq]])==3) ) && genpartpair[top_dqp[iq]]>=0)) continue;
	
	for(int ib=0; ib<ndb; ib++){
	  
	  if(genpartmompdg[top_dbp[ib]]*genpartmompdg[top_dqp[iq]]>0){
	    TLorentzVector b4; b4.SetPtEtaPhiM(genpartpt[top_dbp[ib]],genparteta[top_dbp[ib]],genpartphi[top_dbp[ib]],genpartm[top_dbp[ib]]);
	    int ipar = top_dqp[iq];
	    if(ipar>=0){
	      TLorentzVector q1; q1.SetPtEtaPhiM(genpartpt[ipar],genparteta[ipar],genpartphi[ipar],genpartm[ipar]);
	      int jpar = genpartpair[top_dqp[iq]];
	      TLorentzVector q2; q2.SetPtEtaPhiM(genpartpt[jpar],genparteta[jpar],genpartphi[jpar],genpartm[jpar]);
	      hadtop4v[ihadtop] = (b4+q1+q2);
	      hadtop4v_daught[0][ihadtop] = q1;
	      hadtop4v_daught[1][ihadtop] = q2;
	      hadtop4v_daught[2][ihadtop] = b4;
	      
	      ihadtop++;
	      break;
	    }
	  }
	  
	}
	if(ihadtop>=nhadtop) break;
      }
      
    }
    
    nleptop = ileptop;
    nhadtop = ihadtop;
    
  }//isMC
  
  DiLeptt = SemiLeptt = Hadtt = EE = MUMU = EMU = EJets = MUJets = TauTau = ETau = MuTau = false;
  
  if(nleptop==2 && nhadtop==0) { DiLeptt = true; }
  if(nleptop==1 && nhadtop==1) { SemiLeptt = true; }
  if(nleptop==0 && nhadtop==2) { Hadtt = true; }
  
  if(DiLeptt && abs(leptop_id_daught[0])==11 && abs(leptop_id_daught[1])==11) { EE = true; }
  if(DiLeptt && abs(leptop_id_daught[0])==13 && abs(leptop_id_daught[1])==13) { MUMU = true; }
  if(DiLeptt && abs(leptop_id_daught[0])==15 && abs(leptop_id_daught[1])==15) { TauTau = true; }
  if(DiLeptt && ((abs(leptop_id_daught[0])==11 && abs(leptop_id_daught[1])==13) || (abs(leptop_id_daught[0])==13 && abs(leptop_id_daught[1])==11)) ) { EMU = true; }
  if(DiLeptt && ((abs(leptop_id_daught[0])==11 && abs(leptop_id_daught[1])==15) || (abs(leptop_id_daught[0])==15 && abs(leptop_id_daught[1])==11)) ) { ETau = true; }
  if(DiLeptt && ((abs(leptop_id_daught[0])==13 && abs(leptop_id_daught[1])==15) || (abs(leptop_id_daught[0])==15 && abs(leptop_id_daught[1])==13)) ) { MuTau = true; }
  
  
  if(SemiLeptt && abs(leptop_id_daught[0])==11) { EJets = true; }
  if(SemiLeptt && abs(leptop_id_daught[0])==13) { MUJets = true; }
  if(SemiLeptt && abs(leptop_id_daught[0])==15) { TAUJets = true; }
  
  bool boosted = ((SemiLeptt && (leptop4v[0].Pt()>400)) || (DiLeptt && ((abs(leptop_id_daught[0])==11 && (leptop4v[0].Pt()>400)) || (abs(leptop_id_daught[1])==11 && (leptop4v[1].Pt()>400))))) ; 
  
#ifdef Data_MC
  //if((isTT && SemiLeptt && EJets)) return kFALSE;
  if((isTT && DiLeptt && EMU)) return kFALSE;
  //#else
  //  if((isTT && SemiLeptt && EJets && boosted)) return kFALSE;
  //  if((isTT && DiLeptt && EMU && boosted)) return kFALSE;
#endif
  
  hist_event_count->Fill(1,weight);
  
  int nbjet_cut = -1;
#ifdef E_MU_TTBar
  nbjet_cut = 1;
#elif defined(E_Jets_TTBar)
   nbjet_cut = 1;
#endif
  int nmuon1 = 0;
  for(int mu=0; mu<nmuons; mu++){
    
    //#elif defined(E_MU_TTBar) && !defined(Data_MC)
    //if(muonpt[mu]<53.) continue;
    //#elif defined(E_MU_TTBar) && defined(Data_MC)
    //if(muonpt[mu]<50.) continue;
    //#else 
    if(muonpt[mu]<20.) continue; 
    
    if(fabs(muoneta[mu])>2.4)  continue; 
    bool mu_id = Muon_TightID(muonisGL[mu],muonisPF[mu],
			      muonchi[mu],muonthit[mu],muonmst[mu],
			      muontrkvtx[mu],muondz[mu],muonpixhit[mu],muontrklay[mu]);
    bool mu_iso = Muon_Iso_ID(muonpfiso[mu]);
    
    if(!mu_id) continue;
    //if(!mu_iso) continue;
    
    //2d iso //
    float dR_min = 1000;
    int nearjet = -1;
    
    for(int kjet=0; kjet<npfjetAK4; kjet++){
      if(pfjetAK4looseID[kjet]==0) continue;
      if(delta2R(pfjetAK4y[kjet],pfjetAK4phi[kjet],muoneta[mu],muonphi[mu]) < dR_min){
	dR_min = delta2R(pfjetAK4y[kjet],pfjetAK4phi[kjet],muoneta[mu],muonphi[mu]) ;
	nearjet = kjet;
      }
    }
    
    float muonpt_nearjet = 10000;
    if(nearjet>=0){
      TLorentzVector mu_mom; mu_mom.SetPtEtaPhiE(muonpt[mu],muoneta[mu],muonphi[mu],muone[mu]);
      TLorentzVector j_mom; j_mom.SetPtEtaPhiM(pfjetAK4pt[nearjet],pfjetAK4eta[nearjet],pfjetAK4phi[nearjet],pfjetAK4mass[nearjet]);
      muonpt_nearjet = ((mu_mom.Vect()).Perp(j_mom.Vect()));
    }
    bool mu_2diso = (nearjet>=0)?(dR_min > 0.4 ||  muonpt_nearjet > 15.):true;
    
    //2d iso ends//
    //#ifdef E_MU_TTBar
    //if(!mu_iso) continue;
    //#else
    //if(!mu_2diso) continue;
    //#endif
    
    muonpt[nmuon1] = muonpt[mu];
    muoneta[nmuon1] = muoneta[mu];
    muonphi[nmuon1] = muonphi[mu];
    muone[nmuon1] = muone[mu];
    muonp[nmuon1] = muonp[mu];
    muoncharge[nmuon1] = muoncharge[mu];
    nmuon1++;
    if(nmuon1 >= njetmx) break;
  }
  
  nmuons = nmuon1;
  
  int fjet = 0;
  for(int ijet=0; ijet<npfjetAK8; ijet++){
    
    if(!pfjetAK8looseID[ijet]) continue; //switch to tight ID (even tight ID calculation also do here in this code)
    
    if(fabs(pfjetAK8y[ijet])>2.5) continue;
    pfjetAK8pt[ijet] *= pfjetAK8JEC[ijet] ;
    pfjetAK8mass[ijet] *= pfjetAK8JEC[ijet];
    
    if(isMC){
       pfjetAK8pt[ijet] *= (1+pfjetAK8reso[ijet]) ;
       pfjetAK8mass[ijet] *= (1+pfjetAK8reso[ijet]) ;
      //pfjetAK8sdmass[ijet] *= (1+pfjetAK8reso[ijet]) ;

      pfjetAK8pt_resoup[ijet] = pfjetAK8pt[ijet]*(1+pfjetAK8resoup[ijet]);
      pfjetAK8mass_resoup[ijet] = pfjetAK8mass[ijet]*(1+pfjetAK8resoup[ijet]);
      pfjetAK8pt_resodown[ijet] = pfjetAK8pt[ijet]*(1+pfjetAK8resodn[ijet]);
      pfjetAK8mass_resodown[ijet] = pfjetAK8mass[ijet]*(1+pfjetAK8resodn[ijet]);
    }
    
    if(pfjetAK8pt[ijet] < ptcut) continue;
    //if (pfjetAK8elinsubpt[ijet] < 0 && pfjetAK8elinsubjpt[ijet]< 0) continue;
    //if (pfjetAK8muinsubpt[ijet] < 0 && pfjetAK8muinsubjpt[ijet]< 0) continue;

    pfjetAK8jesup_total[fjet] = pfjetAK8jesup_total[ijet];
    pfjetAK8jesdn_total[fjet] = pfjetAK8jesdn_total[ijet];
    
    pfjetAK8pt_resoup[fjet] = pfjetAK8pt_resoup[ijet];
    pfjetAK8mass_resoup[fjet] = pfjetAK8mass_resoup[ijet];
    pfjetAK8pt_resodown[fjet] = pfjetAK8pt_resodown[ijet];
    pfjetAK8mass_resodown[fjet] = pfjetAK8mass_resodown[ijet];

    pfjetAK8pt[fjet] = pfjetAK8pt[ijet];
    pfjetAK8mass[fjet] = pfjetAK8mass[ijet];
    pfjetAK8y[fjet] = pfjetAK8y[ijet];
    pfjetAK8phi[fjet] = pfjetAK8phi[ijet];
    pfjetAK8chrad[fjet] = pfjetAK8chrad[ijet];
    pfjetAK8tau21[fjet] = pfjetAK8tau2[ijet]*1./pfjetAK8tau1[ijet];
    pfjetAK8tau32[fjet] = pfjetAK8tau3[ijet]*1./pfjetAK8tau2[ijet];
    pfjetAK8DeepTag_TvsQCD[fjet] = pfjetAK8DeepTag_TvsQCD[ijet];
    pfjetAK8DeepTag_WvsQCD[fjet] = pfjetAK8DeepTag_WvsQCD[ijet];
    pfjetAK8DeepTag_ZvsQCD[fjet] = pfjetAK8DeepTag_ZvsQCD[ijet];
    pfjetAK8btag_DeepCSV[fjet] = pfjetAK8btag_DeepCSV[ijet];
    pfjetAK8btag_CMVA[fjet] = pfjetAK8btag_CMVA[ijet];
    pfjetAK8CHF[fjet] = pfjetAK8CHF[ijet];
    pfjetAK8NHF[fjet] = pfjetAK8NHF[ijet];
    pfjetAK8CEMF[fjet] = pfjetAK8CEMF[ijet];
    pfjetAK8NEMF[fjet] = pfjetAK8NEMF[ijet];
    pfjetAK8MUF[fjet] = pfjetAK8MUF[ijet];
    pfjetAK8PHF[fjet] = pfjetAK8PHF[ijet];
    pfjetAK8HadF[fjet] = (pfjetAK8NHF[fjet]+pfjetAK8CHF[fjet]);
    pfjetAK8NHadF[fjet] = (1.-pfjetAK8HadF[fjet]);
    pfjetAK8EmF[fjet] = (pfjetAK8NEMF[fjet]+pfjetAK8CEMF[fjet]);
    pfjetAK8EEM[fjet] = pfjetAK8EEM[ijet];
    pfjetAK8ncons[fjet] = pfjetAK8Chcons[ijet]+pfjetAK8Neucons[ijet];
    pfjetAK8Chcons[fjet] = pfjetAK8Chcons[ijet];
    pfjetAK8neuemfrac[fjet] = (pfjetAK8NEMF[fjet]*1./pfjetAK8EmF[fjet]);
    pfjetAK8neunhadfrac[fjet] = (pfjetAK8NEMF[fjet]*1./pfjetAK8NHadF[fjet]);
    pfjetAK8sdmass[fjet] = pfjetAK8sdmass[ijet];
    pfjetAK8sub1pt[fjet] = pfjetAK8sub1pt[ijet];
    pfjetAK8sub1eta[fjet] = pfjetAK8sub1eta[ijet];
    pfjetAK8sub1phi[fjet] = pfjetAK8sub1phi[ijet];
    pfjetAK8sub1mass[fjet] = pfjetAK8sub1mass[ijet];
    pfjetAK8sub1btag[fjet] = pfjetAK8sub1btag[ijet];
    pfjetAK8sub1hadfrac[fjet] = pfjetAK8sub1chhadfrac[ijet]+pfjetAK8sub1neuhadfrac[ijet];
    pfjetAK8sub1emfrac[fjet] = pfjetAK8sub1emfrac[ijet];//pfjetAK8sub1chemfrac[ijet]+pfjetAK8sub1frac[ijet];
    pfjetAK8sub2pt[fjet] = pfjetAK8sub2pt[ijet];
    pfjetAK8sub2eta[fjet] = pfjetAK8sub2eta[ijet];
    pfjetAK8sub2phi[fjet] = pfjetAK8sub2phi[ijet];
    pfjetAK8sub2mass[fjet] = pfjetAK8sub2mass[ijet];
    pfjetAK8sub2btag[fjet] = pfjetAK8sub2btag[ijet];
    pfjetAK8sub2hadfrac[fjet] = pfjetAK8sub2chhadfrac[ijet]+pfjetAK8sub2neuhadfrac[ijet];
    pfjetAK8sub2emfrac[fjet] = pfjetAK8sub2emfrac[ijet];//pfjetAK8sub2chemfrac[ijet]+pfjetAK8sub2neuemfrac[ijet];
    pfjetAK8subbtag[fjet] = max(pfjetAK8sub1btag[fjet],pfjetAK8sub2btag[fjet]);
    pfjetAK8subhaddiff[fjet] = diff_func(pfjetAK8sub1hadfrac[fjet],pfjetAK8sub2hadfrac[fjet]);
    pfjetAK8subemdiff[fjet] = diff_func(pfjetAK8sub1emfrac[fjet],pfjetAK8sub2emfrac[fjet]);
    pfjetAK8subptdiff[fjet] = diff_func(pfjetAK8sub1pt[fjet],pfjetAK8sub2pt[fjet]);
    pfjetAK8_leppt[fjet] = pfjetAK8_leppt[ijet];
    pfjetAK8_lepeta[fjet] = pfjetAK8_lepeta[ijet];
    pfjetAK8_lepphi[fjet] = pfjetAK8_lepphi[ijet];
    pfjetAK8_lepe[fjet] = pfjetAK8_lepe[ijet];
    pfjetAK8_bpt[fjet] = pfjetAK8_bpt[ijet];
    pfjetAK8_beta[fjet] = pfjetAK8_beta[ijet];
    pfjetAK8_bphi[fjet] = pfjetAK8_bphi[ijet];
    pfjetAK8_be[fjet] = pfjetAK8_be[ijet];
    pfjetAK8_nupt[fjet] = pfjetAK8_nupt[ijet];
    pfjetAK8_nueta[fjet] = pfjetAK8_nueta[ijet];
    pfjetAK8_nuphi[fjet] = pfjetAK8_nuphi[ijet];
    pfjetAK8_nue[fjet] = pfjetAK8_nue[ijet];
    pfjetAK8_bbyW_E[fjet] = pfjetAK8_bbyW_E[ijet];
    pfjetAK8_Kfactor[fjet] = pfjetAK8_Kfactor[ijet];
    pfjetAK8_Rnew[fjet] = pfjetAK8_Rnew[ijet];

    pfjetAK8elinsubpt[fjet] = pfjetAK8elinsubpt[ijet];
    pfjetAK8elinsubeta[fjet] = pfjetAK8elinsubeta[ijet];
    pfjetAK8elinsubphi[fjet] = pfjetAK8elinsubphi[ijet];
    pfjetAK8elinsube[fjet] = pfjetAK8elinsube[ijet];
    pfjetAK8elinsubjpt[fjet] = pfjetAK8elinsubjpt[ijet];
    pfjetAK8elinsubjeta[fjet] = pfjetAK8elinsubjeta[ijet];
    pfjetAK8elinsubjphi[fjet] = pfjetAK8elinsubjphi[ijet];
    pfjetAK8elinsubjmass[fjet] = pfjetAK8elinsubjmass[ijet];

    pfjetAK8muinsubpt[fjet] = pfjetAK8muinsubpt[ijet];
    pfjetAK8muinsubeta[fjet] = pfjetAK8muinsubeta[ijet];
    pfjetAK8muinsubphi[fjet] = pfjetAK8muinsubphi[ijet];
    pfjetAK8muinsube[fjet] = pfjetAK8muinsube[ijet];
    pfjetAK8muinsubjpt[fjet] = pfjetAK8muinsubjpt[ijet];
    pfjetAK8muinsubjeta[fjet] = pfjetAK8muinsubjeta[ijet];
    pfjetAK8muinsubjphi[fjet] = pfjetAK8muinsubjphi[ijet];
    pfjetAK8muinsubjmass[fjet] = pfjetAK8muinsubjmass[ijet];
    
    pfjetAK8muinsubI0[fjet] = pfjetAK8muinsubI0[ijet];
    pfjetAK8muinsubInear[fjet] = pfjetAK8muinsubInear[ijet];
    pfjetAK8muinsubIfar[fjet] = pfjetAK8muinsubIfar[ijet];
    
    pfjetAK8haspfelectron[fjet] = false;
    pfjetAK8haselectron[fjet] = pfjetAK8hasmuon[fjet] = pfjetAK8hastau[fjet] = pfjetAK8hasqg[fjet] = pfjetAK8hasb[fjet] = pfjetAK8hasleptop[fjet] = pfjetAK8hashadtop[fjet] = pfjetAK8hastop[fjet] = false;
    pfjetAK8hasleptop_alldecay[fjet] = pfjetAK8hashadtop_alldecay[fjet] = false;
    
    if(isMC){
      for(int ngen=0; ngen<ngenelectrons; ngen++){
	if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],genelectroneta[ngen],genelectronphi[ngen])<0.6){
	  pfjetAK8haselectron[fjet] = true;
	  break;
	}
      }
      for(int ngen=0; ngen<ngenmuons; ngen++){
	if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],genmuoneta[ngen],genmuonphi[ngen])<0.6){
	  pfjetAK8hasmuon[fjet] = true;
	  break;
	}
      }
      
      for(int ngen=0; ngen<ngentaus; ngen++){
	if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],gentaueta[ngen],gentauphi[ngen])<0.6){
	  pfjetAK8hastau[fjet] = true;
	  break;
	}
      }
      
      for(int ngen=0; ngen<ngenqgs; ngen++){
	if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],genqgeta[ngen],genqgphi[ngen])<0.6){
	  pfjetAK8hasqg[fjet] = true;
	  break;
	}
      }
      
      for(int ngen=0; ngen<ngenbs; ngen++){
	if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],genbeta[ngen],genbphi[ngen])<0.6){
	  pfjetAK8hasb[fjet] = true;
	  break;
	}
      }
      for(int ngen=0; ngen<ngentops; ngen++){
	if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],gentopeta[ngen],gentopphi[ngen])<0.6){
	  pfjetAK8hastop[fjet] = true;
	  break;
	 }
      }
      
      for(int ilept=0; ilept<nleptop; ilept++){
	if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],leptop4v[ilept].Rapidity(),leptop4v[ilept].Phi())<0.6){
	  pfjetAK8hasleptop[fjet] = true;
	  break;
	}
      }
      for(int ilept=0; ilept<nleptop; ilept++){
	//if(!pfjetAK8hasleptop[fjet]) continue;                                        
	bool match[3] = {0};
	for(int idaut=0; idaut<3; idaut++){
	  if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],leptop4v_daught[idaut][ilept].Rapidity(),leptop4v_daught[idaut][ilept].Phi())<0.8){
	    match[idaut] = true;
	  }
	}
	if(match[0]&&match[1]&&match[2]){
	  pfjetAK8hasleptop_alldecay[fjet] = true;
	  break;
	}
      }
      
      for(int ihadt=0; ihadt<nhadtop; ihadt++){
	if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],hadtop4v[ihadt].Rapidity(),hadtop4v[ihadt].Phi())<0.6){
	  pfjetAK8hashadtop[fjet] = true;
	  break;
	}
      }
      
      for(int ihadt=0; ihadt<nhadtop; ihadt++){
	bool match[3] = {0};
	for(int idaut=0; idaut<3; idaut++){
	  if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],hadtop4v_daught[idaut][ihadt].Rapidity(),hadtop4v_daught[idaut][ihadt].Phi())<0.8){
	    match[idaut] = true;
	  }
	}
	if(match[0]&&match[1]&&match[2]){
	  pfjetAK8hashadtop_alldecay[fjet] = true;
	  break;
	}
      }
      
    }//if (isMC)
    
    if (pfjetAK8elinsubpt[ijet] > 0. && pfjetAK8elinsubjpt[ijet]> 0.) {
      if (delta2R(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet],pfjetAK8y[fjet],pfjetAK8phi[fjet]) < 0.8) {
	pfjetAK8haspfelectron[fjet] = true;
      }
    }
    
    int pfjetAK8mactAK4_i = -1;
    float minR = 0.4;
    
    for(int kjet=0; kjet<npfjetAK4; kjet++){
      if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],pfjetAK4y[kjet],pfjetAK4phi[kjet])<minR){
	minR = delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],pfjetAK4y[kjet],pfjetAK4phi[kjet]);
	pfjetAK8mactAK4_i = kjet;
      }
    }
    
    if(pfjetAK8mactAK4_i>=0){
      pfjetAK8matchAK4deepb[fjet] = pfjetAK4btag_DeepFlav[pfjetAK8mactAK4_i];
    }else{
      pfjetAK8matchAK4deepb[fjet] = -100;
    }
    
    pfjetAK8haspfmuon[fjet] = false;
    pfjetAK8muon[fjet] = -1;
    /*
      float minRmu = 0.8;
      for(int imu=0; imu<nmuons; imu++){
      if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],muoneta[imu],muonphi[imu])<minRmu){
      minRmu = delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],muoneta[imu],muonphi[imu]);
      pfjetAK8muon[fjet] = imu;
      }
      }
      pfjetAK8ele[fjet] = -1;
      float minRe = 0.8;
      for(int ie=0; ie<nelecs; ie++){
      if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],eleta[ie],elphi[ie])<minRe){
      minRe = delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],eleta[ie],elphi[ie]);
      pfjetAK8ele[fjet] = ie;
      }
      }*/
      
    if (pfjetAK8muinsubpt[ijet] > 0. && pfjetAK8muinsubjpt[ijet]> 0.) {
      if (delta2R(pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet],pfjetAK8y[fjet],pfjetAK8phi[fjet]) < 0.8) {
        pfjetAK8haspfmuon[fjet] = true;
      }
    }
    
    fjet++;
    if(fjet>=njetmxAK8) break;
    
  }//ijet
  
  npfjetAK8 = fjet;
  
  int maxM(-1);
  float LMass(0);
  for(int ljet=0; ljet< npfjetAK8; ljet++){
    if (!(isnan(pfjetAK8mass[ljet]))) {
      if (pfjetAK8mass[ljet] > LMass) {
	LMass = pfjetAK8mass[ljet];
	maxM = ljet;
      }
    }
  }
  
  int nelec1 = 0;
  for(int ie=0; ie<nelecs; ie++) {
    //#ifdef E_Jets_TTBar
    // if(fabs(elpt[ie])<125.) continue;
    //if(fabs(elpt[ie])<60.) continue;
    //#elif defined(E_MU_TTBar)
    //if(fabs(elpt[ie])<50.) continue; //if(fabs(elpt[ie])<25.) continue; 
    //#endif
    if (elpt[ie]<20.) continue;
    if(fabs(eleta[ie])>2.4)  continue; 
    // if(!elmvaid[ie]) continue;
    if(!elmvaid_noIso[ie]) continue;
    elpt[nelec1] = elpt[ie];
    eleta[nelec1] = eleta[ie];
    elphi[nelec1] = elphi[ie];
    elp[nelec1] = elp[ie];
    elmvaid[nelec1] = elmvaid[ie];
    elmvaid_noIso[nelec1] = elmvaid_noIso[ie];
    elpfiso[nelec1] = elpfiso[ie];
    elcharge[nelec1] = elcharge[ie];
    
    nelec1++;
    if(nelec1 >= njetmx) break;
    
  }
  nelecs = nelec1;
  
  fjet = 0;
  int nbjetAK4 = 0;
  int nbjetAK4_lead = 0;
  
  float btagwt = 1.;
  float btagwtup = 1.;
  float btagwtdown = 1.;
  float btag_eff = 1;
  float Event_HT = 0;

  std::vector<TLorentzVector> bjv;
  for(int ijet=0; ijet<npfjetAK4; ijet++){
    
    if(!pfjetAK4looseID[ijet]) continue; //switch to tight ID (even tight ID calculation also do here in this code)
    if(fabs(pfjetAK4eta[ijet])>2.4) continue;
    
    pfjetAK4pt[ijet] *= pfjetAK4JEC[ijet] ;
    pfjetAK4mass[ijet] *= pfjetAK4JEC[ijet];
    if(isMC){
      pfjetAK4pt[ijet] *= (1+pfjetAK4reso[ijet]) ;
      pfjetAK4mass[ijet] *= (1+pfjetAK4reso[ijet]) ;
    }
    
    if(pfjetAK4pt[ijet]<30.) continue;
    
    Event_HT += pfjetAK4pt[ijet];
    
    pfjetAK4pt[fjet] = pfjetAK4pt[ijet];
    pfjetAK4mass[fjet] = pfjetAK4mass[ijet];
    pfjetAK4eta[fjet] = pfjetAK4eta[ijet];
    pfjetAK4y[fjet] = pfjetAK4y[ijet];
    pfjetAK4phi[fjet] = pfjetAK4phi[ijet];
    pfjetAK4hadronflav[fjet] = pfjetAK4hadronflav[ijet];
    pfjetAK4partonflav[fjet] = pfjetAK4partonflav[ijet];
    pfjetAK4btag_DeepFlav[fjet] = pfjetAK4btag_DeepFlav[ijet];
    
    if(pfjetAK4btag_DeepFlav[fjet] > deep_btag_cut) { 
      if(abs(pfjetAK4hadronflav[fjet])==5){  hist_2D_bpass_flavb->Fill(pfjetAK4pt[fjet],fabs(pfjetAK4eta[fjet]),weight); }
      if(abs(pfjetAK4hadronflav[fjet])==4){  hist_2D_bpass_flavc->Fill(pfjetAK4pt[fjet],fabs(pfjetAK4eta[fjet]),weight); }
      if(abs(pfjetAK4hadronflav[fjet])!=5 &&abs(pfjetAK4hadronflav[fjet])!=4){  hist_2D_bpass_flavq->Fill(pfjetAK4pt[fjet],fabs(pfjetAK4eta[fjet]),weight); }
    }
    
    if(abs(pfjetAK4hadronflav[fjet])==5){ hist_2D_ball_flavb->Fill(pfjetAK4pt[fjet],fabs(pfjetAK4eta[fjet]),weight); }
    if(abs(pfjetAK4hadronflav[fjet])==4){ hist_2D_ball_flavc->Fill(pfjetAK4pt[fjet],fabs(pfjetAK4eta[fjet]),weight); }
    if(abs(pfjetAK4hadronflav[fjet])!=5 &&abs(pfjetAK4hadronflav[fjet])!=4){  hist_2D_ball_flavq->Fill(pfjetAK4pt[fjet],fabs(pfjetAK4eta[fjet]),weight); }
    
    if(pfjetAK4btag_DeepFlav[fjet] > deep_btag_cut) { nbjetAK4++; 
      TLorentzVector bv;
      bv.SetPtEtaPhiM(pfjetAK4pt[fjet],pfjetAK4y[fjet],pfjetAK4phi[fjet],pfjetAK4mass[fjet]);
      bjv.push_back(bv);
    }
    if((pfjetAK4btag_DeepFlav[fjet] > deep_btag_cut) && (fjet==0||fjet==1)) { nbjetAK4_lead++; }
    
    if(isMC){
      
      if(pfjetAK4btag_DeepFlav[fjet] > deep_btag_cut) { 
	
	btagwt *= max(float(0),float(BTag_SF(pfjetAK4hadronflav[fjet],"noSyst",pfjetAK4pt[fjet])));
	btagwtup *= max(float(0),float(BTag_SF(pfjetAK4hadronflav[fjet],"up",pfjetAK4pt[fjet])));
	btagwtdown *= max(float(0),float(BTag_SF(pfjetAK4hadronflav[fjet],"down",pfjetAK4pt[fjet])));
      } else{
	
	if(isTT){	btag_eff = BTag_MCEfficiency_TT(abs(pfjetAK4hadronflav[fjet]),pfjetAK4pt[fjet],pfjetAK4eta[fjet]);	}
	if(isST){	btag_eff = BTag_MCEfficiency_ST(abs(pfjetAK4hadronflav[fjet]),pfjetAK4pt[fjet],pfjetAK4eta[fjet]);	}
	if(isDIB){	btag_eff = BTag_MCEfficiency_DIB(abs(pfjetAK4hadronflav[fjet]),pfjetAK4pt[fjet],pfjetAK4eta[fjet]);	}
	if(isWJ){	btag_eff = BTag_MCEfficiency_WJ(abs(pfjetAK4hadronflav[fjet]),pfjetAK4pt[fjet],pfjetAK4eta[fjet]);	}
	if(isDY){	btag_eff = BTag_MCEfficiency_DY(abs(pfjetAK4hadronflav[fjet]),pfjetAK4pt[fjet],pfjetAK4eta[fjet]);	}
	if(isbQCD){	btag_eff = BTag_MCEfficiency_bQCD(abs(pfjetAK4hadronflav[fjet]),pfjetAK4pt[fjet],pfjetAK4eta[fjet]);	}
	
	btagwt *= max(float(0),float((1. - btag_eff*BTag_SF(pfjetAK4hadronflav[fjet],"noSyst",pfjetAK4pt[fjet]))*1./(1. - btag_eff)) );
	btagwtup *= max(float(0),float((1. - btag_eff*BTag_SF(pfjetAK4hadronflav[fjet],"up",pfjetAK4pt[fjet]))*1./(1. - btag_eff)) );
	btagwtdown *= max(float(0),float((1. - btag_eff*BTag_SF(pfjetAK4hadronflav[fjet],"down",pfjetAK4pt[fjet]))*1./(1. - btag_eff)) );
      }
    }
    
    fjet++;
    if(fjet >= njetmx) break;
  }
  
  npfjetAK4 = fjet;
  
  hist_npv_nopuwt->Fill(nchict,weight);
  
  if(isMC){
    
    hist_npu_nopuwt->Fill(npu_vert,weight);
    
    if(npu_vert>=0 && npu_vert<100){
      puWeight = pu_rat18[npu_vert];
      puWeightUp = pu_rat18_up[npu_vert];
      puWeightDown = pu_rat18_dn[npu_vert];
    }
    if(!isnan(puWeightUp) || fabs(puWeightUp)<1.e+6){
      weight_puwup = weight*puWeightUp;
    }
    if(!isnan(puWeightDown) || fabs(puWeightDown)<1.e+6){
      weight_puwdown = weight*puWeightDown;
    }

    if(!isnan(puWeight) || fabs(puWeight)<1.e+6){
      weight *= puWeight;  
    }
    hist_npu->Fill(npu_vert,weight);
  }
  hist_npv->Fill(nchict,weight);
  hist_nprim->Fill(nprimi,weight);

  if((!isnan(btagwtup) || fabs(btagwtup)<1.e+6) && nbjet_cut>0){
    weight_btagwup = weight*btagwtup;
  }
  if((!isnan(btagwtdown) || fabs(btagwtdown)<1.e+6) && nbjet_cut>0){
    weight_btagwdown = weight*btagwtdown;
  }

  if((!isnan(btagwt) || fabs(btagwt)<1.e+6) && nbjet_cut>0){
    weight *= btagwt;
    weight_puwup *= btagwt;
    weight_puwdown *= btagwt;
  }
  
  for(int ijet=0; ijet< npfjetAK8; ijet++){
    
    if(ijet>(nmaxjet-1)) break;
    
    if(isnan(pfjetAK8pt[ijet])) { pfjetAK8pt[ijet] = -100; }
    if(isnan(pfjetAK8y[ijet])) { pfjetAK8y[ijet] = -100; }
    if(isnan(pfjetAK8mass[ijet])) { pfjetAK8mass[ijet] = -100; }
    if(isnan(pfjetAK8phi[ijet])) { pfjetAK8phi[ijet] = -100; }
    if(isnan(pfjetAK8btag_CMVA[ijet])) { pfjetAK8btag_CMVA[ijet] = -100; }
    if(isnan(pfjetAK8btag_CSV[ijet])) { pfjetAK8btag_CSV[ijet] = -100; }
    if(isnan(pfjetAK8btag_DeepCSV[ijet])) { pfjetAK8btag_DeepCSV[ijet] = -100; }
    if(isnan(pfjetAK8matchAK4deepb[ijet])) { pfjetAK8matchAK4deepb[ijet] = -100; }
    if(isnan(pfjetAK8DeepTag_TvsQCD[ijet])) { pfjetAK8DeepTag_TvsQCD[ijet] = -100; }
    if(isnan(pfjetAK8DeepTag_WvsQCD[ijet])) { pfjetAK8DeepTag_WvsQCD[ijet] = -100; }
    if(isnan(pfjetAK8DeepTag_ZvsQCD[ijet])) { pfjetAK8DeepTag_ZvsQCD[ijet] = -100; }
    if(isnan(pfjetAK8CHF[ijet])) { pfjetAK8CHF[ijet] = -100; }
    if(isnan(pfjetAK8NHF[ijet])) { pfjetAK8NHF[ijet] = -100; }
    if(isnan(pfjetAK8CEMF[ijet])) { pfjetAK8CEMF[ijet] = -100; }
    if(isnan(pfjetAK8NEMF[ijet])) { pfjetAK8NEMF[ijet] = -100; }
    if(isnan(pfjetAK8MUF[ijet])) { pfjetAK8MUF[ijet] = -100; }
    if(isnan(pfjetAK8HOF[ijet])) { pfjetAK8HOF[ijet] = -100; }
    if(isnan(pfjetAK8HadF[ijet])) { pfjetAK8HadF[ijet] = -100; }
    if(isnan(pfjetAK8NHadF[ijet])) { pfjetAK8NHadF[ijet] = -100; }
    if(isnan(pfjetAK8EmF[ijet])) { pfjetAK8EmF[ijet] = -100; }
    if(isnan(pfjetAK8neuemfrac[ijet])) { pfjetAK8neuemfrac[ijet] = -100; }
    if(isnan(pfjetAK8neunhadfrac[ijet])) { pfjetAK8neunhadfrac[ijet] = -100; }
    if(isnan(pfjetAK8EEM[ijet])) { pfjetAK8EEM[ijet] = -100; }
    if(isnan(pfjetAK8chrad[ijet])) { pfjetAK8chrad[ijet] = -100; }
    if(isnan(pfjetAK8pTD[ijet])) { pfjetAK8pTD[ijet] = -100; }
    if(isnan(pfjetAK8sdmass[ijet])) { pfjetAK8sdmass[ijet] = -100; }
    if(isnan(pfjetAK8elsubjptrat[ijet])) { pfjetAK8elsubjptrat[ijet] = -100; }
    if(isnan(pfjetAK8elinsubpt[ijet])) { pfjetAK8elinsubpt[ijet] = -100; }
    if(isnan(pfjetAK8elinsubeta[ijet])) { pfjetAK8elinsubeta[ijet] = -100; }
    if(isnan(pfjetAK8elinsubphi[ijet])) { pfjetAK8elinsubphi[ijet] = -100; }
    if(isnan(pfjetAK8elinsube[ijet])) { pfjetAK8elinsube[ijet] = -100; }
    if(isnan(pfjetAK8elinsubjpt[ijet])) { pfjetAK8elinsubjpt[ijet] = -100; }
    if(isnan(pfjetAK8elinsubjeta[ijet])) { pfjetAK8elinsubjeta[ijet] = -100; }
    if(isnan(pfjetAK8elinsubjphi[ijet])) { pfjetAK8elinsubjphi[ijet] = -100; }
    if(isnan(pfjetAK8elinsubjmass[ijet])) { pfjetAK8elinsubjmass[ijet] = -100; }
    
    if(isnan(pfjetAK8muinsubpt[ijet])) { pfjetAK8muinsubpt[ijet] = -100; }
    if(isnan(pfjetAK8muinsubeta[ijet])) { pfjetAK8muinsubeta[ijet] = -100; }
    if(isnan(pfjetAK8muinsubphi[ijet])) { pfjetAK8muinsubphi[ijet] = -100; }
    if(isnan(pfjetAK8muinsube[ijet])) { pfjetAK8muinsube[ijet] = -100; }
    if(isnan(pfjetAK8muinsubjpt[ijet])) { pfjetAK8muinsubjpt[ijet] = -100; }
    if(isnan(pfjetAK8muinsubjeta[ijet])) { pfjetAK8muinsubjeta[ijet] = -100; }
    if(isnan(pfjetAK8muinsubjphi[ijet])) { pfjetAK8muinsubjphi[ijet] = -100; }
    if(isnan(pfjetAK8muinsubjmass[ijet])) { pfjetAK8muinsubjmass[ijet] = -100; }
    
    if(isnan(pfjetAK8muinsubI0[ijet])) { pfjetAK8muinsubI0[ijet] = -100; }
    if(isnan(pfjetAK8muinsubInear[ijet])) { pfjetAK8muinsubInear[ijet] = -100; }
    if(isnan(pfjetAK8muinsubIfar[ijet])) { pfjetAK8muinsubIfar[ijet] = -100; }
    
    if(isnan(pfjetAK8tau21[ijet])) { pfjetAK8tau21[ijet] = -100; }
    if(isnan(pfjetAK8tau32[ijet])) { pfjetAK8tau32[ijet] = -100; }
    if(isnan(pfjetAK8sub1mass[ijet])) { pfjetAK8sub1mass[ijet] = -100; }
    if(isnan(pfjetAK8sub1btag[ijet])) { pfjetAK8sub1btag[ijet] = -100; }
    if(isnan(pfjetAK8sub1hadfrac[ijet])) { pfjetAK8sub1hadfrac[ijet] = -100; }
    if(isnan(pfjetAK8sub1emfrac[ijet])) { pfjetAK8sub1emfrac[ijet] = -100; }
    if(isnan(pfjetAK8sub2mass[ijet])) { pfjetAK8sub2mass[ijet] = -100; }
    if(isnan(pfjetAK8sub2btag[ijet])) { pfjetAK8sub2btag[ijet] = -100; }
    if(isnan(pfjetAK8sub2hadfrac[ijet])) { pfjetAK8sub2hadfrac[ijet] = -100; }
    if(isnan(pfjetAK8sub2emfrac[ijet])) { pfjetAK8sub2emfrac[ijet] = -100; }
    if(isnan(pfjetAK8subhaddiff[ijet])) { pfjetAK8subhaddiff[ijet] = -100; }
    if(isnan(pfjetAK8subemdiff[ijet])) { pfjetAK8subemdiff[ijet] = -100; }
    if(isnan(pfjetAK8subptdiff[ijet])) { pfjetAK8subptdiff[ijet] = -100; }
    if(isnan(pfjetAK8subbtag[ijet])) { pfjetAK8subbtag[ijet] = -100; }
    if(isnan(pfjetAK8haselectron[ijet])) { pfjetAK8haselectron[ijet] = -100; }
    if(isnan(pfjetAK8hasmuon[ijet])) { pfjetAK8hasmuon[ijet] = -100; }
    if(isnan(pfjetAK8hasleptop[ijet])) { pfjetAK8hasleptop[ijet] = -100; }
    if(isnan(pfjetAK8hashadtop[ijet])) { pfjetAK8hashadtop[ijet] = -100; }
    if(isnan(pfjetAK8hasqg[ijet])) { pfjetAK8hasqg[ijet] = -100; }
    if(isnan(pfjetAK8hasb[ijet])) { pfjetAK8hasb[ijet] = -100; }
    if(isnan(pfjetAK8_bbyW_E[ijet])) { pfjetAK8_bbyW_E[ijet] = -100; }
    if(isnan(pfjetAK8_Kfactor[ijet])) { pfjetAK8_Kfactor[ijet] = -100; }
    if(isnan(pfjetAK8_Rnew[ijet])) { pfjetAK8_Rnew[ijet] = -100; }
    if(isnan(pfjetAK8_leppt[ijet])) { pfjetAK8_leppt[ijet] = -100; }
    if(isnan(pfjetAK8_bpt[ijet])) { pfjetAK8_bpt[ijet] = -100; }
    if(isnan(pfjetAK8_nupt[ijet])) { pfjetAK8_nupt[ijet] = -100; }
    
    Float_t Re(-100);
      
    in_pfjetAK8NHadF = -999;                                                            
    in_pfjetAK8neunhadfrac = -999;
    in_pfjetAK8subhaddiff = -999;
    in_pfjetAK8tau21 = -999;
    in_pfjetAK8chrad = -999;
    in_pfjetAK8sdmass = -999;
    in_pfjetAK8matchedmuonchi = -999;
    in_pfjetAK8matchedmuonposmatch = -999;
    in_pfjetAK8matchedmuontrkink = -999;
    in_pfjetAK8matchedmuonsegcom = -999;
    in_pfjetAK8matchedmuonhit = -999;
    in_pfjetAK8matchedmuonmst = -999;
    in_pfjetAK8matchedmuontrkvtx = -999;
    in_pfjetAK8matchedmuondz = -999;
    in_pfjetAK8matchedmuonpixhit = -999;
    in_pfjetAK8matchedmuontrklay = -999;
    in_pfjetAK8matchedmuonvalfrac = -999;
    in_pfjetAK8muinsubptrat = -999;
    in_pfjetAK8muinsubmassrat = -999;
    in_pfjetAK8muinsubinvmass = -999;
    in_pfjetAK8muinsubIfarbyI0 = -999;
    in_pfjetAK8muinsubInearbyI0 = -999;

    pfjetAK8_hasmatchmu[ijet] = false;

    if (pfjetAK8muinsubeta[ijet] != -100 && pfjetAK8muinsubphi[ijet] != -100)
      {
        if (nmuons > 0) {
          float dR_min(0.4); int nearestmu(-1);
          for(int mu=0; mu<nmuons; mu++){
            float dR = delta2R(muoneta[mu],muonphi[mu],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet]);
            if (dR < dR_min) {
              dR_min = dR;
              nearestmu = mu;
            }
          }
          if (nearestmu >= 0) {

	    in_pfjetAK8NHadF = pfjetAK8NHadF[ijet];
            in_pfjetAK8neunhadfrac = pfjetAK8neunhadfrac[ijet];
            in_pfjetAK8subhaddiff = pfjetAK8subhaddiff[ijet];
            in_pfjetAK8tau21 = pfjetAK8tau21[ijet];
            in_pfjetAK8chrad = pfjetAK8chrad[ijet];
            in_pfjetAK8sdmass = pfjetAK8sdmass[ijet];
	    in_pfjetAK8matchedmuonchi = muonchi[nearestmu];
	    in_pfjetAK8matchedmuonposmatch = muonposmatch[nearestmu];
	    in_pfjetAK8matchedmuontrkink = muontrkink[nearestmu];
	    in_pfjetAK8matchedmuonsegcom = muonsegcom[nearestmu];
	    in_pfjetAK8matchedmuonhit = muonthit[nearestmu];
	    in_pfjetAK8matchedmuonmst = muonmst[nearestmu];
	    in_pfjetAK8matchedmuontrkvtx = muontrkvtx[nearestmu];
	    in_pfjetAK8matchedmuondz = muondz[nearestmu];
	    in_pfjetAK8matchedmuonpixhit = muonpixhit[nearestmu];
	    in_pfjetAK8matchedmuontrklay = muontrklay[nearestmu];
	    in_pfjetAK8matchedmuonvalfrac = muonvalfrac[nearestmu];
	    
	    TLorentzVector lep, lepbj, bj;
	    lep.SetPtEtaPhiE(pfjetAK8muinsubpt[ijet],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet],pfjetAK8muinsube[ijet]);
	    bj.SetPtEtaPhiM(pfjetAK8muinsubjpt[ijet],pfjetAK8muinsubjeta[ijet],pfjetAK8muinsubjphi[ijet],pfjetAK8muinsubjmass[ijet]);
	    lepbj = lep + bj;

	    in_pfjetAK8muinsubptrat = (lep.Pt())/(lepbj.Pt());
	    in_pfjetAK8muinsubmassrat = (bj.M())/(lepbj.M());
	    in_pfjetAK8muinsubinvmass = lepbj.M();
	    
	    if(isnan(in_pfjetAK8muinsubptrat)) {in_pfjetAK8muinsubptrat = -100;}
	    if(isnan(in_pfjetAK8muinsubmassrat)) {in_pfjetAK8muinsubmassrat = -100;}
	    if(isnan(in_pfjetAK8muinsubinvmass)) {in_pfjetAK8muinsubinvmass = -100;}

	    in_pfjetAK8muinsubIfarbyI0 = pfjetAK8muinsubIfar[ijet]/pfjetAK8muinsubI0[ijet];
	    in_pfjetAK8muinsubInearbyI0 = pfjetAK8muinsubInear[ijet]/pfjetAK8muinsubI0[ijet];

	    if(isnan(in_pfjetAK8muinsubIfarbyI0)) {in_pfjetAK8muinsubIfarbyI0 = -100;}
	    if(isnan(in_pfjetAK8muinsubInearbyI0)) {in_pfjetAK8muinsubInearbyI0 = -100;}
	  }
	  pfjetAK8_hasmatchmu[ijet] = (nearestmu >= 0)?true:false;
	}
      }
  
    in_pfjetAK8eldxy_sv = -999;
    in_pfjetAK8matchedelcleta = -999;
    in_pfjetAK8matchedelpt = -999;
    in_pfjetAK8matchedelsigmaieta = -999;
    in_pfjetAK8matchedelsigmaiphi = -999;
    in_pfjetAK8matchedelr9full = -999;
    in_pfjetAK8matchedelsupcl_etaw = -999;
    in_pfjetAK8matchedelsupcl_phiw = -999;
    in_pfjetAK8matchedelhcaloverecal = -999;
    in_pfjetAK8matchedelcloctftrkn = -999;
    in_pfjetAK8matchedelcloctftrkchi2 = -999;
    in_pfjetAK8matchedele1x5bye5x5 = -999;
    in_pfjetAK8matchedelnormchi2 = -999;
    in_pfjetAK8matchedelhitsmiss = -999;
    in_pfjetAK8matchedeltrkmeasure = -999;
    in_pfjetAK8matchedelecloverpout = -999;
    in_pfjetAK8matchedelecaletrkmomentum = -999;
    in_pfjetAK8matchedeldeltaetacltrkcalo = -999;
    in_pfjetAK8matchedelsupcl_preshvsrawe = -999;
    in_pfjetAK8matchedelpfisolsumphet = -999;
    in_pfjetAK8matchedelpfisolsumchhadpt = -999;
    in_pfjetAK8matchedelpfisolsumneuhadet = -999;
    in_pfjetAK8matchedeletain = -999;
    in_pfjetAK8matchedelphiin = -999;
    in_pfjetAK8matchedelfbrem = -999;
    in_pfjetAK8matchedeleoverp = -999;
    in_pfjetAK8matchedelhovere = -999;
  
  
    pfjetAK8_hasmatche[ijet] = false;
    
    if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
      {
        if (nelecs > 0) {
          float dR_min(0.4); int nearest(-1);
          for(int el=0; el<nelecs; el++){
            float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
            if (dR < dR_min) {
              dR_min = dR;
              nearest = el;
            }
	  }
          if (nearest >= 0 && eldxy_sv[nearest] != 1000) {
	    in_pfjetAK8NHadF = pfjetAK8NHadF[ijet];
	    in_pfjetAK8neunhadfrac = pfjetAK8neunhadfrac[ijet];
	    in_pfjetAK8subhaddiff = pfjetAK8subhaddiff[ijet];
	    in_pfjetAK8tau21 = pfjetAK8tau21[ijet];
	    in_pfjetAK8chrad = pfjetAK8chrad[ijet];
	    in_pfjetAK8sdmass = pfjetAK8sdmass[ijet];
            in_pfjetAK8eldxy_sv = eldxy_sv[nearest];
	    in_pfjetAK8matchedelcleta = elsupcl_eta[nearest];
	    in_pfjetAK8matchedelpt = fabs(elpt[nearest]);
	    in_pfjetAK8matchedelsigmaieta = elsigmaieta[nearest];
            in_pfjetAK8matchedelsigmaiphi = elsigmaiphi[nearest];
	    in_pfjetAK8matchedelr9full = elr9full[nearest];
	    in_pfjetAK8matchedelsupcl_etaw = elsupcl_etaw[nearest];
            in_pfjetAK8matchedelsupcl_phiw = elsupcl_phiw[nearest];
	    in_pfjetAK8matchedelhcaloverecal = elhcaloverecal[nearest];
            in_pfjetAK8matchedelcloctftrkn = elcloctftrkn[nearest];
	    in_pfjetAK8matchedelcloctftrkchi2 = elcloctftrkchi2[nearest];
            in_pfjetAK8matchedele1x5bye5x5 = ele1x5bye5x5[nearest];
	    in_pfjetAK8matchedelnormchi2 = elnormchi2[nearest];
            in_pfjetAK8matchedelhitsmiss = elhitsmiss[nearest];
	    in_pfjetAK8matchedeltrkmeasure = eltrkmeasure[nearest];
	    in_pfjetAK8matchedelecloverpout = elecloverpout[nearest];
	    in_pfjetAK8matchedelecaletrkmomentum = elecaletrkmomentum[nearest];
	    in_pfjetAK8matchedeldeltaetacltrkcalo = eldeltaetacltrkcalo[nearest];
	    in_pfjetAK8matchedelsupcl_preshvsrawe = elsupcl_preshvsrawe[nearest];
	    in_pfjetAK8matchedelpfisolsumphet = elpfisolsumphet[nearest];
	    in_pfjetAK8matchedelpfisolsumchhadpt = elpfisolsumchhadpt[nearest];
	    in_pfjetAK8matchedelpfisolsumneuhadet = elpfsiolsumneuhadet[nearest];
	    in_pfjetAK8matchedeletain = eletain[nearest];
            in_pfjetAK8matchedelphiin = elphiin[nearest];
            in_pfjetAK8matchedelfbrem = elfbrem[nearest];
	    in_pfjetAK8matchedeleoverp = eleoverp[nearest];
            in_pfjetAK8matchedelhovere = elhovere[nearest];
	    
	  }
	  //pfjetAK8_hasmatche[ijet] = (nearest >= 0)?true:false;
	  pfjetAK8_hasmatche[ijet] = (nearest >= 0 && eldxy_sv[nearest] != 1000)?true:false;
	}
      }
    
    if (!isnan(Rho)) in_pfjetAK8matchedelRho = Rho;
    else in_pfjetAK8matchedelRho = -999;
    
    hist_2D_msd_deepak8->Fill(pfjetAK8sdmass[ijet],pfjetAK8DeepTag_TvsQCD[ijet]);
    
    pfjetAK8re_tvsb[ijet] = -100;
    Re = reader1->EvaluateMVA("BDTG method");
    pfjetAK8re_tvsb[ijet] = Re;
    
    in_pfjetAK8_bbyW_E = pfjetAK8_bbyW_E[ijet];
    in_pfjetAK8_Kfactor = pfjetAK8_Kfactor[ijet];
  
    Float_t Rnu(-100);
    Rnu = reader2->EvaluateMVA("BDTG method");
    pfjetAK8rnu_tvsb[ijet] = Rnu;
    
    pfjetAK8rt[ijet] = reader3->EvaluateMVA("BDTG method");
    pfjetAK8rmu_tvsb[ijet]  = reader4->EvaluateMVA("BDTG method");

  }//ijet
  
  int nelec2 = 0;
  std::vector<double> elptv;
  std::vector<double> eletav;
  std::vector<double> elphiv;
  std::vector<double> elev;
  std::vector<double> elchv;
  std::vector<TLorentzVector> elcandv;
  for(int ie=0; ie<nelec1; ie++) {
    
    if(elpt[ie]<30.) continue; 
    if(fabs(eleta[ie])>2.4)  continue; 
    if(!elmvaid_noIso[ie]) continue;

    /*
      elpt[nelec2] = fabs(elpt[ie]);
      eleta[nelec2] = eleta[ie];
      elphi[nelec2] = elphi[ie];
      elp[nelec2] = elp[ie];
      elmvaid[nelec2] = elmvaid[ie];
      elmvaid_noIso[nelec2] = elmvaid_noIso[ie];
      elpfiso[nelec2] = elpfiso[ie];
    */
    //TLorentzVector elcand;
    //elcand.SetPtEtaPhiE(elpt[ie],eleta[ie],elphi[ie],ele[ie]);
    //elcandv.push_back(elcand);
    
    elptv.push_back(elpt[ie]);
    eletav.push_back(eleta[ie]);
    elphiv.push_back(elphi[ie]);
    elev.push_back(ele[ie]);
    elchv.push_back(elcharge[ie]);

    nelec2++;
    if(nelec2 >= njetmx) break;
  }


  reOrder(elptv, eletav, elphiv, elev, elchv);
  std::vector<double> reelchv;

  for(unsigned int ivi=0; ivi<elptv.size(); ivi++){
    TLorentzVector elcand;
    elcand.SetPtEtaPhiE(elptv[ivi],eletav[ivi],elphiv[ivi],elev[ivi]);
    elcandv.push_back(elcand);
    reelchv.push_back(elchv[ivi]);
  }
   
  int nmuon2 = 0;
  
  std::vector<double> muptv;
  std::vector<double> muetav;
  std::vector<double> muphiv;
  std::vector<double> muev;
  std::vector<double> muchv;
  std::vector<TLorentzVector> mucandv;
  for(int imu=0; imu<nmuon1; imu++) {
    
    if(muonpt[imu]<30.) continue;
    if(fabs(muoneta[imu])>2.4)  continue;
    
    bool mu2_id = Muon_TightID(muonisGL[imu],muonisPF[imu],
                              muonchi[imu],muonthit[imu],muonmst[imu],
			       muontrkvtx[imu],muondz[imu],muonpixhit[imu],muontrklay[imu]);
    if(!mu2_id) continue;
    
    /*
      muonpt[nmuon2] = muonpt[imu];
      muoneta[nmuon2] = muoneta[imu];
      muonphi[nmuon2] = muonphi[imu];
      muonp[nmuon2] = muonp[imu];
      muone[nmuon2] = muone[imu];
    */
    
    //TLorentzVector mucand;
    //mucand.SetPtEtaPhiE(muonpt[imu],muoneta[imu],muonphi[imu],muone[imu]);
    //mucandv.push_back(mucand);

    muptv.push_back(muonpt[imu]);
    muetav.push_back(muoneta[imu]);
    muphiv.push_back(muonphi[imu]);
    muev.push_back(muone[imu]);
    muchv.push_back(muoncharge[imu]);

    nmuon2++;
    if( nmuon2 >= njetmx) break;
  }
  
  reOrder(muptv, muetav, muphiv, muev, muchv);
  std::vector<double> remuchv;

  for(unsigned int ivi=0; ivi<muptv.size(); ivi++){
    TLorentzVector mucand;                                                                                                                 
    mucand.SetPtEtaPhiE(muptv[ivi],muetav[ivi],muphiv[ivi],muev[ivi]);
    mucandv.push_back(mucand);
    remuchv.push_back(muchv[ivi]);
  }

  int t_cand = -1;
  double remax = -200;
  for(int ijet=0; ijet < npfjetAK8; ijet++){
    if(pfjetAK8re_tvsb[ijet] > remax){
      remax = pfjetAK8re_tvsb[ijet];
      t_cand = ijet;
    }
  }
  
  // top pt reweighting //
  
  if(isTT){
    
  TLorentzVector top4mom[2];
  
  int ngent = 0;
  
  for(int igen=0; igen<ngenparticles; igen++){
    
    if(abs(genpartstatus[igen])!=22) continue;
    if(!(genpartfromhard[igen])) continue;
    if(abs(genpartpdg[igen])!=6) continue;
    
    top4mom[ngent].SetPtEtaPhiM(genpartpt[igen],genparteta[igen],genpartphi[igen],genpartm[igen]);
    ngent++;
    if(ngent>=2) break;
    
  }
  
  float toppt_wt = 1;
  
  if(ngent==2){
    toppt_wt = SF_TOP(0.0416,0.0003,TMath::Min(float(500),float(top4mom[0].Pt())),TMath::Min(float(500),float(top4mom[1].Pt())));
  }
  
  weight *= toppt_wt;
  weight_puwup *= toppt_wt;
  weight_puwdown *= toppt_wt;
  weight_btagwup *= toppt_wt;
  weight_btagwdown *= toppt_wt;
  }
  // top pt reweighting ends //

  if(isnan(weight) || weight>1.e+12) { weight = 0; }
  if(isnan(weight_puwup) || weight_puwup>1.e+12) { weight_puwup = 0; }
  if(isnan(weight_puwdown) || weight_puwdown>1.e+12) { weight_puwdown = 0; }
  if(isnan(weight_btagwup) || weight_btagwup>1.e+12) { weight_btagwup = 0; }
  if(isnan(weight_btagwdown) || weight_btagwdown>1.e+12) { weight_btagwdown = 0; }
 
  // event selection starts
  hist_count->Fill(1,weight);
  
  //if(nchict<1) return kFALSE;
  if (nprimi<1) return kFALSE;  
  hist_count->Fill(2,weight);
  
  bool itrig_pass = false;
  bool itrig_epass = false;
  bool itrig_ljpass = false;
  
  // e + mu (dileptonic ttbar)
#ifdef E_MU_TTBar
  itrig_pass = ((ihlt09==1)||(ihlt10==1));
  if(!itrig_pass) return kFALSE;
  hist_count->Fill(3,weight);
  if (nmuon2 == 0) return kFALSE;
  hist_count->Fill(4,weight);
  if (nelec2 == 0) return kFALSE;
  hist_count->Fill(5,weight);

  /*
  if(mucandv.size()>2) {
  for(unsigned int iti=0; iti<mucandv.size()-2; iti++){
  TString str = TString::Format("hello pT for muon0 %f muon1 %f muon2 %f",mucandv[iti].Pt(),mucandv[iti+1].Pt(),mucandv[iti+2].Pt());
  if(gProofServ) gProofServ->SendAsynMessage(str);
  }
  }
  
  if (elcandv.size()>2) {
  for(unsigned int iui=0; iui<elcandv.size()-2; iui++){
  TString str1 = TString::Format("hello1 pT for electron0 %f electron1 %f electron2 %f",elcandv[iui].Pt(),elcandv[iui+1].Pt(),elcandv[iui+2].Pt());
  if(gProofServ) gProofServ->SendAsynMessage(str1);
  }
  }
  */
  
  //"HLT_Mu37_Ele27_CaloIdL_MW_v", "HLT_Mu27_Ele37_CaloIdL_MW_v"
  /*new addition of trigger checks*/
  float mulpt(0.), ellpt(0.);
  bool fsttrig = false; 
  bool sndtrig = false;
  bool bothtrig = false;
  
  if (ihlt09==1 && ihlt10==0) {
    mulpt=40.0; ellpt=30.0;
    fsttrig=true;
  }
  else if (ihlt09==0 && ihlt10==1) {
    mulpt=30.0; ellpt=40.0;
    sndtrig=true;
  }
  else if (ihlt09==1 && ihlt10==1) {
    mulpt=40.0; ellpt=40.0;
    bothtrig=true;
  }
  if (fsttrig==1 || sndtrig==1 || bothtrig==1) {if(!(mucandv[0].Pt()>mulpt && elcandv[0].Pt()>ellpt)) return kFALSE;}
  hist_count->Fill(6,weight);
/*****/
  std::vector<TLorentzVector> emupair;
  double ptsum(-99.);
  int itf(-1), iuf(-1);
  float fel_ch(-99.), fmu_ch(-99.);
  if (nmuon2>=1 && nelec2>=1) {
    double chksumpt(0.);
    for(unsigned int it=0; it<mucandv.size(); it++){
      for(unsigned int iu=0; iu<elcandv.size(); iu++){
	chksumpt = mucandv[it].Pt() + elcandv[iu].Pt();
	if (chksumpt > ptsum) {
	  ptsum = chksumpt;
	  itf = it;
	  iuf = iu;
	}
      }
    }
  }
  
  if (itf<0) return kFALSE;
  hist_count->Fill(7,weight);
  if (iuf<0) return kFALSE;
  hist_count->Fill(8,weight);
  fmu_ch = remuchv[itf];
  fel_ch = reelchv[iuf];
  
  if ((fmu_ch*fel_ch)>0) return kFALSE;
  hist_count->Fill(9,weight);
  
  if ((mucandv[itf] + elcandv[iuf]).M() < 20.) return kFALSE;
  hist_count->Fill(10,weight);
  
  //hist_nmu->Fill(nmuon1,weight);
  //hist_nel->Fill(nelec1,weight);
  
  if (nmuon1>1) return kFALSE;
  hist_count->Fill(11,weight);
  if (nelec1>1) return kFALSE;
  hist_count->Fill(12,weight);
  if (PFMET<100.) return kFALSE; //before it was 70 GeV. 100 GeV on 17th April  
  hist_count->Fill(13,weight);
  if (nbjetAK4 <1) return kFALSE;
  hist_count->Fill(14,weight);
  
  hist_init[0]->Fill(nmuon1,weight);
  hist_init[1]->Fill(nelec1,weight);
  hist_init[2]->Fill(PFMET,weight);
  hist_init[3]->Fill(nprimi,weight);
  hist_init[4]->Fill(npfjetAK4,weight);
  hist_init[5]->Fill(nbjetAK4,weight);
  hist_init[6]->Fill(npfjetAK8,weight);
  hist_init[7]->Fill((mucandv[itf] + elcandv[iuf]).M(),weight);
  hist_init[8]->Fill(mucandv[itf].Pt(),weight);
  hist_init[9]->Fill(mucandv[itf].Eta(),weight);
  hist_init[10]->Fill(mucandv[itf].Phi(),weight);
  hist_init[11]->Fill(elcandv[iuf].Pt(),weight);
  hist_init[12]->Fill(elcandv[iuf].Eta(),weight);
  hist_init[13]->Fill(elcandv[iuf].Phi(),weight);
  hist_init[14]->Fill(bjv[0].Pt(),weight);
  hist_init[15]->Fill(bjv[0].Eta(),weight);
  hist_init[16]->Fill(bjv[0].Phi(),weight);
  
  hist_initpuwup[0]->Fill(nmuon1,weight_puwup);
  hist_initpuwup[1]->Fill(nelec1,weight_puwup);
  hist_initpuwup[2]->Fill(PFMET,weight_puwup);
  hist_initpuwup[3]->Fill(nprimi,weight_puwup);
  hist_initpuwup[4]->Fill(npfjetAK4,weight_puwup);
  hist_initpuwup[5]->Fill(nbjetAK4,weight_puwup);
  hist_initpuwup[6]->Fill(npfjetAK8,weight_puwup);
  hist_initpuwup[7]->Fill((mucandv[itf] + elcandv[iuf]).M(),weight_puwup);
  hist_initpuwup[8]->Fill(mucandv[itf].Pt(),weight_puwup);
  hist_initpuwup[9]->Fill(mucandv[itf].Eta(),weight_puwup);
  hist_initpuwup[10]->Fill(mucandv[itf].Phi(),weight_puwup);
  hist_initpuwup[11]->Fill(elcandv[iuf].Pt(),weight_puwup);
  hist_initpuwup[12]->Fill(elcandv[iuf].Eta(),weight_puwup);
  hist_initpuwup[13]->Fill(elcandv[iuf].Phi(),weight_puwup);
  hist_initpuwup[14]->Fill(bjv[0].Pt(),weight_puwup);
  hist_initpuwup[15]->Fill(bjv[0].Eta(),weight_puwup);
  hist_initpuwup[16]->Fill(bjv[0].Phi(),weight_puwup);

  hist_initbtagwup[0]->Fill(nmuon1,weight_btagwup);
  hist_initbtagwup[1]->Fill(nelec1,weight_btagwup);
  hist_initbtagwup[2]->Fill(PFMET,weight_btagwup);
  hist_initbtagwup[3]->Fill(nprimi,weight_btagwup);
  hist_initbtagwup[4]->Fill(npfjetAK4,weight_btagwup);
  hist_initbtagwup[5]->Fill(nbjetAK4,weight_btagwup);
  hist_initbtagwup[6]->Fill(npfjetAK8,weight_btagwup);
  hist_initbtagwup[7]->Fill((mucandv[itf] + elcandv[iuf]).M(),weight_btagwup);
  hist_initbtagwup[8]->Fill(mucandv[itf].Pt(),weight_btagwup);
  hist_initbtagwup[9]->Fill(mucandv[itf].Eta(),weight_btagwup);
  hist_initbtagwup[10]->Fill(mucandv[itf].Phi(),weight_btagwup);
  hist_initbtagwup[11]->Fill(elcandv[iuf].Pt(),weight_btagwup);
  hist_initbtagwup[12]->Fill(elcandv[iuf].Eta(),weight_btagwup);
  hist_initbtagwup[13]->Fill(elcandv[iuf].Phi(),weight_btagwup);
  hist_initbtagwup[14]->Fill(bjv[0].Pt(),weight_btagwup);
  hist_initbtagwup[15]->Fill(bjv[0].Eta(),weight_btagwup);
  hist_initbtagwup[16]->Fill(bjv[0].Phi(),weight_btagwup);

  hist_initpuwdown[0]->Fill(nmuon1,weight_puwdown);
  hist_initpuwdown[1]->Fill(nelec1,weight_puwdown);
  hist_initpuwdown[2]->Fill(PFMET,weight_puwdown);
  hist_initpuwdown[3]->Fill(nprimi,weight_puwdown);
  hist_initpuwdown[4]->Fill(npfjetAK4,weight_puwdown);
  hist_initpuwdown[5]->Fill(nbjetAK4,weight_puwdown);
  hist_initpuwdown[6]->Fill(npfjetAK8,weight_puwdown);
  hist_initpuwdown[7]->Fill((mucandv[itf] + elcandv[iuf]).M(),weight_puwdown);
  hist_initpuwdown[8]->Fill(mucandv[itf].Pt(),weight_puwdown);
  hist_initpuwdown[9]->Fill(mucandv[itf].Eta(),weight_puwdown);
  hist_initpuwdown[10]->Fill(mucandv[itf].Phi(),weight_puwdown);
  hist_initpuwdown[11]->Fill(elcandv[iuf].Pt(),weight_puwdown);
  hist_initpuwdown[12]->Fill(elcandv[iuf].Eta(),weight_puwdown);
  hist_initpuwdown[13]->Fill(elcandv[iuf].Phi(),weight_puwdown);
  hist_initpuwdown[14]->Fill(bjv[0].Pt(),weight_puwdown);
  hist_initpuwdown[15]->Fill(bjv[0].Eta(),weight_puwdown);
  hist_initpuwdown[16]->Fill(bjv[0].Phi(),weight_puwdown);

  hist_initbtagwdown[0]->Fill(nmuon1,weight_btagwdown);
  hist_initbtagwdown[1]->Fill(nelec1,weight_btagwdown);
  hist_initbtagwdown[2]->Fill(PFMET,weight_btagwdown);
  hist_initbtagwdown[3]->Fill(nprimi,weight_btagwdown);
  hist_initbtagwdown[4]->Fill(npfjetAK4,weight_btagwdown);
  hist_initbtagwdown[5]->Fill(nbjetAK4,weight_btagwdown);
   hist_initbtagwdown[6]->Fill(npfjetAK8,weight_btagwdown);
  hist_initbtagwdown[7]->Fill((mucandv[itf] + elcandv[iuf]).M(),weight_btagwdown);
  hist_initbtagwdown[8]->Fill(mucandv[itf].Pt(),weight_btagwdown);
  hist_initbtagwdown[9]->Fill(mucandv[itf].Eta(),weight_btagwdown);
  hist_initbtagwdown[10]->Fill(mucandv[itf].Phi(),weight_btagwdown);
  hist_initbtagwdown[11]->Fill(elcandv[iuf].Pt(),weight_btagwdown);
  hist_initbtagwdown[12]->Fill(elcandv[iuf].Eta(),weight_btagwdown);
  hist_initbtagwdown[13]->Fill(elcandv[iuf].Phi(),weight_btagwdown);
  hist_initbtagwdown[14]->Fill(bjv[0].Pt(),weight_btagwdown);
  hist_initbtagwdown[15]->Fill(bjv[0].Eta(),weight_btagwdown);
  hist_initbtagwdown[16]->Fill(bjv[0].Phi(),weight_btagwdown);

  if (npfjetAK8>0) {
    int npfjetAK8wmass(0);
    int ljcand(-1);
    float mass(0.);
    float maxpt(-100);
    for(int ijet=0; ijet<npfjetAK8; ijet++){
      if (pfjetAK8mass[ijet] > mass) {
	npfjetAK8wmass++;
	if (pfjetAK8pt[ijet]>maxpt) {
	 maxpt = pfjetAK8pt[ijet];
	 ljcand = ijet;
	}
      }
    }
    if (npfjetAK8wmass>0) {
      if (ljcand>=0) {
	hist_dRdPhi[0]->Fill(delta2R(mucandv[itf].Eta(),mucandv[itf].Phi(),pfjetAK8y[ljcand],pfjetAK8phi[ljcand]),weight);
	hist_dRdPhi[1]->Fill(PhiInRange(mucandv[itf].Phi() - pfjetAK8phi[ljcand]),weight);
	hist_dRdPhi[2]->Fill(delta2R(elcandv[iuf].Eta(),elcandv[iuf].Phi(),pfjetAK8y[ljcand],pfjetAK8phi[ljcand]),weight);
	hist_dRdPhi[3]->Fill(PhiInRange(elcandv[iuf].Phi() - pfjetAK8phi[ljcand]),weight);
	hist_dRdPhi[12]->Fill(delta2R(mucandv[itf].Eta(),mucandv[itf].Phi(),elcandv[iuf].Eta(),elcandv[iuf].Phi()),weight);
	hist_dRdPhi[13]->Fill(PhiInRange(mucandv[itf].Phi() - elcandv[iuf].Phi()),weight); 
      }
      int npfjetAK8_el(0), npfjetAK8_mu(0);
      bool te_found(false);
      int telcand(-1);
      float maxptel = -100;
      
      for(int ijet=0; ijet<npfjetAK8wmass; ijet++){
	if(pfjetAK8pt[ijet]<400.) { continue; }
	if(//(delta2R(mucandv[itf].Eta(),mucandv[itf].Phi(),pfjetAK8y[ijet],pfjetAK8phi[ijet]) > 1.2)
	   //&& 
	   (fabs(PhiInRange(mucandv[itf].Phi() - pfjetAK8phi[ijet])) > M_PI/2.) && pfjetAK8pt[ijet]>maxptel){
	  te_found = true;
	  telcand = ijet;
	  maxptel = pfjetAK8pt[ijet];
	}
      }
      if (telcand>=0) hist_init[17]->Fill(npfjetAK8wmass,weight);
      if (telcand>=0) hist_count->Fill(15,weight);
      if (telcand>=0 && pfjetAK8_hasmatche[telcand] == true) hist_count->Fill(16,weight);
      
      //if (pfjetAK8_hasmatchmu[ijet] == true ) npfjetAK8_mu++;
      //if (pfjetAK8_hasmatche[ijet] == true) npfjetAK8_el++;
      //if (npfjetAK8_mu>=1)  hist_count->Fill(16,weight);
      //if (npfjetAK8_el>=1)  hist_count->Fill(17,weight);
      
      int tmucand1(-1);
      int nmucand1(0);
      float maxptmu = -100;

      if (telcand >=0) {
	for(int ijet=0; ijet<npfjetAK8wmass; ijet++){
	  if(pfjetAK8pt[ijet]<400.) { continue; }
	  if (ijet != telcand && pfjetAK8_hasmatche[ijet] == false) {
	    if (pfjetAK8pt[ijet] > maxptmu) {
	      maxptmu = pfjetAK8pt[ijet];
	      tmucand1 = ijet;
	      nmucand1++;
	    }
	  }
	}
      }
      if (tmucand1>=0) hist_count->Fill(17,weight);
      if (tmucand1>=0 && pfjetAK8_hasmatchmu[tmucand1] == true) hist_count->Fill(18,weight);
      if (tmucand1>=0) {
	hist_dRdPhi[4]->Fill(delta2R(mucandv[itf].Eta(),mucandv[itf].Phi(),pfjetAK8y[tmucand1],pfjetAK8phi[tmucand1]),weight);
	hist_dRdPhi[5]->Fill(PhiInRange(mucandv[itf].Phi() - pfjetAK8phi[tmucand1]),weight);
	hist_dRdPhi[6]->Fill(delta2R(elcandv[iuf].Eta(),elcandv[iuf].Phi(),pfjetAK8y[tmucand1],pfjetAK8phi[tmucand1]),weight);
	hist_dRdPhi[7]->Fill(PhiInRange(elcandv[iuf].Phi() - pfjetAK8phi[tmucand1]),weight);
	
	hist_obs_mu[0]->Fill(pfjetAK8pt[tmucand1],weight);
	hist_obs_mu[1]->Fill(pfjetAK8y[tmucand1],weight);
	hist_obs_mu[2]->Fill(pfjetAK8mass[tmucand1],weight);
	
	hist_obs_mu[3]->Fill(pfjetAK8NHadF[tmucand1],weight);
	hist_obs_mu[4]->Fill(pfjetAK8neunhadfrac[tmucand1],weight);
	hist_obs_mu[5]->Fill(pfjetAK8sdmass[tmucand1],weight);
	hist_obs_mu[6]->Fill(pfjetAK8chrad[tmucand1],weight);
	hist_obs_mu[7]->Fill(pfjetAK8subhaddiff[tmucand1],weight);
	hist_obs_mu[8]->Fill(pfjetAK8tau21[tmucand1],weight);
	hist_obs_mu[9]->Fill(pfjetAK8DeepTag_TvsQCD[tmucand1],weight);
	hist_obs_mu[10]->Fill(pfjetAK8_bbyW_E[tmucand1],weight);
	hist_obs_mu[11]->Fill(pfjetAK8_Kfactor[tmucand1],weight);
	hist_obs_mu[12]->Fill(pfjetAK8re_tvsb[tmucand1],weight);
	hist_obs_mu[13]->Fill(pfjetAK8rmu_tvsb[tmucand1],weight);
	
	hist_obs_mupuwup[0]->Fill(pfjetAK8pt[tmucand1],weight_puwup);
	hist_obs_mupuwup[1]->Fill(pfjetAK8y[tmucand1],weight_puwup);
	hist_obs_mupuwup[2]->Fill(pfjetAK8mass[tmucand1],weight_puwup);
	hist_obs_mupuwup[3]->Fill(pfjetAK8NHadF[tmucand1],weight_puwup);
	hist_obs_mupuwup[4]->Fill(pfjetAK8neunhadfrac[tmucand1],weight_puwup);
	hist_obs_mupuwup[5]->Fill(pfjetAK8sdmass[tmucand1],weight_puwup);
	hist_obs_mupuwup[6]->Fill(pfjetAK8chrad[tmucand1],weight_puwup);
	hist_obs_mupuwup[7]->Fill(pfjetAK8subhaddiff[tmucand1],weight_puwup);
	hist_obs_mupuwup[8]->Fill(pfjetAK8tau21[tmucand1],weight_puwup);
	hist_obs_mupuwup[9]->Fill(pfjetAK8DeepTag_TvsQCD[tmucand1],weight_puwup);
	hist_obs_mupuwup[10]->Fill(pfjetAK8_bbyW_E[tmucand1],weight_puwup);
	hist_obs_mupuwup[11]->Fill(pfjetAK8_Kfactor[tmucand1],weight_puwup);
	hist_obs_mupuwup[12]->Fill(pfjetAK8re_tvsb[tmucand1],weight_puwup);
	hist_obs_mupuwup[13]->Fill(pfjetAK8rmu_tvsb[tmucand1],weight_puwup);
	
	hist_obs_mubtagwup[0]->Fill(pfjetAK8pt[tmucand1],weight_btagwup);
	hist_obs_mubtagwup[1]->Fill(pfjetAK8y[tmucand1],weight_btagwup);
	hist_obs_mubtagwup[2]->Fill(pfjetAK8mass[tmucand1],weight_btagwup);
	hist_obs_mubtagwup[3]->Fill(pfjetAK8NHadF[tmucand1],weight_btagwup);
	hist_obs_mubtagwup[4]->Fill(pfjetAK8neunhadfrac[tmucand1],weight_btagwup);
	hist_obs_mubtagwup[5]->Fill(pfjetAK8sdmass[tmucand1],weight_btagwup);
	hist_obs_mubtagwup[6]->Fill(pfjetAK8chrad[tmucand1],weight_btagwup);
	hist_obs_mubtagwup[7]->Fill(pfjetAK8subhaddiff[tmucand1],weight_btagwup);
	hist_obs_mubtagwup[8]->Fill(pfjetAK8tau21[tmucand1],weight_btagwup);
	hist_obs_mubtagwup[9]->Fill(pfjetAK8DeepTag_TvsQCD[tmucand1],weight_btagwup);
	hist_obs_mubtagwup[10]->Fill(pfjetAK8_bbyW_E[tmucand1],weight_btagwup);
	hist_obs_mubtagwup[11]->Fill(pfjetAK8_Kfactor[tmucand1],weight_btagwup);
	hist_obs_mubtagwup[12]->Fill(pfjetAK8re_tvsb[tmucand1],weight_btagwup);
	hist_obs_mubtagwup[13]->Fill(pfjetAK8rmu_tvsb[tmucand1],weight_btagwup);
	
	hist_obs_mupuwdown[0]->Fill(pfjetAK8pt[tmucand1],weight_puwdown);
	hist_obs_mupuwdown[1]->Fill(pfjetAK8y[tmucand1],weight_puwdown);
	hist_obs_mupuwdown[2]->Fill(pfjetAK8mass[tmucand1],weight_puwdown);
	hist_obs_mupuwdown[3]->Fill(pfjetAK8NHadF[tmucand1],weight_puwdown);
	hist_obs_mupuwdown[4]->Fill(pfjetAK8neunhadfrac[tmucand1],weight_puwdown);
	hist_obs_mupuwdown[5]->Fill(pfjetAK8sdmass[tmucand1],weight_puwdown);
	hist_obs_mupuwdown[6]->Fill(pfjetAK8chrad[tmucand1],weight_puwdown);
	hist_obs_mupuwdown[7]->Fill(pfjetAK8subhaddiff[tmucand1],weight_puwdown);
	hist_obs_mupuwdown[8]->Fill(pfjetAK8tau21[tmucand1],weight_puwdown);
	hist_obs_mupuwdown[9]->Fill(pfjetAK8DeepTag_TvsQCD[tmucand1],weight_puwdown);
	hist_obs_mupuwdown[10]->Fill(pfjetAK8_bbyW_E[tmucand1],weight_puwdown);
	hist_obs_mupuwdown[11]->Fill(pfjetAK8_Kfactor[tmucand1],weight_puwdown);
	hist_obs_mupuwdown[12]->Fill(pfjetAK8re_tvsb[tmucand1],weight_puwdown);
	hist_obs_mupuwdown[13]->Fill(pfjetAK8rmu_tvsb[tmucand1],weight_puwdown);
	
	hist_obs_mubtagwdown[0]->Fill(pfjetAK8pt[tmucand1],weight_btagwdown);
	hist_obs_mubtagwdown[1]->Fill(pfjetAK8y[tmucand1],weight_btagwdown);
	hist_obs_mubtagwdown[2]->Fill(pfjetAK8mass[tmucand1],weight_btagwdown);
	hist_obs_mubtagwdown[3]->Fill(pfjetAK8NHadF[tmucand1],weight_btagwdown);
	hist_obs_mubtagwdown[4]->Fill(pfjetAK8neunhadfrac[tmucand1],weight_btagwdown);
	hist_obs_mubtagwdown[5]->Fill(pfjetAK8sdmass[tmucand1],weight_btagwdown);
	hist_obs_mubtagwdown[6]->Fill(pfjetAK8chrad[tmucand1],weight_btagwdown);
	hist_obs_mubtagwdown[7]->Fill(pfjetAK8subhaddiff[tmucand1],weight_btagwdown);
	hist_obs_mubtagwdown[8]->Fill(pfjetAK8tau21[tmucand1],weight_btagwdown);
	hist_obs_mubtagwdown[9]->Fill(pfjetAK8DeepTag_TvsQCD[tmucand1],weight_btagwdown);
	hist_obs_mubtagwdown[10]->Fill(pfjetAK8_bbyW_E[tmucand1],weight_btagwdown);
	hist_obs_mubtagwdown[11]->Fill(pfjetAK8_Kfactor[tmucand1],weight_btagwdown);
	hist_obs_mubtagwdown[12]->Fill(pfjetAK8re_tvsb[tmucand1],weight_btagwdown);
	hist_obs_mubtagwdown[13]->Fill(pfjetAK8rmu_tvsb[tmucand1],weight_btagwdown);
	hist_obs_muljesup[0]->Fill(pfjetAK8pt[tmucand1]*pfjetAK8jesup_total[tmucand1],weight);
	hist_obs_muljesdown[0]->Fill(pfjetAK8pt[tmucand1]*pfjetAK8jesdn_total[tmucand1],weight);
	hist_obs_muljesup[2]->Fill(pfjetAK8mass[tmucand1]*pfjetAK8jesup_total[tmucand1],weight);
	hist_obs_muljesdown[2]->Fill(pfjetAK8mass[tmucand1]*pfjetAK8jesdn_total[tmucand1],weight);
	hist_obs_muljerup[0]->Fill(pfjetAK8pt_resoup[tmucand1],weight);
	hist_obs_muljerdown[0]->Fill(pfjetAK8pt_resodown[tmucand1],weight);
	hist_obs_muljerup[2]->Fill(pfjetAK8mass_resoup[tmucand1],weight);
	hist_obs_muljerdown[2]->Fill(pfjetAK8mass_resodown[tmucand1],weight);
      }
      
      if (telcand>=0) {
	
	hist_dRdPhi[8]->Fill(delta2R(mucandv[itf].Eta(),mucandv[itf].Phi(),pfjetAK8y[telcand],pfjetAK8phi[telcand]),weight);
	hist_dRdPhi[9]->Fill(PhiInRange(mucandv[itf].Phi()- pfjetAK8phi[telcand]),weight);
	hist_dRdPhi[10]->Fill(delta2R(elcandv[iuf].Eta(),elcandv[iuf].Phi(),pfjetAK8y[telcand],pfjetAK8phi[telcand]),weight);
	hist_dRdPhi[11]->Fill(PhiInRange(elcandv[iuf].Phi()- pfjetAK8phi[telcand]),weight);
	
	hist_obs[0]->Fill(pfjetAK8pt[telcand],weight);       
	hist_obs[1]->Fill(pfjetAK8y[telcand],weight);                                                              
	hist_obs[2]->Fill(pfjetAK8mass[telcand],weight);                                                           
	hist_obs[3]->Fill(pfjetAK8NHadF[telcand],weight);                                                         
	hist_obs[4]->Fill(pfjetAK8neunhadfrac[telcand],weight);                                                   
	hist_obs[5]->Fill(pfjetAK8sdmass[telcand],weight);                                                        
	hist_obs[6]->Fill(pfjetAK8chrad[telcand],weight);                                                         
	hist_obs[7]->Fill(pfjetAK8subhaddiff[telcand],weight);                                                    
	hist_obs[8]->Fill(pfjetAK8tau21[telcand],weight);                                                         
	hist_obs[9]->Fill(pfjetAK8DeepTag_TvsQCD[telcand],weight);                                                 
	hist_obs[10]->Fill(pfjetAK8_bbyW_E[telcand],weight);                                                      
	hist_obs[11]->Fill(pfjetAK8_Kfactor[telcand],weight);                                                     
	hist_obs[12]->Fill(pfjetAK8re_tvsb[telcand],weight);                                                      
	hist_obs[13]->Fill(pfjetAK8rnu_tvsb[telcand],weight);                                                     
	
	hist_obspuwup[0]->Fill(pfjetAK8pt[telcand],weight_puwup);
	hist_obspuwup[1]->Fill(pfjetAK8y[telcand],weight_puwup);
	hist_obspuwup[2]->Fill(pfjetAK8mass[telcand],weight_puwup);
	hist_obspuwup[3]->Fill(pfjetAK8NHadF[telcand],weight_puwup);
	hist_obspuwup[4]->Fill(pfjetAK8neunhadfrac[telcand],weight_puwup);
	hist_obspuwup[5]->Fill(pfjetAK8sdmass[telcand],weight_puwup);
	hist_obspuwup[6]->Fill(pfjetAK8chrad[telcand],weight_puwup);
	hist_obspuwup[7]->Fill(pfjetAK8subhaddiff[telcand],weight_puwup);
	hist_obspuwup[8]->Fill(pfjetAK8tau21[telcand],weight_puwup);
	hist_obspuwup[9]->Fill(pfjetAK8DeepTag_TvsQCD[telcand],weight_puwup);
	hist_obspuwup[10]->Fill(pfjetAK8_bbyW_E[telcand],weight_puwup);
	hist_obspuwup[11]->Fill(pfjetAK8_Kfactor[telcand],weight_puwup);
	hist_obspuwup[12]->Fill(pfjetAK8re_tvsb[telcand],weight_puwup);
	hist_obspuwup[13]->Fill(pfjetAK8rmu_tvsb[telcand],weight_puwup);
	
	hist_obsbtagwup[0]->Fill(pfjetAK8pt[telcand],weight_btagwup);
	hist_obsbtagwup[1]->Fill(pfjetAK8y[telcand],weight_btagwup);
	hist_obsbtagwup[2]->Fill(pfjetAK8mass[telcand],weight_btagwup);
	hist_obsbtagwup[3]->Fill(pfjetAK8NHadF[telcand],weight_btagwup);
	hist_obsbtagwup[4]->Fill(pfjetAK8neunhadfrac[telcand],weight_btagwup);
	hist_obsbtagwup[5]->Fill(pfjetAK8sdmass[telcand],weight_btagwup);
	hist_obsbtagwup[6]->Fill(pfjetAK8chrad[telcand],weight_btagwup);
	hist_obsbtagwup[7]->Fill(pfjetAK8subhaddiff[telcand],weight_btagwup);
	hist_obsbtagwup[8]->Fill(pfjetAK8tau21[telcand],weight_btagwup);
	hist_obsbtagwup[9]->Fill(pfjetAK8DeepTag_TvsQCD[telcand],weight_btagwup);
	hist_obsbtagwup[10]->Fill(pfjetAK8_bbyW_E[telcand],weight_btagwup);
	hist_obsbtagwup[11]->Fill(pfjetAK8_Kfactor[telcand],weight_btagwup);
	hist_obsbtagwup[12]->Fill(pfjetAK8re_tvsb[telcand],weight_btagwup);
	hist_obsbtagwup[13]->Fill(pfjetAK8rmu_tvsb[telcand],weight_btagwup);
	
	hist_obspuwdown[0]->Fill(pfjetAK8pt[telcand],weight_puwdown);
	hist_obspuwdown[1]->Fill(pfjetAK8y[telcand],weight_puwdown);
	hist_obspuwdown[2]->Fill(pfjetAK8mass[telcand],weight_puwdown);
	hist_obspuwdown[3]->Fill(pfjetAK8NHadF[telcand],weight_puwdown);
	hist_obspuwdown[4]->Fill(pfjetAK8neunhadfrac[telcand],weight_puwdown);
	hist_obspuwdown[5]->Fill(pfjetAK8sdmass[telcand],weight_puwdown);
	hist_obspuwdown[6]->Fill(pfjetAK8chrad[telcand],weight_puwdown);
	hist_obspuwdown[7]->Fill(pfjetAK8subhaddiff[telcand],weight_puwdown);
	hist_obspuwdown[8]->Fill(pfjetAK8tau21[telcand],weight_puwdown);
	hist_obspuwdown[9]->Fill(pfjetAK8DeepTag_TvsQCD[telcand],weight_puwdown);
	hist_obspuwdown[10]->Fill(pfjetAK8_bbyW_E[telcand],weight_puwdown);
	hist_obspuwdown[11]->Fill(pfjetAK8_Kfactor[telcand],weight_puwdown);
	hist_obspuwdown[12]->Fill(pfjetAK8re_tvsb[telcand],weight_puwdown);
	hist_obspuwdown[13]->Fill(pfjetAK8rmu_tvsb[telcand],weight_puwdown);
	
	hist_obsbtagwdown[0]->Fill(pfjetAK8pt[telcand],weight_btagwdown);
	hist_obsbtagwdown[1]->Fill(pfjetAK8y[telcand],weight_btagwdown);
	hist_obsbtagwdown[2]->Fill(pfjetAK8mass[telcand],weight_btagwdown);
	hist_obsbtagwdown[3]->Fill(pfjetAK8NHadF[telcand],weight_btagwdown);
	hist_obsbtagwdown[4]->Fill(pfjetAK8neunhadfrac[telcand],weight_btagwdown);
	hist_obsbtagwdown[5]->Fill(pfjetAK8sdmass[telcand],weight_btagwdown);
	hist_obsbtagwdown[6]->Fill(pfjetAK8chrad[telcand],weight_btagwdown);
	hist_obsbtagwdown[7]->Fill(pfjetAK8subhaddiff[telcand],weight_btagwdown);
	hist_obsbtagwdown[8]->Fill(pfjetAK8tau21[telcand],weight_btagwdown);
	hist_obsbtagwdown[9]->Fill(pfjetAK8DeepTag_TvsQCD[telcand],weight_btagwdown);
	hist_obsbtagwdown[10]->Fill(pfjetAK8_bbyW_E[telcand],weight_btagwdown);
	hist_obsbtagwdown[11]->Fill(pfjetAK8_Kfactor[telcand],weight_btagwdown);
	hist_obsbtagwdown[12]->Fill(pfjetAK8re_tvsb[telcand],weight_btagwdown);
	hist_obsbtagwdown[13]->Fill(pfjetAK8rmu_tvsb[telcand],weight_btagwdown);
	
	hist_obsljesup[0]->Fill(pfjetAK8pt[telcand]*pfjetAK8jesup_total[telcand],weight);
	hist_obsljesdown[0]->Fill(pfjetAK8pt[telcand]*pfjetAK8jesdn_total[telcand],weight);
	hist_obsljesup[2]->Fill(pfjetAK8mass[telcand]*pfjetAK8jesup_total[telcand],weight);
	hist_obsljesdown[2]->Fill(pfjetAK8mass[telcand]*pfjetAK8jesdn_total[telcand],weight);
	
	hist_obsljerup[0]->Fill(pfjetAK8pt_resoup[telcand],weight);
	hist_obsljerdown[0]->Fill(pfjetAK8pt_resodown[telcand],weight);
	hist_obsljerup[2]->Fill(pfjetAK8mass_resoup[telcand],weight);
	hist_obsljerdown[2]->Fill(pfjetAK8mass_resodown[telcand],weight);

      }
      // if (npfjetAK8_mu>=1 && npfjetAK8_el>=1) hist_count->Fill(18,weight);
    }
  }
#endif
  

  // end //                                                                            
                                  
  return kTRUE;                                                                       
}
 void Anal_Leptop_PROOF::SlaveTerminate()
{
  // The SlaveTerminate() function is called after all entries or objects
  // have been processed. When running with PROOF SlaveTerminate() is called
  // on each slave server.
  fileOut->cd();
  fileOut->Write();
  fOutput->Add(OutFile);
  fileOut->Close();
}

void Anal_Leptop_PROOF::Terminate()
{
  // The Terminate() function is the last function to be called during
  // a query. It always runs on the client, it can be used to present
  // the results graphically or save the results to file.
  
}
