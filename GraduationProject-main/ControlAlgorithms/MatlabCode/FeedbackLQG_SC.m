clear;clc;

mc = 1.12;
mpw = 0.095;
mps = 0.025;
l = 0.347;
fc = 2.53165;
fp = 0.000107443;
J = 0.0135735;
g = 9.81;
mp = mpw + mps;
a = l^2 + J/(mc + mp);
mu = (mc + mp)*l;

A = [0          0              1               0;
     0          0              0               1;
     0      (l*mu*g)/J    -(a*fc)/J    -(l*fp)/J;
     0      (mu*g)/J      -(l*fc)/J     -(fp)/J];
 
B = [          0;
               0;
             a/J;
            l/J];
  
C = [1 0 0 0];
 
D = [0];
 
Q = diag([0 6000 100 1000 10000]);
R = 20;

[K, S, e] = lqi(ss(A,B,C,D),Q,R)

% C = [1 0 0 0;
%      0 1 0 0];
%  
% D = [0;
%      0];
% 
% G = eye(4);
% 
% H = eye(2);
% 
% sys = ss(A,[B G zeros(4,2)],C,[D zeros(2,4) H]);
% Qn = diag([1 1 1 1]);
% Rn = diag([1 1]);
% 
% [kalmf,L,P,M] = kalman(sys,Qn,Rn)
% 
% trksys = lqgtrack(kalmf,K)