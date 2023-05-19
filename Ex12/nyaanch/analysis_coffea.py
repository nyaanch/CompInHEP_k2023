#!/usr/bin/env python3

import sys
import os,re
import datetime
import numpy as np
import multiprocessing

from coffea import processor

import hist
import uproot

class Analysis(processor.ProcessorABC):
    def __init__(self):
        self.histograms = {}
        self.histograms["h_pileup"] = (
            hist.Hist.new
            .Reg(100, 0 ,100, name="x", label="x-axis")
            .Double()
        ) 

    def process(self, events):
        self.histograms['h_pileup'].fill(x=events[events.HLT_IsoMu24 == True].PV_npvs)


        out = {}
        out.update(self.histograms)
        return out

    def postprocess(self, accumulator):
        pass

def main():

    MAX_WORKERS = max(multiprocessing.cpu_count()-1,1)
    CHUNKSIZE = 1000000
    MAXCHUNKS = None

    samples = {"DYJetsToLL": ["DYJetsToLL.root"]}

    job_executor = processor.FuturesExecutor(workers = MAX_WORKERS)
    
    run = processor.Runner(
        executor = job_executor,
        # schema=nanoevents.NanoAODSchema,
        chunksize = CHUNKSIZE,
        maxchunks = MAXCHUNKS
    )
    result = run(samples, 'Events', Analysis())

    with uproot.recreate("output_coffea.root") as fOUT:
        days = ["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"]
        now = datetime.datetime.now()
        m = "produced: %s %s"%(days[now.weekday()],now)
        fOUT[f"{m}"] = ""

        for key in result.keys():
            fOUT[f"{key}"] = result[key]


if __name__ == "__main__":
    main()