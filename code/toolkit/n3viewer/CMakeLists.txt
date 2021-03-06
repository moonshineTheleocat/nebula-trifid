#-------------------------------------------------------------------------------
# Toolkit
#-------------------------------------------------------------------------------
INCLUDE_DIRECTORIES(				${Nebula3_SOURCE_DIR}/code/application
									${Nebula3_SOURCE_DIR}/code/addons									
									${Nebula3_SOURCE_DIR}/code/application/basegamefeature
									${Nebula3_SOURCE_DIR}/code/application/corefeature
									${Nebula3_SOURCE_DIR}/code/application/graphicsfeature
									${Nebula3_SOURCE_DIR}/code/application/physicsfeature
									${Nebula3_SOURCE_DIR}/code/extlibs
									${Nebula3_SOURCE_DIR}/code/extlibs/ode
									${Nebula3_SOURCE_DIR}/code/foundation
									${Nebula3_SOURCE_DIR}/code/render
									${Nebula3_SOURCE_DIR}/code/sui
									${Nebula3_SOURCE_DIR}/code/tools		
									${Nebula3_SOURCE_DIR}/code/toolkit
									${Nebula3_SOURCE_DIR}/code
					)


FILE(GLOB SRC "*.cc")
FILE(GLOB HEAD "*.h")
LIST(APPEND SRCS ${SRC} ${HEAD})
SOURCE_GROUP("n3viewer" FILES ${SRCS})

set(PCH_files	
    ../stdneb.cc
)
SOURCE_GROUP("Precompiled" FILES ${PCH_files})

LIST(APPEND ALLSRCS ${SRCS} ${PCH_files})

ADD_EXECUTABLE(n3viewer ${ALLSRCS})
SET_TARGET_PROPERTIES(n3viewer PROPERTIES FOLDER "N3SDK/Toolkit")

N_SET_COMPILER_DEFAULTS()
N_SET_EXE_LINKER_DEFAULTS(n3viewer)
N_SET_EXE_SUBSYSTEM(n3viewer Windows)
IF(N_USE_PRECOMPILED_HEADERS)
	N_SET_PCH(n3viewer stdneb.h stdneb.cc ../)
ENDIF()
ADD_DEPENDENCIES(n3viewer
	${NEBULA_DEFAULT_LIBS}
	${N_LIBS}
	)
TARGET_LINK_LIBRARIES(n3viewer 
	${NEBULA_DEFAULT_LIBS}
	${N_LIBS}
)
IF(N_QT_NEB_SUPPORT)
TARGET_LINK_LIBRARIES(n3viewer qtfeature 	${QT_WIN_LIBS}
	${QT_LIBRARIES} ${QT_QTMAIN_LIBRARY})
ENDIF()
