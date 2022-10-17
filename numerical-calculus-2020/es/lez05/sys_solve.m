function x=sys_solve(c, b)
%

n=length(b);
x=zeros(n, 1);

%Ly=b
y(1:n-1)=b(1:n-1);
prodottoscalare=ps(c, y(1:n-1));
%L(n, 1:n-1)*y(1:n-1)

y(n)=b(n)-prodottoscalare;

%Ux=y

end