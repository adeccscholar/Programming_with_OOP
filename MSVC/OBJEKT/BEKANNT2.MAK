# Microsoft Visual C++ generated build script - Do not modify

PROJ = BEKANNT2
DEBUG = 1
PROGTYPE = 3
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = -d_DEBUG
R_RCDEFINES = -dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = I:\MSVC\OBJEKT\
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC =             
FIRSTCPP =             
RC = rc
CFLAGS_D_WTTY = /nologo /W3 /FR /G2 /Zi /D_DEBUG /Od /AM /Mq /Fd"BEKANNT2.PDB"
CFLAGS_R_WTTY = /nologo /W3 /FR /G2 /DNDEBUG /Gs /Ox /AM /Mq
LFLAGS_D_WTTY = /NOLOGO /ONERROR:NOEXE /NOD /PACKC:57344 /CO /ALIGN:16
LFLAGS_R_WTTY = /NOLOGO /ONERROR:NOEXE /NOD /PACKC:57344 /ALIGN:16
LIBS_D_WTTY = oldnames libw mlibcewq
LIBS_R_WTTY = oldnames libw mlibcewq
RCFLAGS = /nologo
RESFLAGS = /nologo
RUNFLAGS = 
OBJS_EXT = 
LIBS_EXT = 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_WTTY)
LFLAGS = $(LFLAGS_D_WTTY)
LIBS = $(LIBS_D_WTTY)
MAPFILE = nul
RCDEFINES = $(D_RCDEFINES)
DEFFILE=H:\MSVC\BIN\CL.DEF
!else
CFLAGS = $(CFLAGS_R_WTTY)
LFLAGS = $(LFLAGS_R_WTTY)
LIBS = $(LIBS_R_WTTY)
MAPFILE = nul
RCDEFINES = $(R_RCDEFINES)
DEFFILE=H:\MSVC\BIN\CL.DEF
!endif
!if [if exist MSVC.BND del MSVC.BND]
!endif
SBRS = ADRESSE.SBR \
		DATUM.SBR \
		MYSTRING.SBR \
		PERSON.SBR \
		TESTBEK2.SBR \
		BEKANNT2.SBR \
		BEKANNT.SBR


ADRESSE_DEP = i:\msvc\objekt\adresse.hpp \
	i:\msvc\objekt\mystring.hpp


DATUM_DEP = i:\msvc\objekt\datum.hpp


MYSTRING_DEP = i:\msvc\objekt\mystring.hpp


PERSON_DEP = i:\msvc\objekt\person.hpp \
	i:\msvc\objekt\mystring.hpp \
	i:\msvc\objekt\adresse.hpp \
	i:\msvc\objekt\datum.hpp


TESTBEK2_DEP = i:\msvc\objekt\bekannt.hpp \
	i:\msvc\objekt\person.hpp \
	i:\msvc\objekt\mystring.hpp \
	i:\msvc\objekt\adresse.hpp \
	i:\msvc\objekt\datum.hpp \
	i:\msvc\objekt\bekannt2.hpp


BEKANNT2_DEP = i:\msvc\objekt\bekannt2.hpp \
	i:\msvc\objekt\person.hpp \
	i:\msvc\objekt\mystring.hpp \
	i:\msvc\objekt\adresse.hpp \
	i:\msvc\objekt\datum.hpp


BEKANNT_DEP = i:\msvc\objekt\bekannt.hpp \
	i:\msvc\objekt\person.hpp \
	i:\msvc\objekt\mystring.hpp \
	i:\msvc\objekt\adresse.hpp \
	i:\msvc\objekt\datum.hpp


all:	$(PROJ).EXE $(PROJ).BSC

ADRESSE.OBJ:	ADRESSE.CPP $(ADRESSE_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ADRESSE.CPP

DATUM.OBJ:	DATUM.CPP $(DATUM_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c DATUM.CPP

MYSTRING.OBJ:	MYSTRING.CPP $(MYSTRING_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c MYSTRING.CPP

PERSON.OBJ:	PERSON.CPP $(PERSON_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c PERSON.CPP

TESTBEK2.OBJ:	TESTBEK2.CPP $(TESTBEK2_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c TESTBEK2.CPP

BEKANNT2.OBJ:	BEKANNT2.CPP $(BEKANNT2_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c BEKANNT2.CPP

BEKANNT.OBJ:	BEKANNT.CPP $(BEKANNT_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c BEKANNT.CPP


$(PROJ).EXE::	ADRESSE.OBJ DATUM.OBJ MYSTRING.OBJ PERSON.OBJ TESTBEK2.OBJ BEKANNT2.OBJ \
	BEKANNT.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
ADRESSE.OBJ +
DATUM.OBJ +
MYSTRING.OBJ +
PERSON.OBJ +
TESTBEK2.OBJ +
BEKANNT2.OBJ +
BEKANNT.OBJ +
$(OBJS_EXT)
$(PROJ).EXE
$(MAPFILE)
h:\msvc\lib\+
h:\msvc\mfc\lib\+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) $@


run: $(PROJ).EXE
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
