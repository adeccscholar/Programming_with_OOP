# Microsoft Visual C++ generated build script - Do not modify

PROJ = ANGEST2
DEBUG = 1
PROGTYPE = 3
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = -d_DEBUG
R_RCDEFINES = -dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = I:\MSVC\DBASE\
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC =             
FIRSTCPP = ANGEST_2.CPP
RC = rc
CFLAGS_D_WTTY = /nologo /W3 /FR /G2 /Zi /D_DEBUG /Od /AM /Mq
CFLAGS_R_WTTY = /nologo /W3 /FR /G2 /DNDEBUG /Gs /Ox /AM /Mq
LFLAGS_D_WTTY = /NOLOGO /ONERROR:NOEXE /NOD /PACKC:57344 /CO /ALIGN:16
LFLAGS_R_WTTY = /NOLOGO /ONERROR:NOEXE /NOD /PACKC:57344 /ALIGN:16
LIBS_D_WTTY = oldnames libw mlibcewq
LIBS_R_WTTY = oldnames libw mlibcewq
RCFLAGS = /nologo
RESFLAGS = /nologo
RUNFLAGS = 
DEFFILE = ANGEST2.DEF
OBJS_EXT = 
LIBS_EXT = 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_WTTY)
LFLAGS = $(LFLAGS_D_WTTY)
LIBS = $(LIBS_D_WTTY)
MAPFILE = nul
RCDEFINES = $(D_RCDEFINES)
DEFFILE=I:\MSVC\DBASE\ANGEST2.DEF
!else
CFLAGS = $(CFLAGS_R_WTTY)
LFLAGS = $(LFLAGS_R_WTTY)
LIBS = $(LIBS_R_WTTY)
MAPFILE = nul
RCDEFINES = $(R_RCDEFINES)
DEFFILE=I:\MSVC\DBASE\ANGEST2.DEF
!endif
!if [if exist MSVC.BND del MSVC.BND]
!endif
SBRS = ANGEST_2.SBR \
		DBASE.SBR \
		DBDATUM.SBR \
		DBDEFINE.SBR \
		DBLOGIC.SBR \
		DBOBJEKT.SBR \
		DBSTRING.SBR \
		DBZAHL.SBR \
		MYSTRING.SBR


ANGEST_2_DEP = i:\msvc\dbase\dbheader.hpp \
	i:\msvc\dbase\dbdefine.hpp \
	i:\msvc\dbase\dbobjekt.hpp \
	i:\msvc\dbase\dbdatum.hpp \
	i:\msvc\dbase\dbstring.hpp \
	i:\msvc\dbase\mystring.hpp \
	i:\msvc\dbase\dblogic.hpp \
	i:\msvc\dbase\dbzahl.hpp


DBASE_DEP = i:\msvc\dbase\dbheader.hpp \
	i:\msvc\dbase\dbdefine.hpp


DBDATUM_DEP = i:\msvc\dbase\dbdatum.hpp \
	i:\msvc\dbase\dbobjekt.hpp


DBDEFINE_DEP = i:\msvc\dbase\dbdefine.hpp


DBLOGIC_DEP = i:\msvc\dbase\dblogic.hpp \
	i:\msvc\dbase\dbobjekt.hpp


DBOBJEKT_DEP = i:\msvc\dbase\dbobjekt.hpp


DBSTRING_DEP = i:\msvc\dbase\dbstring.hpp \
	i:\msvc\dbase\dbobjekt.hpp \
	i:\msvc\dbase\mystring.hpp


DBZAHL_DEP = i:\msvc\dbase\dbzahl.hpp \
	i:\msvc\dbase\dbobjekt.hpp


MYSTRING_DEP = i:\msvc\dbase\mystring.hpp


all:	$(PROJ).EXE $(PROJ).BSC

ANGEST_2.OBJ:	ANGEST_2.CPP $(ANGEST_2_DEP)
	$(CPP) $(CFLAGS) $(CPPCREATEPCHFLAG) /c ANGEST_2.CPP

DBASE.OBJ:	DBASE.CPP $(DBASE_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c DBASE.CPP

DBDATUM.OBJ:	DBDATUM.CPP $(DBDATUM_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c DBDATUM.CPP

DBDEFINE.OBJ:	DBDEFINE.CPP $(DBDEFINE_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c DBDEFINE.CPP

DBLOGIC.OBJ:	DBLOGIC.CPP $(DBLOGIC_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c DBLOGIC.CPP

DBOBJEKT.OBJ:	DBOBJEKT.CPP $(DBOBJEKT_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c DBOBJEKT.CPP

DBSTRING.OBJ:	DBSTRING.CPP $(DBSTRING_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c DBSTRING.CPP

DBZAHL.OBJ:	DBZAHL.CPP $(DBZAHL_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c DBZAHL.CPP

MYSTRING.OBJ:	MYSTRING.CPP $(MYSTRING_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c MYSTRING.CPP


$(PROJ).EXE::	ANGEST_2.OBJ DBASE.OBJ DBDATUM.OBJ DBDEFINE.OBJ DBLOGIC.OBJ DBOBJEKT.OBJ \
	DBSTRING.OBJ DBZAHL.OBJ MYSTRING.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
ANGEST_2.OBJ +
DBASE.OBJ +
DBDATUM.OBJ +
DBDEFINE.OBJ +
DBLOGIC.OBJ +
DBOBJEKT.OBJ +
DBSTRING.OBJ +
DBZAHL.OBJ +
MYSTRING.OBJ +
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
