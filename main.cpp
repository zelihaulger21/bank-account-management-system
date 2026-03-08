#include <iostream>
#include <vector>
#include < fstream>
using namespace std;

class Account
{
private:
	int accountNumber;
	string ownerName;
	double balance;
public:
	Account(int accNo, string name, double initialBalance)
	{
		accountNumber = accNo;
		ownerName = name;
		balance = initialBalance;
	}
	void deposit(double amount)
	{
		balance += amount;
		cout << "Money deposited successfully." << endl;
	}
	void withdraw(double amount)
	{
		if (amount > balance)
		{
			cout << "Insufficient balance!" << endl;
		}
		else
		{
			balance -= amount;
			cout << "Money withdraw successfully." << endl;
		}
	}
	void display()
	{
		cout << "\nAccount Number: " << accountNumber << endl;
		cout << "Owner Name: " << ownerName << endl;
		cout << "Balance: " << balance << endl;
	}
	int getAccountNumber()
	{
		return accountNumber;
	}
};

int findAccount(vector<Account>& accounts, int accNo)
{
	for (int i = 0;i < accounts.size();i++)
	{
		if (accounts[i].getAccountNumber() == accNo)
			return i;
	}
	return -1;
}


int main()
{
	vector<Account> accounts;
	ifstream infile("accounts.txt");
	int accNo;
	string name;
	double balance;
	while (infile >> accNo >> name >> balance)
	{
		Account temp(accNo, name, balance);
		accounts.push_back(temp);
	}
	infile.close();
	int choice;

	do
	{
		cout << "\n-------BANK MENU-------" << endl;
		cout << "1. Create Account" << endl;
		cout << "2. Deposit Money" << endl;
		cout << "3. Withdraw Money" << endl;
		cout << "4. Show All Accounts" << endl;
		cout << "5.Exit" << endl;
		cout << "Choose: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int accNo;
			string name;
			double balance;

			cout << "Enter account number: ";
			cin >> accNo;

			cout << "Enter owner name: ";
			cin >> name;

			cout << "Enter initial balance: ";
			cin >> balance;

			Account newAccount(accNo, name, balance);
			accounts.push_back(newAccount);
			ofstream file("accounts.txt",ios::app);

			file << accNo << " " << name << " " << balance << endl;
			file.close();

			cout << "Account created successfully!" << endl;
			break;
		}
		case 2:
		{
			int accNo;
			double amount;
			cout << "Enter account number: ";
			cin >> accNo;
			int index = findAccount(accounts, accNo);
			if (index != -1)
			{
				cout << "Enter amount to deposit: ";
				cin >> amount;
				accounts[index].deposit(amount);
			}
			else {
				cout << "Account not found!" << endl;
			}
			break;
		}
		case 3:
		{
			int accNo;
			double amount;
			cout << "Enter account number: ";
			cin >> accNo;

			int index = findAccount(accounts, accNo);
			if (index != -1)
			{
				cout << "Enter amount to withdraw: ";
				cin >> amount;
				accounts[index].withdraw(amount);
			}
			else {
				cout << "Account not found!" << endl;
			}
			break;
		}
		case 4:
		{
			for (Account& acc : accounts)
				acc.display();
			break;
		}
		default:
		{
			cout << "Invalid choice!" << endl;
		}
		}
		} while (choice = !5);
		return 0;
	}
	
