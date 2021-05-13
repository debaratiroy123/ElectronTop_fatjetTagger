#include <iostream>
#include <TFile.h>
#include <TTree.h>

using namespace std;

void counter()
{
float tot_weight;
float weight;

 TFile *fileIn = new TFile("TestMtt_1000toInfnewvarBDT.root");
 
 float sumweight = 0;
 float sum_pos =0, sum_neg = 0;
 
 TTree* T1;
 T1 = (TTree*)fileIn->Get("leptop");
 T1->SetBranchAddress("weight", &weight);
 
 int nevt = T1->GetEntries();
 cout<<"entries "<<nevt<<endl;
 double count[6]={0};
 float count2[6]={0};
 
 for(int iev=0; iev<nevt; iev++){
   T1->GetEntry(iev);
   count[0]++;
   count[3] += weight;
   count2[0]++;
   count2[3] += weight;
   
   if(weight>=0){   count[1]++; count[4] += (weight) ;  }
   else { count[2]++; count[5] += (weight) ; }

   //if((iev+1)%100000 == 1) { cout<<iev<<" weight "<<weight<<" event sum "<<count[0]<<" f "<<count2[0]<<" weight sum "<<count[3]<<" f "<<count2[3]<<endl; }

   //cout<<"sum "<<sumweight<<endl;
 }
 //cout<<fileIn->GetName()<<" total weight "<<sumweight<<endl;
 //cout<<"total +ve weight "<<sum_pos<<" total -ve weight  "<<sum_neg<<endl;
 cout<<fileIn->GetName()<<endl;
//cout<<"# of occurence : total "<<count[0]<<" postive weights "<<count[1]<<" negative weights "<<count[2]<<endl;
 cout<<"sum : total "<<count[3]<<" postive weights "<<count[4]<<" negative weights "<<count[5]<<endl;
}

int main()
{
  counter();
}
