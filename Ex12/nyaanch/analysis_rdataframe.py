#!/usr/bin/env python

import datetime

import ROOT

ROOT.ROOT.EnableImplicitMT()

def main():

    df = ROOT.RDataFrame("Events", "DYJetsToLL.root")
    df = df.Filter("HLT_IsoMu24 > 0.5", "PV_npvs")
   
    hist = df.Histo1D(("h_pileup", ";x-axis;y-axis", 100, 0, 100), "PV_npvs")

    fOUT = ROOT.TFile.Open("output_rdataframe.root","RECREATE")

    days = ["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"]
    now = datetime.datetime.now()
    m = "produced: %s %s"%(days[now.weekday()],now)
    timestamp = ROOT.TNamed(m,"")
    timestamp.Write()

    hist.Write()

    fOUT.Close()

if __name__ == "__main__":
    main()

