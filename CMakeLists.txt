cmake_minimum_required(VERSION 3.4)
project(QtCustomizeTooltip)

file(GLOB hFile ${CMAKE_SOURCE_DIR}/*.h)
file(GLOB SrcFile ${CMAKE_SOURCE_DIR}/*.cpp)
#file(GLOB uiFile ${CMAKE_SOURCE_DIR}/*.ui)

#set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.12.9/5.12.9/msvc2017_64")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME}
	${hFile}
	${SrcFile}
	${uiFile}
	)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
target_link_libraries(${PROJECT_NAME}
	PUBLIC
	Qt5::Widgets
	Qt5::Core
	Qt5::Gui
	)
		
 source_group("hFile" FILES ${hFile})
 source_group("uiFile" FILES ${uiFile})
 
 add_compile_definitions(D_UNICODE)