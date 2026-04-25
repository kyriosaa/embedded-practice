% 1.9 Strings

% Character strings in MATLAB are enclosed in single quotes ''
x = 'abcd'
y = 'abc123@#${}[]:;'
word = 'didn''t'    % didn't
word = 'didn"t'     % didn"t
% ------------------------------------------------------------------------
% 1.9.1 String Indexing

% The first character of a string has an index of 1

% To access any character, we specify the variable name with the index of
% the character enclosed in parantheses
x
x(1)
x(2)
x(3)
x(4)

x(2:3)
x(2:4)
% ------------------------------------------------------------------------
% 1.9.2 Concentrating Strings

% Strings can be concatenated (linked to make a larger string)
x1 = 'abcd'
x2 = 'efgh'
x3 = 'ijklmnop'

x123 = [x1, x2, x3]
x_all = [x1, x2, x3, 'qrstuvwxyz']

x_aei = [x1(1), x2(1), x3(1)]
% ------------------------------------------------------------------------
% 1.9.3 String Functions

% LENGTH    - Returns the number of characters in a string
    a = 'abcdefgh'
    length(a)
    % find last character in a string:
    a(length(a))

% STRCMP    - Compares two strings
    a = 'abcd'
    b = 'efgh'
    c = 'abcd'
    d = 'abcd '
    strcmp(a, b)        % 0
    strcmp(a, c)        % 1
    strcmp(a, 'abcd')   % 1
    strcmp(a, d)        % 0

% STR2NUM   - Converts a string to a numerical value
    '123' + '321'
    % ^ adding two strings gives us the sum of the ASCII codes, so we need 
    % to convert them into numbers before calculating with them
    str2num('123') + str2num('321')

% STRREP    - Replaces characters in a string with different characters
    xx = 'String search and replacement'
    yy = strrep(xx, 'a', '*')
    % ^ replace all occurences of the letter 'a' with '*'
    
    aa = 'supplement replacement excitement retirement'
    bb = strrep(aa, 'ent', '*****')
    % ^ we can also replace strings of char with new strings

% UPPER     - Converts a string to uppercase
    greeting = 'hello world'
    upper_greeting = upper(greeting)

% LOWER     - Converts a string to lowercase
    farewell = 'GOODBYE WORLD'
    lower_farewell = lower(farewell)