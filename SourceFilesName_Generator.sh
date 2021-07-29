#!/bin/bash

function traverse()
{
    for element in "$1"/*
    do
        elementR=${element:$2}
        
        if [[ -f "$element" && ( ${element: -2} == ".h" || ${element: -4} == ".cpp" ) ]]
        then
        
            echo -e ' \t '"\"""$elementR""\""
            
        elif [ -d "$element" ]
        then
        
            traverse "$element" "$2"
            
        fi
    done
}

startPath="$(dirname $0)""/src"
sources="$(dirname $0)""/SourceFilesName.cmake"

rm "$sources"
touch "$sources"

echo "[INFO   ] Start of "\""SourceFilesName.cmake"\"" file generation"
 
/bin/cat <<EOM>"$sources"
set(SOURCE_FILES_NAME

$(traverse $startPath ${#startPath}+1)

)
EOM

echo "[SUCCESS] End of "\""SourceFilesName.cmake"\"" file generation"


