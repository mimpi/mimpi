# Generated automatically from Makefile.in by configure.
# ------------------------------ MAKEFILE -----------------------
 


# --- 1.- Operating system options ---

CC             = gcc
MAKE           = gmake
LIB_PATH       = ../../../../lib
INCLUDE_PATH   = -I./ -I../../../../src/ -I../../../../include
SOURCE_PATH    = .
CFLAGS         = -DHAVE_CONFIG_H  -D__LINUX__
LIBLINK        = -lmpi -lpthread -lz -llzo



# --- 2.- Libraries profiles -------

TEST_OBJ  = \
            $(SOURCE_PATH)/x_string.o \
            $(SOURCE_PATH)/x_dtd.o

 

# --- 3.- Compilation rules -------

all:    init  $(TEST_OBJ)  test
fast:         $(TEST_OBJ)  test


init:
	@echo "" 
	@echo "    test" 
	@echo "   ------" 
	@echo "" 
	@echo "   Options   :"
	@echo "     "$(CFLAGS)
	@echo "   Directory :"
	@echo "     "$(INCLUDE_PATH)
	@echo "   Compiling :"

%.o: %.c
	@echo "     $< ..." 
	@$(CC)  $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@ 

test:
	@echo "   Building test :"
	@echo "     x_string.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o ./x_string.exe x_string.o  $(LIBLINK)
	@echo "     x_dtd.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o ./x_dtd.exe x_dtd.o  $(LIBLINK)

clean: 
	@echo "   Removing trash..."
	@rm -fr $(TEST_OBJ) 
	@rm -fr ./x_string.exe
	@rm -fr ./x_dtd.exe
	@echo "   Trash succesfully removed !."



# ------------------------------ MAKEFILE -----------------------

