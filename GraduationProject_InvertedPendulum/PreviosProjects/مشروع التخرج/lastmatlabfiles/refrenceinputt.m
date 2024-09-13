% Design of an inverted pendulum control system 
%This program determine the state -feedback gain matrix K=[k1 k2 k3 k4] and
%integral gain matrix Ki
%enter matrices A, B, C, 
A=[0 0 1 0; 0 0 0 1; 0 0.25 -0.0417 0 ;0 15.03 -0.0625 0];
B=[0;0;0.82;1.24];
C=[1 0 0 0 ]
%***Enter matrices A1 and B1***
A1=[A zeros(4,1);-C 0]
B1=[B;0]
%***Define the controllability matrix M***
M=[B1  A1*B1  A1^2*B1  A1^3*B1 A1^4*B1]
rank(M)
%ans=5
%since the rank of M is 5,the system is completely state controllable
%,hence arbitary pole placement is possible
ja=poly(A1)
a1=ja(2);a2=ja(3);a3=ja(4);a4=ja(5);a5=ja(6);
%define matrices w and T as follows 
w=[ a4 a3 a2 a1 1;a3 a2 a1 1 0; a2 a1 1 0 0; a1 1 0 0 0; 1 0 0 0 0]
T=M*w
j=[-1+sqrt(3)*i 0 0 0 0;0 -1-sqrt(3)*i 0 0 0; 0 0 -5 0 0; 0 0 0 -5 0; 0 0 0 0 -5 ];
jj=poly(j)
aa1=jj(2);aa2=jj(3); aa3=jj(4); aa4=jj(5);aa5=jj(6);
% state feedback gain matrix k can be given by 
k=[ aa5-a5  aa4-a4  aa3-a3  aa2-a2  aa1-a1 ]*(inv(T))

