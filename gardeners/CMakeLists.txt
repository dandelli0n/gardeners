cmake_minimum_required(VERSION 3.20)
project(gardeners)
include_directories(vendor/sdl/include vendor/sdl_ttf/include)

set(CMAKE_CXX_STANDARD 14)

add_executable(gardeners main.cpp Game.cpp Game.hpp Task.cpp Task.hpp Board.cpp Board.hpp Tile.cpp Tile.hpp TerrainTile.cpp TerrainTile.hpp NonTerrainTile.cpp NonTerrainTile.hpp Plant.cpp Plant.hpp Shape.cpp Shape.hpp Renderer.cpp Renderer.hpp Geometry.cpp Geometry.hpp)
link_directories(vendor/sdl/lib/x86)
link_directories(vendor/sdl_ttf/lib/x86)
target_link_libraries(gardeners ${CMAKE_CURRENT_SOURCE_DIR}/vendor/sdl/lib/x86/SDL2.lib ${CMAKE_SOURCE_DIR}/vendor/sdl_ttf/lib/x86/SDL2_ttf.lib)