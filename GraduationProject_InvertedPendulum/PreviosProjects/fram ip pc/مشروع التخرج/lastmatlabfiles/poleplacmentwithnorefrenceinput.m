% Design of an inverted pendulum control system 
%This program determine the state -feedback gain matrix 
A=[0 0 1 0; 0 0 0 1; 0 0.25 -0.0417 0 ;0 15.03 -0.0625 0];
B=[0;0;0.82;1.24];
C=[1 0 0 0 ; 0 1 0 0 ]
% define controllability matrix M and check its rank 
M=[B  A*B  A^2*B  A^3*B]
rank(M)
%ans=4
%since the rank of M is 4,the system is completely state controllable
%,hence arbitary pole placement is possible 

%obtain the coefficients of the characteristic polynomail [sI-A] this can be done
%by entering statemenet poly(A)
ja=poly(A)
a1=ja(2);a2=ja(3);a3=ja(4);a4=ja(5);
%define matrices w and T as follows 
w=[ a3 a2 a1 1; a2 a1 1 0; a1 1 0 0 ; 1 0 0 0]
T=M*w;
j=[-0.8638+2.5845i 0 0 0 ;0 -0.8638-2.5845i 0 0 ; 0 0 -0.8638+2.5845i 0 ; 0 0 0 -0.8638-2.5845i]
jj=poly(j)
aa1=jj(2);aa2=jj(3); aa3=jj(4); aa4=jj(5);
% state feedback gain matrix k can be given by 
k=[aa4-a4  aa3-a3  aa2-a2  aa1-a1 ]*(inv(T))


 