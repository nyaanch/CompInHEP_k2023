CXX = g++
OPT = -O2 -Wall -fPIC -g

all:
	$(MAKE) cpp_compile_run --no-print-directory
	$(MAKE) clean --no-print-directory

cpp_compile_run: 
	$(CXX) $(OPT) calc.cpp -o calc.exe
	./calc.exe

clean:
	rm -rf $(wildcard *.o *.exe)