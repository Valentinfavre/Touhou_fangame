cmake_minimum_required(VERSION 3.15)
project(Touhou_flandre)

set(CMAKE_CXX_STANDARD 14)

function(importGit NAME GIT_URL)
    configure_file(CMakeLists.txt.in ${NAME}-download/CMakeLists.txt)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
            RESULT_VARIABLE result
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${NAME}-download)
    if (result)
        message(FATAL_ERROR "CMake step for ${NAME} failed : ${result}")
    endif ()
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
            RESULT_VARIABLE result
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${NAME}-download)
    if (result)
        message(FATAL_ERROR "Build step for ${NAME} failed : ${result}")
    endif ()

    add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/${NAME}-src
            ${CMAKE_CURRENT_BINARY_DIR}/${NAME}-build
            EXCLUDE_FROM_ALL)

    include_directories("${${NAME}_SOURCE_DIR}/include")
endfunction(importGit)


importGit(sfml https://github.com/SFML/SFML)
importGit(freetype https://github.com/aseprite/freetype2)
importGit(ZLIB https://github.com/madler/zlib)

add_executable(Touhou_flandre src/objects/bullet.cpp include/objects/bullet.h src/objects/background.cpp include/objects/background.h src/system/clock.cpp include/system/clock.h src/system/data.cpp include/system/data.h src/objects/drawable.cpp include/objects/drawable.h
        include/objects/entity.h src/game/game.cpp include/game/game.h src/system/hitbox.cpp include/system/hitbox.h src/system/input.cpp include/system/input.h main.cpp src/menu/main_menu.cpp include/menu/main_menu.h src/menu/main_options_menu.cpp include/menu/main_options_menu.h src/menu/menu.cpp include/menu/menu.h include/system/movable.h src/menu/options_menu.cpp include/menu/options_menu.h
        src/system/path.cpp include/system/path.h src/menu/pause.cpp include/menu/pause.h src/game/player.cpp include/game/player.h include/objects/resources.h src/system/spawner.cpp include/system/spawner.h src/game/world.cpp include/game/world.h include/system/audio.h)
target_link_libraries(Touhou_flandre sfml-graphics sfml-audio winmm)