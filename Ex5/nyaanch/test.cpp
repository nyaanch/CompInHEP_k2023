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

  const int N = tree->GetEntries();
  TH1D* hist = new TH1D("hist", "Normally Distributed Random Numbers", 100, -5, 5);
  hist->SetLineColor(kBlack);
  hist->SetLineWidth(2);
  hist->SetFillColor(kYellow);

  for (int i = 0; i < N; i++) {
    tree->GetEntry(i);
    hist->Fill(data);
  }

  TCanvas* canvas = new TCanvas("canvas", "Normally Distributed Random Numbers", 800, 600);
  canvas->SetFillColor(kWhite);

  gStyle->SetTitleFontSize(0.05);
  // gStyle->SetOptStat();
  // gStyle->SetOptFit(111);
  gStyle->SetStatFontSize(0.03);

  hist->GetXaxis()->SetTitle("Value");
  hist->GetYaxis()->SetTitle("Events");

  hist->SetStats(0);

  TF1* fit = new TF1("fit", "gaus", -5, 5); // Create Gaussian fit function
  hist->Fit(fit); // Fit histogram with Gaussian function

  canvas->Update();

  hist->Draw("hist");
  fit->Draw("same");
  
  canvas->SaveAs("hist.root");
  canvas->SaveAs("plot.pdf");
  canvas->SaveAs("plot.png");
}

int main() {
  test();
  return 0;
}