cmake_minimum_required(VERSION 3.5)
project(passwordSecurity VERSION 1.0.2 LANGUAGES CXX)

set(DEFAULT_BUILD_TYPE "Release")

message(STATUS "Downloading password list")
set(PSWD_LIST ${CMAKE_CURRENT_SOURCE_DIR}/lists/pswds.txt)
file(DOWNLOAD "https://raw.githubusercontent.com/danielmiessler/SecLists/master/Passwords/xato-net-10-million-passwords.txt" ${PSWD_LIST})

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

include(GNUInstallDirs)

file(GLOB_RECURSE SOURCE_FILES
    "src/*"
    "include/*"
)
message(STATUS ${PSWD_LIST})

add_library(${PROJECT_NAME} ${SOURCE_FILES})
target_compile_definitions(${PROJECT_NAME} PRIVATE WORDLIST="${PSWD_LIST}")
target_link_libraries(${PROJECT_NAME} PUBLIC)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1)

install(TARGETS ${PROJECT_NAME} EXPORT passwordSecurityConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/pswdsec DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT passwordSecurityConfig DESTINATION share/${PROJECT_NAME}/cmake)

add_subdirectory(test)