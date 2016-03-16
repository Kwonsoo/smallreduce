#!/bin/bash

RDIR=$1		# directory where the reduced files of a program exist.
MDIR=$2		# directory to which the reduced files will be moved.

for rfile in ${RDIR}*; do
	if [[ $rfile == *reduced.c ]]; then		
		IFS='/' read -ra FPATH <<< "$rfile"
		FNAME=pos_${FPATH[-2]}_${FPATH[-1]}
	
#mv $rfile $FNAME
#cp $FNAME $MDIR
		cp $rfile ${MDIR}/${FNAME}
	fi
done
