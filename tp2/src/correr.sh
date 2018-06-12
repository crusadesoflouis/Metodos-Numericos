for k in $(seq 1 9); do
  echo k: $k
  for iteration in $(seq 1 10)
  do
    echo iteracion: $iteration
    train='k_'$k'_train_'$k'_it'$iteration'.csv'
    echo $train
    test='k_'$k'_test_'$((10-$k))'_it'$iteration'.csv'
    echo $test
    pred='k_'$k'_pred_'$((10-$k))'_it'$iteration'.csv'
    echo $pred
    ./tp2 -m 1 -i $train -q $test -o $pred $k
  done
done
