# Generated automatically from Makefile.in by configure.
# ........................................................................
#
#  fgarcia,acaldero@hinojo.datsi.fi.upm.es
#
# ........................................................................



#--------------------------
# 1.- Native configuration 
#-------------------------- 

CC             = gcc
LIB_PATH       = -L/usr/lib
INCLUDE_PATH   = -I./ -I.. -I../../include
SOURCE_PATH    = ./
CFLAGS         = -O2 -Wall -DHAVE_CONFIG_H -D__LINUX__
LIBLINK        = -lmpi -lpthread -lz -llzo


#--------------------------
# 2.- library object
#-------------------------- 

OBJETOS   = \
            $(SOURCE_PATH)/l_debug/l_debug.o                     \
            $(SOURCE_PATH)/l_debug/l_debug_msg.o                 \
            $(SOURCE_PATH)/l_debug/l_debug_dfa.o                 \
            \
            $(SOURCE_PATH)/l_alloc/l_alloc.o                     \
            $(SOURCE_PATH)/l_alloc/v_alloc.o                     \
            $(SOURCE_PATH)/l_alloc/x_alloc.o                     \
            \
            $(SOURCE_PATH)/l_string/l_string.o                   \
            $(SOURCE_PATH)/l_string/x_string.o                   \
            $(SOURCE_PATH)/l_string/v_dtd.o                      \
            $(SOURCE_PATH)/l_string/x_dtd.o                      \
            \
            $(SOURCE_PATH)/l_socket/v_socket.o                   \
            $(SOURCE_PATH)/l_socket/x_socket.o                   \
            \
            $(SOURCE_PATH)/l_thread/v_thread.o                   \
            $(SOURCE_PATH)/l_thread/l_thread_pool.o              \
            $(SOURCE_PATH)/l_thread/v_thread_pool.o              \
            $(SOURCE_PATH)/l_thread/x_thread.o                   \
            \
            $(SOURCE_PATH)/l_process/v_process.o                 \
            $(SOURCE_PATH)/l_process/x_process.o                 \
            \
            $(SOURCE_PATH)/l_zlib/v_zl.o                         \
            $(SOURCE_PATH)/l_zlib/x_zl.o                         \
            \
            $(SOURCE_PATH)/l_time/l_time.o                       \
            $(SOURCE_PATH)/l_time/x_time.o                       \
            \
            $(SOURCE_PATH)/l_adt/l_darray.o                      \
            $(SOURCE_PATH)/l_adt/l_buffa.o                       \
            $(SOURCE_PATH)/l_adt/l_dstack.o                      \
            $(SOURCE_PATH)/l_adt/l_dhash.o                       \
            \
            $(SOURCE_PATH)/l_file/v_file.o                       \
            $(SOURCE_PATH)/l_file/x_file.o


 
#--------------------------
# 3.- compilation rules
#-------------------------- 

all:    init  $(OBJETOS)
fast:         $(OBJETOS)


init:
	@echo "" 
	@echo "    base" 
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


clean: 
	@echo "   Removing object files..."
	@rm -fr $(OBJETOS) 
	@echo "   Object files succesfully removed !."


# ........................................................................

