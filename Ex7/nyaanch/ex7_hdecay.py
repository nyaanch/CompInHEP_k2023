import ROOT
import re
from array import array

# Read the table data from a file
with open("br.sm2", "r") as file:
    table_data = file.read()

# Extract mass and width using regex
masses = []
widths = []

pattern = r"\d+\.\d+"  # Pattern to match decimal numbers
matches = re.findall(pattern, table_data)

for i in range(0, len(matches), 7):
    mass = float(matches[i])
    width = float(matches[i + 6])
    masses.append(mass)
    widths.append(width)

# Create a TGraph object
graph = ROOT.TGraph(len(masses), array('d', masses), array('d', widths))
graph.SetTitle("SM Higgs Boson Width")
graph.GetXaxis().SetTitle("Higgs Boson Mass [GeV]")
graph.GetYaxis().SetTitle("Width [GeV]")

# Create a canvas
canvas = ROOT.TCanvas("canvas", "Higgs Width", 800, 600)

# Draw the graph
graph.Draw("AP")
canvas.Update()

# Save the canvas
canvas.SaveAs("ex7_hdecay.pdf")
canvas.SaveAs("ex7_hdecay.root")