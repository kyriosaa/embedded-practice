% 1.2 Defining Variables

% Define variables using =
A=5
zoo=26/3.7
This_is_a_very_long_variable_name=789

% Perform calculations using variables
a=5;
b=3;
c=8;
x=a+b/c

% Check variables in memory using the WHO command
who

% A second form of the WHO command is WHOS. It lists the variables in
% memory and how much mem it uses
whos

% We can also make arrays that aren't just single num value/element
array=[1 2 3 4; 66 76 88 44; 567 45 76 0]
whos

% Variables can be changed and still stored in memory
A
A=27
who

% Use CLEAR to clear specific variables from memory
clear This_is_a_very_long_variable_name a b c
who