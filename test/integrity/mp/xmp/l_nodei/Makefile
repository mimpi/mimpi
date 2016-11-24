# Generated automatically from Makefile.in by configure.
#----------------------------- MAKEFILE -------------------- 
 


# --- 1.- Operating system options ---

CC             = gcc
LIB_PATH       = ../../../../../lib
INCLUDE_PATH   = -I./ -I./../../../../../src/ -I./../../../../../include/
SOURCE_PATH    = .
CFLAGS         = -DHAVE_CONFIG_H  -D__LINUX__
LIBLINK        = -lmpi -lpthread -lz -llzo


# --- 2.- Libraries profiles -------

OBJETOS   = \
            $(SOURCE_PATH)/l_nodei_m.o \
            $(SOURCE_PATH)/l_nodei_w.o


# --- 3.- Compilation rules -------

all:    init    nodei
refast: clean   nodei
fast:   nodei

nodei: $(OBJETOS)
	@echo "   Building :"
	@echo "     l_nodei_m.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o l_nodei_m.exe l_nodei_m.o  $(LIBLINK)
	@echo "     l_nodei_w.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o l_nodei_w.exe l_nodei_w.o  $(LIBLINK)


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    test" 
	@echo "   ------"
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
	@rm -fr ./l_nodei_m.exe
	@rm -fr ./l_nodei_w.exe
	@echo "   Trash succesfully removed !."




# ----------------------------- MAKEFILE -------------------- 

