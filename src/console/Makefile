# Generated automatically from Makefile.in by configure.
# ........................................................................
#
#  fgarcia,acaldero@hinojo.datsi.fi.upm.es
#
# ........................................................................



#--------------------------
# 1.- Native configuration
#--------------------------

CC             = gcc
LIB_PATH       = -L/usr/lib
INCLUDE_PATH   = -I./ -I../  -I../../include
SOURCE_PATH    = ./
CFLAGS         = -O2 -Wall -DHAVE_CONFIG_H  -D__LINUX__
LIBLINK        = -lmpi -lpthread -lz -llzo


#--------------------------
# 2.- library object
#--------------------------

OBJETOS   = \
            $(SOURCE_PATH)/l_condition_msg.o   \
            $(SOURCE_PATH)/l_stack_msg.o       \
            $(SOURCE_PATH)/l_trace_msg.o       \
            $(SOURCE_PATH)/l_verbose_msg.o


#--------------------------
# 3.- compilation rules
#--------------------------

all:    init  $(OBJETOS)
fast:         $(OBJETOS)


init:
	@echo "" 
	@echo "    console" 
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


clean: 
	@echo "   Removing trash..."
	@rm -fr $(OBJETOS) 
	@echo "   Trash succesfully removed !."


# ........................................................................

