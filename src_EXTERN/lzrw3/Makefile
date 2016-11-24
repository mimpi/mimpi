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
LIBNAME  = liblzrw3.a
TESTPATH = ./
TESTNAME = test_lzrw3

OBJ   = \
        $(SOURCE_PATH)/time.o \
        $(SOURCE_PATH)/lzrw3.o \
        \
        $(SOURCE_PATH)/test_lzrw3.o



#--------------------------
# 3.- compilation rules
#--------------------------
 
all:    init  $(OBJ)  libs  tests
fast:         $(OBJ)  libs  tests


init:
	@echo "" 
	@echo "    lzrw3" 
	@echo "   -------" 
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
	@echo "     liblzrw3.a ..."
	@ar -rc $(LIBPATH)/$(LIBNAME)
	@ar -rs $(LIBPATH)/$(LIBNAME) lzrw3.o

tests:
	@echo "   Building test :"
	@echo "     test_lzrw3 ..."
	@$(CC)  $(CFLAGS) -o $(TESTPATH)/$(TESTNAME) test_lzrw3.o time.o $(LIBPATH)/$(LIBNAME)


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

