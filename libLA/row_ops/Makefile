row_ops_test.out: row_ops_test.o
	g++ -o row_ops_test.out row_ops_test.o

row_ops_test.o: row_ops_test.cpp row_ops.hpp
	g++ -c row_ops_test.cpp

clean:
	rm ./*.o ./*.out
