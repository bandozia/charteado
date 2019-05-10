cmake_minimum_required(VERSION 3.0.0)
project(charteado VERSION 0.1.0)

set(OpenCV_DIR E:\\Recursos\\opencv\\build\\x64\\vc15\\lib)
set(EXECUTABLE_OUTPUT_PATH E:\\Andozianos\\charteado\\build)
find_package( OpenCV REQUIRED )

add_executable(hist samples/histogramas.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include_directories(include)
target_link_libraries( hist ${OpenCV_LIBS} )