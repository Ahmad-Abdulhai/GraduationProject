clear all
clc
%%%%%%%%%%%%%%%%
% SYSTEM PARAMETERS
%%%%%%%%%%%%%%%%
mc=1.12;
mp=0.11;
l=0.017;
g=9.81;
j=0.0136;
fp=0.000107443;
fc=0.05;
umax=17;
xmax=0.5;
a=l*l+j/(mc+mp);
mi=l*(mc+mp);
dzcv=0.0079311;
%%%%%%%%%%%%%%%%
% LINEAR STATE SPACE MODEL
%%%%%%%%%%%%%%%%
A=[0 0 1 0;0 0 0 1;0 0.6111 -34.9727 -0.001;0 43.4213 -145.7195 -0.0054];
B=[0;0;9.1803;-38.2514];
C=[1 0 0 0;0 1 0 0];
D=[0;0];
K=[-7.0711 -11.0166 2.0021 -1.2233];
%%%%%%%%%%%%%%%%%%%
% LINEAR TRANSFER FUNCTION
%%%%%%%%%%%%%%%%%%%
%s=tf('s');
%ht=minreal(tf(nums(2,:),den));
% %%%%%%%%%%%%%%%%%%%
% % PD CONTROLLER DESIGN
% %%%%%%%%%%%%%%%%%%%
% syms s k1 k2 k3 k4
% % POSISTION CONTROLLER k1+k2s
% n=k1+k2*s;
% m=1;
% b='0.8343';
% a=s^2+'0.04065'*s;
% acl=coeffs(collect(a*m+b*n,s),s);
% % z=.8; w=0.8;
% % acd=coeffs(collect((s^2+2*z*w*s+w^2),s),s);
% c=23;
% acd=coeffs(collect((s+c)^2,s),s);
% t1=acl(1)-acd(1);
% t2=acl(2)-acd(2);
% [k1,k2]=solve(t1,t2)
% % PENDULUM CONTROLLER k3+k4s
% n=k3+k4*s;
% m=1;
% b='1.25';
% a=s^2+'0.001063'*s-'15.08';
% acl=coeffs(collect(a*m+b*n,s),s);
% % z=1; w=1;
% % acd=coeffs(collect((s^2+2*z*w*s+w^2),s),s);
% c=30;
% acd=coeffs(collect((s+c)^2,s),s);
% t1=acl(1)-acd(1);
% t2=acl(2)-acd(2);
% [k3,k4]=solve(t1,t2);
% s=tf('s');
% htc=double(k3)+double(k4)*s
% 
% % syms k1 k2 k3 k4;
% % K=[k1 k2 k3 k4];
% % Ac=A+B*K;
% % syms z
% % adet=coeffs(det(z*eye(4)-Ac),z);
% % Ad=collect((z^2+1.727*z+7.42)^2,z);
% % ddet=coeffs(Ad,z)
