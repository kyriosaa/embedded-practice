% 1.10 Input and Output Statements

% As of now, we've been using MATLAB as a calculator
% However, we can use have it take in an input and do some calculations 
% with that input to form an output too
% ------------------------------------------------------------------------
% 1.10.1 The Semicolon in MATLAB

% Add a semicolon ; to the end of a line to suppress the results of a calc
a = 5+6;

% Semicolons can also be used to signal the end of a statement, 
% so multiple commands can be entered on a single line
x = 5; y = 25; z = x+y/13;
% ------------------------------------------------------------------------
% 1.10.2 MATLAB Programmed Output

% We can use the fprintf() function to print stuff to the terminal
fprintf('This is a test.\n');

% The fprintf function wont generate an output until it reaches a "\n"
fprintf('This is line 1.');
fprintf('This is line 2.\n\n');

fprintf('This is line 1.\n');
fprintf('This is line 2.\n\n');

% Use %g to display the value of a variable
fprintf('The value of pi is %g, and the value of negative pi is %g.\n\n', pi, -pi);
% ------------------------------------------------------------------------
% 1.10.3 MATLAB Programmed Input

% Information from the user can be requested by using the input() function
num = input('Specify a number: ');
fprintf('The number you typed was: %g\n\n', num);

% input() normally only takes in numerical values, but we can add an 's'
% modifier to the function to allow it to take in strings
xx_string = input('Insert text: ', 's');
fprintf('Your inserted text: ');
fprintf(xx_string);
fprintf('\n');