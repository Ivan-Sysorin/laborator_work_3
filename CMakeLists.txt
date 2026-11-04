cmake_minimum_required(VERSION 3.14)
project(laborator_work_3 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем директорию с заголовочными файлами
include_directories(include)

# Создаем интерфейсную библиотеку для заголовочных файлов (так как стек шаблонный)
add_library(stack_lib INTERFACE)
target_include_directories(stack_lib INTERFACE include)

# --- ПОДКЛЮЧЕНИЕ GOOGLE TEST ---
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --- СБОРКА ТЕСТОВ ---
add_executable(test_stack
    tests/stack_tests.cpp
    tests/arithmetic_expression.cpp
)

target_link_libraries(test_stack
    PRIVATE
    stack_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_stack)
