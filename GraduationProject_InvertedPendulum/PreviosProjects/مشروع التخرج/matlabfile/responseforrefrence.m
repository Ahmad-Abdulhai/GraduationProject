%Response to initial condition 
% this program obtains the step response of the system 
A=[0 0 1 0; 0 0 0 1; 0 -0.25 0 0 ;0 -15.03 0 0]
B=[0;0;0.82;1.24]
C=[1 0 0 0 ];
D=[0];
K=[45.7776   45.5099   25.0424   -2.8506  ]
ki=41.6160;
AA=[A-B*K  B*ki;-C 0];
BB=[0;0;0;0;1];
CC=[C 0];
DD=[0];
t=0:0.02:6;
[y,x,t]=step(AA,BB,CC,DD,1,t);
x1=[1 0 0 0 0]*x';
x2=[0 1 0 0 0]*x';
x3=[0 0 1 0 0]*x';
x4=[0 0 0 1 0]*x';
x5=[0 0 0 0 1]*x';
%pole response currves x1 versus t x2 versus t x3 versus t and x4 versus t
%on diagram
subplot(3,2,1)
plot(t,x1); grid
title('x1 Displacement of Cart versus t')
xlabel ('t sec')
ylabel('x1')
subplot(3,2,2)
plot(t,x2); grid
title('x2 theta versus t')
xlabel ('t sec')
ylabel('x2')

subplot(3,2,3)
plot(t,x3); grid
title('x3 velocity of Cart versus t')
xlabel ('t sec')
ylabel('x3')
subplot(3,2,4)
plot(t,x4); grid
title('x1 theta dot versus t')
xlabel ('t sec')
ylabel('x4')
subplot(3,2,5)
plot(t,x5); grid
title('x5  versus t')
xlabel ('t sec')
ylabel('x5')
