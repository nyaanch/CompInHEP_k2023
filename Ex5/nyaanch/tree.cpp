#include "TRandom3.h"
#include "TFile.h"
#include "TTree.h"

void tree() {
  const int N = 10000;
  double data;

  TFile* file = new TFile("data.root", "RECREATE");
  TTree* tree = new TTree("tree", "Tree with normally distributed random numbers");
  
  tree->Branch("data", &data, "data/D"); // Add branch to tree

  TRandom3* rand = new TRandom3();
  for (int i = 0; i < N; i++) {
    data = rand->Gaus(0, 1); // Generate normally distributed random numbers
    tree->Fill();
  }

  tree->Write();
  file->Close(); 
}

int main() {
  tree();
  return 0;
}
