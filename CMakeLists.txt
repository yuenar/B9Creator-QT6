cmake_minimum_required(VERSION 3.21)

project(B9Creator VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.9 REQUIRED COMPONENTS
  Core
  Gui
  Widgets
  Svg
  Network
  Concurrent
  OpenGLWidgets
)

qt_standard_project_setup()

# 顶层只负责全局配置与子目录
# 第三方库（如 qextserialport）后续可在此处 add_subdirectory

add_subdirectory(src)
add_subdirectory(resources)
