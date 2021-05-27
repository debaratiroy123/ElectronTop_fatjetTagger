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
  
  OutFile = new TProofOutputFile("testeltop_qcd2000toInflepv2_Jan2021Corr_19UL18.root");
  
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
  
  Tout1->Branch("selpfjetAK8matchedelsigmaieta",selpfjetAK8matchedelsigmaieta,"selpfjetAK8matchedelsigmaieta[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelsigmaiphi",selpfjetAK8matchedelsigmaiphi,"selpfjetAK8matchedelsigmaiphi[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelr9full",selpfjetAK8matchedelr9full,"selpfjetAK8matchedelr9full[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelsupcl_etaw",selpfjetAK8matchedelsupcl_etaw,"selpfjetAK8matchedelsupcl_etaw[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelsupcl_phiw",selpfjetAK8matchedelsupcl_phiw,"selpfjetAK8matchedelsupcl_phiw[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelhcaloverecal",selpfjetAK8matchedelhcaloverecal,"selpfjetAK8matchedelhcaloverecal[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelcloctftrkn",selpfjetAK8matchedelcloctftrkn,"selpfjetAK8matchedelcloctftrkn[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelcloctftrkchi2",selpfjetAK8matchedelcloctftrkchi2,"selpfjetAK8matchedelcloctftrkchi2[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedele1x5bye5x5",selpfjetAK8matchedele1x5bye5x5,"selpfjetAK8matchedele1x5bye5x5[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelnormchi2",selpfjetAK8matchedelnormchi2,"selpfjetAK8matchedelnormchi2[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelhitsmiss",selpfjetAK8matchedelhitsmiss,"selpfjetAK8matchedelhitsmiss[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedeltrkmeasure",selpfjetAK8matchedeltrkmeasure,"selpfjetAK8matchedeltrkmeasure[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelconvtxprob",selpfjetAK8matchedelconvtxprob,"selpfjetAK8matchedelconvtxprob[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelecloverpout",selpfjetAK8matchedelecloverpout,"selpfjetAK8matchedelecloverpout[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelecaletrkmomentum",selpfjetAK8matchedelecaletrkmomentum,"selpfjetAK8matchedelecaletrkmomentum[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedeldeltaetacltrkcalo",selpfjetAK8matchedeldeltaetacltrkcalo,"selpfjetAK8matchedeldeltaetacltrkcalo[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelsupcl_preshvsrawe",selpfjetAK8matchedelsupcl_preshvsrawe,"selpfjetAK8matchedelsupcl_preshvsrawe[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelpfisolsumphet",selpfjetAK8matchedelpfisolsumphet,"selpfjetAK8matchedelpfisolsumphet[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelpfisolsumchhadpt",selpfjetAK8matchedelpfisolsumchhadpt,"selpfjetAK8matchedelpfisolsumchhadpt[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelpfisolsumneuhadet",selpfjetAK8matchedelpfisolsumneuhadet,"selpfjetAK8matchedelpfisolsumneuhadet[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedeletain",selpfjetAK8matchedeletain,"selpfjetAK8matchedeletain[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelphiin",selpfjetAK8matchedelphiin,"selpfjetAK8matchedelphiin[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelfbrem",selpfjetAK8matchedelfbrem,"selpfjetAK8matchedelfbrem[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedeleoverp",selpfjetAK8matchedeleoverp,"selpfjetAK8matchedeleoverp[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelhovere",selpfjetAK8matchedelhovere,"selpfjetAK8matchedelhovere[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelRho", selpfjetAK8matchedelRho,"selpfjetAK8matchedelRho[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchedelptrel", selpfjetAK8matchedelptrel,"selpfjetAK8matchedelptrel[npfjetAK8_te]/F");
    
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
  Tout1->Branch("selpfjetAK8hastau",selpfjetAK8hastau,"selpfjetAK8hastau[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hashadtop_alldecay",selpfjetAK8hashadtop_alldecay,"selpfjetAK8hashadtop_alldecay[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hasleptop_alldecay",selpfjetAK8hasleptop_alldecay,"selpfjetAK8hasleptop_alldecay[npfjetAK8_te]/O");
  
  /*
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
    
    Tout2->Branch("selpfjetAK8matchedelsigmaieta",selpfjetAK8matchedelsigmaieta,"selpfjetAK8matchedelsigmaieta[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelsigmaiphi",selpfjetAK8matchedelsigmaiphi,"selpfjetAK8matchedelsigmaiphi[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelr9full",selpfjetAK8matchedelr9full,"selpfjetAK8matchedelr9full[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelsupcl_etaw",selpfjetAK8matchedelsupcl_etaw,"selpfjetAK8matchedelsupcl_etaw[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelsupcl_phiw",selpfjetAK8matchedelsupcl_phiw,"selpfjetAK8matchedelsupcl_phiw[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelhcaloverecal",selpfjetAK8matchedelhcaloverecal,"selpfjetAK8matchedelhcaloverecal[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelcloctftrkn",selpfjetAK8matchedelcloctftrkn,"selpfjetAK8matchedelcloctftrkn[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelcloctftrkchi2",selpfjetAK8matchedelcloctftrkchi2,"selpfjetAK8matchedelcloctftrkchi2[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedele1x5bye5x5",selpfjetAK8matchedele1x5bye5x5,"selpfjetAK8matchedele1x5bye5x5[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelnormchi2",selpfjetAK8matchedelnormchi2,"selpfjetAK8matchedelnormchi2[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelhitsmiss",selpfjetAK8matchedelhitsmiss,"selpfjetAK8matchedelhitsmiss[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedeltrkmeasure",selpfjetAK8matchedeltrkmeasure,"selpfjetAK8matchedeltrkmeasure[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelconvtxprob",selpfjetAK8matchedelconvtxprob,"selpfjetAK8matchedelconvtxprob[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelecloverpout",selpfjetAK8matchedelecloverpout,"selpfjetAK8matchedelecloverpout[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelecaletrkmomentum",selpfjetAK8matchedelecaletrkmomentum,"selpfjetAK8matchedelecaletrkmomentum[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedeldeltaetacltrkcalo",selpfjetAK8matchedeldeltaetacltrkcalo,"selpfjetAK8matchedeldeltaetacltrkcalo[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelsupcl_preshvsrawe",selpfjetAK8matchedelsupcl_preshvsrawe,"selpfjetAK8matchedelsupcl_preshvsrawe[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelpfisolsumphet",selpfjetAK8matchedelpfisolsumphet,"selpfjetAK8matchedelpfisolsumphet[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelpfisolsumchhadpt",selpfjetAK8matchedelpfisolsumchhadpt,"selpfjetAK8matchedelpfisolsumchhadpt[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelpfisolsumneuhadet",selpfjetAK8matchedelpfisolsumneuhadet,"selpfjetAK8matchedelpfisolsumneuhadet[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedeletain",selpfjetAK8matchedeletain,"selpfjetAK8matchedeletain[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelphiin",selpfjetAK8matchedelphiin,"selpfjetAK8matchedelphiin[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelfbrem",selpfjetAK8matchedelfbrem,"selpfjetAK8matchedelfbrem[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedeleoverp",selpfjetAK8matchedeleoverp,"selpfjetAK8matchedeleoverp[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelhovere",selpfjetAK8matchedelhovere,"selpfjetAK8matchedelhovere[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelRho", selpfjetAK8matchedelRho,"selpfjetAK8matchedelRho[npfjetAK8_tmu]/F");
    Tout2->Branch("selpfjetAK8matchedelptrel", selpfjetAK8matchedelptrel,"selpfjetAK8matchedelptrel[npfjetAK8_tmu]/F");
    
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
    
    Tout3->Branch("selpfjetAK8matchedelsigmaieta",selpfjetAK8matchedelsigmaieta,"selpfjetAK8matchedelsigmaieta[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelsigmaiphi",selpfjetAK8matchedelsigmaiphi,"selpfjetAK8matchedelsigmaiphi[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelr9full",selpfjetAK8matchedelr9full,"selpfjetAK8matchedelr9full[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelsupcl_etaw",selpfjetAK8matchedelsupcl_etaw,"selpfjetAK8matchedelsupcl_etaw[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelsupcl_phiw",selpfjetAK8matchedelsupcl_phiw,"selpfjetAK8matchedelsupcl_phiw[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelhcaloverecal",selpfjetAK8matchedelhcaloverecal,"selpfjetAK8matchedelhcaloverecal[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelcloctftrkn",selpfjetAK8matchedelcloctftrkn,"selpfjetAK8matchedelcloctftrkn[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelcloctftrkchi2",selpfjetAK8matchedelcloctftrkchi2,"selpfjetAK8matchedelcloctftrkchi2[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedele1x5bye5x5",selpfjetAK8matchedele1x5bye5x5,"selpfjetAK8matchedele1x5bye5x5[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelnormchi2",selpfjetAK8matchedelnormchi2,"selpfjetAK8matchedelnormchi2[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelhitsmiss",selpfjetAK8matchedelhitsmiss,"selpfjetAK8matchedelhitsmiss[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedeltrkmeasure",selpfjetAK8matchedeltrkmeasure,"selpfjetAK8matchedeltrkmeasure[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelconvtxprob",selpfjetAK8matchedelconvtxprob,"selpfjetAK8matchedelconvtxprob[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelecloverpout",selpfjetAK8matchedelecloverpout,"selpfjetAK8matchedelecloverpout[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelecaletrkmomentum",selpfjetAK8matchedelecaletrkmomentum,"selpfjetAK8matchedelecaletrkmomentum[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedeldeltaetacltrkcalo",selpfjetAK8matchedeldeltaetacltrkcalo,"selpfjetAK8matchedeldeltaetacltrkcalo[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelsupcl_preshvsrawe",selpfjetAK8matchedelsupcl_preshvsrawe,"selpfjetAK8matchedelsupcl_preshvsrawe[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelpfisolsumphet",selpfjetAK8matchedelpfisolsumphet,"selpfjetAK8matchedelpfisolsumphet[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelpfisolsumchhadpt",selpfjetAK8matchedelpfisolsumchhadpt,"selpfjetAK8matchedelpfisolsumchhadpt[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelpfisolsumneuhadet",selpfjetAK8matchedelpfisolsumneuhadet,"selpfjetAK8matchedelpfisolsumneuhadet[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedeletain",selpfjetAK8matchedeletain,"selpfjetAK8matchedeletain[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelphiin",selpfjetAK8matchedelphiin,"selpfjetAK8matchedelphiin[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelfbrem",selpfjetAK8matchedelfbrem,"selpfjetAK8matchedelfbrem[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedeleoverp",selpfjetAK8matchedeleoverp,"selpfjetAK8matchedeleoverp[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelhovere",selpfjetAK8matchedelhovere,"selpfjetAK8matchedelhovere[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelRho", selpfjetAK8matchedelRho,"selpfjetAK8matchedelRho[npfjetAK8_thad]/F");
    Tout3->Branch("selpfjetAK8matchedelptrel", selpfjetAK8matchedelptrel,"selpfjetAK8matchedelptrel[npfjetAK8_thad]/F");
    
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
    Tout3->Branch("selpfjetAK8hastau",selpfjetAK8hastau,"selpfjetAK8hastau[npfjetAK8_thad]/O");
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
  */
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
  
  Tout5->Branch("selpfjetAK8matchedelsigmaieta",selpfjetAK8matchedelsigmaieta,"selpfjetAK8matchedelsigmaieta[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelsigmaiphi",selpfjetAK8matchedelsigmaiphi,"selpfjetAK8matchedelsigmaiphi[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelr9full",selpfjetAK8matchedelr9full,"selpfjetAK8matchedelr9full[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelsupcl_etaw",selpfjetAK8matchedelsupcl_etaw,"selpfjetAK8matchedelsupcl_etaw[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelsupcl_phiw",selpfjetAK8matchedelsupcl_phiw,"selpfjetAK8matchedelsupcl_phiw[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelhcaloverecal",selpfjetAK8matchedelhcaloverecal,"selpfjetAK8matchedelhcaloverecal[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelcloctftrkn",selpfjetAK8matchedelcloctftrkn,"selpfjetAK8matchedelcloctftrkn[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelcloctftrkchi2",selpfjetAK8matchedelcloctftrkchi2,"selpfjetAK8matchedelcloctftrkchi2[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedele1x5bye5x5",selpfjetAK8matchedele1x5bye5x5,"selpfjetAK8matchedele1x5bye5x5[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelnormchi2",selpfjetAK8matchedelnormchi2,"selpfjetAK8matchedelnormchi2[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelhitsmiss",selpfjetAK8matchedelhitsmiss,"selpfjetAK8matchedelhitsmiss[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedeltrkmeasure",selpfjetAK8matchedeltrkmeasure,"selpfjetAK8matchedeltrkmeasure[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelconvtxprob",selpfjetAK8matchedelconvtxprob,"selpfjetAK8matchedelconvtxprob[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelecloverpout",selpfjetAK8matchedelecloverpout,"selpfjetAK8matchedelecloverpout[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelecaletrkmomentum",selpfjetAK8matchedelecaletrkmomentum,"selpfjetAK8matchedelecaletrkmomentum[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedeldeltaetacltrkcalo",selpfjetAK8matchedeldeltaetacltrkcalo,"selpfjetAK8matchedeldeltaetacltrkcalo[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelsupcl_preshvsrawe",selpfjetAK8matchedelsupcl_preshvsrawe,"selpfjetAK8matchedelsupcl_preshvsrawe[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelpfisolsumphet",selpfjetAK8matchedelpfisolsumphet,"selpfjetAK8matchedelpfisolsumphet[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelpfisolsumchhadpt",selpfjetAK8matchedelpfisolsumchhadpt,"selpfjetAK8matchedelpfisolsumchhadpt[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelpfisolsumneuhadet",selpfjetAK8matchedelpfisolsumneuhadet,"selpfjetAK8matchedelpfisolsumneuhadet[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedeletain",selpfjetAK8matchedeletain,"selpfjetAK8matchedeletain[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelphiin",selpfjetAK8matchedelphiin,"selpfjetAK8matchedelphiin[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelfbrem",selpfjetAK8matchedelfbrem,"selpfjetAK8matchedelfbrem[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedeleoverp",selpfjetAK8matchedeleoverp,"selpfjetAK8matchedeleoverp[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelhovere",selpfjetAK8matchedelhovere,"selpfjetAK8matchedelhovere[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelRho", selpfjetAK8matchedelRho,"selpfjetAK8matchedelRho[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchedelptrel", selpfjetAK8matchedelptrel,"selpfjetAK8matchedelptrel[npfjetAK8_b]/F");
  
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
  Tout5->Branch("selpfjetAK8hastau",selpfjetAK8hastau,"selpfjetAK8hastau[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_b]/O");
  /*
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
  */
