test_errors.out: test_errors.o matrixErrors.o
	g++ -o test_errors.o matrixErrors.o
test_errors.o: test_errors.cpp matrixErrors.o
	g++ -c test_errors.cpp
matrixErrors.o: matrixErrors.cpp matrixErrors.hpp
	g++ -c matrixErrors.cpp
clean:
	rm ./*.o ./*.out
