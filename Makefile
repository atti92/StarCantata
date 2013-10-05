# Makefile for Irrlicht Examples
# It's usually sufficient to change just the target name and source file list
# and be sure that CXX is set to a valid compiler

#os name, for some reason
OS := $(shell uname)
ARCH := $(shell uname -m)

ifeq ($(OS), Linux)
ifeq ($(ARCH), x86_64)
LIBSELECT=64
else
LIBSELECT=32
endif
endif

#solaris real-time features
ifeq ($(HOSTTYPE), sun4)
LDFLAGS += -lrt
endif


IRRLICHT_LIB=-Ldependencies/irrlicht/lib/Linux -lIrrlicht

# Name of the executable created (.exe will be added automatically if necessary)
Target:=StarCantata

# Path for the executable. Note that Irrlicht.dll should usually also be there for win32 systems
BinPath=.

# target specific settings
# name of the binary - only valid for targets which set SYSTEM
DESTPATH=$(BinPath)/$(Target)


# general compiler settings (might need to be set when compiling the lib, too)
# preprocessor flags, e.g. defines and include paths
USERCPPFLAGS=
# compiler flags such as optimization flags
USERCXXFLAGS=-ggdb -Wall
# linker flags such as additional libraries and link paths
USERLDFLAGS =-L/usr/X11R6/lib$(LIBSELECT) -lGL -lXxf86vm -lXext -lX11 -lXcursor

####
#no changes necessary below this line
####

CPPFLAGS=$(USERCPPFLAGS) -Idependencies/irrlicht/include -Isrc -Ipugixml -I/usr/X11R6/include
CXXFLAGS=$(USERCXXFLAGS)
LDFLAGS =$(USERLDFLAGS) $(IRRLICHT_LIB)

# List of source directories
SRCD = src
XMLD = pugixml

include make.objects

$(SRCD)%.o : $(SRCD)%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(XMLD)%.o : $(XMLD)%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

#default target is Linux
all: $(SRC) $(XML)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SRC) $(XML) -o $(DESTPATH) $(LDFLAGS)

#.cpp.o:
#	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(SRCD)/*.o
	rm -f $(XMLD)/*.o
