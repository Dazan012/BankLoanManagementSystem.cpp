#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath> // Include cmath for pow function

using namespace std;

// Class to represent a Loan
class Loan
{
public:
    Loan(string customerName, double amount, double interestRate, int term)
        : customerName(customerName), amount(amount), interestRate(interestRate), term(term) {}

    void displayLoanInfo() const
    {
        cout << "Customer Name: " << customerName << endl;
        cout << "Loan Amount: $" << fixed << setprecision(2) << amount << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Term: " << term << " months" << endl;
        cout << "Monthly Payment: $" << fixed << setprecision(2) << calculateMonthlyPayment() << endl;
        cout << "Total Payment: $" << fixed << setprecision(2) << calculateTotalPayment() << endl;
        cout << "----------------------------------------" << endl;
    }