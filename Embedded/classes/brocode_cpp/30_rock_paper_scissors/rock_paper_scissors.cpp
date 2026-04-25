#include <iostream>
#include <ctime>

using std::cout;
using std::cin;

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main() {
    char player;
    char computer;

    player = getUserChoice();
    cout << "\nYour choice: ";
    showChoice(player);

    computer = getComputerChoice();
    cout << "\nComputer's choice: ";
    showChoice(computer);

    cout << "\n";
    chooseWinner(player, computer);
    
    return 0;
}

char getUserChoice() {
    char player;

    cout << "\nRock-Paper-Scissors Game!\n";
    
    do {
        cout << "-------------------------\n\n";
        cout << "'R' for Rock\n";
        cout << "'P' for Paper\n";
        cout << "'S' for Scissors\n";
        cout << "Pick your choice: ";
        cin >> player;
        player = toupper(player);

        if(player != 'R' && player != 'P' && player != 'S') {
            cout << "\nInvalid choice!\n";
        }
    } while(player != 'R' && player != 'P' && player != 'S');

    return player;
}

char getComputerChoice() {
    srand(time(0));
    int num = rand() % 3 + 1;

    switch(num) {
        case 1:
            return 'R';
        case 2:
            return 'P';
        case 3:
            return 'S';
    }

    return 0;
}

void showChoice(char choice) {
    switch(choice) {
        case 'R':
            cout << "ROCK\n";
            break;
        case 'P':
            cout << "PAPER\n";
            break;
        case 'S':
            cout << "SCISSORS\n";
            break;
    }
}

void chooseWinner(char player, char computer) {
    switch(player) {
        case 'R':
            if(computer == 'R') {
                cout << "It's a tie!\n";
            } else if(computer == 'P') {
                cout << "You lose!\n";
            } else {
                cout << "You win!\n";
            }
            break;
        case 'P':
            if(computer == 'R') {
                cout << "You win!\n";
            } else if(computer == 'P') {
                cout << "It's a tie!\n";
            } else {
                cout << "You lose!\n";
            }
            break;
        case 'S':
            if(computer == 'R') {
                cout << "You lose!\n";
            } else if(computer == 'P') {
                cout << "You win!\n";
            } else {
                cout << "It's a tie!\n";
            }
            break;
    }
}