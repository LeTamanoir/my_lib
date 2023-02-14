#!/bin/bash

display_help() {
    echo "Epitech project setup tool:
USAGE:
    ./setup.sh [project-name]"
}

if [ $# != 1 ]; then
    display_help
    exit 1
fi

project_name=$1
replace='\[PROJECT-NAME\]'
temp=''

files=(
    '.gitignore'
    'Makefile'
    '.vscode/settings.json'
    'src/main.c'
)

for file in ${files[@]}; do
    temp="${file}_temp"

    cp $file $temp

    sed "s/$replace/$project_name/g" $temp > $file

    rm $temp
done
