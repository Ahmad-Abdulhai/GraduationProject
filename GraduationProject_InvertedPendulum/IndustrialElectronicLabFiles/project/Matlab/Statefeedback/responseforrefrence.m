%Response to initial condition 
% this program obtains the step response of the system 
A=[0 0 1 0; 0 0 0 1; 0 0.25 -0.0417 0 ;0 15.03 -0.0625 0];
B=[0;0;0.82;1.24];C=[1 0 0 0 ];
D=[0];
K=[  -45.7776  130.2839  -30.7689   34.0233     ]
ki=- 41.6160;
AA=[A-B*K  B*ki;-C 0];
BB=[0;0;0;0;0.2];
CC=[C 0];
DD=[0];
t=0:0.02:6;
[y,x,t]=step(AA,BB,CC,DD,1,t);
plot(t,x)
grid;
title('Response curves x1,x2,x3,x4,x5 versus t')
xlabel('tsec')
ylabel('x1,x2,x3,x4,x5')
text(2,1,'x1')
text(1.4,0.1,'x2')
text(1.8,0.6,'x3')
text(1.3,0.3,'x4')
text(1.5,1.3,'x5')
x1=[1 0 0 0 0]*x';
x2=[0 1 0 0 0]*x';
x3=[0 0 1 0 0]*x';
x4=[0 0 0 1 0]*x';
x5=[0 0 0 0 1]*x';
%pole response currves x1 versus t x2 versus t x3 versus t and x4 versus t
%on diagram
%subplot(3,2,1)
plot(t,x1); grid
% title('x1 Displacement of Cart versus t')
% xlabel ('t sec')
% ylabel('x1')
% subplot(3,2,2)
% plot(t,x2); grid
% title('x2 theta versus t')
% xlabel ('t sec')
% ylabel('x2')
% 
% subplot(3,2,3)
% plot(t,x3); grid
% title('x3 velocity of Cart versus t')
% xlabel ('t sec')
% ylabel('x3')
% subplot(3,2,4)
% plot(t,x4); grid
% title('x1 theta dot versus t')
% xlabel ('t sec')
% ylabel('x4')
% subplot(3,2,5)
% plot(t,x5); grid
% title('x5  versus t')
% xlabel ('t sec')
% ylabel('x5')
