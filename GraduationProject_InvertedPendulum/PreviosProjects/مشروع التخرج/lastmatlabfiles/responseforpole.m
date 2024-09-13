%Response to initial condition 
% this program obtains the response of the system 
A=[0 0 1 0; 0 0 0 1; 0 0.25 -0.0417 0 ;0 15.03 -0.0625 0];
B=[0;0;0.82;1.24];
K=[ -4.5896   29.5385   -2.1853    4.1979]
AA=A-B*K;
BB=[0.1;0;0;0]
[x,z,t]=step(AA,BB,AA,BB);
x1=[1 0 0 0]*x';
x2=[0 1 0 0]*x';
x3=[0 0 1 0]*x';
x4=[0 0 0 1]*x';
%pole response currves x1 versus t x2 versus t x3 versus t and x4 versus t
%on diagram
subplot(2,2,1)
plot(t,x1); grid
title('x1 Displacement of Cart versus t')
xlabel ('t sec')
ylabel('x1')
subplot(2,2,2)
plot(t,x2); grid
title('x2 theta versus t')
xlabel ('t sec')
ylabel('x2')

subplot(2,2,3)
plot(t,x3); grid
title('x3 velocity of Cart versus t')
xlabel ('t sec')
ylabel('x3')
subplot(2,2,4)
plot(t,x4); grid
title('x1 theta dot versus t')
xlabel ('t sec')
ylabel('x4')
