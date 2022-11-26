#!/bin/bash

display_help() {
    echo "Epitech project setup tools:
USAGE:
    ./setup.sh [project-name]"
}

if [ $# != 1 ]; then
    display_help
    exit 1
fi

project_name=$1

cp .gitignore temp

sed "s/\[PROJECT\-NAME\]/$project_name/g" temp > .gitignore

rm temp
