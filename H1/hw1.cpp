// name: Dargo Wang, yzw0060
// partner: NONE
// filename: hw1.cpp
// due date: 08/31/2018
// collaboration: I did not use any enternal sources for this assignment.
// problem: determine how much diet soda it is possible to drink without dying as a result
// how to compile: type in "g++ hw1.cpp" in terminal.

#include <iostream>
using namespace std;

const double RATIO = 0.001; 

int main() {

   double lethal_amount, mouse_weight, your_weight, threshold;

   cout << "What is the amount of artificial sweetener needed to kill a mouse: ";
   cin >> lethal_amount;

   cout << "\nWhat is the weight of the mouse: ";
   cin >> mouse_weight;

   cout << "\nWhat is the weight of the dieter: ";
   cin >> your_weight;

   threshold = lethal_amount / mouse_weight * your_weight / RATIO;

   cout << "\nYou can drink " << threshold << " diet soda without dying as a result.\n";

   return 0;
}