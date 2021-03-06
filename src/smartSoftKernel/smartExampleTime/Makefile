# --------------------------------------------------------------------------
#
#  Copyright (C) 2002 Christian Schlegel
#
#        schlegel@hs-ulm.de
#
#        Prof. Dr. Christian Schlegel
#        University of Applied Sciences
#        Prittwitzstr. 10
#        D-89075 Ulm
#        Germany
#
#  This file is part of the "SmartSoft Communication Library".
#  It provides standardized patterns for communication between
#  different components.
#
#  This library is free software; you can redistribute it and/or
#  modify it under the terms of the GNU Lesser General Public
#  License as published by the Free Software Foundation; either
#  version 2.1 of the License, or (at your option) any later version.
#
#  This library is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public
#  License along with this library; if not, write to the Free Software
#  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#
#
#  (partly based on joint work with Robert W�rz)
#
# --------------------------------------------------------------------------

#----------------------------------------------------------------------------
#
# 
#
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
#
#----------------------------------------------------------------------------
CONF  = $(SMART_ROOT)/src/Makefile.smart.conf
RULES = $(SMART_ROOT)/src/Makefile.smart.rules

include $(CONF)

#----------------------------------------------------------------------------
#       Include macros and targets
#----------------------------------------------------------------------------

DEPENDENCIES += *.cc
INCLUDES     += -I$(TAO_ROOT)/orbsvcs

#----------------------------------------------------------------------------
# Variables
#
# USER: IDL_FILES         IDL files in this directory
#       EXPORT_FILES      files to be exported not including the IDL files
#       INI_FILES         ini files needed by that component
#       OBJ_FILES         generated object files without IDL object files
#       DISTCLEAN_FILES   files to be removed when cleaning up
#
#       SERVER_OBJS       all object files which build the component
#       SERVER_LIBS       libraries needed by the component
#       CLIENT_OBJS       all object files for the client library
#       CLIENT_LIBS       libraries needed by the client library
#
#---------------------------------------------------------------------------- 
IDL_FILES    = exampleTime
EXPORT_FILES = commExampleTime.hh
INI_FILES    =
OBJ_FILES    = commExampleTime.o

#---------------------------------------------------------------------------- 
#
#---------------------------------------------------------------------------- 
IDL_EXPORT   = $(addsuffix C.i,    $(IDL_FILES)) \
               $(addsuffix C.hh,   $(IDL_FILES)) \
               $(addsuffix S.i,    $(IDL_FILES)) \
               $(addsuffix S.hh,   $(IDL_FILES))
 
IDL_DEPEND   = $(addsuffix S.cc,   $(IDL_FILES)) \
               $(addsuffix S.hh,   $(IDL_FILES)) \
               $(addsuffix S.i,    $(IDL_FILES)) \
               $(addsuffix C.cc,   $(IDL_FILES)) \
               $(addsuffix C.hh,   $(IDL_FILES)) \
               $(addsuffix C.i,    $(IDL_FILES))
 
IDL_CLEAN    = $(IDL_DEPEND) \
               $(addprefix $(OBJ_DIR)/, $(addsuffix S.o,   $(IDL_FILES))) \
               $(addprefix $(OBJ_DIR)/, $(addsuffix S_T.o, $(IDL_FILES))) \
               $(addprefix $(OBJ_DIR)/, $(addsuffix C.o,   $(IDL_FILES))) \
               $(addprefix $(INC_DIR)/, $(IDL_EXPORT)) 

EXPORT_CLEAN = $(addprefix $(INC_DIR)/, $(EXPORT_FILES))

INI_CLEAN    = $(addprefix $(ETC_DIR)/, $(INI_FILES))

CLEAN_FILES = $(IDL_CLEAN) \
              $(EXPORT_CLEAN) \
              $(INI_CLEAN) \
              $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
 
TAO_IDLFLAGS += -cs C.cc -hc C.hh -ss S.cc -hs S.hh -sT S_T.cc -hT S_T.hh -ci C.i -si S.i

##
## local build variables
##

INCLUDES  += -I$(QTDIR)/include
LIB_DIRS  += -L$(QTDIR)/lib
LFLAGS     = -Wl,-rpath,$(QTDIR)/lib

DISTCLEAN_FILES = $(LIB_DIR)/libsmartExampleTime.a

SERVER_OBJS = 

SERVER_LIBS = 

CLIENT_OBJS = $(OBJ_DIR)/commExampleTime.o \
              $(OBJ_DIR)/exampleTimeC.o \
              $(OBJ_DIR)/exampleTimeS.o

CLIENT_LIBS =

##
## Compulsory rules
##

all: $(IDL_DEPEND)
	$(MAKE) export $(DEPEND)
	$(MAKE) build


build: build-libs build-components

build-libs: $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR) \
	$(LIB_DIR)/libsmartExampleTime.a

build-components:

build-tests:

export: $(IDL_EXPORT)
	$(ECHO) "   ---- Installing header files etc."
	$(SILENT) $(MKDIR) $(ETC_DIR)
	$(SILENT) $(MKDIR) $(INC_DIR)
	$(foreach exp,$(IDL_EXPORT),$(INSTALL_H) `pwd`/$(exp) $(INC_DIR);)
	$(foreach exp,$(EXPORT_FILES),$(INSTALL_H) `pwd`/$(exp) $(INC_DIR);)
	$(foreach exp,$(INI_FILES),$(INSTALL_H) `pwd`/$(exp) $(ETC_DIR);)


clean:
	$(RM) $(CLEAN_FILES)

distclean: clean
	$(RM) $(DEPEND) Makefile.depend* $(DISTCLEAN_FILES)

##
## local rules
##

$(OBJ_DIR) $(LIB_DIR) $(BIN_DIR):
	$(SILENT) $(MKDIR) $@

$(LIB_DIR)/libsmartExampleTime.a: $(CLIENT_OBJS)
	$(ECHO) "   ---- Creating $@"
	$(SILENT) $(AR) $@ $(CLIENT_OBJS)
	$(SILENT) $(RANLIB) $@


##
## Standard suffix, version, packaging and dep rules
##
include $(RULES)


%S.cc %S.hh %S.i %C.cc %C.cc %C.hh %C.i : %.idl
	$(ECHO) "    ---- Processing $< (IDL)"
	$(IDL) $(TAO_IDLFLAGS) $<

