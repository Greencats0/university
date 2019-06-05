#!/usr/bin/env bash
# I cannot come up with original names so I name these scripts after the tea I'm drinking while writing this


function convertTextToPDF() {
  if [ ! -f $1 ]; then
    echo "File does not exist at $1"
    exit
  fi
  filename="${1%.*}"
  mv $1 $filename
  enscript -B --silent "$filename" -o - | ps2pdf - ./$2/"$filename.pdf"
  rm -rf {"$filename.ps","$filename"}
}

function backupTextFilesAndImages() {
  mkdir {textFileBackup,imageBackup}
  for i in $(find . -maxdepth 1 -type f); do
    if [[ $(file $i | grep "ASCII") ]]; then
      cp $i textFileBackup
    elif [[ $(file $i | grep "image") ]]; then
      cp $i imageBackup
    fi
  done
}

function convertAllTheThings() {
  mkdir {sourceCode,imagesConverted}
  for i in $(find . -maxdepth 1 -type f); do
    if [[ $(file $i | grep "ASCII") ]]; then
      convertTextToPDF $i sourceCode
    elif [[ $(file $i | grep "image") ]]; then
      filename="${1%.*}"
      convert $i ./imagesConverted/"$filename.pdf"
      rm $i
    fi
  done
  pdfunite sourceCode/*.pdf "ALL_SOURCE.pdf"
  pdfunite imagesConverted/*.pdf "ALL_IMAGES.pdf"
}

# function autoGenerateUML() {
#   # this feature is going to be awesome when complete
#   for header in $(find . -maxdepth 1 -name '*.h*'); do
#     className=$(cat $header | | grep "^class" | sed 's/[{]//g' | sed -n -e 's/^.*class//p' | sed 's/^\ //')
#     classNameLength="$(echo $className | wc -c)"
#     lineAmountToPrint=$(python -c "print($(echo "$className" | wc -c) * 3)")
#
#     echo "$className"
#     printf "%*s%s" $classNameLength
#     echo "$className"
#     printf '_%.0s' $(seq $classNameLength) && printf '\n'
#     for i in "$(sed -n '/private/,/public/p' CustomerBill.hpp | sed 's/public://g;s/private://g' | sed 's:/.*::' | sed "s/^[ \t]*//" | sed '/^\s*$/d' )"; do
#       dataType=$(echo "$i" | awk '{print $1}')
#       variableName=$(echo $i | sed -n -e 's/^.*'$dataType'//p')
#       echo "-- $variableName : ${dataType^}"
#     done
#     printf '_%.0s' $(seq $classNameLength) && printf '\n'
# }
if [ ! -d $1 ]; then
  echo "[*]Error: $1 - Path does not exist"
  exit
else
  cd $1
fi
backupTextFilesAndImages
convertAllTheThings
