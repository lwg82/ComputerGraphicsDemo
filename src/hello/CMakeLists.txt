project(Hello)



set(GC_HEADERS
	
)

set(GC_SOURCES
	main.cpp
)


add_executable(${PROJECT_NAME}  ${GC_HEADERS}  ${GC_SOURCES})

target_link_libraries(${PROJECT_NAME}  
				${EAXYX_STATIC_LIBRARIES}
)






