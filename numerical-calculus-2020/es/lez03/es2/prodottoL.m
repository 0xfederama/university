function [y]=prodottoL(b)
%dato il vettore b calcola y=Lb in O(n^2)
len=length(b);
if (iscolumn(b))
    x=b;
else
    x=b';
end
L=laplace(len);
y=L*x;
end