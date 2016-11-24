# Generated automatically from Makefile.in by configure.
# ------------------------------ MAKEFILE -----------------------
 


# --- 1.- Operating system options ---

CC             = gcc
MAKE           = gmake
LIB_PATH       = ../../../lib
INCLUDE_PATH   = -I./ -I../../../src/ -I../../../include
SOURCE_PATH    = .
CFLAGS         = -DHAVE_CONFIG_H  -D__LINUX__
LIBLINK        = -lmpi -lpthread -lz -llzo



# --- 2.- Libraries profiles -------

TEST_OBJ  = \
            $(SOURCE_PATH)/l_condition_msg.o

 

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
	@echo "     l_condition_msg.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o l_condition_msg.exe l_condition_msg.o  $(LIBLINK)

clean: 
	@echo "   Removing trash..."
	@rm -fr $(TEST_OBJ) 
	@rm -fr ./l_condition_msg.exe
	@echo "   Trash succesfully removed !."



# ------------------------------ MAKEFILE -----------------------

