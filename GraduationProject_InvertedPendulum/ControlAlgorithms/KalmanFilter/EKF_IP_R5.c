/*
 * Copyright (c) by University of Aleppo
 * All Rights Reserved
 * Saturday-2-2-2013
 * Dalia Kass Hanna
 */

#define S_FUNCTION_NAME EKF_IP

#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "simstruc.h"

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

/*
 * Input arguments
 */

#define SAMPLE_TIME_ARG			ssGetArg(S,0)

#define NUMBER_OF_ARGS			(1)

#define NSAMPLE_TIMES			(1)

#define NUMBER_OF_INPUTS		(3)

#define NUMBER_OF_OUTPUTS		(4)

/*
 * mdlInitializeSizes - initialize the sizes array
 *
 * The sizes array is used by SIMULINK to determine the S-function block's
 * characteristics (number of inputs, outputs, states, etc.).
 */

// Variables
double Xes[4]; // [X_es, o_k_1_es, v_k_1_es, w_k_1_es]
double Xprd[4]; // [X_prd, o_k_1_prd, v_k_1_prd, w_k_1_prd]

// nonlinStates inputs & outputs
double x_k, o_k, v_k, w_k;
double x_k_1, o_k_1, v_k_1, w_k_1, Uv, x_m, v_m;

// Cumputation Matrixes
double tsam; // constatnts
//    double  Ad[4][3],Bd[3][1],C[1][3],
double Pk_k[4][4],Q[4][4],R[2][2];
double fx_k[4][4],fu_k[4][1],Pk_1_k[4][4],fx_k_T[4][4],fu_k_T[1][4];
double K_g[4][2],H[2][4],H_T[4][2];
double Pk_H_T[4][2]; //P(k+1)H'
double H_Pk_H_T[2][2];//HP(k+1)H'
double fx_P[4][4], fu_q[4][1],PK_1_K_1[4][4];   //JP(k)
double fx_P_fx[4][4], fu_q_fu[4][4], HPH_R[2][2], HPH_R_inv[2][2]; //JP(k)J'
double I_eye[4][4],K_g_H[4][4];
double I_K_g_H[4][4];

//     ???????????????????????????????????????????????????????????????????????????
//     float  sgn;
//     ???????????????????????????????????????????????????????????????????????????

double x_es_k[4]; // estimated state

int    i,j,k;
double  mc, mpw, mps, l, fc , fp, J, g, vf, mp, a, mu, errorx, errorv, sum, del;

static void mdlInitializeSizes(SimStruct *S)
{
    if (ssGetNumArgs(S) != NUMBER_OF_ARGS) {
#ifdef MATLAB_MEX_FILE
	mexErrMsgTxt("Wrong number of input arguments passed.\nThree arguments are expected\n");
#endif
    }

	/* Set up size information */
    ssSetNumContStates(    S, 0);      /* number of continuous states */
    ssSetNumDiscStates(    S, 4);      /* number of discrete states */
    ssSetNumInputs(        S, NUMBER_OF_INPUTS);      /* number of inputs */
    ssSetNumOutputs(       S, NUMBER_OF_OUTPUTS);      /* number of outputs */
    ssSetDirectFeedThrough(S, 1);      /* direct feedthrough flag */
    ssSetNumSampleTimes(   S, NSAMPLE_TIMES);      /* number of sample times */
    ssSetNumInputArgs(     S, NUMBER_OF_ARGS);      /* number of input arguments */
    ssSetNumRWork(         S, 0);      /* number of real work vector elements */
    ssSetNumIWork(         S, 0); 	   /* NUMBER_OF_IWORKS);      /* number of integer work vector elements */
    ssSetNumPWork(         S, 0);      /* number of pointer work vector elements */
}

/*
 * mdlInitializeSampleTimes - initialize the sample times array
 *
 * This function is used to specify the sample time(s) for your S-function.
 * If your S-function is continuous, you must specify a sample time of 0.0.
 * Sample times must be registered in ascending order.  If your S-function
 * is to acquire the sample time of the block that is driving it, you must
 * specify the sample time to be INHERITED_SAMPLE_TIME.
 */

static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTimeEvent(S, 0, mxGetPr(SAMPLE_TIME_ARG)[0]);
    ssSetOffsetTimeEvent(S, 0, 0.0);
}

/*
 * mdlInitializeConditions - initialize the states
 *
 * In this function, you should initialize the continuous and discrete
 * states for your S-function block.  The initial states are placed
 * in the x0 variable.  You can also perform any other initialization
 * activities that your S-function may require.
 */

