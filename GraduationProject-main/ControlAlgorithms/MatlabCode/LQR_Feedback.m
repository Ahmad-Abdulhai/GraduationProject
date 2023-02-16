%% Inverted Pendulum: State-Space Methods for Controller Design
% The design criteria for this system for a 0.2-m step in desired cart
% position x are as follows:
% 
% Settling time for x and theta of less than 5 seconds
% Rise time for x of less than 0.5 seconds
% Pendulum angle theta never more than 20 degrees (0.35 radians) from the
% vertical
% Steady-state error of less than 2% for x and theta

disp('Inverted Pendulum: State-Space Methods for Controller Design')
clear;clc;

%% Open-loop poles
%The first step in designing a full-state feedback controller is to
%determine the open-loop poles of the system.

disp('Open-loop poles')
mc = 1.12;
mpw = 0.095;
mps = 0.025;
l = 0.0167903; % lco = 0.347;
fc = 2.53165; % FS = 2.53165; FC = 2.28133
fp = 0.000107443;
J = 0.0135735;
g = 9.81;
vf = 17.463/2.5; %Voltage to Motor Force ratio
mp = mpw + mps;
a = l^2 + J/(mc + mp);
mu = (mc + mp)*l;

% theta 0 in upward position
% theta pi in downward position
s = 1; % 1 when upward  -1 when downward

A = [0          0              1               0;
     0          0              0               1;
     0      (l*mu*g)/J    -(a*fc)/J    -(l*fp)/J;
     0      s*(mu*g)/J    -s*(l*fc)/J    -(fp)/J];
 
B = [         0;
              0;
       (vf*a)/J;
      (s*vf*l)/J];
  
C = [1 0 0 0;
     0 1 0 0];
D = [0;
     0];

states = {'x' 'phi' 'x_dot' 'phi_dot'};
inputs = {'u'};
outputs = {'x'; 'phi'};

sys_ss = ss(A,B,C,D,'statename',states,'inputname',inputs,'outputname',outputs)

poles = eig(A)

%% Linear Quadratic Regulation (LQR)
% Before we design our controller, we will first verify that the system is
% controllable.

disp('Linear Quadratic Regulation (LQR)')
co = ctrb(sys_ss);
controllability = rank(co)

% Specifically, we will use the linear quadratic regulation method for
% determining our state-feedback control gain matrix K.
% The controller can be tuned by changing the nonzero elements in the Q
% matrix to achieve a desirable response.

Q = C'*C

% We will go ahead and find the $K$ matrix and plot the response all in one
% step so that changes can be made in the control and seen automatically in
% the response.

R = 1
[K, S, e] = lqr(A,B,Q,R)

Ac = [(A-B*K)];
Bc = [B];
Cc = [C];
Dc = [D];

sys_cl = ss(Ac,Bc,Cc,Dc,'statename',states,'inputname',inputs,'outputname',outputs)

t = 0:0.01:6;
r =0.2*ones(size(t)); % 20cm reference
[y,t,x]=lsim(sys_cl,r,t); 
subplot(2,2,1)
[AX,H1,H2] = plotyy(t,y(:,1),t,y(:,2),'plot');
set(get(AX(1),'Ylabel'),'String','cart position (m)')
set(get(AX(2),'Ylabel'),'String','pendulum angle (radians)')
title('Step Response with LQR Control')

% you are putting more weight on the errors at the cost of increased
% control effort u.

disp('putting more weight')
Q = diag([10000, 1000, 100, 1000])
%Q = diag([50, 100, 1, 1])
R = 20; %270;
[K, S, e] = lqr(A,B,Q,R)

Ac = [(A-B*K)];

sys_cl = ss(Ac,Bc,Cc,Dc,'statename',states,'inputname',inputs,'outputname',outputs)

[y,t,x]=lsim(sys_cl,r,t);
subplot(2,2,2)
[AX,H1,H2] = plotyy(t,y(:,1),t,y(:,2),'plot');
set(get(AX(1),'Ylabel'),'String','cart position (m)')
set(get(AX(2),'Ylabel'),'String','pendulum angle (radians)')
title('Step Response with LQR Control')

%% Adding precompensation
% if there are errors in the model (or unknown disturbances) the
% precompensator will not correct for them and there will be steady-state
% error.

disp('Adding precompensation')
Cn = [1 0 0 0];
sys_ss = ss(A,B,Cn,0);
Nbar = rscale(sys_ss,K)

sys_cl = ss(Ac,Bc*Nbar,Cc,Dc,'statename',states,'inputname',inputs,'outputname',outputs)

[y,t,x]=lsim(sys_cl,r,t);
subplot(2,2,3)
[AX,H1,H2] = plotyy(t,y(:,1),t,y(:,2),'plot');
set(get(AX(1),'Ylabel'),'String','cart position (m)')
set(get(AX(2),'Ylabel'),'String','pendulum angle (radians)')
title('Step Response with Precompensation and LQR Control')

%% Observer-based control
% The response achieved above is good, but was based on the assumption of
% full-state feedback, which is not necessarily valid. To address the
% situation where not all state variables are measured, a state estimator
% must be designed.

% Before we design our estimator, we will first verify that our system is
% observable.

disp('Observer-based control')
ob = obsv(sys_ss);
observability = rank(ob)

% Based on this logic, we must first find the controller poles.

poles = eig(Ac)

% we can use the same commands for finding the estimator gain L as we can
% for finding the state-feedback gain K.

P = [-40 -41 -42 -43];
L = place(A',C',P)'

% Now we will combine our state-feedback controller from before with our
% state estimator to get the full compensator.

Ace = [(A-B*K) (B*K);
       zeros(size(A)) (A-L*C)];
Bce = [B*Nbar;
       zeros(size(B))];
Cce = [Cc zeros(size(Cc))];
Dce = [0;0];

states = {'x' 'x_dot' 'phi' 'phi_dot' 'e1' 'e2' 'e3' 'e4'};
inputs = {'r'};
outputs = {'x'; 'phi'};

sys_est_cl = ss(Ace,Bce,Cce,Dce,'statename',states,'inputname',inputs,'outputname',outputs)

t = 0:0.01:6;
r = 0.2*ones(size(t));
[y,t,x]=lsim(sys_est_cl,r,t);
subplot(2,2,4)
[AX,H1,H2] = plotyy(t,y(:,1),t,y(:,2),'plot');
set(get(AX(1),'Ylabel'),'String','cart position (m)')
set(get(AX(2),'Ylabel'),'String','pendulum angle (radians)')
title('Step Response with Observer-Based State-Feedback Control')

% This response is almost identical to the response achieved when it was
% assumed that we had full access to the state variables. This is because
% the observer poles are fast, and because the model we assumed for the
% observer is identical to the model of the actual plant (including the
% same initial conditions). Therefore, all of the design requirements have
% been met with the minimal control effort expended. No further iteration
% is needed.