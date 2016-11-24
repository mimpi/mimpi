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
INCLUDE_PATH   = -I./ -I./../../src/ -I./../../include/
SOURCE_PATH    = .
CFLAGS         = -DHAVE_CONFIG_H -D__LINUX__
LIB_PATH       = -L/usr/lib -L../../lib
LIBLINK        = -lmpi -lpthread -lz -llzo


#--------------------------
# 2.- library object
#--------------------------

LIBPATH   = ../../lib/
OBJETOS   = \
            $(SOURCE_PATH)/ping.o


#--------------------------
# 3.- compilation rules
#--------------------------

all:    init    ping
refast: clean   ping
fast:   ping

ping: $(OBJETOS)
	@echo "   Building ping :"
	@echo "     ping.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o ping.exe $(OBJETOS) $(LIBLINK)


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    examples" 
	@echo "   ----------"
	@echo "" 
	@echo "   Computer  :"
	@echo "     "`uname -a` 
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
	@rm -fr $(OBJETOS) ./ping.exe
	@echo "   Trash succesfully removed !."


# ........................................................................

