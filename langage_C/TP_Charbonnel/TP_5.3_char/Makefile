CCOPTS=-Wall
%: %.c
	gcc $(CCOPTS) -o $@ $@.c

all: 5.1 5.2 5.3 5.4 5.7

5.3thy: 5.3thy.c
	cc $(CCOPTS) -o $@ $@.c -lreadline 

5.4thy: 5.4thy.c
	cc $(CCOPTS) -o $@ $@.c -lreadline 
	
5.7thy: 5.7thy.c
	cc $(CCOPTS) -o $@ $@.c -lreadline 
