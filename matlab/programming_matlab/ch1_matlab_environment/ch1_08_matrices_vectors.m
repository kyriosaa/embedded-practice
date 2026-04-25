% 1.8 Matrices and Vectors

% When referring to a variable with multiple numberical values, MATLAB
% treats these variables as either matrices or arrays. When treated as
% arrays, MATLAB addresses these variables like other conventional
% programming languages, by performing element-by-element operations. When
% these variables are treated as matrices, MATLAB performs matrix
% operations with the variables. In MATLAB, the default uses matrix algebra
% instead of array operations.

A=[1 2 3;4 5 6;7 8 9]   % separate columns by spaces...
B=[9,8,7;6,5,4;3,2,1]   % ...or by commas

% ------------------------------------------------------------------------
% 1.8.1 Matrix Multiplication

% Matrix multiplication is not commutative
c=A*B
c2=B*A

% You can also multiply using a scalar
d=5*A


% Create a one-row matrix
x=[1 2 3]

% Create a one-column matrix
y=[1;2;3]

z=x*y
z=y*x
% ------------------------------------------------------------------------
% 1.8.2 Matrix Addition and Subtraction

% Same matrix addition/subtraction rule applies in general mathematics
% Same size matrices can be added and subtracted.

A
B
q=A-B
b_sub_a=B-A

% We can also add/sub a matrix with a scalar
A+5
% ------------------------------------------------------------------------
% 1.8.3 The Inverse of a Matrix

% We can find the inverse of a matrix by using the "inv" function
inv(A)
% MATLAB takes the inverse but it also warns that the result is probably
% not accurate. This is because matrix A is close to a singular matrix

% The "rand(m, n)" function creates an 'm x n' matrix and fills it with
% pseudo random numbers between 0 and 1.
A=rand(3)

A_inv=inv(A)

A*A_inv
% ------------------------------------------------------------------------
% 1.8.4 The Determinant of a Matrix

% The MATLAB "det" function is used to find the determinant of a matrix
B
det(B)

% ^ in this case, the determinant is zero. Before taking the inverse of a
% matrix, you should check to see if the determinant is zero. If it is, do
% not take the inverse of the matrix.

det(A)
% ------------------------------------------------------------------------
% 1.8.5 Solving Systems of Equations

% In many fields of engineering, we will end up with a system of n
% equations with n unknown variables. If the system is linear, MATLAB
% solves it easily. 

%       5x +  7y +   3z =    1
%      -3x + 16y + 2.5z =   -4
%      15x - 12y + 3.9z = 16.8

A=[5 7 3; -3 16 -2.5; 15 -12 3.9]

b=[1;-4;16.8]

rank(A)
rank([A b])
% both have rank 3 so we can calculate

x=inv(A)*b
x=A\b % <- preferred method