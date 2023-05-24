cmake_minimum_required(VERSION 3.21)
project(ChessRumbleSFML CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(CMakeSFMLProject src/main.cpp src/Game.cpp src/Menu.cpp 
src/ChessBoard.cpp src/Square.cpp src/Piece.cpp src/Pawn.cpp src/King.cpp src/Queen.cpp 
src/Knight.cpp src/Rook.cpp src/Bishop.cpp src/BomberPawn.h src/BomberPawn.cpp)
target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics)
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET CMakeSFMLProject POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:CMakeSFMLProject> $<TARGET_FILE_DIR:CMakeSFMLProject> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS CMakeSFMLProject)
