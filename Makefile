
bin/prog: build/main.o build/mySimpleComputer.o 
	gcc build/main.o build/mySimpleComputer.o -o bin/prog

build/main.o: src/main.c src/mySimpleComputer.h
	gcc -Wall -Werror -c src/main.c -o build/main.o 

build/mySimpleComputer.o: src/mySimpleComputer.c src/mySimpleComputer.h
	gcc -Wall -Werror -c src/mySimpleComputer.c -o build/mySimpleComputer.o 

clean: 
	rm -rf bin/prog build/*.o *.bin

.PHONY: all clean 