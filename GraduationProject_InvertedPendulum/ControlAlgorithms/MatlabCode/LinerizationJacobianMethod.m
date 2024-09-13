clear;clc;

%% declaration

syms t
syms x theta F dx dtheta
syms mc mp l g J fc fp

a = l^2+J/(mc+mp);
mu = l*(mc+mp);

%% state equations

ddx = (a*((F-fc*dx)-mu*dtheta^2*sin(theta))+l*cos(theta)*((mu*g*sin(theta)-fp*dtheta)))/(J+mu*l*sin(theta)^2);
ddtheta = (l*cos(theta)*(F-fc*dx-mu*dtheta^2*sin(theta))+mu*g*sin(theta)-fp*dtheta)/(J+mu*l*sin(theta)^2);

%% Jacobian

fx = simplify(jacobian([dx; dtheta; ddx; ddtheta], [x theta dx dtheta]));
fu = simplify(vf*jacobian([dx; dtheta; ddx; ddtheta], F));
hx = simplify(jacobian([x; theta], [x theta dx dtheta]));
hu = simplify(jacobian([x; theta], F);

%% initial conditions

x_t = 0;
theta_t = 0;
dx_t = 0;
dtheta_t = 0;
F_t = 0;

%% symbolic expression

fx = subs(fx, {x, theta, dx, dtheta, F}, {x_t, theta_t, dx_t, dtheta_t, F_t});
fu = subs(fu, {x, theta, dx, dtheta, F}, {x_t, theta_t, dx_t, dtheta_t, F_t});
hx = subs(hx, {x, theta, dx, dtheta, F}, {x_t, theta_t, dx_t, dtheta_t, F_t});
hu = subs(hu, {x, theta, dx, dtheta, F}, {x_t, theta_t, dx_t, dtheta_t, F_t});

%% After Adding s & vf

syms s M
vf = M/2.5; % Voltage to Motor Force ratio
fx(4,[2 3]) = s*fx(4,[2 3]);
fu(4) = s*fu(4);
fu = vf*fu;

%% For the nominal parameters of the cart–pendulum system

A = double(subs(fx, {mc, mp, l, g, J, fc, fp, M, s}, {1.12, 0.12, 0.033245968, 9.80665, 0.013935418, 2.53165, 0.000107443, 9.4, 1}));
B = double(subs(fu, {mc, mp, l, g, J, fc, fp, M, s}, {1.12, 0.12, 0.033245968, 9.80665, 0.013935418, 2.53165, 0.000107443, 9.4, 1}));
C = double(hx);
D = double(hu);

%% Analys

Sys = ss(A,B,C,D);
SysPole = pole(Sys);