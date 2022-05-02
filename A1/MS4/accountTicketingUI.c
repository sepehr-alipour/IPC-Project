// #############################################################################################
//  Assignment: 1 
//  Milestone : 4
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################

#include <stdio.h>
#include "commonHelpers.h"
#include "accountTicketingUI.h"
#include "account.h"
#define INIT_DATA_SIZE 5

void displayAccountDetailHeader()
{
	printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
	printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
	return;
}
void displayAccountDetailRecord(const struct Account* account)
{
	int i;
	char pass[9];
	for (i = 0; account->userLogin.password[i] != '\0'; i++)
	{

		pass[i] = i % 2 == 0 ? account->userLogin.password[i] : '*';
	}
	pass[i] = 0;
	printf("%05d %-9s %-15s %5d %11.2lf %-10s %-10s %8s\n"
		, account->number
		, account->type == 'A' ? "AGENT" : "CUSTOMER"
		, account->person.fullName
		, account->person.brithYear
		, account->person.income
		, account->person.country
		, account->userLogin.userName
		, pass);
	return;
}

void applicationStartup(struct Account accounts[], int length)
{
	int index;
	int isExit = 0;
	char confirmation = 'n';
	do
	{
		index = menuLogin(accounts, INIT_DATA_SIZE);
		if (index > 0) {
			printf("\n");
			menuAgent(accounts, length, &accounts[index]);
		}
		else {
			printf("\nAre you sure you want to exit? ([Y]es|[N]o): ");
			confirmation = getCharOption("yYnN");
			if (confirmation == 'y' || confirmation == 'Y')
				isExit = 1;
			printf("\n");
		}
	} while (isExit == 0);
	printf("==============================================\n");
	printf("Account Ticketing System - Terminated\n");
	printf("==============================================");
	return;
}
int menuLogin(const struct Account accounts[], int length)
{
	int option;
	int accountIndex;
	do {
		printf("==============================================\n");
		printf("Account Ticketing System - Login\n");
		printf("==============================================\n");
		printf("1) Login to the system\n");
		printf("0) Exit application\n");
		printf("----------------------------------------------\n");
		printf("\nSelection: ");
		option = getIntFromRange(0, 1);
		if (option == 0)
			return -1;
		printf("\nEnter your account#: ");
		accountIndex = findAccountIndexByAcctNum(getPositiveInteger(), accounts, length, 0);
		if (accountIndex < 0 || accounts[accountIndex].type == 'C')
		{
			printf("ERROR:  Login failed!\n\n");
			pauseExecution();
		}
	} while (accountIndex < 0 || accounts[accountIndex].type == 'C');
	return accountIndex;
}

int findAccountIndexByAcctNum(int accountID, const struct Account accounts[], int length, int shouldPromt)
{
	int i;
	int accountIndex = -1;
	if (shouldPromt > 0) {
		printf("\nEnter the account#: ");
		accountID = getPositiveInteger();
	}

	for (i = 0; i < length; i++)
	{
		if (accountID == accounts[i].number)
			accountIndex = i;
	}


	return accountIndex;
}
void menuAgent(struct Account accounts[], int length, const struct Account* account)
{
	int option, i, indexAccount, hasFree;
	char confirmationDelete;
	do {
		printf("AGENT: %s (%d)\n", account->person.fullName, account->number);
		printf("==============================================\n");
		printf("Account Ticketing System - Agent Menu\n");
		printf("==============================================\n");
		printf("1) Add a new account\n");
		printf("2) Modify an existing account\n");
		printf("3) Remove an account\n");
		printf("4) List accounts: detailed view\n");
		printf("----------------------------------------------\n");
		printf("0) Logout\n");
		printf("\nSelection: ");
		option = getIntFromRange(0, 4);
		switch (option)
		{
		case 1:
			printf("\n");
			for (i = 0; i < length; i++)
			{
				if (accounts[i].number == 0) {
					hasFree = 1;
					break;
				}
			}
			if (hasFree == 0)
				printf("ERROR: Account listing is FULL, call ITS Support!");
			else
			{
				struct Account newAccount = { 0 };
				getAccount(&newAccount);
				accounts[i] = newAccount;
				printf("\n*** New account added! ***\n\n");
				pauseExecution();
			}
			break;
		case 2:
			indexAccount = findAccountIndexByAcctNum(-1, accounts, length, 1);
			if (indexAccount < 0)
			{
				printf("ERROR: the account not found\n");
				pauseExecution();
			}
			else
				updateAccount(&accounts[indexAccount]);
			break;
		case 3:
			indexAccount = findAccountIndexByAcctNum(-1, accounts, length, 1);
			if (indexAccount < 0)
			{
				printf("ERROR: the account not found\n\n");
				pauseExecution();
				break;
			}
			if (accounts[indexAccount].number == account->number)
			{
				printf("\nERROR: You can't remove your own account!\n\n");
				pauseExecution();
				break;
			}
			else
			{
				displayAccountDetailHeader();
				displayAccountDetailRecord(&accounts[indexAccount]);
				printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
				confirmationDelete = getCharOption("yYnN");
				if (confirmationDelete == 'Y' || confirmationDelete == 'y') {
					accounts[indexAccount].number = 0;
					printf("\n*** Account Removed! ***\n\n");
					pauseExecution();
				}
				break;

			}
			break;
		case 4:
			displayAllAccountDetailRecords(accounts, length);
			printf("\n");
			pauseExecution();
			break;
		case 0:
			printf("\n### LOGGED OUT ###\n\n");
			break;
		}

	} while (option > 0);
	return;
}
void displayAllAccountDetailRecords(const struct Account accounts[], int length)
{
	int i;
	printf("\n");
	displayAccountDetailHeader();
	for (i = 0; i < length; i++)
	{
		if (accounts[i].number > 0)
			displayAccountDetailRecord(&accounts[i]);

	}
	return;

}

