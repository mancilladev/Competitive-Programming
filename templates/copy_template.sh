#!/bin/bash
cp ~/cp/templates/cpp_template.cpp "${PWD}/${1}.cpp"

if [[ -n "${@:2}" && "${2}" == "-v" ]]; then
    vim "${PWD}/${1}.cpp"
else
    subl "${PWD}/${1}.cpp"
fi
