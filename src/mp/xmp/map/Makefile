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
DIR           = node  node_server


#--------------------------
# 2.- library object
#--------------------------



#--------------------------
# 3.- compilation rules
#--------------------------

all:    init  compo
fast:         compo 


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    xmp_tcp" 
	@echo "   ---------"
	@echo "" 

compo:
	@set -e;  for i in $(DIR);   do $(MAKE) -C $$i -f Makefile       fast;  done



clean: 
	@echo "   Removing trash..."
	@rm -fr `find $(SRCDIR) -name "*.o" -print`
	@rm -fr `find $(SRCDIR) -name "*.a" -print`
	@rm -fr `find $(SRCDIR) -name "*.exe" -print`
	@echo "   Trash succesfully removed !."


# ........................................................................