static void mdlInitializeConditions(double *x0, SimStruct *S)
{

	tsam = mxGetPr(SAMPLE_TIME_ARG)[0];		 /*Sampling Time*/

/* States initialization*/

// System Parameters
    mc = 1.12; // Cart mass
    mpw = 0.095; // Pendulum wight mass
    mps = 0.025; // Pendulum stick mass
    l = 0.033245968; // rotation axes to CoM Length
    fc = 2.53165; // Cart friction
    fp = 0.000107443; // Pendulum damping cofficient
    J = 0.013935418; // moment of Inertia
    g = 9.81; // Gravetational acceleration
    vf = 9.4/2.5; // Voltage to Motor Force ratio
    mp = mpw + mps;
    a = pow(l,2) + J/(mc + mp);
    mu = (mc + mp)*l;

    sum = 0.0;
    del=0.001;


Pk_k[0][0]=100;///100;  //  related to ia
Pk_k[0][1]=0.0;
Pk_k[0][2]=0.0;
Pk_k[0][3]=0.0;

Pk_k[1][0]=0.0;
Pk_k[1][1]=100;////100;       related to Wr
Pk_k[1][2]=0.0;
Pk_k[1][3]=0.0;

Pk_k[2][0]=0.0;
Pk_k[2][1]=0.0;////100;       related to Wr
Pk_k[2][2]=100;
Pk_k[2][3]=0.0;

Pk_k[3][0]=0.0;
Pk_k[3][1]=0.0;////100;       related to Wr
Pk_k[3][2]=0.0;
Pk_k[3][3]=100;

R[0][0]=1e-05; R[0][1]=0.0;
R[1][0]=0.0;   R[1][1]=1e-03;

Q[0][0]=1e-02; Q[0][1]=0; Q[0][2]=0; Q[0][3]=0;
Q[1][0]=0; Q[1][1]=40; Q[1][2]=0; Q[1][3]=0;
Q[2][0]=0; Q[2][1]=0; Q[2][2]=1e-03; Q[2][3]=0;
Q[3][0]=0; Q[3][1]=0; Q[3][2]=0; Q[3][3]=35;

//////////////////I_eye(2,2)///////

I_eye[0][0]=1;
I_eye[0][1]=0;
I_eye[0][2]=0;
I_eye[0][2]=0;
I_eye[1][0]=0;
I_eye[1][1]=1;
I_eye[1][2]=0;
I_eye[1][2]=0;
I_eye[2][0]=0;
I_eye[2][1]=0;
I_eye[2][2]=1;
I_eye[2][2]=0;
I_eye[3][0]=0;
I_eye[3][1]=0;
I_eye[3][2]=0;
I_eye[3][3]=1;

///////////////////////////////

x_es_k[0]=0.0;
x_es_k[1]=0.0;
x_es_k[2]=0.0;
x_es_k[3]=0.0;

}

/*
 * mdlOutputs - compute the outputs
 *
 * In this function, you compute the outputs of your S-function
 * block.  The outputs are placed in the y variable.
 */

static void mdlOutputs(double *y, double *x, double *u, SimStruct *S, int tid)
{
//???????????????????????????????????????????????????????????????????????????
y[0]=x_es_k[0];
y[1]=x_es_k[1];
y[2]=x_es_k[2];
y[3]=x_es_k[3];

//???????????????????????????????????????????????????????????????????????????
}

/*
 * mdlUpdate - perform action at major integration time step
 *
 * This function is called once for every major integration time step.
 * Discrete states are typically updated here, but this function is useful
 * for performing any tasks that should only take place once per integration
 * step.
 */

