#!/bin/bash
TARGET=./${TARGET:-"megaphone"}

# ANSIエスケープコードを定義
NC='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'

function run_test {
  output=$($TARGET "${@:1:$#-1}")
  expected="${@: -1}"
  echo -e "Running test with input:"
  # 引数ごとにループして表示
  for arg in "${@:1:$#-1}"; do
    echo -e "  '$arg'"
  done
  if [ "$output" == "$expected" ]; then
    echo -e "${GREEN}Test passed${NC}"
    echo -e "------------------------------------------"
  else
    echo -e "${RED}Test failed${NC}"
    echo "Expected: '$expected'"
    echo "Got: '$output'"
    exit 1
  fi
}

run_test "shhhhh... I think the students are asleep..." "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
run_test "Damnit" " ! " "Sorry students, I thought this thing was off." "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
run_test "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

# すべてのテストがパスした場合にメッセージを表示
echo -e "${GREEN}All tests passed${NC}"

