import ROOT
import numpy as np

N = 10000
mean = 0.0
sigma = 1.0

# Create a ROOT file and a TTree to store the data
f = ROOT.TFile("data.root", "RECREATE")
tree = ROOT.TTree("tree", "Tree with random numbers")

# Create a numpy array to store the data
data = np.zeros(1, dtype=float)

# Create a branch in the tree for the data
tree.Branch("data", data, "data/D")

# Generate and fill the data
rand = ROOT.TRandom3()
for i in range(N):
    data[0]  = rand.Gaus(mean, sigma)
    tree.Fill()

# Write the tree to the ROOT file
tree.Write()

# Close the ROOT file
f.Close()
