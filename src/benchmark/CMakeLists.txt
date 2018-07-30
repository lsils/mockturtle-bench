file(GLOB FILENAMES *.cpp)

add_custom_target(benchmarks ALL ${CMAKE_COMMAND} -E echo_append "" COMMENT "Build all benchmarks")

foreach(FILENAME ${FILENAMES})
  get_filename_component(BASENAME ${FILENAME} NAME_WE)

  set(TARGET_NAME bench_${BASENAME})

  add_executable(${TARGET_NAME} ${FILENAME})
  target_link_libraries(${TARGET_NAME} benchmark mockturtle libabc-pic)
  target_compile_options(${TARGET_NAME} PRIVATE -O2 -DNDEBUG)
  target_compile_definitions(${TARGET_NAME} PUBLIC NETWORKS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/../../networks")
  add_dependencies(benchmarks ${TARGET_NAME})
endforeach()
