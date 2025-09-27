#include <iostream>
#include <string>
#include <limits>
#include "BankAccount.h"

/*----------[Constructors]----------*/

// Default Constructor
BankAccount::BankAccount()
{
	accountNumber = "";
	accountHolderName = "";
	balance = 0.00;
}

// Parameterized Constructor
BankAccount::BankAccount(std::string AccountNumber, std::string AccountHolderName, double Balance)
{
	accountNumber = AccountNumber;
	accountHolderName = AccountHolderName;
	balance = Balance;
}

// Constructor
BankAccount::BankAccount(const BankAccount& other) {
	accountNumber = other.accountNumber;
	accountHolderName = other.accountHolderName;
	balance = other.balance;
}

/*--------------------*/

/*----------[Operators]----------*/
BankAccount& BankAccount::operator=(const BankAccount& other)
{
	if (this != &other)
	{
		accountNumber = other.accountNumber;
		accountHolderName = other.accountHolderName;
		balance = other.balance;
	}
	return *this;
}

BankAccount& BankAccount::operator+=(double amount)
{
	balance += amount;
	return *this;
}

BankAccount& BankAccount::operator-=(double amount)
{
	balance -= amount;
	return *this;
}

bool BankAccount::operator==(const BankAccount& other) const
{
	return (accountNumber == other.accountNumber &&
		accountHolderName == other.accountHolderName &&
		balance == other.balance);
}

bool BankAccount::operator<(const BankAccount& other) const
{
	return (balance < other.balance);
}

bool BankAccount::operator>(const BankAccount& other) const
{
	return (balance > other.balance);
}

/*--------------------*/

/*----------[Static function]----------*/
void BankAccount::printAccount(const BankAccount& account)
{
	std::cout << "Bank Info:"
		<< "\nAccount Name: " << account.accountHolderName
		<< "\nAccount Number: " << account.accountNumber
		<< "\nCurrent Balance: $" << account.balance
		<< std::endl;
	return;
}

BankAccount BankAccount::createAccountFromInput()
{
	BankAccount createAccount;
	int accountNum;
	double balance;
	std::string accountName;

	std::cout << "Define a account number for the Bank Account." << std::endl;

	std::cout << "> ";

	while (!(std::cin >> accountNum))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "> ";
	}
	std::cout << std::endl;

	std::cout << "Define a account name for the Bank Account." << std::endl;
	std::cout << "> ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, accountName);
	std::cout << std::endl;

	std::cout << "Define a starting balance for the Bank Account." << std::endl;

	std::cout << "$ ";
	while (!(std::cin >> balance))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "$ ";
	}

	std::cout << std::endl;

	createAccount.SetAccountHolderName(accountName);
	createAccount = BankAccount(std::to_string(accountNum), createAccount.GetAccountHolderName(), balance);
	return createAccount;
}

/*--------------------*/

/*----------[Class Functions]----------*/
void BankAccount::SetAccountHolderName(std::string AccountHolderName)
{
	accountHolderName = AccountHolderName;
	return;
}

void BankAccount::Deposit(double amount)
{
	if (amount == 0)
	{
		std::cout << "Your balance did not change cause of invalid amount of 0." << std::endl;
	}
	else if (amount < 0)
	{
		std::cout << "Invalid amount of money to deposit." << std::endl;
	}
	else {
		*this += amount;
		std::cout << "New account balance: $" << balance << std::endl;
	}
}

void BankAccount::Withdraw(double amount)
{
	if (amount == 0)
	{
		std::cout << "Your balance did not change cause of invalid amount of 0." << std::endl;
	}
	else if (amount < 0)
	{
		std::cout << "Invalid amount of money to withdraw." << std::endl;
	}
	else if (amount > balance)
	{
		std::cout << "Not enough funds." << std::endl;
	}
	else {
		*this -= amount;
		std::cout << "New account balance: $" << balance << std::endl;
	}
}
/*--------------------*/

/*----------[Getters]----------*/
std::string BankAccount::GetAccountNumber()
{
	return accountNumber;
}

std::string BankAccount::GetAccountHolderName()
{
	return accountHolderName;
}

double BankAccount::GetBalance()
{
	return balance;
}

/*--------------------*/

/*----------[Destructor]----------*/
BankAccount::~BankAccount() {}
/*--------------------*/