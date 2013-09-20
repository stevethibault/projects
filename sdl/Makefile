test:
	make build;
	make run;
build:
	gcc -I"/usr/include/SDL" -c sdldemo.c;
	gcc sdldemo.o -lSDL -o sdldemo;
run:
	./sdldemo;
clean:
	-rm sdldemo.o;
	-rm sdldemo;
