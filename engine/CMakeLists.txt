set(ENGINE_SOURCES
	Engine.cpp
	Entity.cpp
	Component.cpp
	System.cpp
	)
set(ENGINE_HEADERS
	../include/ECSFPlatform.h
	../include/ECSFEngine.h
	../include/ECSFEntity.h
	../include/ECSFComponent.h
	../include/ECSFSystem.h
	)

add_library(engine SHARED ${ENGINE_HEADERS} ${ENGINE_SOURCES})
if(MSVC)
set_target_properties(engine PROPERTIES COMPILE_FLAGS "${COMPILE_FLAGS} /DNOMINMAX /DDLL_EXPORT /D_CRT_SECURE_NO_WARNINGS")
endif(MSVC)
target_link_libraries(engine crc)
