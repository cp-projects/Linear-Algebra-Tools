test_det.out: test_det.o
	g++ -o test_det.out test_det.o
test_det.o: test_det.cpp determinant.hpp
	g++ -c test_det.cpp
clean:
	rm ./*.o ./*.out
