vectorTest.out: vectorTest.o vector_vector.o
	g++ -o vectorTest.out vectorTest.o vector_vector.o
vectorTest.o: vectorTest.cpp vector_vector.hpp
	g++ -c vectorTest.cpp
vector_vector.o: vector_vector.cpp vector_vector.hpp
	g++ -c vector_vector.cpp
clean:
	rm ./*.o ./*.out
