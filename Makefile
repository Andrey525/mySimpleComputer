
bin/prog: build/main.o lib/libmySimpleComputer.a
	gcc build/main.o -L./lib -lmySimpleComputer -o bin/prog

build/main.o: src/main.c src/mySimpleComputer.h
	gcc -Wall -Werror -c src/main.c -o build/main.o 

# lib/libmySimpleComputer.a: build/mySimpleComputer.o 
# 	ar rc lib/libmySimpleComputer.a build/mySimpleComputer.o

# build/mySimpleComputer.o: src/mySimpleComputer.c src/mySimpleComputer.h
# 	gcc -Wall -Werror -c src/mySimpleComputer.c -o build/mySimpleComputer.o 

clean: 
	rm -rf bin/prog build/*.o *.bin

.PHONY: all clean 