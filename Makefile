libnote.so:note.o
	gcc -shared -o libnote.so note.o
note.o:note.c
	gcc -fPIC -c note.c
clean:
	-rm *.o  *.so
