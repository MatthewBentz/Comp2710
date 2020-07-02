//============================================================================
// Name        : project1_Bentz_mlb0119.cpp
// Author      : Matthew Bentz (mlb0119)
// Description : COMP 2710: Project 1, "Flow of Control"
// Sources	   : Project1_hints.pdf
//			   : Previous Knowledge
//			   : Kindson Youtube Tutorial - TA sent me links through email
// Compile	   : Compiled with MinGW GCC C++ Compiler
// Version	   : Submission 2 - Added comments and refactored code
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int n = 100;
	do {
		cout << "X";
		n = n + 100;
	}
	while (n < 1000);

	cout << endl;

	for (int n = 100; n < 1000; n += 100) {
		cout << "X";
	}


	return 0;
}


enum Colors {
	COLOR_BLACK,
	COLOR_WHITE,
	COLOR_RED,
};


void printColor(Colors color) {
	switch(color) {
		case COLOR_BLACK:
			cout << "Black";
			break;
		case COLOR_WHITE:
			cout << "White";
			break;
		case COLOR_RED:
			cout << "Red";
			break;
		default:
			cout << "Unknown";
			break;
}

}
	/*
	// Global Variables
	double loan;
	double interestRate;
	double interestRateC;
	double monthlyPayment;
	int currentMonth = 0;
	double monthlyInterestAmount;
	double interestTotal = 0;

	// Currency Format
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// User Input
	// Loan Amount
	do {
		cout << "\nLoan Amount: ";
		cin >> loan;
		if (loan <= 0) {
			cout << "Please enter a positive amount." << endl;
		}
	}
	while (loan <= 0);

	// Interest Rate
	do {
		cout << "Interest Rate (% per year): ";
		cin >> interestRate;
		if (interestRate < 0) {
			cout << "Please enter a positive amount." << endl;
		}
	}
	while (interestRate < 0);

	// Calculate Interest Rates
	interestRate /= 12;
	interestRateC = interestRate / 100;

	// Monthly Payments
	do {
		cout << "Monthly Payments: ";
		cin >> monthlyPayment;
		if (monthlyPayment <= (interestRateC * loan)) {
			cout << "Please enter sufficient monthly payment." << endl;
		}
	}
	while (monthlyPayment < (interestRateC * loan));

	cout << endl;

	// Amortization Table
	cout << "*****************************************************************\n"
		 << "\tAmortization Table\n"
		 << "*****************************************************************\n"
		 << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

	// Loop to fill table
	while (loan > 0) {
		if (currentMonth == 0) {
			cout << currentMonth++ << "\t$" << loan;
			if (loan < 1000) {
				cout << "\t";
			}
			cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
		}
		else {
			// Calculate Monthly and Total Interest before deducting loan
			monthlyInterestAmount = loan * interestRateC;
			interestTotal += monthlyInterestAmount;

			// Calculate Loan after deducting monthly payment
			// Check to see if loan is paid off
			loan = (loan * (1 + interestRateC)) - monthlyPayment;
			if (loan < 0) {
				monthlyPayment += loan;
				loan = 0;
			}

			// Display the current month's info in the table
			cout << currentMonth++ // "Month"
				 << "\t$" << loan << "\t"; // "Balance"
			if (loan < 1000) {
				cout << "\t";
			}
			cout << "$" << monthlyPayment << "\t" // "Payment"
				 << interestRate << "\t" // "Rate"
				 << "$" << monthlyInterestAmount << "\t\t" // "Interest"
				 << "$" << monthlyPayment - monthlyInterestAmount << endl; // "Principal"
		}
	}

	// Display info
	cout << "****************************************************************\n";
	cout << "\nIt takes " << --currentMonth << " months to pay off the loan.\n"
		 << "Total interest paid is: $" << interestTotal;
	cout << endl << endl;
	return 0;
}
*/
