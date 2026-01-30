#!/bin/zsh
echo "formatting src"
clang-format -i $(find src/ -name '*.cpp' -o -name '*.hpp' ) -verbose
