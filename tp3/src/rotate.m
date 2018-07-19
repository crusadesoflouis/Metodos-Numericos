A = [ 1 2 3 ; 4 5 6 ; 7 8 9];
B = eye(3);
C = ones(1,9);
for i = 1:3
  for j = 1:3
  B(j,4-i) = A(i,j);
  C(1,3*j + (4-i)) = A(i,j);
  endfor
endfor
A
B
C

#{
A = [ 1 2 3 ; 4 5 6 ; 7 8 9];
B = eye(3);
for i = 1:3
  for j = 1:3
  B(4-i,4-j) = A(i,j);
  endfor
endfor

B

A = [ 1 2 3 ; 4 5 6 ; 7 8 9];
B = eye(3);
for i = 1:3
  for j = 1:3
  B(4-j,i) = A(i,j);
  endfor
endfor

B

#}
