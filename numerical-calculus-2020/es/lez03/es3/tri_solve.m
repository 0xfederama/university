function x=tri_solve(alfa, beta, gamma, b)
%Risolve tridiagonale   
n=legth(b);
a=ones(n);
c=ones(n);
a(1)=alfa(1);
for i=1:n-1
    c(i)=beta(i)/alfa(i);
    a(i+1)=alfa(i+1)-c(i)*gamma(i);
end
L=eye(n)+diag(c, -1);
U=diag(a)+diag(gamma, 1);
y=inf_solve(L, b);
x=sup_solve(U, y);
end