#endif
    
  hist_Obs_re = new TH1D("Obs_re", "Obs_re", 25, -1.0, 1.0);
  hist_Obs_re->Sumw2();
  
  hist_Obs_re_sdmasscut = new TH1D("Obs_re_sdmasscut", "Obs_re_sdmasscut", 25, -1.0, 1.0);
  hist_Obs_re_sdmasscut->Sumw2();
  
  hist_Obs_re_tau21cut = new TH1D("Obs_re_tau21cut", "Obs_re_tau21cut", 25, -1.0, 1.0);
  hist_Obs_re_tau21cut->Sumw2();
  
  hist_Obs_re_sdmasscut_tau21cut = new TH1D("Obs_re_sdmasscut_tau21cut", "Obs_re_sdmasscut_tau21cut", 25, -1.0, 1.0);
  hist_Obs_re_sdmasscut_tau21cut->Sumw2();
  
  hist_Obs_mass = new TH1D("Obs_mass", "Obs_mass", 100, 0.0, 300.0);
  hist_Obs_mass->Sumw2();
  
  hist_Obs_pt = new TH1D("Obs_pt", "Obs_pt", 25, 400.0, 3100.);
  hist_Obs_pt->Sumw2();
  
  hist_count = new TH1D("hist_count", "hist_count", 10,-0.5,10.5);
  hist_count->Sumw2();

  hist_Obs_sdmass = new TH1D("Obs_sdmass", "Obs_sdmass", 100, 0.0, 300.0);
  hist_Obs_sdmass->Sumw2();
  
  hist_Obs_tau21 = new TH1D("Obs_tau21", "Obs_tau21", 100, 0.0, 1.0);
  hist_Obs_tau21->Sumw2();
  
  hist_Obs_re_hasel = new TH1D("Obs_re_hasel", "Obs_re_hasel", 25, -1.0, 1.0);
  hist_Obs_re_hasel->Sumw2();
  
  hist_Obs_mass_hasel = new TH1D("Obs_mass_hasel", "Obs_mass_hasel", 100, 0.0, 300.0);
  hist_Obs_mass_hasel->Sumw2();
  
  hist_Obs_sdmass_hasel = new TH1D("Obs_sdmass_hasel", "Obs_sdmass_hasel", 100, 0.0, 300.0);
  hist_Obs_sdmass_hasel->Sumw2();
  
  hist_Obs_tau21_hasel = new TH1D("Obs_tau21_hasel", "Obs_tau21_hasel", 100, 0.0, 1.0);
  hist_Obs_tau21_hasel->Sumw2();
  
  hist_Obs_re_hasel_hasb = new TH1D("Obs_re_hasel_hasb", "Obs_re_hasel_hasb", 25, -1.0, 1.0);
  hist_Obs_re_hasel_hasb->Sumw2();
  
  hist_Obs_re_hasel_hasleptop = new TH1D("Obs_re_hasel_hasleptop", "Obs_re_hasel_hasleptop", 25, -1.0, 1.0);
  hist_Obs_re_hasel_hasleptop->Sumw2();
  
  
  hist_Obs_re_hasel_hasleptop_hastop = new TH1D("Obs_re_hasel_hasleptop_hastop", "Obs_re_hasel_hasleptop_hastop", 25, -1.0, 1.0);
  hist_Obs_re_hasel_hasleptop_hastop->Sumw2();
  
  hist_Obs_re_hasel_hasleptop_hastop_hasalltopdecay = new TH1D("Obs_re_hasel_hasleptop_hastop_hasalltopdecay", "Obs_re_hasel_hasleptop_hastop_hasalltopdecay", 25, -1.0, 1.0);
  hist_Obs_re_hasel_hasleptop_hastop_hasalltopdecay->Sumw2();
  
  hist_Obs_re_tecond = new TH1D("Obs_re_tecond", "Obs_re_tecond", 25, -1.0, 1.0);
  hist_Obs_re_tecond->Sumw2();
  
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
    
    sprintf(name,"%s_thad",branchnames[ihist]);
    hist_3[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
    hist_3[ihist]->Sumw2();
    
    sprintf(name,"%s_qg",branchnames[ihist]);
    hist_4[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
    hist_4[ihist]->Sumw2();
    
    
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
	
	//TString str2 = TString::Format("tau here");                                                         
	//if(gProofServ) gProofServ->SendAsynMessage(str2);
	
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
    
    /*
      bool elidsel = true;
      bool event_sel = false;
      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
      {
      if (nelecs > 0) {
      float dR_min(0.1); int nearest(-1);
      for(int el=0; el<nelecs; el++){
      float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
      if (dR < dR_min) {
      dR_min = dR;
      nearest = el;
      }}
      if (nearest >= 0) {
      if (elmvaid_noIso[nearest] == 0) elidsel = false;
      if (eldxy_sv[nearest] != 1000) event_sel = true;
      }
      }
      }
    */
    //if (elidsel == 0) continue;                                                                                
    //if (event_sel == 0) continue;
    //if (event_sel == 1) {
    
    pfjetAK8pt[ijet] *= pfjetAK8JEC[ijet] ;
    pfjetAK8mass[ijet] *= pfjetAK8JEC[ijet];
    
    if(isMC){
      pfjetAK8pt[ijet] *= (1+pfjetAK8reso[ijet]) ;
      pfjetAK8mass[ijet] *= (1+pfjetAK8reso[ijet]) ;
      pfjetAK8sdmass[ijet] *= (1+pfjetAK8reso[ijet]) ;
    }
    if(pfjetAK8pt[ijet] < ptcut) continue;
    if (pfjetAK8elinsubpt[ijet] < 0 && pfjetAK8elinsubjpt[ijet]< 0) continue;
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
    
    pfjetAK8elinsubpt[fjet] = pfjetAK8elinsubpt[ijet];
    pfjetAK8elinsubeta[fjet] = pfjetAK8elinsubeta[ijet];
    pfjetAK8elinsubphi[fjet] = pfjetAK8elinsubphi[ijet];
    pfjetAK8elinsube[fjet] = pfjetAK8elinsube[ijet];
    pfjetAK8elinsubjpt[fjet] = pfjetAK8elinsubjpt[ijet];
    pfjetAK8elinsubjeta[fjet] = pfjetAK8elinsubjeta[ijet];
    pfjetAK8elinsubjphi[fjet] = pfjetAK8elinsubjphi[ijet];
    pfjetAK8elinsubjmass[fjet] = pfjetAK8elinsubjmass[ijet];
    
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
	//if(!pfjetAK8hashadtop[fjet]) continue;
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
    if(isnan(pfjetAK8elsubjptrat[ijet])) { pfjetAK8elsubjptrat[ijet] = -100; }
    if(isnan(pfjetAK8elinsubpt[ijet])) { pfjetAK8elinsubpt[ijet] = -100; }
    if(isnan(pfjetAK8elinsubeta[ijet])) { pfjetAK8elinsubeta[ijet] = -100; }
    if(isnan(pfjetAK8elinsubphi[ijet])) { pfjetAK8elinsubphi[ijet] = -100; }
    if(isnan(pfjetAK8elinsube[ijet])) { pfjetAK8elinsube[ijet] = -100; }
    if(isnan(pfjetAK8elinsubjpt[ijet])) { pfjetAK8elinsubjpt[ijet] = -100; }
    if(isnan(pfjetAK8elinsubjeta[ijet])) { pfjetAK8elinsubjeta[ijet] = -100; }
    if(isnan(pfjetAK8elinsubjphi[ijet])) { pfjetAK8elinsubjphi[ijet] = -100; }
    if(isnan(pfjetAK8elinsubjmass[ijet])) { pfjetAK8elinsubjmass[ijet] = -100; }
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
    in_pfjetAK8matchedelhovere = -999;
    //in_pfjetAK8matchedelptrel = -999;

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
	    in_pfjetAK8eldxy_sv = eldxy_sv[nearest];
	    //in_pfjetAK8matchedelID = elmvaid_noIso[nearest];
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
	    //in_pfjetAK8matchedelptrel = will add if performance shown as better using this in training 
	  }
	  pfjetAK8_hasmatche[ijet] = (nearest >= 0 && eldxy_sv[nearest] != 1000)?true:false;
	}
      }  
    if (!isnan(Rho)) in_pfjetAK8matchedelRho = Rho;
    else in_pfjetAK8matchedelRho = -999;
    
    pfjetAK8re_tvsb[ijet] = -100;
    
    Re = reader1->EvaluateMVA("BDTG method");
    pfjetAK8re_tvsb[ijet] = Re;
    
    in_pfjetAK8_bbyW_E = pfjetAK8_bbyW_E[ijet];
    in_pfjetAK8_Kfactor = pfjetAK8_Kfactor[ijet];
    
    Float_t Rnu(-100);
    
    Rnu = reader2->EvaluateMVA("BDTG method");
    pfjetAK8rnu_tvsb[ijet] = Rnu;
    
    bool te_cond = false;
    bool tmu_cond = false;
    bool thad_cond = false;
    bool qg_cond = false;
    bool b_cond = false;
  
    te_cond  = (pfjetAK8haselectron[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]);
    tmu_cond = (pfjetAK8hasmuon[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]);
    thad_cond = (pfjetAK8hashadtop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hashadtop_alldecay[ijet]); //why not also hasb and hasqq as well
    //thad_cond = ((pfjetAK8hashadtop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hashadtop_alldecay[ijet]) || (pfjetAK8hastau[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]));
    //tmu_cond = ((pfjetAK8hasmuon[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]) || (pfjetAK8hastau[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]));
    qg_cond = (pfjetAK8hasqg[ijet] && !(pfjetAK8hashadtop[ijet]) && !(pfjetAK8hasleptop[ijet]) && !(pfjetAK8hastop[ijet]));
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
	    if (nearest >= 0 && eldxy_sv[nearest] != 1000) {
	      /*if (ijet == 0) {
		if (Isolpass == 0) helinidiso->Fill(0.5,weight);
		if (Isolpass == 1) helinidiso->Fill(1.5,weight);
		if (Isolpass == 0 && elmvaid_noIso[nearest] == 1) helinidiso->Fill(2.5,weight);
		if (Isolpass == 1 && elmvaid_noIso[nearest] == 1) helinidiso->Fill(3.5,weight);
		}
		if (Re > 0.93) {
		if (ijet == 0) {
		if (Isolpass == 0) hreelinidiso_str->Fill(0.5,weight);
		if (Isolpass == 1) hreelinidiso_str->Fill(1.5,weight);
		if (Isolpass == 0 && elmvaid_noIso[nearest] == 1) hreelinidiso_str->Fill(2.5,weight);
		if (Isolpass == 1 && elmvaid_noIso[nearest] == 1) hreelinidiso_str->Fill(3.5,weight);
		}
		}
		if (Re > 0.3) {
		if (ijet == 0) {
		if (Isolpass == 0) hreelinidiso->Fill(0.5,weight);
		if (Isolpass == 1) hreelinidiso->Fill(1.5,weight);
		if (Isolpass == 0 && elmvaid_noIso[nearest] == 1) hreelinidiso->Fill(2.5,weight);
		if (Isolpass == 1 && elmvaid_noIso[nearest] == 1) hreelinidiso->Fill(3.5,weight);
		}
		}*/
	      //}
	      //if (nearest == -1) {
	      /*hist_1[0]->Fill(pfjetAK8pt[ijet],weight);
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
		
		hist_1[47]->Fill(eldxy_sv[nearest],weight);
		hist_1[48]->Fill(elsigmaieta[nearest],weight);
		hist_1[49]->Fill(elsigmaiphi[nearest],weight);
		hist_1[50]->Fill(elr9full[nearest],weight);
		hist_1[51]->Fill(elsupcl_etaw[nearest],weight);
		hist_1[52]->Fill(elsupcl_phiw[nearest],weight);
		hist_1[53]->Fill(elhcaloverecal[nearest],weight);
		hist_1[54]->Fill(elcloctftrkn[nearest],weight);
		hist_1[55]->Fill(elcloctftrkchi2[nearest],weight);
		hist_1[56]->Fill(ele1x5bye5x5[nearest],weight);
		hist_1[57]->Fill(elnormchi2[nearest],weight);
		hist_1[58]->Fill(elhitsmiss[nearest],weight);
		hist_1[59]->Fill(eltrkmeasure[nearest],weight);
		hist_1[60]->Fill(elecloverpout[nearest],weight);
		hist_1[61]->Fill(elecaletrkmomentum[nearest],weight);
		hist_1[62]->Fill(eldeltaetacltrkcalo[nearest],weight);
		hist_1[63]->Fill(elsupcl_preshvsrawe[nearest],weight);
		hist_1[64]->Fill(elpfisolsumphet[nearest],weight);
		hist_1[65]->Fill(elpfisolsumchhadpt[nearest],weight);
		hist_1[66]->Fill(elpfsiolsumneuhadet[nearest],weight);
		hist_1[67]->Fill(eletain[nearest],weight);
		hist_1[68]->Fill(elphiin[nearest],weight);
		hist_1[69]->Fill(elfbrem[nearest],weight);
		hist_1[70]->Fill(eleoverp[nearest],weight);
		hist_1[71]->Fill(elhovere[nearest],weight);
		hist_1[72]->Fill(Rho,weight);
		hist_1[73]->Fill(fabs(elpt[nearest]),weight);
		hist_1[74]->Fill(elsupcl_eta[nearest],weight);*/
	      // h2d_re_rnu_1->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
	    }
    	  }
    	}
    }
    
    
    if(tmu_cond){
      
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
	      
	      /*
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
		hist_2[47]->Fill(eldxy_sv[nearest],weight);
		hist_2[48]->Fill(elsigmaieta[nearest],weight);
		hist_2[49]->Fill(elsigmaiphi[nearest],weight);
		hist_2[50]->Fill(elr9full[nearest],weight);
		hist_2[51]->Fill(elsupcl_etaw[nearest],weight);
		hist_2[52]->Fill(elsupcl_phiw[nearest],weight);
		hist_2[53]->Fill(elhcaloverecal[nearest],weight);
		hist_2[54]->Fill(elcloctftrkn[nearest],weight);
		hist_2[55]->Fill(elcloctftrkchi2[nearest],weight);
		hist_2[56]->Fill(ele1x5bye5x5[nearest],weight);
		hist_2[57]->Fill(elnormchi2[nearest],weight);
		hist_2[58]->Fill(elhitsmiss[nearest],weight);
		hist_2[59]->Fill(eltrkmeasure[nearest],weight);
		hist_2[60]->Fill(elecloverpout[nearest],weight);
		hist_2[61]->Fill(elecaletrkmomentum[nearest],weight);
		hist_2[62]->Fill(eldeltaetacltrkcalo[nearest],weight);
		hist_2[63]->Fill(elsupcl_preshvsrawe[nearest],weight);
		hist_2[64]->Fill(elpfisolsumphet[nearest],weight);
		hist_2[65]->Fill(elpfisolsumchhadpt[nearest],weight);
		hist_2[66]->Fill(elpfsiolsumneuhadet[nearest],weight);
		hist_2[67]->Fill(eletain[nearest],weight);
		hist_2[68]->Fill(elphiin[nearest],weight);
		hist_2[69]->Fill(elfbrem[nearest],weight);
		hist_2[70]->Fill(eleoverp[nearest],weight);
		hist_2[71]->Fill(elhovere[nearest],weight);
		hist_2[72]->Fill(Rho,weight);
		hist_2[73]->Fill(fabs(elpt[nearest]),weight);
		hist_2[74]->Fill(elsupcl_eta[nearest],weight);*/
	      //h2d_re_rnu_2->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
	    }
	  }
	}
    }
  
    if(thad_cond){
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
	      /*
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
		hist_3[47]->Fill(eldxy_sv[nearest],weight);
		hist_3[48]->Fill(elsigmaieta[nearest],weight);
		hist_3[49]->Fill(elsigmaiphi[nearest],weight);
		hist_3[50]->Fill(elr9full[nearest],weight);
		hist_3[51]->Fill(elsupcl_etaw[nearest],weight);
		hist_3[52]->Fill(elsupcl_phiw[nearest],weight);
		hist_3[53]->Fill(elhcaloverecal[nearest],weight);
		hist_3[54]->Fill(elcloctftrkn[nearest],weight);
		hist_3[55]->Fill(elcloctftrkchi2[nearest],weight);
		hist_3[56]->Fill(ele1x5bye5x5[nearest],weight);
		hist_3[57]->Fill(elnormchi2[nearest],weight);
		hist_3[58]->Fill(elhitsmiss[nearest],weight);
		hist_3[59]->Fill(eltrkmeasure[nearest],weight);
		hist_3[60]->Fill(elecloverpout[nearest],weight);
		hist_3[61]->Fill(elecaletrkmomentum[nearest],weight);
		hist_3[62]->Fill(eldeltaetacltrkcalo[nearest],weight);
		hist_3[63]->Fill(elsupcl_preshvsrawe[nearest],weight);
		hist_3[64]->Fill(elpfisolsumphet[nearest],weight);
		hist_3[65]->Fill(elpfisolsumchhadpt[nearest],weight);
		hist_3[66]->Fill(elpfsiolsumneuhadet[nearest],weight);
		hist_3[67]->Fill(eletain[nearest],weight);
		hist_3[68]->Fill(elphiin[nearest],weight);
		hist_3[69]->Fill(elfbrem[nearest],weight);
		hist_3[70]->Fill(eleoverp[nearest],weight);
		hist_3[71]->Fill(elhovere[nearest],weight);
		hist_3[72]->Fill(Rho,weight);
		hist_3[73]->Fill(fabs(elpt[nearest]),weight);
		hist_3[74]->Fill(elsupcl_eta[nearest],weight);*/
	      //h2d_re_rnu_3->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
	    }
	  }
	}
    }
    if(qg_cond){
      
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
	      /*
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
		hist_4[47]->Fill(eldxy_sv[nearest],weight);
                hist_4[48]->Fill(elsigmaieta[nearest],weight);
                hist_4[49]->Fill(elsigmaiphi[nearest],weight);
                hist_4[50]->Fill(elr9full[nearest],weight);
                hist_4[51]->Fill(elsupcl_etaw[nearest],weight);
                hist_4[52]->Fill(elsupcl_phiw[nearest],weight);
                hist_4[53]->Fill(elhcaloverecal[nearest],weight);
                hist_4[54]->Fill(elcloctftrkn[nearest],weight);
                hist_4[55]->Fill(elcloctftrkchi2[nearest],weight);
                hist_4[56]->Fill(ele1x5bye5x5[nearest],weight);
                hist_4[57]->Fill(elnormchi2[nearest],weight);
                hist_4[58]->Fill(elhitsmiss[nearest],weight);
                hist_4[59]->Fill(eltrkmeasure[nearest],weight);
                hist_4[60]->Fill(elecloverpout[nearest],weight);
                hist_4[61]->Fill(elecaletrkmomentum[nearest],weight);
                hist_4[62]->Fill(eldeltaetacltrkcalo[nearest],weight);
                hist_4[63]->Fill(elsupcl_preshvsrawe[nearest],weight);
                hist_4[64]->Fill(elpfisolsumphet[nearest],weight);
                hist_4[65]->Fill(elpfisolsumchhadpt[nearest],weight);
                hist_4[66]->Fill(elpfsiolsumneuhadet[nearest],weight);
                hist_4[67]->Fill(eletain[nearest],weight);
                hist_4[68]->Fill(elphiin[nearest],weight);
                hist_4[69]->Fill(elfbrem[nearest],weight);
                hist_4[70]->Fill(eleoverp[nearest],weight);
                hist_4[71]->Fill(elhovere[nearest],weight);
                hist_4[72]->Fill(Rho,weight);
                hist_4[73]->Fill(fabs(elpt[nearest]),weight);
                hist_4[74]->Fill(elsupcl_eta[nearest],weight);*/
		//h2d_re_rnu_4->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
	    }
	  }
	}
    }
    
    if(b_cond){
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
	      /*if (ijet == 0) {
                if (Isolpass == 0) helinidiso->Fill(0.5,weight);
                if (Isolpass == 1) helinidiso->Fill(1.5,weight);
                if (Isolpass == 0 && elmvaid_noIso[nearest] == 1) helinidiso->Fill(2.5,weight);
                if (Isolpass == 1 && elmvaid_noIso[nearest] == 1) helinidiso->Fill(3.5,weight);
		}
		if (Re > 0.93) {
                if (ijet == 0) {
		if (Isolpass == 0) hreelinidiso_str->Fill(0.5,weight);
		if (Isolpass == 1) hreelinidiso_str->Fill(1.5,weight);
		if (Isolpass == 0 && elmvaid_noIso[nearest] == 1) hreelinidiso_str->Fill(2.5,weight);
		if (Isolpass == 1 && elmvaid_noIso[nearest] == 1) hreelinidiso_str->Fill(3.5,weight);
		}
		}
              if (Re > 0.3) {
	      if (ijet == 0) {
	      if (Isolpass == 0) hreelinidiso->Fill(0.5,weight);
	      if (Isolpass == 1) hreelinidiso->Fill(1.5,weight);
	      if (Isolpass == 0 && elmvaid_noIso[nearest] == 1) hreelinidiso->Fill(2.5,weight);
	      if (Isolpass == 1 && elmvaid_noIso[nearest] == 1) hreelinidiso->Fill(3.5,weight);
	      }
	      }*/
	      //}
	      //if (nearest == -1) {
	      /*hist_5[0]->Fill(pfjetAK8pt[ijet],weight);
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
	      
	      hist_5[47]->Fill(eldxy_sv[nearest],weight);
	      hist_5[48]->Fill(elsigmaieta[nearest],weight);
	      hist_5[49]->Fill(elsigmaiphi[nearest],weight);
	      hist_5[50]->Fill(elr9full[nearest],weight);
	      hist_5[51]->Fill(elsupcl_etaw[nearest],weight);
	      hist_5[52]->Fill(elsupcl_phiw[nearest],weight);
	      hist_5[53]->Fill(elhcaloverecal[nearest],weight);
	      hist_5[54]->Fill(elcloctftrkn[nearest],weight);
	      hist_5[55]->Fill(elcloctftrkchi2[nearest],weight);
	      hist_5[56]->Fill(ele1x5bye5x5[nearest],weight);
	      hist_5[57]->Fill(elnormchi2[nearest],weight);
	      hist_5[58]->Fill(elhitsmiss[nearest],weight);
	      hist_5[59]->Fill(eltrkmeasure[nearest],weight);
	      hist_5[60]->Fill(elecloverpout[nearest],weight);
	      hist_5[61]->Fill(elecaletrkmomentum[nearest],weight);
	      hist_5[62]->Fill(eldeltaetacltrkcalo[nearest],weight);
	      hist_5[63]->Fill(elsupcl_preshvsrawe[nearest],weight);
	      hist_5[64]->Fill(elpfisolsumphet[nearest],weight);
	      hist_5[65]->Fill(elpfisolsumchhadpt[nearest],weight);
	      hist_5[66]->Fill(elpfsiolsumneuhadet[nearest],weight);
	      hist_5[67]->Fill(eletain[nearest],weight);
	      hist_5[68]->Fill(elphiin[nearest],weight);
	      hist_5[69]->Fill(elfbrem[nearest],weight);
	      hist_5[70]->Fill(eleoverp[nearest],weight);
	      hist_5[71]->Fill(elhovere[nearest],weight);
	      hist_5[72]->Fill(Rho,weight);
	      hist_5[73]->Fill(fabs(elpt[nearest]),weight);
	      hist_5[74]->Fill(elsupcl_eta[nearest],weight);*/
	      //h2d_re_rnu_5->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
	    }
	  }
    	}
    }
  }//ijet
  //}//npfjetAK8 > 0
  //TString str1 = TString::Format("tr_count %d \n",tr_count);                                                              
  //if(gProofServ) gProofServ->SendAsynMessage(str1);
 
  int telcand1 = -1;
  bool te_found1 = false;
  bool te_cond1(false);
  int nelcand1 = 0;
  
  
  float BDT_score1(-100.);
  /*if (SemiLeptt && EJets){
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
	}*/
  
  int t_cand = -1;
  double remax = -200;
  for(int ijet=0; ijet < npfjetAK8; ijet++){
    if(pfjetAK8re_tvsb[ijet] > remax){
      remax = pfjetAK8re_tvsb[ijet];
      t_cand = ijet;
    }
  }
  
  /*
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
  */
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
	}
  */
  
