test_clean.out: test_clean.o
	g++ -o test_clean.out test_clean.o

test_clean.o: test_clean.cpp ../errorsLA/matrixErrors.hpp cleanMatrix.hpp ../printLA/printLA.hpp ../printLA/printLA.cpp
	g++ -c test_clean.cpp

clean:
	rm ./*.o ./*.out
