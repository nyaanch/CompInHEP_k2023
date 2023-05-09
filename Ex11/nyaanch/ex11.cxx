#include <iostream>
#include "TTree.h"
#include "TFile.h"
#include "TSelector.h"

using namespace std;

int main()
{   
    TFile *file = new TFile("DYJetsToLL.root", "READ");
    TTree *tree = (TTree*)file->Get("Events");

    // Create a TSelector object   
    //tree -> MakeSelector("selector");

    tree->Process("selector.C");

    file -> Close();

    return 0;
}