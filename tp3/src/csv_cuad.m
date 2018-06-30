A = csvread('matrixD.csv');
B = csvread('solucion.csv');
C = cuadrado_minimo(A,B);
csvwrite('resultado.csv',C);