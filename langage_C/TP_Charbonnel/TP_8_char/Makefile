OPTS=-Wall
TARGETS=8.2a 8.2b 8.3 8.4 8.5a 8.5b

%: %.c
	gcc $(OPTS) -o $@ $@.c

all: $(TARGETS)

8.2a: 8.2a.c 8.2.h

8.2b: 8.2b.c 8.2.h

8.5a: 8.5a.c 8.5.h

8.5b: 8.5b.c 8.5.h

clean:
	rm $(TARGETS)
