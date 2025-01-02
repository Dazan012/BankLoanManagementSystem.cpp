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

private:
    string customerName;
    double amount;       // Principal amount
    double interestRate; // Annual interest rate
    int term;            // Term in months

    double calculateMonthlyPayment() const
    {
        double monthlyRate = interestRate / 100 / 12; // Convert annual rate to monthly
        return (amount * monthlyRate) / (1 - pow(1 + monthlyRate, -term));
    }

    double calculateTotalPayment() const
    {
        return calculateMonthlyPayment() * term;
    }
};

// Class to represent the Bank
class Bank
{
public:
    void addLoan(const Loan &loan)
    {
        loans.push_back(loan);
    }

    void displayLoans() const
    {
        if (loans.empty())
        {
            cout << "No loans available." << endl;
            return;
        }

        for (const auto &loan : loans)
        {
            loan.displayLoanInfo();
        }
    }

private:
    vector<Loan> loans; // List of loans
};
