function ris=solve2(a, b, c)
%Risolve l'equazione di secondo grado ax^2+bx+c=0
%Calcolo il determinante e risolvo con la classica formula
det=sqrt(pow2(b)-(4*a*c));
ris1=(-b+det)/(2*a);
ris2=(-b-det)/(2*a);
ris=[ris1;ris2];
end

