cmake_minimum_required(VERSION 3.0)

project(login)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

set(CMAKE_PREFIX_PATH "/home/yunzhongke/work/Qt5.6.2/5.6/gcc_64/lib/cmake/Qt5Widgets/Qt5WidgetsConfig.cmake")

find_package(Qt5Widgets)
if(Qt5Widgets_FOUND)
    message(STATUS ${Qt5Widgets_LIBRARIES})
    message(STATUS ${Qt5Widgets_VERSION_STRING})
    message(STATUS ${CMAKE_CURRENT_LIST_DIR})
    message(STATUS ${Qt5Widgets_INCLUDE_DIRS})
endif()

add_executable(${PROJECT_NAME} passwd_line_edit.cpp dialog1.cpp dialog.cpp main.cpp mainwindos.cpp)
target_link_libraries(${PROJECT_NAME} ${Qt5Widgets_LIBRARIES})
