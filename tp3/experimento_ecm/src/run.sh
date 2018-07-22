make clean
make experimentos
rm *.pgm
rm ecm.txt
echo "Normal" >> ecm.txt
for i in $(seq 0 250 20000)
do
    # echo  $i
    echo "$i" >> ecm.txt
    echo "crear matrices destino y origen"
    ./experimentos 0 ../experimento/1.csv ../experimento/dim.csv 4 $i
    echo "calculando valor en octave"
    octave --eval "csv_cuad(\"destino.csv\",\"tiempos.csv\")"
    echo "fase final"
    ./experimentos 1 ../experimento/reducida.csv ../experimento/reducida_dim.csv resultado_imagen.csv dimension_imagen.csv >> ecm.txt
    mv 'visualizacion.pgm' 'normal_imagen_'$i'.pgm'
done

make clean
make experimentos2
echo "Uniforme" >> ecm.txt
for i in $(seq 0 250 20000)
do
    # echo  $i
    echo "$i" >> ecm.txt
    echo "crear matrices destino y origen"
    ./experimentos2 0 ../experimento/1.csv ../experimento/dim.csv 4 $i
    echo "calculando valor en octave"
    octave --eval "csv_cuad(\"destino.csv\",\"tiempos.csv\")"
    echo "fase final"
    ./experimentos2 1 ../experimento/reducida.csv ../experimento/reducida_dim.csv resultado_imagen.csv dimension_imagen.csv >> ecm.txt
    mv 'visualizacion.pgm' 'uniforme_imagen_'$i'.pgm'
done
