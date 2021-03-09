# Microsoft Developer Studio Generated NMAKE File, Based on LabyrinthWay.dsp
!IF "$(CFG)" == ""
CFG=LabyrinthWay - Win32 Debug
!MESSAGE No configuration specified. Defaulting to LabyrinthWay - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "LabyrinthWay - Win32 Release" && "$(CFG)" != "LabyrinthWay - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "LabyrinthWay.mak" CFG="LabyrinthWay - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LabyrinthWay - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "LabyrinthWay - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "LabyrinthWay - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\LabyrinthWay.exe"


CLEAN :
	-@erase "$(INTDIR)\CColor.obj"
	-@erase "$(INTDIR)\CDIB.OBJ"
	-@erase "$(INTDIR)\CutDlg.obj"
	-@erase "$(INTDIR)\HelpDialog.obj"
	-@erase "$(INTDIR)\InformationDlg.obj"
	-@erase "$(INTDIR)\Labyrinth.obj"
	-@erase "$(INTDIR)\LabyrinthWay.obj"
	-@erase "$(INTDIR)\LabyrinthWay.pch"
	-@erase "$(INTDIR)\LabyrinthWay.res"
	-@erase "$(INTDIR)\LabyrinthWayDoc.obj"
	-@erase "$(INTDIR)\LabyrinthWayView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\PointInt.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\WaitDialog.obj"
	-@erase "$(OUTDIR)\LabyrinthWay.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\LabyrinthWay.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x412 /fo"$(INTDIR)\LabyrinthWay.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\LabyrinthWay.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\LabyrinthWay.pdb" /machine:I386 /out:"$(OUTDIR)\LabyrinthWay.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CColor.obj" \
	"$(INTDIR)\CDIB.OBJ" \
	"$(INTDIR)\CutDlg.obj" \
	"$(INTDIR)\InformationDlg.obj" \
	"$(INTDIR)\Labyrinth.obj" \
	"$(INTDIR)\LabyrinthWay.obj" \
	"$(INTDIR)\LabyrinthWayDoc.obj" \
	"$(INTDIR)\LabyrinthWayView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\PointInt.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WaitDialog.obj" \
	"$(INTDIR)\LabyrinthWay.res" \
	"$(INTDIR)\HelpDialog.obj"

"$(OUTDIR)\LabyrinthWay.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "LabyrinthWay - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\LabyrinthWay.exe" "$(OUTDIR)\LabyrinthWay.bsc"


CLEAN :
	-@erase "$(INTDIR)\CColor.obj"
	-@erase "$(INTDIR)\CColor.sbr"
	-@erase "$(INTDIR)\CDIB.OBJ"
	-@erase "$(INTDIR)\CDIB.SBR"
	-@erase "$(INTDIR)\CutDlg.obj"
	-@erase "$(INTDIR)\CutDlg.sbr"
	-@erase "$(INTDIR)\HelpDialog.obj"
	-@erase "$(INTDIR)\HelpDialog.sbr"
	-@erase "$(INTDIR)\InformationDlg.obj"
	-@erase "$(INTDIR)\InformationDlg.sbr"
	-@erase "$(INTDIR)\Labyrinth.obj"
	-@erase "$(INTDIR)\Labyrinth.sbr"
	-@erase "$(INTDIR)\LabyrinthWay.obj"
	-@erase "$(INTDIR)\LabyrinthWay.pch"
	-@erase "$(INTDIR)\LabyrinthWay.res"
	-@erase "$(INTDIR)\LabyrinthWay.sbr"
	-@erase "$(INTDIR)\LabyrinthWayDoc.obj"
	-@erase "$(INTDIR)\LabyrinthWayDoc.sbr"
	-@erase "$(INTDIR)\LabyrinthWayView.obj"
	-@erase "$(INTDIR)\LabyrinthWayView.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\PointInt.obj"
	-@erase "$(INTDIR)\PointInt.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WaitDialog.obj"
	-@erase "$(INTDIR)\WaitDialog.sbr"
	-@erase "$(OUTDIR)\LabyrinthWay.bsc"
	-@erase "$(OUTDIR)\LabyrinthWay.exe"
	-@erase "$(OUTDIR)\LabyrinthWay.ilk"
	-@erase "$(OUTDIR)\LabyrinthWay.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\LabyrinthWay.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x412 /fo"$(INTDIR)\LabyrinthWay.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\LabyrinthWay.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\CColor.sbr" \
	"$(INTDIR)\CDIB.SBR" \
	"$(INTDIR)\CutDlg.sbr" \
	"$(INTDIR)\InformationDlg.sbr" \
	"$(INTDIR)\Labyrinth.sbr" \
	"$(INTDIR)\LabyrinthWay.sbr" \
	"$(INTDIR)\LabyrinthWayDoc.sbr" \
	"$(INTDIR)\LabyrinthWayView.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\PointInt.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\WaitDialog.sbr" \
	"$(INTDIR)\HelpDialog.sbr"

