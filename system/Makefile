include $(REL)/Makefile.inc
SOURCES := $(shell find ./ -name '*.cpp')
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

all: $(OBJECTS)
	$(INTR_LINK) $(OBJECTS) -o ../$(TARG).o

$(OBJECTS): %.o: %.cpp
	$(CXX) $(CFLAG) $(CFLAGS_GTK) -c $< -o $@
