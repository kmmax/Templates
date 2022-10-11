cmake_minimum_required(VERSION 3.2)

project(programoptions CXX)

set (BOOST_ROOT "C:/Boost/") # Путь к библиотеке Boost (установить, если путь нестандартный - не "C:/Boost/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")


# === Boost Library ===
#set(Boost_USE_STATIC_RUNTIME    OFF)
#set(Boost_USE_STATIC_LIBS       OFF)	# Статическая/динамическая линковка с boost

set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (BOOST_ALL_DYN_LINK OFF)

find_package(Boost 1.80.0 REQUIRED COMPONENTS program_options)
if (Boost_FOUND)
	message("BOOST_ROOT: " ${BOOST_ROOT})
	message("Bost_INCLUDE_DIRS: " ${Boost_INCLUDE_DIRS})
endif()

# === Application ===
file(GLOB_RECURSE Proj_Src "src/*.cpp" "src/*.h")
include_directories(${Boost_INCLUDE_DIRS})
add_executable(programoptions ${Proj_Src})
target_link_libraries(programoptions ${Boost_LIBRARIES})

