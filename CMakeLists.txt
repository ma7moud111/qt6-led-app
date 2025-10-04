cmake_minimum_required(VERSION 3.16)

project(LedSimulation VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

# ---- Application target ----
qt_add_executable(appLedSimulation
    main.cpp
    LedController.cpp
    led.cpp
)

qt_add_qml_module(appLedSimulation
    URI LedSimulation
    VERSION 1.0
    QML_FILES main.qml
    SOURCES LedController.h LedController.cpp led.h led.cpp
)



set_target_properties(appLedSimulation PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

target_link_libraries(appLedSimulation PRIVATE Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS appLedSimulation
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
