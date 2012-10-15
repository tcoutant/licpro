GCCOPT=-Wall
%: %.c
	gcc $(GCCOPT) -o $@ $@.c

palin: mainpalin.o
	gcc -o palin mainpalin.o -L. -lmylib -lreadline
mainpalin.o: mainpalin.c
	gcc -c -Wall mainpalin.c
ana: mainana.o
	gcc -o ana mainana.o -L. -lmylib -lreadline
mainana.o: mainana.c
	gcc -c -Wall mainana.c
libmylib.a: palin.o ana.o
	ar -rs libmylib.a palin.o ana.o
palin.o: palin.c mylib.h
	gcc -c -Wall palin.c
ana.o: ana.c mylib.h
	gcc -c -Wall ana.c 

