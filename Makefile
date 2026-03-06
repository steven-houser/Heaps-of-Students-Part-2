all: heapStudents

heapStudents: main.o date.o address.o student.o
	g++ -g main.o date.o address.o student.o -o heapStudents

main.o: main.cpp date.h address.h student.h
	g++ -g -c main.cpp

date.o: date.cpp date.h
	g++ -g -c date.cpp

address.o: address.cpp address.h
	g++ -g -c address.cpp

student.o: student.cpp student.h date.h address.h
	g++ -g -c student.cpp

run: heapStudents
	./heapStudents

clean:
	rm -f *.o heapStudents

debug: heapStudents
	gdb heapStudents

valgrind: heapStudents
	valgrind --leak-check=full ./heapStudents
