project(line)



set(GC_HEADERS
	
)

set(GC_SOURCES
	dda.cpp
)


add_executable(${PROJECT_NAME}  ${GC_HEADERS}  ${GC_SOURCES})

target_link_libraries(${PROJECT_NAME}  
				${EAXYX_STATIC_LIBRARIES}
)






