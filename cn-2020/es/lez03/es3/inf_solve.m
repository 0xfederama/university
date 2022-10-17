function x=inf_solve(A,b)
% Risolve b=U*x con U triangolare inferiore
n=length(b);
x=zeros(n,1);
for i=1:n
    somma=0; % accumulatore
    for j=1:i-1
        somma=somma+A(i,j)*x(j);
    end
    x(i)=(b(i)-somma)/A(i,i);
end
end