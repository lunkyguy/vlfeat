cmake_minimum_required(VERSION 3.15)

project(ImageFeat)

set(PULIC_INCLUDE_DIR
	${CMAKE_SOURCE_DIR}/img_matchse_itf
	CACHE INTERNAL "PULIC_INCLUDE_DIR")

if(WIN32)	
set(CMAKE_TOOLCHAIN_FILE "E:/repos/vcpkg-2021.05.12/scripts/buildsystems/vcpkg.cmake")
else()
set(CMAKE_TOOLCHAIN_FILE "/home/gtac/Public/repos/vcpkg-2021.05.12/scripts/buildsystems/vcpkg.cmake")
endif()

find_package(vlfeat CONFIG REQUIRED)
find_package(GDAL REQUIRED)
find_package(OpenCV CONFIG REQUIRED)

add_subdirectory(app)
add_subdirectory(img_matchse_itf)
