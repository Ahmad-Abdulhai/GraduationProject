clear;clc;

mc = 1.12;
mpw = 0.095;
mps = 0.025;
l = 0.033245968;
fc = 2.53165;
fp = 0.000107443;
J = 0.013935418;
g = 9.81;
vf = 9.4/2.5;
mp = mpw + mps;
a = l^2 + J/(mc + mp);
mu = (mc + mp)*l;
s = 1;

A = [0          0              1               0;
     0          0              0               1;
     0      (l*mu*g)/J    -(a*fc)/J    -(l*fp)/J;
     0      s*(mu*g)/J    -s*(l*fc)/J     -(fp)/J];
 
B = [          0;
               0;
        (vf*a)/J;
     (s*vf*l)/J];
  
C = [1 0 0 0];
 
D = [0];
 
Q = diag([20000 1000 20 1 4000]);
R = 10;
[K, S, e] = lqi(ss(A,B,C,D),Q,R);

% C = [1 0 0 0];
%  
% D = [0];
% 
% G = eye(4);
% 
% H = eye(1);
% 
% sys = ss(A,[B G zeros(4,1)],C,[D zeros(1,4) H]);
% Qn = diag([1 1 1 1]);
% Rn = diag([1 1]);
% 
% [kalmf,L,P,M] = kalman(sys,Qn,Rn)
% 
% trksys = lqgtrack(kalmf,K)