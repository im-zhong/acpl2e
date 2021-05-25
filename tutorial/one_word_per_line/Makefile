objects = one_word_per_line.o

one_word_per_line : $(objects)
	gcc -o one_word_per_line.out $(objects)

$(objects) :

.PHONY : test clean

test :
	./test.sh one_word_per_line.c Makefile

clean :
	rm one_word_per_line.out $(objects) *.tmp

