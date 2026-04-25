#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::setprecision;
using std::fixed;

// ----- function declarations -----
void showBalance(double balance);
double deposit();
double withdraw(double balance);
// ---------------------------------

int main() {
    double balance = 0;
    int choice = 0;

    do {
        cout << "\n----- Banking Program -----\n\n";
        cout << "1. Show Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "---------------------------\n";
        cout << "Enter your banking choice: \n";
        cin >> choice;

        cin.clear();
        fflush(stdin);

        switch(choice) {
            case 1:
                showBalance(balance);
                break;
            case 2:
                balance += deposit();
                showBalance(balance);
                break;
                case 3:
                balance -= withdraw(balance);
                showBalance(balance);
                break;
            case 4:
                cout << "Thank you for visiting.\n";
                break;
            default:
                cout << "Invalid Choice\n";
        }
    } while(choice != 4);

    return 0;
}

void showBalance(double balance) {
    cout << "Your balance is: $" << setprecision(2) << fixed << balance << "\n";
}

double deposit() {
    double amount = 0;

    cout << "Enter amount to deposit: ";
    cin >> amount;

    if(amount > 0) {
        return amount;
    } else {
        cout << "You cannot deposit a negative number!\n";
        return 0;
    }
}

double withdraw(double balance) {
    double amount = 0;

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if(amount > balance) {
        cout << "Insufficient funds.\n";
        return 0;
    } else if(amount < 0) {
        cout << "Invalid amount.\n";
        return 0;
    } else {
        return amount;
    }
}