#pragma once
#include "BankAccount.h"

class CheckingAccount : public BankAccount {
public:
    // Constructors
    CheckingAccount(int dollars, int cents, double fee);
    CheckingAccount(int dollars, double fee);
    CheckingAccount();

    // Accessor for check fee
    double getCheckFee() const;

    // Overridden input and output functions
    void input(std::istream& ins);
    void output(std::ostream& outs) const;

    // Function to perform a check withdrawal
    void check(double amount);

private:
    double check_fee; // Fee charged per check transaction
};