static void mdlUpdate(double *x, double *u, SimStruct *S, int tid)
{
    {

Uv = u[0];
x_m = u[1];
v_m = u[2];

////////////Transition Matrix Ad////////////
//tsam=10e-6;
// Ad[0][0]=1-((x_es_k[2]*tsam)/La);
// Ad[0][1]=-(Kt*tsam)/La;
// Ad[0][2]=0;
// Ad[1][0]=0;
// Ad[1][1]=1;
// Ad[1][2]=0;
// Ad[2][0]=0;
// Ad[2][1]=0;
// Ad[2][2]=1;

///////////////////Control Matrix///////////
// Bd[0][0]=tsam/La;
// Bd[1][0]=0.0;
// Bd[2][0]=0.0;

///////////Output Matrix///////////
H[0][0]=1.0;
H[0][1]=0.0;
H[0][2]=0.0;
H[0][3]=0.0;
H[1][0]=0.0;
H[1][1]=0.0;
H[1][2]=1.0;
H[1][3]=0.0;

H_T[0][0]=1.0;
H_T[1][0]=0.0;
H_T[2][0]=0.0;
H_T[3][0]=0.0;
H_T[0][1]=0.0;
H_T[1][1]=0.0;
H_T[2][1]=1.0;
H_T[3][1]=0.0;

////////////////Jacopian Matrix/////////
fx_k[0][0] = 1;
fx_k[0][1] = 0;
fx_k[0][2] = tsam;
fx_k[0][3] = 0;
fx_k[1][0] = 0;
fx_k[1][1] = 1;
fx_k[1][2] = 0;
fx_k[1][3] = tsam;
fx_k[2][0] = 0;
fx_k[2][1] = (tsam*(- a*mu*cos(o_k_1)*pow(w_k_1,2) + fp*l*sin(o_k_1)*w_k_1 + g*l*mu*(2*pow(cos(o_k_1),2) - 1)))/(l*mu*pow(sin(o_k_1),2) + J) + (2*tsam*l*mu*cos(o_k_1)*sin(o_k_1)*(a*(mu*sin(o_k_1)*pow(w_k_1,2) + fc*v_k_1 - Uv*vf) + l*cos(o_k_1)*(fp*w_k_1 - g*mu*sin(o_k_1))))/pow((l*mu*pow(sin(o_k_1),2) + J),2);
fx_k[2][2] =  1 - (tsam*a*fc)/(l*mu*pow(sin(o_k_1),2) + J); // 0.9978;
fx_k[2][3] = -(tsam*(fp*l*cos(o_k_1) + 2*a*mu*w_k_1*sin(o_k_1)))/(l*mu*pow(sin(o_k_1),2) + J);
fx_k[3][0] = 0;
fx_k[3][1] = (tsam*(g*mu*cos(o_k_1) + l*sin(o_k_1)*(mu*sin(o_k_1)*pow(w_k_1,2) + fc*v_k_1 - Uv*vf) - l*mu*pow(w_k_1,2)*pow(cos(o_k_1),2)))/(l*mu*pow(sin(o_k_1),2) + J) + (2*tsam*l*mu*cos(o_k_1)*sin(o_k_1)*(fp*w_k_1 + l*cos(o_k_1)*(mu*sin(o_k_1)*pow(w_k_1,2) + fc*v_k_1 - Uv*vf) - g*mu*sin(o_k_1)))/pow((l*mu*pow(sin(o_k_1),2) + J),2);
fx_k[3][2] = -(tsam*fc*l*cos(o_k_1))/(l*mu*pow(sin(o_k_1),2) + J); // -0.0060*cos(o_k_1); 
fx_k[3][3] = 1 - (tsam*(fp + 2*l*mu*w_k_1*cos(o_k_1)*sin(o_k_1)))/(l*mu*pow(sin(o_k_1),2) + J);

// fu_k[0][0] = 0;
// fu_k[1][0] = 0;
// fu_k[2][0] = (tsam*a*vf)/J; // 0.0033;
// fu_k[3][0] = (tsam*l*vf*cos(o_k_1))/J; // 0.0090*cos(o_k_1);

///////////////Jacobian Transpose//////////////

fx_k_T[0][0]=fx_k[0][0];
fx_k_T[0][1]=fx_k[1][0];
fx_k_T[0][2]=fx_k[2][0];
fx_k_T[0][3]=fx_k[3][0];
fx_k_T[1][0]=fx_k[0][1];
fx_k_T[1][1]=fx_k[1][1];
fx_k_T[1][2]=fx_k[2][1];
fx_k_T[1][3]=fx_k[3][1];
fx_k_T[2][0]=fx_k[0][2];
fx_k_T[2][1]=fx_k[1][2];
fx_k_T[2][2]=fx_k[2][2];
fx_k_T[2][3]=fx_k[3][2];
fx_k_T[3][0]=fx_k[0][3];
fx_k_T[3][1]=fx_k[1][3];
fx_k_T[3][2]=fx_k[2][3];
fx_k_T[3][3]=fx_k[3][3];

// fu_k_T[0][0] = fu_k[0][0];
// fu_k_T[0][1] = fu_k[1][0];
// fu_k_T[0][2] = fu_k[2][0];
// fu_k_T[0][3] = fu_k[3][0];

    }
///////////////////////////////////////
// calculation of P(k+1|k) J_P[3][3];
// Compute Prior State Covariance
    
    {
        sum=0.0;
        for (k=0;k<4;k++){
        for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            sum=sum+fx_k[k][j]*Pk_k[j][i]; // J(k|k-1)*P(k-1)
                         }
            fx_P[k][i]=sum;
            sum=0.0;
                         }
                         }
    }
    
    {
        sum=0.0;
        for (k=0;k<4;k++){
        for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            sum=sum+fx_P[k][j]*fx_k_T[j][i]; // J(k|k-1)*P(k-1)*J(k|k-1)'
                         }
            fx_P_fx[k][i]=sum;
            sum=0.0;
                         }
                         }
    }
    
