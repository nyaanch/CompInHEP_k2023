#include "Pythia8/Pythia.h"
#include "iostream"
#include "TTree.h"
#include "TFile.h"
#include "TH1.h"

using namespace Pythia8;

int main() {

    Pythia pythia;
    pythia.readString("Beams:eCM = 13000.");
    pythia.readString("SoftQCD:nonDiffractive = on");
    pythia.init();

    TFile* outFile = new TFile("ex9.root", "RECREATE");
    TTree* tree = new TTree("tree", "PYTHIA8 generated events");

    Hist pt("Transverse momentum", 100, 0., 100.);
    Hist eta("Pseudorapidity", 100, -5., 5.);

    float Pt, Eta;
    tree->Branch("Pt", &Pt);
    tree->Branch("Eta", &Eta);

    float probability;
    int Npassed = 0;
    int Ntotal = 100000;

    for (int event = 0; event < Ntotal; event++) 
    {
        if (!pythia.next()) continue;

        for (int i = 0; i < pythia.event.size(); i++)
        {
            if (pythia.event[i].id() == 13)
            {
                Pt = pythia.event[i].pT();
                Eta = pythia.event[i].eta();

                pt.fill(Pt);
                eta.fill(Eta);

                if(Pt > 5.0 && abs(Eta) < 2.5)
                {
                    Npassed++;
                }

               tree -> Fill();
            }
        }
    }

    pythia.stat();
    std::cout << pt;
    std::cout << eta;

    probability = (float)Npassed/(float)Ntotal;
    std::cout << "Probability: " << probability*100 << "%" << std::endl;

    outFile->Write();
    outFile->Close();

  return 0;
}