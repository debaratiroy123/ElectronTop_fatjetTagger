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
  //OutFile = new TProofOutputFile("testmutop_thadv2_Jan2021Corr_19UL18.root");
  OutFile = new TProofOutputFile("TTbar_Had.root");
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
  //Tout2->Branch("selpfjetAK8musubjptrat",selpfjetAK8musubjptrat,"selpfjetAK8musubjptrat[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8muinsubpt",selpfjetAK8muinsubpt,"selpfjetAK8muinsubpt[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8muinsubeta",selpfjetAK8muinsubeta,"selpfjetAK8muinsubeta[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8muinsubphi",selpfjetAK8muinsubphi,"selpfjetAK8muinsubphi[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8muinsubjpt",selpfjetAK8muinsubjpt,"selpfjetAK8muinsubjpt[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8muinsubjeta",selpfjetAK8muinsubjeta,"selpfjetAK8muinsujbeta[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8muinsubjphi",selpfjetAK8muinsubjphi,"selpfjetAK8muinsubjphi[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmupt",selpfjetAK8matchedmupt,"selpfjetAK8matchedmupt[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmueta",selpfjetAK8matchedmueta,"selpfjetAK8matchedmueta[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuphi",selpfjetAK8matchedmuphi,"selpfjetAK8matchedmuphi[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuE",selpfjetAK8matchedmuE,"selpfjetAK8matchedmuE[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8muinsubjmass",selpfjetAK8muinsubjmass,"selpfjetAK8muinsubjmass[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8muinsubptrat",selpfjetAK8muinsubptrat,"selpfjetAK8muinsubptrat[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8muinsubmassrat",selpfjetAK8muinsubmassrat,"selpfjetAK8muinsubmassrat[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8muinsubinvmass",selpfjetAK8muinsubinvmass,"selpfjetAK8muinsubinvmass[npfjetAK8_tmu]/F");

  Tout2->Branch("selpfjetAK8matchedmuonisLoose",selpfjetAK8matchedmuonisLoose,"selpfjetAK8matchedmuonisLoose[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuonisGoodGL",selpfjetAK8matchedmuonisGoodGL,"selpfjetAK8matchedmuonisGoodGL[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuonisMed",selpfjetAK8matchedmuonisMed,"selpfjetAK8matchedmuonisMed[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuonisMedPr",selpfjetAK8matchedmuonisMedPr,"selpfjetAK8matchedmuonisMedPr[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuonisTight",selpfjetAK8matchedmuonisTight,"selpfjetAK8matchedmuonisTight[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuonisHighPt",selpfjetAK8matchedmuonisHighPt,"selpfjetAK8matchedmuonisHighPt[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuonisHighPttrk",selpfjetAK8matchedmuonisHighPttrk,"selpfjetAK8matchedmuonisHighPttrk[npfjetAK8_tmu]/F");
  //Tout2->Branch("selpfjetAK8matchedmuonisTRK",selpfjetAK8matchedmuonisTRK,"selpfjetAK8matchedmuonisTRK[npfjetAK8_tmu]/F");
  
  Tout2->Branch("selpfjetAK8matchedmuonchi",selpfjetAK8matchedmuonchi,"selpfjetAK8matchedmuonchi[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuonposmatch",selpfjetAK8matchedmuonposmatch,"selpfjetAK8matchedmuonposmatch[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuontrkink",selpfjetAK8matchedmuontrkink,"selpfjetAK8matchedmuontrkink[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuonsegcom",selpfjetAK8matchedmuonsegcom,"selpfjetAK8matchedmuonsegcom[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuonhit",selpfjetAK8matchedmuonhit,"selpfjetAK8matchedmuonhit[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuonmst",selpfjetAK8matchedmuonmst,"selpfjetAK8matchedmuonmst[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuontrkvtx",selpfjetAK8matchedmuontrkvtx,"selpfjetAK8matchedmuontrkvtx[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuondz",selpfjetAK8matchedmuondz,"selpfjetAK8matchedmuondz[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuonpixhit",selpfjetAK8matchedmuonpixhit,"selpfjetAK8matchedmuonpixhit[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuontrklay",selpfjetAK8matchedmuontrklay,"selpfjetAK8matchedmuontrklay[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmuonvalfrac",selpfjetAK8matchedmuonvalfrac,"selpfjetAK8matchedmuonvalfrac[npfjetAK8_tmu]/F");
  //Ifar,Inear,I0
  Tout2->Branch("selpfjetAK8muinsubIfar",selpfjetAK8muinsubIfar,"selpfjetAK8muinsubIfar[npfjetAK8_tmu]/F");  
  Tout2->Branch("selpfjetAK8muinsubInear",selpfjetAK8muinsubInear,"selpfjetAK8muinsubInear[npfjetAK8_tmu]/F"); 
  Tout2->Branch("selpfjetAK8muinsubI0",selpfjetAK8muinsubI0,"selpfjetAK8muinsubI0[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8muinsubIfarbyI0",selpfjetAK8muinsubIfarbyI0,"selpfjetAK8muinsubIfarbyI0[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8muinsubInearbyI0",selpfjetAK8muinsubInearbyI0,"selpfjetAK8muinsubInearbyI0[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchedmupfiso",selpfjetAK8matchedmupfiso,"selpfjetAK8matchedmupfiso[npfjetAK8_tmu]/F");
  
  
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
  Tout2->Branch("selpfjetAK8haselectron",selpfjetAK8haselectron,"selpfjetAK8haselectron[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasmuon",selpfjetAK8hasmuon,"selpfjetAK8hasmuon[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hashadtop_alldecay",selpfjetAK8hashadtop_alldecay,"selpfjetAK8hashadtop_alldecay[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasleptop_alldecay",selpfjetAK8hasleptop_alldecay,"selpfjetAK8hasleptop_alldecay[npfjetAK8_tmu]/O");
  
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
  //Tout5->Branch("selpfjetAK8musubjptrat",selpfjetAK8musubjptrat,"selpfjetAK8musubjptrat[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8muinsubpt",selpfjetAK8muinsubpt,"selpfjetAK8muinsubpt[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8muinsubeta",selpfjetAK8muinsubeta,"selpfjetAK8muinsubeta[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8muinsubphi",selpfjetAK8muinsubphi,"selpfjetAK8muinsubphi[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8muinsubjpt",selpfjetAK8muinsubjpt,"selpfjetAK8muinsubjpt[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8muinsubjeta",selpfjetAK8muinsubjeta,"selpfjetAK8muinsujbeta[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8muinsubjphi",selpfjetAK8muinsubjphi,"selpfjetAK8muinsubjphi[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmupt",selpfjetAK8matchedmupt,"selpfjetAK8matchedmupt[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmueta",selpfjetAK8matchedmueta,"selpfjetAK8matchedmueta[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuphi",selpfjetAK8matchedmuphi,"selpfjetAK8matchedmuphi[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuE",selpfjetAK8matchedmuE,"selpfjetAK8matchedmuE[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8muinsubjmass",selpfjetAK8muinsubjmass,"selpfjetAK8muinsubjmass[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8muinsubptrat",selpfjetAK8muinsubptrat,"selpfjetAK8muinsubptrat[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8muinsubmassrat",selpfjetAK8muinsubmassrat,"selpfjetAK8muinsubmassrat[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8muinsubinvmass",selpfjetAK8muinsubinvmass,"selpfjetAK8muinsubinvmass[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuonisLoose",selpfjetAK8matchedmuonisLoose,"selpfjetAK8matchedmuonisLoose[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuonisGoodGL",selpfjetAK8matchedmuonisGoodGL,"selpfjetAK8matchedmuonisGoodGL[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuonisMed",selpfjetAK8matchedmuonisMed,"selpfjetAK8matchedmuonisMed[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuonisMedPr",selpfjetAK8matchedmuonisMedPr,"selpfjetAK8matchedmuonisMedPr[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuonisTight",selpfjetAK8matchedmuonisTight,"selpfjetAK8matchedmuonisTight[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuonisHighPt",selpfjetAK8matchedmuonisHighPt,"selpfjetAK8matchedmuonisHighPt[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuonisHighPttrk",selpfjetAK8matchedmuonisHighPttrk,"selpfjetAK8matchedmuonisHighPttrk[npfjetAK8_b]/F");
  //Tout5->Branch("selpfjetAK8matchedmuonisTRK",selpfjetAK8matchedmuonisTRK,"selpfjetAK8matchedmuonisTRK[npfjetAK8_b]/F");
  
  Tout5->Branch("selpfjetAK8matchedmuonchi",selpfjetAK8matchedmuonchi,"selpfjetAK8matchedmuonchi[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuonposmatch",selpfjetAK8matchedmuonposmatch,"selpfjetAK8matchedmuonposmatch[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuontrkink",selpfjetAK8matchedmuontrkink,"selpfjetAK8matchedmuontrkink[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuonsegcom",selpfjetAK8matchedmuonsegcom,"selpfjetAK8matchedmuonsegcom[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuonhit",selpfjetAK8matchedmuonhit,"selpfjetAK8matchedmuonhit[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuonmst",selpfjetAK8matchedmuonmst,"selpfjetAK8matchedmuonmst[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuontrkvtx",selpfjetAK8matchedmuontrkvtx,"selpfjetAK8matchedmuontrkvtx[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuondz",selpfjetAK8matchedmuondz,"selpfjetAK8matchedmuondz[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuonpixhit",selpfjetAK8matchedmuonpixhit,"selpfjetAK8matchedmuonpixhit[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuontrklay",selpfjetAK8matchedmuontrklay,"selpfjetAK8matchedmuontrklay[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmuonvalfrac",selpfjetAK8matchedmuonvalfrac,"selpfjetAK8matchedmuonvalfrac[npfjetAK8_b]/F");
  
  //Ifar,Inear,I0
  Tout5->Branch("selpfjetAK8muinsubIfar",selpfjetAK8muinsubIfar,"selpfjetAK8muinsubIfar[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8muinsubInear",selpfjetAK8muinsubInear,"selpfjetAK8muinsubInear[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8muinsubI0",selpfjetAK8muinsubI0,"selpfjetAK8muinsubI0[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8muinsubIfarbyI0",selpfjetAK8muinsubIfarbyI0,"selpfjetAK8muinsubIfarbyI0[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8muinsubInearbyI0",selpfjetAK8muinsubInearbyI0,"selpfjetAK8muinsubInearbyI0[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedmupfiso",selpfjetAK8matchedmupfiso,"selpfjetAK8matchedmupfiso[npfjetAK8_b]/F");
  
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
  Tout5->Branch("selpfjetAK8haselectron",selpfjetAK8haselectron,"selpfjetAK8haselectron[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasmuon",selpfjetAK8hasmuon,"selpfjetAK8hasmuon[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hastau",selpfjetAK8hastau,"selpfjetAK8hastau[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_b]/O");
