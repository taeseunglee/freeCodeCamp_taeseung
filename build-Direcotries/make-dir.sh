#!/bin/bash
echo "Enter the directory text filename"
read filename

echo "Filename you input : $filename"

file_content=`cat $filename`

for dir_name in $file_content
do
  mkdir -p $dir_name
done

