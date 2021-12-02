testHeaders: testHeaders.o myArithmetic.o
	g++ -o testHeaders testHeaders.o myArithmetic.o

testHeaders.o: testHeaders.cpp matrix.hpp
	g++ -c testHeaders.cpp

myArithmetic.o: myArithmetic.cpp myArithmetic.hpp
	g++ -c myArithmetic.cpp

clean:
	rm ./*.o testHeaders