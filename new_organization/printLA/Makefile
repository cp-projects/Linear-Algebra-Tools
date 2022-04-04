test_print.out: test_print.o
	g++ -o test_print.out test_print.o

test_print.o: test_print.cpp printLA.hpp
	g++ -c test_print.cpp

#printLa.o: printLA.cpp printLA.hpp
	#g++ -c  printLA.hpp printLa.cpp

clean:
	rm ./*.o ./*.out
