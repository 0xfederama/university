function [y]=prodottoL2(b)
%dato il vettore b calcola y=Lb in O(n)
len=length(b);
y=zeros(len, 1);
y(1)=2*b(1)+(-1)*b(2);
for k=2:(len-1)
    y(k)=(-1)*b(k-1)+2*b(k)+(-1)*b(k+1);
end
y(len)=(-1)*b(len-1)+2*b(len);
end