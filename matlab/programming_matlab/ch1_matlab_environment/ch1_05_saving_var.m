% 1.5 Saving the Variables Stored in Memory

% Suppose you've done a large amount of work and defined a number of
% variables. You need to quit using MATLAB for the moment, but you would
% like to use these variables in the future. This can be done in two ways.
% You can use the MATLAB menus and use the *File* and *Save Workspace As*
% menu selections, or you can use the MATLAB *SAVE* command.

a=1;
b=2;
c=3;
d=4;
e=5;
f=6;
g=7;
who

% Save the variables using the save command
save ch1_5_saving_var_SAVE
clear
who

% Load them back using the load command
load ch1_5_saving_var_SAVE
who