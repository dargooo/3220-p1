// name: Dargo Wang, yzw0060
// partner: NONE
// filename: hw2.cpp
// due date: 09/07/2018
// collaboration: I did not use any enternal sources for this assignment.
// problem: determine how many months it will take to pay off the loan.
// how to compile: type in "g++ hw1.cpp" in terminal.

#include <iostream>
#include <iomanip>
#include <locale>
using namespace std;
   
int main() {
   
   double loanAmount, rateYear, rateMonth, payment;
         
   cout << "Loan Amount: ";
   cin >> loanAmount;
   
   cout << "Interest Rate (% per year): ";
   cin >> rateYear;
   rateMonth = rateYear / 12;
   
   cout << "Monthly Payments: ";
   cin >> payment;
   
   double balance = loanAmount, interest, principal, totalInterest = 0;
   int month = 0;
   
   cout.setf(ios::left);
   cout.setf(ios::fixed);
   //std::locale loc("");
   //std::cout.imbue(loc);      
   //cout.imbue(std::locale(""));
   
   cout << "\n*******************************************************"
        << "\n       Amortization Table"
        << "\n*******************************************************"
        << "\n" << setw(7) << "Month" 
        << setw(13) << "Balance"
        << setw(9) << "Payment"
        << setw(8) << "Rate"
        << setw(9) << "Interest"
        << setw(9) << "Principal" << endl;
        
   cout << setw(7) << month 
        << "$" << setprecision(2) << setw(12) << balance 
        << setw(9) << "N/A"
        << setw(8) << "N/A"
        << setw(9) << "N/A"
        << setw(9) << "N/A" << endl;
   
   month++;
      
   while (balance > 0) {
   
      interest = balance * rateMonth / 100;
      if (balance < payment) {
         principal = balance;
         payment = principal + interest;
      }
      else {
         principal = payment - interest;
      }
      balance -= principal;
      
      if (payment < interest)    
         break;
      
      cout << setw(7) << month 
           << "$" << showpoint << setprecision(2) << setw(12) << balance 
           << "$" << setw(8) << payment;
      cout.unsetf(ios::showpoint);
      cout.unsetf(ios::fixed);
      cout << setw(8) << rateMonth; 
      cout << "$" << fixed << setprecision(2) << setw(8) << interest 
           << "$" << setw(8) << principal << endl;
           
      totalInterest += interest;   
      month++;
   }
   month--;
   
   cout << "*******************************************************\n\n";
   if (balance != 0) {
      cout << "You need to pay more to pay off the loan." << endl;
   }
   else {
      cout << "It takes " << month << " months to pay off the loan.\n"
         << "Total interest paid is: $" << totalInterest << endl;
   }

   return 0;
}