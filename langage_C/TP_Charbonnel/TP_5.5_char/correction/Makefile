all: main_palin main_ana

main_palin: main_palin.o palin.o
	cc -o palin main_palin.o palin.o -lreadline
	
main_palin.o: main_palin.c mylib.h
	cc -c -Wall main_palin.c

palin.o: palin.c mylib.h
	cc -c -Wall palin.c

main_ana: main_ana.o ana.o
	cc -o ana main_ana.o ana.o -lreadline

main_ana.o: main_ana.c mylib.h
	cc -c -Wall main_ana.c

ana.o: ana.c mylib.h
	cc -c -Wall ana.c
