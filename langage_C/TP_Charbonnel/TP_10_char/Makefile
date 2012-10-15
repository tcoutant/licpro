OPTS=-Wall
TARGETS=10.2 10.3

%: %.c
	gcc $(OPTS) -o $@ $@.c

all: $(TARGETS)

clean:
	rm $(TARGETS)
