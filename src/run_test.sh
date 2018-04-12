for i in $(seq 50 50 1500)
do
	echo $i >>out.txt
	for j in 0.05 0.1 0.2 0.3
	do
		a='./tp1 ../matrices/matriz_lado'$i'_densidad'$j'_.txt 0.5'
		A='../matrices/matriz_lado'$i'_densidad'$j'_.txt'
		sed -n '2p' < $A >>out.txt
		echo $j >>out.txt
		for k in 1 2 3 4 5 6 7 8 9 10
		do
	  	$a>> out.txt
		done
	done
done
