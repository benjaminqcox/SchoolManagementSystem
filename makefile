all: main

main: main.out libs
	gcc main.out -o main -L. subject.a student.a

main.out: main.c
	gcc -c main.c -o main.out

subject.out: subject.c
	gcc -c subject.c -o subject.out

subject.a: subject.out
	ar rcs subject.a subject.out

student.out: student.c
	gcc -c student.c -o student.out

student.a: student.out
	ar rcs student.a student.out

libs: subject.a student.a

clean:
	rm -f main *.out *.a