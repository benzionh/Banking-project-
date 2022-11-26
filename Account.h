#pragma once
class Account
{
	private:
		double balance, interest, intRate;
		int transactions;
	public:
		// Constructor
		Account(double rate = 0.045, double bal = 0.0){
			balance = bal;
			intRate = rate;
			interest = 0.0;
			transactions = 0;
		}
		// make a method for deposit
		void makeDeposit(double amount){
			balance += amount;
			transactions++;
		}
		// make a method for withdrawal
		bool withdraw(double amount); // definition in Account.cpp
		void calculateInterest(){
			interest = balance + intRate;
			balance += interest;
		}
		double getBalance(){
			return balance;
		}
		// make a method to get interst
		double getInterest(){
			return interest;
		}
		// make a method to get transactions
		int getTransactions(){
			return transactions;
		}
};