cc ?= cc
CFLAGS = -Wall
LDFALGS = 

BINDIR := bin
BINARY := qual

$(BINDIR)/$(BINARY):
	if [ ! -d $(BINDIR) ]; then mkdir bin; fi
	$(CC) $(CFLAGS) -o $(BINDIR)/$(BINARY) main.c

.PHONY: clean
clean:
	rm -f $(BINDIR)/$(BINARY)

.PHONY: test
test: clean
