#define Anal_LeptopReco2D_muePROOF_cxx
#include "Anal_LeptopReco2D_muePROOF.h"
#include <TH2.h>
#include <TStyle.h>

#define E_MU_TTBar
//#define E_Jets_TTBar

void Anal_LeptopReco2D_muePROOF::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.
  // The tree argument is deprecated (on PROOF 0 is passed).
  
  TString option = GetOption();
}

void Anal_LeptopReco2D_muePROOF::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).
  
  TString option = GetOption();
  //OutFile = new TProofOutputFile("testHadronic_elid_notallevtsv4.root");
  //OutFile = new TProofOutputFile("SingleElectron_Data_2018A_leptrig.root");
  //OutFile = new TProofOutputFile("testQCD_2000toInfv2.root");
  OutFile = new TProofOutputFile("testhad_ttbarv2mue.root");

  //fOutput->Add(OutFile);
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
  
  char name[1000];
    
  hist_pfmet = new TH1D("hist_PFMET","hist_PFMET",25,0,500);
  hist_pfmet_1 = new TH1D("hist_PFMET_pass","hist_PFMET_pass",25,0,500);
  
  for(int ihist=0; ihist<nobshist; ihist++){
    sprintf(name,"Obs_%s",obsnames[ihist]);
    hist_obs[ihist] = new TH1D(name,name,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
    hist_obs[ihist]->Sumw2();
    
    sprintf(name,"Obs_%s_pass",obsnames[ihist]);
    hist_obs_1[ihist] = new TH1D(name,name,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
    hist_obs_1[ihist]->Sumw2();
    
    sprintf(name,"Obs_%s_fail",obsnames[ihist]);
    hist_obs_2[ihist] = new TH1D(name,name,obs_nbins[ihist],obs_low[ihist],obs_up[ihist]);
    hist_obs_2[ihist]->Sumw2();
  }
  
  char title[1000];
  sprintf(name,"N_PV");
  sprintf(title,"# of Primary Vertices");
  hist_npv = new TH1D(name,title,100,-0.1,99.9);//80,-0.1,79.9);
  hist_npv->Sumw2();
  
  sprintf(name,"N_PU");
  sprintf(title,"# of Pileup Vertices");
  hist_npu = new TH1D(name,title,100,0,100);//80,-0.1,79.9);
  hist_npu->Sumw2();
  
  sprintf(name,"N_PV_sel");
  sprintf(title,"# of Primary Vertices");
  hist_npv_sel = new TH1D(name,title,100,-0.1,99.9);//80,-0.1,79.9);
  hist_npv_sel->Sumw2();
  
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
  
  sprintf(name,"NJets_AK8");
  sprintf(title,"# of AK8 jets");
  hist_njets_AK8 = new TH1D(name,title,10,0,10);
  hist_njets_AK8->Sumw2();
  
  sprintf(name,"NJets_AK4");
  sprintf(title,"# of AK4 jets");
  hist_njets_AK4 = new TH1D(name,title,10,0,10);
  hist_njets_AK4->Sumw2();
  
  sprintf(name,"NBJets_AK4");
  sprintf(title,"# of b tagged AK4 jets");
  hist_nbjets_AK4 = new TH1D(name,title,10,0,10);
  hist_nbjets_AK4->Sumw2();

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
  
  hist_top_deepak8 = new TH1D("TopJet_Pt","TopJet_Pt",notptbins,tptbins);
  hist_top_deepak8->Sumw2();  
  
  hist_top_deepak8_pass = new TH1D("TopJet_Pt_DeepAK8_pass","TopJet_Pt_DeepAK8_pass",notptbins,tptbins);
  hist_top_deepak8_pass->Sumw2();  

  hist_th_pt = new TH1D("HTop_pt","HTop_pt",25,400,3100);
  hist_th_pt->Sumw2(); 
  
  hist_th_y = new TH1D("HTop_y","HTop_y",25,-2.5,2.5);
  hist_th_y->Sumw2(); 
  
  hist_th_sdmass = new TH1D("HTop_sdmass","HTop_sdmass",25,0,300);
  hist_th_sdmass->Sumw2(); 
  
  hist_th_deepak8 = new TH1D("HTop_DAK8","HTop_DAK8",25,0,1);
  hist_th_deepak8->Sumw2();  
  
  hist_th_tau32 = new TH1D("HTop_tau32","HTop_tau32",25,0,1);
  hist_th_tau32->Sumw2();  
  
  hist_count = new TH1D("Counter","Counter",12,0.5,12.5);
  hist_count->Sumw2();  
}

Bool_t Anal_LeptopReco2D_muePROOF::Process(Long64_t entry)
{
  // The Process() function is called for each entry in the tree (or possibly
  // keyed object in the case of PROOF) to be processed. The entry argument
  // specifies which entry in the currently loaded tree is to be processed.
  // It can be passed to either Anal_LeptopReco2D_muePROOF::GetEntry() or TBranch::GetEntry()
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
  
  hist_event_count->Fill(1,weight);
  
  int nbjet_cut = -1;
#ifdef E_MU_TTBar
  nbjet_cut = 1;
#elif defined(E_Jets_TTBar)
  nbjet_cut = 0;
#endif
  
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
    }
    
    if(pfjetAK8pt[ijet] < ptcut) continue;
    //if (pfjetAK8elinsubpt[ijet] < 0 && pfjetAK8elinsubjpt[ijet]< 0) continue;
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
    pfjetAK8haspfelectron[fjet] = false;
    
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
  std::vector<TLorentzVector> Mu_Fsel;
  int nmuon1 = 0;
  for(int mu=0; mu<nmuons; mu++){
    
    if(muonpt[mu]<53.) continue; 
    if(fabs(muoneta[mu])>2.4)  continue; 
    bool mu_id = Muon_TightID(muonisGL[mu],muonisPF[mu],
			      muonchi[mu],muonthit[mu],muonmst[mu],
			      muontrkvtx[mu],muondz[mu],muonpixhit[mu],muontrklay[mu]);
    bool mu_iso = Muon_Iso_ID(muonpfiso[mu]);
    
    if(!mu_id) continue;
    //if(!mu_iso) continue;
    TLorentzVector mu_collection;
    mu_collection.SetPtEtaPhiE(fabs(muonpt[mu]),muoneta[mu],muonphi[mu],muone[mu]);
    Mu_Fsel.push_back(mu_collection);

    muonpt[nmuon1] = muonpt[mu];
    muoneta[nmuon1] = muoneta[mu];
    muonphi[nmuon1] = muonphi[mu];
    muone[nmuon1] = muone[mu];
    muonp[nmuon1] = muonp[mu];
    nmuon1++;
    if(nmuon1 >= njetmx) break;
  }
  nmuons = nmuon1;
  
  std::vector<TLorentzVector> El_Fsel;
  for(int ie=0; ie<nelecs; ie++) {
    if(fabs(elpt[ie])<25.) continue; 
    if(fabs(eleta[ie])>2.5)  continue; 
    if(!elmvaid_noIso[ie]) continue;
    TLorentzVector el_collection;
    el_collection.SetPtEtaPhiE(fabs(elpt[ie]),eleta[ie],elphi[ie],ele[ie]);
    El_Fsel.push_back(el_collection);
  }
  
  std::vector<TLorentzVector> Jet_basesel;
  for(int ijet=0; ijet<npfjetAK4; ijet++){
    if(!pfjetAK4looseID[ijet]) continue; //switch to tight id (calculation also do here).
    if(fabs(pfjetAK4eta[ijet])>2.5) continue;
    if(pfjetAK4pt[ijet]<15.) continue;
    pfjetAK4pt[ijet] *= pfjetAK4JEC[ijet] ;
    pfjetAK4mass[ijet] *= pfjetAK4JEC[ijet];
    if(isMC){                                                                                                  
      pfjetAK4pt[ijet] *= (1+pfjetAK4reso[ijet]) ;                                                             
    }
    TLorentzVector jet_base_collection;
    jet_base_collection.SetPtEtaPhiM(pfjetAK4pt[ijet],pfjetAK4eta[ijet],pfjetAK4phi[ijet],pfjetAK4mass[ijet]);
    Jet_basesel.push_back(jet_base_collection);
  }
  
  fjet = 0;
  int nbjetAK4 = 0;
  
  float btagwt = 1.;
  float btag_eff = 1;
  float Event_HT = 0;

  for(int ijet=0; ijet<npfjetAK4; ijet++){
    if(!pfjetAK4looseID[ijet]) continue; //switch to tight ID (even tight ID calculation also do here in this code)
    if(fabs(pfjetAK4eta[ijet])>2.5) continue;
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
    
    if(pfjetAK4btag_DeepFlav[fjet] > deep_btag_cut) { nbjetAK4++; }
    if(isMC){
      if(pfjetAK4btag_DeepFlav[fjet] > deep_btag_cut) { 
	btagwt *= max(float(0),float(BTag_SF(pfjetAK4hadronflav[fjet],"noSyst",pfjetAK4pt[fjet])));
      }else{
	if(isTT){	btag_eff = BTag_MCEfficiency_TT(abs(pfjetAK4hadronflav[fjet]),pfjetAK4pt[fjet],pfjetAK4eta[fjet]);	}
	if(isST){	btag_eff = BTag_MCEfficiency_ST(abs(pfjetAK4hadronflav[fjet]),pfjetAK4pt[fjet],pfjetAK4eta[fjet]);	}
	if(isDIB){	btag_eff = BTag_MCEfficiency_DIB(abs(pfjetAK4hadronflav[fjet]),pfjetAK4pt[fjet],pfjetAK4eta[fjet]);	}
	if(isWJ){	btag_eff = BTag_MCEfficiency_WJ(abs(pfjetAK4hadronflav[fjet]),pfjetAK4pt[fjet],pfjetAK4eta[fjet]);	}
	if(isDY){	btag_eff = BTag_MCEfficiency_DY(abs(pfjetAK4hadronflav[fjet]),pfjetAK4pt[fjet],pfjetAK4eta[fjet]);	}
	if(isbQCD){	btag_eff = BTag_MCEfficiency_bQCD(abs(pfjetAK4hadronflav[fjet]),pfjetAK4pt[fjet],pfjetAK4eta[fjet]);	}
	btagwt *= max(float(0),float((1. - btag_eff*BTag_SF(pfjetAK4hadronflav[fjet],"noSyst",pfjetAK4pt[fjet]))*1./(1. - btag_eff)) );
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
    if(!isnan(puWeight) || fabs(puWeight)<1.e+6){
      weight *= puWeight;  
    }
    hist_npu->Fill(npu_vert,weight);
  }
  hist_npv->Fill(nchict,weight);
  if((!isnan(btagwt) || fabs(btagwt)<1.e+6) && nbjet_cut>0){
    weight *= btagwt;
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
    if(isnan(pfjetAK8_bbyW_E[ijet])) { pfjetAK8_bbyW_E[ijet] = -100; }
    if(isnan(pfjetAK8_Kfactor[ijet])) { pfjetAK8_Kfactor[ijet] = -100; }
    if(isnan(pfjetAK8_Rnew[ijet])) { pfjetAK8_Rnew[ijet] = -100; }
    if(isnan(pfjetAK8_leppt[ijet])) { pfjetAK8_leppt[ijet] = -100; }
    if(isnan(pfjetAK8_bpt[ijet])) { pfjetAK8_bpt[ijet] = -100; }
    if(isnan(pfjetAK8_nupt[ijet])) { pfjetAK8_nupt[ijet] = -100; }
    hist_2D_msd_deepak8->Fill(pfjetAK8sdmass[ijet],pfjetAK8DeepTag_TvsQCD[ijet]);
  }//ijet
  
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
      toppt_wt = SF_TOP(0.0615,0.0005,top4mom[0].Pt(),top4mom[1].Pt());
    }
    weight *= toppt_wt;
  }
  
  // top pt reweighting ends //
  if(isnan(weight) || weight>1.e+12) { weight = 0; }

  // event selection
  hist_count->Fill(1,weight);
  if(nchict<1) return kFALSE;
  bool itrig_pass = false;
  bool itrig_epass = false;
  bool itrig_ljpass = false;

  // e + jets (semileptonic ttbar) 
#ifdef E_Jets_TTBar
  itrig_pass = (ihlt15==1);// || ihlt14==1);
  if(!itrig_pass) return kFALSE;
  hist_count->Fill(2,weight);
  
  int npfjetAK8_we = 0;
  for(int ijet=0; ijet<npfjetAK8; ijet++){
    if (pfjetAK8haspfelectron[ijet]) {
      npfjetAK8_we++;
    }
  }

  if(npfjetAK8<1) return kFALSE;
  hist_count->Fill(3,weight);
  
  if (Jet_basesel.size() <= 0) return kFALSE;
  if (El_Fsel.size() != 1) return kFALSE;

  float dR_min(1000.0);
  int nearjet(-1);
  bool passed_2D(false);

  for(unsigned kjet=0; kjet< Jet_basesel.size(); kjet++){
    if(delta2R(Jet_basesel[kjet].Eta(),Jet_basesel[kjet].Phi(),El_Fsel[0].Eta(),El_Fsel[0].Phi())<dR_min){
      dR_min = delta2R(Jet_basesel[kjet].Eta(),Jet_basesel[kjet].Phi(),El_Fsel[0].Eta(),El_Fsel[0].Phi());
      nearjet = kjet;
    }
  }
  double Electron_pt_nearjet(0.0);
  if(nearjet>=0){
    TLorentzVector j_mom; 
    j_mom.SetPtEtaPhiM(Jet_basesel[nearjet].Pt(),Jet_basesel[nearjet].Eta(),Jet_basesel[nearjet].Phi(),Jet_basesel[nearjet].M());
    Electron_pt_nearjet = ((El_Fsel[0].Vect()).Perp(j_mom.Vect()));
    TString str0 = TString::Format(" %f dRmin %f \n",Electron_pt_nearjet,dR_min);
    if(gProofServ) gProofServ->SendAsynMessage(str0);
  }
  if((dR_min > 0.4 ||  Electron_pt_nearjet > 25.)) passed_2D = true;
  
  hist_count->Fill(4,weight);
  
  if(PFMET < 50.) return kFALSE;  // MET cut of 50 GeV for Ejets                                                
   
  hist_count->Fill(5,weight);

#endif
  
  // e + mu (dileptonic ttbar)
#ifdef E_MU_TTBar
  itrig_pass = ((ihlt01==1));
  if(!itrig_pass) return kFALSE;
  hist_count->Fill(2,weight);
  
  if(npfjetAK8<1) return kFALSE;
  hist_count->Fill(3,weight);
  
  
  if(Mu_Fsel.size() != 1) return kFALSE;
  hist_count->Fill(4,weight);
  if (Jet_basesel.size() <= 0) return kFALSE;
  
  if (El_Fsel.size() != 1) return kFALSE;
  hist_count->Fill(5,weight);

  if ((Mu_Fsel[0]+El_Fsel[0]).M()<20.0) return kFALSE;
  if ((Mu_Fsel[0]+El_Fsel[0]).M() > 76.0 && (Mu_Fsel[0]+El_Fsel[0]).M() < 106.0) return kFALSE;
  hist_count->Fill(6,weight);
  
  if (npfjetAK4 < 2) return kFALSE; //&& pfjetAK4pt[0] > 100.0
  hist_count->Fill(7,weight);

  if(!(pfjetAK4btag_DeepFlav[0] > deep_btag_cut || pfjetAK4btag_DeepFlav[1] > deep_btag_cut)) return kFALSE;
  hist_count->Fill(8,weight);

  float dR_min(1000.0);
  int nearjet(-1);
  bool passed_2D(false);
  
  for(unsigned kjet=0; kjet< Jet_basesel.size(); kjet++){
    if(delta2R(Jet_basesel[kjet].Eta(),Jet_basesel[kjet].Phi(),El_Fsel[0].Eta(),El_Fsel[0].Phi())<dR_min){
      dR_min = delta2R(Jet_basesel[kjet].Eta(),Jet_basesel[kjet].Phi(),El_Fsel[0].Eta(),El_Fsel[0].Phi());
      nearjet = kjet;
    }
  }
  double Electron_pt_nearjet(0.0);
  if(nearjet>=0){
    TLorentzVector j_mom;
    j_mom.SetPtEtaPhiM(Jet_basesel[nearjet].Pt(),Jet_basesel[nearjet].Eta(),Jet_basesel[nearjet].Phi(),Jet_basesel[nearjet].M());
    Electron_pt_nearjet = ((El_Fsel[0].Vect()).Perp(j_mom.Vect()));
    TString str0 = TString::Format(" %f dRmin %f \n",Electron_pt_nearjet,dR_min);
    if(gProofServ) gProofServ->SendAsynMessage(str0);
  }
  if((dR_min > 0.4 ||  Electron_pt_nearjet > 15.)) passed_2D = true;
  
  if(PFMET < 30.) return kFALSE; 
  hist_count->Fill(9,weight);

#endif
  
#if !defined(E_Jets_TTBar) && !defined(E_MU_TTBar) 
  itrig_pass = ((ihlt01==1)||(ihlt02==1)||(ihlt03==1)||(ihlt04==1)||(ihlt05==1)||(ihlt06==1)||(ihlt07==1)||(ihlt08==1)||(ihlt09==1)||(ihlt10==1));
  if(!itrig_pass) return kFALSE;
#endif
  

  hist_pfmet->Fill(PFMET,weight);
  
  
  // for e+jets
#ifdef E_Jets_TTBar
  
  int thcand = -1;
  int nhcand = 0;
  float maxscore = DAK8_topcut;
  float topwt = 1;
  for(int ijet=0; ijet<npfjetAK8; ijet++){
    if(pfjetAK8sdmass[ijet] > 105. &&  pfjetAK8sdmass[ijet] < 210. && pfjetAK8DeepTag_TvsQCD[ijet] > maxscore
       ){
      maxscore = pfjetAK8DeepTag_TvsQCD[ijet] ;
      thcand = ijet;
      nhcand++;
    }
    if(pfjetAK8sdmass[ijet] > 105. &&  pfjetAK8sdmass[ijet] < 210.){
      hist_top_deepak8->Fill(pfjetAK8pt[ijet],weight);
      if(pfjetAK8DeepTag_TvsQCD[ijet] > DAK8_topcut) { hist_top_deepak8_pass->Fill(pfjetAK8pt[ijet],weight); }
    }
    if(isMC){   
      if(pfjetAK8sdmass[ijet] > 105. &&  pfjetAK8sdmass[ijet] < 210.){
	if(pfjetAK8DeepTag_TvsQCD[ijet] > DAK8_topcut) { topwt *= max(float(0),float(TopTag_SF(pfjetAK8pt[ijet]))); }
	else {	
	  float topeff = 1;
	  if(isTT){ topeff = TopTag_Efficiency_TT(pfjetAK8pt[ijet]); }
	  if(isST){ topeff = TopTag_Efficiency_ST(pfjetAK8pt[ijet]); }
	  if(isDIB){ topeff = TopTag_Efficiency_DIB(pfjetAK8pt[ijet]); }
	  if(isWJ){ topeff = TopTag_Efficiency_WJ(pfjetAK8pt[ijet]); }
	  if(isDY){ topeff = TopTag_Efficiency_DY(pfjetAK8pt[ijet]); }
	  if(isbQCD){ topeff = TopTag_Efficiency_bQCD(pfjetAK8pt[ijet]); }
	  topwt *=  max(float(0),float((1. - topeff* TopTag_SF(pfjetAK8pt[ijet]))*1./(1.- topeff)) );
	} 
      }
    }
  }
  
  weight *= topwt;
  
  int isoljet(-1); 
  bool elclosejet(false);
  if(thcand >=0 && nhcand==1){
    hist_count->Fill(6,weight);

    for(int ijet=0; ijet<npfjetAK4; ijet++){
      if(delta2R(pfjetAK8y[thcand],pfjetAK8phi[thcand],pfjetAK4y[ijet],pfjetAK4phi[ijet]) > 1.2)
	isoljet = ijet;
      break;
    }
    if (isoljet >= 0) hist_count->Fill(7,weight);
    if (isoljet >= 0 && delta2R(pfjetAK4y[isoljet],pfjetAK4phi[isoljet],El_Fsel[0].Eta(),El_Fsel[0].Phi()) < 0.8) hist_count->Fill(8,weight);
    if (isoljet >= 0 && delta2R(pfjetAK4y[isoljet],pfjetAK4phi[isoljet],El_Fsel[0].Eta(),El_Fsel[0].Phi()) < 0.8 && passed_2D == 1) hist_count->Fill(9,weight);
    if (isoljet >= 0 && passed_2D == 1 && delta2R(pfjetAK4y[isoljet],pfjetAK4phi[isoljet],El_Fsel[0].Eta(),El_Fsel[0].Phi()) < 0.8) elclosejet = true;
  }
  
#endif
    
  // for e+mu //
  
#ifdef E_MU_TTBar
  

  /* float maxpt = -100;
  for(int ijet=0; ijet<npfjetAK8; ijet++){
    if(pfjetAK8pt[ijet]<400.) { continue; }
    if( (delta2R(muoneta[0],muonphi[0],pfjetAK8y[ijet],pfjetAK8phi[ijet]) > 1.2)
	&& (PhiInRange(muonphi[0] - pfjetAK8phi[ijet]) > M_PI/2.)
	&& pfjetAK8pt[ijet]>maxpt
	){
      maxpt = pfjetAK8pt[ijet];
    }
    }*/
  
  int isoljet(-1);
  for(int ijet=0; ijet<npfjetAK4; ijet++){
    if(delta2R(Mu_Fsel[0].Eta(),Mu_Fsel[0].Phi(),pfjetAK4y[ijet],pfjetAK4phi[ijet]) > 1.2)
      isoljet = ijet;
    break;
  }

  if (isoljet >= 0) hist_count->Fill(10,weight);
  if (isoljet >= 0 && delta2R(pfjetAK4y[isoljet],pfjetAK4phi[isoljet],El_Fsel[0].Eta(),El_Fsel[0].Phi()) < 0.8)
    {hist_count->Fill(11,weight);}
  if (isoljet >= 0 && delta2R(pfjetAK4y[isoljet],pfjetAK4phi[isoljet],El_Fsel[0].Eta(),El_Fsel[0].Phi()) < 0.8 && passed_2D == 1) hist_count->Fill(12,weight);
  
#endif

  //#if !defined(E_Jets_TTBar) && !defined(E_MU_TTBar) 
  //if(npfjetAK8>0){ telcand = 0; }
  //#endif
  
  
  // fill the histograms //
#ifdef E_Jets_TTBar
  if(thcand>=0){
    hist_th_pt->Fill(pfjetAK8pt[thcand],weight);
    hist_th_y->Fill(pfjetAK8y[thcand],weight);
    hist_th_sdmass->Fill(pfjetAK8sdmass[thcand],weight);
    hist_th_tau32->Fill(pfjetAK8tau32[thcand],weight);
    hist_th_deepak8->Fill(pfjetAK8DeepTag_TvsQCD[thcand],weight);
    hist_count->Fill(10,weight);
  }
  if(elclosejet == 1){
    
    hist_count->Fill(11,weight);
    hist_npv_sel->Fill(nchict,weight);
    hist_njets_AK8->Fill(npfjetAK8,weight);
    hist_njets_AK4->Fill(npfjetAK4,weight);
    hist_nbjets_AK4->Fill(nbjetAK4,weight);
    
    if(nbjetAK4>=nbjet_cut){ 
      
      hist_count->Fill(12,weight);
    }
  }
#endif
  // end //
  return kTRUE;
}
  
void Anal_LeptopReco2D_muePROOF::SlaveTerminate()
{
  // The SlaveTerminate() function is called after all entries or objects
  // have been processed. When running with PROOF SlaveTerminate() is called
  // on each slave server.
  fileOut->cd();
  fileOut->Write();
  fOutput->Add(OutFile);
  fileOut->Close();
}
 
 void Anal_LeptopReco2D_muePROOF::Terminate()
 {
  // The Terminate() function is the last function to be called during
  // a query. It always runs on the client, it can be used to present
  // the results graphically or save the results to file.
 }
