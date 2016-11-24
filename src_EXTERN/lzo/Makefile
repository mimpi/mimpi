# Generated automatically from Makefile.in by configure.
# ........................................................................
#
#  fgarcia,acaldero@hinojo.datsi.fi.upm.es
#
# ........................................................................



#--------------------------
# 1.- Native configuration
#--------------------------

CC            = gcc
MAKE          = gmake
SOURCE_PATH   = ./
INCLUDE_PATH  = -I. -I../include -I../../src
CFLAGS        = -O4 -DTIMES -DHAVE_CONFIG_H



#--------------------------
# 2.- library object
#--------------------------

LIBPATH  = ../../lib/
LIBNAME  = liblzo.a
TESTPATH = ./
TESTNAME = testmini

OBJ   = \
        $(SOURCE_PATH)/minilzo.o \
        \
        $(SOURCE_PATH)/testmini.o



#--------------------------
# 3.- compilation rules
#--------------------------
 
all:    init  $(OBJ)  libs  tests
fast:         $(OBJ)  libs  tests


init:
	@echo "" 
	@echo "    minilzo" 
	@echo "   ---------" 
	@echo "" 
	@echo "   Options   :"
	@echo "     "$(CFLAGS)
	@echo "   Directory :"
	@echo "     "$(INCLUDE_PATH)
	@echo "   Compiling :"

%.o: %.c
	@echo "     $< ..." 
	@$(CC)  $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@ 

libs:
	@echo "   Building library :"
	@echo "     liblzo.a ..."
	@ar -rc $(LIBPATH)/$(LIBNAME)
	@ar -rs $(LIBPATH)/$(LIBNAME) minilzo.o

tests:
	@echo "   Building test :"
	@echo "     testmini ..."
	@$(CC)  $(CFLAGS) -o $(TESTPATH)/$(TESTNAME) testmini.o $(LIBPATH)/$(LIBNAME)


clean: 
	@echo "   Removing object files..."
	@rm -fr $(OBJ) 

cleane: 
	@echo "   Removing test and examples..."
	@rm -fr $(TESTPATH)/$(TESTNAME)
	@rm -fr $(LIBPATH)/$(LIBNAME)

cleanall: clean  cleane
	@echo "   Removed trash."


# ........................................................................

