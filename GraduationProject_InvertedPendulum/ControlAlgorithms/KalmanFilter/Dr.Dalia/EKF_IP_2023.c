/*
 * Copyright (c) by University of Aleppo
 * All Rights Reserved
 * Saturday-2-2-2013
 * Dalia Kass Hanna
 */

#define S_FUNCTION_NAME EKF_IP_2023

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
double Xes[4]; // [Xk_1_es, ok_1_es, vk_1_es, wk_1_es]
double Xprd[4]; // [Xk_1_prd, ok_1_prd, vk_1_prd, wk_1_prd]

// nonlinStates inputs & outputs
double x_k, o_k, v_k, w_k;
double x_k_1, o_k_1, v_k_1, w_k_1, Uv, x_m, v_m, D;

// Cumputation Matrixes
double tsam; // constatnts
double Pk_k[4][4],Q[4][4],R[2][2];
double fx_k[4][4],fu_k[4][1],Pk_1_k[4][4],fx_k_T[4][4];
double K_g[4][2],H[2][4],H_T[4][2];
double Pk_H_T[4][2]; //P(k+1)H'
double H_Pk_H_T[2][2];//HP(k+1)H'
double fx_P[4][4],PK_1_K_1[4][4];   //JP(k)
double fx_P_fx[4][4], HPH_R[2][2], HPH_R_inv[2][2]; //JP(k)J'
double I_eye[4][4],K_g_H[4][4];
double I_K_g_H[4][4];
double x_es_k[4]; // estimated state

int    i,j,k;
double  M,m,L,fc,g,errorx,errorv,sum,del;

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
    M = 1.12; // Cart mass
    m = 0.12; // Pendulum mass 
    L = 0.033245968; // rotation axes to CoM Length
    fc = 2.53165; // Cart friction
    g = 9.81; // Gravetational acceleration
    
    sum = 0.0;
    del=0.001;
   // tsam=1e-4;


Pk_k[0][0]=0.1;   //related to x
Pk_k[0][1]=0.0;
Pk_k[0][2]=0.0;
Pk_k[0][3]=0.0;

Pk_k[1][0]=0.0;
Pk_k[1][1]=0.1;   //related to v
Pk_k[1][2]=0.0;
Pk_k[1][3]=0.0;

Pk_k[2][0]=0.0;
Pk_k[2][1]=0.0;
Pk_k[2][2]=0.1;  //related to o
Pk_k[2][3]=0.0;

Pk_k[3][0]=0.0;
Pk_k[3][1]=0.0;
Pk_k[3][2]=0.0;
Pk_k[3][3]=0.1;  //related to w

R[0][0]=0.0001; 
R[0][1]=0.0;

R[1][0]=0.0;   
R[1][1]=0.0001;

Q[0][0]=1; //6000
Q[0][1]=0; 
Q[0][2]=0; 
Q[0][3]=0;

Q[1][0]=0; 
Q[1][1]=1; //800
Q[1][2]=0; 
Q[1][3]=0;

Q[2][0]=0; 
Q[2][1]=0; 
Q[2][2]=1; //12000
Q[2][3]=0;

Q[3][0]=0; 
Q[3][1]=0; 
Q[3][2]=0; 
Q[3][3]=1; //600

//////////////////I_eye(2,2)///////

I_eye[0][0]=1;
I_eye[0][1]=0;
I_eye[0][2]=0;
I_eye[0][3]=0;

I_eye[1][0]=0;
I_eye[1][1]=1;
I_eye[1][2]=0;
I_eye[1][3]=0;

I_eye[2][0]=0;
I_eye[2][1]=0;
I_eye[2][2]=1;
I_eye[2][3]=0;

I_eye[3][0]=0;
I_eye[3][1]=0;
I_eye[3][2]=0;
I_eye[3][3]=1;

///////////////////////////////

x_es_k[0]=0.0;
x_es_k[1]=0.0;
x_es_k[2]=3.141592653589793;
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
fx_k[0][1] = tsam;
fx_k[0][2] = 0;
fx_k[0][3] = 0;