"$(OUTDIR)\LabyrinthWay.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\LabyrinthWay.pdb" /debug /machine:I386 /out:"$(OUTDIR)\LabyrinthWay.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\CColor.obj" \
	"$(INTDIR)\CDIB.OBJ" \
	"$(INTDIR)\CutDlg.obj" \
	"$(INTDIR)\InformationDlg.obj" \
	"$(INTDIR)\Labyrinth.obj" \
	"$(INTDIR)\LabyrinthWay.obj" \
	"$(INTDIR)\LabyrinthWayDoc.obj" \
	"$(INTDIR)\LabyrinthWayView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\PointInt.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WaitDialog.obj" \
	"$(INTDIR)\LabyrinthWay.res" \
	"$(INTDIR)\HelpDialog.obj"

"$(OUTDIR)\LabyrinthWay.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("LabyrinthWay.dep")
!INCLUDE "LabyrinthWay.dep"
!ELSE 
!MESSAGE Warning: cannot find "LabyrinthWay.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "LabyrinthWay - Win32 Release" || "$(CFG)" == "LabyrinthWay - Win32 Debug"
SOURCE=.\CColor.cpp

!IF  "$(CFG)" == "LabyrinthWay - Win32 Release"


"$(INTDIR)\CColor.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ELSEIF  "$(CFG)" == "LabyrinthWay - Win32 Debug"


"$(INTDIR)\CColor.obj"	"$(INTDIR)\CColor.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ENDIF 

SOURCE=.\CDIB.CPP

!IF  "$(CFG)" == "LabyrinthWay - Win32 Release"


"$(INTDIR)\CDIB.OBJ" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ELSEIF  "$(CFG)" == "LabyrinthWay - Win32 Debug"


"$(INTDIR)\CDIB.OBJ"	"$(INTDIR)\CDIB.SBR" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ENDIF 

SOURCE=.\CutDlg.cpp

!IF  "$(CFG)" == "LabyrinthWay - Win32 Release"


"$(INTDIR)\CutDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ELSEIF  "$(CFG)" == "LabyrinthWay - Win32 Debug"


"$(INTDIR)\CutDlg.obj"	"$(INTDIR)\CutDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ENDIF 

SOURCE=.\HelpDialog.cpp

!IF  "$(CFG)" == "LabyrinthWay - Win32 Release"


"$(INTDIR)\HelpDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ELSEIF  "$(CFG)" == "LabyrinthWay - Win32 Debug"


"$(INTDIR)\HelpDialog.obj"	"$(INTDIR)\HelpDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ENDIF 

SOURCE=.\InformationDlg.cpp

!IF  "$(CFG)" == "LabyrinthWay - Win32 Release"


"$(INTDIR)\InformationDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ELSEIF  "$(CFG)" == "LabyrinthWay - Win32 Debug"


"$(INTDIR)\InformationDlg.obj"	"$(INTDIR)\InformationDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ENDIF 

SOURCE=.\Labyrinth.cpp

!IF  "$(CFG)" == "LabyrinthWay - Win32 Release"


"$(INTDIR)\Labyrinth.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ELSEIF  "$(CFG)" == "LabyrinthWay - Win32 Debug"


"$(INTDIR)\Labyrinth.obj"	"$(INTDIR)\Labyrinth.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ENDIF 

SOURCE=.\LabyrinthWay.cpp

!IF  "$(CFG)" == "LabyrinthWay - Win32 Release"


"$(INTDIR)\LabyrinthWay.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ELSEIF  "$(CFG)" == "LabyrinthWay - Win32 Debug"


"$(INTDIR)\LabyrinthWay.obj"	"$(INTDIR)\LabyrinthWay.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ENDIF 

SOURCE=.\LabyrinthWay.rc

"$(INTDIR)\LabyrinthWay.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\LabyrinthWayDoc.cpp

!IF  "$(CFG)" == "LabyrinthWay - Win32 Release"


"$(INTDIR)\LabyrinthWayDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ELSEIF  "$(CFG)" == "LabyrinthWay - Win32 Debug"


"$(INTDIR)\LabyrinthWayDoc.obj"	"$(INTDIR)\LabyrinthWayDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ENDIF 

SOURCE=.\LabyrinthWayView.cpp

!IF  "$(CFG)" == "LabyrinthWay - Win32 Release"


"$(INTDIR)\LabyrinthWayView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ELSEIF  "$(CFG)" == "LabyrinthWay - Win32 Debug"


"$(INTDIR)\LabyrinthWayView.obj"	"$(INTDIR)\LabyrinthWayView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "LabyrinthWay - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ELSEIF  "$(CFG)" == "LabyrinthWay - Win32 Debug"


"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ENDIF 

SOURCE=.\PointInt.cpp

!IF  "$(CFG)" == "LabyrinthWay - Win32 Release"


"$(INTDIR)\PointInt.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ELSEIF  "$(CFG)" == "LabyrinthWay - Win32 Debug"


"$(INTDIR)\PointInt.obj"	"$(INTDIR)\PointInt.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "LabyrinthWay - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\LabyrinthWay.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\LabyrinthWay.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "LabyrinthWay - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\LabyrinthWay.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\LabyrinthWay.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\WaitDialog.cpp

!IF  "$(CFG)" == "LabyrinthWay - Win32 Release"


"$(INTDIR)\WaitDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ELSEIF  "$(CFG)" == "LabyrinthWay - Win32 Debug"


"$(INTDIR)\WaitDialog.obj"	"$(INTDIR)\WaitDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LabyrinthWay.pch"


!ENDIF 


!ENDIF 

