cmake_minimum_required(VERSION 3.9)
project(Learning)

set(CMAKE_CXX_STANDARD 17)
add_executable(Learning main.cpp Entitee/Anime.cpp Entitee/Anime.h database/DBManager.cpp database/DBManager.h)
target_link_libraries(Learning C:\\Users\\Restauration\\CLionProjects\\Learning\\lib\\libsqlite.a)