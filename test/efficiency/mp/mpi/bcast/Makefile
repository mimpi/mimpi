# Generated automatically from Makefile.in by configure.
#---------------------- bcast' MAKEFILE -------------------- 
 



# --- 1.- Opciones del sistema base ---

CC             = gcc
LIB_PATH       = ../../../../../lib
INCLUDE_PATH   = -I./ -I./../../../../../src/ -I./../../../../../include
SOURCE_PATH    = .
CFLAGS         = -DHAVE_CONFIG_H  -D__LINUX__
LIBLINK        = -lmpi -lpthread -lz -llzo


# --- 2.- Perfil de la libreria -------

OBJETOS   = \
            $(SOURCE_PATH)/bcast.o



 
#--------------------------
# Reglas de compilacion ...
#-------------------------- 

all:    init    bcast
refast: clean   bcast
fast:   bcast

bcast: $(OBJETOS)
	@echo "   Building bcast :"
	@echo "     bcast.linux.xmp ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o bcast.linux.xmp $(OBJETOS)  $(LIBLINK)


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    bcast" 
	@echo "   -------"
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
	@rm -fr $(OBJETOS)  ./bcast.linux.xmp
	@echo "   Trash succesfully removed !."




# ---------------------- bcast' MAKEFILE -------------------- 

