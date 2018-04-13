#!/bin/sh
seq 0.01 0.01 1 | sed 's/,/./g' | while read p; do
	seq 1 1000 | while read dummy; do
		./src/tp1 matrices/matriz_lado250_densidad0.2_.txt $p >> salida150
	done
	echo $p
done
