# Generated automatically from Makefile.in by configure.
#---------------------- scatter' MAKEFILE -------------------- 
 



# --- 1.- Opciones del sistema base ---

#-----------------------
# Constantes en LINUX
#-----------------------
 
CC             = gcc
LIB_PATH       = ../../../../../lib
INCLUDE_PATH   = -I./ -I./../../../../../src/ -I./../../../../../include
SOURCE_PATH    =   .
CFLAGS         = -DHAVE_CONFIG_H  -D__LINUX__ -D_REENTRANT -DPOSIX_THREADS
LIBLINK        = -lmpi -lpthread -lz -llzo


# --- 2.- Perfil de la libreria -------

OBJETOS   = \
            $(SOURCE_PATH)/scatter.o



 
#--------------------------
# Reglas de compilacion ...
#-------------------------- 

all:    init    scatter
refast: clean   scatter
fast:   scatter

scatter: $(OBJETOS)
	@echo "   Building scatter :"
	@echo "     scatter.linux.xmp ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o scatter.linux.xmp $(OBJETOS)  $(LIBLINK)


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    scatter" 
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
	@rm -fr $(OBJETOS)  ./scatter.linux.xmp
	@echo "   Trash succesfully removed !."




# ---------------------- scatter' MAKEFILE -------------------- 

