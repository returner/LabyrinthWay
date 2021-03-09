<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: SampleParser - Win32 (WCE x86em) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\returner\LOCALS~1\Temp\RSP9.tmp" with contents
[
/nologo /W3 /Zi /D "i486" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32" /D "STRICT" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "WIN32_PLATFORM_PSPC" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "NDEBUG" /D "_AFXDLL" /Fp"X86EMRel/SampleParser.pch" /Yu"stdafx.h" /Fo"X86EMRel/" /Fd"X86EMRel/" /Gz /Oxs /c 
"C:\프로젝트\게임\미니골프2\SampleParser\SampleParserDlg.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\returner\LOCALS~1\Temp\RSP9.tmp" 
<h3>Output Window</h3>
Compiling...
SampleParserDlg.cpp
C:\프로젝트\게임\미니골프2\SampleParser\SampleParserDlg.cpp(4) : warning C4653: compiler option 'structure packing (/Zp)' inconsistent with precompiled header; current command-line option ignored
C:\프로젝트\게임\미니골프2\SampleParser\SampleParserDlg.cpp(65) : error C2248: 'CParser::~CParser' : cannot access protected member declared in class 'CParser'
        C:\프로젝트\게임\미니골프2\SampleParser\Labyrinth.h(74) : see declaration of 'CParser::~CParser'
Error executing cl.exe.



<h3>Results</h3>
SampleParserDlg.obj - 1 error(s), 1 warning(s)
</pre>
</body>
</html>
