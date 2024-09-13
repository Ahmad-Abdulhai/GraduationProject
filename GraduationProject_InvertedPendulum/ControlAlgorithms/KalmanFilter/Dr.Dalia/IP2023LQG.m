syms x m M L g d u v w o tsam
D = m*L*L*(M+m*(1-cos(o)^2));
dx = tsam*v+x;
dv = tsam*((1/D)*(-m^2*L^2*g*cos(o)*sin(o)+m*L^2*(m*L*w^2*sin(o)-d*v))+m*L*L*(1/D)*u)+v;
do = tsam*w+o;
dw = tsam*((1/D)*((m+M)*m*g*L*sin(o)-m*L*cos(o)*(m*L*w^2*sin(o)-d*v))-m*L*cos(o)*(1/D)*u)+w;


j11=simplify(jacobian(dx,x))
j12=simplify(jacobian(dx,v))
j13=simplify(jacobian(dx,o))
j14=simplify(jacobian(dx,w))

j21=simplify(jacobian(dv,x))
j22=simplify(jacobian(dv,v))
j23=simplify(jacobian(dv,o))
j24=simplify(jacobian(dv,w))

j31=simplify(jacobian(do,x))
j32=simplify(jacobian(do,v))
j33=simplify(jacobian(do,o))
j34=simplify(jacobian(do,w))

j41=simplify(jacobian(dw,x))
j42=simplify(jacobian(dw,v))
j43=simplify(jacobian(dw,o))
j44=simplify(jacobian(dw,w))