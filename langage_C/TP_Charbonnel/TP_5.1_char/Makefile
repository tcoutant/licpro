CCOPTS=-Wall
%: %.c
	gcc $(CCOPTS) -o $@ $@.c

all: 5.1 5.2 5.3 5.4 5.7

5.3: 5.3.c
	cc $(CCOPTS) -o $@ $@.c -lreadline 

5.4: 5.4.c
	cc $(CCOPTS) -o $@ $@.c -lreadline 
	
5.7: 5.7.c
	cc $(CCOPTS) -o $@ $@.c -lreadline 
