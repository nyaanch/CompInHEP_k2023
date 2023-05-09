import ROOT

# Open the file
f = ROOT.TFile("ex8.root")

# Get the tree
tree = f.Get("tree")

# Create a canvas
canvas = ROOT.TCanvas("canvas", "", 800, 600)

# Create a histogram
mass = ROOT.TH1F("mass", "Higgs boson mass disrtibution", 500, 124.97, 125.03)

# Loop over the events
for event in tree:
    mass.Fill(event.Mass)

# Customize the histogram properties
mass.SetLineColor(ROOT.kBlack)
mass.SetLineWidth(2)

# Customize the canvas properties
canvas.SetFillColor(ROOT.kWhite)
canvas.SetLeftMargin(0.15)
canvas.SetBottomMargin(0.15)

# Add axis labels
mass.GetXaxis().SetTitle("Mass {GeV}")
mass.GetYaxis().SetTitle("Events")

# Draw the histogram
mass.Draw()

# Calculate the mean and RMS of the mass distribution
mean = mass.GetMean()
rms = mass.GetRMS()

# Calculate the Breit-Wigner width using the RMS value
width = rms / ROOT.TMath.Sqrt(2)

# Save the width to an exisiting file
with open("width.txt", "a") as results:
    results.write("PART 2\n")
    results.write("========================================\n")
    results.write("Width = {:.8f} GeV".format(width))
    results.write("\n========================================\n")

# Save the canvas
canvas.SaveAs("plots.root")
canvas.SaveAs("plots.pdf")

# Close the file
f.Close()
