test_ar.out: test_ar.o myArithmetic.o
	g++ -o test_ar.out test_ar.o myArithmetic.o

test_ar.o: test_ar.cpp
	g++ -c test_ar.cpp

myArithmetic.o: myArithmetic.cpp myArithmetic.hpp
	g++ -c myArithmetic.cpp

clean:
	rm ./*.o ./*.out