#endif
  
  helinidiso = new TH1D("elinidiso","elinidiso", 4, 0.0, 4.0);
  hreelinidiso = new TH1D("hreelinidiso", "hreelinidiso", 4, 0.0, 4.0);
  hreelinidiso_str = new TH1D("hreelinidiso_str", "hreelinidiso_str", 4, 0.0, 4.0);
  
  char name[1000];
  char title[1000];
  
  for(int ihist=0; ihist<nhist; ihist++){
    
    
    sprintf(name,"%s_tlepe",branchnames[ihist]);
    hist_1[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
    hist_1[ihist]->Sumw2();
    
    
    sprintf(name,"%s_tlepmu",branchnames[ihist]);
    hist_2[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
    hist_2[ihist]->Sumw2();
    
    //sprintf(name,"%s_thad",branchnames[ihist]);
    //hist_3[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
    //hist_3[ihist]->Sumw2();
    
    //sprintf(name,"%s_qg",branchnames[ihist]);
    //hist_4[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
    //hist_4[ihist]->Sumw2();
    
    sprintf(name,"%s_b",branchnames[ihist]);
    hist_5[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
    hist_5[ihist]->Sumw2();
    
    /*
      sprintf(name,"%s_topcand",branchnames[ihist]);
      hist_6[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
      hist_6[ihist]->Sumw2();
    */
  }
  sprintf(name,"N_PV");
  sprintf(title,"# of Primary Vertices");
  hist_npv = new TH1D(name,title,100,-0.1,99.9);//80,-0.1,79.9);
  hist_npv->Sumw2();
  
  sprintf(name,"N_PU");
  sprintf(title,"# of Pileup Vertices");
  hist_npu = new TH1D(name,title,100,0,100);//80,-0.1,79.9);
  hist_npu->Sumw2();
  
  sprintf(name,"dReb_lcand");
  sprintf(title,"#Delta R(e,b)");
  hist_dReb = new TH1D(name,title,100,0.0,2.5);
  hist_dReb->Sumw2();
  
  sprintf(name,"dRenu_lcand");
  sprintf(title,"#Delta R(e,#nu)");
  hist_dRnue = new TH1D(name,title,100,0.0,2.5);
  hist_dRnue->Sumw2();
  
  sprintf(name,"dRbnu_lcand");
  sprintf(title,"#Delta R(b,#nu)");
  hist_dRnub = new TH1D(name,title,100,0.0,2.5);
  hist_dRnub->Sumw2();
  
  sprintf(name,"dRet_lcand");
  sprintf(title,"#Delta R(e,t)");
  hist_dRet = new TH1D(name,title,100,0.0,2.5);
  hist_dRet->Sumw2();
  
  sprintf(name,"dRnut_lcand");
  sprintf(title,"#Delta R(#nu,t)");
  hist_dRnut = new TH1D(name,title,100,0.0,2.5);
  hist_dRnut->Sumw2();
  
  sprintf(name,"dRbt_lcand");
  sprintf(title,"#Delta R(b,t)");
  hist_dRbt = new TH1D(name,title,100,0.0,2.5);
  hist_dRbt->Sumw2();
  
  sprintf(name,"dReb_lcand2D");
  sprintf(title,"Top p_{T} vs #Delta R(e,b)");
  hist2D_dReb = new TH2D(name,title,noptbins,ptbins,100,0.0,2.5);
  hist2D_dReb->Sumw2();
  
  sprintf(name,"dRenu_lcand2D");
  sprintf(title,"Top p_{T} vs #Delta R(e,#nu)");
  hist2D_dRnue = new TH2D(name,title,noptbins,ptbins,100,0.0,2.5);
  hist2D_dRnue->Sumw2();
  
  sprintf(name,"dRbnu_lcand2D");
  sprintf(title,"Top p_{T} vs #Delta R(b,#nu)");
  hist2D_dRnub = new TH2D(name,title,noptbins,ptbins,100,0.0,2.5);
  hist2D_dRnub->Sumw2();
  
  sprintf(name,"dRet_lcand2D");
  sprintf(title,"Top p_{T} vs #Delta R(e,t)");
  hist2D_dRet = new TH2D(name,title,noptbins,ptbins,100,0.0,2.5);
  hist2D_dRet->Sumw2();
  
  sprintf(name,"dRnut_lcand2D");
  sprintf(title,"Top p_{T} vs #Delta R(#nu,t)");
  hist2D_dRnut = new TH2D(name,title,noptbins,ptbins,100,0.0,2.5);
  hist2D_dRnut->Sumw2();
  
  sprintf(name,"dRbt_lcand2D");
  sprintf(title,"Top p_{T} vs #Delta R(b,t)");
  hist2D_dRbt = new TH2D(name,title,noptbins,ptbins,100,0.0,2.5);
  hist2D_dRbt->Sumw2();
  
  sprintf(name,"H2D_dR_lb_LepTop");
  sprintf(title,"Top p_{T} vs #Delta R(l,b)");
  h2d_pt_lb = new TH2D(name,title,noptbins,ptbins,100,0.0,2.5);
  h2d_pt_lb->Sumw2();
  
  sprintf(name,"H2D_dR_lt_LepTop");
  sprintf(title,"Top p_{T} vs #Delta R(l,t)");
  h2d_pt_lt = new TH2D(name,title,noptbins,ptbins,100,0.0,2.5);
  h2d_pt_lt->Sumw2();
  
  sprintf(name,"H2D_dR_lb_HadTop");
  sprintf(title,"Top p_{T} vs #Delta R(d/s,b)");
  h2d_pt_qb = new TH2D(name,title,noptbins,ptbins,100,0.0,2.5);
  h2d_pt_qb->Sumw2();
  
  sprintf(name,"H2D_dR_lt_HadTop");
  sprintf(title,"Top p_{T} vs #Delta R(d/s,t)");
  h2d_pt_qt = new TH2D(name,title,noptbins,ptbins,100,0.0,2.5);
  h2d_pt_qt->Sumw2();
  
  sprintf(name,"H2D_dRmax_daught_top_LepTop");
  sprintf(title,"Top p_{T} vs Max(#Delta R(d,t))");
  h2d_pt_qt_lep = new TH2D(name,title,noptbins,ptbins,100,0.0,2.5);
  h2d_pt_qt_lep->Sumw2();
  
  sprintf(name,"H2D_dRmax_daught_top_HadTop");
  sprintf(title,"Top p_{T} vs Max(#Delta R(d,t))");
  h2d_pt_qt_had = new TH2D(name,title,noptbins,ptbins,100,0.0,2.5);
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
  h2d_pt_dR_leptop_Jet = new TH2D(name,title,noptbins,ptbins,100,0.0,2.5);
  h2d_pt_dR_leptop_Jet->Sumw2();
  
  sprintf(name,"H2D_dRmin_top_jet_HadTop");
  sprintf(title,"Top p_{T} vs Min(#Delta R(t,j))");
  h2d_pt_dR_hadtop_Jet = new TH2D(name,title,noptbins,ptbins,100,0.0,2.5);
  h2d_pt_dR_hadtop_Jet->Sumw2();
  
  sprintf(name,"Counter_event");
  hist_event_count = new TH1D(name,title,2,-0.5,1.5);
  hist_event_count->Sumw2();
  
  sprintf(name,"Counter_event_truthtop");
  hist_event_count_truth = new TH1D(name,title,2,-0.5,1.5);
  hist_event_count_truth->Sumw2();
  
  sprintf(name,"Counter_event_pass_re");
  hist_event_top_pass = new TH1D(name,title,nre+1,-0.5,101.5);
  hist_event_top_pass->Sumw2();
  
  sprintf(name,"Counter_event_pass_re_wel");
  hist_event_top_pass_wel = new TH1D(name,title,nre+1,-0.5,101.5);
  hist_event_top_pass_wel->Sumw2();
  
  sprintf(name,"Counter_event_total_pfel");
  hist_event_count_total_pfel = new TH1D(name,title,2,-0.5,1.5);
  hist_event_count_total_pfel->Sumw2();
  
  sprintf(name,"Counter_event_pass_matchgsf");
  hist_event_count_pass_matchgsf = new TH1D(name,title,2,-0.5,1.5);
  hist_event_count_pass_matchgsf->Sumw2();
  
  /*
  reader1 = new TMVA::Reader( "BDTG_Re" );
  reader1->AddVariable( "selpfjetAK8NHadF", &in_pfjetAK8NHadF);
  reader1->AddVariable( "selpfjetAK8neunhadfrac", &in_pfjetAK8neunhadfrac);
  reader1->AddVariable( "selpfjetAK8subhaddiff", &in_pfjetAK8subhaddiff);
  reader1->AddVariable( "selpfjetAK8tau21", &in_pfjetAK8tau21);
  reader1->AddVariable( "selpfjetAK8chrad", &in_pfjetAK8chrad);
  reader1->AddVariable( "selpfjetAK8sdmass", &in_pfjetAK8sdmass);
  reader1->AddVariable( "selpfjetAK8matchedeldxy_sv", &in_pfjetAK8eldxy_sv);
  //reader1->AddVariable( "selpfjetAK8matchedelID", &in_pfjetAK8matchedelID);

  reader1->AddVariable("selpfjetAK8matchedelcleta", &in_pfjetAK8matchedelcleta);
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
  //reader1->AddVariable("selpfjetAK8matchedelptrel", &in_pfjetAK8matchedelptrel);
  reader1->BookMVA("BDTG method", weightfile1);
  
  reader2 = new TMVA::Reader( "BDTG_Rnu" );
  reader2->AddVariable( "selpfjetAK8_bbyW_E", &in_pfjetAK8_bbyW_E);
  reader2->AddVariable( "selpfjetAK8_Kfactor", &in_pfjetAK8_Kfactor);
  reader2->BookMVA("BDTG method", weightfile2);
  */
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
  
  int ngenelc = 0;
  int ngenmu = 0;
  int ngentau = 0;
  int ngenqg = 0;
  int ngenb = 0;
  
  hist_event_count->Fill(1,weight);
  
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
    nleptop = nhadtop = -1;
    
    if(ndq==4 && ndl==0) { nleptop = 0; nhadtop = 2; }
    if(ndq==2 && ndl==2) { nleptop = 1; nhadtop = 1; }
    if(ndq==0 && ndl==4) { nleptop = 2; nhadtop = 0; }
    if(ndq==0 && ndl==2) { nleptop = 1; nhadtop = 0; }
    if(ndq==2 && ndl==0) { nleptop = 0; nhadtop = 1; }
    if(ndq==0 && ndl==0) { nleptop = 0; nhadtop = 0; }
    
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
	      
	      h2d_pt_lb->Fill(leptop4v[ileptop].Pt(),delta2R(b4.Rapidity(),b4.Phi(),q1.Rapidity(),q1.Phi()), weight);
	      h2d_pt_lt->Fill(leptop4v[ileptop].Pt(),delta2R(leptop4v[ileptop].Rapidity(),leptop4v[ileptop].Phi(),q1.Rapidity(),q1.Phi()),weight);
	      hist_dReb->Fill(delta2R(b4.Rapidity(),b4.Phi(),q1.Rapidity(),q1.Phi()),weight);
	      hist_dRnue->Fill(delta2R(q2.Rapidity(),q2.Phi(),q1.Rapidity(),q1.Phi()),weight);
	      hist_dRnub->Fill(delta2R(b4.Rapidity(),b4.Phi(),q2.Rapidity(),q2.Phi()),weight);
	      hist_dRet->Fill(delta2R(leptop4v[ileptop].Rapidity(),leptop4v[ileptop].Phi(),q1.Rapidity(),q1.Phi()),weight);
	      hist_dRnut->Fill(delta2R(leptop4v[ileptop].Rapidity(),leptop4v[ileptop].Phi(),q2.Rapidity(),q2.Phi()),weight);
	      hist_dRbt->Fill(delta2R(leptop4v[ileptop].Rapidity(),leptop4v[ileptop].Phi(),b4.Rapidity(),b4.Phi()),weight);
	      
	      hist2D_dReb->Fill(leptop4v[ileptop].Pt(),delta2R(b4.Rapidity(),b4.Phi(),q1.Rapidity(),q1.Phi()),weight);
	      hist2D_dRnue->Fill(leptop4v[ileptop].Pt(),delta2R(q2.Rapidity(),q2.Phi(),q1.Rapidity(),q1.Phi()),weight);
	      hist2D_dRnub->Fill(leptop4v[ileptop].Pt(),delta2R(b4.Rapidity(),b4.Phi(),q2.Rapidity(),q2.Phi()),weight);
	      hist2D_dRet->Fill(leptop4v[ileptop].Pt(),delta2R(leptop4v[ileptop].Rapidity(),leptop4v[ileptop].Phi(),q1.Rapidity(),q1.Phi()),weight);
	      hist2D_dRnut->Fill(leptop4v[ileptop].Pt(),delta2R(leptop4v[ileptop].Rapidity(),leptop4v[ileptop].Phi(),q2.Rapidity(),q2.Phi()),weight);
	      hist2D_dRbt->Fill(leptop4v[ileptop].Pt(),delta2R(leptop4v[ileptop].Rapidity(),leptop4v[ileptop].Phi(),b4.Rapidity(),b4.Phi()),weight);
	      
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
  
  //*****adding on 19th October,2020*****//
  EE = MUMU = EMU = EJets = MUJets = TauTau = ETau = MuTau = false;

  if(DiLeptt && abs(leptop_id_daught[0])==11 && abs(leptop_id_daught[1])==11) { EE = true; }
  if(DiLeptt && abs(leptop_id_daught[0])==13 && abs(leptop_id_daught[1])==13) { MUMU = true; }
  if(DiLeptt && abs(leptop_id_daught[0])==15 && abs(leptop_id_daught[1])==15) { TauTau = true; }
  if(DiLeptt && ((abs(leptop_id_daught[0])==11 && abs(leptop_id_daught[1])==13) || (abs(leptop_id_daught[0])==13 && abs(leptop_id_daught[1])==11)) ) { EMU = true; }
  if(DiLeptt && ((abs(leptop_id_daught[0])==11 && abs(leptop_id_daught[1])==15) || (abs(leptop_id_daught[0])==15 && abs(leptop_id_daught[1])==11)) ) { ETau = true; }
  if(DiLeptt && ((abs(leptop_id_daught[0])==13 && abs(leptop_id_daught[1])==15) || (abs(leptop_id_daught[0])==15 && abs(leptop_id_daught[1])==13)) ) { MuTau = true; }
  
  if(SemiLeptt && abs(leptop_id_daught[0])==11) { EJets = true; }
  if(SemiLeptt && abs(leptop_id_daught[0])==13) { MUJets = true; }
  if(SemiLeptt && abs(leptop_id_daught[0])==15) { TAUJets = true; }
  
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

    //if (pfjetAK8muinsubpt[ijet] < 0 && pfjetAK8muinsubjpt[ijet]< 0) continue;
    
    //TString str = TString::Format("Ifar %f Inear %f I0 %f\n",pfjetAK8muinsubIfar[ijet],pfjetAK8muinsubInear[ijet],pfjetAK8muinsubI0[ijet]);            
    //if(gProofServ) gProofServ->SendAsynMessage(str); 

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

    pfjetAK8elinsubpt[fjet] = pfjetAK8elinsubpt[ijet];
    pfjetAK8elinsubeta[fjet] = pfjetAK8elinsubeta[ijet];
    pfjetAK8elinsubphi[fjet] = pfjetAK8elinsubphi[ijet];
    pfjetAK8elinsube[fjet] = pfjetAK8elinsube[ijet];
    pfjetAK8elinsubjpt[fjet] = pfjetAK8elinsubjpt[ijet];
    pfjetAK8elinsubjeta[fjet] = pfjetAK8elinsubjeta[ijet];
    pfjetAK8elinsubjphi[fjet] = pfjetAK8elinsubjphi[ijet];
    pfjetAK8elinsubjmass[fjet] = pfjetAK8elinsubjmass[ijet];

    pfjetAK8elinsubI0[fjet] = pfjetAK8elinsubI0[ijet];
    pfjetAK8elinsubInear[fjet] = pfjetAK8elinsubInear[ijet];
    pfjetAK8elinsubIfar[fjet] = pfjetAK8elinsubIfar[ijet];


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
      //}
  }
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
    
    //if(isnan(pfjetAK8musubjptrat[ijet])) { pfjetAK8musubjptrat[ijet] = -100; }
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

    if(isnan(pfjetAK8elinsubpt[ijet])) { pfjetAK8elinsubpt[ijet] = -100; }
    if(isnan(pfjetAK8elinsubeta[ijet])) { pfjetAK8elinsubeta[ijet] = -100; }
    if(isnan(pfjetAK8elinsubphi[ijet])) { pfjetAK8elinsubphi[ijet] = -100; }
    if(isnan(pfjetAK8elinsube[ijet])) { pfjetAK8elinsube[ijet] = -100; }
    if(isnan(pfjetAK8elinsubjpt[ijet])) { pfjetAK8elinsubjpt[ijet] = -100; }
    if(isnan(pfjetAK8elinsubjeta[ijet])) { pfjetAK8elinsubjeta[ijet] = -100; }
    if(isnan(pfjetAK8elinsubjphi[ijet])) { pfjetAK8elinsubjphi[ijet] = -100; }
    if(isnan(pfjetAK8elinsubjmass[ijet])) { pfjetAK8elinsubjmass[ijet] = -100; }

    if(isnan(pfjetAK8elinsubI0[ijet])) { pfjetAK8elinsubI0[ijet] = -100; }
    if(isnan(pfjetAK8elinsubInear[ijet])) { pfjetAK8elinsubInear[ijet] = -100; }
    if(isnan(pfjetAK8elinsubIfar[ijet])) { pfjetAK8elinsubIfar[ijet] = -100; }


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
    if(isnan(pfjetAK8hastau[ijet])) { pfjetAK8hastau[ijet] = -100; }
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
    /*
    Float_t Re(-100);
    
    in_pfjetAK8NHadF = pfjetAK8NHadF[ijet];
    in_pfjetAK8neunhadfrac = pfjetAK8neunhadfrac[ijet];
    in_pfjetAK8subhaddiff = pfjetAK8subhaddiff[ijet];
    in_pfjetAK8tau21 = pfjetAK8tau21[ijet];
    in_pfjetAK8chrad = pfjetAK8chrad[ijet];
    in_pfjetAK8sdmass = pfjetAK8sdmass[ijet];
    
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
    in_pfjetAK8matchedelhovere = -999;*/
    //in_pfjetAK8matchedelptrel = -999;
    
    bool Isolpass = false;
    if (pfjetAK8muinsubeta[ijet] != -100 && pfjetAK8muinsubphi[ijet] != -100)
      {
        if (npfjetAK4 > 0) {
          float minR = 1000;
          int nearjet = -1;
          double Muon_pt_nearjet(0);
          for (int kjet=0; kjet<npfjetAK4; kjet++) {
            if(delta2R(pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet],pfjetAK4eta[kjet],pfjetAK4phi[kjet])<minR) {
              minR = delta2R(pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet],pfjetAK4eta[kjet],pfjetAK4phi[kjet]);
              nearjet = kjet;
            }
          }
          if (nearjet>=0){
            TLorentzVector j_mom; j_mom.SetPtEtaPhiM(pfjetAK4pt[nearjet],pfjetAK4eta[nearjet],pfjetAK4phi[nearjet],pfjetAK4mass[nearjet]);
	    
            TLorentzVector nearmu; nearmu.SetPtEtaPhiE(pfjetAK8muinsubpt[ijet],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet],pfjetAK8muinsube[ijet]);
            Muon_pt_nearjet = ((nearmu.Vect()).Perp(j_mom.Vect()));
          }
          if (minR > 0.4 ||  Muon_pt_nearjet > 15.) Isolpass = true;
        }
      }
    
    pfjetAK8_hasmatchmu[ijet] = false;
    
    if (pfjetAK8muinsubeta[ijet] != -100 && pfjetAK8muinsubphi[ijet] != -100)
      {
	if (nmuons > 0) {
	  float dR_min(0.4); int nearest(-1);
	  for(int mu=0; mu<nmuons; mu++){
	    float dR = delta2R(muoneta[mu],muonphi[mu],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet]);
	    if (dR < dR_min) {
	      dR_min = dR;
	      nearest = mu;
	    }
	  }
	  if (nearest >= 0) pfjetAK8_hasmatchmu[ijet] = (nearest >= 0)?true:false;
	}
      }
    //if (!isnan(Rho)) in_pfjetAK8matchedelRho = Rho;
    //else 
    /*
      in_pfjetAK8matchedelRho = -999;
      pfjetAK8re_tvsb[ijet] = -100;
      Re = reader1->EvaluateMVA("BDTG method");
      pfjetAK8re_tvsb[ijet] = Re;
      in_pfjetAK8_bbyW_E = pfjetAK8_bbyW_E[ijet];
      in_pfjetAK8_Kfactor = pfjetAK8_Kfactor[ijet];
      Float_t Rnu(-100);
      Rnu = reader2->EvaluateMVA("BDTG method");
      pfjetAK8rnu_tvsb[ijet] = Rnu;
    */
    bool te_cond = false;
    bool tmu_cond = false;
    bool thad_cond = false;
    bool qg_cond = false;
    bool b_cond = false;
  
    te_cond  = (pfjetAK8haselectron[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]);
    tmu_cond = (pfjetAK8hasmuon[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]);
    //thad_cond = (pfjetAK8hashadtop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hashadtop_alldecay[ijet]); //why not also hasb and hasqq as well
    //qg_cond = (pfjetAK8hasqg[ijet] && !(pfjetAK8hashadtop[ijet]) && !(pfjetAK8hasleptop[ijet]) && !(pfjetAK8hastop[ijet]));
    b_cond = (pfjetAK8hasb[ijet] && !(pfjetAK8hashadtop[ijet]) && !(pfjetAK8hasleptop[ijet]) && !(pfjetAK8hastop[ijet]));
    
    if(te_cond){
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
	    if (nearest >= 0) {
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
	      TLorentzVector lep, lepbj, bj;
	      lep.SetPtEtaPhiE(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet],pfjetAK8elinsube[ijet]);

	      bj.SetPtEtaPhiM(pfjetAK8elinsubjpt[ijet],pfjetAK8elinsubjeta[ijet],pfjetAK8elinsubjphi[ijet],pfjetAK8elinsubjmass[ijet]);
	      lepbj = lep + bj;

	      hist_1[46]->Fill(lepbj.M(),weight);
	      hist_1[47]->Fill(lep.Pt()/lepbj.Pt(),weight);
	      hist_1[48]->Fill(bj.M()/lepbj.M(),weight);

	      hist_1[49]->Fill(pfjetAK8elinsubIfar[ijet]/pfjetAK8elinsubI0[ijet],weight);
	      hist_1[50]->Fill(pfjetAK8elinsubInear[ijet]/pfjetAK8elinsubI0[ijet],weight);
	    }
	  }
	}
    }


    if(tmu_cond){
      
	if (pfjetAK8muinsubeta[ijet] != -100 && pfjetAK8muinsubphi[ijet] != -100)
	  {
	    if (nmuons > 0) {
	      float dR_min(0.4); int nearest(-1);
	      for(int mu=0; mu<nmuons; mu++){
		float dR = delta2R(muoneta[mu],muonphi[mu],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet]);
		if (dR < dR_min) {
		  dR_min = dR;
		  nearest = mu;
		}
	      }
	      if (nearest >= 0) {
		bool mu_iso = Muon_Iso_ID(muonpfiso[nearest]);
		//if (mu_iso) {
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

		TLorentzVector lep, lepbj, bj;
		lep.SetPtEtaPhiE(pfjetAK8muinsubpt[ijet],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet],pfjetAK8muinsube[ijet]);

		bj.SetPtEtaPhiM(pfjetAK8muinsubjpt[ijet],pfjetAK8muinsubjeta[ijet],pfjetAK8muinsubjphi[ijet],pfjetAK8muinsubjmass[ijet]);
		lepbj = lep + bj;

		hist_2[46]->Fill(lepbj.M(),weight);
		hist_2[47]->Fill(lep.Pt()/lepbj.Pt(),weight);
		hist_2[48]->Fill(bj.M()/lepbj.M(),weight);
		
		hist_2[49]->Fill(pfjetAK8muinsubIfar[ijet]/pfjetAK8muinsubI0[ijet],weight);
		hist_2[50]->Fill(pfjetAK8muinsubInear[ijet]/pfjetAK8muinsubI0[ijet],weight);
	      }
	    }
	  }
    }
    if(b_cond){
      if (pfjetAK8muinsubeta[ijet] != -100 && pfjetAK8muinsubphi[ijet] != -100)
        {
          if (nmuons > 0) {
            float dR_min(0.4); int nearest(-1);
            for(int mu=0; mu<nmuons; mu++){
              float dR = delta2R(muoneta[mu],muonphi[mu],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet]);
              if (dR < dR_min) {
                dR_min = dR;
                nearest = mu;
              }
            }
            if (nearest >= 0) {
	      bool mu_iso = Muon_Iso_ID(muonpfiso[nearest]);
              //if (mu_iso) {
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
	      
	      TLorentzVector lep, lepbj, bj;
	      lep.SetPtEtaPhiE(pfjetAK8muinsubpt[ijet],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet],pfjetAK8muinsube[ijet]);
	      
	      bj.SetPtEtaPhiM(pfjetAK8muinsubjpt[ijet],pfjetAK8muinsubjeta[ijet],pfjetAK8muinsubjphi[ijet],pfjetAK8muinsubjmass[ijet]);
	      lepbj = lep + bj;
	      
	      hist_5[46]->Fill(lepbj.M(),weight);
	      hist_5[47]->Fill(lep.Pt()/lepbj.Pt(),weight);
	      hist_5[48]->Fill(bj.M()/lepbj.M(),weight);

	      hist_5[49]->Fill(pfjetAK8muinsubIfar[ijet]/pfjetAK8muinsubI0[ijet],weight);
	      hist_5[50]->Fill(pfjetAK8muinsubInear[ijet]/pfjetAK8muinsubI0[ijet],weight);
	    }
	  }
	}
    }
  } //ijet
  //}
  //npfjetAK8 > 0
  //TString str1 = TString::Format("tr_count %d \n",tr_count);                                                              
  //if(gProofServ) gProofServ->SendAsynMessage(str1);
  /*
    int telcand1 = -1;
    bool te_found1 = false;
    bool te_cond1(false);
    int nelcand1 = 0;
    

    float BDT_score1(-100.);
    if (SemiLeptt && EJets){
    hist_count->Fill(1,weight);
    for(int ijet=0; ijet<npfjetAK8; ijet++){
    if (pfjetAK8_hasmatche[ijet] == 1) {
    if(pfjetAK8re_tvsb[ijet] > BDT_score1){
    BDT_score1 = pfjetAK8re_tvsb[ijet];
    telcand1 = ijet;
    te_found1 = true;
    nelcand1++;
    }
    }
    }
    if (telcand1>= 0){
      
    hist_Obs_re->Fill(pfjetAK8re_tvsb[telcand1],weight);
    hist_Obs_pt->Fill(pfjetAK8pt[telcand1],weight);
    
    if (pfjetAK8sdmass[telcand1] > 70.) hist_Obs_re_sdmasscut->Fill(pfjetAK8re_tvsb[telcand1],weight);
    if (pfjetAK8tau21[telcand1] < 0.35) hist_Obs_re_tau21cut->Fill(pfjetAK8re_tvsb[telcand1],weight);
    if (pfjetAK8sdmass[telcand1] > 70. && pfjetAK8tau21[telcand1] < 0.35) hist_Obs_re_sdmasscut_tau21cut->Fill(pfjetAK8re_tvsb[telcand1],weight);
    
    hist_Obs_mass->Fill(pfjetAK8mass[telcand1],weight);
    hist_Obs_sdmass->Fill(pfjetAK8sdmass[telcand1],weight);
    hist_Obs_tau21->Fill(pfjetAK8tau21[telcand1],weight);
    
    te_cond1  = (pfjetAK8haselectron[telcand1] && pfjetAK8hasleptop[telcand1] && pfjetAK8hastop[telcand1] && pfjetAK8hasleptop_alldecay[telcand1]);
      if (pfjetAK8haselectron[telcand1]) {
      
      hist_Obs_re_hasel->Fill(pfjetAK8re_tvsb[telcand1],weight);
      hist_Obs_mass_hasel->Fill(pfjetAK8mass[telcand1],weight);
      hist_Obs_sdmass_hasel->Fill(pfjetAK8sdmass[telcand1],weight);
      hist_Obs_tau21_hasel->Fill(pfjetAK8tau21[telcand1],weight);
      }
      if (pfjetAK8haselectron[telcand1] && pfjetAK8hasb[telcand1]) hist_Obs_re_hasel_hasb->Fill(pfjetAK8re_tvsb[telcand1],weight);
      if (pfjetAK8haselectron[telcand1] && pfjetAK8hasleptop[telcand1]) hist_Obs_re_hasel_hasleptop->Fill(pfjetAK8re_tvsb[telcand1],weight);
      if (pfjetAK8haselectron[telcand1] && pfjetAK8hasleptop[telcand1] && pfjetAK8hastop[telcand1]) hist_Obs_re_hasel_hasleptop_hastop->Fill(pfjetAK8re_tvsb[telcand1],weight);
      if (pfjetAK8haselectron[telcand1] && pfjetAK8hasleptop[telcand1] && pfjetAK8hastop[telcand1] && pfjetAK8hasleptop_alldecay[telcand1]) hist_Obs_re_hasel_hasleptop_hastop_hasalltopdecay->Fill(pfjetAK8re_tvsb[telcand1],weight);
      if (te_cond1) hist_Obs_re_tecond->Fill(pfjetAK8re_tvsb[telcand1],weight);
      }
      }
      
      int t_cand = -1;
      double remax = -200;
      for(int ijet=0; ijet < npfjetAK8; ijet++){
      if(pfjetAK8re_tvsb[ijet] > remax){
      remax = pfjetAK8re_tvsb[ijet];
      t_cand = ijet;
      }
      }*/
  /*
  double dRmax = -999;
  double dRmax_wel = -999;
  int max(-1);
  int max_wel(-1);
  for(int ijet=0; ijet< npfjetAK8; ijet++){
    if(pfjetAK8re_tvsb[ijet] > dRmax){
      dRmax = pfjetAK8re_tvsb[ijet];
      max = ijet;
    }
  
    if(pfjetAK8re_tvsb[ijet] > dRmax_wel && pfjetAK8_hasmatche[ijet] == 1){
      dRmax_wel = pfjetAK8re_tvsb[ijet];
      max_wel = ijet;
    }
  }
    
  if(nleptop>=1) { 
    for(int ire=0; ire<(nre+1); ire++){
      if(dRmax >= (-1.+ ire*2./100.)){
     	hist_event_top_pass->Fill(1.*(ire+1.),weight); 
      }
    }
  }
    
  if(nleptop>=1) {
    for(int ire=0; ire<(nre+1); ire++){
      if(dRmax_wel >= (-1.+ ire*2./100.)){
        hist_event_top_pass_wel->Fill(1.*(ire+1.),weight);
      }
    }
  }*/
  
  
