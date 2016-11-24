# Microsoft Developer Studio Generated NMAKE File, Based on ping.dsp
!IF "$(CFG)" == ""
CFG=ping - Win32 Debug
!MESSAGE No configuration specified. Defaulting to ping - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "ping - Win32 Release" && "$(CFG)" != "ping - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ping.mak" CFG="ping - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ping - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "ping - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ping - Win32 Release"

OUTDIR=.\ping\Release
INTDIR=.\ping\Release

ALL : ".\ping.exe"


CLEAN :
	-@erase "$(INTDIR)\ping.obj"
	-@erase "$(INTDIR)\table.obj"
	-@erase "$(INTDIR)\timer.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase ".\ping.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "..\..\..\..\..\src" /I "..\..\..\..\..\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "HAVE_CONFIG_H" /D "HAVE_WINDOWS_H" /Fp"$(INTDIR)\ping.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ping.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Ws2_32.lib ../../../../../lib/mplib.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\ping.pdb" /machine:I386 /out:".\ping.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ping.obj" \
	"$(INTDIR)\timer.obj" \
	"$(INTDIR)\table.obj"

".\ping.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ping - Win32 Debug"

OUTDIR=.\ping\Debug
INTDIR=.\ping\Debug
# Begin Custom Macros
OutDir=.\ping\Debug
# End Custom Macros

ALL : ".\ping.exe" "$(OUTDIR)\ping.bsc"


CLEAN :
	-@erase "$(INTDIR)\ping.obj"
	-@erase "$(INTDIR)\ping.sbr"
	-@erase "$(INTDIR)\table.obj"
	-@erase "$(INTDIR)\table.sbr"
	-@erase "$(INTDIR)\timer.obj"
	-@erase "$(INTDIR)\timer.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ping.bsc"
	-@erase "$(OUTDIR)\ping.pdb"
	-@erase ".\ping.exe"
	-@erase ".\ping.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "..\..\..\..\..\src" /I "..\..\..\..\..\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "HAVE_CONFIG_H" /D "__DEBUG__" /D "HAVE_WINDOWS_H" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ping.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ping.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ping.sbr" \
	"$(INTDIR)\timer.sbr" \
	"$(INTDIR)\table.sbr"

"$(OUTDIR)\ping.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Ws2_32.lib ../../../../../lib/mplib.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\ping.pdb" /debug /machine:I386 /out:".\ping.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ping.obj" \
	"$(INTDIR)\timer.obj" \
	"$(INTDIR)\table.obj"

".\ping.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("ping.dep")
!INCLUDE "ping.dep"
!ELSE 
!MESSAGE Warning: cannot find "ping.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ping - Win32 Release" || "$(CFG)" == "ping - Win32 Debug"
SOURCE=.\ping.c

!IF  "$(CFG)" == "ping - Win32 Release"


"$(INTDIR)\ping.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ping - Win32 Debug"


"$(INTDIR)\ping.obj"	"$(INTDIR)\ping.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\table.c

!IF  "$(CFG)" == "ping - Win32 Release"


"$(INTDIR)\table.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ping - Win32 Debug"


"$(INTDIR)\table.obj"	"$(INTDIR)\table.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\timer.c

!IF  "$(CFG)" == "ping - Win32 Release"


"$(INTDIR)\timer.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ping - Win32 Debug"


"$(INTDIR)\timer.obj"	"$(INTDIR)\timer.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

