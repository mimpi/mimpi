# Generated automatically from Makefile.in by configure.
#---------------------- reduce' MAKEFILE -------------------- 
 



# --- 1.- Opciones del sistema base ---

CC             = gcc
LIB_PATH       = ../../../../../lib
INCLUDE_PATH   = -I./ -I./../../../../../src/ -I./../../../../../include
SOURCE_PATH    = .
CFLAGS         = -DHAVE_CONFIG_H  -D__LINUX__
LIBLINK        = -lmpi -lpthread -lz -llzo


# --- 2.- Perfil de la libreria -------

OBJETOS   = \
            $(SOURCE_PATH)/reduce.o



 
#--------------------------
# Reglas de compilacion ...
#-------------------------- 

all:    init    reduce
refast: clean   reduce
fast:   reduce

reduce: $(OBJETOS)
	@echo "   Building reduce :"
	@echo "     reduce.linux.xmp ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o reduce.linux.xmp $(OBJETOS)  $(LIBLINK)


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    reduce" 
	@echo "   --------"
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
	@rm -fr $(OBJETOS)  ./reduce.linux.xmp
	@echo "   Trash succesfully removed !."




# ---------------------- reduce' MAKEFILE -------------------- 

