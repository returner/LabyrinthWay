# Microsoft Developer Studio Generated NMAKE File, Based on MapEditor.dsp
!IF "$(CFG)" == ""
CFG=MapEditor - Win32 Debug
!MESSAGE No configuration specified. Defaulting to MapEditor - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "MapEditor - Win32 Release" && "$(CFG)" != "MapEditor - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MapEditor.mak" CFG="MapEditor - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MapEditor - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MapEditor - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MapEditor - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\MapEditor.exe"


CLEAN :
	-@erase "$(INTDIR)\CDIB.OBJ"
	-@erase "$(INTDIR)\CellData.obj"
	-@erase "$(INTDIR)\CutDlg.obj"
	-@erase "$(INTDIR)\InformationDlg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MapEditor.obj"
	-@erase "$(INTDIR)\MapEditor.pch"
	-@erase "$(INTDIR)\MapEditor.res"
	-@erase "$(INTDIR)\MapEditorDoc.obj"
	-@erase "$(INTDIR)\MapEditorView.obj"
	-@erase "$(INTDIR)\Position.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MapEditor.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\MapEditor.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x412 /fo"$(INTDIR)\MapEditor.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MapEditor.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\MapEditor.pdb" /machine:I386 /out:"$(OUTDIR)\MapEditor.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CDIB.OBJ" \
	"$(INTDIR)\CellData.obj" \
	"$(INTDIR)\CutDlg.obj" \
	"$(INTDIR)\InformationDlg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MapEditor.obj" \
	"$(INTDIR)\MapEditorDoc.obj" \
	"$(INTDIR)\MapEditorView.obj" \
	"$(INTDIR)\Position.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\MapEditor.res"

"$(OUTDIR)\MapEditor.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MapEditor - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\MapEditor.exe" "$(OUTDIR)\MapEditor.bsc"


CLEAN :
	-@erase "$(INTDIR)\CDIB.OBJ"
	-@erase "$(INTDIR)\CDIB.SBR"
	-@erase "$(INTDIR)\CellData.obj"
	-@erase "$(INTDIR)\CellData.sbr"
	-@erase "$(INTDIR)\CutDlg.obj"
	-@erase "$(INTDIR)\CutDlg.sbr"
	-@erase "$(INTDIR)\InformationDlg.obj"
	-@erase "$(INTDIR)\InformationDlg.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MapEditor.obj"
	-@erase "$(INTDIR)\MapEditor.pch"
	-@erase "$(INTDIR)\MapEditor.res"
	-@erase "$(INTDIR)\MapEditor.sbr"
	-@erase "$(INTDIR)\MapEditorDoc.obj"
	-@erase "$(INTDIR)\MapEditorDoc.sbr"
	-@erase "$(INTDIR)\MapEditorView.obj"
	-@erase "$(INTDIR)\MapEditorView.sbr"
	-@erase "$(INTDIR)\Position.obj"
	-@erase "$(INTDIR)\Position.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\MapEditor.bsc"
	-@erase "$(OUTDIR)\MapEditor.exe"
	-@erase "$(OUTDIR)\MapEditor.ilk"
	-@erase "$(OUTDIR)\MapEditor.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\MapEditor.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x412 /fo"$(INTDIR)\MapEditor.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MapEditor.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\CDIB.SBR" \
	"$(INTDIR)\CellData.sbr" \
	"$(INTDIR)\CutDlg.sbr" \
	"$(INTDIR)\InformationDlg.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MapEditor.sbr" \
	"$(INTDIR)\MapEditorDoc.sbr" \
	"$(INTDIR)\MapEditorView.sbr" \
	"$(INTDIR)\Position.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\MapEditor.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\MapEditor.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MapEditor.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\CDIB.OBJ" \
	"$(INTDIR)\CellData.obj" \
	"$(INTDIR)\CutDlg.obj" \
	"$(INTDIR)\InformationDlg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MapEditor.obj" \
	"$(INTDIR)\MapEditorDoc.obj" \
	"$(INTDIR)\MapEditorView.obj" \
	"$(INTDIR)\Position.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\MapEditor.res"

"$(OUTDIR)\MapEditor.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("MapEditor.dep")
!INCLUDE "MapEditor.dep"
!ELSE 
!MESSAGE Warning: cannot find "MapEditor.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "MapEditor - Win32 Release" || "$(CFG)" == "MapEditor - Win32 Debug"
SOURCE=.\CDIB.CPP

!IF  "$(CFG)" == "MapEditor - Win32 Release"


"$(INTDIR)\CDIB.OBJ" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ELSEIF  "$(CFG)" == "MapEditor - Win32 Debug"


"$(INTDIR)\CDIB.OBJ"	"$(INTDIR)\CDIB.SBR" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ENDIF 

SOURCE=.\CellData.cpp

!IF  "$(CFG)" == "MapEditor - Win32 Release"


"$(INTDIR)\CellData.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ELSEIF  "$(CFG)" == "MapEditor - Win32 Debug"


"$(INTDIR)\CellData.obj"	"$(INTDIR)\CellData.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ENDIF 

SOURCE=.\CutDlg.cpp

!IF  "$(CFG)" == "MapEditor - Win32 Release"


"$(INTDIR)\CutDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ELSEIF  "$(CFG)" == "MapEditor - Win32 Debug"


"$(INTDIR)\CutDlg.obj"	"$(INTDIR)\CutDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ENDIF 

SOURCE=.\InformationDlg.cpp

!IF  "$(CFG)" == "MapEditor - Win32 Release"


"$(INTDIR)\InformationDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ELSEIF  "$(CFG)" == "MapEditor - Win32 Debug"


"$(INTDIR)\InformationDlg.obj"	"$(INTDIR)\InformationDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "MapEditor - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ELSEIF  "$(CFG)" == "MapEditor - Win32 Debug"


"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ENDIF 

SOURCE=.\MapEditor.cpp

!IF  "$(CFG)" == "MapEditor - Win32 Release"


"$(INTDIR)\MapEditor.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ELSEIF  "$(CFG)" == "MapEditor - Win32 Debug"


"$(INTDIR)\MapEditor.obj"	"$(INTDIR)\MapEditor.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ENDIF 

SOURCE=.\MapEditorDoc.cpp

!IF  "$(CFG)" == "MapEditor - Win32 Release"


"$(INTDIR)\MapEditorDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ELSEIF  "$(CFG)" == "MapEditor - Win32 Debug"


"$(INTDIR)\MapEditorDoc.obj"	"$(INTDIR)\MapEditorDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ENDIF 

SOURCE=.\MapEditorView.cpp

!IF  "$(CFG)" == "MapEditor - Win32 Release"


"$(INTDIR)\MapEditorView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ELSEIF  "$(CFG)" == "MapEditor - Win32 Debug"


"$(INTDIR)\MapEditorView.obj"	"$(INTDIR)\MapEditorView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ENDIF 

SOURCE=.\Position.cpp

!IF  "$(CFG)" == "MapEditor - Win32 Release"


"$(INTDIR)\Position.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ELSEIF  "$(CFG)" == "MapEditor - Win32 Debug"


"$(INTDIR)\Position.obj"	"$(INTDIR)\Position.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MapEditor.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "MapEditor - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\MapEditor.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MapEditor.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MapEditor - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\MapEditor.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\MapEditor.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\MapEditor.rc

"$(INTDIR)\MapEditor.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

