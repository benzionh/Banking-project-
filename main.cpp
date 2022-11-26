#include <iostream>
#include <iomanip>
#include <windows.h>
#include "Account.h"
using namespace std;
// make a display menu function
void displayMenu(){
	cout << "\n\n        MENU\n\n";
	cout << "1) Account balance\n";
	cout << "2) Transactions\n";
	cout << "3) Interest for the period\n";
	cout << "4) Deposit\n";
	cout << "5) Withdraw\n";
	cout << "6) Calculate interest for the period\n";
	cout << "7) Exit\n\n";
	cout << "Enter choice: ";
}
char getChoice(char max){
	char choice = cin.get();
	cin.ignore();//bypass the enter '\n' in the input buffer
	while (choice < '1' || choice > max){
		cout << "Invalid choice! Enter choice: ";
		choice = cin.get();
		cin.ignore();
	}
	return choice;
}
void makeDeposit(Account &account){
	double dollars;
	cout << "Enter amount: ";
	cin >> dollars;
	cin.ignore();
	account.makeDeposit(dollars);
}
void withdraw(Account &account){
	double dollars;
	cout << "Enter amount: ";
	cin >> dollars;
	cin.ignore();
	if (!account.withdraw(dollars)){
		cout << "Invalid amount\n\n";
	}
}
int main()
{
	const char MAX_CHOICE = '7';
	//system("color 3F");
	Account savings;
	char choice;
	cout << fixed << showpoint << setprecision(2);
	do{
		displayMenu();
		choice = getChoice(MAX_CHOICE);
		switch(choice)
		{
		case '1':
			//system("cls");
			cout << "Balance is $";
			cout << savings.getBalance() << endl;
			break;
		case '2':
			//system("cls");
			cout << "Total transactions is ";
			cout << savings.getTransactions() << " transactions.\n";
			break;
		case '3':
			//system("cls");
			cout << "Total interest is $ " << savings.getInterest() << endl;
			break;
		case '4':
			//system("cls");
			makeDeposit(savings);
			break;
		case '5':
			//system("cls");
			withdraw(savings);
			break;
		case '6':
			//system("cls");
			savings.calculateInterest();
			cout << "Interest added.\n"; 
		default:
			break;
		}
	}while(choice != '7');
	return 0;
}