//     {
//         sum=0.0;
//         for (k=0;k<4;k++){
//         for (i=0;i<1;i++){
//         for (j=0;j<1;j++){
//             sum=sum+fu_k[k][j]*Q[j][i]; // Ju(k|k-1)*Q
//                          }
//             fu_q[k][i]=sum;
//             sum=0.0;
//                          }
//                          }
//     }  
//     
//     {
//         sum=0.0;
//         for (k=0;k<4;k++){
//         for (i=0;i<4;i++){
//         for (j=0;j<1;j++){
//             sum=sum+fu_q[k][j]*fu_k_T[j][i]; // Ju(k|k-1)*Q*Ju(k|k-1)'
//                          }
//             fu_q_fu[k][i]=sum;
//             sum=0.0;
//                          }
//                          }
//     }       
    
    {
        sum=0.0;
        for (i=0;i<4;i++) {
        for (j=0;j<4;j++) {
            // Pk_1_k[i][j]=fx_P_fx[i][j]+fu_q_fu[i][j]; // J(k|k-1)*P(k-1)*J(k|k-1)' + Ju(k|k-1)*Q*Ju(k|k-1)'
            Pk_1_k[i][j]=fx_P_fx[i][j] + Q[i][j]; // J(k|k-1)*P(k-1)*J(k|k-1)' + Q
                          }
                          }
    }
    
////////////////Kalman Filter Gain Calculation//////////
    {
        sum=0.0;
        for (k=0;k<4;k++){
        for (i=0;i<2;i++){
        for (j=0;j<4;j++){
            sum=sum+Pk_1_k[k][j]*H_T[j][i]; // P(-)*H(k)'
                         }
            Pk_H_T[k][i]=sum;
            sum=0.0;
                         }
                         }
    }
    
    {
        sum=0.0;
        for (k=0;k<2;k++){
        for (i=0;i<2;i++){
        for (j=0;j<4;j++){
            sum=sum+H[k][j]*Pk_H_T[j][i]; // H(k)*P(-)*H(k)'
                         }
            H_Pk_H_T[k][i]=sum;
            sum=0.0;
                         }
                         }
    }
    
    {
        for (k=0;k<2;k++){
        for (j=0;j<2;j++){
            HPH_R[k][j]=H_Pk_H_T[k][j]+R[k][j]; // H(k)*P(-)*H(k)' + R
                         }
                         }
        
    // Matrix Inverse for  HPH_R ( H(k)*P(-)*H(k)' + R)
    
        del=HPH_R[0][0]*HPH_R[1][1]-HPH_R[1][0]*HPH_R[0][1];
        if (del==0.0)
        {   
            del=0.0001;
        }
  
        HPH_R_inv[0][0]=HPH_R[1][1]/del;
        HPH_R_inv[0][1]=-HPH_R[0][1]/del;
        HPH_R_inv[1][0]=-HPH_R[1][0]/del;
        HPH_R_inv[1][1]=HPH_R[0][0]/del;
       
    } 
    {
        sum=0.0;
        for (k=0;k<4;k++){
        for (i=0;i<2;i++){
        for (j=0;j<2;j++){
            sum=sum+Pk_H_T[k][j]*HPH_R_inv[j][i]; // (P(-)*H(k)')/(H(k)*P(-)*H(k)' + R)
                         }
            K_g[k][i]=sum;
            sum=0.0;
                         }
                         }
    }

