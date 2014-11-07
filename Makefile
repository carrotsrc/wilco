BINARY=wilco
REL=.
include Makefile.inc

all: framework.o domain.o
	mkdir -p $(BIN)
	$(CXX) $(LIB_GTK) \
	framework.o \
	domain.o \
	-o $(BIN)/$(BINARY)

framework.o:
	$(MAKE) -C system REL=.. TARG=framework

domain.o:
	$(MAKE) -C domain REL=.. TARG=domain

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.d" -type f -delete
	make
