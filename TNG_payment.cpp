#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

double balance = 0.00;

void checkBalance();
void topUp();
void transferPayment();
void displayMenu();
void transactionHistory();

int choice;
double amount;
vector<string> history;

int main(){
    cout << "Payment Simulation - Inspired by Touch 'n GO\n";
    do{
        displayMenu();
        switch (choice){
            case 1: checkBalance(); break;
            case 2: topUp(); break;
            case 3: transferPayment(); break;
            case 4: transactionHistory(); break;
            case 5: cout << "Thank you for using Touch 'n Go wallet!" << endl;
                cout << "Goodbye!" << endl; 
                break;
            default: 
                cout << "Invalid choice. Please select 1 - 4" << endl;
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
    cout << "Your balance is: RM " << balance << endl;
}

void topUp(){
    amount = 0;
    while (amount <=0 || amount > 1000){
    cout << "Enter the top Up amount: ";
    cin >> amount;

   
    if (amount <= 0){
        cout << "Invalid amount. Please enter a positive amount." << endl;
    }
    else if (amount > 1000) {
        cout << "Top up limit is RM 1000." << endl;
    }
}
    
        balance = balance + amount;
        cout << "Top up successful!" << endl;
        cout << "Your new balance is RM " << balance << endl;
    
        history.push_back("Top Up: +RM " + to_string(amount));

}

void transferPayment(){
   string accountNumber; 
    bool isValid = false;

    while(!isValid){

     cout << "Enter recipient account number (6 digits): ";
     cin >> accountNumber;

     isValid = (accountNumber.length() == 6);
     if (isValid){
        for (char c : accountNumber){
            if (!isdigit(c)){
                isValid = false;
            }
        }
     }    
   
     if (!isValid){
       cout << "Invalid account number. It must be exactly 6 digits." << endl;
        }

      }

   bool validAmount = false;

   while (!validAmount) {
       cout << "Enter amount to transfer: RM ";
       cin >> amount;

       if (amount <= 0){
           cout << "Invalid amount. Transfer must be greater than 0." << endl;
       }
       else if (amount > balance){
           cout << "Insufficient balance. Your current balance is RM " << balance << endl;
       }
       else {
           validAmount = true; 
       }
   }
   balance -= amount;
   cout << fixed << setprecision(2);
   cout << "Transfer successful! RM " << amount << " sent to account " << accountNumber << "." << endl;

   history.push_back("Transfer: -RM " + to_string(amount) + " to Acc " + accountNumber);
}

void transactionHistory(){
    if (history.empty()){
        cout << "No transaction yet." << endl;
        return;
    }

    cout << "\n-------Transaction History-------" << endl;
    for ( int i = 0; i < history.size(); i++){
        cout << i + 1 << ". " << history[i] << endl;
    }
    cout << "-----------------------------------" << endl;
}
