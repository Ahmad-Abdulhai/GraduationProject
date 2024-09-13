clear; clc;

%% declaration

syms t
syms x theta F dx dtheta ddx ddtheta
syms mc mp l g J fc fp

a = l^2+J/(mc+mp);
mu = l*(mc+mp);

%% state equations after Linearization

eqn(1) = ddx == (a*(F-fc*dx)+l*(mu*g*theta-fp*dtheta))/(J);
eqn(2) = ddtheta == (l*(F-fc*dx)+mu*g*theta-fp*dtheta)/(J);

%% Linearization

eqn(1) = isolate(eqn(1),a*F);
eqn(2) = isolate(eqn(2),l*F);

%% Laplace Transformation

G = laplace(eqn);

%% Fixed

% ddP_2 = isolate(eqn(2), diff(p,2));
% ddTheta_2 = isolate(eqn(2), diff(theta,2));
% eqn1 = subs(eqn, diff(p,2), ddP_2);
% eqn2 = subs(eqn, diff(theta,2), ddTheta_2);
% ddP = isolate(eqn2 );