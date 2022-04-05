matrix_vector_test.out: matrix_vector_test.o
	g++ -o matrix_vector_test.out matrix_vector_test.o

matrix_vector_test.o: matrix_vector_test.cpp matrix_vector.hpp
	g++ -c matrix_vector_test.cpp

matrix_vector.o: matrix_vector.cpp matrix_vector.hpp
	g++ -c matrix_vector.cpp

clean:
	rm ./*.o ./*.out
