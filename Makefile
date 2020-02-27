PROJS=pst kdh
CFLAGS_DEBUG=-Wall -Wextra -gdwarf-2 -ggdb3 -O0 -fPIC
CFLAGS_PROD=-Wall -Wextra -O3 -fPIC
SOFLAGS=-shared

all: $(PROJS:=.o)
	@echo zstructs built successfully

.c.o:
	$(CC) $(CFLAGS) $(CFLAGS_PROD) -o $@ -c $<

clean:
	rm -f *.o
