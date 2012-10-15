cdCCOPTS=-Wall
TARGETS=6.1 6.2
LDPATH=../mylib

%: %.c
	gcc $(CCOPTS) -o $@ $@.c

all: $(TARGETS)

6.1char: 6.1char.c
	gcc $(CCOPTS) -o $@ $@.c -L$(LDPATH) -lmylib

6.2: 6.2.c
	gcc $(CCOPTS) -o $@ $@.c -L$(LDPATH) -lmylib

clean:
	rm $(TARGETS)
