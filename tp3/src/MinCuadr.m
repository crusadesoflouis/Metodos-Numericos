function ret = MinCuadr(U,V,S,b)
    tic
     ret = zeros((size(S)(2)),1);
     A = U';
    for i = 1:rank(S)
      x = A(i,:)*b;
      x = x/S(i,i);
      ret = ret + (V(:,i)*x);
    endfor 
    toc
endfunction

