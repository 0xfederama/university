function y=mat_prod(c, b)
%Calcolo la fattorizzazione LU

n=legth(b);
somma=0;
y=zeros(n, 1);
for i=1:n-1
    y(i)=b(i)-b(i+1)/2;
    somma=somma+b(i);
end
y(n)=c*somma+b(n);

end