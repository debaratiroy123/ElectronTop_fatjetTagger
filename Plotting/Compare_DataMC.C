#include "iostream"
#include "TFile.h"
#include "TMath.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH1.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "THStack.h"
#include <iomanip>

#include "My_Style.C"

//#define Matching
//#define No_Matching

#define Syst

static const int nfiles = 8;

const char *filenames[nfiles] = {
  //"testDataMuEG18ABCD_SumanCommentv0.root",
  //"testDataMuEG18ABCD_SumanCommentv0.root",
  //"TTbarMue_SumanCommentv0muiso.root",
  //"testDataMuEG18ABCD_SumanCommentv0LJTightID.root",
  "MuEG2018ABCD_SumanCommentv0muiso.root",
  "DilepMue_SumanCommentv0muiso.root",
  "TTbarNotMue_SumanCommentv0muiso.root",
  "QCD_SumanCommentv0muiso.root",
  "ST_SumanCommentv0muiso.root",
  "DYJetsToLL_SumanCommentv0muiso.root",
  "WJetsToLNu_SumanCommentv0muiso.root",
  "Diboson_SumanCommentv0muiso.root"
};								
float lumi_fac[nfiles] = 	  {		1.,// 0.875,
						//0.00000607799,
						//0.0000190505,
						0.0000190489,
						1,
						1,
						1,
						1,
						1,
						1
};

