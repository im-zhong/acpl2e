
# prerequeists should be file for the best
# otherwise it will always be compiled
all : word_length.out character_frequency.out

debug : CFLAGS = -g
debug : all 

word_length.out : c_string.o graphics.o histogram.o word_length.o 
	$(CC) -o word_length.out c_string.o graphics.o histogram.o word_length.o

character_frequency.out : c_string.o graphics.o histogram.o character_frequency.o
	$(CC) -o character_frequency.out c_string.o graphics.o histogram.o character_frequency.o
	
# every c source file should compile to a .o file
# every c source file should depends on its header file
# $(objects) : histogram.h
#1 cc -c -o histogram.o histogram.c
#2 cc -c -o word_length.o word_length.c
#3 cc -c -o character_frequency.o character_frequency.c

c_string.o histogram.o word_length.o character_frequency.o : c_string.h

graphics.o histogram.o : graphics.h

histogram.o word_length.o character_frequency.o : histogram.h

# cc usually link to gcc
# -c means do not link
# -o means generate the object file
# histogram.o comes from the target of the rule
# histogram.c is auto-generate by make, which is related to histogram.o
# as for the prerequeists, histogram.h is required, because when header fileer
# modified, we want to recompiler it, and hisgotram.c is alse required but do
# not need to write it, because make will auto-generate it
# make will only auto-generate the relative source file,
# and do not care about the prerequeists

.PHONY : clean
clean :
	rm *.o *.out

