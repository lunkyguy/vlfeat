set(APP_SRC 
	main.cpp)
add_executable(app ${APP_SRC})
target_include_directories(app PRIVATE ${PULIC_INCLUDE_DIR})
target_link_libraries(app PRIVATE ${OpenCV_LIBS} img_matchse_itf)
