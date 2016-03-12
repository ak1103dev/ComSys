#--------------------------------------------------------
# Simple Makefile
# Note header files are not checked if updated!
#--------------------------------------------------------

# Specify all source and header files
SRCS = stimulus.cpp
SRCH = reg.h reg32.h divide_compound.h dff.h RegisterFile.h mux_dmux.h

# Target file run.exe
TARGET = run

# Variable that points to SystemC installation path
SYSTEMC = /usr/local/systemc-2.3.1

INCDIR = -I. -I.. -I$(SYSTEMC)/include
LIBDIR = -L. -L.. -L$(SYSTEMC)/lib-linux64
LIBS   = -lsystemc -lm

CC     = g++
CFLAGS = -g -Wno-deprecated -Wall
OBJS   = $(SRCS:.cpp=.o)

EXE    = $(TARGET).exe

.SUFFIXES: .cpp .o

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS) 2>&1 | c++filt

all: $(EXE)	$(SRCH)

.cpp.o:
	$(CC) $(DEBUG) $(CFLAGS) $(INCDIR) -c $<

clean:
	rm -f $(OBJS) *~ $(EXE) *.bak $(TARGET).exe.stackdump wave.vcd
