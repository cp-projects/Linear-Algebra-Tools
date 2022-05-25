test:
	[ -f test.out ] && rm test.out || echo "404 file not found"
	[ -f test.o ] && rm test.o || echo "404 file not found"
	make test.o
	make test.out
	valgrind ./test.out

        
        #[ -f test.out ] && rm test.out || echo "404 file not found"
        #make test.out
        #valgrind ./test.out

test.out: test.o
	g++ -std=c++17 -g -o test.out test.o

test.o: test.cpp matrix.hpp
	g++ -std=c++17 -g -c test.cpp

clean:
	rm ./*.o ./*.out

