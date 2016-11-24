# Generated automatically from Makefile.in by configure.
# ------------------------------ MAKEFILE ----------------------- 



# --- 1.- Operating system options ---

MAKE          = gmake
SRCDIR        = .
DIR           = l_adt l_alloc l_debug l_string l_time


# --- 2.- Libraries profiles -------



# --- 3.- Compilation rules -------

all:    init  compo
fast:         compo


init:
	@echo [2J 
	@echo "[1;1f" 
	@echo "" 
	@echo "    tests" 
	@echo "   -------" 
	@echo "" 

compo:
	@set -e;  for i in $(DIR);   do $(MAKE) -C $$i -f Makefile       fast ;  done



clean: 
	@echo "   Removing trash..."
	@set -e;  for i in $(DIR);   do $(MAKE) -C $$i -f Makefile       clean ;  done
	@echo "   Trash succesfully removed !."



# ----------------------------- END MAKEFILE -------------------- 

