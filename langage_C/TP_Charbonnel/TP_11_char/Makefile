OPTS=-Wall
TARGETS=11.1 11.2a 11.2b

%: %.c
	gcc $(OPTS) -o $@ $@.c

all: $(TARGETS)

11.1 : 11.1.c
	cc $(OPTS) -o $@ $@.c -lm

11.2b : 11.2b.c
	cc $(OPTS) -o $@ $@.c -lreadline

clean:
	rm $(TARGETS)
