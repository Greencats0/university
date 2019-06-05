#!/usr/bin/env bash
# use extension .uml to signify that it is a class diagram
if [ -z $1 ]; then
  echo "Usage: convertTextToPDF <path to text file>"
  exit
fi
if [ ! -f $1 ]; then
  echo "File does not exist at $1"
  exit
fi
filename="${1%.*}"
mv $1 $filename
enscript -B --silent "$filename" -o - | ps2pdf - "$filename.pdf"
rm -rf {"$filename.ps","$filename"}
