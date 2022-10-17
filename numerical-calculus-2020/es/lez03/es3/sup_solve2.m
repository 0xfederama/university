function x=sup_solve2(A, b)
%Implementazione di sup_solve in tempo lineare per sistemi bidiagonali
n=length(b);
x=zeros(n,1);
x(n)=A(n, n)/b(n);
for i=n-1:-1:1
    x(i)=(b(i)-(A(i, i+1)*x(i+1)))/A(i,i);
end
end