void updateAccount(struct Account* account)
{
	int option;
	do {
		printf("\n");
		printf("Update Account: %d (%s)\n", account->number, account->person.fullName);
		printf("----------------------------------------\n");
		printf("1) Update account type (current value: %c)\n", account->type);
		printf("2) Person\n");
		printf("3) Login\n");
		printf("0) Done\n");
		printf("Selection: ");
		option = getIntFromRange(0, 3);
		switch (option)
		{
		case 1:
			printf("\nEnter the account type (A=Agent | C=Customer): ");
			account->type = getCharOption("AC");
			if (account->type == 'A')
			{
				printf("\nAgent type accounts require a user login.  Please enter this information now:\n");

				getUserLogin(&account->userLogin);
			}
			else {
				struct UserLogin empty = { {0} };
				account->userLogin = empty;
			}

			break;
		case 2:
			updatePerson(&account->person);
			break;
		case 3:
			if (account->type == 'C')
			{
				printf("\nERROR:  Customer account types don't have user logins!\n");

			}
			else
			{
				updateUserLogin(&account->userLogin);
			}
			break;
		case 0:
			printf("\n");
			break;

		}
	} while (option > 0);
	return;
}
void updatePerson(struct Person* person)
{
	int option;
	do {
		printf("\n");
		printf("Person Update Options\n");
		printf("----------------------------------------\n");
		printf("1) Full name (current value: %s)\n", person->fullName);
		printf("2) Household Income (current value: $%.2lf)\n", person->income);
		printf("3) Country (current value: %s)\n", person->country);
		printf("0) Done\n");
		printf("Selection: ");
		option = getIntFromRange(0, 3);
		switch (option)
		{
		case 1:
			printf("\nEnter the person's full name (30 chars max): ");
			getCString(person->fullName, 1, 30);
			break;
		case 2:
			printf("\nEnter the household Income: $");
			person->income = getPositiveDouble();
			break;
		case 3:
			printf("\nEnter the country (30 chars max.): ");
			getCString(person->country, 1, 30);
			break;
		case 0:
			break;

		}
	} while (option > 0);
	return;
}
void updateUserLogin(struct UserLogin* userLogin)
{
	int option;
	do {
		printf("\n");
		printf("User Login: %s - Update Options\n", userLogin->userName);
		printf("----------------------------------------\n");
		printf("1) Password\n");
		printf("0) Done\n");
		printf("Selection: ");
		option = getIntFromRange(0, 1);
		switch (option)
		{
		case 1:
			printf("\nEnter the password (must be 8 chars in length): ");
			getCString(userLogin->password, 8, 8);
			break;
		case 0:
			break;

		}
	} while (option > 0);
	return;
}






// Pause execution until user enters the enter key 
void pauseExecution(void)
{
	printf("<< ENTER key to Continue... >>");
	clearStandardInputBuffer(); putchar('\n');
	return;
}