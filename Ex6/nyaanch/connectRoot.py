import ROOT

# Open the ROOT file and retrieve the tree with the data
f = ROOT.TFile("data.root")
tree = f.Get("tree")

# Create a canvas and a histogram with the data from the tree
canvas = ROOT.TCanvas("canvas", "Normally Distributed Random Numbers", 800, 600)
hist = ROOT.TH1D("hist", "Normally Distributed Random Numbers", 100, -5.0, 5.0)

# Fill the histogram with the data from the tree
tree.Draw("data>>hist")

# Customize the histogram properties
hist.SetLineColor(ROOT.kBlack)
hist.SetLineWidth(2)
hist.SetFillColor(ROOT.kYellow)

# Customize the canvas properties
canvas.SetFillColor(ROOT.kWhite)
canvas.SetLeftMargin(0.15)
canvas.SetBottomMargin(0.15)

# Add axis labels
hist.GetXaxis().SetTitle("Value")
hist.GetYaxis().SetTitle("Events")

# Fit the histogram with a Gaussian function
fitFunc = ROOT.TF1("fitFunc", "gaus", -5.0, 5.0)
hist.Fit(fitFunc)

hist.SetStats(0)
canvas.Update()

# Draw the histogram and the fit function
hist.Draw()
fitFunc.Draw("same")

# Save the plot to a PNG file
canvas.SaveAs("hist.root")
canvas.SaveAs("plot.png")

# Close the ROOT file
f.Close()
