add_library(cells INTERFACE)

target_include_directories(cells INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
