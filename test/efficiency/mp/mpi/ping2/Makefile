# Generated automatically from Makefile.in by configure.
#---------------------- ping2' MAKEFILE -------------------- 
 



# --- 1.- Opciones del sistema base ---

CC             = gcc
LIB_PATH       = ../../../../../lib
INCLUDE_PATH   = -I./ -I./../../../../../src/ -I./../../../../../include/
SOURCE_PATH    = .
CFLAGS         = -DHAVE_CONFIG_H  -D__LINUX__
LIBLINK        = -lmpi -lpthread -lz -llzo


# --- 2.- Perfil de la libreria -------

OBJETOS   = \
            $(SOURCE_PATH)/ping2.o



 
#--------------------------
# Reglas de compilacion ...
#-------------------------- 

all:    init    ping2
refast: clean   ping2
fast:   ping2

ping2: $(OBJETOS)
	@echo "   Building ping2 :"
	@echo "     ping2 ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o ping2 $(OBJETOS)  $(LIBLINK)


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    ping2  " 
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
	@rm -fr $(OBJETOS) ./ping2
	@echo "   Trash succesfully removed !."




# ---------------------- ping2' MAKEFILE -------------------- 

