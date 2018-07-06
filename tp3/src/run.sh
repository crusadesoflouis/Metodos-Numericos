#!/bin/bash
opcion=0;
imagen=../imagenes/lena.pgm
reduciones=3;
./tp3 $opcion $reduciones $imagen
if [ $opcion = 0 ];
then
  #llamamos a octave
  octave --eval "csv_cuad(\"destino.csv\",\"tiempo.csv\")"
  #python ../imagenes/conversor_csv/csv_visualizer.py resultado_imagen.csv
  exit 0
else
  ./tp3 1 resultado_vector.csv resultado_vector_dimension.csv original_reducido.csv
  echo "pifiaste"
  exit 0
fi



#TODO iterar la opcion, iterar las imagenes, iterar las reducciones #parametros para densidad y distancia entre puntos
##para mas adelante variar el metodo de generacion de rectas con su tamanio
#para un tamaño fijo variar el tipo de ruido
