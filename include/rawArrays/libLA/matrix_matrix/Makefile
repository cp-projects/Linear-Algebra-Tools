testMM.out: testMM.o
	g++ -o testMM.out testMM.o

testMM.o: testMM.cpp matrix_matrix.hpp ../printLA/printLA.hpp 
	g++ -c testMM.cpp

clean:
	rm ./*.o ./*.out

