# Generated automatically from Makefile.in by configure.
#---------------------- fpu' MAKEFILE -------------------- 
 



# --- 1.- Opciones del sistema base ---

CC             = gcc
LIB_PATH       = ../../../../lib
INCLUDE_PATH   = -I./ -I./../../../src/ -I./../../../include
SOURCE_PATH    =   .
CFLAGS         = -DHAVE_CONFIG_H  -D__LINUX__
LIBLINK        = -lmpi -lpthread -lz -llzo


# --- 2.- Perfil de la libreria -------

OBJETOS   = \
            $(SOURCE_PATH)/fpu.o



 
#--------------------------
# Reglas de compilacion ...
#-------------------------- 

all:    init    fpu
refast: clean   fpu
fast:   fpu

fpu: $(OBJETOS)
	@echo "   Building fpu :"
	@echo "     fpu.linux ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o fpu.linux $(OBJETOS) $(LIBLINK)


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    fpu" 
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
	@rm -fr $(OBJETOS)  ./fpu.linux
	@echo "   Trash succesfully removed !."




# ---------------------- fpu' MAKEFILE -------------------- 

