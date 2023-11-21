all: main.c visualiser.h langton.h visualiser.o langton.o
	gcc main.c visualiser.o langton.o -o ant -lncursesw
	./ant RRLLLRLLLRRR

library: visualiser.h langton.h
	gcc visualiser.c langton.c -c -fPIC
	gcc visualiser.o langton.o -shared -o libant.so -lncursesw

clean:
	rm ./*.o
	rm ./ant
	rm ./*.so

run:
	./ant i

visualiser.o: visualiser.c visualiser.h
	gcc -c visualiser.c -lncursesw

langton.o: langton.c langton.h
	gcc -c langton.c -lncursesw

test:
	cpplint --filter=-legal,-build *.c