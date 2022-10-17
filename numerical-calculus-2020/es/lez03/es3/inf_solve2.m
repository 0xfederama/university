function x=inf_solve2(A, b)
%Implementazione di inf_solve in tempo lineare per sistemi bidiagonali
n=length(b);
x=zeros(n,1);
x(1)=A(1, 1)/b(1);
for i=2:n
    x(i)=(b(i)-(A(i, i-1)*x(i-1)))/A(i,i);
end
end