#ifdef TRAINING
  int iseljet = 0;
  npfjetAK8_tmu = 0;
  
  for(int ijet=0; ijet< npfjetAK8; ijet++){
    
    if(ijet>(nmaxjet-1)) break;
    
    bool tmu_cond = false;
    tmu_cond = (pfjetAK8hasmuon[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]);    
    
    if(tmu_cond){
      /*
      selpfjetAK8NHadF_nosel[iseljet] = pfjetAK8NHadF[ijet];
      selpfjetAK8neunhadfrac_nosel[iseljet] = pfjetAK8neunhadfrac[ijet];
      selpfjetAK8subhaddiff_nosel[iseljet] = pfjetAK8subhaddiff[ijet];
      selpfjetAK8tau21_nosel[iseljet] = pfjetAK8tau21[ijet];
      selpfjetAK8chrad_nosel[iseljet] = pfjetAK8chrad[ijet];
      selpfjetAK8sdmass_nosel[iseljet] = pfjetAK8sdmass[ijet];
      */

      if (pfjetAK8muinsubeta[ijet] != -100 && pfjetAK8muinsubphi[ijet] != -100)
	{
	  if (nmuons > 0) {
            float dR_min(0.4); int nearest(-1);
            for(int mu=0; mu<nmuons; mu++){
              float dR = delta2R(muoneta[mu],muonphi[mu],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet]);
              if (dR < dR_min) {
                dR_min = dR;
                nearest = mu;
              }
            }
            if (nearest >= 0) {
	      bool mu_iso = Muon_Iso_ID(muonpfiso[nearest]);
	      //if (mu_iso) {
	      selpfjetAK8matchedmupfiso[iseljet] = muonpfiso[nearest];
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
	      selpfjetAK8haselectron[iseljet] =  pfjetAK8haselectron[ijet];                    
              selpfjetAK8hasmuon[iseljet] =  pfjetAK8hasmuon[ijet];                            
              selpfjetAK8hastau[iseljet] =  pfjetAK8hastau[ijet];                              
              selpfjetAK8hasqg[iseljet] =  pfjetAK8hasqg[ijet];                                
              selpfjetAK8hasb[iseljet] =  pfjetAK8hasb[ijet];                                  
              selpfjetAK8hashadtop[iseljet] =  pfjetAK8hashadtop[ijet];                        
              selpfjetAK8hasleptop[iseljet] = pfjetAK8hasleptop[ijet];                         
              selpfjetAK8hastop[iseljet] = pfjetAK8hastop[ijet];                               
              selpfjetAK8hashadtop_alldecay[iseljet] = pfjetAK8hashadtop_alldecay[ijet];       
              selpfjetAK8hasleptop_alldecay[iseljet] = pfjetAK8hasleptop_alldecay[ijet];
	      
	      //selpfjetAK8musubjptrat[iseljet] = pfjetAK8musubjptrat[ijet];
	      selpfjetAK8muinsubpt[iseljet] = pfjetAK8muinsubpt[ijet];
	      selpfjetAK8muinsubeta[iseljet] = pfjetAK8muinsubeta[ijet];
	      selpfjetAK8muinsubphi[iseljet] = pfjetAK8muinsubphi[ijet];
	      selpfjetAK8muinsubjpt[iseljet] = pfjetAK8muinsubjpt[ijet];
	      selpfjetAK8muinsubjeta[iseljet] = pfjetAK8muinsubjeta[ijet];
	      selpfjetAK8muinsubjphi[iseljet] = pfjetAK8muinsubjphi[ijet];
	      selpfjetAK8muinsubInear[iseljet] = pfjetAK8muinsubInear[ijet];
	      selpfjetAK8muinsubIfar[iseljet] = pfjetAK8muinsubIfar[ijet];
	      selpfjetAK8muinsubI0[iseljet] = pfjetAK8muinsubI0[ijet];

	      selpfjetAK8muinsubIfarbyI0[iseljet] = pfjetAK8muinsubIfar[ijet]/pfjetAK8muinsubI0[ijet]; 
	      selpfjetAK8muinsubInearbyI0[iseljet] = pfjetAK8muinsubInear[ijet]/pfjetAK8muinsubI0[ijet];

	      if(isnan(selpfjetAK8muinsubIfarbyI0[iseljet])) { selpfjetAK8muinsubIfarbyI0[iseljet] = -100;}
	      if(isnan(selpfjetAK8muinsubInearbyI0[iseljet])) { selpfjetAK8muinsubInearbyI0[iseljet] = -100;}

	      selpfjetAK8matchedmupt[iseljet] = muonpt[nearest];                               
	      selpfjetAK8matchedmueta[iseljet] = muoneta[nearest];
	      selpfjetAK8matchedmuphi[iseljet] = muonphi[nearest];
              selpfjetAK8matchedmuE[iseljet] = muone[nearest];
	      selpfjetAK8muinsubjmass[iseljet] = pfjetAK8muinsubjmass[ijet];
	    
	      TLorentzVector lep, lepbj, bj;
	      lep.SetPtEtaPhiE(pfjetAK8muinsubpt[ijet],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet],pfjetAK8muinsube[ijet]);
	      //float delR1 = delta2R(pfjetAK8sub1eta[ijet],pfjetAK8sub1phi[ijet],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet]);
	      //float delR2 = delta2R(pfjetAK8sub2eta[ijet],pfjetAK8sub2phi[ijet],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet]);
	      //TString str = TString::Format("delR1 %f  delR2 %f hadfrac1 %f hadfrac2 %f emfrac1 %f emfrac2 %f ",delR1,delR2,pfjetAK8sub1hadfrac[ijet],pfjetAK8sub2hadfrac[ijet],pfjetAK8sub1emfrac[ijet],pfjetAK8sub2emfrac[ijet]);
	      //if(gProofServ) gProofServ->SendAsynMessage(str);
	      //if (delR1 < delR2) bj.SetPtEtaPhiM(pfjetAK8sub2pt[ijet],pfjetAK8sub2eta[ijet],pfjetAK8sub2phi[ijet],pfjetAK8sub2mass[ijet]);
	      //else bj.SetPtEtaPhiM(pfjetAK8sub1pt[ijet],pfjetAK8sub1eta[ijet],pfjetAK8sub1phi[ijet],pfjetAK8sub1mass[ijet]);

	      bj.SetPtEtaPhiM(pfjetAK8muinsubjpt[ijet],pfjetAK8muinsubjeta[ijet],pfjetAK8muinsubjphi[ijet],pfjetAK8muinsubjmass[ijet]);
	      lepbj = lep + bj;
	      
	      selpfjetAK8muinsubptrat[iseljet] = (lep.Pt())/(lepbj.Pt());
	      selpfjetAK8muinsubmassrat[iseljet] = (bj.M())/(lepbj.M());
	      selpfjetAK8muinsubinvmass[iseljet] = lepbj.M();
	      
	      if(isnan(selpfjetAK8muinsubptrat[iseljet])) {selpfjetAK8muinsubptrat[iseljet] = -100;}
	      if(isnan(selpfjetAK8muinsubmassrat[iseljet])) {selpfjetAK8muinsubmassrat[iseljet] = -100;}
	      if(isnan(selpfjetAK8muinsubinvmass[iseljet])) {selpfjetAK8muinsubinvmass[iseljet] = -100;}

	      selpfjetAK8matchedmuonisLoose[iseljet] = muonisLoose[nearest];
	      selpfjetAK8matchedmuonisGoodGL[iseljet] = muonisGoodGL[nearest];
	      selpfjetAK8matchedmuonisMed[iseljet] = muonisMed[nearest];
	      selpfjetAK8matchedmuonisMedPr[iseljet] = muonisMedPr[nearest];
	      selpfjetAK8matchedmuonisTight[iseljet] = muonisTight[nearest];
	      selpfjetAK8matchedmuonisHighPt[iseljet] = muonisHighPt[nearest];
	      selpfjetAK8matchedmuonisHighPttrk[iseljet] = muonisHighPttrk[nearest];
	      //selpfjetAK8matchedmuonisTRK[iseljet] = muonisTRK[nearest];
	      
	      selpfjetAK8matchedmuonchi[iseljet] = muonchi[nearest];
	      selpfjetAK8matchedmuonposmatch[iseljet] = muonposmatch[nearest];
	      selpfjetAK8matchedmuontrkink[iseljet] = muontrkink[nearest];
	      selpfjetAK8matchedmuonsegcom[iseljet] = muonsegcom[nearest];
	      selpfjetAK8matchedmuonhit[iseljet] = muonthit[nearest];
	      selpfjetAK8matchedmuonmst[iseljet] = muonmst[nearest];
	      selpfjetAK8matchedmuontrkvtx[iseljet] = muontrkvtx[nearest];
	      selpfjetAK8matchedmuondz[iseljet] = muondz[nearest];
	      selpfjetAK8matchedmuonpixhit[iseljet] = muonpixhit[nearest];
	      selpfjetAK8matchedmuontrklay[iseljet] = muontrklay[nearest];
	      selpfjetAK8matchedmuonvalfrac[iseljet] = muonvalfrac[nearest];
	      iseljet++;
	      if(iseljet>=njetmxAK8) break;
	      //}
	    }
	  }
	}
    }
  }
  npfjetAK8_tmu = iseljet;
  //if (iseljet != 0) Tout2->Fill();
  
  
  iseljet = 0;
  npfjetAK8_b = 0;
  
  for(int ijet=0; ijet< npfjetAK8; ijet++){
    
    if(ijet>(nmaxjet-1)) break;
    
    bool b_cond = false;
    b_cond = (pfjetAK8hasb[ijet] && !(pfjetAK8hashadtop[ijet]) && !(pfjetAK8hasleptop[ijet]) && !(pfjetAK8hastop[ijet]));
  
    if(b_cond){
      if (pfjetAK8muinsubeta[ijet] != -100 && pfjetAK8muinsubphi[ijet] != -100)
        {
	  if (nmuons > 0) {
            float dR_min(0.4); int nearest(-1);
            for(int mu=0; mu<nmuons; mu++){
              float dR = delta2R(muoneta[mu],muonphi[mu],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet]);
              if (dR < dR_min) {
                dR_min = dR;
                nearest = mu;
              }
            }
	    if (nearest >= 0) {
	      bool mu_iso = Muon_Iso_ID(muonpfiso[nearest]);
              //if (mu_iso) { 
	      selpfjetAK8matchedmupfiso[iseljet] = muonpfiso[nearest];
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
	      selpfjetAK8subemdiff[iseljet] = pfjetAK8subemdiff[ijet];
              selpfjetAK8subptdiff[iseljet] = pfjetAK8subptdiff[ijet];
              selpfjetAK8_bbyW_E[iseljet] = pfjetAK8_bbyW_E[ijet];
              selpfjetAK8_Kfactor[iseljet] = pfjetAK8_Kfactor[ijet];
              selpfjetAK8haselectron[iseljet] =  pfjetAK8haselectron[ijet];
              selpfjetAK8hasmuon[iseljet] =  pfjetAK8hasmuon[ijet];
              selpfjetAK8hastau[iseljet] =  pfjetAK8hastau[ijet];
              selpfjetAK8hasqg[iseljet] =  pfjetAK8hasqg[ijet];
              selpfjetAK8hasb[iseljet] =  pfjetAK8hasb[ijet];
              selpfjetAK8hashadtop[iseljet] =  pfjetAK8hashadtop[ijet];
              selpfjetAK8hasleptop[iseljet] = pfjetAK8hasleptop[ijet];
              selpfjetAK8hastop[iseljet] = pfjetAK8hastop[ijet];
              selpfjetAK8hashadtop_alldecay[iseljet] = pfjetAK8hashadtop_alldecay[ijet];
              selpfjetAK8hasleptop_alldecay[iseljet] = pfjetAK8hasleptop_alldecay[ijet];
	      //selpfjetAK8musubjptrat[iseljet] = pfjetAK8musubjptrat[ijet];
	      selpfjetAK8muinsubpt[iseljet] = pfjetAK8muinsubpt[ijet];
	      selpfjetAK8muinsubeta[iseljet] = pfjetAK8muinsubeta[ijet];
	      selpfjetAK8muinsubphi[iseljet] = pfjetAK8muinsubphi[ijet];
	      selpfjetAK8muinsubjpt[iseljet] = pfjetAK8muinsubjpt[ijet];
	      selpfjetAK8muinsubjeta[iseljet] = pfjetAK8muinsubjeta[ijet];
	      selpfjetAK8muinsubjphi[iseljet] = pfjetAK8muinsubjphi[ijet];
	      selpfjetAK8muinsubInear[iseljet] = pfjetAK8muinsubInear[ijet];
	      selpfjetAK8muinsubIfar[iseljet] = pfjetAK8muinsubIfar[ijet];
	      selpfjetAK8muinsubI0[iseljet] = pfjetAK8muinsubI0[ijet];
	      	      
	      selpfjetAK8muinsubIfarbyI0[iseljet] = pfjetAK8muinsubIfar[ijet]/pfjetAK8muinsubI0[ijet];
              selpfjetAK8muinsubInearbyI0[iseljet] = pfjetAK8muinsubInear[ijet]/pfjetAK8muinsubI0[ijet];

              if(isnan(selpfjetAK8muinsubIfarbyI0[iseljet])) { selpfjetAK8muinsubIfarbyI0[iseljet] = -100;}
	      if(isnan(selpfjetAK8muinsubInearbyI0[iseljet])) { selpfjetAK8muinsubInearbyI0[iseljet] = -100;}

	      selpfjetAK8matchedmupt[iseljet] = muonpt[nearest];                               
              selpfjetAK8matchedmueta[iseljet] = muoneta[nearest];
              selpfjetAK8matchedmuphi[iseljet] = muonphi[nearest];                             
              selpfjetAK8matchedmuE[iseljet] = muone[nearest];
	      selpfjetAK8muinsubjmass[iseljet] = pfjetAK8muinsubjmass[ijet];

              TLorentzVector lep, lepbj, bj;
              lep.SetPtEtaPhiE(pfjetAK8muinsubpt[ijet],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet],pfjetAK8muinsube[ijet]);
              //float delR1 = delta2R(pfjetAK8sub1eta[ijet],pfjetAK8sub1phi[ijet],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet]);
              //float delR2 = delta2R(pfjetAK8sub2eta[ijet],pfjetAK8sub2phi[ijet],pfjetAK8muinsubeta[ijet],pfjetAK8muinsubphi[ijet]);

              //TString str = TString::Format("delR1 %f  delR2 %f hadfrac1 %f hadfrac2 %f emfrac1 %f emfrac2 %f ",delR1,delR2,pfjetAK8sub1hadfrac[ijet],pfjetAK8sub2hadfrac[ijet],pfjetAK8sub1emfrac[ijet],pfjetAK8sub2emfrac[ijet]);                                                                           	    //if(gProofServ) gProofServ->SendAsynMessage(str);           
	      //if (delR1 < delR2) bj.SetPtEtaPhiM(pfjetAK8sub2pt[ijet],pfjetAK8sub2eta[ijet],pfjetAK8sub2phi[ijet],pfjetAK8sub2mass[ijet]);
	      //else bj.SetPtEtaPhiM(pfjetAK8sub1pt[ijet],pfjetAK8sub1eta[ijet],pfjetAK8sub1phi[ijet],pfjetAK8sub1mass[ijet]);

	      bj.SetPtEtaPhiM(pfjetAK8muinsubjpt[ijet],pfjetAK8muinsubjeta[ijet],pfjetAK8muinsubjphi[ijet],pfjetAK8muinsubjmass[ijet]);
              lepbj = lep + bj;

              selpfjetAK8muinsubptrat[iseljet] = (lep.Pt())/(lepbj.Pt());
              selpfjetAK8muinsubmassrat[iseljet] = (bj.M())/(lepbj.M());
              selpfjetAK8muinsubinvmass[iseljet] = lepbj.M();

	      if(isnan(selpfjetAK8muinsubptrat[iseljet])) {selpfjetAK8muinsubptrat[iseljet] = -100;}
	      if(isnan(selpfjetAK8muinsubmassrat[iseljet])) {selpfjetAK8muinsubmassrat[iseljet] = -100;}
	      if(isnan(selpfjetAK8muinsubinvmass[iseljet])) {selpfjetAK8muinsubinvmass[iseljet] = -100;}

	      selpfjetAK8matchedmuonisLoose[iseljet] = muonisLoose[nearest];
              selpfjetAK8matchedmuonisGoodGL[iseljet] = muonisGoodGL[nearest];
              selpfjetAK8matchedmuonisMed[iseljet] = muonisMed[nearest];
              selpfjetAK8matchedmuonisMedPr[iseljet] = muonisMedPr[nearest];
              selpfjetAK8matchedmuonisTight[iseljet] = muonisTight[nearest];
              selpfjetAK8matchedmuonisHighPt[iseljet] = muonisHighPt[nearest];
              selpfjetAK8matchedmuonisHighPttrk[iseljet] = muonisHighPttrk[nearest];

	      selpfjetAK8matchedmuonchi[iseljet] = muonchi[nearest];
              selpfjetAK8matchedmuonposmatch[iseljet] = muonposmatch[nearest];
              selpfjetAK8matchedmuontrkink[iseljet] = muontrkink[nearest];
              selpfjetAK8matchedmuonsegcom[iseljet] = muonsegcom[nearest];
              selpfjetAK8matchedmuonhit[iseljet] = muonthit[nearest];
              selpfjetAK8matchedmuonmst[iseljet] = muonmst[nearest];
              selpfjetAK8matchedmuontrkvtx[iseljet] = muontrkvtx[nearest];
              selpfjetAK8matchedmuondz[iseljet] = muondz[nearest];
              selpfjetAK8matchedmuonpixhit[iseljet] = muonpixhit[nearest];
              selpfjetAK8matchedmuontrklay[iseljet] = muontrklay[nearest];
              selpfjetAK8matchedmuonvalfrac[iseljet] = muonvalfrac[nearest];
	      iseljet++;
	      if(iseljet>=njetmxAK8) break;
	      //}
	    }
	  }
	}
    }
  }
  npfjetAK8_b = iseljet;
  //if (iseljet != 0) Tout5->Fill();	
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
