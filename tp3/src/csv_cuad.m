function ret = csv_cuad(a,b)
  tic
  % para ejecutar la funcion desde consola usar : 
  % octave --eval "csv_cuad(\"destino.csv\",\"tiempo.csv\")"
  A = csvread(a);
  B = csvread(b);
  C = cuadrado_minimo(A,B);
  n = sqrt(size(C)(1));
  D = reshape (C,n,n);
  D = D';
  uint8(D);
  csvwrite('resultado.csv',D);
  csvwrite('dimension.csv',n);
  ret = 1
  toc
endfunction