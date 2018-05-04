echo "" > test.csv
find ../datosEntrenamiento/ImagenesCaras -type f | while read directorioActual;do
	id=`echo "$directorioActual" | cut -d '/' -f 4 | sed 's/s//g'`
	echo $directorioActual", "$id",">> test.csv
done

sed -i '/^$/d' test.csv
