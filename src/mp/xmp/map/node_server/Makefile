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
INCLUDE_PATH   = -I./ -I../../../.. -I../../../../../include
SOURCE_PATH    = ./
CFLAGS         = -O2 -Wall -DHAVE_CONFIG_H  -D__LINUX__
LIBLINK        = -lmpi -lpthread -lz -llzo


#--------------------------
# 2.- library object
#--------------------------

OBJETOS   = \
            $(SOURCE_PATH)/l_ns/l_node/l_do_creat.o            \
            $(SOURCE_PATH)/l_ns/l_node/l_do_default.o          \
            $(SOURCE_PATH)/l_ns/l_node/l_do_disc.o             \
            $(SOURCE_PATH)/l_ns/l_node/l_do_match.o            \
            $(SOURCE_PATH)/l_ns/l_node/l_do_open.o             \
            $(SOURCE_PATH)/l_ns/l_node/l_do_unlink.o           \
            $(SOURCE_PATH)/l_ns/l_node/l_go_debug.o            \
            $(SOURCE_PATH)/l_ns/l_brow/l_authors.o             \
            $(SOURCE_PATH)/l_ns/l_brow/l_dump_all.o            \
            $(SOURCE_PATH)/l_ns/l_brow/l_root.o                \
            $(SOURCE_PATH)/l_ns/l_brow/l_trace_all.o           \
            $(SOURCE_PATH)/l_ns/l_brow/l_unknow.o              \
            $(SOURCE_PATH)/l_ns/l_ns_params.o                  \
            $(SOURCE_PATH)/l_ns/l_ns_params/l_ns_params_sb.o   \
            $(SOURCE_PATH)/l_ns/l_nodeli.o                     \
            $(SOURCE_PATH)/l_ns/l_brow.o                       \
            $(SOURCE_PATH)/l_ns/l_node.o                       \
            $(SOURCE_PATH)/l_nsi.o                             \
            $(SOURCE_PATH)/l_ns.o                              \
            $(SOURCE_PATH)/ns.o


#--------------------------
# 3.- compilation rules
#--------------------------

all:    init  $(OBJETOS)
fast:         $(OBJETOS)


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    node_server" 
	@echo "   -------------" 
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
	@echo "   Removing trash..."
	@rm -fr $(OBJETOS) 
	@echo "   Trash succesfully removed !."


# ........................................................................

