cmake_minimum_required(VERSION 3.10.0)
project(laboratory3 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_executable(
               laboratory3 
               main.cpp 

               voidprint.h 
               voidprint.cpp 
               elementdoublelinkedlist.h 
               elementdoublelinkedlist.cpp
               
               elementmonolinkedlist.h
               elementmonolinkedlist.cpp
               
               functions.h
               functions.cpp

               newcontainer.h

               containers.h

               consistent_container.h
               consistent_container.cpp

               list_type_container.h
               list_type_container.cpp
               
               )

# Для MSVC добавьте специфичные настройки
if(MSVC)
    add_compile_options(/W4)  # Включить предупреждения
    # Отключите конкретные предупреждения если нужно
    add_compile_options(/wd4244)  # Отключить warning C4244
endif()