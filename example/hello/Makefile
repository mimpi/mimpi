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
            $(SOURCE_PATH)/hello_world.o


#--------------------------
# 3.- compilation rules
#--------------------------

all:    init    hello_world
refast: clean   hello_world
fast:   hello_world

hello_world: $(OBJETOS)
	@echo "   Building hello_world :"
	@echo "     hello_world.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o hello_world.exe $(OBJETOS) $(LIBLINK)


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
	@rm -fr $(OBJETOS) ./hello_world.exe
	@echo "   Trash succesfully removed !."


# ........................................................................

