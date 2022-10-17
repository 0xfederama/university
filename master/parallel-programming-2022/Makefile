CXX 	 = g++ -std=c++20
CXXFLAGS = -O3 -pthread
DBGFLAGS = -O0 -pthread -DDEBUG -g -Wall
ALLDEFS  = -DJACOBI_SEQ -DJACOBI_STD -DJACOBI_FF

.PHONY: all prod debug seq std ff par clean overhead

all: prod overhead debug seq std ff par

prod:
	$(CXX) $(CXXFLAGS) $(ALLDEFS) -o ./bin/jacobi ./src/main.cpp
	
debug:
	$(CXX) $(DBGFLAGS) $(ALLDEFS) -o ./bin/jacobi_debug ./src/main.cpp

overhead:
	$(CXX) $(CXXFLAGS) -DJACOBI_STD -DJACOBI_FF -DOVERHEAD -o ./bin/jacobi_overhead ./src/main.cpp

seq:
	$(CXX) $(CXXFLAGS) -DJACOBI_SEQ -o ./bin/jacobi_seq ./src/main.cpp

std:
	$(CXX) $(CXXFLAGS) -DJACOBI_STD -o ./bin/jacobi_std ./src/main.cpp

ff:
	$(CXX) $(CXXFLAGS) -DJACOBI_FF -o ./bin/jacobi_ff ./src/main.cpp

par:
	$(CXX) $(CXXFLAGS) -DJACOBI_STD -DJACOBI_FF -o ./bin/jacobi_par ./src/main.cpp

clean:
	rm -f ./bin/*