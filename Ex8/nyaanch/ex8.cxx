#include "Pythia8/Pythia.h"
#include <iostream>
#include <TTree.h>
#include <TFile.h>

using namespace Pythia8;

int main() {
    
    Pythia pythia;

    pythia.readString("Beams:eCM = 13000.");

    // PART 1
    pythia.readString("HiggsSM:all = on");
    pythia.readString("25:m0 = 125");
    pythia.readString("PhaseSpace:mHatMin = 100.");
    pythia.readString("Next:numberShowEvent = 0");

    // PART 2
    pythia.readString("PDF:pSet=8");  // built-in pdf

    pythia.init();

    /// PART 1
    ParticleDataEntryPtr particlePtr = pythia.particleData.particleDataEntryPtr(25);
    
    std::ofstream results("width.txt");
    results << "PART 1" << std::endl;
    results << "========================================" << std::endl;
    results << "Width = " << particlePtr->mWidth() << " GeV" << std::endl;
    results << "========================================\n\n" << std::endl;

    results.close();

    /// PART 2

    TFile *file = new TFile("ex8.root", "RECREATE");
    TTree *tree = new TTree("tree", "Higgs boson mass distribution");

    double Mass;

    tree->Branch("Mass", &Mass, "Mass/D");

    for (int event = 0; event < 1000; event++) 
    {
        if (!pythia.next()) continue;

        for (int i = 0; i < pythia.event.size(); ++i)
            if (pythia.event[i].id() == 25)
            {
                Mass = pythia.event[i].m();

                tree->Fill();
            }
    }

    pythia.stat();

    tree->Write();
    file->Close();

    pythia.settings.listChanged();

    return 0;
}