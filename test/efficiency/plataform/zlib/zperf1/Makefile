# Generated automatically from Makefile.in by configure.
# ------------------------------ MAKEFILE -----------------------
 


# --- 1.- Operating system options ---

CC             = gcc
MAKE           = gmake
LIB_PATH       = -L/usr/lib -L../../../../../lib
INCLUDE_PATH   = -I./ -I../../../../src/ -I../../../../include
SOURCE_PATH    = .
CFLAGS         = -DHAVE_CONFIG_H  -D__LINUX__
LIBLINK        = -lmpi -lpthread -lz -llzo



# --- 2.- Libraries profiles -------

TEST_OBJ  = \
            $(SOURCE_PATH)/l_time_ms.o       \
            $(SOURCE_PATH)/l_calloc_xy.o     \
            $(SOURCE_PATH)/l_ztest_x.o       \
            $(SOURCE_PATH)/zperf1.o

 

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
	@echo "     zperf1.exe ..."
	@$(CC)   $(LIB_PATH)  $(CFLAGS) -o ./zperf1.exe $(TEST_OBJ) $(LIB_PATH) $(LIBLINK)

clean: 
	@echo "   Removing trash..."
	@rm -fr $(TEST_OBJ) 
	@rm -fr ./zperf1.exe
	@echo "   Trash succesfully removed !."



# ------------------------------ MAKEFILE -----------------------

