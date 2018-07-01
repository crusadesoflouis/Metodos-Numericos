function ret = csv_cuad(A,B)
  tic
  C = cuadrado_minimo(A,B);
  n = sqrt(size(C)(1));
  D = reshape (C,n,n);
  D = D';
  uint8(D);
  csvwrite('resultado.csv',D);
  imwrite(D,"img_solucion",'gif');
  ret = 1
  toc
endfunction