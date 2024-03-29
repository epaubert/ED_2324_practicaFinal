cmake_minimum_required(VERSION 3.16)
project(practicafinal)

set(CMAKE_CXX_STANDARD 14)
set(BASE_FOLDER rutas_aereas)

# Opciones de compilación: 
add_compile_options(-O0 -Wall -g -ggdb)
# Opciones de release: 
# add_compile_options(-O3 -Wall)

include_directories(${BASE_FOLDER}/include)

add_library(image ${BASE_FOLDER}/src/imagen.cpp  ${BASE_FOLDER}/src/imagenES.cpp)

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/pruebarotacion.cpp)
add_executable(pruebarotacion ${BASE_FOLDER}/src/pruebarotacion.cpp)
target_link_libraries(pruebarotacion LINK_PUBLIC image)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/pruebapegado.cpp)
add_executable(pruebapegado ${BASE_FOLDER}/src/pruebapegado.cpp)
target_link_libraries(pruebapegado LINK_PUBLIC image)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/ruta_aerea.cpp)
add_executable(ruta_aerea ${BASE_FOLDER}/src/ruta_aerea.cpp)
target_link_libraries(ruta_aerea LINK_PUBLIC image)
endif()

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
