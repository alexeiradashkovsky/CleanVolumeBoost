clc;clear; close all;
Fs = 44100;
Ts = 1/Fs;
f = 1000;
t = [0:Ts:0.01].';

Vi = 0.1* sin(2*pi*f*t);

C2;
R2 = Ts/(2*C2);
R4;
Rp = 0;
R6;
C3;
R3 = Ts/(2*C3);

G = 1/(R3+Rp+R6);
G0 = R4*R2/(R4+R2);
G3 = R3 * G;



