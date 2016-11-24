# Generated automatically from Makefile.in by configure.
# ........................................................................
#
#  fgarcia,acaldero@hinojo.datsi.fi.upm.es
#
# ........................................................................



#--------------------------
# 1.- Native configuration
#--------------------------

MAKE          = gmake
SRCDIR        = .
DIR           = lzo  lzrw3


#--------------------------
# 2.- library object
#--------------------------



#--------------------------
# 3.- compilation rules
#--------------------------

all:     init  object
fast:          object


init:
	@echo [2J
	@echo "[1;1f"
	@echo "" 
	@echo "    EXTERNAL sources" 
	@echo "   ------------------"
	@echo "" 

object:
	@set -e;  for i in $(DIR);   do $(MAKE) -C $$i -f Makefile       fast ;  done

clean: 
	@echo "   Removing trash..."
	@set -e;  for i in $(DIR);   do $(MAKE) -C $$i -f Makefile       clean ;  done
	@echo "   Trash succesfully removed !."



# ---------------------------------------------------------------

