#!/bin/bash

filename=$1;
outputName=$filename
path="$PWD/$outputName.cpp"

echo $PWD
echo $path
cmdToRun="g++ -o $outputName \"${path}\" -std=c++11 -Wall"
eval "${cmdToRun}"
