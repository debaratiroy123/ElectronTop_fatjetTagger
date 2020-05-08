#define Anal_Leptop_PROOF_cxx
// The class definition in Anal_Leptop_PROOF.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("Anal_Leptop_PROOF.C")
// Root > T->Process("Anal_Leptop_PROOF.C","some options")
// Root > T->Process("Anal_Leptop_PROOF.C+")
//

#include "Anal_Leptop_PROOF.h"
#include <TH2.h>
#include <TStyle.h>

#define TRAINING

void Anal_Leptop_PROOF::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.
  // The tree argument is deprecated (on PROOF 0 is passed).
  
  TString option = GetOption();
}

void Anal_Leptop_PROOF::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).
  
  TString option = GetOption();
  
  //OutFile = new TProofOutputFile("TestQCD_BEnriched_HT2000toInfnewvarBDTsvtrv3.root");
  //OutFile = new TProofOutputFile("Test500to700wt.root");
  // OutFile = new TProofOutputFile("TestMtt_1000toInf_newvarBDTsvtrv3.root");
  // OutFile = new TProofOutputFile("TestMtt_1000toInfnewvarBDT.root");
  //OutFile = new TProofOutputFile("TestTTBar_DiLeptonicnewvarBDT.root");
  //OutFile = new TProofOutputFile("Output_Zp1500W15newvardR.root");
  //OutFile = new TProofOutputFile("Test_Zp1500W15newvarBDT.root");
  //OutFile = new TProofOutputFile("Test_Zp3000W30newvarBDTsvtrv3.root");

  //OutFile = new TProofOutputFile("TestZp1500_15wtchk4.root"); 
  //OutFile = new TProofOutputFile("TestbQCDHT2000toInf_chk4.root");
  //OutFile = new TProofOutputFile("TestMtt_700to1000_chk4.root");


  //OutFile = new TProofOutputFile("testbQCD_HT2000toInfresv_qg.root");
  //OutFile = new TProofOutputFile("test3000zpW300_resvalljets2Disogenmtche.root");
  //OutFile = new TProofOutputFile("testDileptonic_resvalljets.root");
  OutFile = new TProofOutputFile("testDileptonic_resvalljets2Disogenmtche2v.root");

  //OutFile = new TProofOutputFile("test1500zp_resvalljets2Disogenmtche2v.root");

  //fOutput->Add(OutFile);
  
  fileOut = OutFile->OpenFile("RECREATE");
  if ( !(fileOut = OutFile->OpenFile("RECREATE")) )
    {
      Warning("SlaveBegin", "problems opening file: %s/%s",
	      OutFile->GetDir(), OutFile->GetFileName());
    }
  
  isMC = true;
  
  Tout = new TTree("leptop","leptop");
  Tout->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout->Branch("weight",&weight,"weight/F");
  
  #ifdef TRAINING
  
  Tout1 = new TTree("leptop_e","leptop_e");
  Tout1->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout1->Branch("weight",&weight,"weight/F");
  Tout1->Branch("DiLeptt",&DiLeptt,"DiLeptt/O");
  Tout1->Branch("SemiLeptt",&SemiLeptt,"SemiLeptt/O");
  Tout1->Branch("Hadtt",&Hadtt,"Hadtt/O");
  Tout1->Branch("npfjetAK8_te",&npfjetAK8_te, "npfjetAK8_te/I");  
  Tout1->Branch("selpfjetAK8pt",selpfjetAK8pt,"selpfjetAK8pt[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8y",selpfjetAK8y,"selpfjetAK8y[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8phi",selpfjetAK8phi,"selpfjetAK8phi[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8mass",selpfjetAK8mass,"selpfjetAK8mass[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8btag_CMVA",selpfjetAK8btag_CMVA,"selpfjetAK8btag_CMVA[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8btag_CSV",selpfjetAK8btag_CSV,"selpfjetAK8btag_CSV[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8btag_DeepCSV",selpfjetAK8btag_DeepCSV,"selpfjetAK8btag_DeepCSV[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchAK4deepb",selpfjetAK8matchAK4deepb,"selpfjetAK8matchAK4deepb[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8DeepTag_TvsQCD",selpfjetAK8DeepTag_TvsQCD,"selpfjetAK8DeepTag_TvsQCD[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8DeepTag_WvsQCD",selpfjetAK8DeepTag_WvsQCD,"selpfjetAK8DeepTag_WvsQCD[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8DeepTag_ZvsQCD",selpfjetAK8DeepTag_ZvsQCD,"selpfjetAK8DeepTag_ZvsQCD[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8CHF",selpfjetAK8CHF,"selpfjetAK8CHF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8NHF",selpfjetAK8NHF,"selpfjetAK8NHF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8CEMF",selpfjetAK8CEMF,"selpfjetAK8CEMF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8NEMF",selpfjetAK8NEMF,"selpfjetAK8NEMF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8MUF",selpfjetAK8MUF,"selpfjetAK8MUF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8HOF",selpfjetAK8HOF,"selpfjetAK8HOF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8HadF",selpfjetAK8HadF,"selpfjetAK8HadF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8NHadF",selpfjetAK8NHadF,"selpfjetAK8NHadF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8EmF",selpfjetAK8EmF,"selpfjetAK8EmF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8neuemfrac",selpfjetAK8neuemfrac,"selpfjetAK8neuemfrac[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8neunhadfrac",selpfjetAK8neunhadfrac,"selpfjetAK8neunhadfrac[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8CHM",selpfjetAK8CHM,"selpfjetAK8CHM[npfjetAK8_te]/I");
  Tout1->Branch("selpfjetAK8NHM",selpfjetAK8NHM,"selpfjetAK8NHM[npfjetAK8_te]/I");
  Tout1->Branch("selpfjetAK8CEMM",selpfjetAK8CEMM,"selpfjetAK8CEMM[npfjetAK8_te]/I");
  Tout1->Branch("selpfjetAK8NEMM",selpfjetAK8NEMM,"selpfjetAK8NEMM[npfjetAK8_te]/I");
  Tout1->Branch("selpfjetAK8MUM",selpfjetAK8MUM,"selpfjetAK8MUM[npfjetAK8_te]/I");
  Tout1->Branch("selpfjetAK8Neucons",selpfjetAK8Neucons,"selpfjetAK8Neucons[npfjetAK8_te]/I");
  Tout1->Branch("selpfjetAK8Chcons",selpfjetAK8Chcons,"selpfjetAK8Chcons[npfjetAK8_te]/I");
  Tout1->Branch("selpfjetAK8chrad",selpfjetAK8chrad,"selpfjetAK8chrad[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8pTD",selpfjetAK8pTD,"selpfjetAK8pTD[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sdmass",selpfjetAK8sdmass,"selpfjetAK8sdmass[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8elsubjptrat",selpfjetAK8elsubjptrat,"selpfjetAK8elsubjptrat[npfjetAK8_te]/F");

  Tout1->Branch("selpfjetAK8elinsubpt",selpfjetAK8elinsubpt,"selpfjetAK8elinsubpt[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8elinsubeta",selpfjetAK8elinsubeta,"selpfjetAK8elinsubeta[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8elinsubphi",selpfjetAK8elinsubphi,"selpfjetAK8elinsubphi[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8elinsubjpt",selpfjetAK8elinsubjpt,"selpfjetAK8elinsubjpt[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8elinsubjeta",selpfjetAK8elinsubjeta,"selpfjetAK8elinsujbeta[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8elinsubjphi",selpfjetAK8elinsubjphi,"selpfjetAK8elinsubjphi[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelID",selpfjetAK8matchedelID,"selpfjetAK8matchedelID[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelpt",selpfjetAK8matchedelpt,"selpfjetAK8matchedelpt[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedeleta",selpfjetAK8matchedeleta,"selpfjetAK8matchedeleta[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelphi",selpfjetAK8matchedelphi,"selpfjetAK8matchedelphi[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelE",selpfjetAK8matchedelE,"selpfjetAK8matchedelE[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedeldxy",selpfjetAK8matchedeldxy,"selpfjetAK8matchedeldxy[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedeldxy_sv",selpfjetAK8matchedeldxy_sv,"selpfjetAK8matchedeldxy_sv[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelcleta",selpfjetAK8matchedelcleta,"selpfjetAK8matchedelcleta[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelclphi",selpfjetAK8matchedelclphi,"selpfjetAK8matchedelclphi[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelclrawE",selpfjetAK8matchedelclrawE,"selpfjetAK8matchedelclrawE[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8re_tvsb",selpfjetAK8re_tvsb,"selpfjetAK8re_tvsb[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8rnu_tvsb",selpfjetAK8rnu_tvsb,"selpfjetAK8rnu_tvsb[npfjetAK8_te]/F");

  Tout1->Branch("selpfjetAK8tau21",selpfjetAK8tau21,"selpfjetAK8tau21[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8tau32",selpfjetAK8tau32,"selpfjetAK8tau32[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sub1mass",selpfjetAK8sub1mass,"selpfjetAK8sub1mass[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sub1btag",selpfjetAK8sub1btag,"selpfjetAK8sub1btag[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sub1hadfrac",selpfjetAK8sub1hadfrac,"selpfjetAK8sub1hadfrac[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sub1emfrac",selpfjetAK8sub1emfrac,"selpfjetAK8sub1emfrac[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sub2mass",selpfjetAK8sub2mass,"selpfjetAK8sub2mass[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sub2btag",selpfjetAK8sub2btag,"selpfjetAK8sub2btag[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sub2hadfrac",selpfjetAK8sub2hadfrac,"selpfjetAK8sub2hadfrac[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sub2emfrac",selpfjetAK8sub2emfrac,"selpfjetAK8sub2emfrac[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8subbtag", pfjetAK8subbtag,"selpfjetAK8subbtag[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8subhaddiff",selpfjetAK8subhaddiff,"selpfjetAK8subhaddiff[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8subemdiff",selpfjetAK8subemdiff,"selpfjetAK8subemdiff[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8subptdiff",selpfjetAK8subptdiff,"selpfjetAK8subptdiff[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8_bbyW_E", selpfjetAK8_bbyW_E,"selpfjetAK8_bbyW_E[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8_Kfactor", selpfjetAK8_Kfactor,"selpfjetAK8_Kfactor[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8_Rnew", selpfjetAK8_Rnew,"selpfjetAK8_Rnew[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8haselectron",selpfjetAK8haselectron,"selpfjetAK8haselectron[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hasmuon",selpfjetAK8hasmuon,"selpfjetAK8hasmuon[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hashadtop_alldecay",selpfjetAK8hashadtop_alldecay,"selpfjetAK8hashadtop_alldecay[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hasleptop_alldecay",selpfjetAK8hasleptop_alldecay,"selpfjetAK8hasleptop_alldecay[npfjetAK8_te]/O");
  Tout2 = new TTree("leptop_mu","leptop_mu");
  Tout2->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout2->Branch("weight",&weight,"weight/F");
  Tout2->Branch("DiLeptt",&DiLeptt,"DiLeptt/O");
  Tout2->Branch("SemiLeptt",&SemiLeptt,"SemiLeptt/O");
  Tout2->Branch("Hadtt",&Hadtt,"Hadtt/O");
  Tout2->Branch("npfjetAK8_tmu",&npfjetAK8_tmu, "npfjetAK8_tmu/I");  
  Tout2->Branch("selpfjetAK8pt",selpfjetAK8pt,"selpfjetAK8pt[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8y",selpfjetAK8y,"selpfjetAK8y[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8phi",selpfjetAK8phi,"selpfjetAK8phi[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8mass",selpfjetAK8mass,"selpfjetAK8mass[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8btag_CMVA",selpfjetAK8btag_CMVA,"selpfjetAK8btag_CMVA[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8btag_CSV",selpfjetAK8btag_CSV,"selpfjetAK8btag_CSV[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8btag_DeepCSV",selpfjetAK8btag_DeepCSV,"selpfjetAK8btag_DeepCSV[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchAK4deepb",selpfjetAK8matchAK4deepb,"selpfjetAK8matchAK4deepb[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8DeepTag_TvsQCD",selpfjetAK8DeepTag_TvsQCD,"selpfjetAK8DeepTag_TvsQCD[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8DeepTag_WvsQCD",selpfjetAK8DeepTag_WvsQCD,"selpfjetAK8DeepTag_WvsQCD[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8DeepTag_ZvsQCD",selpfjetAK8DeepTag_ZvsQCD,"selpfjetAK8DeepTag_ZvsQCD[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8CHF",selpfjetAK8CHF,"selpfjetAK8CHF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8NHF",selpfjetAK8NHF,"selpfjetAK8NHF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8CEMF",selpfjetAK8CEMF,"selpfjetAK8CEMF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8NEMF",selpfjetAK8NEMF,"selpfjetAK8NEMF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8MUF",selpfjetAK8MUF,"selpfjetAK8MUF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8HOF",selpfjetAK8HOF,"selpfjetAK8HOF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8HadF",selpfjetAK8HadF,"selpfjetAK8HadF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8NHadF",selpfjetAK8NHadF,"selpfjetAK8NHadF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8EmF",selpfjetAK8EmF,"selpfjetAK8EmF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8neuemfrac",selpfjetAK8neuemfrac,"selpfjetAK8neuemfrac[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8neunhadfrac",selpfjetAK8neunhadfrac,"selpfjetAK8neunhadfrac[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8CHM",selpfjetAK8CHM,"selpfjetAK8CHM[npfjetAK8_tmu]/I");
  Tout2->Branch("selpfjetAK8NHM",selpfjetAK8NHM,"selpfjetAK8NHM[npfjetAK8_tmu]/I");
  Tout2->Branch("selpfjetAK8CEMM",selpfjetAK8CEMM,"selpfjetAK8CEMM[npfjetAK8_tmu]/I");
  Tout2->Branch("selpfjetAK8NEMM",selpfjetAK8NEMM,"selpfjetAK8NEMM[npfjetAK8_tmu]/I");
  Tout2->Branch("selpfjetAK8MUM",selpfjetAK8MUM,"selpfjetAK8MUM[npfjetAK8_tmu]/I");
  Tout2->Branch("selpfjetAK8Neucons",selpfjetAK8Neucons,"selpfjetAK8Neucons[npfjetAK8_tmu]/I");
  Tout2->Branch("selpfjetAK8Chcons",selpfjetAK8Chcons,"selpfjetAK8Chcons[npfjetAK8_tmu]/I");
  Tout2->Branch("selpfjetAK8chrad",selpfjetAK8chrad,"selpfjetAK8chrad[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8pTD",selpfjetAK8pTD,"selpfjetAK8pTD[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sdmass",selpfjetAK8sdmass,"selpfjetAK8sdmass[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8elsubjptrat",selpfjetAK8elsubjptrat,"selpfjetAK8elsubjptrat[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8elinsubpt",selpfjetAK8elinsubpt,"selpfjetAK8elinsubpt[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8elinsubeta",selpfjetAK8elinsubeta,"selpfjetAK8elinsubeta[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8elinsubphi",selpfjetAK8elinsubphi,"selpfjetAK8elinsubphi[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8elinsubjpt",selpfjetAK8elinsubjpt,"selpfjetAK8elinsubjpt[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8elinsubjeta",selpfjetAK8elinsubjeta,"selpfjetAK8elinsujbeta[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8elinsubjphi",selpfjetAK8elinsubjphi,"selpfjetAK8elinsubjphi[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedelID",selpfjetAK8matchedelID,"selpfjetAK8matchedelID[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedelpt",selpfjetAK8matchedelpt,"selpfjetAK8matchedelpt[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedeleta",selpfjetAK8matchedeleta,"selpfjetAK8matchedeleta[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedelphi",selpfjetAK8matchedelphi,"selpfjetAK8matchedelphi[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedelE",selpfjetAK8matchedelE,"selpfjetAK8matchedelE[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedeldxy",selpfjetAK8matchedeldxy,"selpfjetAK8matchedeldxy[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedeldxy_sv",selpfjetAK8matchedeldxy_sv,"selpfjetAK8matchedeldxy_sv[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedelcleta",selpfjetAK8matchedelcleta,"selpfjetAK8matchedelcleta[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedelclphi",selpfjetAK8matchedelclphi,"selpfjetAK8matchedelclphi[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedelclrawE",selpfjetAK8matchedelclrawE,"selpfjetAK8matchedelclrawE[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8re_tvsb",selpfjetAK8re_tvsb,"selpfjetAK8re_tvsb[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8rnu_tvsb",selpfjetAK8rnu_tvsb,"selpfjetAK8rnu_tvsb[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8tau21",selpfjetAK8tau21,"selpfjetAK8tau21[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8tau32",selpfjetAK8tau32,"selpfjetAK8tau32[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sub1mass",selpfjetAK8sub1mass,"selpfjetAK8sub1mass[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sub1btag",selpfjetAK8sub1btag,"selpfjetAK8sub1btag[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sub1hadfrac",selpfjetAK8sub1hadfrac,"selpfjetAK8sub1hadfrac[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sub1emfrac",selpfjetAK8sub1emfrac,"selpfjetAK8sub1emfrac[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sub2mass",selpfjetAK8sub2mass,"selpfjetAK8sub2mass[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sub2btag",selpfjetAK8sub2btag,"selpfjetAK8sub2btag[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sub2hadfrac",selpfjetAK8sub2hadfrac,"selpfjetAK8sub2hadfrac[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sub2emfrac",selpfjetAK8sub2emfrac,"selpfjetAK8sub2emfrac[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8subbtag", pfjetAK8subbtag,"selpfjetAK8subbtag[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8subhaddiff",selpfjetAK8subhaddiff,"selpfjetAK8subhaddiff[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8subemdiff",selpfjetAK8subemdiff,"selpfjetAK8subemdiff[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8subptdiff",selpfjetAK8subptdiff,"selpfjetAK8subptdiff[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8_bbyW_E", selpfjetAK8_bbyW_E,"selpfjetAK8_bbyW_E[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8_Kfactor", selpfjetAK8_Kfactor,"selpfjetAK8_Kfactor[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8_Rnew", selpfjetAK8_Rnew,"selpfjetAK8_Rnew[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8haselectron",selpfjetAK8haselectron,"selpfjetAK8haselectron[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasmuon",selpfjetAK8hasmuon,"selpfjetAK8hasmuon[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hashadtop_alldecay",selpfjetAK8hashadtop_alldecay,"selpfjetAK8hashadtop_alldecay[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasleptop_alldecay",selpfjetAK8hasleptop_alldecay,"selpfjetAK8hasleptop_alldecay[npfjetAK8_tmu]/O");
  
  Tout3 = new TTree("hadtop","hadtop");
  Tout3->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout3->Branch("weight",&weight,"weight/F");
  Tout3->Branch("DiLeptt",&DiLeptt,"DiLeptt/O");
  Tout3->Branch("SemiLeptt",&SemiLeptt,"SemiLeptt/O");
  Tout3->Branch("Hadtt",&Hadtt,"Hadtt/O");
  Tout3->Branch("npfjetAK8_thad",&npfjetAK8_thad, "npfjetAK8_thad/I");  
  Tout3->Branch("selpfjetAK8pt",selpfjetAK8pt,"selpfjetAK8pt[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8y",selpfjetAK8y,"selpfjetAK8y[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8phi",selpfjetAK8phi,"selpfjetAK8phi[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8mass",selpfjetAK8mass,"selpfjetAK8mass[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8btag_CMVA",selpfjetAK8btag_CMVA,"selpfjetAK8btag_CMVA[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8btag_CSV",selpfjetAK8btag_CSV,"selpfjetAK8btag_CSV[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8btag_DeepCSV",selpfjetAK8btag_DeepCSV,"selpfjetAK8btag_DeepCSV[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8matchAK4deepb",selpfjetAK8matchAK4deepb,"selpfjetAK8matchAK4deepb[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8DeepTag_TvsQCD",selpfjetAK8DeepTag_TvsQCD,"selpfjetAK8DeepTag_TvsQCD[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8DeepTag_WvsQCD",selpfjetAK8DeepTag_WvsQCD,"selpfjetAK8DeepTag_WvsQCD[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8DeepTag_ZvsQCD",selpfjetAK8DeepTag_ZvsQCD,"selpfjetAK8DeepTag_ZvsQCD[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8CHF",selpfjetAK8CHF,"selpfjetAK8CHF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8NHF",selpfjetAK8NHF,"selpfjetAK8NHF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8CEMF",selpfjetAK8CEMF,"selpfjetAK8CEMF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8NEMF",selpfjetAK8NEMF,"selpfjetAK8NEMF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8MUF",selpfjetAK8MUF,"selpfjetAK8MUF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8HOF",selpfjetAK8HOF,"selpfjetAK8HOF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8HadF",selpfjetAK8HadF,"selpfjetAK8HadF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8NHadF",selpfjetAK8NHadF,"selpfjetAK8NHadF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8EmF",selpfjetAK8EmF,"selpfjetAK8EmF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8neuemfrac",selpfjetAK8neuemfrac,"selpfjetAK8neuemfrac[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8neunhadfrac",selpfjetAK8neunhadfrac,"selpfjetAK8neunhadfrac[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8CHM",selpfjetAK8CHM,"selpfjetAK8CHM[npfjetAK8_thad]/I");
  Tout3->Branch("selpfjetAK8NHM",selpfjetAK8NHM,"selpfjetAK8NHM[npfjetAK8_thad]/I");
  Tout3->Branch("selpfjetAK8CEMM",selpfjetAK8CEMM,"selpfjetAK8CEMM[npfjetAK8_thad]/I");
  Tout3->Branch("selpfjetAK8NEMM",selpfjetAK8NEMM,"selpfjetAK8NEMM[npfjetAK8_thad]/I");
  Tout3->Branch("selpfjetAK8MUM",selpfjetAK8MUM,"selpfjetAK8MUM[npfjetAK8_thad]/I");
  Tout3->Branch("selpfjetAK8Neucons",selpfjetAK8Neucons,"selpfjetAK8Neucons[npfjetAK8_thad]/I");
  Tout3->Branch("selpfjetAK8Chcons",selpfjetAK8Chcons,"selpfjetAK8Chcons[npfjetAK8_thad]/I");
  Tout3->Branch("selpfjetAK8chrad",selpfjetAK8chrad,"selpfjetAK8chrad[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8pTD",selpfjetAK8pTD,"selpfjetAK8pTD[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sdmass",selpfjetAK8sdmass,"selpfjetAK8sdmass[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8elsubjptrat",selpfjetAK8elsubjptrat,"selpfjetAK8elsubjptrat[npfjetAK8_thad]/F");

  Tout3->Branch("selpfjetAK8elinsubpt",selpfjetAK8elinsubpt,"selpfjetAK8elinsubpt[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8elinsubeta",selpfjetAK8elinsubeta,"selpfjetAK8elinsubeta[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8elinsubphi",selpfjetAK8elinsubphi,"selpfjetAK8elinsubphi[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8elinsubjpt",selpfjetAK8elinsubjpt,"selpfjetAK8elinsubjpt[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8elinsubjeta",selpfjetAK8elinsubjeta,"selpfjetAK8elinsujbeta[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8elinsubjphi",selpfjetAK8elinsubjphi,"selpfjetAK8elinsubjphi[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8matchedelID",selpfjetAK8matchedelID,"selpfjetAK8matchedelID[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8matchedelpt",selpfjetAK8matchedelpt,"selpfjetAK8matchedelpt[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8matchedeleta",selpfjetAK8matchedeleta,"selpfjetAK8matchedeleta[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8matchedelphi",selpfjetAK8matchedelphi,"selpfjetAK8matchedelphi[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8matchedelE",selpfjetAK8matchedelE,"selpfjetAK8matchedelE[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8matchedeldxy",selpfjetAK8matchedeldxy,"selpfjetAK8matchedeldxy[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8matchedeldxy_sv",selpfjetAK8matchedeldxy_sv,"selpfjetAK8matchedeldxy_sv[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8matchedelcleta",selpfjetAK8matchedelcleta,"selpfjetAK8matchedelcleta[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8matchedelclphi",selpfjetAK8matchedelclphi,"selpfjetAK8matchedelclphi[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8matchedelclrawE",selpfjetAK8matchedelclrawE,"selpfjetAK8matchedelclrawE[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8re_tvsb",selpfjetAK8re_tvsb,"selpfjetAK8re_tvsb[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8rnu_tvsb",selpfjetAK8rnu_tvsb,"selpfjetAK8rnu_tvsb[npfjetAK8_thad]/F");


  Tout3->Branch("selpfjetAK8tau21",selpfjetAK8tau21,"selpfjetAK8tau21[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8tau32",selpfjetAK8tau32,"selpfjetAK8tau32[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sub1mass",selpfjetAK8sub1mass,"selpfjetAK8sub1mass[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sub1btag",selpfjetAK8sub1btag,"selpfjetAK8sub1btag[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sub1hadfrac",selpfjetAK8sub1hadfrac,"selpfjetAK8sub1hadfrac[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sub1emfrac",selpfjetAK8sub1emfrac,"selpfjetAK8sub1emfrac[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sub2mass",selpfjetAK8sub2mass,"selpfjetAK8sub2mass[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sub2btag",selpfjetAK8sub2btag,"selpfjetAK8sub2btag[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sub2hadfrac",selpfjetAK8sub2hadfrac,"selpfjetAK8sub2hadfrac[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sub2emfrac",selpfjetAK8sub2emfrac,"selpfjetAK8sub2emfrac[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8subbtag", pfjetAK8subbtag,"selpfjetAK8subbtag[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8subhaddiff",selpfjetAK8subhaddiff,"selpfjetAK8subhaddiff[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8subemdiff",selpfjetAK8subemdiff,"selpfjetAK8subemdiff[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8subptdiff",selpfjetAK8subptdiff,"selpfjetAK8subptdiff[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8_bbyW_E", selpfjetAK8_bbyW_E,"selpfjetAK8_bbyW_E[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8_Kfactor", selpfjetAK8_Kfactor,"selpfjetAK8_Kfactor[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8_Rnew", selpfjetAK8_Rnew,"selpfjetAK8_Rnew[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8haselectron",selpfjetAK8haselectron,"selpfjetAK8haselectron[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hasmuon",selpfjetAK8hasmuon,"selpfjetAK8hasmuon[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hashadtop_alldecay",selpfjetAK8hashadtop_alldecay,"selpfjetAK8hashadtop_alldecay[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hasleptop_alldecay",selpfjetAK8hasleptop_alldecay,"selpfjetAK8hasleptop_alldecay[npfjetAK8_thad]/O");
  
  Tout4 = new TTree("qg","qg");
  Tout4->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout4->Branch("weight",&weight,"weight/F");
  Tout4->Branch("DiLeptt",&DiLeptt,"DiLeptt/O");
  Tout4->Branch("SemiLeptt",&SemiLeptt,"SemiLeptt/O");
  Tout4->Branch("Hadtt",&Hadtt,"Hadtt/O");
  Tout4->Branch("npfjetAK8_qg",&npfjetAK8_qg, "npfjetAK8_qg/I");  
  Tout4->Branch("selpfjetAK8pt",selpfjetAK8pt,"selpfjetAK8pt[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8y",selpfjetAK8y,"selpfjetAK8y[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8phi",selpfjetAK8phi,"selpfjetAK8phi[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8mass",selpfjetAK8mass,"selpfjetAK8mass[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8btag_CMVA",selpfjetAK8btag_CMVA,"selpfjetAK8btag_CMVA[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8btag_CSV",selpfjetAK8btag_CSV,"selpfjetAK8btag_CSV[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8btag_DeepCSV",selpfjetAK8btag_DeepCSV,"selpfjetAK8btag_DeepCSV[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8matchAK4deepb",selpfjetAK8matchAK4deepb,"selpfjetAK8matchAK4deepb[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8DeepTag_TvsQCD",selpfjetAK8DeepTag_TvsQCD,"selpfjetAK8DeepTag_TvsQCD[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8DeepTag_WvsQCD",selpfjetAK8DeepTag_WvsQCD,"selpfjetAK8DeepTag_WvsQCD[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8DeepTag_ZvsQCD",selpfjetAK8DeepTag_ZvsQCD,"selpfjetAK8DeepTag_ZvsQCD[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8CHF",selpfjetAK8CHF,"selpfjetAK8CHF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8NHF",selpfjetAK8NHF,"selpfjetAK8NHF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8CEMF",selpfjetAK8CEMF,"selpfjetAK8CEMF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8NEMF",selpfjetAK8NEMF,"selpfjetAK8NEMF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8MUF",selpfjetAK8MUF,"selpfjetAK8MUF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8HOF",selpfjetAK8HOF,"selpfjetAK8HOF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8HadF",selpfjetAK8HadF,"selpfjetAK8HadF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8NHadF",selpfjetAK8NHadF,"selpfjetAK8NHadF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8EmF",selpfjetAK8EmF,"selpfjetAK8EmF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8neuemfrac",selpfjetAK8neuemfrac,"selpfjetAK8neuemfrac[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8neunhadfrac",selpfjetAK8neunhadfrac,"selpfjetAK8neunhadfrac[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8CHM",selpfjetAK8CHM,"selpfjetAK8CHM[npfjetAK8_qg]/I");
  Tout4->Branch("selpfjetAK8NHM",selpfjetAK8NHM,"selpfjetAK8NHM[npfjetAK8_qg]/I");
  Tout4->Branch("selpfjetAK8CEMM",selpfjetAK8CEMM,"selpfjetAK8CEMM[npfjetAK8_qg]/I");
  Tout4->Branch("selpfjetAK8NEMM",selpfjetAK8NEMM,"selpfjetAK8NEMM[npfjetAK8_qg]/I");
  Tout4->Branch("selpfjetAK8MUM",selpfjetAK8MUM,"selpfjetAK8MUM[npfjetAK8_qg]/I");
  Tout4->Branch("selpfjetAK8Neucons",selpfjetAK8Neucons,"selpfjetAK8Neucons[npfjetAK8_qg]/I");
  Tout4->Branch("selpfjetAK8Chcons",selpfjetAK8Chcons,"selpfjetAK8Chcons[npfjetAK8_qg]/I");
  Tout4->Branch("selpfjetAK8chrad",selpfjetAK8chrad,"selpfjetAK8chrad[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8pTD",selpfjetAK8pTD,"selpfjetAK8pTD[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sdmass",selpfjetAK8sdmass,"selpfjetAK8sdmass[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8elsubjptrat",selpfjetAK8elsubjptrat,"selpfjetAK8elsubjptrat[npfjetAK8_qg]/F");

  Tout4->Branch("selpfjetAK8elinsubpt",selpfjetAK8elinsubpt,"selpfjetAK8elinsubpt[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8elinsubeta",selpfjetAK8elinsubeta,"selpfjetAK8elinsubeta[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8elinsubphi",selpfjetAK8elinsubphi,"selpfjetAK8elinsubphi[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8elinsubjpt",selpfjetAK8elinsubjpt,"selpfjetAK8elinsubjpt[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8elinsubjeta",selpfjetAK8elinsubjeta,"selpfjetAK8elinsujbeta[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8elinsubjphi",selpfjetAK8elinsubjphi,"selpfjetAK8elinsubjphi[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8matchedelID",selpfjetAK8matchedelID,"selpfjetAK8matchedelID[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8matchedelpt",selpfjetAK8matchedelpt,"selpfjetAK8matchedelpt[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8matchedeleta",selpfjetAK8matchedeleta,"selpfjetAK8matchedeleta[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8matchedelphi",selpfjetAK8matchedelphi,"selpfjetAK8matchedelphi[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8matchedelE",selpfjetAK8matchedelE,"selpfjetAK8matchedelE[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8matchedeldxy",selpfjetAK8matchedeldxy,"selpfjetAK8matchedeldxy[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8matchedeldxy_sv",selpfjetAK8matchedeldxy_sv,"selpfjetAK8matchedeldxy_sv[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8matchedelcleta",selpfjetAK8matchedelcleta,"selpfjetAK8matchedelcleta[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8matchedelclphi",selpfjetAK8matchedelclphi,"selpfjetAK8matchedelclphi[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8matchedelclrawE",selpfjetAK8matchedelclrawE,"selpfjetAK8matchedelclrawE[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8re_tvsb",selpfjetAK8re_tvsb,"selpfjetAK8re_tvsb[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8rnu_tvsb",selpfjetAK8rnu_tvsb,"selpfjetAK8rnu_tvsb[npfjetAK8_qg]/F");


  Tout4->Branch("selpfjetAK8tau21",selpfjetAK8tau21,"selpfjetAK8tau21[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8tau32",selpfjetAK8tau32,"selpfjetAK8tau32[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sub1mass",selpfjetAK8sub1mass,"selpfjetAK8sub1mass[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sub1btag",selpfjetAK8sub1btag,"selpfjetAK8sub1btag[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sub1hadfrac",selpfjetAK8sub1hadfrac,"selpfjetAK8sub1hadfrac[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sub1emfrac",selpfjetAK8sub1emfrac,"selpfjetAK8sub1emfrac[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sub2mass",selpfjetAK8sub2mass,"selpfjetAK8sub2mass[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sub2btag",selpfjetAK8sub2btag,"selpfjetAK8sub2btag[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sub2hadfrac",selpfjetAK8sub2hadfrac,"selpfjetAK8sub2hadfrac[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sub2emfrac",selpfjetAK8sub2emfrac,"selpfjetAK8sub2emfrac[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8subbtag", pfjetAK8subbtag,"selpfjetAK8subbtag[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8subhaddiff",selpfjetAK8subhaddiff,"selpfjetAK8subhaddiff[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8subemdiff",selpfjetAK8subemdiff,"selpfjetAK8subemdiff[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8subptdiff",selpfjetAK8subptdiff,"selpfjetAK8subptdiff[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8_bbyW_E", selpfjetAK8_bbyW_E,"selpfjetAK8_bbyW_E[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8_Kfactor", selpfjetAK8_Kfactor,"selpfjetAK8_Kfactor[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8_Rnew", selpfjetAK8_Rnew,"selpfjetAK8_Rnew[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8haselectron",selpfjetAK8haselectron,"selpfjetAK8haselectron[npfjetAK8_qg]/O");
  Tout4->Branch("selpfjetAK8hasmuon",selpfjetAK8hasmuon,"selpfjetAK8hasmuon[npfjetAK8_qg]/O");
  Tout4->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_qg]/O");
  Tout4->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_qg]/O");
  Tout4->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_qg]/O");
  Tout4->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_qg]/O");
  Tout4->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_qg]/O");
  
  Tout5 = new TTree("bq","bq");
  Tout5->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout5->Branch("weight",&weight,"weight/F");
  Tout5->Branch("DiLeptt",&DiLeptt,"DiLeptt/O");
  Tout5->Branch("SemiLeptt",&SemiLeptt,"SemiLeptt/O");
  Tout5->Branch("Hadtt",&Hadtt,"Hadtt/O");
  Tout5->Branch("npfjetAK8_b",&npfjetAK8_b, "npfjetAK8_b/I"); 
  Tout5->Branch("selpfjetAK8pt",selpfjetAK8pt,"selpfjetAK8pt[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8y",selpfjetAK8y,"selpfjetAK8y[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8phi",selpfjetAK8phi,"selpfjetAK8phi[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8mass",selpfjetAK8mass,"selpfjetAK8mass[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8btag_CMVA",selpfjetAK8btag_CMVA,"selpfjetAK8btag_CMVA[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8btag_CSV",selpfjetAK8btag_CSV,"selpfjetAK8btag_CSV[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8btag_DeepCSV",selpfjetAK8btag_DeepCSV,"selpfjetAK8btag_DeepCSV[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchAK4deepb",selpfjetAK8matchAK4deepb,"selpfjetAK8matchAK4deepb[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8DeepTag_TvsQCD",selpfjetAK8DeepTag_TvsQCD,"selpfjetAK8DeepTag_TvsQCD[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8DeepTag_WvsQCD",selpfjetAK8DeepTag_WvsQCD,"selpfjetAK8DeepTag_WvsQCD[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8DeepTag_ZvsQCD",selpfjetAK8DeepTag_ZvsQCD,"selpfjetAK8DeepTag_ZvsQCD[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8CHF",selpfjetAK8CHF,"selpfjetAK8CHF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8NHF",selpfjetAK8NHF,"selpfjetAK8NHF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8CEMF",selpfjetAK8CEMF,"selpfjetAK8CEMF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8NEMF",selpfjetAK8NEMF,"selpfjetAK8NEMF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8MUF",selpfjetAK8MUF,"selpfjetAK8MUF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8HOF",selpfjetAK8HOF,"selpfjetAK8HOF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8HadF",selpfjetAK8HadF,"selpfjetAK8HadF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8NHadF",selpfjetAK8NHadF,"selpfjetAK8NHadF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8EmF",selpfjetAK8EmF,"selpfjetAK8EmF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8neuemfrac",selpfjetAK8neuemfrac,"selpfjetAK8neuemfrac[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8neunhadfrac",selpfjetAK8neunhadfrac,"selpfjetAK8neunhadfrac[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8CHM",selpfjetAK8CHM,"selpfjetAK8CHM[npfjetAK8_b]/I");
  Tout5->Branch("selpfjetAK8NHM",selpfjetAK8NHM,"selpfjetAK8NHM[npfjetAK8_b]/I");
  Tout5->Branch("selpfjetAK8CEMM",selpfjetAK8CEMM,"selpfjetAK8CEMM[npfjetAK8_b]/I");
  Tout5->Branch("selpfjetAK8NEMM",selpfjetAK8NEMM,"selpfjetAK8NEMM[npfjetAK8_b]/I");
  Tout5->Branch("selpfjetAK8MUM",selpfjetAK8MUM,"selpfjetAK8MUM[npfjetAK8_b]/I");
  Tout5->Branch("selpfjetAK8Neucons",selpfjetAK8Neucons,"selpfjetAK8Neucons[npfjetAK8_b]/I");
  Tout5->Branch("selpfjetAK8Chcons",selpfjetAK8Chcons,"selpfjetAK8Chcons[npfjetAK8_b]/I");
  Tout5->Branch("selpfjetAK8chrad",selpfjetAK8chrad,"selpfjetAK8chrad[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8pTD",selpfjetAK8pTD,"selpfjetAK8pTD[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sdmass",selpfjetAK8sdmass,"selpfjetAK8sdmass[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8elsubjptrat",selpfjetAK8elsubjptrat,"selpfjetAK8elsubjptrat[npfjetAK8_b]/F");

  Tout5->Branch("selpfjetAK8elinsubpt",selpfjetAK8elinsubpt,"selpfjetAK8elinsubpt[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8elinsubeta",selpfjetAK8elinsubeta,"selpfjetAK8elinsubeta[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8elinsubphi",selpfjetAK8elinsubphi,"selpfjetAK8elinsubphi[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8elinsubjpt",selpfjetAK8elinsubjpt,"selpfjetAK8elinsubjpt[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8elinsubjeta",selpfjetAK8elinsubjeta,"selpfjetAK8elinsujbeta[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8elinsubjphi",selpfjetAK8elinsubjphi,"selpfjetAK8elinsubjphi[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelID",selpfjetAK8matchedelID,"selpfjetAK8matchedelID[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelpt",selpfjetAK8matchedelpt,"selpfjetAK8matchedelpt[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedeleta",selpfjetAK8matchedeleta,"selpfjetAK8matchedeleta[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelphi",selpfjetAK8matchedelphi,"selpfjetAK8matchedelphi[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelE",selpfjetAK8matchedelE,"selpfjetAK8matchedelE[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedeldxy",selpfjetAK8matchedeldxy,"selpfjetAK8matchedeldxy[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedeldxy_sv",selpfjetAK8matchedeldxy_sv,"selpfjetAK8matchedeldxy_sv[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelcleta",selpfjetAK8matchedelcleta,"selpfjetAK8matchedelcleta[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelclphi",selpfjetAK8matchedelclphi,"selpfjetAK8matchedelclphi[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelclrawE",selpfjetAK8matchedelclrawE,"selpfjetAK8matchedelclrawE[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8re_tvsb",selpfjetAK8re_tvsb,"selpfjetAK8re_tvsb[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8rnu_tvsb",selpfjetAK8rnu_tvsb,"selpfjetAK8rnu_tvsb[npfjetAK8_b]/F");


  Tout5->Branch("selpfjetAK8tau21",selpfjetAK8tau21,"selpfjetAK8tau21[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8tau32",selpfjetAK8tau32,"selpfjetAK8tau32[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sub1mass",selpfjetAK8sub1mass,"selpfjetAK8sub1mass[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sub1btag",selpfjetAK8sub1btag,"selpfjetAK8sub1btag[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sub1hadfrac",selpfjetAK8sub1hadfrac,"selpfjetAK8sub1hadfrac[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sub1emfrac",selpfjetAK8sub1emfrac,"selpfjetAK8sub1emfrac[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sub2mass",selpfjetAK8sub2mass,"selpfjetAK8sub2mass[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sub2btag",selpfjetAK8sub2btag,"selpfjetAK8sub2btag[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sub2hadfrac",selpfjetAK8sub2hadfrac,"selpfjetAK8sub2hadfrac[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sub2emfrac",selpfjetAK8sub2emfrac,"selpfjetAK8sub2emfrac[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8subbtag", pfjetAK8subbtag,"selpfjetAK8subbtag[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8subhaddiff",selpfjetAK8subhaddiff,"selpfjetAK8subhaddiff[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8subemdiff",selpfjetAK8subemdiff,"selpfjetAK8subemdiff[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8subptdiff",selpfjetAK8subptdiff,"selpfjetAK8subptdiff[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8_bbyW_E", selpfjetAK8_bbyW_E,"selpfjetAK8_bbyW_E[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8_Kfactor", selpfjetAK8_Kfactor,"selpfjetAK8_Kfactor[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8_Rnew", selpfjetAK8_Rnew,"selpfjetAK8_Rnew[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8haselectron",selpfjetAK8haselectron,"selpfjetAK8haselectron[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasmuon",selpfjetAK8hasmuon,"selpfjetAK8hasmuon[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_b]/O");
  
  Tout6 = new TTree("inclusive","inclusive");
  Tout6->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout6->Branch("weight",&weight,"weight/F");
  Tout6->Branch("DiLeptt",&DiLeptt,"DiLeptt/O");
  Tout6->Branch("SemiLeptt",&SemiLeptt,"SemiLeptt/O");
  Tout6->Branch("Hadtt",&Hadtt,"Hadtt/O");
  Tout6->Branch("nleptop",&nleptop,"nleptop/I");
  Tout6->Branch("PFMET",&PFMET,"PFMET/F");
  Tout6->Branch("npfjetAK8_all",&npfjetAK8_all, "npfjetAK8_all/I"); 
  Tout6->Branch("selpfjetAK8pt",selpfjetAK8pt,"selpfjetAK8pt[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8y",selpfjetAK8y,"selpfjetAK8y[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8phi",selpfjetAK8phi,"selpfjetAK8phi[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8mass",selpfjetAK8mass,"selpfjetAK8mass[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8btag_CMVA",selpfjetAK8btag_CMVA,"selpfjetAK8btag_CMVA[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8btag_CSV",selpfjetAK8btag_CSV,"selpfjetAK8btag_CSV[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8btag_DeepCSV",selpfjetAK8btag_DeepCSV,"selpfjetAK8btag_DeepCSV[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8matchAK4deepb",selpfjetAK8matchAK4deepb,"selpfjetAK8matchAK4deepb[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8DeepTag_TvsQCD",selpfjetAK8DeepTag_TvsQCD,"selpfjetAK8DeepTag_TvsQCD[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8DeepTag_WvsQCD",selpfjetAK8DeepTag_WvsQCD,"selpfjetAK8DeepTag_WvsQCD[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8DeepTag_ZvsQCD",selpfjetAK8DeepTag_ZvsQCD,"selpfjetAK8DeepTag_ZvsQCD[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8CHF",selpfjetAK8CHF,"selpfjetAK8CHF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8NHF",selpfjetAK8NHF,"selpfjetAK8NHF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8CEMF",selpfjetAK8CEMF,"selpfjetAK8CEMF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8NEMF",selpfjetAK8NEMF,"selpfjetAK8NEMF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8MUF",selpfjetAK8MUF,"selpfjetAK8MUF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8HOF",selpfjetAK8HOF,"selpfjetAK8HOF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8HadF",selpfjetAK8HadF,"selpfjetAK8HadF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8NHadF",selpfjetAK8NHadF,"selpfjetAK8NHadF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8EmF",selpfjetAK8EmF,"selpfjetAK8EmF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8neuemfrac",selpfjetAK8neuemfrac,"selpfjetAK8neuemfrac[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8neunhadfrac",selpfjetAK8neunhadfrac,"selpfjetAK8neunhadfrac[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8CHM",selpfjetAK8CHM,"selpfjetAK8CHM[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8NHM",selpfjetAK8NHM,"selpfjetAK8NHM[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8CEMM",selpfjetAK8CEMM,"selpfjetAK8CEMM[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8NEMM",selpfjetAK8NEMM,"selpfjetAK8NEMM[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8MUM",selpfjetAK8MUM,"selpfjetAK8MUM[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8EEM",selpfjetAK8EEM,"selpfjetAK8EEM[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8Neucons",selpfjetAK8Neucons,"selpfjetAK8Neucons[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8Chcons",selpfjetAK8Chcons,"selpfjetAK8Chcons[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8chrad",selpfjetAK8chrad,"selpfjetAK8chrad[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8pTD",selpfjetAK8pTD,"selpfjetAK8pTD[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sdmass",selpfjetAK8sdmass,"selpfjetAK8sdmass[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8elsubjptrat",selpfjetAK8elsubjptrat,"selpfjetAK8elsubjptrat[npfjetAK8_all]/F");

  Tout6->Branch("selpfjetAK8elinsubpt",selpfjetAK8elinsubpt,"selpfjetAK8elinsubpt[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8elinsubeta",selpfjetAK8elinsubeta,"selpfjetAK8elinsubeta[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8elinsubphi",selpfjetAK8elinsubphi,"selpfjetAK8elinsubphi[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8elinsubjpt",selpfjetAK8elinsubjpt,"selpfjetAK8elinsubjpt[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8elinsubjeta",selpfjetAK8elinsubjeta,"selpfjetAK8elinsujbeta[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8elinsubjphi",selpfjetAK8elinsubjphi,"selpfjetAK8elinsubjphi[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8matchedelID",selpfjetAK8matchedelID,"selpfjetAK8matchedelID[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8matchedelpt",selpfjetAK8matchedelpt,"selpfjetAK8matchedelpt[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8matchedeleta",selpfjetAK8matchedeleta,"selpfjetAK8matchedeleta[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8matchedelphi",selpfjetAK8matchedelphi,"selpfjetAK8matchedelphi[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8matchedelE",selpfjetAK8matchedelE,"selpfjetAK8matchedelE[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8matchedeldxy",selpfjetAK8matchedeldxy,"selpfjetAK8matchedeldxy[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8matchedeldxy_sv",selpfjetAK8matchedeldxy_sv,"selpfjetAK8matchedeldxy_sv[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8matchedelcleta",selpfjetAK8matchedelcleta,"selpfjetAK8matchedelcleta[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8matchedelclphi",selpfjetAK8matchedelclphi,"selpfjetAK8matchedelclphi[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8matchedelclrawE",selpfjetAK8matchedelclrawE,"selpfjetAK8matchedelclrawE[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8re_tvsb",selpfjetAK8re_tvsb,"selpfjetAK8re_tvsb[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8rnu_tvsb",selpfjetAK8rnu_tvsb,"selpfjetAK8rnu_tvsb[npfjetAK8_all]/F");


  Tout6->Branch("selpfjetAK8tau21",selpfjetAK8tau21,"selpfjetAK8tau21[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8tau32",selpfjetAK8tau32,"selpfjetAK8tau32[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sub1mass",selpfjetAK8sub1mass,"selpfjetAK8sub1mass[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sub1btag",selpfjetAK8sub1btag,"selpfjetAK8sub1btag[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sub1hadfrac",selpfjetAK8sub1hadfrac,"selpfjetAK8sub1hadfrac[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sub1emfrac",selpfjetAK8sub1emfrac,"selpfjetAK8sub1emfrac[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sub2mass",selpfjetAK8sub2mass,"selpfjetAK8sub2mass[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sub2btag",selpfjetAK8sub2btag,"selpfjetAK8sub2btag[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sub2hadfrac",selpfjetAK8sub2hadfrac,"selpfjetAK8sub2hadfrac[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sub2emfrac",selpfjetAK8sub2emfrac,"selpfjetAK8sub2emfrac[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8subbtag", pfjetAK8subbtag,"selpfjetAK8subbtag[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8subhaddiff",selpfjetAK8subhaddiff,"selpfjetAK8subhaddiff[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8subemdiff",selpfjetAK8subemdiff,"selpfjetAK8subemdiff[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8subptdiff",selpfjetAK8subptdiff,"selpfjetAK8subptdiff[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8_bbyW_E", selpfjetAK8_bbyW_E,"selpfjetAK8_bbyW_E[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8_Kfactor", selpfjetAK8_Kfactor,"selpfjetAK8_Kfactor[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8_Rnew", selpfjetAK8_Rnew,"selpfjetAK8_Rnew[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8haselectron",selpfjetAK8haselectron,"selpfjetAK8haselectron[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hasmuon",selpfjetAK8hasmuon,"selpfjetAK8hasmuon[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hashadtop_alldecay",selpfjetAK8hashadtop_alldecay,"selpfjetAK8hashadtop_alldecay[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hasleptop_alldecay",selpfjetAK8hasleptop_alldecay,"selpfjetAK8hasleptop_alldecay[npfjetAK8_all]/O");
  
  #endif
  
  hvsb_re = new TH1D("rev", "rev", 1000, -1.0, 1.0);
  helinidiso = new TH1D("elinidiso","elinidiso", 4, 0.0, 4.0);
  hreelinidiso = new TH1D("hreelinidiso", "hreelinidiso", 4, 0.0, 4.0);
  hreelinidiso_str = new TH1D("hreelinidiso_str", "hreelinidiso_str", 4, 0.0, 4.0);


  h2d_eldxy_sv_elIDv = new TH2D("h2d_eldxy_sv_elIDv","h2d_eldxy_sv_elIDv", 200, -0.25, 0.25, 200, -0.05, 1.05);
  h2d_reeldxy_sv_elIDv = new TH2D("h2d_reeldxy_sv_elIDv","h2d_reeldxy_sv_elIDv", 200, -0.25, 0.25, 200, -0.05, 1.05);

  helinpt = new TH1D("elinpt","elinpt", 400, 0, 1000.0);
  helinpt->Sumw2();
  helinid = new TH1D("elinid","elinid", 400, -0.05, 1.05);
  helinid->Sumw2();

  hreelinpt = new TH1D("re_elinpt","re_elinpt", 400, 0, 1000.0);
  hreelinpt->Sumw2();
  hreelinid = new TH1D("re_elinid","re_elinid", 400, -0.05, 1.05);
  hreelinid->Sumw2();


  htelinpt = new TH1D("t_elinpt","t_elinpt", 400, 0, 1000.0);
  htelinpt->Sumw2();
  htelinid = new TH1D("t_elinid","t_elinid", 400, -0.05, 1.05);
  htelinid->Sumw2();

  htrelinpt = new TH1D("t_re_elinpt","t_re_elinpt", 400, 0, 1000.0);
  htrelinpt->Sumw2();
  htrelinid = new TH1D("t_re_elinid","t_re_elinid", 400, -0.05, 1.05);
  htrelinid->Sumw2();


  helpt = new TH1D("elptIn","elptIn", 400, 0, 1000.0);
  helpt->Sumw2();
  helpt_gre = new TH1D("elptIn_gre","elptIn_gre", 400, 0, 1000.0);
  helpt_gre->Sumw2();
  helptID = new TH1D("elptIn_WID","elptIn_WID", 400, 0, 1000.0);
  helptID->Sumw2();
  helptID_gre = new TH1D("elptIn_WID_gre","elptIn_WID_gre", 400, 0, 1000.0);
  helptID_gre->Sumw2();

  ht = new TH1D("trawE","trawE", 200, 0, 2000.0);
  ht->Sumw2();
  hteldxy = new TH1D("teldxy","teldxy", 2000, -0.2, 0.2);
  hteldxy->Sumw2();
  hteldxy_sv = new TH1D("teldxy_sv","teldxy_sv", 2000, -0.2, 0.2);
  hteldxy_sv->Sumw2();
  htelsubptrat = new TH1D("telsubptrat", "telsubptrat", 200, 0, 1.5);
  htelsubptrat->Sumw2();
  htelcleta = new TH1D("telcleta", "telcleta", 200, -3.0, 3.0);
  htelcleta->Sumw2();
  htre = new TH1D("trawE_gre","trawE_gre", 200, 0, 2000.0);
  htre->Sumw2();
  htreeldxy = new TH1D("teldxy_gre","teldxy_gre", 2000, -0.2, 0.2);
  htreeldxy->Sumw2();
  htreeldxy_sv = new TH1D("teldxy_sv_gre","teldxy_sv_gre", 2000, -0.2, 0.2);
  htreeldxy_sv->Sumw2();
  htreelsubptrat = new TH1D("telsubptrat_gre", "telsubptrat_gre", 200, 0, 1.5);
  htreelsubptrat->Sumw2();
  htreelcleta = new TH1D("telcleta_gre", "telcleta_gre", 200, -3.0, 3.0);
  htreelcleta->Sumw2();

  hljetpt = new TH1D("ljetpt", "ljetpt", 100, 300, 3000);
  hljety = new TH1D("ljety", "ljety", 100, -3.0, 3.0);
  hljetphi = new TH1D("ljetphi", "ljetphi", 100, -3.14, 3.14);
  hljetmass = new TH1D("ljetmass", "ljetmass", 100, 0, 500);

  hljetpt->Sumw2();
  hljety->Sumw2();
  hljetphi->Sumw2();
  hljetmass->Sumw2();

  char name[1000];
  char title[1000];
  
  for(int ihist2D=0; ihist2D<nhist2D; ihist2D++){
    sprintf(name,"%s_tlepe",branch2Dnames[ihist2D]);
    hist_12D[ihist2D] = new TH2D(name,name,hist_nbins2D[ihist2D],hist_low2D[ihist2D],hist_up2D[ihist2D],hist_nbins2D[ihist2D],hist_low2D[ihist2D],hist_up2D[ihist2D]);
    
    sprintf(name,"%s_b",branch2Dnames[ihist2D]);
    hist_52D[ihist2D] = new TH2D(name,name,hist_nbins2D[ihist2D],hist_low2D[ihist2D],hist_up2D[ihist2D],hist_nbins2D[ihist2D],hist_low2D[ihist2D],hist_up2D[ihist2D]);
  }

  for(int ihist2D=0; ihist2D<nhist2Dnew; ihist2D++){
    sprintf(name,"%s_tlepe",branch2Dnamesnew[ihist2D]);
    hist_12Dnew[ihist2D] = new TH2D(name,name,hist_nbins2Dnew[ihist2D],hist_lowx2D[ihist2D],hist_highx2D[ihist2D],hist_nbins2Dnew[ihist2D],hist_lowy2D[ihist2D],hist_highy2D[ihist2D]);
    
    sprintf(name,"%s_b",branch2Dnamesnew[ihist2D]);
    hist_52Dnew[ihist2D] = new TH2D(name,name,hist_nbins2Dnew[ihist2D],hist_lowx2D[ihist2D],hist_highx2D[ihist2D],hist_nbins2Dnew[ihist2D],hist_lowy2D[ihist2D],hist_highy2D[ihist2D]);

    sprintf(name,"%s_topcand",branch2Dnamesnew[ihist2D]);
    hist_62Dnew[ihist2D] = new TH2D(name,name,hist_nbins2Dnew[ihist2D],hist_lowx2D[ihist2D],hist_highx2D[ihist2D],hist_nbins2Dnew[ihist2D],hist_lowy2D[ihist2D],hist_highy2D[ihist2D]);
  }
  
  for(int ihist=0; ihist<nhist; ihist++){
    
    sprintf(name,"%s_tlepe",branchnames[ihist]);
    hist_1[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
    hist_1[ihist]->Sumw2();
    
    sprintf(name,"%s_tlepmu",branchnames[ihist]);
    hist_2[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
    hist_2[ihist]->Sumw2();
    
    sprintf(name,"%s_thad",branchnames[ihist]);
    hist_3[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
    hist_3[ihist]->Sumw2();
    
    sprintf(name,"%s_qg",branchnames[ihist]);
    hist_4[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
    hist_4[ihist]->Sumw2();
    
    sprintf(name,"%s_b",branchnames[ihist]);
    hist_5[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
    hist_5[ihist]->Sumw2();
    
    sprintf(name,"%s_topcand",branchnames[ihist]);
    hist_6[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
    hist_6[ihist]->Sumw2();
  }
  sprintf(name,"H2D_re_rnu_tlepe");
  h2d_re_rnu_1 = new TH2D(name,name,900, -1.0, 1.0, 80, -1.0, 1.0);
  sprintf(name,"H2D_re_rnu_tlepmu");
  h2d_re_rnu_2 = new TH2D(name,name,900, -1.0, 1.0, 80, -1.0, 1.0);
  sprintf(name,"H2D_re_rnu_thad");
  h2d_re_rnu_3 = new TH2D(name,name,900, -1.0, 1.0, 80, -1.0, 1.0);
  sprintf(name,"H2D_re_rnu_qg");
  h2d_re_rnu_4 = new TH2D(name,name,900, -1.0, 1.0, 80, -1.0, 1.0);
  sprintf(name,"H2D_re_rnu_b");
  h2d_re_rnu_5 = new TH2D(name,name,900, -1.0, 1.0, 80, -1.0, 1.0);
  sprintf(name,"H2D_re_rnu_topcand");
  h2d_re_rnu_6 = new TH2D(name,name,900, -1.0, 1.0, 80, -1.0, 1.0);
  

  sprintf(name,"tecount");
  h_te_count = new TH1D(name, name, 100, -1.5, 1.5);
  h_te_count->Sumw2();
  
  sprintf(name,"tecount_tr");
  h_te_count_tr = new TH1D(name, name, 100, -1.5, 1.5);
  h_te_count_tr->Sumw2();

  sprintf(name,"recount_tr");
  h_re_count_tr = new TH1D(name, name, 100, -1.5, 1.5);
  h_re_count_tr->Sumw2();

  sprintf(name,"tstcount_tr");
  h_ts_count_tr = new TH1D(name, name, 100, -1.5, 1.5);
  h_ts_count_tr->Sumw2();

  sprintf(name, "rawE");
  h = new TH1D(name, name, 200, 0, 2000.0);
  h->Sumw2();

  sprintf(name, "Re");
  h_Re = new TH1D(name, name, 1000, -1.0, 1.0);
  h_Re->Sumw2();

  sprintf(name, "Re_gre");
  h_reRe = new TH1D(name, name, 1000, -1.0, 1.0);
  h_reRe->Sumw2();

  sprintf(name, "eldxy");
  heldxy = new TH1D(name, name, 2000, -0.2, 0.2);
  heldxy->Sumw2();
  sprintf(name, "eldxy_sv");
  heldxy_sv = new TH1D(name, name, 2000, -0.2, 0.2);
  heldxy_sv->Sumw2();
  sprintf(name, "elsubptrat");
  helsubptrat = new TH1D(name, name, 200, 0, 1.5);
  helsubptrat->Sumw2();
  sprintf(name, "elcleta");
  helcleta = new TH1D(name, name, 200, -3.0, 3.0);
  helcleta->Sumw2();
  sprintf(name, "rawE_gre");
  hre = new TH1D(name, name, 200, 0, 2000.0);
  hre->Sumw2();
  sprintf(name, "eldxy_gre");
  hreeldxy = new TH1D(name, name, 2000, -0.2, 0.2);
  hreeldxy->Sumw2();
  sprintf(name, "eldxy_sv_gre");
  hreeldxy_sv = new TH1D(name, name, 2000, -0.2, 0.2);
  hreeldxy_sv->Sumw2();
  sprintf(name, "elsubptrat_gre");
  hreelsubptrat = new TH1D(name, name, 200, 0, 1.5);
  hreelsubptrat->Sumw2();
  sprintf(name, "elcleta_gre");
  hreelcleta = new TH1D(name, name, 200, -3.0, 3.0);
  hreelcleta->Sumw2();

  sprintf(name, "rawE_NoID");
  h_NoID_ = new TH1D(name, name, 200, 0, 2000.0);
  h_NoID_->Sumw2();
  sprintf(name, "eldxy_NoID");
  h_NoID_eldxy = new TH1D(name, name, 2000, -0.2, 0.2);
  h_NoID_eldxy->Sumw2();
  sprintf(name, "eldxy_sv_NoID");
  h_NoID_eldxy_sv = new TH1D(name, name, 2000, -0.2, 0.2);
  h_NoID_eldxy_sv->Sumw2();
  sprintf(name, "elsubptrat_NoID");
  h_NoID_elsubptrat = new TH1D(name, name, 200, 0, 1.5);
  h_NoID_elsubptrat->Sumw2();
  sprintf(name, "elcleta_NoID");
  h_NoID_elcleta = new TH1D(name, name, 200, -3.0, 3.0);
  h_NoID_elcleta->Sumw2();
  sprintf(name, "rawE_gre_NoID");
  h_NoID_re = new TH1D(name, name, 200, 0, 2000.0);
  h_NoID_re->Sumw2();
  sprintf(name, "eldxy_gre_NoID");
  h_NoID_reeldxy = new TH1D(name, name, 2000, -0.2, 0.2);
  h_NoID_reeldxy->Sumw2();
  sprintf(name, "eldxy_sv_gre_NoID");
  h_NoID_reeldxy_sv = new TH1D(name, name, 2000, -0.2, 0.2);
  h_NoID_reeldxy_sv->Sumw2();
  sprintf(name, "elsubptrat_gre_NoID");
  h_NoID_reelsubptrat = new TH1D(name, name, 200, 0, 1.5);
  h_NoID_reelsubptrat->Sumw2();
  sprintf(name, "elcleta_gre_NoID");
  h_NoID_reelcleta = new TH1D(name, name, 200, -3.0, 3.0);
  h_NoID_reelcleta->Sumw2();

  sprintf(name, "elptIn");
  h_NoID_elptIn = new TH1D(name, name, 500, 0, 1000);
  h_NoID_elptIn->Sumw2();

  sprintf(name, "elptIn_gre");
  h_NoID_reelptIn = new TH1D(name, name, 500, 0, 1000);
  h_NoID_reelptIn->Sumw2();

  sprintf(name, "rawE_Noelpt");
  h_Noelpt_ = new TH1D(name, name, 200, 0, 2000.0);
  h_Noelpt_->Sumw2();
  sprintf(name, "eldxy_Noelpt");
  h_Noelpt_eldxy = new TH1D(name, name, 2000, -0.2, 0.2);
  h_Noelpt_eldxy->Sumw2();
  sprintf(name, "eldxy_sv_Noelpt");
  h_Noelpt_eldxy_sv = new TH1D(name, name, 2000, -0.2, 0.2);
  h_Noelpt_eldxy_sv->Sumw2();
  sprintf(name, "elsubptrat_Noelpt");
  h_Noelpt_elsubptrat = new TH1D(name, name, 200, 0, 1.5);
  h_Noelpt_elsubptrat->Sumw2();
  sprintf(name, "elcleta_Noelpt");
  h_Noelpt_elcleta = new TH1D(name, name, 200, -3.0, 3.0);
  h_Noelpt_elcleta->Sumw2();
  sprintf(name, "rawE_gre_Noelpt");
  h_Noelpt_re = new TH1D(name, name, 200, 0, 2000.0);
  h_Noelpt_re->Sumw2();
  sprintf(name, "eldxy_gre_Noelpt");
  h_Noelpt_reeldxy = new TH1D(name, name, 2000, -0.2, 0.2);
  h_Noelpt_reeldxy->Sumw2();
  sprintf(name, "eldxy_sv_gre_Noelpt");
  h_Noelpt_reeldxy_sv = new TH1D(name, name, 2000, -0.2, 0.2);
  h_Noelpt_reeldxy_sv->Sumw2();
  sprintf(name, "elsubptrat_gre_Noelpt");
  h_Noelpt_reelsubptrat = new TH1D(name, name, 200, 0, 1.5);
  h_Noelpt_reelsubptrat->Sumw2();
  sprintf(name, "elcleta_gre_Noelpt");
  h_Noelpt_reelcleta = new TH1D(name, name, 200, -3.0, 3.0);
  h_Noelpt_reelcleta->Sumw2();

  sprintf(name, "elptIn_Noelpt");
  h_Noelpt_elptIn = new TH1D(name, name, 500, 0, 1000);
  h_Noelpt_elptIn->Sumw2();
  
  sprintf(name, "elptIn_gre_Noelpt");
  h_Noelpt_reelptIn = new TH1D(name, name, 500, 0, 1000);
  h_Noelpt_reelptIn->Sumw2();

  sprintf(name, "eldxy_subjet");
  h1d_eldxy_subjet = new TH1D(name,name,100,-3.0,3.0);
  h1d_eldxy_subjet->Sumw2();

  sprintf(name, "eldxy_subjetM"); 
  h1d_eldxy_subjetM = new TH1D(name,name,100,-3.0,3.0);                                                                                       h1d_eldxy_subjetM->Sumw2();
  
  sprintf(name, "eldxy_subjet_tlepe"); 
  h1d_eldxy_subjet_tlepe = new TH1D(name,name,100,-3.0,3.0);
  h1d_eldxy_subjet_tlepe->Sumw2();
  
  sprintf(name, "eldxy_subjetM_tlepe");
  h1d_eldxy_subjetM_tlepe = new TH1D(name,name,100,-3.0,3.0);                                                                                                                                            
  h1d_eldxy_subjetM_tlepe->Sumw2();
  
  sprintf(name, "eldxy_subjet_b");                                                                                                                                                                  
  h1d_eldxy_subjet_b = new TH1D(name,name,100,-3.0,3.0);                                                                                                                                            
  h1d_eldxy_subjet_b->Sumw2();                                                                                                                                                                      
  
  sprintf(name, "eldxy_subjetM_b");                                                                                                                                                                 
  h1d_eldxy_subjetM_b = new TH1D(name,name,100,-3.0,3.0);                                                                                                                                            
  h1d_eldxy_subjetM_b->Sumw2();
  
  
  sprintf(name, "eldxy_subjet_gRe");
  h1d_eldxy_subjet_gRe = new TH1D(name,name,100,-3.0,3.0);
  h1d_eldxy_subjet_gRe->Sumw2();

  sprintf(name, "eldxy_subjetM_gRe");
  h1d_eldxy_subjetM_gRe = new TH1D(name,name,100,-3.0,3.0);
  h1d_eldxy_subjetM_gRe->Sumw2();

  sprintf(name, "eldxy_subjet_tlepe_gRe");
  h1d_eldxy_subjet_tlepe_gRe = new TH1D(name,name,100,-3.0,3.0);
  h1d_eldxy_subjet_tlepe_gRe->Sumw2();

  sprintf(name, "eldxy_subjetM_tlepe_gRe");
  h1d_eldxy_subjetM_tlepe_gRe = new TH1D(name,name,100,-3.0,3.0);
  h1d_eldxy_subjetM_tlepe_gRe->Sumw2();

  sprintf(name, "eldxy_subjet_b_gRe");
  h1d_eldxy_subjet_b_gRe = new TH1D(name,name,100,-3.0,3.0);
  h1d_eldxy_subjet_b_gRe->Sumw2();

  sprintf(name, "eldxy_subjetM_b_gRe");
  h1d_eldxy_subjetM_b_gRe = new TH1D(name,name,100,-3.0,3.0);
  h1d_eldxy_subjetM_b_gRe->Sumw2();


  sprintf(name, "eldxy_subjet_lRe");
  h1d_eldxy_subjet_lRe = new TH1D(name,name,100,-3.0,3.0);
  h1d_eldxy_subjet_lRe->Sumw2();

  sprintf(name, "eldxy_subjetM_lRe");
  h1d_eldxy_subjetM_lRe = new TH1D(name,name,100,-3.0,3.0);
  h1d_eldxy_subjetM_lRe->Sumw2();

  sprintf(name, "eldxy_subjet_tlepe_lRe");
  h1d_eldxy_subjet_tlepe_lRe = new TH1D(name,name,100,-3.0,3.0);
  h1d_eldxy_subjet_tlepe_lRe->Sumw2();

  sprintf(name, "eldxy_subjetM_tlepe_lRe");
  h1d_eldxy_subjetM_tlepe_lRe = new TH1D(name,name,100,-3.0,3.0);
  h1d_eldxy_subjetM_tlepe_lRe->Sumw2();

  sprintf(name, "eldxy_subjet_b_lRe");
  h1d_eldxy_subjet_b_lRe = new TH1D(name,name,100,-3.0,3.0);
  h1d_eldxy_subjet_b_lRe->Sumw2();

  sprintf(name, "eldxy_subjetM_b_lRe");
  h1d_eldxy_subjetM_b_lRe = new TH1D(name,name,100,-3.0,3.0);
  h1d_eldxy_subjetM_b_lRe->Sumw2();


  sprintf(name, "elpt_subjet");
  h1d_elpt_subjet = new TH1D(name,name,100,0,1000);
  h1d_elpt_subjet->Sumw2();


  sprintf(name, "elpt_subjetM");
  h1d_elpt_subjetM = new TH1D(name,name,100,0,1000);
  h1d_elpt_subjetM->Sumw2();


  sprintf(name, "elpt_subjet_tlepe");
  h1d_elpt_subjet_tlepe = new TH1D(name,name,100,0,1000);
  h1d_elpt_subjet_tlepe->Sumw2();

  sprintf(name, "elpt_subjetM_tlepe");
  h1d_elpt_subjetM_tlepe = new TH1D(name,name,100,0,1000);
  h1d_elpt_subjetM_tlepe->Sumw2();


  sprintf(name, "elpt_subjet_b");
  h1d_elpt_subjet_b = new TH1D(name,name,100,0,1000);
  h1d_elpt_subjet_b->Sumw2();

  sprintf(name, "elpt_subjetM_b");
  h1d_elpt_subjetM_b = new TH1D(name,name,100,0,1000);
  h1d_elpt_subjetM_b->Sumw2();


  sprintf(name, "el subjet ratio");
  h1d_elsubrat = new TH1D(name,name,50,0,1.0);
  h1d_elsubrat->Sumw2();

   sprintf(name, "el subjet ratio with LMJ");
  h1d_elsubratM = new TH1D(name,name,50,0,1.0);
  h1d_elsubratM->Sumw2();


  sprintf(name, "el subjet ratio with tlepe");
  h1d_elsubrat_tlepe = new TH1D(name,name,50,0,1.0);
  h1d_elsubrat_tlepe->Sumw2();

  sprintf(name, "el subjet ratio with tlepe with LMJ");
  h1d_elsubratM_tlepe = new TH1D(name,name,50,0,1.0);
  h1d_elsubratM_tlepe->Sumw2();

  sprintf(name, "el subjet ratio with b");
  h1d_elsubrat_b = new TH1D(name,name,50,0,1.0);
  h1d_elsubrat_b->Sumw2();

  sprintf(name, "el subjet ratio with b with LMJ");
  h1d_elsubratM_b = new TH1D(name,name,50,0,1.0);
  h1d_elsubratM_b->Sumw2();

  sprintf(name, "el subjet ratio & gRe");
  h1d_elsubrat_gRe = new TH1D(name,name,50,0,1.0);
  h1d_elsubrat_gRe->Sumw2();

  sprintf(name, "el subjet ratio with LMJ & gRe");
  h1d_elsubratM_gRe = new TH1D(name,name,50,0,1.0);
  h1d_elsubratM_gRe->Sumw2();

  sprintf(name, "el subjet ratio with tlepe & gRe");
  h1d_elsubrat_tlepe_gRe = new TH1D(name,name,50,0,1.0);
  h1d_elsubrat_tlepe_gRe->Sumw2();

  sprintf(name, "el subjet ratio with tlepe with LMJ & gRe");
  h1d_elsubratM_tlepe_gRe = new TH1D(name,name,50,0,1.0);
  h1d_elsubratM_tlepe_gRe->Sumw2();

  sprintf(name, "el subjet ratio with b & gRe");
  h1d_elsubrat_b_gRe = new TH1D(name,name,50,0,1.0);
  h1d_elsubrat_b_gRe->Sumw2();

  sprintf(name, "el subjet ratio with b with LMJ & gRe");
  h1d_elsubratM_b_gRe = new TH1D(name,name,50,0,1.0);
  h1d_elsubratM_b_gRe->Sumw2();


  sprintf(name, "el subjet ratio & lRe");
  h1d_elsubrat_lRe = new TH1D(name,name,50,0,1.0);
  h1d_elsubrat_lRe->Sumw2();

  sprintf(name, "el subjet ratio with LMJ & lRe");
  h1d_elsubratM_lRe = new TH1D(name,name,50,0,1.0);
  h1d_elsubratM_lRe->Sumw2();

  sprintf(name, "el subjet ratio with tlepe & lRe");
  h1d_elsubrat_tlepe_lRe = new TH1D(name,name,50,0,1.0);
  h1d_elsubrat_tlepe_lRe->Sumw2();

  sprintf(name, "el subjet ratio with tlepe with LMJ & lRe");
  h1d_elsubratM_tlepe_lRe = new TH1D(name,name,50,0,1.0);
  h1d_elsubratM_tlepe_lRe->Sumw2();

  sprintf(name, "el subjet ratio with b & lRe");
  h1d_elsubrat_b_lRe = new TH1D(name,name,50,0,1.0);
  h1d_elsubrat_b_lRe->Sumw2();

  sprintf(name, "el subjet ratio with b with LMJ & lRe");
  h1d_elsubratM_b_lRe = new TH1D(name,name,50,0,1.0);
  h1d_elsubratM_b_lRe->Sumw2();


  sprintf(name,"electron vs its subjet momentum");
  h2d_el_subjet = new TH2D(name,name,200,0,2000,200,0,2000);
  sprintf(name,"electron vs its subjet momentum with Re > 0.42");
  h2d_el_subjet_gRe = new TH2D(name,name,200,0,2000,200,0,2000);
  sprintf(name,"electron vs its subjet momentum with Re < 0.42");
  h2d_el_subjet_lRe = new TH2D(name,name,200,0,2000,200,0,2000);
  sprintf(name,"electron vs its subjet momentum for highest mass Ljet");
  h2d_el_subjetM = new TH2D(name,name,200,0,2000,200,0,2000);
  sprintf(name,"electron vs its subjet momentum with Re > 0.42 for highest mass Ljet");
  h2d_el_subjetM_gRe = new TH2D(name,name,200,0,2000,200,0,2000);
  sprintf(name,"electron vs its subjet momentum with Re < 0.42 highest mass Ljet");
  h2d_el_subjetM_lRe = new TH2D(name,name,200,0,2000,200,0,2000);

  sprintf(name,"electron vs its subjet eta");
  h2d_el_subjeteta = new TH2D(name,name,100,-5.0,5.0,100,-5.0,5.0);
  sprintf(name,"electron vs its subjet eta with Re > 0.42");
  h2d_el_subjeteta_gRe = new TH2D(name,name,100,-5.0,5.0,100,-5.0,5.0);
  sprintf(name,"electron vs its subjet eta with Re < 0.42");
  h2d_el_subjeteta_lRe = new TH2D(name,name,100,-5.0,5.0,100,-5.0,5.0);
  sprintf(name,"electron vs its subjet eta for highest mass Ljet");
  h2d_el_subjetetaM = new TH2D(name,name,100,-5.0,5.0,100,-5.0,5.0);
  sprintf(name,"electron vs its subjet eta with Re > 0.42 for highest mass Ljet");
  h2d_el_subjetetaM_gRe = new TH2D(name,name,100,-5.0,5.0,100,-5.0,5.0);
  sprintf(name,"electron vs its subjet eta with Re < 0.42 highest mass Ljet");
  h2d_el_subjetetaM_lRe = new TH2D(name,name,100,-5.0,5.0,100,-5.0,5.0);


  sprintf(name,"electron cluster vs its subjet eta");
  h2d_elcl_subjeteta = new TH2D(name,name,100,-5.0,5.0,100,-5.0,5.0);
  sprintf(name,"electron cluster vs its subjet eta with Re > 0.42");
  h2d_elcl_subjeteta_gRe = new TH2D(name,name,100,-5.0,5.0,100,-5.0,5.0);
  sprintf(name,"electron cluster vs its subjet eta with Re < 0.42");
  h2d_elcl_subjeteta_lRe = new TH2D(name,name,100,-5.0,5.0,100,-5.0,5.0);
  sprintf(name,"electron cluster vs its subjet eta for highest mass Ljet");
  h2d_elcl_subjetetaM = new TH2D(name,name,100,-5.0,5.0,100,-5.0,5.0);
  sprintf(name,"electron cluster vs its subjet eta with Re > 0.42 for highest mass Ljet");
  h2d_elcl_subjetetaM_gRe = new TH2D(name,name,100,-5.0,5.0,100,-5.0,5.0);
  sprintf(name,"electron cluster vs its subjet eta with Re < 0.42 highest mass Ljet");
  h2d_elcl_subjetetaM_lRe = new TH2D(name,name,100,-5.0,5.0,100,-5.0,5.0);


  sprintf(name,"electron cluster vs its subjet raw E");
  h2d_elcl_subjete = new TH2D(name,name,200,0,2000,200,0,2000);
  sprintf(name,"electron cluster vs its subjet raw E with Re > 0.42");
  h2d_elcl_subjete_gRe = new TH2D(name,name,200,0,2000,200,0,2000);
  sprintf(name,"electron cluster vs its subjet raw E with Re < 0.42");
  h2d_elcl_subjete_lRe = new TH2D(name,name,200,0,2000,200,0,2000);
  sprintf(name,"electron cluster vs its subjet raw E for highest mass Ljet");
  h2d_elcl_subjeteM = new TH2D(name,name,200,0,2000,200,0,2000);
  sprintf(name,"electron cluster vs its subjet raw E with Re > 0.42 for highest mass Ljet");
  h2d_elcl_subjeteM_gRe = new TH2D(name,name,200,0,2000,200,0,2000);
  sprintf(name,"electron cluster vs its subjet raw E with Re < 0.42 highest mass Ljet");
  h2d_elcl_subjeteM_lRe = new TH2D(name,name,200,0,2000,200,0,2000);



  sprintf(name,"N_PV");
  sprintf(title,"# of Primary Vertices");
  hist_npv = new TH1D(name,title,100,-0.1,99.9);//80,-0.1,79.9);
  hist_npv->Sumw2();
  
  sprintf(name,"N_PU");
  sprintf(title,"# of Pileup Vertices");
  hist_npu = new TH1D(name,title,100,0,100);//80,-0.1,79.9);
  hist_npu->Sumw2();
  
  sprintf(name,"H2D_dR_lb_LepTop");
  sprintf(title,"Top p_{T} vs #Delta R(l,b)");
  h2d_pt_lb = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_lb->Sumw2();
  
  sprintf(name,"H2D_dR_lt_LepTop");
  sprintf(title,"Top p_{T} vs #Delta R(l,t)");
  h2d_pt_lt = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_lt->Sumw2();
  
  sprintf(name,"H2D_dR_lb_HadTop");
  sprintf(title,"Top p_{T} vs #Delta R(d/s,b)");
  h2d_pt_qb = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_qb->Sumw2();
  
  sprintf(name,"H2D_dR_lt_HadTop");
  sprintf(title,"Top p_{T} vs #Delta R(d/s,t)");
  h2d_pt_qt = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_qt->Sumw2();
  
  sprintf(name,"H2D_dRmax_daught_top_LepTop");
  sprintf(title,"Top p_{T} vs Max(#Delta R(d,t))");
  h2d_pt_qt_lep = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_qt_lep->Sumw2();
  
  sprintf(name,"H2D_dRmax_daught_top_HadTop");
  sprintf(title,"Top p_{T} vs Max(#Delta R(d,t))");
  h2d_pt_qt_had = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_qt_had->Sumw2();
  
  sprintf(name,"Pt_LepTop");
  sprintf(title,"P_{T} of leptonic top");
  h_pt_leptop = new TH1D(name,title,noptbins,ptbins);
  h_pt_leptop->Sumw2();
  
  sprintf(name,"Pt_hadTop");
  sprintf(title,"P_{T} of hadronic top");
  h_pt_hadtop = new TH1D(name,title,noptbins,ptbins);
  h_pt_hadtop->Sumw2();
  
  sprintf(name,"Pt_LepTop_matchedtojet");
  sprintf(title,"P_{T} of leptonic top (#Delta R(t,j) < 0.6)");
  h_pt_leptop_matchedJet = new TH1D(name,title,noptbins,ptbins);
  h_pt_leptop_matchedJet->Sumw2();
  
  sprintf(name,"Pt_hadTop_matchedtojet");
  sprintf(title,"P_{T} of hadronic top (#Delta R(t,j) < 0.6)");
  h_pt_hadtop_matchedJet = new TH1D(name,title,noptbins,ptbins);
  h_pt_hadtop_matchedJet->Sumw2();
  
  sprintf(name,"H2D_dRmin_top_jet_LepTop");
  sprintf(title,"Top p_{T} vs Min(#Delta R(t,j))");
  h2d_pt_dR_leptop_Jet = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_dR_leptop_Jet->Sumw2();
  
  sprintf(name,"H2D_dRmin_top_jet_HadTop");
  sprintf(title,"Top p_{T} vs Min(#Delta R(t,j))");
  h2d_pt_dR_hadtop_Jet = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_dR_hadtop_Jet->Sumw2();
  
  sprintf(name,"Counter_event");
  hist_event_count = new TH1D(name,title,2,-0.5,1.5);
  hist_event_count->Sumw2();
  
  sprintf(name,"Counter_event_truthtop");
  hist_event_count_truth = new TH1D(name,title,2,-0.5,1.5);
  hist_event_count_truth->Sumw2();
  
  sprintf(name,"Counter_event_pass_re");
  hist_event_top_pass = new TH1D(name,title,nre+1,-0.5,101.5);
  //hist_event_top_pass = new TH1D(name,title,nre,-1.0,1.0);
  hist_event_top_pass->Sumw2();
  
  reader1 = new TMVA::Reader( "BDTG_Re" );
  reader1->AddVariable( "selpfjetAK8NHadF", &in_pfjetAK8NHadF);
  reader1->AddVariable( "selpfjetAK8neunhadfrac", &in_pfjetAK8neunhadfrac);
  reader1->AddVariable( "selpfjetAK8subhaddiff", &in_pfjetAK8subhaddiff);
  reader1->AddVariable( "selpfjetAK8tau21", &in_pfjetAK8tau21);
  reader1->AddVariable( "selpfjetAK8chrad", &in_pfjetAK8chrad);
  reader1->AddVariable( "selpfjetAK8sdmass", &in_pfjetAK8sdmass);
  reader1->AddVariable( "selpfjetAK8matchedeldxy_sv", &in_pfjetAK8eldxy_sv);
  //reader1->AddVariable( "selpfjetAK8matchedelID", &in_pfjetAK8matchedelID);
  reader1->BookMVA("BDTG method", weightfile1);
  
  reader2 = new TMVA::Reader( "BDTG_Rnu" );
  reader2->AddVariable( "selpfjetAK8_bbyW_E", &in_pfjetAK8_bbyW_E);
  reader2->AddVariable( "selpfjetAK8_Kfactor", &in_pfjetAK8_Kfactor);
  reader2->BookMVA("BDTG method", weightfile2);
  
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
    //if (event_weight != 1) {
      //TString str = TString::Format("event weight %f \n",event_weight);                      
      //if(gProofServ) gProofServ->SendAsynMessage(str);
    //}
    weight = event_weight;
  }else{
    weight = 1;
  }
  Tout->Fill();
  
  int ngenelc = 0;
  int ngenmu = 0;
  int ngenqg = 0;
  int ngenb = 0;
  
  hist_event_count->Fill(1,weight);
  
  TLorentzVector leptop4v[2];
  TLorentzVector leptop4v_daught[3][2];
  TLorentzVector hadtop4v[2];
  TLorentzVector hadtop4v_daught[3][2];
  
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
  
    int top_dp[6];
    int idp = 0;
    int ndq = 0; int ndb = 0; int ndl = 0;
    int top_dqp[4] = {-1,-1,-1,-1};
    int top_dbp[2] = {-1,-1};
    int top_dlp[4] = {-1,-1,-1,-1};
    
    for(int igen=0; igen<ngenparticles; igen++){
      
      if(!(genpartstatus[igen]==23 || genpartstatus[igen]==1)) continue;
      if(!(genpartfromhard[igen])) continue;
      if(!((abs(genpartpdg[igen])>=1 && abs(genpartpdg[igen])<=5)||(abs(genpartpdg[igen])>=11 && abs(genpartpdg[igen])<=14))) continue;
      if(!(abs(genpartmompdg[igen])==6 || abs(genpartmompdg[igen])==24)) continue;
      top_dp[idp] = igen;
      if(abs(genpartpdg[igen])>=1 && abs(genpartpdg[igen])<5 && abs(genpartmompdg[igen])==24) {  top_dqp[ndq] = igen;  ndq++; }
        if(abs(genpartpdg[igen])>=11 && abs(genpartpdg[igen])<=16 && abs(genpartmompdg[igen])==24) {  top_dlp[ndl] = igen;  ndl++; } //when not genmatched use for eff. calculation & not only dealing with electron
      //if((abs(genpartpdg[igen])==11 || abs(genpartpdg[igen])==12) && abs(genpartmompdg[igen])==24) {top_dlp[ndl] = igen;  ndl++; }
      if(abs(genpartpdg[igen])==5 && abs(genpartmompdg[igen])==6) {  top_dbp[ndb] = igen;  ndb++; }
      idp++;
    }
    nleptop = nhadtop = -1;
    
    if(ndq==4 && ndl==0) { nleptop = 0; nhadtop = 2; }
    if(ndq==2 && ndl==2) { nleptop = 1; nhadtop = 1; }
    if(ndq==0 && ndl==4) { nleptop = 2; nhadtop = 0; }
    if(ndq==0 && ndl==2) { nleptop = 1; nhadtop = 0; }
    if(ndq==2 && ndl==0) { nleptop = 0; nhadtop = 1; }
    if(ndq==0 && ndl==0) { nleptop = 0; nhadtop = 0; }
    
    //  TString str = TString::Format("entry %lli nleptop %i nhadtop %i ngentops %i\n",entry,nleptop,nhadtop,ngentops);
    //  if(gProofServ) gProofServ->SendAsynMessage(str);
    
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
	if(((abs(abs(genpartpdg[top_dqp[iq]])-abs(genpartpdg[top_dqp[jq]]))==1)||(abs(abs(genpartpdg[top_dqp[iq]])-abs(genpartpdg[top_dqp[jq]]))==3) ) && (genpartpdg[top_dqp[iq]]*genpartpdg[top_dqp[jq]]<0) && (genpartmompdg[top_dqp[iq]]==genpartmompdg[top_dqp[jq]]))
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
	if(!((abs(genpartpdg[top_dlp[ilep]])==11 /*|| abs(genpartpdg[top_dlp[ilep]])==13*/) && genpartpair[top_dlp[ilep]]>=0)) continue;
	
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
	      h2d_pt_lb->Fill(leptop4v[ileptop].Pt(),delta2R(b4.Rapidity(),b4.Phi(),q1.Rapidity(),q1.Phi()), weight);
	      h2d_pt_lt->Fill(leptop4v[ileptop].Pt(),delta2R(leptop4v[ileptop].Rapidity(),leptop4v[ileptop].Phi(),q1.Rapidity(),q1.Phi()),weight);
	      
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
	     h2d_pt_qb->Fill(hadtop4v[ihadtop].Pt(),delta2R(b4.Rapidity(),b4.Phi(),q1.Rapidity(),q1.Phi()), weight);
	     h2d_pt_qt->Fill(hadtop4v[ihadtop].Pt(),delta2R(hadtop4v[ihadtop].Rapidity(),hadtop4v[ihadtop].Phi(),q1.Rapidity(),q1.Phi()), weight);
	     
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
  
  DiLeptt = SemiLeptt = Hadtt = false;

  if(nleptop==2 && nhadtop==0) { DiLeptt = true; }
  if(nleptop==1 && nhadtop==1) { SemiLeptt = true; }
  if(nleptop==0 && nhadtop==2) { Hadtt = true; }
  
  if(nleptop>=1) { hist_event_count_truth->Fill(1,weight); }

  for(int ilep=0; ilep<nleptop; ilep++){
    h_pt_leptop->Fill(leptop4v[ilep].Pt(),weight);
    

    for(int ijet=0; ijet< npfjetAK8; ijet++){	
      if(delta2R(leptop4v[ilep].Rapidity(),leptop4v[ilep].Phi(),pfjetAK8y[ijet],pfjetAK8phi[ijet])<0.6){
	h_pt_leptop_matchedJet->Fill(leptop4v[ilep].Pt(),weight);
	break;
      }
    }
    
    double dRmin = 100;
    for(int ijet=0; ijet< npfjetAK8; ijet++){	
      if(delta2R(leptop4v[ilep].Rapidity(),leptop4v[ilep].Phi(),pfjetAK8y[ijet],pfjetAK8phi[ijet])<dRmin){
	dRmin = delta2R(leptop4v[ilep].Rapidity(),leptop4v[ilep].Phi(),pfjetAK8y[ijet],pfjetAK8phi[ijet]);
      }
    }
    h2d_pt_dR_leptop_Jet->Fill(leptop4v[ilep].Pt(),dRmin,weight);
    
    float dRmax = std::max({delta2R(leptop4v_daught[0][ilep].Rapidity(),leptop4v_daught[0][ilep].Phi(),leptop4v[ilep].Rapidity(),leptop4v[ilep].Phi()),
	  delta2R(leptop4v_daught[1][ilep].Rapidity(),leptop4v_daught[1][ilep].Phi(),leptop4v[ilep].Rapidity(),leptop4v[ilep].Phi()),
	  delta2R(leptop4v_daught[2][ilep].Rapidity(),leptop4v_daught[2][ilep].Phi(),leptop4v[ilep].Rapidity(),leptop4v[ilep].Phi())});
    
    h2d_pt_qt_lep->Fill(leptop4v[ilep].Pt(),dRmax, weight);
  }
  
  for(int ihad=0; ihad<nhadtop; ihad++){
	
    h_pt_hadtop->Fill(hadtop4v[ihad].Pt(),weight);
    
    for(int ijet=0; ijet< npfjetAK8; ijet++){	
      if(delta2R(hadtop4v[ihad].Rapidity(),hadtop4v[ihad].Phi(),pfjetAK8y[ijet],pfjetAK8phi[ijet])<0.6){
	h_pt_hadtop_matchedJet->Fill(hadtop4v[ihad].Pt(),weight);
	break;
      }
    }
  
    double dRmin = 100;
    for(int ijet=0; ijet< npfjetAK8; ijet++){	
      if(delta2R(hadtop4v[ihad].Rapidity(),hadtop4v[ihad].Phi(),pfjetAK8y[ijet],pfjetAK8phi[ijet])<dRmin){
	dRmin = delta2R(hadtop4v[ihad].Rapidity(),hadtop4v[ihad].Phi(),pfjetAK8y[ijet],pfjetAK8phi[ijet]);
      }
    }
    h2d_pt_dR_hadtop_Jet->Fill(hadtop4v[ihad].Pt(),dRmin,weight);
    
    float dRmax = std::max({delta2R(hadtop4v_daught[0][ihad].Rapidity(),hadtop4v_daught[0][ihad].Phi(),hadtop4v[ihad].Rapidity(),hadtop4v[ihad].Phi()),
	  delta2R(hadtop4v_daught[1][ihad].Rapidity(),hadtop4v_daught[1][ihad].Phi(),hadtop4v[ihad].Rapidity(),hadtop4v[ihad].Phi()),
	  delta2R(hadtop4v_daught[2][ihad].Rapidity(),hadtop4v_daught[2][ihad].Phi(),hadtop4v[ihad].Rapidity(),hadtop4v[ihad].Phi())});
    
    h2d_pt_qt_had->Fill(hadtop4v[ihad].Pt(),dRmax, weight);
  }
  
  int fjet = 0;
  
  //if (npfjetAK8 > 0) {
  for(int ijet=0; ijet<npfjetAK8; ijet++){
    
    if(!pfjetAK8looseID[ijet]) continue;
    
    if(fabs(pfjetAK8y[ijet])>2.5) continue;
    
    pfjetAK8pt[ijet] *= pfjetAK8JEC[ijet] ;
    pfjetAK8mass[ijet] *= pfjetAK8JEC[ijet];
    if(isMC){
      pfjetAK8pt[ijet] *= (1+pfjetAK8reso[ijet]) ;
      pfjetAK8mass[ijet] *= (1+pfjetAK8reso[ijet]) ;
      pfjetAK8sdmass[ijet] *= (1+pfjetAK8reso[ijet]) ;
    }
    
    if(pfjetAK8pt[ijet] < ptcut) continue;
    
    if (pfjetAK8elinsubpt[ijet] < 0 && pfjetAK8elinsubjpt[ijet]< 0) continue;
                                                                                                                                        
    if (fabs(pfjetAK8elinsubpt[ijet] > 25.0)) {
      pfjetAK8elsubjptrat[ijet] = fabs(pfjetAK8elinsubpt[ijet])/fabs(pfjetAK8elinsubjpt[ijet]);
    }
    else pfjetAK8elsubjptrat[ijet] = -100;
    
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
    pfjetAK8ncons[fjet] = pfjetAK8Chcons[ijet]+pfjetAK8Chcons[ijet];
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
    
    pfjetAK8haselectron[fjet] = pfjetAK8hasmuon[fjet] = pfjetAK8hasqg[fjet] = pfjetAK8hasb[fjet] = pfjetAK8hasleptop[fjet] = pfjetAK8hashadtop[fjet] = pfjetAK8hastop[fjet] = false;
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
	//		  if(!pfjetAK8hasleptop[fjet]) continue;
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
	//		  if(!pfjetAK8hashadtop[fjet]) continue;
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
      
    }//isMC
  
    float minR = 0.4;
    int pfjetAK8mactAK4_i = -1;
    
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
    
    fjet++;
    if(fjet>=njetmxAK8) break;
  }
  //} if (npfjetAK8 > 0) {
  
  //int npfjetAK8_v = fjet;
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
  
  hist_npv->Fill(nchict,weight);
  if(isMC){
    hist_npu->Fill(npu_vert,weight);
  }

  int tr_count(0);
  //if (npfjetAK8 > 0) {
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
    if(isnan(pfjetAK8elinsubjpt[ijet])) { pfjetAK8elinsubjpt[ijet] = -100; }
    if(isnan(pfjetAK8elinsubjeta[ijet])) { pfjetAK8elinsubjeta[ijet] = -100; }
    if(isnan(pfjetAK8elinsubjphi[ijet])) { pfjetAK8elinsubjphi[ijet] = -100; }
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
    if(isnan(pfjetAK8hashadtop_alldecay[ijet])) { pfjetAK8hashadtop_alldecay[ijet] = -100; }
    if(isnan(pfjetAK8hasleptop_alldecay[ijet])) { pfjetAK8hasleptop_alldecay[ijet] = -100; }
    if(isnan(pfjetAK8_bbyW_E[ijet])) { pfjetAK8_bbyW_E[ijet] = -100; }
    if(isnan(pfjetAK8_Kfactor[ijet])) { pfjetAK8_Kfactor[ijet] = -100; }
    if(isnan(pfjetAK8_Rnew[ijet])) { pfjetAK8_Rnew[ijet] = -100; }
    if(isnan(pfjetAK8_leppt[ijet])) { pfjetAK8_leppt[ijet] = -100; }
    if(isnan(pfjetAK8_bpt[ijet])) { pfjetAK8_bpt[ijet] = -100; }
    if(isnan(pfjetAK8_nupt[ijet])) { pfjetAK8_nupt[ijet] = -100; }
  
    Float_t Re(-100);
    
    in_pfjetAK8NHadF = pfjetAK8NHadF[ijet];
    in_pfjetAK8neunhadfrac = pfjetAK8neunhadfrac[ijet];
    in_pfjetAK8subhaddiff = pfjetAK8subhaddiff[ijet];
    in_pfjetAK8tau21 = pfjetAK8tau21[ijet];
    in_pfjetAK8chrad = pfjetAK8chrad[ijet];
    in_pfjetAK8sdmass = pfjetAK8sdmass[ijet];
    in_pfjetAK8eldxy_sv = -100;
    
    bool Isolpass = false;
    if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
      {
        if (npfjetAK4 > 0) {
          float minR = 1000;
          int nearjet = -1;
          double Electron_pt_nearjet(0);
          for (int kjet=0; kjet<npfjetAK4; kjet++) {
            if(delta2R(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet],pfjetAK4eta[kjet],pfjetAK4phi[kjet])<minR) {
              minR = delta2R(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet],pfjetAK4eta[kjet],pfjetAK4phi[kjet]);
              nearjet = kjet;
            }
          }
          if (nearjet>=0){
            TLorentzVector j_mom; j_mom.SetPtEtaPhiM(pfjetAK4pt[nearjet],pfjetAK4eta[nearjet],pfjetAK4phi[nearjet],pfjetAK4mass[nearjet]);

            TLorentzVector nearel; nearel.SetPtEtaPhiE(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet],pfjetAK8elinsube[ijet]);
            Electron_pt_nearjet = ((nearel.Vect()).Perp(j_mom.Vect()));
          }
          if (minR > 0.4 ||  Electron_pt_nearjet > 15.) Isolpass = true;
        }
      }

    if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
      {
	if (nelecs > 0) {
	  float dR_min(0.4); int nearest(-1);
	  for(int el=0; el<nelecs; el++){
	    float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
	    if (dR < dR_min) {
	      dR_min = dR;
	      nearest = el;
	    }}
	  if (nearest >= 0) {
	    in_pfjetAK8eldxy_sv = eldxy_sv[nearest];
	    //in_pfjetAK8matchedelID = elmvaid_noIso[nearest];
	  }}}

    pfjetAK8re_tvsb[ijet] = -100;
    Re = reader1->EvaluateMVA("BDTG method");
    pfjetAK8re_tvsb[ijet] = Re;
    
    //TString str1 = TString::Format("Re %f \n",pfjetAK8re_tvsb[ijet]);
    //if(gProofServ) gProofServ->SendAsynMessage(str1);
  

    in_pfjetAK8_bbyW_E = pfjetAK8_bbyW_E[ijet];
    in_pfjetAK8_Kfactor = pfjetAK8_Kfactor[ijet];
    
    Float_t Rnu(-100);
    
    Rnu = reader2->EvaluateMVA("BDTG method");
    pfjetAK8rnu_tvsb[ijet] = Rnu;
  
    if (ijet == 0 && pfjetAK8pt[ijet] > 400) {
      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100) h1d_elpt_subjet->Fill(pfjetAK8elinsubpt[ijet],weight);
      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100 && pfjetAK8elinsubpt[ijet] > 25) {
	
	h1d_elsubrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);
	if (Re > 0.42) h1d_elsubrat_gRe->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);
	if (Re < 0.42) h1d_elsubrat_lRe->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);

	h2d_el_subjet->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
	if (Re > 0.42) h2d_el_subjet_gRe->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
	if (Re < 0.42) h2d_el_subjet_lRe->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
	
	h2d_el_subjeteta->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);
	if (Re > 0.42) h2d_el_subjeteta_gRe->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);
        if (Re < 0.42) h2d_el_subjeteta_lRe->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);

	if (nelecs > 0) {
	  float dR_min(0.4); int nearest(-1);
	  
	  for(int el=0; el<nelecs; el++){
	    float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
	    
	    if (dR < dR_min) {
	      dR_min = dR;
	      nearest = el;
	    }}

	  if (nearest >= 0) {
            hist_62Dnew[0]->Fill(eldxy[nearest],pfjetAK8elinsubpt[ijet],weight);
            hist_62Dnew[1]->Fill(eldxy_sv[nearest],pfjetAK8elinsubpt[ijet],weight);
            hist_62Dnew[2]->Fill(eldxy[nearest],eldxy_sv[nearest],weight);
            hist_62Dnew[3]->Fill(eldxy[nearest],elmvaid_noIso[nearest],weight);
            hist_62Dnew[4]->Fill(eldxy_sv[nearest],elmvaid_noIso[nearest],weight);
            hist_62Dnew[5]->Fill(eldxy_sv[nearest],elsupcl_eta[nearest],weight);
            hist_62Dnew[6]->Fill(eldxy_sv[nearest],elsupcl_rawE[nearest],weight);
            hist_62Dnew[7]->Fill(eldxy_sv[nearest],ele[nearest],weight);
          }
	
	  if (nearest >= 0) {
	    h1d_eldxy_subjet->Fill(eldxy_sv[nearest],weight);
	    if (Re > 0.42) h1d_eldxy_subjet_gRe->Fill(eldxy_sv[nearest],weight);
	    if (Re < 0.42) h1d_eldxy_subjet_lRe->Fill(eldxy_sv[nearest],weight);
	  }
	  if (nearest >= 0) h2d_elcl_subjeteta->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);
	  if (nearest >= 0 && Re > 0.42) h2d_elcl_subjeteta_gRe->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);
	  if (nearest >= 0 && Re < 0.42) h2d_elcl_subjeteta_lRe->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);

	  if (nearest >= 0) h2d_elcl_subjete->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
          if (nearest >= 0 && Re > 0.42) h2d_elcl_subjete_gRe->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
          if (nearest >= 0 && Re < 0.42) h2d_elcl_subjete_lRe->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
	}
	
      }}
  
    if (ijet == maxM && pfjetAK8pt[ijet] > 400) {
      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)h1d_elpt_subjetM->Fill(pfjetAK8elinsubpt[ijet],weight);
      
      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100 && pfjetAK8elinsubpt[ijet] > 25) {
	
	h1d_elsubratM->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);
	
	if (Re > 0.42) h1d_elsubratM_gRe->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);
	if (Re < 0.42) h1d_elsubratM_lRe->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);

	h2d_el_subjetM->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
	if (Re > 0.42) h2d_el_subjetM_gRe->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
	if (Re < 0.42) h2d_el_subjetM_lRe->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
	
	h2d_el_subjetetaM->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);
	if (Re > 0.42) h2d_el_subjetetaM_gRe->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);
	if (Re < 0.42) h2d_el_subjetetaM_lRe->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);

	if (nelecs > 0) {
          float dR_min(0.4); int nearest(-1);
          for(int el=0; el<nelecs; el++){
            float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
            if (dR < dR_min) {
              dR_min = dR;
              nearest = el;
            }}
        
	
	  if (nearest >= 0) {
	    h1d_eldxy_subjetM->Fill(eldxy_sv[nearest],weight);
            if (Re > 0.42) h1d_eldxy_subjetM_gRe->Fill(eldxy_sv[nearest],weight);
            if (Re < 0.42) h1d_eldxy_subjetM_lRe->Fill(eldxy_sv[nearest],weight);
	  }

	  if (nearest >= 0) h2d_elcl_subjetetaM->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);
          if (nearest >= 0 && Re > 0.42) h2d_elcl_subjetetaM_gRe->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);
          if (nearest >= 0 && Re < 0.42) h2d_elcl_subjetetaM_lRe->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);
	  
	  if (nearest >= 0) h2d_elcl_subjeteM->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
	  if (nearest >= 0 && Re > 0.42) h2d_elcl_subjeteM_gRe->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
	  if (nearest >= 0 && Re < 0.42) h2d_elcl_subjeteM_lRe->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
	}
	
      }}
    bool te_cond = false;
    bool tmu_cond = false;
    bool thad_cond = false;
    bool qg_cond = false;
    bool b_cond = false;
    
    te_cond  = (pfjetAK8haselectron[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]);
    tmu_cond = (pfjetAK8hasmuon[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]);
    thad_cond = (pfjetAK8hashadtop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hashadtop_alldecay[ijet]);
    qg_cond = (pfjetAK8hasqg[ijet] && !(pfjetAK8hashadtop[ijet]) && !(pfjetAK8hasleptop[ijet]) && !(pfjetAK8hastop[ijet]));
    b_cond = (pfjetAK8hasb[ijet] && !(pfjetAK8hashadtop[ijet]) && !(pfjetAK8hasleptop[ijet]) && !(pfjetAK8hastop[ijet]));
  
    if(te_cond){
      if (ijet >= 0) h_te_count->Fill(1,weight);
      
      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
	{
	  if (pfjetAK8pt[ijet] > 400.0) {
            hvsb_re->Fill(Re,weight);
            helinpt->Fill(pfjetAK8elinsubpt[ijet],weight);
            helsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
            if (Re > 0.42) {
              hreelinpt->Fill(pfjetAK8elinsubpt[ijet],weight);
              hreelsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
            }}
	  
	  if (nelecs > 0) {
	    float dR_min(0.4); int nearest(-1);
	    for(int el=0; el<nelecs; el++){
	      float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
	      if (dR < dR_min) {
		dR_min = dR;
		nearest = el;
	      }}
	    if (nearest >= 0 && pfjetAK8pt[ijet] > 400.0) {
	      //if (ijet == 0) {
	      if (Isolpass == 0) helinidiso->Fill(0.5,weight);
              if (Isolpass == 1) helinidiso->Fill(1.5,weight);
              if (Isolpass == 0 && elmvaid_noIso[nearest] == 1) helinidiso->Fill(2.5,weight);
              if (Isolpass == 1 && elmvaid_noIso[nearest] == 1) helinidiso->Fill(3.5,weight);
	      
	      //helinpt->Fill(pfjetAK8elinsubpt[ijet],weight);
	      helinid->Fill(elmvaid_noIso[nearest],weight);
	      h->Fill(elsupcl_rawE[nearest],weight);
	      h_Re->Fill(Re,weight);
	      heldxy->Fill(eldxy[nearest],weight);
	      heldxy_sv->Fill(eldxy_sv[nearest],weight);
	      //helsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
	      helcleta->Fill(elsupcl_eta[nearest],weight);
	      h2d_eldxy_sv_elIDv->Fill(eldxy_sv[nearest],elmvaid_noIso[nearest],weight);

	      if (Re > 0.96) {
		if (Isolpass == 0) hreelinidiso_str->Fill(0.5,weight);
                if (Isolpass == 1) hreelinidiso_str->Fill(1.5,weight);
                if (Isolpass == 0 && elmvaid_noIso[nearest] == 1) hreelinidiso_str->Fill(2.5,weight);
                if (Isolpass == 1 && elmvaid_noIso[nearest] == 1) hreelinidiso_str->Fill(3.5,weight);
	      }
	      if (Re > 0.42) {
		//hreelinpt->Fill(pfjetAK8elinsubpt[ijet],weight);
		if (Isolpass == 0) hreelinidiso->Fill(0.5,weight);
                if (Isolpass == 1) hreelinidiso->Fill(1.5,weight);
                if (Isolpass == 0 && elmvaid_noIso[nearest] == 1) hreelinidiso->Fill(2.5,weight);
                if (Isolpass == 1 && elmvaid_noIso[nearest] == 1) hreelinidiso->Fill(3.5,weight);
		hreelinid->Fill(elmvaid_noIso[nearest],weight);
		float ptrat = pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet];
		hre->Fill(elsupcl_rawE[nearest],weight);
		h_reRe->Fill(Re,weight);
		hreeldxy->Fill(eldxy[nearest],weight);
		hreeldxy_sv->Fill(eldxy_sv[nearest],weight);
		//hreelsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
		hreelcleta->Fill(elsupcl_eta[nearest],weight);
		h2d_reeldxy_sv_elIDv->Fill(eldxy_sv[nearest],elmvaid_noIso[nearest],weight);
	      }
	      //}
	    }
	  }
	}
      /*
      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
        {
          if (nelecs > 0) {
            float dR_min(0.4); int nearest(-1);
            for(int el=0; el<nelecs; el++){
              float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
              if (dR < dR_min) {
                dR_min = dR;
                nearest = el;
              }}
            if (ijet == 0 && nearest >= 0 && pfjetAK8pt[ijet] > 400){
              h_NoID_elptIn->Fill(pfjetAK8elinsubpt[ijet],weight);
              if (Re > 0.42) {
                h_NoID_reelptIn->Fill(pfjetAK8elinsubpt[ijet],weight);
              }}

            if (ijet == 0 && nearest >= 0 && pfjetAK8elinsubpt[ijet] > 25 && pfjetAK8pt[ijet] > 400){
              h_NoID_->Fill(elsupcl_rawE[nearest],weight);
              h_NoID_eldxy->Fill(eldxy[nearest],weight);
              h_NoID_eldxy_sv->Fill(eldxy_sv[nearest],weight);
              h_NoID_elsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
              h_NoID_elcleta->Fill(elsupcl_eta[nearest],weight);

              if (Re > 0.42) {
                float ptrat = pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet];
                h_NoID_re->Fill(elsupcl_rawE[nearest],weight);
                h_NoID_reeldxy->Fill(eldxy[nearest],weight);
                h_NoID_reeldxy_sv->Fill(eldxy_sv[nearest],weight);
                h_NoID_reelsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
                h_NoID_reelcleta->Fill(elsupcl_eta[nearest],weight);
              }}
            if (ijet == 0 && nearest >= 0 && pfjetAK8pt[ijet] > 400 && elmvaid_noIso[nearest] == 1){
              h_Noelpt_->Fill(elsupcl_rawE[nearest],weight);
              h_Noelpt_eldxy->Fill(eldxy[nearest],weight);
              h_Noelpt_eldxy_sv->Fill(eldxy_sv[nearest],weight);
              h_Noelpt_elsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
              h_Noelpt_elcleta->Fill(elsupcl_eta[nearest],weight);
              h_Noelpt_elptIn->Fill(pfjetAK8elinsubpt[ijet],weight);

              if (Re > 0.42) {
                float ptrat = pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet];
                h_Noelpt_re->Fill(elsupcl_rawE[nearest],weight);
                h_Noelpt_reeldxy->Fill(eldxy[nearest],weight);
                h_Noelpt_reeldxy_sv->Fill(eldxy_sv[nearest],weight);
                h_Noelpt_reelsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
                h_Noelpt_reelcleta->Fill(elsupcl_eta[nearest],weight);
                h_Noelpt_reelptIn->Fill(pfjetAK8elinsubpt[ijet],weight);
              }}*/
            /*
	      if (ijet == 0 && nearest >= 0 && pfjetAK8elinsubpt[ijet] > 25 && pfjetAK8pt[ijet] > 400 && elmvaid_noIso[nearest] == 1) {
              h->Fill(elsupcl_rawE[nearest],weight);
	      h_Re->Fill(Re,weight);
              heldxy->Fill(eldxy[nearest],weight);
              heldxy_sv->Fill(eldxy_sv[nearest],weight);
              helsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
              helcleta->Fill(elsupcl_eta[nearest],weight);

              if (Re > 0.42) {
                float ptrat = pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet];
                hre->Fill(elsupcl_rawE[nearest],weight);
		h_reRe->Fill(Re,weight);
                hreeldxy->Fill(eldxy[nearest],weight);
                hreeldxy_sv->Fill(eldxy_sv[nearest],weight);
                hreelsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
                hreelcleta->Fill(elsupcl_eta[nearest],weight);
		}
	      }
	    */
      // }
      //	}

      if (ijet == 0 && pfjetAK8pt[ijet] > 400) {

	if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)h1d_elpt_subjet_tlepe->Fill(pfjetAK8elinsubpt[ijet],weight);
	if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100 && pfjetAK8elinsubpt[ijet] > 25) {
	  h1d_elsubrat_tlepe->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);
	  if (Re > 0.42) h1d_elsubrat_tlepe_gRe->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);
	  if (Re < 0.42) h1d_elsubrat_tlepe_lRe->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);



	  h1d_elpt_subjet_tlepe->Fill(pfjetAK8elinsubpt[ijet],weight);
	  hist_12D[0]->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
	  if (Re > 0.42) hist_12D[1]->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
	  if (Re < 0.42) hist_12D[2]->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);

	  hist_12D[3]->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);
	  if (Re > 0.42) hist_12D[4]->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);
	  if (Re < 0.42) hist_12D[5]->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);

	  if (nelecs > 0) {
	    float dR_min(0.4); int nearest(-1);
	    for(int el=0; el<nelecs; el++){
	      float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
	      if (dR < dR_min) {
		dR_min = dR;
		nearest = el;
	      }}
	    
	    if (nearest >= 0) {
	      hist_12Dnew[0]->Fill(eldxy[nearest],pfjetAK8elinsubpt[ijet],weight);
	      hist_12Dnew[1]->Fill(eldxy_sv[nearest],pfjetAK8elinsubpt[ijet],weight);
	      hist_12Dnew[2]->Fill(eldxy[nearest],eldxy_sv[nearest],weight);
	      hist_12Dnew[3]->Fill(eldxy[nearest],elmvaid_noIso[nearest],weight);
	      hist_12Dnew[4]->Fill(eldxy_sv[nearest],elmvaid_noIso[nearest],weight);
	      hist_12Dnew[5]->Fill(eldxy_sv[nearest],elsupcl_eta[nearest],weight);
	      hist_12Dnew[6]->Fill(eldxy_sv[nearest],elsupcl_rawE[nearest],weight);
	      hist_12Dnew[7]->Fill(eldxy_sv[nearest],ele[nearest],weight);
	    }

	    if (nearest >= 0) {
	      h1d_eldxy_subjet_tlepe->Fill(eldxy_sv[nearest],weight);
	      if (Re > 0.42) h1d_eldxy_subjet_tlepe_gRe->Fill(eldxy_sv[nearest],weight);
	      if (Re < 0.42) h1d_eldxy_subjet_tlepe_lRe->Fill(eldxy_sv[nearest],weight);
	    }

	    if (nearest >= 0) hist_12D[6]->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);
	    if (nearest >= 0 && Re > 0.42) hist_12D[7]->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);
	    if (nearest >= 0 && Re < 0.42) hist_12D[8]->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);

	    if (nearest >= 0) hist_12D[9]->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
	    if (nearest >= 0 && Re > 0.42) hist_12D[10]->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
	    if (nearest >= 0 && Re < 0.42) hist_12D[11]->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
	  }

	}}

      if (ijet == maxM && pfjetAK8pt[ijet] > 400) {
	if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)h1d_elpt_subjetM_tlepe->Fill(pfjetAK8elinsubpt[ijet],weight);
	if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100 && pfjetAK8elinsubpt[ijet] > 25) {
	  h1d_elsubratM_tlepe->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);
	  if (Re > 0.42) h1d_elsubratM_tlepe_gRe->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);
          if (Re < 0.42) h1d_elsubratM_tlepe_lRe->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);


	  hist_12D[12]->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
	  if (Re > 0.42) hist_12D[13]->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
	  if (Re < 0.42) hist_12D[14]->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);

	  hist_12D[15]->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);
	  if (Re > 0.42) hist_12D[16]->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);
	  if (Re < 0.42) hist_12D[17]->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);
	  if (nelecs > 0) {
	    float dR_min(0.4); int nearest(-1);
	    for(int el=0; el<nelecs; el++){
	      float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
	      if (dR < dR_min) {
		dR_min = dR;
		nearest = el;
	      }}

	    if (nearest >= 0) {
              h1d_eldxy_subjetM_tlepe->Fill(eldxy_sv[nearest],weight);
              if (Re > 0.42) h1d_eldxy_subjetM_tlepe_gRe->Fill(eldxy_sv[nearest],weight);
              if (Re < 0.42) h1d_eldxy_subjetM_tlepe_lRe->Fill(eldxy_sv[nearest],weight);
            }

	    if (nearest >= 0) hist_12D[18]->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);
	    if (nearest >= 0 && Re > 0.42) hist_12D[19]->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);
	    if (nearest >= 0 && Re < 0.42) hist_12D[20]->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);

	    if (nearest >= 0) hist_12D[21]->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
	    if (nearest >= 0 && Re > 0.42) hist_12D[22]->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
	    if (nearest >= 0 && Re < 0.42) hist_12D[23]->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
	  }

	  }}
    
      hist_1[0]->Fill(pfjetAK8pt[ijet],weight);
      hist_1[1]->Fill(pfjetAK8y[ijet],weight);
      hist_1[2]->Fill(pfjetAK8phi[ijet],weight);
      hist_1[3]->Fill(pfjetAK8mass[ijet],weight);
      hist_1[4]->Fill(pfjetAK8btag_CMVA[ijet],weight);
      hist_1[5]->Fill(pfjetAK8btag_CSV[ijet],weight);
      hist_1[6]->Fill(pfjetAK8btag_DeepCSV[ijet],weight);
      hist_1[7]->Fill(pfjetAK8matchAK4deepb[ijet],weight);
      hist_1[8]->Fill(pfjetAK8DeepTag_TvsQCD[ijet],weight);
      hist_1[9]->Fill(pfjetAK8DeepTag_WvsQCD[ijet],weight);
      hist_1[10]->Fill(pfjetAK8DeepTag_ZvsQCD[ijet],weight);
      hist_1[11]->Fill(pfjetAK8CHF[ijet],weight);
      hist_1[12]->Fill(pfjetAK8NHF[ijet],weight);
      hist_1[13]->Fill(pfjetAK8CEMF[ijet],weight);
      hist_1[14]->Fill(pfjetAK8NEMF[ijet],weight);
      hist_1[15]->Fill(pfjetAK8MUF[ijet],weight);
      hist_1[16]->Fill(pfjetAK8HOF[ijet],weight);
      hist_1[17]->Fill(pfjetAK8HadF[ijet],weight);
      hist_1[18]->Fill(pfjetAK8NHadF[ijet],weight);
      hist_1[19]->Fill(pfjetAK8EmF[ijet],weight);
      hist_1[20]->Fill(pfjetAK8neuemfrac[ijet],weight);
      hist_1[21]->Fill(pfjetAK8neunhadfrac[ijet],weight);
      hist_1[22]->Fill(pfjetAK8chrad[ijet],weight);
      hist_1[23]->Fill(pfjetAK8pTD[ijet],weight);
      hist_1[24]->Fill(pfjetAK8sdmass[ijet],weight);
      hist_1[25]->Fill(pfjetAK8tau21[ijet],weight);
      hist_1[26]->Fill(pfjetAK8tau32[ijet],weight);
      hist_1[27]->Fill(pfjetAK8sub1mass[ijet],weight);
      hist_1[28]->Fill(pfjetAK8sub1btag[ijet],weight);
      hist_1[29]->Fill(pfjetAK8sub1hadfrac[ijet],weight);
      hist_1[30]->Fill(pfjetAK8sub1emfrac[ijet],weight);
      hist_1[31]->Fill(pfjetAK8sub2mass[ijet],weight);
      hist_1[32]->Fill(pfjetAK8sub2btag[ijet],weight);
      hist_1[33]->Fill(pfjetAK8sub2hadfrac[ijet],weight);
      hist_1[34]->Fill(pfjetAK8sub2emfrac[ijet],weight);
      hist_1[35]->Fill(pfjetAK8subhaddiff[ijet],weight);
      hist_1[36]->Fill(pfjetAK8subemdiff[ijet],weight);
      hist_1[37]->Fill(pfjetAK8subptdiff[ijet],weight);
      hist_1[38]->Fill(pfjetAK8subbtag[ijet],weight);
      hist_1[39]->Fill(pfjetAK8_leppt[ijet],weight);
      hist_1[40]->Fill(pfjetAK8_bpt[ijet],weight);
      hist_1[41]->Fill(pfjetAK8_nupt[ijet],weight);
      hist_1[42]->Fill(pfjetAK8_Rnew[ijet],weight);
      hist_1[43]->Fill(pfjetAK8_bbyW_E[ijet],weight);
      hist_1[44]->Fill(pfjetAK8_Kfactor[ijet],weight);
      hist_1[45]->Fill(pfjetAK8re_tvsb[ijet],weight);
      hist_1[46]->Fill(pfjetAK8rnu_tvsb[ijet],weight);
      h2d_re_rnu_1->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
    }
    
    if(tmu_cond){
      
      hist_2[0]->Fill(pfjetAK8pt[ijet],weight);
      hist_2[1]->Fill(pfjetAK8y[ijet],weight);
      hist_2[2]->Fill(pfjetAK8phi[ijet],weight);
      hist_2[3]->Fill(pfjetAK8mass[ijet],weight);
      hist_2[4]->Fill(pfjetAK8btag_CMVA[ijet],weight);
      hist_2[5]->Fill(pfjetAK8btag_CSV[ijet],weight);
      hist_2[6]->Fill(pfjetAK8btag_DeepCSV[ijet],weight);
      hist_2[7]->Fill(pfjetAK8matchAK4deepb[ijet],weight);
      hist_2[8]->Fill(pfjetAK8DeepTag_TvsQCD[ijet],weight);
      hist_2[9]->Fill(pfjetAK8DeepTag_WvsQCD[ijet],weight);
      hist_2[10]->Fill(pfjetAK8DeepTag_ZvsQCD[ijet],weight);
      hist_2[11]->Fill(pfjetAK8CHF[ijet],weight);
      hist_2[12]->Fill(pfjetAK8NHF[ijet],weight);
      hist_2[13]->Fill(pfjetAK8CEMF[ijet],weight);
      hist_2[14]->Fill(pfjetAK8NEMF[ijet],weight);
      hist_2[15]->Fill(pfjetAK8MUF[ijet],weight);
      hist_2[16]->Fill(pfjetAK8HOF[ijet],weight);
      hist_2[17]->Fill(pfjetAK8HadF[ijet],weight);
      hist_2[18]->Fill(pfjetAK8NHadF[ijet],weight);
      hist_2[19]->Fill(pfjetAK8EmF[ijet],weight);
      hist_2[20]->Fill(pfjetAK8neuemfrac[ijet],weight);
      hist_2[21]->Fill(pfjetAK8neunhadfrac[ijet],weight);
      hist_2[22]->Fill(pfjetAK8chrad[ijet],weight);
      hist_2[23]->Fill(pfjetAK8pTD[ijet],weight);
      hist_2[24]->Fill(pfjetAK8sdmass[ijet],weight);
      hist_2[25]->Fill(pfjetAK8tau21[ijet],weight);
      hist_2[26]->Fill(pfjetAK8tau32[ijet],weight);
      hist_2[27]->Fill(pfjetAK8sub1mass[ijet],weight);
      hist_2[28]->Fill(pfjetAK8sub1btag[ijet],weight);
      hist_2[29]->Fill(pfjetAK8sub1hadfrac[ijet],weight);
      hist_2[30]->Fill(pfjetAK8sub1emfrac[ijet],weight);
      hist_2[31]->Fill(pfjetAK8sub2mass[ijet],weight);
      hist_2[32]->Fill(pfjetAK8sub2btag[ijet],weight);
      hist_2[33]->Fill(pfjetAK8sub2hadfrac[ijet],weight);
      hist_2[34]->Fill(pfjetAK8sub2emfrac[ijet],weight);
      hist_2[35]->Fill(pfjetAK8subhaddiff[ijet],weight);
      hist_2[36]->Fill(pfjetAK8subemdiff[ijet],weight);
      hist_2[37]->Fill(pfjetAK8subptdiff[ijet],weight);
      hist_2[38]->Fill(pfjetAK8subbtag[ijet],weight);
      hist_2[39]->Fill(pfjetAK8_leppt[ijet],weight);
      hist_2[40]->Fill(pfjetAK8_bpt[ijet],weight);
      hist_2[41]->Fill(pfjetAK8_nupt[ijet],weight);
      hist_2[42]->Fill(pfjetAK8_Rnew[ijet],weight);
      hist_2[43]->Fill(pfjetAK8_bbyW_E[ijet],weight);
      hist_2[44]->Fill(pfjetAK8_Kfactor[ijet],weight);
      hist_2[45]->Fill(pfjetAK8re_tvsb[ijet],weight);
      hist_2[46]->Fill(pfjetAK8rnu_tvsb[ijet],weight);
      
      h2d_re_rnu_2->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
      }
    
    if(thad_cond){
      
      hist_3[0]->Fill(pfjetAK8pt[ijet],weight);
      hist_3[1]->Fill(pfjetAK8y[ijet],weight);
      hist_3[2]->Fill(pfjetAK8phi[ijet],weight);
      hist_3[3]->Fill(pfjetAK8mass[ijet],weight);
      hist_3[4]->Fill(pfjetAK8btag_CMVA[ijet],weight);
      hist_3[5]->Fill(pfjetAK8btag_CSV[ijet],weight);
      hist_3[6]->Fill(pfjetAK8btag_DeepCSV[ijet],weight);
      hist_3[7]->Fill(pfjetAK8matchAK4deepb[ijet],weight);
      hist_3[8]->Fill(pfjetAK8DeepTag_TvsQCD[ijet],weight);
      hist_3[9]->Fill(pfjetAK8DeepTag_WvsQCD[ijet],weight);
      hist_3[10]->Fill(pfjetAK8DeepTag_ZvsQCD[ijet],weight);
      hist_3[11]->Fill(pfjetAK8CHF[ijet],weight);
      hist_3[12]->Fill(pfjetAK8NHF[ijet],weight);
      hist_3[13]->Fill(pfjetAK8CEMF[ijet],weight);
      hist_3[14]->Fill(pfjetAK8NEMF[ijet],weight);
      hist_3[15]->Fill(pfjetAK8MUF[ijet],weight);
      hist_3[16]->Fill(pfjetAK8HOF[ijet],weight);
      hist_3[17]->Fill(pfjetAK8HadF[ijet],weight);
      hist_3[18]->Fill(pfjetAK8NHadF[ijet],weight);
      hist_3[19]->Fill(pfjetAK8EmF[ijet],weight);
      hist_3[20]->Fill(pfjetAK8neuemfrac[ijet],weight);
      hist_3[21]->Fill(pfjetAK8neunhadfrac[ijet],weight);
      hist_3[22]->Fill(pfjetAK8chrad[ijet],weight);
      hist_3[23]->Fill(pfjetAK8pTD[ijet],weight);
      hist_3[24]->Fill(pfjetAK8sdmass[ijet],weight);
      hist_3[25]->Fill(pfjetAK8tau21[ijet],weight);
      hist_3[26]->Fill(pfjetAK8tau32[ijet],weight);
      hist_3[27]->Fill(pfjetAK8sub1mass[ijet],weight);
      hist_3[28]->Fill(pfjetAK8sub1btag[ijet],weight);
      hist_3[29]->Fill(pfjetAK8sub1hadfrac[ijet],weight);
      hist_3[30]->Fill(pfjetAK8sub1emfrac[ijet],weight);
      hist_3[31]->Fill(pfjetAK8sub2mass[ijet],weight);
      hist_3[32]->Fill(pfjetAK8sub2btag[ijet],weight);
      hist_3[33]->Fill(pfjetAK8sub2hadfrac[ijet],weight);
      hist_3[34]->Fill(pfjetAK8sub2emfrac[ijet],weight);
      hist_3[35]->Fill(pfjetAK8subhaddiff[ijet],weight);
      hist_3[36]->Fill(pfjetAK8subemdiff[ijet],weight);
      hist_3[37]->Fill(pfjetAK8subptdiff[ijet],weight);
      hist_3[38]->Fill(pfjetAK8subbtag[ijet],weight);
      hist_3[39]->Fill(pfjetAK8_leppt[ijet],weight);
      hist_3[40]->Fill(pfjetAK8_bpt[ijet],weight);
      hist_3[41]->Fill(pfjetAK8_nupt[ijet],weight);
      hist_3[42]->Fill(pfjetAK8_Rnew[ijet],weight);
      hist_3[43]->Fill(pfjetAK8_bbyW_E[ijet],weight);
      hist_3[44]->Fill(pfjetAK8_Kfactor[ijet],weight);
      hist_3[45]->Fill(pfjetAK8re_tvsb[ijet],weight);
      hist_3[46]->Fill(pfjetAK8rnu_tvsb[ijet],weight);
      
      h2d_re_rnu_3->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
    }
    
    if(qg_cond){
      
      hist_4[0]->Fill(pfjetAK8pt[ijet],weight);
      hist_4[1]->Fill(pfjetAK8y[ijet],weight);
      hist_4[2]->Fill(pfjetAK8phi[ijet],weight);
      hist_4[3]->Fill(pfjetAK8mass[ijet],weight);
      hist_4[4]->Fill(pfjetAK8btag_CMVA[ijet],weight);
      hist_4[5]->Fill(pfjetAK8btag_CSV[ijet],weight);
      hist_4[6]->Fill(pfjetAK8btag_DeepCSV[ijet],weight);
      hist_4[7]->Fill(pfjetAK8matchAK4deepb[ijet],weight);
      hist_4[8]->Fill(pfjetAK8DeepTag_TvsQCD[ijet],weight);
      hist_4[9]->Fill(pfjetAK8DeepTag_WvsQCD[ijet],weight);
      hist_4[10]->Fill(pfjetAK8DeepTag_ZvsQCD[ijet],weight);
      hist_4[11]->Fill(pfjetAK8CHF[ijet],weight);
      hist_4[12]->Fill(pfjetAK8NHF[ijet],weight);
      hist_4[13]->Fill(pfjetAK8CEMF[ijet],weight);
      hist_4[14]->Fill(pfjetAK8NEMF[ijet],weight);
      hist_4[15]->Fill(pfjetAK8MUF[ijet],weight);
      hist_4[16]->Fill(pfjetAK8HOF[ijet],weight);
      hist_4[17]->Fill(pfjetAK8HadF[ijet],weight);
      hist_4[18]->Fill(pfjetAK8NHadF[ijet],weight);
      hist_4[19]->Fill(pfjetAK8EmF[ijet],weight);
      hist_4[20]->Fill(pfjetAK8neuemfrac[ijet],weight);
      hist_4[21]->Fill(pfjetAK8neunhadfrac[ijet],weight);
      hist_4[22]->Fill(pfjetAK8chrad[ijet],weight);
      hist_4[23]->Fill(pfjetAK8pTD[ijet],weight);
      hist_4[24]->Fill(pfjetAK8sdmass[ijet],weight);
      hist_4[25]->Fill(pfjetAK8tau21[ijet],weight);
      hist_4[26]->Fill(pfjetAK8tau32[ijet],weight);
      hist_4[27]->Fill(pfjetAK8sub1mass[ijet],weight);
      hist_4[28]->Fill(pfjetAK8sub1btag[ijet],weight);
      hist_4[29]->Fill(pfjetAK8sub1hadfrac[ijet],weight);
      hist_4[30]->Fill(pfjetAK8sub1emfrac[ijet],weight);
      hist_4[31]->Fill(pfjetAK8sub2mass[ijet],weight);
      hist_4[32]->Fill(pfjetAK8sub2btag[ijet],weight);
      hist_4[33]->Fill(pfjetAK8sub2hadfrac[ijet],weight);
      hist_4[34]->Fill(pfjetAK8sub2emfrac[ijet],weight);
      hist_4[35]->Fill(pfjetAK8subhaddiff[ijet],weight);
      hist_4[36]->Fill(pfjetAK8subemdiff[ijet],weight);
      hist_4[37]->Fill(pfjetAK8subptdiff[ijet],weight);
      hist_4[38]->Fill(pfjetAK8subbtag[ijet],weight);
      hist_4[39]->Fill(pfjetAK8_leppt[ijet],weight);
      hist_4[40]->Fill(pfjetAK8_bpt[ijet],weight);
      hist_4[41]->Fill(pfjetAK8_nupt[ijet],weight);
      hist_4[42]->Fill(pfjetAK8_Rnew[ijet],weight);
      hist_4[43]->Fill(pfjetAK8_bbyW_E[ijet],weight);
      hist_4[44]->Fill(pfjetAK8_Kfactor[ijet],weight);
      hist_4[45]->Fill(pfjetAK8re_tvsb[ijet],weight);
      hist_4[46]->Fill(pfjetAK8rnu_tvsb[ijet],weight);
      
      h2d_re_rnu_4->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
    }
    
    if(b_cond){
      /* 
      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)                                                                                                                                  
        {                                                                                                                                                                                                        
          if (nelecs > 0) {                                                                                                                                                                                      
	    float dR_min(0.4); int nearest(-1);                                                                                                                                                                  
            for(int el=0; el<nelecs; el++){                                                                                                                                                                      
              float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);                                                                                                         
              if (dR < dR_min) {                                                                                                                                                                                 
                dR_min = dR;                                                                                                                                                                                     
                nearest = el;                                                                                                                                                                                    
              }}                                                                                                                                                                                                 
             if (nearest >= 0 && pfjetAK8elinsubpt[ijet] > 25.0 && pfjetAK8pt[ijet] > 400.0 && elmvaid_noIso[nearest] == 1) {                                                                                     
              if (ijet == 0) {                                                                                                                                                                                   
                h->Fill(elsupcl_rawE[nearest],weight);                                                                                                                                                           
                h_Re->Fill(Re,weight);                                                                                                                                                                           
                heldxy->Fill(eldxy[nearest],weight);                                                                                                                                                             
                heldxy_sv->Fill(eldxy_sv[nearest],weight);                                                                                                                                                       
                helsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);                                                                                                                      
                helcleta->Fill(elsupcl_eta[nearest],weight);                                                                                                                                                     
                if (Re > 0.42) {                                                                                                                                                                                 
                  float ptrat = pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet];                                                                                                                                
                  hre->Fill(elsupcl_rawE[nearest],weight);                                                                                                                                                       
                  h_reRe->Fill(Re,weight);                                                                                                                                                                       
                  hreeldxy->Fill(eldxy[nearest],weight);                                                                                                                                                         
                  hreeldxy_sv->Fill(eldxy_sv[nearest],weight);                                                                                                                                                   
                  hreelsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);                                                                                                                  
                  hreelcleta->Fill(elsupcl_eta[nearest],weight);                                                                                                                                                 
                }                                                                                                                                                                                                
              }                                                                                                                                                                                                  
            }
	  }
	}
      */
      /*
      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
        {
          if (nelecs > 0) {
            float dR_min(0.4); int nearest(-1);
            for(int el=0; el<nelecs; el++){
              float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
              if (dR < dR_min) {
                dR_min = dR;
                nearest = el;
              }}
	    if (ijet == 0 && nearest >= 0 && pfjetAK8pt[ijet] > 400){
	      h_NoID_elptIn->Fill(pfjetAK8elinsubpt[ijet],weight);
	      if (Re > 0.42) {
		h_NoID_reelptIn->Fill(pfjetAK8elinsubpt[ijet],weight);
	      }}

	    if (ijet == 0 && nearest >= 0 && pfjetAK8elinsubpt[ijet] > 25 && pfjetAK8pt[ijet] > 400){
	      h_NoID_->Fill(elsupcl_rawE[nearest],weight);
              h_NoID_eldxy->Fill(eldxy[nearest],weight);
              h_NoID_eldxy_sv->Fill(eldxy_sv[nearest],weight);
              h_NoID_elsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
              h_NoID_elcleta->Fill(elsupcl_eta[nearest],weight);

              if (Re > 0.42) {
                float ptrat = pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet];
                h_NoID_re->Fill(elsupcl_rawE[nearest],weight);
                h_NoID_reeldxy->Fill(eldxy[nearest],weight);
                h_NoID_reeldxy_sv->Fill(eldxy_sv[nearest],weight);
                h_NoID_reelsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
                h_NoID_reelcleta->Fill(elsupcl_eta[nearest],weight);
	      }}
	    if (ijet == 0 && nearest >= 0 && pfjetAK8pt[ijet] > 400 && elmvaid_noIso[nearest] == 1){
	      h_Noelpt_->Fill(elsupcl_rawE[nearest],weight);
              h_Noelpt_eldxy->Fill(eldxy[nearest],weight);
              h_Noelpt_eldxy_sv->Fill(eldxy_sv[nearest],weight);
              h_Noelpt_elsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
              h_Noelpt_elcleta->Fill(elsupcl_eta[nearest],weight);
	      h_Noelpt_elptIn->Fill(pfjetAK8elinsubpt[ijet],weight);
	      
              if (Re > 0.42) {
                float ptrat = pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet];
                h_Noelpt_re->Fill(elsupcl_rawE[nearest],weight);
                h_Noelpt_reeldxy->Fill(eldxy[nearest],weight);
                h_Noelpt_reeldxy_sv->Fill(eldxy_sv[nearest],weight);
                h_Noelpt_reelsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
                h_Noelpt_reelcleta->Fill(elsupcl_eta[nearest],weight);
		h_Noelpt_reelptIn->Fill(pfjetAK8elinsubpt[ijet],weight);
              }}
	    if (ijet == 0 && nearest >= 0 && pfjetAK8elinsubpt[ijet] > 25 && pfjetAK8pt[ijet] > 400 && elmvaid_noIso[nearest] == 1) {
	      h->Fill(elsupcl_rawE[nearest],weight);                                                                                       
	      heldxy->Fill(eldxy[nearest],weight);                                                                                         
	      heldxy_sv->Fill(eldxy_sv[nearest],weight);                                                                                   
	      helsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);                                                  
	      helcleta->Fill(elsupcl_eta[nearest],weight);                                                                                 
                                                                                                                                           
	      if (Re > 0.42) {                                                                                                             
		float ptrat = pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet];                                                            
		hre->Fill(elsupcl_rawE[nearest],weight);                                                                                   
		hreeldxy->Fill(eldxy[nearest],weight);                                                                                     
		hreeldxy_sv->Fill(eldxy_sv[nearest],weight);                                                                               
		hreelsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);                                              
		hreelcleta->Fill(elsupcl_eta[nearest],weight);
		}}}}*/
	      

      if (ijet == 0 && pfjetAK8pt[ijet] > 400) {
	if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)h1d_elpt_subjet_b->Fill(pfjetAK8elinsubpt[ijet],weight);
        if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100 && pfjetAK8elinsubpt[ijet] > 25) {
	  h1d_elsubrat_b->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);
	  if (Re > 0.42) h1d_elsubrat_b_gRe->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);
       

	  if (Re < 0.42) h1d_elsubrat_b_lRe->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);
	  
          hist_52D[0]->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
          if (Re > 0.42) hist_52D[1]->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
          if (Re < 0.42) hist_52D[2]->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
	  
          hist_52D[3]->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);
          if (Re > 0.42) hist_52D[4]->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);
          if (Re < 0.42) hist_52D[5]->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);

          if (nelecs > 0) {
            float dR_min(0.4); int nearest(-1);
            for(int el=0; el<nelecs; el++){
              float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
              if (dR < dR_min) {
                dR_min = dR;
                nearest = el;
              }}
	    /*
	    if (nearest >= 0) {
	      if (elmvaid_noIso[nearest] == 1) {
		h->Fill(elsupcl_rawE[nearest],weight);
		heldxy->Fill(eldxy[nearest],weight);
		heldxy_sv->Fill(eldxy_sv[nearest],weight);
		helsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
		helcleta->Fill(elsupcl_eta[nearest],weight);
		
		if (Re > 0.42) {
		  float ptrat = pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet];
		  hre->Fill(elsupcl_rawE[nearest],weight);
		  hreeldxy->Fill(eldxy[nearest],weight);
		  hreeldxy_sv->Fill(eldxy_sv[nearest],weight);
		  hreelsubptrat->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet],weight);
		  hreelcleta->Fill(elsupcl_eta[nearest],weight);

		  //TString str1 = TString::Format("rawE %f eta %f ptrat %f sec_vtx %f \n",elsupcl_rawE[nearest],elsupcl_eta[nearest],ptrat,eldxy_sv[nearest]);                                               
		  //if(gProofServ) gProofServ->SendAsynMessage(str1);
		}}}*/
	    
	    if (nearest >= 0) {
              hist_52Dnew[0]->Fill(eldxy[nearest],pfjetAK8elinsubpt[ijet],weight);
              hist_52Dnew[1]->Fill(eldxy_sv[nearest],pfjetAK8elinsubpt[ijet],weight);
              hist_52Dnew[2]->Fill(eldxy[nearest],eldxy_sv[nearest],weight);
              hist_52Dnew[3]->Fill(eldxy[nearest],elmvaid_noIso[nearest],weight);
	      hist_52Dnew[4]->Fill(eldxy_sv[nearest],elmvaid_noIso[nearest],weight);
	      hist_52Dnew[5]->Fill(eldxy_sv[nearest],elsupcl_eta[nearest],weight);
	      hist_52Dnew[6]->Fill(eldxy_sv[nearest],elsupcl_rawE[nearest],weight);
	      hist_52Dnew[7]->Fill(eldxy_sv[nearest],ele[nearest],weight);
            }
	    
	    if (nearest >= 0) {
              h1d_eldxy_subjet_b->Fill(eldxy_sv[nearest],weight);
              if (Re > 0.42) h1d_eldxy_subjet_b_gRe->Fill(eldxy_sv[nearest],weight);
              if (Re < 0.42) h1d_eldxy_subjet_b_lRe->Fill(eldxy_sv[nearest],weight);
            }
	    
            if (nearest >= 0) hist_52D[6]->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);
            if (nearest >= 0 && Re > 0.42) hist_52D[7]->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);
            if (nearest >= 0 && Re < 0.42) hist_52D[8]->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);
	    
            if (nearest >= 0) hist_52D[9]->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
            if (nearest >= 0 && Re > 0.42) hist_52D[10]->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
            if (nearest >= 0 && Re < 0.42) hist_52D[11]->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
          }
	  
        }}
      
      if (ijet == maxM && pfjetAK8pt[ijet] > 400) {
	if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)h1d_elpt_subjetM_b->Fill(pfjetAK8elinsubpt[ijet],weight);
	if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100 && pfjetAK8elinsubpt[ijet] > 25) {
	  
	  h1d_elsubratM_b->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);
	  if (Re > 0.42) h1d_elsubratM_b_gRe->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);
          if (Re < 0.42) h1d_elsubratM_b_lRe->Fill(pfjetAK8elinsubpt[ijet]/pfjetAK8elinsubjpt[ijet]);

          hist_52D[12]->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
          if (Re > 0.42) hist_52D[13]->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);
          if (Re < 0.42) hist_52D[14]->Fill(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubjpt[ijet],weight);

          hist_52D[15]->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);
          if (Re > 0.42) hist_52D[16]->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);
          if (Re < 0.42) hist_52D[17]->Fill(pfjetAK8elinsubeta[ijet],pfjetAK8elinsubjeta[ijet],weight);
          if (nelecs > 0) {
            float dR_min(0.4); int nearest(-1);
            for(int el=0; el<nelecs; el++){
              float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
	      if (dR < dR_min) {
                dR_min = dR;
                nearest = el;
              }}
	    
	    if (nearest >= 0) {
              h1d_eldxy_subjetM_b->Fill(eldxy_sv[nearest],weight);
              if (Re > 0.42) h1d_eldxy_subjetM_b_gRe->Fill(eldxy_sv[nearest],weight);
              if (Re < 0.42) h1d_eldxy_subjetM_b_lRe->Fill(eldxy_sv[nearest],weight);
            }
	    
            if (nearest >= 0) hist_52D[18]->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);
            if (nearest >= 0 && Re > 0.42) hist_52D[19]->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);
            if (nearest >= 0 && Re < 0.42) hist_52D[20]->Fill(elsupcl_eta[nearest],pfjetAK8elinsubeta[ijet],weight);

            if (nearest >= 0) hist_52D[21]->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
            if (nearest >= 0 && Re > 0.42) hist_52D[22]->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
            if (nearest >= 0 && Re < 0.42) hist_52D[23]->Fill(elsupcl_rawE[nearest],pfjetAK8elinsube[ijet],weight);
          }

	  }} 

      hist_5[0]->Fill(pfjetAK8pt[ijet],weight);
      hist_5[1]->Fill(pfjetAK8y[ijet],weight);
      hist_5[2]->Fill(pfjetAK8phi[ijet],weight);
      hist_5[3]->Fill(pfjetAK8mass[ijet],weight);
      hist_5[4]->Fill(pfjetAK8btag_CMVA[ijet],weight);
      hist_5[5]->Fill(pfjetAK8btag_CSV[ijet],weight);
      hist_5[6]->Fill(pfjetAK8btag_DeepCSV[ijet],weight);
      hist_5[7]->Fill(pfjetAK8matchAK4deepb[ijet],weight);
      hist_5[8]->Fill(pfjetAK8DeepTag_TvsQCD[ijet],weight);
      hist_5[9]->Fill(pfjetAK8DeepTag_WvsQCD[ijet],weight);
      hist_5[10]->Fill(pfjetAK8DeepTag_ZvsQCD[ijet],weight);
      hist_5[11]->Fill(pfjetAK8CHF[ijet],weight);
      hist_5[12]->Fill(pfjetAK8NHF[ijet],weight);
      hist_5[13]->Fill(pfjetAK8CEMF[ijet],weight);
      hist_5[14]->Fill(pfjetAK8NEMF[ijet],weight);
      hist_5[15]->Fill(pfjetAK8MUF[ijet],weight);
      hist_5[16]->Fill(pfjetAK8HOF[ijet],weight);
      hist_5[17]->Fill(pfjetAK8HadF[ijet],weight);
      hist_5[18]->Fill(pfjetAK8NHadF[ijet],weight);
      hist_5[19]->Fill(pfjetAK8EmF[ijet],weight);
      hist_5[20]->Fill(pfjetAK8neuemfrac[ijet],weight);
      hist_5[21]->Fill(pfjetAK8neunhadfrac[ijet],weight);
      hist_5[22]->Fill(pfjetAK8chrad[ijet],weight);
      hist_5[23]->Fill(pfjetAK8pTD[ijet],weight);
      hist_5[24]->Fill(pfjetAK8sdmass[ijet],weight);
      hist_5[25]->Fill(pfjetAK8tau21[ijet],weight);
      hist_5[26]->Fill(pfjetAK8tau32[ijet],weight);
      hist_5[27]->Fill(pfjetAK8sub1mass[ijet],weight);
      hist_5[28]->Fill(pfjetAK8sub1btag[ijet],weight);
      hist_5[29]->Fill(pfjetAK8sub1hadfrac[ijet],weight);
      hist_5[30]->Fill(pfjetAK8sub1emfrac[ijet],weight);
      hist_5[31]->Fill(pfjetAK8sub2mass[ijet],weight);
      hist_5[32]->Fill(pfjetAK8sub2btag[ijet],weight);
      hist_5[33]->Fill(pfjetAK8sub2hadfrac[ijet],weight);
      hist_5[34]->Fill(pfjetAK8sub2emfrac[ijet],weight);
      hist_5[35]->Fill(pfjetAK8subhaddiff[ijet],weight);
      hist_5[36]->Fill(pfjetAK8subemdiff[ijet],weight);
      hist_5[37]->Fill(pfjetAK8subptdiff[ijet],weight);
      hist_5[38]->Fill(pfjetAK8subbtag[ijet],weight);
      hist_5[39]->Fill(pfjetAK8_leppt[ijet],weight);
      hist_5[40]->Fill(pfjetAK8_bpt[ijet],weight);
      hist_5[41]->Fill(pfjetAK8_nupt[ijet],weight);
      hist_5[42]->Fill(pfjetAK8_Rnew[ijet],weight);
      hist_5[43]->Fill(pfjetAK8_bbyW_E[ijet],weight);
      hist_5[44]->Fill(pfjetAK8_Kfactor[ijet],weight);
      hist_5[45]->Fill(pfjetAK8re_tvsb[ijet],weight);
      hist_5[46]->Fill(pfjetAK8rnu_tvsb[ijet],weight);
      h2d_re_rnu_5->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
    }
  
  }//ijet
  //}//npfjetAK8 > 0
  //TString str1 = TString::Format("tr_count %d \n",tr_count);                                                              
  //if(gProofServ) gProofServ->SendAsynMessage(str1);

  
  int t_cand = -1;
  double remax = -200;
  //if (npfjetAK8 > 0) {
  for(int ijet=0; ijet < npfjetAK8; ijet++){
    if(pfjetAK8re_tvsb[ijet] > remax){
      remax = pfjetAK8re_tvsb[ijet];
      t_cand = ijet;
    }
  }
  //}
  hist_6[0]->Fill(pfjetAK8pt[t_cand],weight);
  hist_6[1]->Fill(pfjetAK8y[t_cand],weight);
  hist_6[2]->Fill(pfjetAK8phi[t_cand],weight);
  hist_6[3]->Fill(pfjetAK8mass[t_cand],weight);
  hist_6[4]->Fill(pfjetAK8btag_CMVA[t_cand],weight);
  hist_6[5]->Fill(pfjetAK8btag_CSV[t_cand],weight);
  hist_6[6]->Fill(pfjetAK8btag_DeepCSV[t_cand],weight);
  hist_6[7]->Fill(pfjetAK8matchAK4deepb[t_cand],weight);
  hist_6[8]->Fill(pfjetAK8DeepTag_TvsQCD[t_cand],weight);
  hist_6[9]->Fill(pfjetAK8DeepTag_WvsQCD[t_cand],weight);
  hist_6[10]->Fill(pfjetAK8DeepTag_ZvsQCD[t_cand],weight);
  hist_6[11]->Fill(pfjetAK8CHF[t_cand],weight);
  hist_6[12]->Fill(pfjetAK8NHF[t_cand],weight);
  hist_6[13]->Fill(pfjetAK8CEMF[t_cand],weight);
  hist_6[14]->Fill(pfjetAK8NEMF[t_cand],weight);
  hist_6[15]->Fill(pfjetAK8MUF[t_cand],weight);
  hist_6[16]->Fill(pfjetAK8HOF[t_cand],weight);
  hist_6[17]->Fill(pfjetAK8HadF[t_cand],weight);
  hist_6[18]->Fill(pfjetAK8NHadF[t_cand],weight);
  hist_6[19]->Fill(pfjetAK8EmF[t_cand],weight);
  hist_6[20]->Fill(pfjetAK8neuemfrac[t_cand],weight);
  hist_6[21]->Fill(pfjetAK8neunhadfrac[t_cand],weight);
  hist_6[22]->Fill(pfjetAK8chrad[t_cand],weight);
  hist_6[23]->Fill(pfjetAK8pTD[t_cand],weight);
  hist_6[24]->Fill(pfjetAK8sdmass[t_cand],weight);
  hist_6[25]->Fill(pfjetAK8tau21[t_cand],weight);
  hist_6[26]->Fill(pfjetAK8tau32[t_cand],weight);
  hist_6[27]->Fill(pfjetAK8sub1mass[t_cand],weight);
  hist_6[28]->Fill(pfjetAK8sub1btag[t_cand],weight);
  hist_6[29]->Fill(pfjetAK8sub1hadfrac[t_cand],weight);
  hist_6[30]->Fill(pfjetAK8sub1emfrac[t_cand],weight);
  hist_6[31]->Fill(pfjetAK8sub2mass[t_cand],weight);
  hist_6[32]->Fill(pfjetAK8sub2btag[t_cand],weight);
  hist_6[33]->Fill(pfjetAK8sub2hadfrac[t_cand],weight);
  hist_6[34]->Fill(pfjetAK8sub2emfrac[t_cand],weight);
  hist_6[35]->Fill(pfjetAK8subhaddiff[t_cand],weight);
  hist_6[36]->Fill(pfjetAK8subemdiff[t_cand],weight);
  hist_6[37]->Fill(pfjetAK8subptdiff[t_cand],weight);
  hist_6[38]->Fill(pfjetAK8subbtag[t_cand],weight);
  hist_6[39]->Fill(pfjetAK8_leppt[t_cand],weight);
  hist_6[40]->Fill(pfjetAK8_bpt[t_cand],weight);
  hist_6[41]->Fill(pfjetAK8_nupt[t_cand],weight);
  hist_6[42]->Fill(pfjetAK8_Rnew[t_cand],weight);
  hist_6[43]->Fill(pfjetAK8_bbyW_E[t_cand],weight);
  hist_6[44]->Fill(pfjetAK8_Kfactor[t_cand],weight);
  hist_6[45]->Fill(pfjetAK8re_tvsb[t_cand],weight);
  hist_6[46]->Fill(pfjetAK8rnu_tvsb[t_cand],weight);
  h2d_re_rnu_6->Fill(pfjetAK8re_tvsb[t_cand],pfjetAK8rnu_tvsb[t_cand],weight);
  
  double dRmax = -999;
  int max(-1);
  //if(npfjetAK8 > 0) {
  for(int ijet=0; ijet< npfjetAK8; ijet++){
    if(pfjetAK8re_tvsb[ijet] > dRmax){
      dRmax = pfjetAK8re_tvsb[ijet];
      max = ijet;
    }
  }
  //}
    
  if(nleptop>=1) { 
    for(int ire=0; ire<(nre+1); ire++){
      if(dRmax >= (-1.+ ire*2./100.)){
	//TString str2 = TString::Format(" %f  entry %lli \n",(-1.+ ire*2./100.),entry);
	//if(gProofServ) gProofServ->SendAsynMessage(str2);
     	hist_event_top_pass->Fill(1.*(ire+1.),weight); 
      }
    }
  }
 
  #ifdef TRAINING
  int iseljet = 0;
  npfjetAK8_te = 0;

  for(int ijet=0; ijet< npfjetAK8; ++ijet){
    
    if(ijet>(nmaxjet-1)) break;
    
    bool te_cond = false;
    te_cond  = (pfjetAK8haselectron[ijet] == 1 && pfjetAK8hasleptop[ijet] == 1 && pfjetAK8hastop[ijet] == 1 && pfjetAK8hasleptop_alldecay[ijet] == 1);
    
     if(te_cond == 1){
       h_re_count_tr->Fill(1,weight);
       selpfjetAK8pt[iseljet] = pfjetAK8pt[ijet];
       selpfjetAK8y[iseljet] = pfjetAK8y[ijet];
       selpfjetAK8mass[iseljet] = pfjetAK8mass[ijet];
       selpfjetAK8phi[iseljet] = pfjetAK8phi[ijet];
       selpfjetAK8btag_CMVA[iseljet] = pfjetAK8btag_CMVA[ijet];
       selpfjetAK8btag_CSV[iseljet] = pfjetAK8btag_CSV[ijet];
       selpfjetAK8btag_DeepCSV[iseljet] = pfjetAK8btag_DeepCSV[ijet];
       selpfjetAK8matchAK4deepb[iseljet] = pfjetAK8matchAK4deepb[ijet];
       selpfjetAK8DeepTag_TvsQCD[iseljet] =  pfjetAK8DeepTag_TvsQCD[ijet];
       selpfjetAK8DeepTag_WvsQCD[iseljet] = pfjetAK8DeepTag_WvsQCD[ijet];
       selpfjetAK8DeepTag_ZvsQCD[iseljet] = pfjetAK8DeepTag_ZvsQCD[ijet];
       selpfjetAK8CHF[iseljet] = pfjetAK8CHF[ijet];
       selpfjetAK8NHF[iseljet] = pfjetAK8NHF[ijet];
       selpfjetAK8CEMF[iseljet] = pfjetAK8CEMF[ijet];
       selpfjetAK8NEMF[iseljet] = pfjetAK8NEMF[ijet];
       selpfjetAK8MUF[iseljet] = pfjetAK8MUF[ijet];
       selpfjetAK8HOF[iseljet] = pfjetAK8HOF[ijet];
       selpfjetAK8HadF[iseljet] = pfjetAK8HadF[ijet];
       selpfjetAK8NHadF[iseljet] = pfjetAK8NHadF[ijet];
       selpfjetAK8EmF[iseljet] = pfjetAK8EmF[ijet];
       selpfjetAK8neuemfrac[iseljet] = pfjetAK8neuemfrac[ijet];
       selpfjetAK8neunhadfrac[iseljet] = pfjetAK8neunhadfrac[ijet];
       selpfjetAK8CHM[iseljet] = pfjetAK8CHM[ijet];
       selpfjetAK8NHM[iseljet] = pfjetAK8NHM[ijet];
       selpfjetAK8CEMM[iseljet] = pfjetAK8CEMM[ijet];
       selpfjetAK8NEMM[iseljet] =  pfjetAK8NEMM[ijet];
       selpfjetAK8MUM[iseljet] = pfjetAK8MUM[ijet];
       selpfjetAK8Neucons[iseljet] = pfjetAK8Neucons[ijet];
       selpfjetAK8Chcons[iseljet] = pfjetAK8Chcons[ijet] ;
       selpfjetAK8chrad[iseljet] =  pfjetAK8chrad[ijet];
       selpfjetAK8pTD[iseljet] = pfjetAK8pTD[ijet];
       selpfjetAK8sdmass[iseljet] = pfjetAK8sdmass[ijet];
      
       
       selpfjetAK8elsubjptrat[iseljet] = pfjetAK8elsubjptrat[ijet];
       selpfjetAK8elinsubpt[iseljet] = fabs(pfjetAK8elinsubpt[ijet]);
       selpfjetAK8elinsubeta[iseljet] = pfjetAK8elinsubeta[ijet];
       selpfjetAK8elinsubphi[iseljet] = pfjetAK8elinsubphi[ijet];
       selpfjetAK8elinsubjpt[iseljet] = pfjetAK8elinsubjpt[ijet];
       selpfjetAK8elinsubjeta[iseljet] = pfjetAK8elinsubjeta[ijet];
       selpfjetAK8elinsubjphi[iseljet] = pfjetAK8elinsubjphi[ijet];
       
       selpfjetAK8matchedelID[iseljet] = -100;
       selpfjetAK8matchedelpt[iseljet] = -100;
       selpfjetAK8matchedeleta[iseljet] = -100;
       selpfjetAK8matchedelphi[iseljet] = -100;
       selpfjetAK8matchedelE[iseljet] = -100;
       selpfjetAK8matchedeldxy[iseljet] = -100;
       selpfjetAK8matchedeldxy_sv[iseljet] = -100;
       selpfjetAK8matchedelcleta[iseljet] = -100;
       selpfjetAK8matchedelclphi[iseljet] = -100;
       selpfjetAK8matchedelclrawE[iseljet] = -100;
       
       if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
	 {
	   if (nelecs > 0) {
	     float dR_min(0.4); int nearest(-1);
	     for(int el=0; el<nelecs; el++){
	       float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
	       if (dR < dR_min) {
		 dR_min = dR;
		 nearest = el;
	       }}
	     if (nearest >= 0) {
	       selpfjetAK8matchedelID[iseljet] = elmvaid_noIso[nearest];
	       selpfjetAK8matchedelpt[iseljet] = fabs(elpt[nearest]);
	       selpfjetAK8matchedeleta[iseljet] = eleta[nearest];
	       selpfjetAK8matchedelphi[iseljet] = elphi[nearest];
	       selpfjetAK8matchedelE[iseljet] = ele[nearest];
	       selpfjetAK8matchedeldxy[iseljet] = eldxy[nearest];
	       selpfjetAK8matchedeldxy_sv[iseljet] = eldxy_sv[nearest];
	       selpfjetAK8matchedelcleta[iseljet] = elsupcl_eta[nearest];
	       selpfjetAK8matchedelclphi[iseljet] = elsupcl_phi[nearest];
	       selpfjetAK8matchedelclrawE[iseljet] = elsupcl_rawE[nearest];
	     }}}
       
       //if (ijet == 0) {
	 if (selpfjetAK8matchedelclrawE[iseljet]!= -100 && selpfjetAK8pt[iseljet] > 400.0) {
	   htelinpt->Fill(selpfjetAK8elinsubpt[iseljet],weight);
	   htelinid->Fill(selpfjetAK8matchedelID[iseljet],weight);
	   ht->Fill(selpfjetAK8matchedelclrawE[iseljet],weight);                                                             
	   hteldxy->Fill(selpfjetAK8matchedeldxy[iseljet],weight);                                                           
	   hteldxy_sv->Fill(selpfjetAK8matchedeldxy_sv[iseljet],weight);                                                     
	   htelcleta->Fill(selpfjetAK8matchedelcleta[iseljet],weight);                                                       
	   htelsubptrat->Fill(selpfjetAK8elsubjptrat[iseljet],weight);                                                       
  
	 
	   if (pfjetAK8re_tvsb[iseljet] > 0.42) {                                                                            
	     htrelinpt->Fill(selpfjetAK8elinsubpt[iseljet],weight);
	     htrelinid->Fill(selpfjetAK8matchedelID[iseljet],weight);
	     htre->Fill(selpfjetAK8matchedelclrawE[iseljet],weight);                                                           
	     htreeldxy->Fill(selpfjetAK8matchedeldxy[iseljet],weight);                                                         
	     htreeldxy_sv->Fill(selpfjetAK8matchedeldxy_sv[iseljet],weight);                                                   
	     htreelcleta->Fill(selpfjetAK8matchedelcleta[iseljet],weight);                                                     
	     htreelsubptrat->Fill(selpfjetAK8elsubjptrat[iseljet],weight);                                                 
    	   }                                                                                                                          }
	 //}
	selpfjetAK8tau21[iseljet] = pfjetAK8tau21[ijet];
       selpfjetAK8tau32[iseljet] = pfjetAK8tau32[ijet];
       selpfjetAK8sub1mass[iseljet] = pfjetAK8sub1mass[ijet];
       selpfjetAK8sub1btag[iseljet] = pfjetAK8sub1btag[ijet];
       selpfjetAK8sub1hadfrac[iseljet] =  pfjetAK8sub1hadfrac[ijet];
       selpfjetAK8sub1emfrac[iseljet] = pfjetAK8sub1emfrac[ijet];
       selpfjetAK8sub2mass[iseljet] = pfjetAK8sub2mass[ijet];
       selpfjetAK8sub2btag[iseljet] =  pfjetAK8sub2btag[ijet];
       selpfjetAK8sub2hadfrac[iseljet] = pfjetAK8sub2hadfrac[ijet];
       selpfjetAK8sub2emfrac[iseljet] = pfjetAK8sub2emfrac[ijet];
       selpfjetAK8subbtag[iseljet] = pfjetAK8subbtag[ijet];
       selpfjetAK8subhaddiff[iseljet] =  pfjetAK8subhaddiff[ijet];
       selpfjetAK8subemdiff[iseljet] = pfjetAK8subemdiff[ijet];
       selpfjetAK8subptdiff[iseljet] = pfjetAK8subptdiff[ijet];
       selpfjetAK8_bbyW_E[iseljet] = pfjetAK8_bbyW_E[ijet];
       selpfjetAK8_Kfactor[iseljet] = pfjetAK8_Kfactor[ijet];
       selpfjetAK8_Rnew[iseljet] = pfjetAK8_Rnew[ijet];
       selpfjetAK8haselectron[iseljet] =  pfjetAK8haselectron[ijet];
       selpfjetAK8hasmuon[iseljet] =  pfjetAK8hasmuon[ijet];
       selpfjetAK8hasqg[iseljet] =  pfjetAK8hasqg[ijet];
       selpfjetAK8hasb[iseljet] =  pfjetAK8hasb[ijet];
       selpfjetAK8hashadtop[iseljet] =  pfjetAK8hashadtop[ijet];
       selpfjetAK8hasleptop[iseljet] = pfjetAK8hasleptop[ijet];
       selpfjetAK8hastop[iseljet] = pfjetAK8hastop[ijet];
       selpfjetAK8hashadtop_alldecay[iseljet] = pfjetAK8hashadtop_alldecay[ijet];
       selpfjetAK8hasleptop_alldecay[iseljet] = pfjetAK8hasleptop_alldecay[ijet];
       selpfjetAK8re_tvsb[iseljet] = pfjetAK8re_tvsb[ijet];
       selpfjetAK8rnu_tvsb[iseljet] = pfjetAK8rnu_tvsb[ijet];
       
      iseljet++;
      if(iseljet>=njetmxAK8) break;
     }
  }
  npfjetAK8_te = iseljet;
  Tout1->Fill();
  /*
  for(int z=1; z<=iseljet; ++z){
    h_te_count_tr->Fill(z,weight);

    if (z == 1) {

      hljetpt->Fill(selpfjetAK8pt[z-1],weight);
      hljety->Fill(selpfjetAK8y[z-1],weight);
      hljetphi->Fill(selpfjetAK8phi[z-1],weight);
      hljetmass->Fill(selpfjetAK8mass[z-1],weight);

      if (selpfjetAK8matchedelclrawE[z-1]!= -100 && selpfjetAK8pt[z-1] > 400.) {
	helpt->Fill(selpfjetAK8elinsubpt[z-1],weight);
	if (selpfjetAK8re_tvsb[z-1] > 0.42) helpt_gre->Fill(selpfjetAK8elinsubpt[z-1],weight);

	if (selpfjetAK8matchedelID[z-1] == 1) {
	  helptID->Fill(selpfjetAK8elinsubpt[z-1],weight);
	  if (selpfjetAK8re_tvsb[z-1] > 0.42) helptID_gre->Fill(selpfjetAK8elinsubpt[z-1],weight);
	}
	}*/
      /*
   
	if (selpfjetAK8matchedelclrawE[z-1]!= -100 && selpfjetAK8elinsubpt[z-1] > 25.0 && selpfjetAK8pt[z-1] > 400.0 && selpfjetAK8matchedelID[z-1] == 1) {
	ht->Fill(selpfjetAK8matchedelclrawE[z-1],weight);
	hteldxy->Fill(selpfjetAK8matchedeldxy[z-1],weight);
	hteldxy_sv->Fill(selpfjetAK8matchedeldxy_sv[z-1],weight);
	htelcleta->Fill(selpfjetAK8matchedelcleta[z-1],weight);
	htelsubptrat->Fill(selpfjetAK8elsubjptrat[z-1],weight);
	if (selpfjetAK8re_tvsb[z-1] > 0.42) {
	htre->Fill(selpfjetAK8matchedelclrawE[z-1],weight);
	htreeldxy->Fill(selpfjetAK8matchedeldxy[z-1],weight);
	htreeldxy_sv->Fill(selpfjetAK8matchedeldxy_sv[z-1],weight);
	htreelcleta->Fill(selpfjetAK8matchedelcleta[z-1],weight);
	htreelsubptrat->Fill(selpfjetAK8elsubjptrat[z-1],weight);
	}
	}*/
      //}
      //}
  
  
  iseljet = 0;
  npfjetAK8_tmu = 0;
  
  for(int ijet=0; ijet< npfjetAK8; ijet++){
    
    if(ijet>(nmaxjet-1)) break;
    
    bool tmu_cond = false;
    tmu_cond = (pfjetAK8hasmuon[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]);
    
    if(tmu_cond){
      
      selpfjetAK8pt[iseljet] = pfjetAK8pt[ijet];
      selpfjetAK8y[iseljet] = pfjetAK8y[ijet];
      selpfjetAK8mass[iseljet] = pfjetAK8mass[ijet];
      selpfjetAK8phi[iseljet] = pfjetAK8phi[ijet];
      selpfjetAK8btag_CMVA[iseljet] = pfjetAK8btag_CMVA[ijet];
      selpfjetAK8btag_CSV[iseljet] = pfjetAK8btag_CSV[ijet];
      selpfjetAK8btag_DeepCSV[iseljet] = pfjetAK8btag_DeepCSV[ijet];
      selpfjetAK8matchAK4deepb[iseljet] = pfjetAK8matchAK4deepb[ijet];
      selpfjetAK8DeepTag_TvsQCD[iseljet] =  pfjetAK8DeepTag_TvsQCD[ijet];
      selpfjetAK8DeepTag_WvsQCD[iseljet] = pfjetAK8DeepTag_WvsQCD[ijet];
      selpfjetAK8DeepTag_ZvsQCD[iseljet] = pfjetAK8DeepTag_ZvsQCD[ijet];
      selpfjetAK8CHF[iseljet] = pfjetAK8CHF[ijet];
      selpfjetAK8NHF[iseljet] = pfjetAK8NHF[ijet];
      selpfjetAK8CEMF[iseljet] = pfjetAK8CEMF[ijet];
      selpfjetAK8NEMF[iseljet] = pfjetAK8NEMF[ijet];
      selpfjetAK8MUF[iseljet] = pfjetAK8MUF[ijet];
      selpfjetAK8HOF[iseljet] = pfjetAK8HOF[ijet];
      selpfjetAK8HadF[iseljet] = pfjetAK8HadF[ijet];
      selpfjetAK8NHadF[iseljet] = pfjetAK8NHadF[ijet];
      selpfjetAK8EmF[iseljet] = pfjetAK8EmF[ijet];
      selpfjetAK8neuemfrac[iseljet] = pfjetAK8neuemfrac[ijet];
      selpfjetAK8neunhadfrac[iseljet] = pfjetAK8neunhadfrac[ijet];
      selpfjetAK8CHM[iseljet] = pfjetAK8CHM[ijet];
      selpfjetAK8NHM[iseljet] = pfjetAK8NHM[ijet];
      selpfjetAK8CEMM[iseljet] = pfjetAK8CEMM[ijet];
      selpfjetAK8NEMM[iseljet] =  pfjetAK8NEMM[ijet];
      selpfjetAK8MUM[iseljet] = pfjetAK8MUM[ijet];
      selpfjetAK8Neucons[iseljet] = pfjetAK8Neucons[ijet];
      selpfjetAK8Chcons[iseljet] = pfjetAK8Chcons[ijet] ;
      selpfjetAK8chrad[iseljet] =  pfjetAK8chrad[ijet];
      selpfjetAK8pTD[iseljet] = pfjetAK8pTD[ijet];
      selpfjetAK8sdmass[iseljet] = pfjetAK8sdmass[ijet];
      
      selpfjetAK8elsubjptrat[iseljet] = pfjetAK8elsubjptrat[ijet];
      selpfjetAK8elinsubpt[iseljet] = fabs(pfjetAK8elinsubpt[ijet]);
      selpfjetAK8elinsubeta[iseljet] = pfjetAK8elinsubeta[ijet];
      selpfjetAK8elinsubphi[iseljet] = pfjetAK8elinsubphi[ijet];
      selpfjetAK8elinsubjpt[iseljet] = pfjetAK8elinsubjpt[ijet];
      selpfjetAK8elinsubjeta[iseljet] = pfjetAK8elinsubjeta[ijet];
      selpfjetAK8elinsubjphi[iseljet] = pfjetAK8elinsubjphi[ijet];

      selpfjetAK8matchedelID[iseljet] = -100;
      selpfjetAK8matchedelpt[iseljet] = -100;
      selpfjetAK8matchedeleta[iseljet] = -100;
      selpfjetAK8matchedelphi[iseljet] = -100;
      selpfjetAK8matchedelE[iseljet] = -100;
      selpfjetAK8matchedeldxy[iseljet] = -100;
      selpfjetAK8matchedeldxy_sv[iseljet] = -100;
      selpfjetAK8matchedelcleta[iseljet] = -100;
      selpfjetAK8matchedelclphi[iseljet] = -100;
      selpfjetAK8matchedelclrawE[iseljet] = -100;

      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
        {
          if (nelecs > 0) {
            float dR_min(0.4); int nearest(-1);
            for(int el=0; el<nelecs; el++){
              float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
              if (dR < dR_min) {
                dR_min = dR;
                nearest = el;
              }}
            if (nearest >= 0) {
              selpfjetAK8matchedelID[iseljet] = elmvaid_noIso[nearest];
              selpfjetAK8matchedelpt[iseljet] = fabs(elpt[nearest]);
              selpfjetAK8matchedeleta[iseljet] = eleta[nearest];
              selpfjetAK8matchedelphi[iseljet] = elphi[nearest];
              selpfjetAK8matchedelE[iseljet] = ele[nearest];
              selpfjetAK8matchedeldxy[iseljet] = eldxy[nearest];
              selpfjetAK8matchedeldxy_sv[iseljet] = eldxy_sv[nearest];
              selpfjetAK8matchedelcleta[iseljet] = elsupcl_eta[nearest];
              selpfjetAK8matchedelclphi[iseljet] = elsupcl_phi[nearest];
              selpfjetAK8matchedelclrawE[iseljet] = elsupcl_rawE[nearest];
            }}}
      

      selpfjetAK8tau21[iseljet] = pfjetAK8tau21[ijet];
      selpfjetAK8tau32[iseljet] = pfjetAK8tau32[ijet];
      selpfjetAK8sub1mass[iseljet] = pfjetAK8sub1mass[ijet];
      selpfjetAK8sub1btag[iseljet] = pfjetAK8sub1btag[ijet];
      selpfjetAK8sub1hadfrac[iseljet] =  pfjetAK8sub1hadfrac[ijet];
      selpfjetAK8sub1emfrac[iseljet] = pfjetAK8sub1emfrac[ijet];
      selpfjetAK8sub2mass[iseljet] = pfjetAK8sub2mass[ijet];
      selpfjetAK8sub2btag[iseljet] =  pfjetAK8sub2btag[ijet];
      selpfjetAK8sub2hadfrac[iseljet] = pfjetAK8sub2hadfrac[ijet];
      selpfjetAK8sub2emfrac[iseljet] = pfjetAK8sub2emfrac[ijet];
      selpfjetAK8subbtag[iseljet] = pfjetAK8subbtag[ijet];
      selpfjetAK8subhaddiff[iseljet] =  pfjetAK8subhaddiff[ijet];
      selpfjetAK8subemdiff[iseljet] = pfjetAK8subemdiff[ijet];
      selpfjetAK8subptdiff[iseljet] = pfjetAK8subptdiff[ijet];
      selpfjetAK8_bbyW_E[iseljet] = pfjetAK8_bbyW_E[ijet];
      selpfjetAK8_Kfactor[iseljet] = pfjetAK8_Kfactor[ijet];
      selpfjetAK8_Rnew[iseljet] = pfjetAK8_Rnew[ijet];
      selpfjetAK8haselectron[iseljet] =  pfjetAK8haselectron[ijet];
      selpfjetAK8hasmuon[iseljet] =  pfjetAK8hasmuon[ijet];
      selpfjetAK8hasqg[iseljet] =  pfjetAK8hasqg[ijet];
      selpfjetAK8hasb[iseljet] =  pfjetAK8hasb[ijet];
      selpfjetAK8hashadtop[iseljet] =  pfjetAK8hashadtop[ijet];
      selpfjetAK8hasleptop[iseljet] = pfjetAK8hasleptop[ijet];
      selpfjetAK8hastop[iseljet] = pfjetAK8hastop[ijet];
      selpfjetAK8hashadtop_alldecay[iseljet] = pfjetAK8hashadtop_alldecay[ijet];
      selpfjetAK8hasleptop_alldecay[iseljet] = pfjetAK8hasleptop_alldecay[ijet];
      selpfjetAK8re_tvsb[iseljet] = pfjetAK8re_tvsb[ijet];
      selpfjetAK8rnu_tvsb[iseljet] = pfjetAK8rnu_tvsb[ijet];
      
      iseljet++;
      if(iseljet>=njetmxAK8) break;
      
    }	
    
  }
  npfjetAK8_tmu = iseljet;
  //Tout2->Fill();
  
  iseljet = 0;
  npfjetAK8_thad = 0;
  
  for(int ijet=0; ijet< npfjetAK8; ijet++){
    
    if(ijet>(nmaxjet-1)) break;
    
    bool thad_cond = false;
    thad_cond = (pfjetAK8hashadtop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hashadtop_alldecay[ijet]);
    
    if(thad_cond){
      
      selpfjetAK8pt[iseljet] = pfjetAK8pt[ijet];
      selpfjetAK8y[iseljet] = pfjetAK8y[ijet];
      selpfjetAK8mass[iseljet] = pfjetAK8mass[ijet];
      selpfjetAK8phi[iseljet] = pfjetAK8phi[ijet];
      selpfjetAK8btag_CMVA[iseljet] = pfjetAK8btag_CMVA[ijet];
      selpfjetAK8btag_CSV[iseljet] = pfjetAK8btag_CSV[ijet];
      selpfjetAK8btag_DeepCSV[iseljet] = pfjetAK8btag_DeepCSV[ijet];
      selpfjetAK8matchAK4deepb[iseljet] = pfjetAK8matchAK4deepb[ijet];
      selpfjetAK8DeepTag_TvsQCD[iseljet] =  pfjetAK8DeepTag_TvsQCD[ijet];
      selpfjetAK8DeepTag_WvsQCD[iseljet] = pfjetAK8DeepTag_WvsQCD[ijet];
      selpfjetAK8DeepTag_ZvsQCD[iseljet] = pfjetAK8DeepTag_ZvsQCD[ijet];
      selpfjetAK8CHF[iseljet] = pfjetAK8CHF[ijet];
      selpfjetAK8NHF[iseljet] = pfjetAK8NHF[ijet];
      selpfjetAK8CEMF[iseljet] = pfjetAK8CEMF[ijet];
      selpfjetAK8NEMF[iseljet] = pfjetAK8NEMF[ijet];
      selpfjetAK8MUF[iseljet] = pfjetAK8MUF[ijet];
      selpfjetAK8HOF[iseljet] = pfjetAK8HOF[ijet];
      selpfjetAK8HadF[iseljet] = pfjetAK8HadF[ijet];
      selpfjetAK8NHadF[iseljet] = pfjetAK8NHadF[ijet];
      selpfjetAK8EmF[iseljet] = pfjetAK8EmF[ijet];
      selpfjetAK8neuemfrac[iseljet] = pfjetAK8neuemfrac[ijet];
      selpfjetAK8neunhadfrac[iseljet] = pfjetAK8neunhadfrac[ijet];
      selpfjetAK8CHM[iseljet] = pfjetAK8CHM[ijet];
      selpfjetAK8NHM[iseljet] = pfjetAK8NHM[ijet];
      selpfjetAK8CEMM[iseljet] = pfjetAK8CEMM[ijet];
      selpfjetAK8NEMM[iseljet] =  pfjetAK8NEMM[ijet];
      selpfjetAK8MUM[iseljet] = pfjetAK8MUM[ijet];
      selpfjetAK8Neucons[iseljet] = pfjetAK8Neucons[ijet];
      selpfjetAK8Chcons[iseljet] = pfjetAK8Chcons[ijet] ;
      selpfjetAK8chrad[iseljet] =  pfjetAK8chrad[ijet];
      selpfjetAK8pTD[iseljet] = pfjetAK8pTD[ijet];
      selpfjetAK8sdmass[iseljet] = pfjetAK8sdmass[ijet];
      
      selpfjetAK8elsubjptrat[iseljet] = pfjetAK8elsubjptrat[ijet];
      selpfjetAK8elinsubpt[iseljet] = fabs(pfjetAK8elinsubpt[ijet]);
      selpfjetAK8elinsubeta[iseljet] = pfjetAK8elinsubeta[ijet];
      selpfjetAK8elinsubphi[iseljet] = pfjetAK8elinsubphi[ijet];
      selpfjetAK8elinsubjpt[iseljet] = pfjetAK8elinsubjpt[ijet];
      selpfjetAK8elinsubjeta[iseljet] = pfjetAK8elinsubjeta[ijet];
      selpfjetAK8elinsubjphi[iseljet] = pfjetAK8elinsubjphi[ijet];

      selpfjetAK8matchedelID[iseljet] = -100;
      selpfjetAK8matchedelpt[iseljet] = -100;
      selpfjetAK8matchedeleta[iseljet] = -100;
      selpfjetAK8matchedelphi[iseljet] = -100;
      selpfjetAK8matchedelE[iseljet] = -100;
      selpfjetAK8matchedeldxy[iseljet] = -100;
      selpfjetAK8matchedeldxy_sv[iseljet] = -100;
      selpfjetAK8matchedelcleta[iseljet] = -100;
      selpfjetAK8matchedelclphi[iseljet] = -100;
      selpfjetAK8matchedelclrawE[iseljet] = -100;

      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
        {
          if (nelecs > 0) {
            float dR_min(0.4); int nearest(-1);
            for(int el=0; el<nelecs; el++){
              float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
              if (dR < dR_min) {
                dR_min = dR;
                nearest = el;
              }}
            if (nearest >= 0) {
              selpfjetAK8matchedelID[iseljet] = elmvaid_noIso[nearest];
              selpfjetAK8matchedelpt[iseljet] = fabs(elpt[nearest]);
              selpfjetAK8matchedeleta[iseljet] = eleta[nearest];
              selpfjetAK8matchedelphi[iseljet] = elphi[nearest];
              selpfjetAK8matchedelE[iseljet] = ele[nearest];
              selpfjetAK8matchedeldxy[iseljet] = eldxy[nearest];
              selpfjetAK8matchedeldxy_sv[iseljet] = eldxy_sv[nearest];
              selpfjetAK8matchedelcleta[iseljet] = elsupcl_eta[nearest];
              selpfjetAK8matchedelclphi[iseljet] = elsupcl_phi[nearest];
              selpfjetAK8matchedelclrawE[iseljet] = elsupcl_rawE[nearest];
            }}}
      
      
      selpfjetAK8tau21[iseljet] = pfjetAK8tau21[ijet];
      selpfjetAK8tau32[iseljet] = pfjetAK8tau32[ijet];
      selpfjetAK8sub1mass[iseljet] = pfjetAK8sub1mass[ijet];
      selpfjetAK8sub1btag[iseljet] = pfjetAK8sub1btag[ijet];
      selpfjetAK8sub1hadfrac[iseljet] =  pfjetAK8sub1hadfrac[ijet];
      selpfjetAK8sub1emfrac[iseljet] = pfjetAK8sub1emfrac[ijet];
      selpfjetAK8sub2mass[iseljet] = pfjetAK8sub2mass[ijet];
      selpfjetAK8sub2btag[iseljet] =  pfjetAK8sub2btag[ijet];
      selpfjetAK8sub2hadfrac[iseljet] = pfjetAK8sub2hadfrac[ijet];
      selpfjetAK8sub2emfrac[iseljet] = pfjetAK8sub2emfrac[ijet];
      selpfjetAK8subbtag[iseljet] = pfjetAK8subbtag[ijet];
      selpfjetAK8subhaddiff[iseljet] =  pfjetAK8subhaddiff[ijet];
      selpfjetAK8subemdiff[iseljet] = pfjetAK8subemdiff[ijet];
      selpfjetAK8subptdiff[iseljet] = pfjetAK8subptdiff[ijet];
      selpfjetAK8_bbyW_E[iseljet] = pfjetAK8_bbyW_E[ijet];
      selpfjetAK8_Kfactor[iseljet] = pfjetAK8_Kfactor[ijet];
      selpfjetAK8_Rnew[iseljet] = pfjetAK8_Rnew[ijet];
      selpfjetAK8haselectron[iseljet] =  pfjetAK8haselectron[ijet];
      selpfjetAK8hasmuon[iseljet] =  pfjetAK8hasmuon[ijet];
      selpfjetAK8hasqg[iseljet] =  pfjetAK8hasqg[ijet];
      selpfjetAK8hasb[iseljet] =  pfjetAK8hasb[ijet];
      selpfjetAK8hashadtop[iseljet] =  pfjetAK8hashadtop[ijet];
      selpfjetAK8hasleptop[iseljet] = pfjetAK8hasleptop[ijet];
      selpfjetAK8hastop[iseljet] = pfjetAK8hastop[ijet];
      selpfjetAK8hashadtop_alldecay[iseljet] = pfjetAK8hashadtop_alldecay[ijet];
      selpfjetAK8hasleptop_alldecay[iseljet] = pfjetAK8hasleptop_alldecay[ijet];
      selpfjetAK8re_tvsb[iseljet] = pfjetAK8re_tvsb[ijet];
      selpfjetAK8rnu_tvsb[iseljet] = pfjetAK8rnu_tvsb[ijet];
      
      iseljet++;
      if(iseljet>=njetmxAK8) break;
    }	
    
  }
  npfjetAK8_thad = iseljet;
  //Tout3->Fill();
 
 
 
  iseljet = 0;
  npfjetAK8_qg = 0;
  
  for(int ijet=0; ijet< npfjetAK8; ijet++){
    
    if(ijet>(nmaxjet-1)) break;
    
    bool qg_cond = false;
    qg_cond = (pfjetAK8hasqg[ijet] && !(pfjetAK8hashadtop[ijet]) && !(pfjetAK8hasleptop[ijet]) && !(pfjetAK8hastop[ijet]));
    
    if(qg_cond){
      
      selpfjetAK8pt[iseljet] = pfjetAK8pt[ijet];
      selpfjetAK8y[iseljet] = pfjetAK8y[ijet];
      selpfjetAK8mass[iseljet] = pfjetAK8mass[ijet];
      selpfjetAK8phi[iseljet] = pfjetAK8phi[ijet];
      selpfjetAK8btag_CMVA[iseljet] = pfjetAK8btag_CMVA[ijet];
      selpfjetAK8btag_CSV[iseljet] = pfjetAK8btag_CSV[ijet];
      selpfjetAK8btag_DeepCSV[iseljet] = pfjetAK8btag_DeepCSV[ijet];
      selpfjetAK8matchAK4deepb[iseljet] = pfjetAK8matchAK4deepb[ijet];
      selpfjetAK8DeepTag_TvsQCD[iseljet] =  pfjetAK8DeepTag_TvsQCD[ijet];
      selpfjetAK8DeepTag_WvsQCD[iseljet] = pfjetAK8DeepTag_WvsQCD[ijet];
      selpfjetAK8DeepTag_ZvsQCD[iseljet] = pfjetAK8DeepTag_ZvsQCD[ijet];
      selpfjetAK8CHF[iseljet] = pfjetAK8CHF[ijet];
      selpfjetAK8NHF[iseljet] = pfjetAK8NHF[ijet];
      selpfjetAK8CEMF[iseljet] = pfjetAK8CEMF[ijet];
      selpfjetAK8NEMF[iseljet] = pfjetAK8NEMF[ijet];
      selpfjetAK8MUF[iseljet] = pfjetAK8MUF[ijet];
      selpfjetAK8HOF[iseljet] = pfjetAK8HOF[ijet];
      selpfjetAK8HadF[iseljet] = pfjetAK8HadF[ijet];
      selpfjetAK8NHadF[iseljet] = pfjetAK8NHadF[ijet];
      selpfjetAK8EmF[iseljet] = pfjetAK8EmF[ijet];
      selpfjetAK8neuemfrac[iseljet] = pfjetAK8neuemfrac[ijet];
      selpfjetAK8neunhadfrac[iseljet] = pfjetAK8neunhadfrac[ijet];
      selpfjetAK8CHM[iseljet] = pfjetAK8CHM[ijet];
      selpfjetAK8NHM[iseljet] = pfjetAK8NHM[ijet];
      selpfjetAK8CEMM[iseljet] = pfjetAK8CEMM[ijet];
      selpfjetAK8NEMM[iseljet] =  pfjetAK8NEMM[ijet];
      selpfjetAK8MUM[iseljet] = pfjetAK8MUM[ijet];
      selpfjetAK8Neucons[iseljet] = pfjetAK8Neucons[ijet];
      selpfjetAK8Chcons[iseljet] = pfjetAK8Chcons[ijet] ;
      selpfjetAK8chrad[iseljet] =  pfjetAK8chrad[ijet];
      selpfjetAK8pTD[iseljet] = pfjetAK8pTD[ijet];
      selpfjetAK8sdmass[iseljet] = pfjetAK8sdmass[ijet];
      
      selpfjetAK8elsubjptrat[iseljet] = pfjetAK8elsubjptrat[ijet];
      selpfjetAK8elinsubpt[iseljet] = fabs(pfjetAK8elinsubpt[ijet]);
      selpfjetAK8elinsubeta[iseljet] = pfjetAK8elinsubeta[ijet];
      selpfjetAK8elinsubphi[iseljet] = pfjetAK8elinsubphi[ijet];
      selpfjetAK8elinsubjpt[iseljet] = pfjetAK8elinsubjpt[ijet];
      selpfjetAK8elinsubjeta[iseljet] = pfjetAK8elinsubjeta[ijet];
      selpfjetAK8elinsubjphi[iseljet] = pfjetAK8elinsubjphi[ijet];

      selpfjetAK8matchedelID[iseljet] = -100;
      selpfjetAK8matchedelpt[iseljet] = -100;
      selpfjetAK8matchedeleta[iseljet] = -100;
      selpfjetAK8matchedelphi[iseljet] = -100;
      selpfjetAK8matchedelE[iseljet] = -100;
      selpfjetAK8matchedeldxy[iseljet] = -100;
      selpfjetAK8matchedeldxy_sv[iseljet] = -100;
      selpfjetAK8matchedelcleta[iseljet] = -100;
      selpfjetAK8matchedelclphi[iseljet] = -100;
      selpfjetAK8matchedelclrawE[iseljet] = -100;

      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
        {
          if (nelecs > 0) {
            float dR_min(0.4); int nearest(-1);
            for(int el=0; el<nelecs; el++){
              float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
              if (dR < dR_min) {
                dR_min = dR;
                nearest = el;
              }}
            if (nearest >= 0) {
              selpfjetAK8matchedelID[iseljet] = elmvaid_noIso[nearest];
              selpfjetAK8matchedelpt[iseljet] = fabs(elpt[nearest]);
              selpfjetAK8matchedeleta[iseljet] = eleta[nearest];
              selpfjetAK8matchedelphi[iseljet] = elphi[nearest];
              selpfjetAK8matchedelE[iseljet] = ele[nearest];
              selpfjetAK8matchedeldxy[iseljet] = eldxy[nearest];
              selpfjetAK8matchedeldxy_sv[iseljet] = eldxy_sv[nearest];
              selpfjetAK8matchedelcleta[iseljet] = elsupcl_eta[nearest];
              selpfjetAK8matchedelclphi[iseljet] = elsupcl_phi[nearest];
              selpfjetAK8matchedelclrawE[iseljet] = elsupcl_rawE[nearest];
            }}}
      
      selpfjetAK8tau21[iseljet] = pfjetAK8tau21[ijet];
      selpfjetAK8tau32[iseljet] = pfjetAK8tau32[ijet];
      selpfjetAK8sub1mass[iseljet] = pfjetAK8sub1mass[ijet];
      selpfjetAK8sub1btag[iseljet] = pfjetAK8sub1btag[ijet];
      selpfjetAK8sub1hadfrac[iseljet] =  pfjetAK8sub1hadfrac[ijet];
      selpfjetAK8sub1emfrac[iseljet] = pfjetAK8sub1emfrac[ijet];
      selpfjetAK8sub2mass[iseljet] = pfjetAK8sub2mass[ijet];
      selpfjetAK8sub2btag[iseljet] =  pfjetAK8sub2btag[ijet];
      selpfjetAK8sub2hadfrac[iseljet] = pfjetAK8sub2hadfrac[ijet];
      selpfjetAK8sub2emfrac[iseljet] = pfjetAK8sub2emfrac[ijet];
      selpfjetAK8subbtag[iseljet] = pfjetAK8subbtag[ijet];
      selpfjetAK8subhaddiff[iseljet] =  pfjetAK8subhaddiff[ijet];
      selpfjetAK8subemdiff[iseljet] = pfjetAK8subemdiff[ijet];
      selpfjetAK8subptdiff[iseljet] = pfjetAK8subptdiff[ijet];
      selpfjetAK8_bbyW_E[iseljet] = pfjetAK8_bbyW_E[ijet];
      selpfjetAK8_Kfactor[iseljet] = pfjetAK8_Kfactor[ijet];
      selpfjetAK8_Rnew[iseljet] = pfjetAK8_Rnew[ijet];
      selpfjetAK8haselectron[iseljet] =  pfjetAK8haselectron[ijet];
      selpfjetAK8hasmuon[iseljet] =  pfjetAK8hasmuon[ijet];
      selpfjetAK8hasqg[iseljet] =  pfjetAK8hasqg[ijet];
      selpfjetAK8hasb[iseljet] =  pfjetAK8hasb[ijet];
      selpfjetAK8hashadtop[iseljet] =  pfjetAK8hashadtop[ijet];
      selpfjetAK8hasleptop[iseljet] = pfjetAK8hasleptop[ijet];
      selpfjetAK8hastop[iseljet] = pfjetAK8hastop[ijet];
      selpfjetAK8re_tvsb[iseljet] = pfjetAK8re_tvsb[ijet];
      selpfjetAK8rnu_tvsb[iseljet] = pfjetAK8rnu_tvsb[ijet];
      
      iseljet++;
      if(iseljet>=njetmxAK8) break;
    }	
    
  }
  npfjetAK8_qg = iseljet;
  Tout4->Fill();	
  
  iseljet = 0;
  npfjetAK8_b = 0;

  for(int ijet=0; ijet< npfjetAK8; ijet++){
    
    if(ijet>(nmaxjet-1)) break;
    
    bool b_cond = false;
    b_cond = (pfjetAK8hasb[ijet] && !(pfjetAK8hashadtop[ijet]) && !(pfjetAK8hasleptop[ijet]) && !(pfjetAK8hastop[ijet]));
    
    if(b_cond){
      
      selpfjetAK8pt[iseljet] = pfjetAK8pt[ijet];
      selpfjetAK8y[iseljet] = pfjetAK8y[ijet];
      selpfjetAK8mass[iseljet] = pfjetAK8mass[ijet];
      selpfjetAK8phi[iseljet] = pfjetAK8phi[ijet];
      selpfjetAK8btag_CMVA[iseljet] = pfjetAK8btag_CMVA[ijet];
      selpfjetAK8btag_CSV[iseljet] = pfjetAK8btag_CSV[ijet];
      selpfjetAK8btag_DeepCSV[iseljet] = pfjetAK8btag_DeepCSV[ijet];
      selpfjetAK8matchAK4deepb[iseljet] = pfjetAK8matchAK4deepb[ijet];
      selpfjetAK8DeepTag_TvsQCD[iseljet] =  pfjetAK8DeepTag_TvsQCD[ijet];
      selpfjetAK8DeepTag_WvsQCD[iseljet] = pfjetAK8DeepTag_WvsQCD[ijet];
      selpfjetAK8DeepTag_ZvsQCD[iseljet] = pfjetAK8DeepTag_ZvsQCD[ijet];
      selpfjetAK8CHF[iseljet] = pfjetAK8CHF[ijet];
      selpfjetAK8NHF[iseljet] = pfjetAK8NHF[ijet];
      selpfjetAK8CEMF[iseljet] = pfjetAK8CEMF[ijet];
      selpfjetAK8NEMF[iseljet] = pfjetAK8NEMF[ijet];
      selpfjetAK8MUF[iseljet] = pfjetAK8MUF[ijet];
      selpfjetAK8HOF[iseljet] = pfjetAK8HOF[ijet];
      selpfjetAK8HadF[iseljet] = pfjetAK8HadF[ijet];
      selpfjetAK8NHadF[iseljet] = pfjetAK8NHadF[ijet];
      selpfjetAK8EmF[iseljet] = pfjetAK8EmF[ijet];
      selpfjetAK8neuemfrac[iseljet] = pfjetAK8neuemfrac[ijet];
      selpfjetAK8neunhadfrac[iseljet] = pfjetAK8neunhadfrac[ijet];
      selpfjetAK8CHM[iseljet] = pfjetAK8CHM[ijet];
      selpfjetAK8NHM[iseljet] = pfjetAK8NHM[ijet];
      selpfjetAK8CEMM[iseljet] = pfjetAK8CEMM[ijet];
      selpfjetAK8NEMM[iseljet] =  pfjetAK8NEMM[ijet];
      selpfjetAK8MUM[iseljet] = pfjetAK8MUM[ijet];
      selpfjetAK8Neucons[iseljet] = pfjetAK8Neucons[ijet];
      selpfjetAK8Chcons[iseljet] = pfjetAK8Chcons[ijet] ;
      selpfjetAK8chrad[iseljet] =  pfjetAK8chrad[ijet];
      selpfjetAK8pTD[iseljet] = pfjetAK8pTD[ijet];
      selpfjetAK8sdmass[iseljet] = pfjetAK8sdmass[ijet];
      
      selpfjetAK8elsubjptrat[iseljet] = pfjetAK8elsubjptrat[ijet];
      selpfjetAK8elinsubpt[iseljet] = fabs(pfjetAK8elinsubpt[ijet]);
      selpfjetAK8elinsubeta[iseljet] = pfjetAK8elinsubeta[ijet];
      selpfjetAK8elinsubphi[iseljet] = pfjetAK8elinsubphi[ijet];
      selpfjetAK8elinsubjpt[iseljet] = pfjetAK8elinsubjpt[ijet];
      selpfjetAK8elinsubjeta[iseljet] = pfjetAK8elinsubjeta[ijet];
      selpfjetAK8elinsubjphi[iseljet] = pfjetAK8elinsubjphi[ijet];

      selpfjetAK8matchedelID[iseljet] = -100;
      selpfjetAK8matchedelpt[iseljet] = -100;
      selpfjetAK8matchedeleta[iseljet] = -100;
      selpfjetAK8matchedelphi[iseljet] = -100;
      selpfjetAK8matchedelE[iseljet] = -100;
      selpfjetAK8matchedeldxy[iseljet] = -100;
      selpfjetAK8matchedeldxy_sv[iseljet] = -100;
      selpfjetAK8matchedelcleta[iseljet] = -100;
      selpfjetAK8matchedelclphi[iseljet] = -100;
      selpfjetAK8matchedelclrawE[iseljet] = -100;

      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
        {
	  //float dR_min(0.4); int nearest(-1);
          if (nelecs > 0) {
            float dR_min(0.4); int nearest(-1);
            for(int el=0; el<nelecs; el++){
              float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
              if (dR < dR_min) {
                dR_min = dR;
                nearest = el;
              }}
            if (nearest >= 0) {
              selpfjetAK8matchedelID[iseljet] = elmvaid_noIso[nearest];
              selpfjetAK8matchedelpt[iseljet] = fabs(elpt[nearest]);
              selpfjetAK8matchedeleta[iseljet] = eleta[nearest];
              selpfjetAK8matchedelphi[iseljet] = elphi[nearest];
              selpfjetAK8matchedelE[iseljet] = ele[nearest];
              selpfjetAK8matchedeldxy[iseljet] = eldxy[nearest];
              selpfjetAK8matchedeldxy_sv[iseljet] = eldxy_sv[nearest];
              selpfjetAK8matchedelcleta[iseljet] = elsupcl_eta[nearest];
              selpfjetAK8matchedelclphi[iseljet] = elsupcl_phi[nearest];
              selpfjetAK8matchedelclrawE[iseljet] = elsupcl_rawE[nearest];
            }}}
      /*
      if (ijet == 0) {                                                                                                                                                                                            
	if (selpfjetAK8matchedelclrawE[iseljet]!= -100 && selpfjetAK8elinsubpt[iseljet] > 25.0 && selpfjetAK8pt[iseljet] > 400.0 && selpfjetAK8matchedelID[iseljet] == 1) {                                      
	  ht->Fill(selpfjetAK8matchedelclrawE[iseljet],weight);                                                                                                                                                  
	  hteldxy->Fill(selpfjetAK8matchedeldxy[iseljet],weight);                                                                                                                                                
	  hteldxy_sv->Fill(selpfjetAK8matchedeldxy_sv[iseljet],weight);                                                                                                                                          
 	  htelcleta->Fill(selpfjetAK8matchedelcleta[iseljet],weight);                                                                                                                                            
	  htelsubptrat->Fill(selpfjetAK8elsubjptrat[iseljet],weight);                                                                                                                                            
	  if (pfjetAK8re_tvsb[iseljet] > 0.42) {                                                                                                                                                                 
	    htre->Fill(selpfjetAK8matchedelclrawE[iseljet],weight);                                                                                                                                              
	    htreeldxy->Fill(selpfjetAK8matchedeldxy[iseljet],weight);                                                                                                                                            
	    htreeldxy_sv->Fill(selpfjetAK8matchedeldxy_sv[iseljet],weight);                                                                                                                                      
	    htreelcleta->Fill(selpfjetAK8matchedelcleta[iseljet],weight);                                                                                                                                        
	    htreelsubptrat->Fill(selpfjetAK8elsubjptrat[iseljet],weight);                                                                                                                                        
	    }                                                                                                                                                                                                      
	    }                                                                                                                              }
      */
      selpfjetAK8tau21[iseljet] = pfjetAK8tau21[ijet];
      selpfjetAK8tau32[iseljet] = pfjetAK8tau32[ijet];
      selpfjetAK8sub1mass[iseljet] = pfjetAK8sub1mass[ijet];
      selpfjetAK8sub1btag[iseljet] = pfjetAK8sub1btag[ijet];
      selpfjetAK8sub1hadfrac[iseljet] =  pfjetAK8sub1hadfrac[ijet];
      selpfjetAK8sub1emfrac[iseljet] = pfjetAK8sub1emfrac[ijet];
      selpfjetAK8sub2mass[iseljet] = pfjetAK8sub2mass[ijet];
      selpfjetAK8sub2btag[iseljet] =  pfjetAK8sub2btag[ijet];
      selpfjetAK8sub2hadfrac[iseljet] = pfjetAK8sub2hadfrac[ijet];
      selpfjetAK8sub2emfrac[iseljet] = pfjetAK8sub2emfrac[ijet];
      selpfjetAK8subbtag[iseljet] = pfjetAK8subbtag[ijet];
      selpfjetAK8subhaddiff[iseljet] =  pfjetAK8subhaddiff[ijet];
      selpfjetAK8subemdiff[iseljet] = pfjetAK8subemdiff[ijet];
      selpfjetAK8subptdiff[iseljet] = pfjetAK8subptdiff[ijet];
      selpfjetAK8_bbyW_E[iseljet] = pfjetAK8_bbyW_E[ijet];
      selpfjetAK8_Kfactor[iseljet] = pfjetAK8_Kfactor[ijet];
      selpfjetAK8_Rnew[iseljet] = selpfjetAK8_Rnew[ijet];
      selpfjetAK8haselectron[iseljet] =  pfjetAK8haselectron[ijet];
      selpfjetAK8hasmuon[iseljet] =  pfjetAK8hasmuon[ijet];
      selpfjetAK8hasqg[iseljet] =  pfjetAK8hasqg[ijet];
      selpfjetAK8hasb[iseljet] =  pfjetAK8hasb[ijet];
      selpfjetAK8hashadtop[iseljet] =  pfjetAK8hashadtop[ijet];
      selpfjetAK8hasleptop[iseljet] = pfjetAK8hasleptop[ijet];
      selpfjetAK8hastop[iseljet] = pfjetAK8hastop[ijet];
      selpfjetAK8re_tvsb[iseljet] = pfjetAK8re_tvsb[ijet];
      selpfjetAK8rnu_tvsb[iseljet] = pfjetAK8rnu_tvsb[ijet];
      
      iseljet++;
      if(iseljet>=njetmxAK8) break;
    }	
    
  }
  npfjetAK8_b = iseljet;
  Tout5->Fill();	
  /*
  for(int z=1; z<=iseljet; ++z){                                                                                                                                                                                 
    if (z == 1) {                                                                                                                                                                                                
      hljetpt->Fill(selpfjetAK8pt[z-1],weight);                                                                                                                                                                  
      hljety->Fill(selpfjetAK8y[z-1],weight);                                                                                                                                                                    
      hljetphi->Fill(selpfjetAK8phi[z-1],weight);                                                                                                                                                                
      hljetmass->Fill(selpfjetAK8mass[z-1],weight);                                                                                                                                                              
      if (selpfjetAK8matchedelclrawE[z-1]!= -100 && selpfjetAK8pt[z-1] > 400.) {                                                                                                                                
        helpt->Fill(selpfjetAK8elinsubpt[z-1],weight);                                                                                                                                                           
        if (selpfjetAK8re_tvsb[z-1] > 0.42) helpt_gre->Fill(selpfjetAK8elinsubpt[z-1],weight);                                                                                                                   
        if (selpfjetAK8matchedelID[z-1] == 1) {                                                                                                                                                                  
          helptID->Fill(selpfjetAK8elinsubpt[z-1],weight);                                                                                                                                                       
          if (selpfjetAK8re_tvsb[z-1] > 0.42) helptID_gre->Fill(selpfjetAK8elinsubpt[z-1],weight);                                                                                                               
        }
      }
    }
  }
  */
  
  iseljet = 0;
  npfjetAK8_all = 0;
  
  //TString str1 = TString::Format("npfjetAK8 %d \n",npfjetAK8);                                           
  //if(gProofServ) gProofServ->SendAsynMessage(str1);


  for(int ijet=0; ijet< npfjetAK8; ijet++){
    
    if(ijet>(nmaxjet-1)) break;
    /*
    selpfjetAK8pt[iseljet] = pfjetAK8pt[ijet];
    selpfjetAK8y[iseljet] = pfjetAK8y[ijet];
    selpfjetAK8mass[iseljet] = pfjetAK8mass[ijet];
    selpfjetAK8phi[iseljet] = pfjetAK8phi[ijet];
    
      selpfjetAK8btag_CMVA[iseljet] = pfjetAK8btag_CMVA[ijet];
      selpfjetAK8btag_CSV[iseljet] = pfjetAK8btag_CSV[ijet];
      selpfjetAK8btag_DeepCSV[iseljet] = pfjetAK8btag_DeepCSV[ijet];
      selpfjetAK8matchAK4deepb[iseljet] = pfjetAK8matchAK4deepb[ijet];
      selpfjetAK8DeepTag_TvsQCD[iseljet] =  pfjetAK8DeepTag_TvsQCD[ijet];
      selpfjetAK8DeepTag_WvsQCD[iseljet] = pfjetAK8DeepTag_WvsQCD[ijet];
      selpfjetAK8DeepTag_ZvsQCD[iseljet] = pfjetAK8DeepTag_ZvsQCD[ijet];
      selpfjetAK8CHF[iseljet] = pfjetAK8CHF[ijet];
      selpfjetAK8NHF[iseljet] = pfjetAK8NHF[ijet];
      selpfjetAK8CEMF[iseljet] = pfjetAK8CEMF[ijet];
      selpfjetAK8NEMF[iseljet] = pfjetAK8NEMF[ijet];
      selpfjetAK8MUF[iseljet] = pfjetAK8MUF[ijet];
      selpfjetAK8HOF[iseljet] = pfjetAK8HOF[ijet];
      selpfjetAK8HadF[iseljet] = pfjetAK8HadF[ijet];
      selpfjetAK8NHadF[iseljet] = pfjetAK8NHadF[ijet];
      selpfjetAK8EmF[iseljet] = pfjetAK8EmF[ijet];
      selpfjetAK8neuemfrac[iseljet] = pfjetAK8neuemfrac[ijet];
      selpfjetAK8neunhadfrac[iseljet] = pfjetAK8neunhadfrac[ijet];
      selpfjetAK8CHM[iseljet] = pfjetAK8CHM[ijet];
      selpfjetAK8NHM[iseljet] = pfjetAK8NHM[ijet];
      selpfjetAK8CEMM[iseljet] = pfjetAK8CEMM[ijet];
      selpfjetAK8NEMM[iseljet] =  pfjetAK8NEMM[ijet];
      selpfjetAK8EEM[iseljet] = pfjetAK8EEM[ijet];
      selpfjetAK8MUM[iseljet] = pfjetAK8MUM[ijet];
      selpfjetAK8Neucons[iseljet] = pfjetAK8Neucons[ijet];
      selpfjetAK8Chcons[iseljet] = pfjetAK8Chcons[ijet] ;
      selpfjetAK8chrad[iseljet] =  pfjetAK8chrad[ijet];
      selpfjetAK8pTD[iseljet] = pfjetAK8pTD[ijet];
      selpfjetAK8sdmass[iseljet] = pfjetAK8sdmass[ijet];
      selpfjetAK8elsubjptrat[iseljet] = pfjetAK8elsubjptrat[ijet];
      selpfjetAK8elinsubpt[iseljet] = fabs(pfjetAK8elinsubpt[ijet]);
      selpfjetAK8elinsubeta[iseljet] = pfjetAK8elinsubeta[ijet];
      selpfjetAK8elinsubphi[iseljet] = pfjetAK8elinsubphi[ijet];
      selpfjetAK8elinsubjpt[iseljet] = pfjetAK8elinsubjpt[ijet];
      selpfjetAK8elinsubjeta[iseljet] = pfjetAK8elinsubjeta[ijet];
      selpfjetAK8elinsubjphi[iseljet] = pfjetAK8elinsubjphi[ijet];
      
      selpfjetAK8matchedelID[iseljet] = -100;
      selpfjetAK8matchedelpt[iseljet] = -100;
      selpfjetAK8matchedeleta[iseljet] = -100;
      selpfjetAK8matchedelphi[iseljet] = -100;
      selpfjetAK8matchedelE[iseljet] = -100;
      selpfjetAK8matchedeldxy[iseljet] = -100;
      selpfjetAK8matchedeldxy_sv[iseljet] = -100;
      selpfjetAK8matchedelcleta[iseljet] = -100;
      selpfjetAK8matchedelclphi[iseljet] = -100;
      selpfjetAK8matchedelclrawE[iseljet] = -100;
      
      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
      {
	if (nelecs > 0) {
	float dR_min(0.4); int nearest(-1);
	for(int el=0; el<nelecs; el++){
	float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
	if (dR < dR_min) {
	dR_min = dR;
	nearest = el;
	}}
	if (nearest >= 0) {
	selpfjetAK8matchedelID[iseljet] = elmvaid_noIso[nearest];
	selpfjetAK8matchedelpt[iseljet] = fabs(elpt[nearest]);
	selpfjetAK8matchedeleta[iseljet] = eleta[nearest];
	selpfjetAK8matchedelphi[iseljet] = elphi[nearest];
	selpfjetAK8matchedelE[iseljet] = ele[nearest];
	selpfjetAK8matchedeldxy[iseljet] = eldxy[nearest];
	selpfjetAK8matchedeldxy_sv[iseljet] = eldxy_sv[nearest];
	selpfjetAK8matchedelcleta[iseljet] = elsupcl_eta[nearest];
	selpfjetAK8matchedelclphi[iseljet] = elsupcl_phi[nearest];
	selpfjetAK8matchedelclrawE[iseljet] = elsupcl_rawE[nearest];
	}}}
    
    selpfjetAK8tau21[iseljet] = pfjetAK8tau21[ijet];
    selpfjetAK8tau32[iseljet] = pfjetAK8tau32[ijet];
    selpfjetAK8sub1mass[iseljet] = pfjetAK8sub1mass[ijet];
    selpfjetAK8sub1btag[iseljet] = pfjetAK8sub1btag[ijet];
    selpfjetAK8sub1hadfrac[iseljet] =  pfjetAK8sub1hadfrac[ijet];
    selpfjetAK8sub1emfrac[iseljet] = pfjetAK8sub1emfrac[ijet];
    selpfjetAK8sub2mass[iseljet] = pfjetAK8sub2mass[ijet];
    selpfjetAK8sub2btag[iseljet] =  pfjetAK8sub2btag[ijet];
    selpfjetAK8sub2hadfrac[iseljet] = pfjetAK8sub2hadfrac[ijet];
    selpfjetAK8sub2emfrac[iseljet] = pfjetAK8sub2emfrac[ijet];
    selpfjetAK8subbtag[iseljet] = pfjetAK8subbtag[ijet];
    selpfjetAK8subhaddiff[iseljet] =  pfjetAK8subhaddiff[ijet];
    selpfjetAK8subemdiff[iseljet] = pfjetAK8subemdiff[ijet];
    selpfjetAK8subptdiff[iseljet] = pfjetAK8subptdiff[ijet];
    selpfjetAK8_bbyW_E[iseljet] = pfjetAK8_bbyW_E[ijet];
    selpfjetAK8_Kfactor[iseljet] = pfjetAK8_Kfactor[ijet];
    selpfjetAK8_Rnew[iseljet] = pfjetAK8_Rnew[ijet];
    selpfjetAK8haselectron[iseljet] =  pfjetAK8haselectron[ijet];
    selpfjetAK8hasmuon[iseljet] =  pfjetAK8hasmuon[ijet];
    selpfjetAK8hasqg[iseljet] =  pfjetAK8hasqg[ijet];
    selpfjetAK8hasb[iseljet] =  pfjetAK8hasb[ijet];
    selpfjetAK8hashadtop[iseljet] =  pfjetAK8hashadtop[ijet];
    selpfjetAK8hasleptop[iseljet] = pfjetAK8hasleptop[ijet];
    selpfjetAK8hastop[iseljet] = pfjetAK8hastop[ijet];
    selpfjetAK8hashadtop_alldecay[iseljet] = pfjetAK8hashadtop_alldecay[ijet];
    selpfjetAK8hasleptop_alldecay[iseljet] = pfjetAK8hasleptop_alldecay[ijet];
    selpfjetAK8re_tvsb[iseljet] = pfjetAK8re_tvsb[ijet];
    selpfjetAK8rnu_tvsb[iseljet] = pfjetAK8rnu_tvsb[ijet];
    */

    iseljet++;
    if(iseljet>=njetmxAK8) break;
    
  }

  npfjetAK8_all = iseljet;
	
  //Tout6->Fill();	
  
  #endif
  
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
