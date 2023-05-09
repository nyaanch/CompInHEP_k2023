CXX = g++
OPT = -O2 -Wall -fPIC -g

all:
	$(MAKE) cpp_compile_run --no-print-directory
	$(MAKE) bash_run --no-print-directory
	$(MAKE) python_run 
	$(MAKE) clean --no-print-directory

cpp_compile_run: 
	$(CXX) $(OPT) ex2_1.cpp -o ex2_1
	./ex2_1

bash_run:
	./ex2_1_b.sh

python_run:
	python3 ex2_1.py
	python3 ex2_2.py
	python3 ex2_3.py 


clean:
	rm -rf $(wildcard *.o *.exe)