cmake_minimum_required(VERSION 3.20)
project(gardeners)

set(CMAKE_CXX_STANDARD 14)

add_executable(gardeners main.cpp Game.cpp Game.hpp Task.cpp Task.hpp Board.cpp Board.hpp Tile.cpp Tile.hpp TerrainTile.cpp TerrainTile.hpp NonTerrainTile.cpp NonTerrainTile.hpp Plant.cpp Plant.hpp Shape.cpp Shape.hpp)
