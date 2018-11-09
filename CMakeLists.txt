cmake_minimum_required (VERSION 2.8.11)
project (ReverseAI)

file(GLOB_RECURSE CORE_FILES src/Reversi/*)

add_executable (reverse_ai
    src/main.cpp
    ${CORE_FILES}
)

