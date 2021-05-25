objects = hello_world.o

hello_world : $(objects) 
	gcc -o hello_world.out $(objects)

$(objects) :

.PHONY : clean
clean :
	rm hello_world.out $(objects)

