set(project Platformer)

project(${project})

# CMake 3.4 come suggerito da CMake
cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

# Richiedo librerie Qt
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)

# Richiesto dalla documentazione
qt_standard_project_setup()

# Aggiungo eseguibile
add_executable(${project} ${sorgenti})

# Seleziona startup project per visual studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${project})

# Collego librerie Qt e Vulkan con eseguibile
target_link_libraries(${project} Qt6::Widgets Qt6::OpenGLWidgets Qt6::Multimedia)

target_sources(${project}
	PRIVATE
		main.cpp
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Attivo funzionalita' specifiche di CMake per Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Suggerito dal compilatore
set(SKIP_AUTOMOC ON)