//////////////Prediction stage//////////////
    {
        x_es_k[0] = x_es_k[2]*tsam + x_es_k[0];
        x_es_k[1] = x_es_k[3]*tsam + x_es_k[1];
        x_es_k[2] = (tsam*(a*((vf*Uv-fc*x_es_k[2])-mu*pow(x_es_k[3],2)*sin(x_es_k[1]))+l*cos(x_es_k[1])*((mu*g*sin(x_es_k[1])-fp*x_es_k[3])))/(J+mu*l*pow(sin(x_es_k[1]),2))) + x_es_k[2];
        x_es_k[3] = (tsam*(l*cos(x_es_k[1])*(vf*Uv-fc*x_es_k[2]-mu*pow(x_es_k[3],2)*sin(x_es_k[1]))+mu*g*sin(x_es_k[1])-fp*x_es_k[3])/(J+mu*l*pow(sin(x_es_k[1]),2))) + x_es_k[3];
    
        // added by fk
        if(abs(x_es_k[0]) > 0.5) x_k_1 = (x_es_k[0]/abs(x_es_k[0]))*0.5;
        if(abs(x_es_k[1]) > 2*3.14) o_k_1 = (x_es_k[1]/abs(x_es_k[1]))*2*3.14;
        if(abs(x_es_k[2]) > 0.5) v_k_1 = (x_es_k[2]/abs(x_es_k[2]))*0.5;
        if(abs(x_es_k[3]) > 10) w_k_1 = (x_es_k[3]/abs(x_es_k[3]))*10;
    
    }

    {
        sum=0.0;
        for (k=0;k<4;k++){
        for (i=0;i<4;i++){
        for (j=0;j<2;j++){
            sum=sum+K_g[k][j]*H[j][i]; // Kn*H(k)
                         }
            K_g_H[k][i]=sum;
            sum=0.0;
                         }
                         }
    }

    {
        sum=0.0;
        for (k=0;k<4;k++){
        for (j=0;j<4;j++){
            I_K_g_H[k][j]=I_eye[k][j]-K_g_H[k][j]; // I - Kn*H(k)
                         }
                         }
    }

    {
        sum=0.0;
        for (k=0;k<4;k++){
        for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            sum=sum+I_K_g_H[k][j]*Pk_1_k[j][i]; // (I - Kn*H(k))*P(-)
                         }
            PK_1_K_1[k][i]=sum;
            sum=0.0;
                         }
                         }
    }

    {
        for (i=0;i<4;i++) {
        for (j=0;j<4;j++) {
            Pk_k[i][j]=PK_1_K_1[i][j]; // P(k-1) = P(k)
                          }
                          }
    }
    
//???????????????????????????????????????????????????????????????????????????
/////////////Correction Stage///////////////
//     if((x_es_k[3])>=0)
//     {
//             sgn=1;
//     }
//     else
//         sgn=-1;

errorx = x_m - x_es_k[0];
errorv = v_m - x_es_k[2];

x_k_1 = x_es_k[0]+K_g[0][0]*errorx+K_g[0][1]*errorv; // x_k_1
o_k_1 = x_es_k[1]+K_g[1][0]*errorx+K_g[1][1]*errorv; // o_k_1
v_k_1 = x_es_k[2]+K_g[2][0]*errorx+K_g[2][1]*errorv; // v_k_1
w_k_1 = x_es_k[3]+K_g[3][0]*errorx+K_g[3][1]*errorv; // w_k_1

// added by fk
if(abs(x_k_1) > 0.5) x_k_1 = (x_k_1/abs(x_k_1))*0.5;
if(abs(o_k_1) > 2*3.14) o_k_1 = (o_k_1/abs(o_k_1))*2*3.14;
if(abs(v_k_1) > 0.5) v_k_1 = (v_k_1/abs(v_k_1))*0.5;
if(abs(w_k_1) > 10) w_k_1 = (w_k_1/abs(w_k_1))*10;

// if ((Rs_es_k_f_1>15))
// {
//     Rs_es_k_f_1=15;
// }
// else if ((Rs_es_k_f_1<10))
// {
//     Rs_es_k_f_1=10;
// }

x_es_k[0] = x_k_1;
x_es_k[1] = o_k_1;
x_es_k[2] = v_k_1;
x_es_k[3] = w_k_1;
}

/*
 * mdlDerivatives - compute the derivatives
 *
 * In this function, you compute the S-function block's derivatives.
 * The derivatives are placed in the dx variable.
 */

static void mdlDerivatives(double *dx, double *x, double *u, SimStruct *S, int tid)
{

}

/*
 * mdlTerminate - called when the simulation is terminated.
 *
 * In this function, you should perform any actions that are necessary
 * at the termination of a simulation.  For example, if memory was allocated
 * in mdlInitializeConditions, this is the place to free it.
 */

static void mdlTerminate(SimStruct *S)
{
}

#ifdef	MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
