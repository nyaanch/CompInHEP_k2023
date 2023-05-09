#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TStyle.h"

void test() {
  TFile* file = new TFile("output.root", "READ");
  TTree* tree = dynamic_cast<TTree*>(file->Get("tree"));

  double data;
  tree->SetBranchAddress("data", &data);

  const int N = 10000;
  TH1D* hist = new TH1D("hist", "Normally Distributed Random Numbers", 100, -5, 5);
  hist->SetLineColor(kBlack);
  hist->SetLineWidth(2);
  hist->SetFillColor(kYellow);

  for (int i = 0; i < N; i++) {
    tree->GetEntry(i);
    hist->Fill(data);
  }

  TF1* fit = new TF1("fit", "gaus", -5, 5); // Create Gaussian fit function
  hist->Fit(fit); // Fit histogram with Gaussian function

  TCanvas* canvas = new TCanvas("canvas", "Normally Distributed Random Numbers", 800, 600);
  canvas->SetFillColor(kWhite);

  gStyle->SetTitleFontSize(0.05);
  gStyle->SetOptFit(111);
  gStyle->SetStatFontSize(0.03);

  hist->GetXaxis()->SetTitle("Value");
  hist->GetYaxis()->SetTitle("Events");

  hist->Draw("hist");
  canvas->SaveAs("hist.root");
}

int main() {
  test();
  return 0;
}