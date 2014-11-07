CXX=g++

LINKER=ld
INTR_LINK=$(LINKER) -r

DEPFLAG=-MMD -MP

CFLAG=$(XFLAGS) -ggdb -I$(REL)/ -I$(REL)/system/include -I$(REL)/domain
BIN=bin
ODIR=$(BIN)/obj
OBJ_DIR=$(ODIR)

CFLAGS_XML=`xml2-config --cflags`
XML_LIB=`xml2-config --libs`

LIB_GTK=`pkg-config --libs --cflags gtk+-3.0`
CFLAGS_GTK=`pkg-config --cflags gtk+-3.0`

CFLAG_GX=$(CFLAGS_XML) $(CFLAGS_GTK)
