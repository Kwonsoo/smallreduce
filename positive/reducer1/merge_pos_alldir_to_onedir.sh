#!/bin/bash

RDIR=$1		# directory where many reduced directories exist
MDIR=$2		# directory to which the reduced files will be moved.

for rdir in $RDIR*; do
		if [[ -d "$rdir" && ! -L "$rdir" ]]; then
				for rfile in ${rdir}/*; do
						if [[ $rfile == *reduced.c ]]; then
								IFS='/' read -ra FPATH <<< "$rfile"
								FNAME=pos_${FPATH[-2]}_${FPATH[-1]}
								cp $rfile ${MDIR}/${FNAME}
						fi
				done
		fi
done
