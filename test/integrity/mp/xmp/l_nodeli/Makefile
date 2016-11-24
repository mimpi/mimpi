# Generated automatically from Makefile.in by configure.
#---------------------- nodeli' MAKEFILE -------------------- 
 


# --- 1.- Operating system options ---

CC             = gcc
LIB_PATH       = ../../../../../lib
INCLUDE_PATH   = -I./ -I./../../../../../src/ -I./../../../../../include/
SOURCE_PATH    = .
CFLAGS         = -DHAVE_CONFIG_H  -D__LINUX__
LIBLINK        = -lmpi -lpthread -lz -llzo


# --- 2.- Libraries profiles -------

OBJETOS   = \
            $(SOURCE_PATH)/1.o   \
            $(SOURCE_PATH)/2.o   \
            $(SOURCE_PATH)/3.o   \
            $(SOURCE_PATH)/4.o


# --- 3.- Compilation rules -------

all:    init    nodeli
refast: clean   nodeli
fast:   nodeli

nodeli: $(OBJETOS)
	@echo "   Building :"
	@echo "     1.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o 1.exe 1.o  $(LIBLINK)
	@echo "     2.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o 2.exe 2.o  $(LIBLINK)
	@echo "     3.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o 3.exe 3.o  $(LIBLINK)
	@echo "     4.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o 4.exe 4.o  $(LIBLINK)


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    nodeli" 
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
	@rm -fr $(OBJETOS)
	@rm -fr ./1.exe
	@rm -fr ./2.exe
	@rm -fr ./3.exe
	@rm -fr ./4.exe
	@echo "   Trash succesfully removed !."




# ---------------------- nodeli' MAKEFILE -------------------- 

