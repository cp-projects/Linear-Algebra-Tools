tes:
	[ -f testHeaders.out ] && rm testHeaders.out || echo "404 file not found"
	[ -f testHeaders.o ] && rm testHeaders.o || echo "404 file not found"
	make cleanSub
	make subdirs
	make testHeaders.o
	make testHeaders.out
	valgrind ./testHeaders.out



testHeaders.out: testHeaders.o
	g++ -o testHeaders.out testHeaders.o

testHeaders.o: testHeaders.cpp libLA.hpp
	g++ -c testHeaders.cpp

clean:
	rm ./*.o ./*.out


SUBDIRS = libLA/

subdirs:
	for dir in $(SUBDIRS); do \
                $(MAKE) -C $$dir; \
        done

cleanSub:
	for dir in $(SUBDIRS); do \
                $(MAKE) -C $$dir clean; \
        done

