#!/bin/bash

for i in $(seq 1 9)
do
   for j in $(seq 1 9)
   do
     echo "i $i"
      echo "j $j"
      ./experimentos 2.pgm 3 $i $j
      echo "octave"
      octave --eval "csv_cuad(\"destino.csv\",\"tiempos.csv\")"
      mv 'resultado_imagen.csv' 'imagen_'$i'_'$j'.csv'
   done
done
