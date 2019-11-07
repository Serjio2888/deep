#!/usr/bin/env bash

set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

print_header "RUN cppcheck"
if [ "${1}" == "--local" ]; then
	CPPCHECK="cppcheck"
else
	CPPCHECK="./linters/cppcheck/cppcheck"
fi
echo "here1"
${CPPCHECK} project --enable=all --error-exitcode=1 -I * --suppress=missingIncludeSystem  -i in.txt tester.out README.md# --check-config
echo "here2"
print_header "RUN cpplint.py"
python2.7 ./linters/cpplint/cpplint.py --extensions=c,cpp *

print_header "SUCCESS"
