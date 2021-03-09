<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: Test - Win32 (WCE ARM) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x409 /fo"ARMRel/Test.res" /d UNDER_CE=300 /d _WIN32_WCE=300 /d "UNICODE" /d "_UNICODE" /d "NDEBUG" /d "WIN32_PLATFORM_PSPC" /d "ARM" /d "_ARM_" /d "_AFXDLL" /r "C:\프로젝트\게임\미니골프2\Test\Test.rc"" 
Creating temporary file "C:\DOCUME~1\returner\LOCALS~1\Temp\RSP57.tmp" with contents
[
/nologo /W3 /D "ARM" /D "_ARM_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC" /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /D "_AFXDLL" /Fp"ARMRel/Test.pch" /Yu"stdafx.h" /Fo"ARMRel/" /Oxs /MC /c 
"C:\프로젝트\게임\미니골프2\Test\Labyrinth.cpp"
"C:\프로젝트\게임\미니골프2\Test\Test.cpp"
"C:\프로젝트\게임\미니골프2\Test\TestDlg.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\returner\LOCALS~1\Temp\RSP57.tmp" 
Creating temporary file "C:\DOCUME~1\returner\LOCALS~1\Temp\RSP58.tmp" with contents
[
/nologo /W3 /D "ARM" /D "_ARM_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC" /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /D "_AFXDLL" /Fp"ARMRel/Test.pch" /Yc"stdafx.h" /Fo"ARMRel/" /Oxs /MC /c 
"C:\프로젝트\게임\미니골프2\Test\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\returner\LOCALS~1\Temp\RSP58.tmp" 
Creating temporary file "C:\DOCUME~1\returner\LOCALS~1\Temp\RSP59.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:no /pdb:"ARMRel/Test.pdb" /out:"ARMRel/Test.exe" /subsystem:windowsce,3.00 /align:"4096" /MACHINE:ARM 
".\ARMRel\Labyrinth.obj"
".\ARMRel\StdAfx.obj"
".\ARMRel\Test.obj"
".\ARMRel\TestDlg.obj"
".\ARMRel\Test.res"
]
Creating command line "link.exe @C:\DOCUME~1\returner\LOCALS~1\Temp\RSP59.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
Labyrinth.cpp
Test.cpp
TestDlg.cpp
Generating Code...
Linking...



<h3>Results</h3>
Test.exe - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
