ROOTLIB = $(shell root-config --libs)
ROOTINC = $(shell root-config --cflags)
INC = -I. $(ROOTINC)
LIB = -L. $(ROOTLIB)
OPT = -O2 -Wall -fPIC -g

all:
	$(MAKE) compile
	$(MAKE) clean

compile:
	@$(CXX) $(OPT) $(INC) ex11.cxx $(LIB) $(ROOTLIB) -o ex11
	@echo Compiled, now run ./ex11
	@./ex11

clean:
	rm -rf $(wildcard *.o)
