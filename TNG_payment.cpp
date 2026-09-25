#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

//Function prototype
void checkBalance();
void topUp();
void transferPayment();
void transactionHistory();
void displayMenu();
 int choice;

int main(){
    cout << "Payment Simulation - Inspired by Touch 'n GO\n";
   do{
            displayMenu();
            switch (choice){
                case 1: checkBalance(); break;
                case 2: topUp(); break;
                case 3: transferPayment(); break;
                case 4: transactionHistory(); break;
                case 5: cout << "Thank you for using Touch 'n Go wallet!"<< endl;
                        cout << "Goodbye!"<< endl; break;
                default: cout << "Invalid choice. Please select 1 - 5" << endl;
            }
        }
        while (choice != 5);

        return 0;
}
  void displayMenu(){
        cout << "\n============ Main Menu ============" << endl;
        cout << "1. Check Balance"<< endl;
        cout << "2. Top Up"<< endl;
        cout << "3. Transfer Money"<< endl;
        cout << "4. Transaction History"<< endl;
        cout << "5. Exit"<< endl;
        cout << "====================================" << endl;
        cout << "Enter your choice ";
        cin >> choice;
    }
    void checkBalance(){
    cout << "Your balance is: RM0.00" << endl;
}

void topUp(){
    cout << "Top up feature coming soon." << endl;
}

void transferPayment(){
    cout << "Transfer feature coming soon." << endl;
}

void transactionHistory(){
    cout << "No transactions yet." << endl;
}
