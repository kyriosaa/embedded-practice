% 1.7 Complex Numbers

% Pure imaginary and complex numbers are expressed in MATLAB by "i" or "j".
% Both are defined as sqrt(-1). If we do sqrt(-1) the answer will have an
% "i" in it

% The real part of the answer is zero and the imaginary part is 1*i

format short
sqrt(-1)
% 0.0000 + 1.0000i

sqrt(-9)
% 0.0000 + 3.0000i

% MATLAB can automatically handle calculations with complex numbers
(1+2i)/(3+5i)
% 0.3824 + 0.0294i

% ------------------------------------------------------------------------
% Let a = 3+4i and b = 1+i and display the results for (a^2), a-b, a+b, 
% a*b, a/b, and sqrt(a)
a = 3+4i;
b = 1+i;

a^2
a-b
a+b
a*b
a/b
sqrt(a)
% ------------------------------------------------------------------------
% Complex Number Manipulation

A=3+4i;

% "real" returns the real part of a complex number
real(A)

% "imag" returns the imaginary part of a complex number
imag(A)

% "abs" returns the magnitude of the complex number
abs(A)

% "angle" returns the angle in radians
angle(A)
% this answer can be converted to degrees by multiplying the result with
% 360/(2*pi)
angle(A)*360/(2*pi)