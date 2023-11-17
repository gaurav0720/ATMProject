#include "CheckingAccount.h"
#include <iostream>

// Constructor with dollars, cents, and fee
CheckingAccount::CheckingAccount(int dollars, int cents, double fee)
    : BankAccount(dollars, cents), check_fee(fee) {
    // You can add additional constructor logic here if needed
}

// Constructor with dollars and fee
CheckingAccount::CheckingAccount(int dollars, double fee)
    : BankAccount(dollars), check_fee(fee) {
    // Constructor logic
}

// Default constructor
CheckingAccount::CheckingAccount() : check_fee(0) {
    // Default constructor logic
}

// Get the check fee
double CheckingAccount::getCheckFee() const {
    return check_fee;
}

// Input function for checking account details
void CheckingAccount::input(std::istream& ins) {
    BankAccount::input(ins); // Call base class input method
    ins >> check_fee; // Input the check fee
}

// Output function for checking account details
void CheckingAccount::output(std::ostream& outs) const {
    BankAccount::output(outs); // Call base class output method
    outs << " Check Fee: " << check_fee << std::endl; // Output the check fee
}

// Perform a check withdrawal
void CheckingAccount::check(double amount) {
    double totalAmount = amount + check_fee;
    BankAccount::withdraw(totalAmount); // Withdraw amount including check fee
}
