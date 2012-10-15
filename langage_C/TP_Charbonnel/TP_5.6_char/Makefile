LDPATH=../mylib

all: main_palin main_ana

# on suppose que mylib est figée, on ne met pas de dépendance à mylib
#
# palin

main_palin: main_palin.o 
	cc -o palin main_palin.o -L$(LDPATH) -lreadline -lmylib
	
main_palin.o: main_palin.c
	cc -c -Wall main_palin.c

# ana

main_ana: main_ana.o 
	cc -o ana main_ana.o -L$(LDPATH) -lreadline -lmylib

main_ana.o: main_ana.c 
	cc -c -Wall main_ana.c

clean:
	rm *.o
