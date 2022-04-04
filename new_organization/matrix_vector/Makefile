matrix_vector_test.out: matrix_vector_test.o
	g++ -o matrix_vector_test.out matrix_vector_test.o

matrix_vector_test.o: matrix_vector_test.cpp matrix_vector.hpp
	g++ -c matrix_vector_test.cpp matrix_vector.hpp

clean:
	rm ./*.o ./*.out
