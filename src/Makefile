# Generated automatically from Makefile.in by configure.
# ........................................................................
#
#  fgarcia,acaldero@hinojo.datsi.fi.upm.es
#
# ........................................................................



#--------------------------
# 1.- Native configuration
#--------------------------

CC            = gcc
MAKE          = gmake
SRCDIR        = .
LIB_PATH      = -L/usr/lib
LIBLINK       = -lmpi -lpthread -lz -llzo
DIR           = base  console  mp  


#--------------------------
# 2.- library object
#--------------------------

LIB_PATH  = ./../lib/
LIBNAME   = libmpi.a
NS_PATH   = ./../bin/
NSNAME    = ns.exe


#--------------------------
# 3.- compilation rules
#--------------------------

all:    init  compo  mpi.a  ns.exe
fast:         compo  mpi.a  ns.exe


ns.exe:
	@echo "   Building NameServer :"
	@echo "     ns.exe ..."
	@$(CC)  $(CFLAGS) -L$(LIB_PATH) -o $(NS_PATH)/$(NSNAME) $(LIBLINK)

mpi.a:
	@echo "   Building library :"
	@echo "     libmpi.a ..."
	@ar -rc $(LIB_PATH)/$(LIBNAME)
	@ar -rs $(LIB_PATH)/$(LIBNAME) `find base console mp -name "*.o" -print`

init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    MiMPI" 
	@echo "   -------"
	@echo "" 

compo:
	@set -e;  for i in $(DIR);   do $(MAKE) -C $$i -f Makefile       fast ;  done



clean: 
	@echo "   Removing trash..."
	@set -e;  for i in $(DIR);   do $(MAKE) -C $$i -f Makefile       clean ;  done
	@rm -fr $(NS_PATH)/$(NSNAME)
	@rm -fr $(LIB_PATH)/$(LIBNAME)
	@echo "   Trash succesfully removed !."


# ........................................................................

