

# ./tp2 -m 0 -i 5_elements_0.csv -q 5_elements_1.csv -o salida.csv


verdadero=`cut -d ',' -f 2 5_elements_1.csv`
predicho=`cut -d ',' -f 2 salida.csv`
