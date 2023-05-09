PYTHIA8_URL = https://pythia.org/download/pythia83/pythia8307.tgz
PYTHIA8_TGZ = $(notdir $(PYTHIA8_URL))
PYTHIA8_DIR = $(basename $(PYTHIA8_TGZ))

ROOTCFLAGS = $(shell root-config --cflags)
ROOTLIBS   = $(shell root-config --libs)

OPT = -g -Wall
INC = -I$(PYTHIA8_DIR)/include -I$(ROOTSYS)/include
LIBS = -L$(PYTHIA8_DIR)/lib -lpythia8 -ldl $(ROOTLIBS)

all: 
	$(MAKE) getPythia
	$(MAKE) ex8
	$(MAKE) ex8_job
	$(MAKE) clean

getPythia:
	@if [ -d "$(PYTHIA8_DIR)" ]; then echo "Pythia already installed"; else $(MAKE) getPythia0; fi

getPythia0:
	wget $(PYTHIA8_URL)
	tar xfvz $(PYTHIA8_TGZ)
	cd $(PYTHIA8_DIR) && ./configure && make
	@echo Installed Pythia
ex8:
	$(CXX) $(OPT) $(INC) $@.cxx $(LIBS) -o ex8.exe

ex8_job:
	@echo Starting job
	./ex8.job

clean:
	rm -rf $(wildcard *.exe)