#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <memory>


int main()
{
	BankAccount a_bank;
	std::vector<std::unique_ptr<BankAccount>> accountList;
	int option, accountOption, accountNum;
	double fee, rate;
	std::string accountName;
	bool found = false;
	double amount;

	do {
		std::cout << "[Choose a option!]"
			<< "\n1. Open Account"
			<< "\n2. See Account"
			<< "\n3. Deposit"
			<< "\n4. Withdraw"
			<< "\n5. Apply Interest"
			<< "\n6. Quit"
			<< std::endl;

		std::cout << "> ";

		while (!(std::cin >> option))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "> ";
		}
		std::cout << std::endl;

		switch (option)
		{
		case 1:
			a_bank = BankAccount::createAccountFromInput();

			std::cout << "What account type would this be?"
				<< "\n1) Checking account"
				<< "\n2) Savings account"
				<< std::endl;

			std::cout << "> ";

			while (!(std::cin >> accountOption))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "> ";
			}

			std::cout << std::endl;

			found = false;

			for (int i = 0; i < accountList.size(); i++)
			{
				if (accountList.at(i).get()->GetAccountNumber() == a_bank.GetAccountNumber() == true)
				{
					found = true;
				}
			}

			if (found == false)
			{
				if (accountOption == 1)
				{
					std::cout << "Enter transaction fee" << std::endl;
					std::cout << "$ ";

					while (!(std::cin >> fee))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "$ ";
					}
					accountList.push_back(std::make_unique<CheckingAccount>(a_bank.GetAccountNumber(), a_bank.GetAccountHolderName(), a_bank.GetBalance(), fee));
				}
				else if (accountOption == 2)
				{
					std::cout << "Enter interest rate" << std::endl;
					std::cout << "$ ";

					while (!(std::cin >> rate))
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "$ ";
					}
					accountList.push_back(std::make_unique<SavingsAccount>(a_bank.GetAccountNumber(), a_bank.GetAccountHolderName(), a_bank.GetBalance(), rate));
				}
				else
				{
					std::cout << "Invalid account type!" << std::endl;
				}
			}
			else {
				std::cout << "Account number already exists to someone." << std::endl;
			}
			std::cout << std::endl;
			break;
		case 2:
			if (accountList.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{

				std::cout << "Please enter in your account number." << std::endl;
				std::cout << "> ";

				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;

				found = false;
				for (int i = 0; i < accountList.size(); i++)
				{
					if (accountList.at(i).get()->GetAccountNumber() == std::to_string(accountNum))
					{
						found = true;
						BankAccount::printAccount(*accountList.at(i));
					}
				}
				if (found == false)
				{
					std::cout << "Account was not found!" << std::endl;
				}
			}
			std::cout << std::endl;
			break;
		case 3:

			if (accountList.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				std::cout << "Please enter in your account number." << std::endl;
				std::cout << "> ";

				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;

				found = false;
				for (int i = 0; i < accountList.size(); i++)
				{
					if (accountList.at(i).get()->GetAccountNumber() == std::to_string(accountNum))
					{
						found = true;
						std::cout << "How much would you like to deposit?" << std::endl;
						std::cout << "$ ";
						while (!(std::cin >> amount))
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "$ ";
						}
						std::cout << std::endl;
						accountList.at(i).get()->Deposit(amount);
					}
				}

				if (found == false)
				{
					std::cout << "Account was not found!" << std::endl;
				}
			}
			std::cout << std::endl;
			break;
		case 4:

			if (accountList.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				std::cout << "Please enter in your account number." << std::endl;
				std::cout << "> ";
				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;
				found = false;
				for (int i = 0; i < accountList.size(); i++)
				{
					if (accountList.at(i).get()->GetAccountNumber() == std::to_string(accountNum))
					{
						found = true;
						std::cout << "How much would you like to withdraw?" << std::endl;

						std::cout << "$ ";
						while (!(std::cin >> amount))
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "$ ";
						}
						std::cout << std::endl;
						accountList.at(i).get()->Withdraw(amount);
					}
				}
				if (found == false)
				{
					std::cout << "Account was not found!" << std::endl;
				}
			}
			std::cout << std::endl;
			break;
		case 5:
			if (accountList.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				std::cout << "Please enter in your account number." << std::endl;
				std::cout << "> ";
				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;

				found = false;
				for (int i = 0; i < accountList.size(); i++)
				{
					if (accountList.at(i).get()->GetAccountNumber() == std::to_string(accountNum))
					{
						found = true;
						SavingsAccount* SavingsInterestAccount = dynamic_cast<SavingsAccount*>(accountList.at(i).get());
						if (SavingsInterestAccount) { SavingsInterestAccount->calculateInterest(); }
					}
				}
				if (found == false)
				{
					std::cout << "Account was not found!" << std::endl;
				}
			}
			std::cout << std::endl;
			break;
		default:
			continue;
		}

	} while (option != 6);

	return 0;
}