fx_k[1][0] = 0;
fx_k[1][1] = 1 - (fc*tsam)/(M-m*(pow(cos(o_k_1),2)-1));
fx_k[1][2] = tsam*((m*(g-2*g*(pow(cos(o_k_1),2))+L*pow(w_k_1,2)*cos(o_k_1)))/(-m*(pow(cos(o_k_1),2))+M+m)-(4*m*Uv*sin(2*o_k_1))/pow((2*M+m-m*cos(2*o_k_1)),2)+(2*m*sin(2*o_k_1)*(-2*L*m*sin(o_k_1)*pow(w_k_1,2)+2*fc*v_k_1+g*m*sin(2*o_k_1)))/pow((2*M+m-m*cos(2*o_k_1)),2));
fx_k[1][3] = (2*L*m*tsam*w_k_1*sin(o_k_1))/(m*pow(sin(o_k_1),2)+M);

fx_k[2][0] = 0;
fx_k[2][1] = 0;
fx_k[2][2] = 1;
fx_k[2][3] = tsam;

fx_k[3][0] = 0;
fx_k[3][1] = (fc*tsam*cos(o_k_1))/(L*(M-m*(pow(cos(o_k_1),2) - 1)));
fx_k[3][2] = -tsam*((L*m*sin(o_k_1)*(-L*m*sin(o_k_1)*pow(w_k_1,2)+fc*v_k_1)+pow(L*m*w_k_1*cos(o_k_1),2)-L*g*m*cos(o_k_1)*(M+m))/(pow(L,2)*m*(M-m*(pow(cos(o_k_1),2)-1)))-(Uv*sin(o_k_1))/(L*(M-m*(pow(cos(o_k_1),2)-1)))+(2*cos(o_k_1)*sin(o_k_1)*(L*m*cos(o_k_1)*(-L*m*sin(o_k_1)*pow(w_k_1,2)+fc*v_k_1)+L*g*m*sin(o_k_1)*(M+m)))/(pow(L,2)*pow((M-m*(pow(cos(o_k_1),2)-1)),2))-(2*m*Uv*pow(cos(o_k_1),2)*sin(o_k_1))/(L*pow((M-m*(pow(cos(o_k_1),2)-1)),2))); 
fx_k[3][3] = 1-(2*m*tsam*w_k_1*cos(o_k_1)*sin(o_k_1))/(M-m*(pow(cos(o_k_1),2)-1));


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
    
    {
        sum=0.0;
        for (i=0;i<4;i++) {
        for (j=0;j<4;j++) {
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
        else
        {   
            del=del;
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
        D = m*L*L*(M+m*(1-pow(cos(x_es_k[2]),2)));
        x_es_k[0] = x_es_k[1]*tsam + x_es_k[0];
        x_es_k[1] = tsam*((1/D)*(-pow(m*L,2)*g*cos(x_es_k[2])*sin(x_es_k[2])+m*L*L*(m*L*pow(x_es_k[3],2)*sin(x_es_k[2])-fc*x_es_k[1]))+m*L*L*(1/D)*Uv)+x_es_k[1];
                
                
        x_es_k[2] = x_es_k[3]*tsam + x_es_k[2];
        x_es_k[3] = tsam*((1/D)*((m+M)*m*g*L*sin(x_es_k[2])-m*L*cos(x_es_k[2])*(m*L*pow(x_es_k[3],2)*sin(x_es_k[2])-fc*x_es_k[1]))-m*L*cos(x_es_k[2])*(1/D)*Uv)+x_es_k[3];
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

errorx = x_m - x_es_k[0];
errorv = v_m - x_es_k[2];

x_k_1 = x_es_k[0]+K_g[0][0]*errorx+K_g[0][1]*errorv; // x_k_1
v_k_1 = x_es_k[1]+K_g[1][0]*errorx+K_g[1][1]*errorv; // v_k_1
o_k_1 = x_es_k[2]+K_g[2][0]*errorx+K_g[2][1]*errorv; // o_k_1
w_k_1 = x_es_k[3]+K_g[3][0]*errorx+K_g[3][1]*errorv; // w_k_1

x_es_k[0] = x_k_1;
x_es_k[1] = v_k_1;
x_es_k[2] = o_k_1;
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
