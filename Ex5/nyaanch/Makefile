ROOTLIB = $(shell root-config --libs)
ROOTINC = $(shell root-config --cflags)
INC = -I. $(ROOTINC)
LIB = -L. $(ROOTLIB)
OPT = -O2 -Wall -fPIC -g

all:
	$(MAKE) compile
	$(MAKE) clean

compile:
	@$(CXX) $(OPT) $(INC) tree.cpp $(LIB) $(ROOTLIB) -o tree
	@echo Created tree, now run ./tree
	@./tree
	@$(CXX) $(OPT) $(INC) test.cpp $(LIB) $(ROOTLIB) -o test
	@echo Created test, now run ./test
	@./test

clean:
	rm -rf $(wildcard *.o)
	rm tree test
