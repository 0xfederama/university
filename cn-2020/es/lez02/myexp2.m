function a = myexp2(x,n)
%implementazione dell'esponenziale con il polinomio di taylor 
%  arrestato al termine n-esimo
t=1;
a=1;
if x>=0
    for k=1:n
        t=t*x/k;
        a=a+t;
    end
else 
    for k=1:n
        t=t*(-x)/k;
        a=a+t;
    end
    a=1/a;
end
%adesso s vale exp
end