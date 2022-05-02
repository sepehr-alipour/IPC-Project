// #############################################################################################
//  Assignment: 2 
//  Milestone : 4
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################
#include <ctype.h> 
#include <stdio.h>
#include <string.h>
#include "accountTicketingUI.h"

#define INIT_DATA_SIZE 5
#define MAX_LOGIN_SIZE 100
void displayAccountDetailHeader()
{
	printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
	printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
	return;
}

void displayAccountDetailRecord(const struct Account* account)
{
	int i;
	char pass[MAX_SIZE_PASSWORD + 1];
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

void applicationStartup(struct AccountTicketingData* ticketingData)
{
	int index;
	int isExit = 0;
	char confirmation = 'n';
	do
	{
		index = menuLogin(ticketingData->accounts, INIT_DATA_SIZE);
		if (index > 0) {
			printf("\n");
			menuAgent(ticketingData, &ticketingData->accounts[index]);
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
int menuLogin(const struct Account* accounts, int length)
{
	int option;
	int accountIndex;
	int attemps = 3;
	char userName[MAX_LOGIN_SIZE + 1];
	char password[MAX_LOGIN_SIZE + 1];
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
		do {
			printf("\nEnter the account#: ");
			accountIndex = findAccountIndexByAcctNum(getPositiveInteger(), accounts, length, 0);
			if (accountIndex >= 0) {
				printf("User Login        : ");
				getCString(userName, 1, MAX_LOGIN_SIZE);
				printf("Password          : ");
				getCString(password, 1, MAX_LOGIN_SIZE);
				if (accountIndex < 0 || accounts[accountIndex].type == 'C'
					|| strcmp(accounts[accountIndex].userLogin.userName, userName) != 0
					|| strcmp(accounts[accountIndex].userLogin.password, password) != 0)
				{
					attemps--;
					printf("INVALID user login/password combination! [attempts remaining:%d]\n", attemps);
					if (attemps == 0) {
						printf("\nERROR:  Access Denied.\n\n");
						pauseExecution();
						accountIndex = -1;
					}

				}
				else
				{
					return accountIndex;
				}
			}
		} while (attemps > 0);
	} while (accountIndex < 0 || accounts[accountIndex].type == 'C');
	return accountIndex;
}

int findAccountIndexByAcctNum(int accountID, const struct Account* accounts, int length, int shouldPromt)
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

	if (accountIndex < 0)
	{
		printf("ERROR: the account not found\n\n");
		pauseExecution();
	}
	return accountIndex;
}
void menuAgent(struct AccountTicketingData* ticketingData, const struct Account* account)
{
	int option;
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
		printf("5) List new tickets\n");
		printf("6) List active tickets\n");
		printf("7) List closed tickets\n");
		printf("8) Add a new ticket\n");
		printf("9) Manage a ticket\n");
		printf("----------------------------------------------\n");
		printf("0) Logout\n");
		printf("\nSelection: ");
		option = getIntFromRange(0, 9);
		switch (option)
		{
		case 1:
			printf("\n");
			addAccountMenu(ticketingData);
			break;
		case 2:
			modifyAccountMenu(ticketingData);
			break;
		case 3:
			deleteAccountMenu(ticketingData, account->number);
			break;
		case 4:
			displayAllAccountDetailRecords(ticketingData->accounts, ticketingData->ACCOUNT_MAX_SIZE);
			printf("\n");
			pauseExecution();
			break;
		case 5:
			printf("\n");
			displayTicketRecords(ticketingData->tickets, ticketingData->TICKET_MAX_SIZE, 0);
			break;
		case 6:
			printf("\n");
			displayTicketRecords(ticketingData->tickets, ticketingData->TICKET_MAX_SIZE, 2);
			break;
		case 7:
			printf("\n");
			displayTicketRecords(ticketingData->tickets, ticketingData->TICKET_MAX_SIZE, 1);
			break;
		case 8:
			addTicket(ticketingData->tickets, ticketingData->accounts, ticketingData->ACCOUNT_MAX_SIZE, ticketingData->TICKET_MAX_SIZE);
			printf("\n");
			pauseExecution();
			break;
		case 9:
			manageTicket(ticketingData->tickets, account->person, ticketingData->TICKET_MAX_SIZE);
			printf("\n");
			break;
		case 0:
			printf("\nSaving session modifications...\n");
			printf("   %d account(s) saved.\n", saveAccounts(ticketingData->accounts, ticketingData->ACCOUNT_MAX_SIZE));
			printf("   %d ticket(s) saved.\n", saveTickets(ticketingData->tickets, ticketingData->TICKET_MAX_SIZE));
			printf("### LOGGED OUT ###\n\n");
			break;
		default:
			printf("\nFeature #%d currently unavailable!\n\n", option);
			pauseExecution();
			break;
		}

	} while (option > 0);
	return;
}
void addAccountMenu(struct AccountTicketingData* ticketingData) {
	int i, hasFree = 0;
	for (i = 0; i < ticketingData->ACCOUNT_MAX_SIZE; i++)
	{
		if (ticketingData->accounts[i].number == 0) {
			hasFree = 1;
			break;
		}
	}
	if (hasFree == 0) {
		printf("ERROR: Account listing is FULL, call ITS Support!\n\n");
		pauseExecution();
	}
	else
	{
		getAccount(ticketingData->accounts, i, ticketingData->ACCOUNT_MAX_SIZE);
		printf("\n*** New account added! ***\n\n");
		pauseExecution();
	}
	return;
}
void modifyAccountMenu(struct AccountTicketingData* ticketingData)
{
	int indexAccount = findAccountIndexByAcctNum(-1, ticketingData->accounts, ticketingData->ACCOUNT_MAX_SIZE, 1);
	updateAccount(&ticketingData->accounts[indexAccount]);
	return;
}
void deleteAccountMenu(struct AccountTicketingData* ticketingData, int accountNumber)
{
	char confirmationDelete;
	int ticketCount;
	int indexAccount = findAccountIndexByAcctNum(-1, ticketingData->accounts, ticketingData->ACCOUNT_MAX_SIZE, 1);

	if (ticketingData->accounts[indexAccount].number == accountNumber)
	{
		printf("\nERROR: You can't remove your own account!\n\n");
		pauseExecution();
	}
	else
	{
		printf("\n");
		displayAccountDetailHeader();
		displayAccountDetailRecord(&ticketingData->accounts[indexAccount]);
		printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
		confirmationDelete = getCharOption("yYnN");
		if (confirmationDelete == 'Y' || confirmationDelete == 'y') {
			ticketCount = deleteTickets(ticketingData->tickets, ticketingData->TICKET_MAX_SIZE, ticketingData->accounts[indexAccount].number);
			ticketingData->accounts[indexAccount].number = 0;
			printf("\n*** Account Removed! (%d ticket(s) removed) ***\n\n", ticketCount);//todo check numbers of tickets
			pauseExecution();
		}

	}
	return;
}



void displayAllAccountDetailRecords(const struct Account* accounts, int length)
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
			updateAccountTypeMenu(account);
			break;
		case 2:
			updatePersonMenu(&account->person);
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
void updateAccountTypeMenu(struct Account* account)
{
	printf("\nEnter the account type (A=Agent | C=Customer): ");
	account->type = getCharOption("AC");
	if (account->type == 'A')
	{
		printf("\nAgent type accounts require a user login.  Please enter this information now:\n");

		getUserLogin(&account->userLogin);
	}
	else {
		struct UserLogin empty = { { 0 } };
		account->userLogin = empty;
	}
}
void updatePersonMenu(struct Person* person)
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
			getCString(person->fullName, 1, MAX_SIZE_STRING);
			break;
		case 2:
			printf("\nEnter the household Income: $");
			person->income = getPositiveDouble();
			break;
		case 3:
			printf("\nEnter the country (30 chars max.): ");
			getCString(person->country, 1, MAX_SIZE_STRING);
			upperCase(person->country);
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
			printf("\n");
			getPassword(userLogin->password);
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