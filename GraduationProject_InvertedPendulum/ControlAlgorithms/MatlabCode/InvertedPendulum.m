function x = InvertedPendulum(x,u)
% sampling time (sec)
dt = 0.01;

% dynamic equations
x_k = x(3);
o_k = x(4);
v_k = (a*((vf*u-fc*v_k_1)-mu*w_k_1^2*sin(o_k_1))+l*cos(o_k_1)*((mu*g*sin(o_k_1)-fp*w_k_1)))/(J+mu*l*sin(o_k_1)^2);
w_k = (l*cos(o_k_1)*(vf*u-fc*v_k_1-mu*w_k_1^2*sin(o_k_1))+mu*g*sin(o_k_1)-fp*w_k_1)/(J+mu*l*sin(o_k_1)^2);

x = x + [x_k; o_k; v_k; w_k]*dt;
end