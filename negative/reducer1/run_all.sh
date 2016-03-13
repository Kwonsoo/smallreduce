#!/bin/bash

DIR=$1    # Path to directory of benchmark programs
NCPU=$2    # Number of CPUs
SPARROW=$3  # pathto/main.native

mkdir -p ./reduced

for src in $DIR/*.c
do
  # Replace precision-effective queries with airac_observe() 
  # and save each copy with one replacement in ./reduced/PGM.
  echo $src
  PGM=`basename $src`
  if [ "$(ls -A ./reduced/$PGM)" ]; then
    echo "Skip $PGM :)"
  else
    mkdir -p "./reduced/$PGM"
    $SPARROW -insert_observe -imprecise $src -dir "./reduced/$PGM"

    # Reduce each copy in ./reduced/PGM
    if [ "$(ls -A ./reduced/$PGM)" ]; then
       for file in ./reduced/$PGM/*.c
       do
         NUM=`basename $file`
         ./run.sh $file $NCPU $SPARROW
         REDUCED_PGM="./reduced/$PGM/$NUM.reduced.c"
         cp reduce.c "$REDUCED_PGM"
       done
    else
      echo "No files to reduce :)"
    fi
  fi
done
