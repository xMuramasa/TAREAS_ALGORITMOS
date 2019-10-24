CC=g++
CFLAGS=-I.
DEPS = 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

obj/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

out: obj/main.o
	$(CC) -o out obj/main.o

clean:
	rm -f obj/* *~ core $(INCDIR)/*~

run:
	 ./out
