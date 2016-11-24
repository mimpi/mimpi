# Generated automatically from Makefile.in by configure.
# ------------------------------ MAKEFILE -----------------------
 


# --- 1.- Operating system options ---

CC             = gcc
MAKE           = gmake
LIB_PATH       = ../../../../lib
INCLUDE_PATH   = -I./ -I../../../../src/ -I../../../../include
SOURCE_PATH    = .
CFLAGS         = -O2 -Wall -DHAVE_CONFIG_H  -D__LINUX__
LIBLINK        = -lmpi -lpthread -lz -llzo



# --- 2.- Libraries profiles -------

TEST_OBJ  = \
            $(SOURCE_PATH)/l_buffa.o    \
            $(SOURCE_PATH)/l_dhash.o    \
            $(SOURCE_PATH)/l_dstack.o


 

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
	@echo "     l_buffa.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o ./l_buffa.exe l_buffa.o  $(LIBLINK)
	@echo "     l_dhash.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o ./l_dhash.exe l_dhash.o  $(LIBLINK)
	@echo "     l_dstack.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o ./l_dstack.exe l_dstack.o  $(LIBLINK)

clean: 
	@echo "   Removing trash..."
	@rm -fr $(TEST_OBJ) 
	@rm -fr ./l_buffa.exe
	@rm -fr ./l_dhash.exe
	@rm -fr ./l_dstack.exe
	@echo "   Trash succesfully removed !."



# ------------------------------ MAKEFILE -----------------------

