CXX=g++

LINKER=ld
INTR_LINK=$(LINKER) -r

CFLAG=$(XFLAGS) -ggdb -I./ -Isystem/include -Idomain
BIN=bin
ODIR=$(BIN)/obj

CFLAGS_XML=`xml2-config --cflags`
XML_LIB=`xml2-config --libs`

LIB_GTK=`pkg-config --libs --cflags gtk+-3.0`
CFLAGS_GTK=`pkg-config --cflags gtk+-3.0`

CFLAG_GX=$(CFLAGS_XML) $(CFLAGS_GTK)

DOM=domain
DOMM=$(DOM)/models
DOMC=$(DOM)/controllers
DOMV=$(DOM)/views
DOMF=$(DOM)/factories

system_factories.o:
	$(CXX) $(CFLAG) $(CFLAGS_GTK) -c system/factories/SignalFactory.cpp  -o $(ODIR)/SignalFactory.o
	$(INTR_LINK) \
		$(ODIR)/SignalFactory.o \
		-o $(ODIR)/system_factories.o

system_signals.o:
	$(CXX) $(CFLAG) $(CFLAGS_GTK) -c system/signals/SignalHandler.cpp  -o $(ODIR)/SignalHandler.o
	$(CXX) $(CFLAG) $(CFLAGS_GTK) -c system/signals/SignalBank.cpp  -o $(ODIR)/SignalBank.o
	$(INTR_LINK) \
		$(ODIR)/SignalHandler.o \
		$(ODIR)/SignalBank.o \
		-o $(ODIR)/system_data.o


system_controllers.o:
	$(CXX) $(CFLAG) $(CFLAGS_GTK) -c system/Controller.cpp  -o $(ODIR)/Controller.o
	$(CXX) $(CFLAG) $(CFLAGS_GTK) -c system/controllers/ToolController.cpp  -o $(ODIR)/ToolController.o
	$(CXX) $(CFLAG) $(CFLAGS_GTK) -c system/controllers/UnitController.cpp  -o $(ODIR)/UnitController.o
	$(INTR_LINK) \
		$(ODIR)/Controller.o \
		$(ODIR)/ToolController.o \
		$(ODIR)/UnitController.o \
		-o $(ODIR)/system_controllers.o

system_views.o:
	$(CXX) $(CFLAG) $(CFLAGS_GTK) -c system/View.cpp  -o $(ODIR)/View.o
	$(CXX) $(CFLAG) $(CFLAGS_GTK) -c system/views/WindowView.cpp  -o $(ODIR)/WindowView.o
	$(INTR_LINK) \
		$(ODIR)/View.o \
		$(ODIR)/WindowView.o \
		-o $(ODIR)/system_views.o

system_models.o:
	$(CXX) $(CFLAG) -c system/Model.cpp  -o $(ODIR)/Model.o
	$(CXX) $(CFLAG) $(CFLAGS_GTK) -c system/models/DirectoryModel.cpp  -o $(ODIR)/DirectoryModel.o
	$(CXX) $(CFLAG) $(CFLAGS_GTK) -c system/models/ControlModel.cpp  -o $(ODIR)/ControlModel.o
	$(INTR_LINK) \
		$(ODIR)/Model.o \
		$(ODIR)/DirectoryModel.o \
		$(ODIR)/ControlModel.o \
		-o $(ODIR)/system_models.o

system_unit.o: system_signals.o system_factories.o system_models.o system_views.o system_controllers.o
	$(INTR_LINK) \
		$(ODIR)/system_data.o \
		$(ODIR)/system_factories.o \
		$(ODIR)/system_models.o \
		$(ODIR)/system_views.o \
		$(ODIR)/system_controllers.o \
		-o $(ODIR)/system_unit.o



framework: system_unit.o
	$(CXX) $(CFLAG) $(CFLAGS_GTK) -c entry.cpp -o $(ODIR)/entry.o
	$(CXX) $(LIB_GTK) \
		$(ODIR)/system_unit.o \
		$(ODIR)/entry.o \
		-o $(BIN)/framework

all:
	make framework


clean:
	rm -rf $(ODIR)/*.o
	make all

