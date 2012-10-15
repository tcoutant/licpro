CCOPTS=-Wall
TARGETS=7.1 7.2 7.3 7.4 7.5

%: %.c
	gcc $(CCOPTS) -o $@ $@.c

all: $(TARGETS)

7.3: 7.3.c
	gcc $(CCOPTS) -o $@ $@.c -lreadline

7.4: 7.4.c
	gcc $(CCOPTS) -o $@ $@.c -L../mylib -lmylib

clean:
	rm $(TARGETS)
