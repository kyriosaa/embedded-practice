% 1.11 Plotting in MATLAB

% linspace(x1, x2, n)
% Creates n equally spaced values from x1 to x2 and stores them in x as a
% one-dimensional array with one row
x = linspace(0, 5, 6)
x = linspace(0, 5, 11)

% plot(x, y)
% Plots the values stored in array y versus the values stored in array x
% The two arrays must have the same number of values

% ------------------------------------------------------------------------
% Plot:
% y = |x|sin(x)
% for -100 <= x <= 100

x = linspace(-100, 100, 5000);
y = abs(x).*sin(x);
plot(x, y)
% ------------------------------------------------------------------------
% Plot:
% sin(x)
% cos(x)
% sin^2(x)
% for 0 <= x <= 2(pi)

x = linspace(0, 2*pi, 100);
y1 = sin(x);
y2 = cos(x);
y3 = sin(x).*sin(x);

plot(x, y1, x, y2, x, y3)
xlabel('x');
ylabel('y');
title('Various Trigonometric Functions');
legend('sin(x)', 'cos(x)', 'sin(x).*sin(x)');