#ifdef TRAINING
  int iseljet = 0;
  npfjetAK8_te = 0;
  
  for(int ijet=0; ijet< npfjetAK8; ++ijet){
    
    if(ijet>(nmaxjet-1)) break;
    
    bool te_cond = false;
    te_cond  = (pfjetAK8haselectron[ijet] == 1 && pfjetAK8hasleptop[ijet] == 1 && pfjetAK8hastop[ijet] == 1 && pfjetAK8hasleptop_alldecay[ijet] == 1);
    
    if(te_cond == 1){
      bool gsfmatch(true);
      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
	{
	  //hist_event_count_total_pfel->Fill(1,weight);
	  if (nelecs > 0) {
	    float dR_min(0.4); int nearest(-1);
	    for(int el=0; el<nelecs; el++){
	      float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
	      if (dR < dR_min) {
		dR_min = dR;
		nearest = el;
	      }
	    }
	    /*
	      change when to study not matched gsf or no PFel option }
	      if (nearest == -1) {
	      gsfmatch = false;
	      }
	      if (nearest >= 0) hist_event_count_pass_matchgsf->Fill(1,weight);
	      }
	      }
	      // if (gsfmatch == 0 || (pfjetAK8elinsubeta[ijet] == -100 && pfjetAK8elinsubphi[ijet] == -100))*/
	    if (nearest >= 0 && eldxy_sv[nearest] != 1000) {
	      
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
	      
	      TLorentzVector lj_mom; 
	      lj_mom.SetPtEtaPhiM(pfjetAK8pt[ijet],pfjetAK8y[ijet],pfjetAK8phi[ijet],pfjetAK8mass[ijet]);
	      //TLorentzVector pfel; pfel.SetPtEtaPhiE(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet],pfjetAK8elinsube[ijet]);
	      TLorentzVector gsfel; 
	      gsfel.SetPtEtaPhiE(fabs(elpt[nearest]),eleta[nearest],elphi[nearest],ele[nearest]);
	      selpfjetAK8matchedelptrel[iseljet] = ((gsfel.Vect()).Perp(lj_mom.Vect()));
	      
	      
	      if (isnan(Rho)) { 
		selpfjetAK8matchedelRho[iseljet] = -100; 
	      }
	      else
		selpfjetAK8matchedelRho[iseljet] = Rho;
	      
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
	      selpfjetAK8matchedelsigmaieta[iseljet] = elsigmaieta[nearest]; 
	      selpfjetAK8matchedelsigmaiphi[iseljet] = elsigmaiphi[nearest];
	      selpfjetAK8matchedelr9full[iseljet] = elr9full[nearest];
	      selpfjetAK8matchedelsupcl_etaw[iseljet] = elsupcl_etaw[nearest];
	      selpfjetAK8matchedelsupcl_phiw[iseljet] = elsupcl_phiw[nearest];
	      selpfjetAK8matchedelhcaloverecal[iseljet] = elhcaloverecal[nearest];
	      selpfjetAK8matchedelcloctftrkn[iseljet] = elcloctftrkn[nearest];
	      selpfjetAK8matchedelcloctftrkchi2[iseljet] = elcloctftrkchi2[nearest];
	      selpfjetAK8matchedele1x5bye5x5[iseljet] = ele1x5bye5x5[nearest];
	      selpfjetAK8matchedelnormchi2[iseljet] = elnormchi2[nearest];
	      selpfjetAK8matchedelhitsmiss[iseljet] = elhitsmiss[nearest];
	      selpfjetAK8matchedeltrkmeasure[iseljet] = eltrkmeasure[nearest];
	      selpfjetAK8matchedelconvtxprob[iseljet] = elconvtxprob[nearest];
	      selpfjetAK8matchedelecloverpout[iseljet] = elecloverpout[nearest];
	      selpfjetAK8matchedelecaletrkmomentum[iseljet] = elecaletrkmomentum[nearest];
	      selpfjetAK8matchedeldeltaetacltrkcalo[iseljet] = eldeltaetacltrkcalo[nearest];
	      selpfjetAK8matchedelsupcl_preshvsrawe[iseljet] = elsupcl_preshvsrawe[nearest];
	      selpfjetAK8matchedelpfisolsumphet[iseljet] = elpfisolsumphet[nearest];
	      selpfjetAK8matchedelpfisolsumchhadpt[iseljet] = elpfisolsumchhadpt[nearest];
	      selpfjetAK8matchedelpfisolsumneuhadet[iseljet] = elpfsiolsumneuhadet[nearest];
	      selpfjetAK8matchedeletain[iseljet] = eletain[nearest];
	      selpfjetAK8matchedelphiin[iseljet] = elphiin[nearest];
	      selpfjetAK8matchedelfbrem[iseljet] = elfbrem[nearest];
	      selpfjetAK8matchedeleoverp[iseljet] = eleoverp[nearest];
	      selpfjetAK8matchedelhovere[iseljet] = elhovere[nearest];
	      
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
	      selpfjetAK8hastau[iseljet] =  pfjetAK8hastau[ijet];
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
	}
    }
  }
  npfjetAK8_te = iseljet;
  if (iseljet != 0) Tout1->Fill();
  
  
  iseljet = 0;
  npfjetAK8_tmu = 0;
  
  for(int ijet=0; ijet< npfjetAK8; ijet++){
    
    if(ijet>(nmaxjet-1)) break;
    
    bool tmu_cond = false;
    tmu_cond = ((pfjetAK8hasmuon[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]) || (pfjetAK8hastau[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]));
    
    if(tmu_cond){
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
	      
	      /*
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
		}
		}
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
	      */
	      
	      if (isnan(Rho)) {
                selpfjetAK8matchedelRho[iseljet] = -100;
              }
              else
                selpfjetAK8matchedelRho[iseljet] = Rho;
	      
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
              selpfjetAK8matchedelsigmaieta[iseljet] = elsigmaieta[nearest];
              selpfjetAK8matchedelsigmaiphi[iseljet] = elsigmaiphi[nearest];
              selpfjetAK8matchedelr9full[iseljet] = elr9full[nearest];
              selpfjetAK8matchedelsupcl_etaw[iseljet] = elsupcl_etaw[nearest];
              selpfjetAK8matchedelsupcl_phiw[iseljet] = elsupcl_phiw[nearest];
              selpfjetAK8matchedelhcaloverecal[iseljet] = elhcaloverecal[nearest];
              selpfjetAK8matchedelcloctftrkn[iseljet] = elcloctftrkn[nearest];
              selpfjetAK8matchedelcloctftrkchi2[iseljet] = elcloctftrkchi2[nearest];
              selpfjetAK8matchedele1x5bye5x5[iseljet] = ele1x5bye5x5[nearest];
              selpfjetAK8matchedelnormchi2[iseljet] = elnormchi2[nearest];
              selpfjetAK8matchedelhitsmiss[iseljet] = elhitsmiss[nearest];
              selpfjetAK8matchedeltrkmeasure[iseljet] = eltrkmeasure[nearest];
              selpfjetAK8matchedelconvtxprob[iseljet] = elconvtxprob[nearest];
              selpfjetAK8matchedelecloverpout[iseljet] = elecloverpout[nearest];
              selpfjetAK8matchedelecaletrkmomentum[iseljet] = elecaletrkmomentum[nearest];
              selpfjetAK8matchedeldeltaetacltrkcalo[iseljet] = eldeltaetacltrkcalo[nearest];
              selpfjetAK8matchedelsupcl_preshvsrawe[iseljet] = elsupcl_preshvsrawe[nearest];
              selpfjetAK8matchedelpfisolsumphet[iseljet] = elpfisolsumphet[nearest];
              selpfjetAK8matchedelpfisolsumchhadpt[iseljet] = elpfisolsumchhadpt[nearest];
              selpfjetAK8matchedelpfisolsumneuhadet[iseljet] = elpfsiolsumneuhadet[nearest];
              selpfjetAK8matchedeletain[iseljet] = eletain[nearest];
              selpfjetAK8matchedelphiin[iseljet] = elphiin[nearest];
              selpfjetAK8matchedelfbrem[iseljet] = elfbrem[nearest];
              selpfjetAK8matchedeleoverp[iseljet] = eleoverp[nearest];
              selpfjetAK8matchedelhovere[iseljet] = elhovere[nearest];
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
              selpfjetAK8hastau[iseljet] =  pfjetAK8hastau[ijet];
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
	}
    }
  }
  npfjetAK8_tmu = iseljet;
  //Tout2->Fill();
   
  iseljet = 0;
  npfjetAK8_thad = 0;
  bool isnoel(false);
  for(int ijet=0; ijet< npfjetAK8; ijet++){
    
    if(ijet>(nmaxjet-1)) break;
    
    bool thad_cond = false;
     thad_cond = (pfjetAK8hashadtop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hashadtop_alldecay[ijet]);
    //thad_cond = ((pfjetAK8hashadtop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hashadtop_alldecay[ijet]) || (pfjetAK8hastau[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]));
     
     if(thad_cond){
       
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
	     //if (nearest == -1) {isnoel = true; continue;}
            if (nearest >= 0 && eldxy_sv[nearest] != 1000) {
	      
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
	      
	      	      
	      if (isnan(Rho)) {
                selpfjetAK8matchedelRho[iseljet] = -100;
              }
              else
                selpfjetAK8matchedelRho[iseljet] = Rho;
	      
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
              selpfjetAK8matchedelsigmaieta[iseljet] = elsigmaieta[nearest];
              selpfjetAK8matchedelsigmaiphi[iseljet] = elsigmaiphi[nearest];
              selpfjetAK8matchedelr9full[iseljet] = elr9full[nearest];
              selpfjetAK8matchedelsupcl_etaw[iseljet] = elsupcl_etaw[nearest];
              selpfjetAK8matchedelsupcl_phiw[iseljet] = elsupcl_phiw[nearest];
              selpfjetAK8matchedelhcaloverecal[iseljet] = elhcaloverecal[nearest];
              selpfjetAK8matchedelcloctftrkn[iseljet] = elcloctftrkn[nearest];
              selpfjetAK8matchedelcloctftrkchi2[iseljet] = elcloctftrkchi2[nearest];
              selpfjetAK8matchedele1x5bye5x5[iseljet] = ele1x5bye5x5[nearest];
              selpfjetAK8matchedelnormchi2[iseljet] = elnormchi2[nearest];
              selpfjetAK8matchedelhitsmiss[iseljet] = elhitsmiss[nearest];
              selpfjetAK8matchedeltrkmeasure[iseljet] = eltrkmeasure[nearest];
              selpfjetAK8matchedelconvtxprob[iseljet] = elconvtxprob[nearest];
              selpfjetAK8matchedelecloverpout[iseljet] = elecloverpout[nearest];
              selpfjetAK8matchedelecaletrkmomentum[iseljet] = elecaletrkmomentum[nearest];
              selpfjetAK8matchedeldeltaetacltrkcalo[iseljet] = eldeltaetacltrkcalo[nearest];
              selpfjetAK8matchedelsupcl_preshvsrawe[iseljet] = elsupcl_preshvsrawe[nearest];
              selpfjetAK8matchedelpfisolsumphet[iseljet] = elpfisolsumphet[nearest];
              selpfjetAK8matchedelpfisolsumchhadpt[iseljet] = elpfisolsumchhadpt[nearest];
              selpfjetAK8matchedelpfisolsumneuhadet[iseljet] = elpfsiolsumneuhadet[nearest];
              selpfjetAK8matchedeletain[iseljet] = eletain[nearest];
              selpfjetAK8matchedelphiin[iseljet] = elphiin[nearest];
              selpfjetAK8matchedelfbrem[iseljet] = elfbrem[nearest];
              selpfjetAK8matchedeleoverp[iseljet] = eleoverp[nearest];
              selpfjetAK8matchedelhovere[iseljet] = elhovere[nearest];
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
	      selpfjetAK8hastau[iseljet] =  pfjetAK8hastau[ijet];
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
	}
    }
  }
 
    npfjetAK8_thad = iseljet;
    //  Tout3->Fill();
 
 
    /*
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
  //Tout4->Fill();	
  */
  
  iseljet = 0;
  npfjetAK8_b = 0;

  for(int ijet=0; ijet< npfjetAK8; ijet++){
  
    if(ijet>(nmaxjet-1)) break;
    
    bool b_cond = false;
    b_cond = (pfjetAK8hasb[ijet] && !(pfjetAK8hashadtop[ijet]) && !(pfjetAK8hasleptop[ijet]) && !(pfjetAK8hastop[ijet]));
  
    if(b_cond){
      bool gsfmatch(true);
      if (pfjetAK8elinsubeta[ijet] != -100 && pfjetAK8elinsubphi[ijet] != -100)
        {
	  //hist_event_count_total_pfel->Fill(1,weight);
          if (nelecs > 0) {
            float dR_min(0.4); int nearest(-1);
            for(int el=0; el<nelecs; el++){
              float dR = delta2R(eleta[el],elphi[el],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet]);
              if (dR < dR_min) {
                dR_min = dR;
                nearest = el;
              }
            }
	    /*
	      if (nearest == -1) {
	      gsfmatch = false;
	      }
	    if (nearest >= 0) hist_event_count_pass_matchgsf->Fill(1,weight);
	    }
	    }
	    if (gsfmatch == 0 || (pfjetAK8elinsubeta[ijet] == -100 && pfjetAK8elinsubphi[ijet] == -100)) {*/
	    if (nearest >= 0 && eldxy_sv[nearest] != 1000) {    
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
	      
	      TLorentzVector lj_mom;
              lj_mom.SetPtEtaPhiM(pfjetAK8pt[ijet],pfjetAK8y[ijet],pfjetAK8phi[ijet],pfjetAK8mass[ijet]);
              //TLorentzVector pfel; pfel.SetPtEtaPhiE(pfjetAK8elinsubpt[ijet],pfjetAK8elinsubeta[ijet],pfjetAK8elinsubphi[ijet],pfjetAK8elinsube[ijet]);                                            
	      TLorentzVector gsfel;
              gsfel.SetPtEtaPhiE(fabs(elpt[nearest]),eleta[nearest],elphi[nearest],ele[nearest]);
              selpfjetAK8matchedelptrel[iseljet] = ((gsfel.Vect()).Perp(lj_mom.Vect()));
	      

	      if(isnan(Rho)) {
		selpfjetAK8matchedelRho[iseljet] = -100;
	      }
	      else
		selpfjetAK8matchedelRho[iseljet] = Rho;
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
	      selpfjetAK8matchedelsigmaieta[iseljet] = elsigmaieta[nearest];
	      selpfjetAK8matchedelsigmaiphi[iseljet] = elsigmaiphi[nearest];
	      selpfjetAK8matchedelr9full[iseljet] = elr9full[nearest];
	      selpfjetAK8matchedelsupcl_etaw[iseljet] = elsupcl_etaw[nearest];
	      selpfjetAK8matchedelsupcl_phiw[iseljet] = elsupcl_phiw[nearest];
	      selpfjetAK8matchedelhcaloverecal[iseljet] = elhcaloverecal[nearest];
	      selpfjetAK8matchedelcloctftrkn[iseljet] = elcloctftrkn[nearest];
	      selpfjetAK8matchedelcloctftrkchi2[iseljet] = elcloctftrkchi2[nearest];
	      selpfjetAK8matchedele1x5bye5x5[iseljet] = ele1x5bye5x5[nearest];
	      selpfjetAK8matchedelnormchi2[iseljet] = elnormchi2[nearest];
	      selpfjetAK8matchedelhitsmiss[iseljet] = elhitsmiss[nearest];
	      selpfjetAK8matchedeltrkmeasure[iseljet] = eltrkmeasure[nearest];
	      selpfjetAK8matchedelconvtxprob[iseljet] = elconvtxprob[nearest];
	      selpfjetAK8matchedelecloverpout[iseljet] = elecloverpout[nearest];
	      selpfjetAK8matchedelecaletrkmomentum[iseljet] = elecaletrkmomentum[nearest];
	      selpfjetAK8matchedeldeltaetacltrkcalo[iseljet] = eldeltaetacltrkcalo[nearest];
	      selpfjetAK8matchedelsupcl_preshvsrawe[iseljet] = elsupcl_preshvsrawe[nearest];
	      selpfjetAK8matchedelpfisolsumphet[iseljet] = elpfisolsumphet[nearest];
	      selpfjetAK8matchedelpfisolsumchhadpt[iseljet] = elpfisolsumchhadpt[nearest];
	      selpfjetAK8matchedelpfisolsumneuhadet[iseljet] = elpfsiolsumneuhadet[nearest];
	      selpfjetAK8matchedeletain[iseljet] = eletain[nearest];
	      selpfjetAK8matchedelphiin[iseljet] = elphiin[nearest];
	      selpfjetAK8matchedelfbrem[iseljet] = elfbrem[nearest];
	      selpfjetAK8matchedeleoverp[iseljet] = eleoverp[nearest];
	      selpfjetAK8matchedelhovere[iseljet] = elhovere[nearest];
	      
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
	      selpfjetAK8hastau[iseljet] =  pfjetAK8hastau[ijet];
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
	}
    }
  }
  npfjetAK8_b = iseljet;
  if (iseljet != 0) Tout5->Fill();	
  
  //iseljet = 0;
  //npfjetAK8_all = 0;
  

  //for(int ijet=0; ijet< npfjetAK8; ijet++){
    
  //if(ijet>(nmaxjet-1)) break;
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

  //iseljet++;
  //if(iseljet>=njetmxAK8) break;
  
  //}
  
  //npfjetAK8_all = iseljet;
  
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
