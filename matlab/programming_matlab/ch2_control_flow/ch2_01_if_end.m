% 2.1 IF-END

% simple number guessing game

number = rand(1);
number = 10*number;
number = ceil(number);

guess = input('Guess the number between 1 and 10: ');

if guess == number
    fprintf('Correct! You win!\n');
end

if guess ~= number
    fprintf('Wrong... The number I was thinking of was %d. Try again.\n', number);
end