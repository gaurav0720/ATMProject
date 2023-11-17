#include <iostream>
#include <string>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"

using namespace std;

// Assuming getTransaction is a function that gets the transaction type, amount, and account type
// void getTransaction(char &transact, double &amount, char &fromAcct);

int main() {
    SavingAccount savings;
    CheckingAccount checking;

    char transact, fromAcct;
    double amount;

    cout << "Update the account info for Checking (balance and fee): ";
    checking.input(cin);

    cout << "Update the account info for Saving (balance and rate): ";
    savings.input(cin);

    cout << "\n\n*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-\n";
    cout << "***** Welcome to the ATM 2000!!\n";
    cout << "\n*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-\n";
    cout << "Looks like you accrued some interest in your Savings.\n";
    // Assuming update function exists for SavingAccount
    savings.update();

    do {
        cout << "\n*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-\n";
        cout << "What would you like to do today?\n";
        cout << "B)alance, D)eposit, W)ithdraw, C)heck, T)ransfer, Q)uit?\n";
        // getTransaction(transact, amount, fromAcct);
        cin >> transact;

        switch (transact) {
            case 'B': // Balance
                cout << "From which account? (C)hecking (S)aving: "<<endl;
                cin >> fromAcct;
                if (fromAcct == 'C') checking.output(cout);
                else if (fromAcct == 'S') savings.output(cout);
                break;

            case 'D': // Deposit
                cout << "What amount would you like to Deposit today? "<<endl;
                cin >> amount;
                cout << "From which account? (C)hecking (S)aving: "<<endl;
                cin >> fromAcct;
                if (fromAcct == 'C') checking.deposit(amount);
                else if (fromAcct == 'S') savings.deposit(amount);
                break;

            case 'W': // Withdraw
                cout << "What amount would you like to Withdraw today? "<<endl;
                cin >> amount;
                cout << "From which account? (C)hecking (S)aving: "<<endl;
                cin >> fromAcct;
                if (fromAcct == 'C') checking.withdraw(amount);
                else if (fromAcct == 'S') savings.withdraw(amount);
                break;

            case 'C': // Check
                cout << "What amount would you like to Check today? "<<endl;
                cin >> amount;
                if (fromAcct == 'C') checking.check(amount);
                break;

            case 'T': // Transfer
                cout << "What amount would you like to Transfer today? "<<endl;
                cin >> amount;
                cout << "From which account? (C)hecking (S)aving: "<<endl;
                cin >> fromAcct;
                if (fromAcct == 'C') {
                    checking.withdraw(amount);
                    savings.deposit(amount);
                } else if (fromAcct == 'S') {
                    savings.withdraw(amount);
                    checking.deposit(amount);
                }
                break;

            case 'Q': // Quit
                cout << "Come Again! Bye!\n";
                break;

            default:
                cout << "Invalid transaction type.\n";
        }
    } while (transact != 'Q');

    return 0;
}