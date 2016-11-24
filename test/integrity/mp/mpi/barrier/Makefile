# Generated automatically from Makefile.in by configure.
#---------------------- barrier' MAKEFILE -------------------- 
 



# --- 1.- Opciones del sistema base ---

CC             = gcc
LIB_PATH       = -L/usr/lib
INCLUDE_PATH   = -I./ -I./../../../../../src/ -I./../../../../../include
SOURCE_PATH    = .
CFLAGS         = -DHAVE_CONFIG_H  -D__LINUX__
LIBLINK        = -lpthread -lz -llzo


# --- 2.- Perfil de la libreria -------

LIB_PATH  = ../../../../../lib/
LIBNAME   = libmpi.a
OBJETOS   = \
            $(SOURCE_PATH)/barrier.o



 
#--------------------------
# Reglas de compilacion ...
#-------------------------- 

all:    init    barrier
refast: clean   barrier
fast:   barrier

barrier: $(OBJETOS)
	@echo "   Building barrier :"
	@echo "     barrier.linux.xmp ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o barrier.linux.xmp $(OBJETOS) $(LIB_PATH)/$(LIBNAME) $(LIBLINK)


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    barrier" 
	@echo "   ---------"
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
	@rm -fr $(OBJETOS)  ./barrier.linux.xmp
	@echo "   Trash succesfully removed !."




# ---------------------- barrier' MAKEFILE -------------------- 

