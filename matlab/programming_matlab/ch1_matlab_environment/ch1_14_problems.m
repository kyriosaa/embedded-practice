% 1.14 Practice Problems

% ------------------------------------------------------------------------
% 1-1: Plot the following functions using the plot() function
    % sin(x)                for -10 <= x <= 10
    % sin(x)cos(x)          for -10 <= x <= 10
    % cos(x)sin(x)exp(x/10) for  -1 <= x <=  1

    x = linspace(-10, 10, 500);
    y = sin(x);
    plot(x, y)
    title('1-1 sin(x)')
    pause;

    x = linspace(-10, 10, 500);
    y1 = sin(x);
    y2 = cos(x);
    plot(x, y1, x, y2)
    title('1-1 sin(x)cos(x)')
    pause;

    x = linspace(-1, 1, 100);
    y1 = cos(x);
    y2 = sin(x);
    y3 = exp(x/10);
    plot(x, y1, x, y2, x, y3)
    title('1-1 cos(x)sin(x)exp(x/10)')
    pause;
    
% ------------------------------------------------------------------------
% 1-2: Write a script that does the following:
    % 1. Creates a random 5x5 matrix, displays that random matrix,
    %    calculates and displays the inverse of the random matrix, and
    %    displays the result of the matrix times its inverse.
    % 2. Asks the user to input three text strings with the input()
    %    function and prints out the concatenation of all three.
    % 3. Asks the user for a text string and changes the word "the" to
    %    "hey".
    % 4. Asks the user for a text string and then tells the user what the
    %    first character was, what the second character was, and what the
    %    third character was.

    % 1
    rand_matrix = rand(5, 5)
    inv_rand_matrix = inv(rand_matrix)
    final_matrix = rand_matrix*inv_rand_matrix
    pause;

    % 2
    p1 = input('Input phrase 1: ', 's');
    p2 = input('Input phrase 2: ', 's');
    p3 = input('Input phrase 3: ', 's');
    p123 = [p1, p2, p3];
    fprintf(p123);
    fprintf('\n');
    pause;

    % 3
    original = input('What''s a phrase that contains all letters of the English alphabet?: ', 's');
    replaced = strrep(original, 'the', 'hey');
    fprintf(replaced);
    fprintf('\n');
    pause;

    % 4
    usr_string = input('Input any text string longer than 3 characters: ', 's');
    first_char = usr_string(1);
    second_char = usr_string(2);
    third_char = usr_string(3);
    fprintf('First character: %s\n', first_char);
    fprintf('Second character: %s\n', second_char);
    fprintf('Third character: %s\n', third_char);
  
% ------------------------------------------------------------------------
% 1-3: Create a script that does the following:
    % 1. Displays your name and major.
    % 2. Pauses for 5 seconds after the above information is displayed.
    % 3. Asks the user to input a number between 50 and 100. Call it x.
    % 4. Takes the square root of the number and displays it in long
    %    format.
    % 5. Pauses until a key is pressed.
    % 6. Sets up an array of 100 values for time from 0 to 0.1 seconds.
    %    Don't display the values.
    % 7. Calculates y=sin(2πxt) using the time array created in step 6 and
    %    the value of x from step 3.
    % 8. Plot 'y' vs 't' using the plot() function
    % 9. Label the x and y axes using the MATLAB xlabel() and ylabel()
    %    functions.

    % 1
    fprintf('Name: kyriosaa\n');
    fprintf('Major: Electrical Engineering and Computer Science\n');

    % 2
    pause(5);

    % 3
    x = input('Input a number between 50 and 100: ', 's');

    % 4
    x = str2double(x);
    sqrt_x = sqrt(x);
    format long;
    fprintf('%f', sqrt_x);

    % 5
    pause;

    % 6
    time = linspace(0, 0.1, 100);

    % 7
    y = sin(2 * pi * x * time)

    % 8 
    figure;
    plot(time, y);

    % 9
    title('y = sin(2πxt)');
    xlabel('Time (s)');
    ylabel('y');

% ------------------------------------------------------------------------
% 1-4: Find the solution (A, B, C) to the system of equations:
    %   10 =  400A -  175B
    %    0 = -175A +  800B - 250C
    %    5 =         -300B + 600C

    A = [ 400, -175,    0;
         -175,  800, -250;
            0, -300,  600];
    B = [10, 0, 5];

    answer = A/B;

    ans_A = answer(1);
    ans_B = answer(2);
    ans_C = answer(3);

    fprintf('A = %f, B = %f, C = %f', ans_A, ans_B, ans_C);