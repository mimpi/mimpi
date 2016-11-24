# Generated automatically from Makefile.in by configure.
#---------------------- lock' MAKEFILE -------------------- 
 



# --- 1.- Opciones del sistema base ---

CC             = gcc
LIB_PATH       = ./../../../../lib
INCLUDE_PATH   = -I./ -I./../../../src/ -I./../../../include
SOURCE_PATH    =   .
CFLAGS         = -DHAVE_CONFIG_H  -D__LINUX__
LIBLINK        = -lmpi -lpthread -lz -llzo


# --- 2.- Perfil de la libreria -------

OBJETOS   = \
            $(SOURCE_PATH)/lock.o



 
#--------------------------
# Reglas de compilacion ...
#-------------------------- 

all:    init    lock
refast: clean   lock
fast:   lock

lock: $(OBJETOS)
	@echo "   Building lock :"
	@echo "     lock.linux ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o lock.linux $(OBJETOS) $(LIBLINK)


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    lock" 
	@echo "   -----"
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
	@rm -fr $(OBJETOS)  ./lock.linux
	@echo "   Trash succesfully removed !."




# ---------------------- lock' MAKEFILE -------------------- 

