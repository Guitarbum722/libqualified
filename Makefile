cc ?= cc
CFLAGS = -Wall
LDFALGS = 

BINDIR := bin
BINARY := qual

$(BINDIR)/$(BINARY):
	if [ ! -d $(BINDIR) ]; then mkdir bin; fi
	$(CC) $(CFLAGS) -o $(BINDIR)/$(BINARY) main.c qual.c

.PHONY: clean
clean:
	rm -f $(BINDIR)/$(BINARY)

.PHONY: test
test: clean

.PHONY: test
test: clean
	$(CC) -o tests/tests tests/tests.c qualified.c tests/unity/unity.c
	tests/tests
	rm -f tests/tests
