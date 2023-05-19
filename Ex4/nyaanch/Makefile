# OPT = -O2 -Wall -fPIC -g

# all:
# 	$(MAKE) cpp_compile_run --no-print-directory
# 	$(MAKE) clean --no-print-directory

# cpp_compile_run: 
# 	$(CXX) $(OPT) Simulated.cpp -o Simulated.exe
# 	./Simulated.exe

# clean:
# 	rm -rf $(wildcard *.o *.exe)

CXX = gcc
CXXFLAGS = -Wall -Wextra -O2 -g -fPIC -Werror -lstdc++

all: cpp_compile_run

cpp_compile_run: Simulated.o Track.o test.o
	$(CXX) $(CXXFLAGS) Simulated.o Track.o test.o -o test

Simulated.o: Simulated.cpp Simulated.h Track.h
	$(CXX) $(CXXFLAGS) -c Simulated.cpp -o Simulated.o

Track.o: Track.cpp Track.h
	$(CXX) $(CXXFLAGS) -c Track.cpp -o Track.o

test.o: test.cpp Simulated.h Track.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

clean:
	rm -f *.o main
