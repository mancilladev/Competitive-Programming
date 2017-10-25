#!/bin/bash
cp ~/cp/templates/cpp_template.cpp "${PWD}/${1}.cpp"

if [[ -n "${@:2}" && "${2}" == "-s" ]]; then
    subl "${PWD}/${1}.cpp"
else
    vim "${PWD}/${1}.cpp"
fi
