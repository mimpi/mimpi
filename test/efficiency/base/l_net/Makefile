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
            $(SOURCE_PATH)/server.o    \
            $(SOURCE_PATH)/client.o    \
            $(SOURCE_PATH)/l_socket.o

 

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
	@echo "     server.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o ./server.exe server.o  $(LIBLINK)
	@echo "     client.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o ./client.exe client.o  $(LIBLINK)
	@echo "     l_socket.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o ./l_socket.exe l_socket.o  $(LIBLINK)

clean: 
	@echo "   Removing trash..."
	@rm -fr $(TEST_OBJ) 
	@rm -fr ./server.exe
	@rm -fr ./client.exe
	@rm -fr ./l_socket.exe
	@echo "   Trash succesfully removed !."



# ------------------------------ MAKEFILE -----------------------

