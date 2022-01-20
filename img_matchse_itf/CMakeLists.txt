set(LIB_SRC 
	"img_matched.cpp" 
	"img_matched.h")

add_library(img_matchse_itf STATIC ${LIB_SRC})
target_include_directories(img_matchse_itf PRIVATE ${PULIC_INCLUDE_DIR})
target_link_libraries(img_matchse_itf unofficial::vlfeat::vl)
