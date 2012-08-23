#poly=[1 -133 6729 -158379 1720294 -6823316];
poly=[1 1 3];
x=linspace(-10,10,1000);
y=polyval(poly,x);
#Legendre polynomials

p0=[1];
p1=[1,0];
p2=[1.5 0 -.5];
p3=[2.5 0 1.5 0];
p4=[4.375 0 -3.75 0 .375];
p5=[7.875 0 -8.75 0 1.875 0];
p6=[14.4375 0 -19.6875 0 6.5625 0 -.3125];

legendre={p0,p1,p2,p3,p4,p5,p6};

#polynomials end
poly2=[1];
count=0;
for n=legendre
	term=conv(poly,n{1});
	integral=polyint(term);
	polyout(integral)
	area=polyval(integral,1)-polyval(integral,-1);
	area
	c=[(count + .5)*area];
	c
	mult=conv(c,n{1});
	if (length(poly2)>length(mult))
		mult=[zeros(1,length(poly2)-length(mult)) mult];
	else
		poly2=[zeros(1,length(mult)-length(poly2)) poly2];
	endif;
	poly2=poly2+mult;
	count=count+1;
endfor;
poly2
polyout(poly2)
