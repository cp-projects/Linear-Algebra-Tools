testMyArithmetic.out: testMyArithmetic.o
	g++ -o testMyArithmetic.out testMyArithmetic.o


testMyArithmetic.o: testMyArithmetic.cpp myArithmetic.hpp
	g++ -c testMyArithmetic.cpp

clean:
	rm ./*.o ./*.out

