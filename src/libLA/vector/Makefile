vectorTest.out: vectorTest.o
	g++ -std=c++17 -o vectorTest.out vectorTest.o
vectorTest.o: vectorTest.cpp vector.hpp
	g++ -std=c++17 -c vectorTest.cpp

clean:
	rm ./*.o ./*.out
