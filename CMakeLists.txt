cmake_minimum_required(VERSION 3.16)
project(project6_part2)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(project6_part2 main.cpp src/Account.cpp src/Account.h src/AccountDao.cpp src/AccountDao.h src/ServiceProvider.cpp src/ServiceProvider.h)
target_link_libraries(project6_part2 ${CMAKE_SOURCE_DIR}/lib/pqxx.lib ${CMAKE_SOURCE_DIR}/lib/libpq.lib wsock32 ws2_32)