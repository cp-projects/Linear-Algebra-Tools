vectorTest.out: vectorTest.o
	g++ -o vectorTest.out vectorTest.o
vectorTest.o: vectorTest.cpp fast_vector_vector.hpp
	g++ -c vectorTest.cpp

clean:
	rm ./*.o ./*.out
