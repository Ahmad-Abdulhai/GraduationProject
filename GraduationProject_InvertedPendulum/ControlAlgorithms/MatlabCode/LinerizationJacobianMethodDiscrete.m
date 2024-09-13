clear;clc;

%% declaration

syms t Ts
syms x_k o_k v_k w_k
syms x_k_1 o_k_1 v_k_1 w_k_1
syms F vf u
syms mc mp l g J fc fp a mu

% a = l^2+J/(mc+mp);
% mu = l*(mc+mp);

%% state equations

x_k = Ts*v_k_1 + x_k_1;
o_k = Ts*w_k_1 + o_k_1;
v_k = Ts*(a*((vf*u-fc*v_k_1)-mu*w_k_1^2*sin(o_k_1))+l*cos(o_k_1)*((mu*g*sin(o_k_1)-fp*w_k_1)))/(J+mu*l*sin(o_k_1)^2) + v_k_1;
w_k = Ts*(l*cos(o_k_1)*(vf*u-fc*v_k_1-mu*w_k_1^2*sin(o_k_1))+mu*g*sin(o_k_1)-fp*w_k_1)/(J+mu*l*sin(o_k_1)^2) + w_k_1;

%% Jacobian

fx = jacobian([x_k; o_k; v_k; w_k], [x_k_1 o_k_1 v_k_1 w_k_1]);
fu = jacobian([x_k; o_k; v_k; w_k], u);
hx = jacobian([x_k], [x_k_1 o_k_1 v_k_1 w_k_1]);
hu = jacobian([x_k], u);

%% Simplifiy

sfxd = simplify(subs(fx, {l*mu*sin(o_k_1)^2 + J, cos(o_k_1)*sin(o_k_1)}, {J, (sin(2*o_k_1)/2)}));
sfud = simplify(subs(fu, {l*mu*sin(o_k_1)^2 + J, cos(o_k_1)*sin(o_k_1)}, {J, (sin(2*o_k_1)/2)}));

sfxd2 = simplify(fx)
sfud2 = simplify(fu)

% -----------------------------------------------------------------------------end
% Run section
%% initial conditions

% x_t = 0;
% theta_t = 0;
% dx_t = 0;
% dtheta_t = 0;
% F_t = 0;

%% symbolic expression

% fx = subs(fx, {x, o_k_1, v_k_1, w_k_1, F}, {x_t, theta_t, dx_t, dtheta_t, F_t});
% fu = subs(fu, {x, o_k_1, v_k_1, w_k_1, F}, {x_t, theta_t, dx_t, dtheta_t, F_t});
% hx = subs(hx, {x, o_k_1, v_k_1, w_k_1, F}, {x_t, theta_t, dx_t, dtheta_t, F_t});
% hu = subs(hu, {x, o_k_1, v_k_1, w_k_1, F}, {x_t, theta_t, dx_t, dtheta_t, F_t});

%% After Adding s & vf

% syms s M
% vf = M/2.5; % Voltage to Motor Force ratio
% fx(4,[2 3]) = s*fx(4,[2 3]);
% fu(4) = s*fu(4);
% fu = vf*fu;

%% For the nominal parameters of the cart–pendulum system

% A = double(subs(fx, {mc, mp, l, g, J, fc, fp, M, s}, {1.12, 0.12, 0.033245968, 9.80665, 0.013935418, 2.53165, 0.000107443, 9.4, 1}));
% B = double(subs(fu, {mc, mp, l, g, J, fc, fp, M, s}, {1.12, 0.12, 0.033245968, 9.80665, 0.013935418, 2.53165, 0.000107443, 9.4, 1}));
% C = double(hx);
% D = double(hu);

%% Analys

% Sys = ss(A,B,C,D);
% SysPole = pole(Sys);