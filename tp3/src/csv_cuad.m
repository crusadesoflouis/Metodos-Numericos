function ret = csv_cuad(a,b)
  tic
  % para ejecutar la funcion desde consola usar :
  % octave --eval "csv_cuad(\"destino.csv\",\"tiempo.csv\")"
  A = csvread(a);
  B = csvread(b);
  C = cuadrado_minimo(A,B);
  csvwrite('resultado_vector.csv',C);
  csvwrite('resultado_vector_dimension.csv',size(C)(1));
  n = sqrt(size(C)(1));
  D = reshape (C,n,n);
  D = D';
  uint8(D);
  csvwrite('resultado_imagen.csv',D);
  csvwrite('dimension_imagen.csv',n);
  ret = 1
  toc
endfunction
