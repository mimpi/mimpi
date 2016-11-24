# Generated automatically from Makefile.in by configure.
#---------------------- test_reduce' MAKEFILE -------------------- 
 



# --- 1.- Opciones del sistema base ---

CC             = gcc
INCLUDE_PATH   = -I./ -I./../../ -I./../../include
SOURCE_PATH    = .
CFLAGS         = -DHAVE_CONFIG_H  -D__LINUX__
LIB_PATH       = -L../../lib -L/usr/lib32 -L/usr/lib
LIBLINK        = -lmpi -lpthread -lz -llzo




# --- 2.- Perfil de la libreria -------

OBJETOS_REDUCE    = \
            $(SOURCE_PATH)/test_reduce.o

EXE_NAME       = \
            test_reduce.exe
EXE_PATH       = \
            $(SOURCE_PATH)/../../bin/


 
#--------------------------
# Reglas de compilacion ...
#-------------------------- 

all:     init   test_reduce 
refast:  clean  test_reduce
fast:           test_reduce

test_reduce: $(OBJETOS_REDUCE)
	@echo "   Building test_reduce ..."
	@$(CC)  $(CFLAGS) $(LIB_PATH) -o $(EXE_PATH)/$(EXE_NAME)  $(OBJETOS_REDUCE) $(LIBLINK)


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    test_reduce" 
	@echo "   -------------"
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
	@rm -fr $(OBJETOS_REDUCE) $(EXE_PATH)/$(EXE_NAME)
	@echo "   Trash succesfully removed !."




# ---------------------- test_reduce' MAKEFILE -------------------- 

