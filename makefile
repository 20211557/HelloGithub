CC = g++
target = findString
objects = strmain.o kmp.o

$(target) : $(objects)
	$(CC) -o $(target) $(objects)

kmp.o : kmp.h

.PHONY : clean

clean :
	rm $(target) $(objects)
