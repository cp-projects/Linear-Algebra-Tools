testMM.out: testMM.o
	g++ -std=c++17 -g -o testMM.out testMM.o

testMM.o: testMM.cpp matrix.hpp
	g++ -std=c++17 -g -c testMM.cpp

clean:
	rm ./*.o ./*.out

