cmake_minimum_required(VERSION 3.19)
project(FishAI LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

# Найти qtermwidget
find_package(QTermWidget6 QUIET)
if(NOT QTermWidget6_FOUND)
    find_package(QTermWidget5 REQUIRED)
    set(QTERMWIDGET_LIB qtermwidget5)
else()
    set(QTERMWIDGET_LIB qtermwidget6)
endif()

qt_standard_project_setup()

# ВАЖНО: добавляем текущую папку в include paths
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

qt_add_executable(FishAI
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    terminalwidget.h
    terminalwidget.cpp
    consolemessagecombiner.h
    consolemessagecombiner.cpp
)

qt_add_translations(
    TARGETS FishAI
    TS_FILES FishAI_en_US.ts
)

target_link_libraries(FishAI
    PRIVATE
        Qt::Core
        Qt::Widgets
        qtermwidget6

        ${QTERMWIDGET_LIB}
)

include(GNUInstallDirs)
install(TARGETS FishAI
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET FishAI
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
