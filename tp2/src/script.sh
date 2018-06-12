echo "" > testRed.csv
find ../datosEntrenamiento/ImagenesCarasRed -type f | while read directorioActual;do
	id=`echo "$directorioActual" | cut -d '/' -f 4 | sed 's/s//g'`
	echo $directorioActual", "$id",">> testRed.csv
done

sed -i '/^$/d' test.csv
