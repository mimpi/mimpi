# Generated automatically from Makefile.in by configure.
#---------------------- test_run' MAKEFILE -------------------- 
 



# --- 1.- Opciones del sistema base ---

CC             = gcc
INCLUDE_PATH   = -I./ -I./../../ -I./../../include
SOURCE_PATH    = .
CFLAGS         = -DHAVE_CONFIG_H  -D__LINUX__
LIB_PATH       = -L../../lib -L/usr/lib32 -L/usr/lib
LIBLINK        = -lmpi -lpthread -lz -llzo




# --- 2.- Perfil de la libreria -------

OBJETOS_RUN    = \
            $(SOURCE_PATH)/test_run.o

EXE_NAME       = \
            test_run.exe
EXE_PATH       = \
            $(SOURCE_PATH)/../../bin/


 
#--------------------------
# Reglas de compilacion ...
#-------------------------- 

all:     init   test_run 
refast:  clean  test_run
fast:           test_run

test_run: $(OBJETOS_RUN)
	@echo "   Building test_run ..."
	@$(CC)  $(CFLAGS) $(LIB_PATH) -o $(EXE_PATH)/$(EXE_NAME)  $(OBJETOS_RUN) $(LIBLINK)


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    test_run" 
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
	@rm -fr $(OBJETOS_RUN) $(EXE_PATH)/$(EXE_NAME)
	@echo "   Trash succesfully removed !."




# ---------------------- test_run' MAKEFILE -------------------- 

