DEBUG_FLAGS = -fsanitize=address -fsanitize=undefined -g -fno-omit-frame-pointer -Wall -pedantic

merge:
	gcc -Wall -pedantic -c mergesort.c
	gcc -o merge mergesort.o

merge_sane: 
	gcc ${DEBUG_FLAGS} -c mergesort.c
	gcc ${DEBUG_FLAGS} -o merge mergesort.o

lab2:
	gcc -Wall -c lab2.c            # Builds lab2.o 
	gcc -Wall -c revwords.c        # Builds revwords.o
	gcc -o lab2 lab2.o revwords.o  # Builds executable 

clean:
	rm -f mergesort.o merge lab2 lab2.o revwords.o