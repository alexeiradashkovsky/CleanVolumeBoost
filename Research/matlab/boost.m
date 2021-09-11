clc;clear; close all;
Fs = 44100;
Ts = 1/Fs;
f = 1000;
t = [0:Ts:0.05].';

Vi = 0.1* sin(2*pi*f*t);

C2 = 47e-9;
R2 = Ts/(2*C2);
R4 = 56e3;
Rp = 0;
R6 = 2.7e3;
C3 = 4.7e-6;
R3 = Ts/(2*C3);
C5 = 15e-6;
R5 = Ts/(2*C5);
R9 = 470;
R10 = 10e3;

G = 1/(R3+Rp+R6);
Gi = R3*G;
G3 = (Rp+R6)*Gi;
Gx = R4*R2/(R4+R2);
Ga = Gx/R3;
Gb = (R9+R10)/(R5+R9+R10);
G5 = R5*Gb;
Go = R10/(R10+R9);
N = length(Vi);
Va = zeros(N,1);
Vo = zeros(N,1);
Vt = zeros(N,1);
Vb = zeros(N,1);
Vr2 = zeros(N,1);
Vr5 = zeros(N,1);
x2 = 0;
x3 = 0;
x5 = 0;

for n=1:N
  Va(n,1) = Gi*Vi(n,1) + G3*x3;
  Vt(n,1) = Vi(n,1) + Ga*Va(n,1) - Gx*(x3-x2);
  if Vt(n,1) > 4.5
    Vt(n,1) = 4.5;
  elseif Vt(n,1) < -4.5
    Vt(n,1) = -4.5;
  endif

  Vb(n,1) = Gb*Vt(n,1) - G5*x5;
  Vo(n,1) = Go*Vb(n,1);
  
  Vr2(n,1) = Vt(n,1)-Vi(n,1);
  x2 = Vr2(n,1)*2/R2 - x2;
  x3 = Va(n,1)*2/R3 - x3;
  Vr5(n,1) = Vt(n,1) - Vb(n,1);
  x5 = Vr5(n,1)*2/R5 - x5;
endfor

% Waveform
subplot(2,3,1);
plot(t,Vi);
title('Effect Vi');
subplot(2,3,2);
[Hi,Fi] = freqz(Vi,1,4096,Fs);
plot(Fi , 20*log10(abs(Hi)));
title('Effect Vi freq response');

subplot(2,3,3);
semilogx(Fi , 20*log10(abs(Hi)));
title('Effect Vi freq response');

subplot(2,3,4);
plot(t, Vo);
title('Boost stage');
subplot(2,3,5);
[H,F] = freqz(Vo,1,4096,Fs);
plot(F , 20*log10(abs(H)));
title('Boost stage freq response');

subplot(2,3,6);
semilogx(F , 20*log10(abs(H)));
title('Boost stage freq response');

