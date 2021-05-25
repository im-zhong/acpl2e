objects = cat.o

cat : $(objects)
	gcc -o cat.out $(objects)

$(objects) :

.PHONY : clean
clean :
	rm cat.out $(objects)