float data_lumi = 59.7;//59.7;//27.943;//31.9;//59.7;
float data_lumisyst = 59.7;
//https://twiki.cern.ch/twiki/bin/viewauth/CMS/DCUserPage#Early2018Re_Reco_datasets_17Sep2
//31.95 : 2018D, 6.612 : 2018C, 6.785 : 2018B, 13.48 : 2018A
void Compare_DataMC()
{
  
  static const int nobshist = 33;//36; //29
  int ncat = nobshist-19;//nobshist-19;//nobshist-12;
  
  TH1D *hist_obs[nobshist][nfiles] ;
  
#ifdef Syst
  TH1D *hist_obs_puu[nobshist-2][nfiles-1];
  TH1D *hist_obs_pud[nobshist-2][nfiles-1];
  TH1D *hist_obs_btagu[nobshist-2][nfiles-1];
  TH1D *hist_obs_btagd[nobshist-2][nfiles-1];
#endif

  const char *obsnames[nobshist] = {
    "pt","y","mass",
    "NHad","neuhad","sdmass","chrad","subhaddiff","tau21",
    "DAK8_topvsQCD","bbyW_E","Kfactor",
    "re","rnu",
    "N_PV_sel",
    "hist_PFMET",
    "hist_nmu","hist_nel","NJets_AK8","NJets_AK4","NBJets_AK4","hist_mll","hist_mupt","hist_mueta","hist_muphi","hist_elpt","hist_eleta","hist_elphi","hist_bjetpt","hist_bjeteta","hist_bjetphi","hist_NJets_balAK8","Counter"
  };

  const char *obstitles[nobshist] = {
    "P_{T} (GeV)","y","Mass (GeV)",
    "1-f_{h}","f_{1-h}^{N}","M_{SD} (GeV)","r_{C}","A_{h}","#tau_{21}",
    "Mass decorrelated DeepAK8 score","Z_{b}","#Theta_{b/e}",
    "r_{e}","r_{#nu}",
    "N_{PV}","p^{miss}_{T} (GeV)",
    "# of muons","# of electrons",
    "# of AK8 jets","# of AK4 jets","# of AK4 b jets","m_{ll} (GeV)","p_{T} of #mu (GeV)","#eta of #mu","#phi of #mu","p_{T} of el (GeV)","#eta of el","#phi of el","p_{T} of b-jet (GeV)","#eta of b-jet","#phi of b-jet","# of AK8 jets wrt #mu","Counter"
  }; 
  
#ifdef Syst

  TFile *File;
  char fname[200];
  char namepuu[200];
  char namepud[200];
  char namebtagu[200];
  char namebtagd[200];
  
  for(int imc=1; imc<nfiles; imc++){

    sprintf(fname,"%s",filenames[imc]);
    File = new TFile(fname,"read");
    
    for(int ihist=0; ihist<nobshist-2; ihist++){
      if (ihist<14) {
	
	sprintf(namepuu,"Obs_%s_puwup",obsnames[ihist]);
	sprintf(namepud,"Obs_%s_puwdown",obsnames[ihist]);
	sprintf(namebtagu,"Obs_%s_btagwup",obsnames[ihist]);
        sprintf(namebtagd,"Obs_%s_btagwdown",obsnames[ihist]);
      } else if (ihist == 14 || ihist == 18 || ihist == 19 || ihist == 20) {
	
	sprintf(namepuu,"hist_%s_puwup",obsnames[ihist]);
        sprintf(namepud,"hist_%s_puwdown",obsnames[ihist]);
        sprintf(namebtagu,"hist_%s_btagwup",obsnames[ihist]);
        sprintf(namebtagd,"hist_%s_btagwdown",obsnames[ihist]);
      }else {
	
	sprintf(namepuu,"%s_puwup",obsnames[ihist]);
        sprintf(namepud,"%s_puwdown",obsnames[ihist]);
        sprintf(namebtagu,"%s_btagwup",obsnames[ihist]);
        sprintf(namebtagd,"%s_btagwdown",obsnames[ihist]);
      }

      hist_obs_btagu[ihist][imc-1] = (TH1D*)File->Get(namebtagu);
      hist_obs_btagd[ihist][imc-1] = (TH1D*)File->Get(namebtagd);
      hist_obs_puu[ihist][imc-1] = (TH1D*)File->Get(namepuu);
      hist_obs_pud[ihist][imc-1] = (TH1D*)File->Get(namepud);
      
      if (imc == 1) {
	hist_obs_btagu[ihist][imc-1]->Scale(data_lumisyst*0.0000190489);
	std::cout << " namebtagu " << namebtagu << " " << fname << std::endl;
	hist_obs_btagd[ihist][imc-1]->Scale(data_lumisyst*0.0000190489);
	std::cout << " namebtagd " << namebtagd << " " << fname << std::endl;
	hist_obs_puu[ihist][imc-1]->Scale(data_lumisyst*0.0000190489);
	std::cout << " namepuu " << namepuu << " " << fname << std::endl;
	hist_obs_pud[ihist][imc-1]->Scale(data_lumisyst*0.0000190489);
	std::cout << " namepud " << namepud << " " << fname << std::endl;
      }
      else {
	hist_obs_btagu[ihist][imc-1]->Scale(data_lumisyst);
	std::cout << " namebtagu " << namebtagu << " " << fname << std::endl;
        hist_obs_btagd[ihist][imc-1]->Scale(data_lumisyst);
	std::cout << " namebtagd " << namebtagd << " " << fname << std::endl;
        hist_obs_puu[ihist][imc-1]->Scale(data_lumisyst);
	std::cout << " namepuu " << namepuu << " " << fname << std::endl;
        hist_obs_pud[ihist][imc-1]->Scale(data_lumisyst);
	std::cout << " namepud " << namepud << " " << fname << std::endl;
      }
    }
  }
#endif
  TFile *filein;
  char name[200];
  for(int fg=0; fg<nfiles; fg++){
    if(fg>0){ lumi_fac[fg] *= data_lumi; }
    cout<<filenames[fg]<<" "<<lumi_fac[fg]<<endl;
    sprintf(name,"%s",filenames[fg]);
    filein = new TFile(name,"read");
    for(int ihist=0; ihist<nobshist; ihist++){
      if(ihist<(ncat)){
#ifdef Matching
	sprintf(name,"Obsmu_%s",obsnames[ihist]);
#elif defined No_Matching
	sprintf(name,"Obs_%s_nomatch_bjet",obsnames[ihist]);
#else
	sprintf(name,"Obs_%s",obsnames[ihist]);
#endif
      }else{
	sprintf(name,"%s",obsnames[ihist]);
      }
      hist_obs[ihist][fg] = (TH1D*)filein->Get(name);
      //std::cout << " name " << name << std::endl;
      hist_obs[ihist][fg]->Scale(lumi_fac[fg]);
      if (ihist==14) {
	hist_obs[ihist][fg]->GetXaxis()->SetRangeUser(0.0,50.0);

	if (fg>0) {

	  hist_obs_btagu[ihist][fg-1]->GetXaxis()->SetRangeUser(0.0,50.0);
	  hist_obs_btagd[ihist][fg-1]->GetXaxis()->SetRangeUser(0.0,50.0);
	  hist_obs_puu[ihist][fg-1]->GetXaxis()->SetRangeUser(0.0,50.0);
	  hist_obs_pud[ihist][fg-1]->GetXaxis()->SetRangeUser(0.0,50.0);

	}
      }
    }
  }
  
  int col[nfiles-1]  = {kRed,kMagenta-7,kGreen+4,kBlue,kOrange+7,kCyan+1,kRed-5};
  
  const char *dataname[nfiles] = {"Data",/*"t #bar{t} (e+j)",*/"t #bar{t} (e#mu)","t #bar{t} (non-e#mu)","QCD","Single t","Z+j","W+j","DiBoson"};
  
  THStack *hist_obs_stack[nobshist];
  THStack *hist_obs_stack2v[nobshist];
  TH1 *last_obs[nobshist]; 

  TH1D *hist_obs_bkg[nobshist];
  TH1D *hist_obs_bkgsyserr[nobshist];
  
  TH1D *hist_obs_bkgbtagu[nobshist-2];
  TH1D *hist_obs_bkgbtagd[nobshist-2];
  TH1D *hist_obs_bkgpuu[nobshist-2];
  TH1D *hist_obs_bkgpud[nobshist-2];
  
  TH1D *rat_obs[nobshist];
  TGraphAsymmErrors *ratioGraph[nobshist];
  TCanvas *cv[nobshist];
  TLegend *legv[nobshist];
  
  TFile *outputFile = new TFile( "stack_entryorg.root", "RECREATE" );
  
  for(int iv=0; iv<nobshist; iv++){
    
    sprintf(name,"Stack_%s",obsnames[iv]);
    hist_obs_stack[iv] = new THStack(name,"");
    sprintf(name,"Stack2v_%s",obsnames[iv]);
    hist_obs_stack2v[iv] = new THStack(name,"");

    for(int bkg=1; bkg<(nfiles); bkg++){ 
          
      hist_obs[iv][nfiles-bkg]->SetFillColor(col[nfiles-bkg-1]);
      hist_obs[iv][nfiles-bkg]->SetLineColor(col[nfiles-bkg-1]);
      hist_obs[iv][nfiles-bkg]->GetYaxis()->SetTitleOffset(1.2);
     
      //if (iv == 12) hist_obs[iv][nfiles-bkg]->Rebin(2);
      
      hist_obs_stack[iv]->Add(hist_obs[iv][nfiles-bkg]);
      hist_obs_stack2v[iv]->Add(hist_obs[iv][nfiles-bkg],"e1");
    }
    last_obs[iv] = (TH1*)hist_obs_stack2v[iv]->GetStack()->Last();                                     
    last_obs[iv]->Write();                                                                             
      
    //new addition for systematics in the band//
    //for(int bkg=1; bkg<(nfiles); bkg++){
      
    for(int bkg=0; bkg<(nfiles-1); bkg++){ 	
      if(bkg==0) { hist_obs_bkg[iv] = (TH1D*)hist_obs[iv][bkg+1]->Clone(); }
      else { hist_obs_bkg[iv]->Add(hist_obs[iv][bkg+1]); }
      //if (iv == 12) hist_obs_bkg[iv]->Rebin(2);
    }
    /***sys additions***/
    for(int bkg=0; bkg<nfiles-1; bkg++){
      if (iv<(nobshist-2)) {
	if (bkg==0) {
	  hist_obs_bkgbtagu[iv] = (TH1D*)hist_obs_btagu[iv][bkg]->Clone();
	  hist_obs_bkgbtagd[iv] = (TH1D*)hist_obs_btagd[iv][bkg]->Clone();
	  hist_obs_bkgpuu[iv] = (TH1D*)hist_obs_puu[iv][bkg]->Clone();
	  hist_obs_bkgpud[iv] = (TH1D*)hist_obs_pud[iv][bkg]->Clone();
	}
	else {
	  hist_obs_bkgbtagu[iv]->Add(hist_obs_btagu[iv][bkg]);
	  hist_obs_bkgbtagd[iv]->Add(hist_obs_btagd[iv][bkg]);
	  hist_obs_bkgpuu[iv]->Add(hist_obs_puu[iv][bkg]);
	  hist_obs_bkgpud[iv]->Add(hist_obs_pud[iv][bkg]);
	}
      }
    }
    sprintf(name,"%s",obstitles[iv]);
    hist_obs[iv][0]->GetXaxis()->SetTitle(name);
    hist_obs[iv][0]->GetXaxis()->SetTitleSize(0.045);
    hist_obs[iv][0]->GetXaxis()->SetLabelSize(0.045);
    hist_obs[iv][0]->GetXaxis()->CenterTitle();
    hist_obs_bkg[iv]->GetXaxis()->SetTitle(name);
    hist_obs_bkg[iv]->GetXaxis()->SetTitleSize(0.045);
    hist_obs_bkg[iv]->GetXaxis()->SetLabelSize(0.045);
    hist_obs_bkg[iv]->GetXaxis()->CenterTitle();

    sprintf(name,"No. of events");
    hist_obs[iv][0]->GetYaxis()->SetTitle(name);
    hist_obs[iv][0]->GetYaxis()->SetTitleSize(0.04);
    hist_obs[iv][0]->GetYaxis()->SetLabelSize(0.04);
    hist_obs[iv][0]->GetYaxis()->SetTitleOffset(1.4);
    hist_obs[iv][0]->GetYaxis()->CenterTitle();
    hist_obs_bkg[iv]->GetYaxis()->SetTitle(name);
    hist_obs_bkg[iv]->GetYaxis()->SetTitleSize(0.04);
    hist_obs_bkg[iv]->GetYaxis()->SetLabelSize(0.04);
    hist_obs_bkg[iv]->GetYaxis()->SetTitleOffset(1.4);
    hist_obs_bkg[iv]->GetYaxis()->CenterTitle();

    // canv obs //
    sprintf(name,"Canv_%s",obsnames[iv]);
    hist_obs[iv][0]->SetMaximum(1.1 * max(hist_obs[iv][0]->GetMaximum(),hist_obs_bkg[iv]->GetMaximum()));
    hist_obs_bkg[iv]->SetMaximum(1.1 * max(hist_obs[iv][0]->GetMaximum(),hist_obs_bkg[iv]->GetMaximum()));
    
    if(iv==15){
      hist_obs[iv][0]->SetMinimum(0.5);
      hist_obs_bkg[iv]->SetMinimum(0.5);
    }
    else{
      hist_obs[iv][0]->SetMinimum(0.5);
      hist_obs_bkg[iv]->SetMinimum(0.5);
    }
    
    cv[iv] = tdrDiCanvas(name,hist_obs[iv][0],hist_obs_bkg[iv],8,0);
    
    if(iv==3||iv==14||iv==8){
      legv[iv] = tdrLeg(0.2,0.65,0.395,0.915);
    }else{
      legv[iv] = tdrLeg(0.65,0.65,0.875,0.915);
    }
    
    legv[iv]->SetTextFont(42);
    legv[iv]->SetTextSize(0.045);
    legv[iv]->SetBorderSize(0);
    
    for(int bkg=0; bkg<(nfiles); bkg++){ 
      if(bkg==0){ legv[iv]->AddEntry(hist_obs[iv][bkg],dataname[bkg],"lep"); }
      else{	
	legv[iv]->AddEntry(hist_obs[iv][bkg],dataname[bkg],"f");
      }
    }
    
    cv[iv]->cd(1);
    gPad->SetLogy(1);
    hist_obs[iv][0]->SetMaximum(20*hist_obs[iv][0]->GetMaximum());
    if(iv==0){
      gPad->SetLogx(1);
    }
    
    hist_obs[iv][0]->SetFillStyle(0);
    hist_obs[iv][0]->SetFillColor(0);
    hist_obs[iv][0]->SetMarkerStyle(kFullCircle);
    hist_obs[iv][0]->SetMarkerColor(kBlack);
    hist_obs[iv][0]->SetMarkerSize(0.7);
    hist_obs[iv][0]->SetLineColor(kBlack);
    hist_obs[iv][0]->GetYaxis()->SetTitleOffset(1.5);

    if (iv==12) {

      //hist_obs_stack[iv]->Rebin(2);
      //hist_obs[iv][0]->Rebin(2);
      //hist_obs_bkg[iv]->Rebin(2);
    }
    hist_obs_stack[iv]->Draw("histSAME");
    hist_obs[iv][0]->Draw("PSAME");
    
    gPad->RedrawAxis();
    
    cv[iv]->cd(2);

    rat_obs[iv] = (TH1D*)hist_obs[iv][0]->Clone();
    rat_obs[iv]->Divide(hist_obs_bkg[iv]);

    hist_obs_bkgsyserr[iv] = (TH1D*)hist_obs_bkg[iv]->Clone();
    
    for (int bn=1; bn<= hist_obs_bkgsyserr[iv]->GetNbinsX(); bn++) {
      
      double bncont = hist_obs_bkgsyserr[iv]->GetBinContent(bn);
      double bnerr = hist_obs_bkgsyserr[iv]->GetBinError(bn);
      double btagerr(0.);
      double puerr(0.);
      double toterr(0.);
      
      if (iv<31) {
	if (bncont>0.) {
	  double btagup = fabs((hist_obs_bkgbtagu[iv]->GetBinContent(bn)-bncont)*1./bncont);
	  double btagdown = fabs((hist_obs_bkgbtagd[iv]->GetBinContent(bn)-bncont)*1./bncont);
	  
	  if (btagup>btagdown) {
	    btagerr = btagup;
	  }
	  else if (btagup<btagdown) {
	    btagerr = btagdown;
	  }
	  else btagerr = btagup;
	  double puup = fabs((hist_obs_bkgpuu[iv]->GetBinContent(bn)-bncont)*1./bncont);
	  double pudown = fabs((hist_obs_bkgpud[iv]->GetBinContent(bn)-bncont)*1./bncont);
	  
	  if (puup>pudown) {
	    puerr = puup;
	  }
	  else if (puup<pudown) {
	    puerr = pudown;
	  }
	  else puerr = puup;
	  toterr = sqrt(btagerr*btagerr + puerr*puerr + (bnerr/bncont)*(bnerr/bncont));
	}
	hist_obs_bkgsyserr[iv]->SetBinError(bn,toterr);
      }
      else {
	if(bncont>0) {
	  hist_obs_bkgsyserr[iv]->SetBinError(bn,bnerr/bncont);
	    }
	else hist_obs_bkgsyserr[iv]->SetBinError(bn,0);}
    }
    //new addtions for drawing band//                          
    int nValidRatioPoints(hist_obs_bkgsyserr[iv]->GetNbinsX());
    ratioGraph[iv] = new TGraphAsymmErrors(nValidRatioPoints);
    
    for (int z=0; z< nValidRatioPoints; z++) {
      if (hist_obs_bkgsyserr[iv]->GetBinContent(z+1) > 0) {
	ratioGraph[iv]->SetPoint(z, hist_obs_bkgsyserr[iv]->GetBinCenter(z+1), 1);
	ratioGraph[iv]->SetPointError(z,(hist_obs_bkgsyserr[iv]->GetBinWidth(z+1))/2, (hist_obs_bkgsyserr[iv]->GetBinWidth(z+1))/2, (hist_obs_bkgsyserr[iv]->GetBinError(z+1)), (hist_obs_bkgsyserr[iv]->GetBinError(z+1)));
      }
      else {
        ratioGraph[iv]->SetPoint(z, hist_obs_bkgsyserr[iv]->GetBinCenter(z+1), 1);
        ratioGraph[iv]->SetPointError(z,(hist_obs_bkgsyserr[iv]->GetBinWidth(z+1))/2, (hist_obs_bkgsyserr[iv]->GetBinWidth(z+1))/2,0,0);
      }
    }
    
    //*****************************//
    
    if(iv==0){
      gPad->SetLogx(1);
      rat_obs[iv]->GetXaxis()->SetMoreLogLabels(kTRUE);
      rat_obs[iv]->GetXaxis()->SetNoExponent(kTRUE);
    }
    
    sprintf(name,"%s",obstitles[iv]);
    rat_obs[iv]->GetXaxis()->SetTitle(name);
    rat_obs[iv]->GetXaxis()->SetTitleSize(0.1);
    rat_obs[iv]->GetXaxis()->SetLabelSize(0.1);
//    rat_obs[iv]->GetXaxis()->CenterTitle();
    rat_obs[iv]->GetXaxis()->SetNdivisions(406);  
    
    rat_obs[iv]->GetYaxis()->SetTitle("Data / MC");
    rat_obs[iv]->GetYaxis()->SetTitleSize(0.1);
    rat_obs[iv]->GetYaxis()->SetLabelSize(0.1);
    rat_obs[iv]->GetYaxis()->SetTitleOffset(0.75);
    rat_obs[iv]->GetYaxis()->SetNdivisions(406);
    rat_obs[iv]->GetYaxis()->CenterTitle();
    
    rat_obs[iv]->SetMinimum(0);
    rat_obs[iv]->SetMaximum(2.);
    
    rat_obs[iv]->SetFillStyle(0);
    rat_obs[iv]->SetFillColor(0);
    rat_obs[iv]->SetMarkerStyle(kFullCircle);
    rat_obs[iv]->SetMarkerColor(kBlack);
    rat_obs[iv]->SetMarkerSize(0.7);
    rat_obs[iv]->SetLineColor(kBlack);
   
    rat_obs[iv]->Draw("e,p");
    
    if(iv==0){                                                                                                
      gPad->SetLogx(1);                                                                                          
      ratioGraph[iv]->GetXaxis()->SetMoreLogLabels(kTRUE);                                                       
      ratioGraph[iv]->GetXaxis()->SetNoExponent(kTRUE);                                                          
    }                                                                                                            
    sprintf(name,"%s",obstitles[iv]);                                                                            
    ratioGraph[iv]->GetXaxis()->SetTitle(name);                                                                  
    ratioGraph[iv]->GetXaxis()->SetTitleSize(0.1);                                                               
    ratioGraph[iv]->GetXaxis()->SetLabelSize(0.1);                                                               
    ratioGraph[iv]->GetXaxis()->CenterTitle();       
    ratioGraph[iv]->GetXaxis()->SetNdivisions(406);                                                              
    ratioGraph[iv]->GetYaxis()->SetTitle("Data / MC");                                                           
    ratioGraph[iv]->GetYaxis()->SetTitleSize(0.1);                                                               
    ratioGraph[iv]->GetYaxis()->SetLabelSize(0.1);                                                               
    ratioGraph[iv]->GetYaxis()->SetTitleOffset(0.75);                                                            
    ratioGraph[iv]->GetYaxis()->SetNdivisions(406);                                                              
    ratioGraph[iv]->GetYaxis()->CenterTitle();                                                                   
    ratioGraph[iv]->SetMinimum(0);                                                                               
    ratioGraph[iv]->SetMaximum(2.);                                                                              
    ratioGraph[iv]->SetFillStyle(3001);                                                                          
    ratioGraph[iv]->SetFillColor(45);                                                                            
    ratioGraph[iv]->SetMarkerSize(0);                                                                            
    ratioGraph[iv]->SetLineColor(45);                                                                            
    ratioGraph[iv]->SetLineWidth(0);                                                                             
    ratioGraph[iv]->Draw("e2"); 
    
    rat_obs[iv]->Draw("pe sames");

    // TLine *line = new TLine(rat_obs[iv]->GetBinLowEdge(1),1.,rat_obs[iv]->GetBinLowEdge(rat_obs[iv]->GetNbinsX()),1.);
    //TH1F* hist;
    //for (unsigned short i=0; i < ratioGraph[iv]->GetN(); ++i) // setting bin contents to the TGraph values
      //{
	//double x,y;
	//ratioGraph[iv]->GetPoint(i, x, y);
	//hist->Fill(x, y); // uncertainties are of course screwed up
	//}
    //for (unsigned short i=1; i < hist->GetNbinsX(); ++i){ 
    //hist->SetBinError(i, 0);}
    TLine *line = new TLine(hist_obs_bkgsyserr[iv]->GetBinLowEdge(1),1.,hist_obs_bkgsyserr[iv]->GetBinLowEdge(hist_obs_bkgsyserr[iv]->GetNbinsX()),1.);
    line->SetLineColor(7);
    line->Draw("sames");
    
#ifdef Matching
    sprintf(name,"Data_MC/EMU_SumanComments_FewsystUncmuiso/%s_mu.pdf",cv[iv]->GetName());
#elif defined(No_Matching)
    sprintf(name,"Data_MC/EMU_SumanComments_FewsystUncmuiso/%s_MET110.pdf",cv[iv]->GetName());
#else
    sprintf(name,"Data_MC/EMU_SumanComments_FewsystUncmuiso/%s.pdf",cv[iv]->GetName());
#endif
    
    cv[iv]->SaveAs(name);
  }
  outputFile->Close();
}
