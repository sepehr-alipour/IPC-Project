// #############################################################################################
//  Assignment: 2 
//  Milestone : 1
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "accountTicketingUI.h"
#include "account.h"
#include "commonHelpers.h"



void getAccount(struct Account* account, struct AccountTicketingData* ticketingData){
	int i;
	int greatest = 0;
	for (i = 0; i < ticketingData->ACCOUNT_MAX_SIZE; i++)
	{
		if (greatest < ticketingData->accounts[i].number)
			greatest = ticketingData->accounts[i].number;
	}
	account->number = greatest + 1;
	printf("New Account Data (Account#:%d)\n", account->number);
	printf("----------------------------------------\n");
	//printf("Enter the account number: ");
	//account->number = getPositiveInteger();
	printf("Enter the account type (A=Agent | C=Customer): ");
	account->type = getCharOption("AC");
	getPerson(&account->person);
	if (account->type == 'A')
		getUserLogin(&account->userLogin);
}
void getPerson(struct Person* person) {

	printf("\n");
	printf("Person Data Input\n");
	printf("----------------------------------------\n");

	printf("Enter the person's full name (30 chars max): ");
	getCString(person->fullName, 1, 30);
	printf("Enter birth year (current age must be between 18 and 110): ");
	person->brithYear = getIntFromRange(1911, 2003);
	printf("Enter the household Income: $");
	person->income = getPositiveDouble();
	printf("Enter the country (30 chars max.): ");
	getCString(person->country, 1, 30);
	upperCase(person->country);
}
void getUserLogin(struct UserLogin* userLogin) {

	printf("\n");
	printf("User Login Data Input\n");                    // *** DO NOT MODIFY THIS LINE ***
	printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***

	// Add the necessary code to get user input for each UserLogin member:
	// !!! <STUDENT CODE HERE> !!!
	getUserName(userLogin->userName);
	getPassword(userLogin->password);
}

void getUserName(char* username) {
	int i, invalid;
	do
	{
		printf("Enter user login (10 chars max): ");
		getCString(username, 1, 10);

		for (i = 0; username[i] != '\0'; i++)
		{
			if (username[i] == ' ') {
				invalid = 1;
				printf("ERROR: The user login must NOT contain whitespace characters.\n");
				break;
			}
			else
			{
				invalid = 0;
			}


		}

	} while (invalid == 1);
}
void getPassword(char* password) {
	int i;
	int symbolCount;
	int upperCaseCount;
	int lowerCaseCount;
	int digitCount;
	do
	{
		symbolCount = 0;
		upperCaseCount = 0;
		lowerCaseCount = 0;
		digitCount = 0;
		printf("Enter the password (must be 8 chars in length): ");
		getCString(password, 8, 8);

		for (i = 0; password[i]!='\0'; i++)
		{
			if (isdigit(password[i]))
			{
				digitCount++;
			}
			if (password[i] > 'a' && password[i] < 'z')
			{
				lowerCaseCount++;
			}
			if (password[i] > 'A' && password[i] < 'Z')
			{
				upperCaseCount++;
			}
			else
			{
				symbolCount++;
			}

		}
		if (digitCount < 2 || lowerCaseCount < 2 || upperCaseCount < 2 || lowerCaseCount < 2)
		{
			printf("SECURITY: Password must contain 2 of each:\n");
			printf("          Digit: 0 - 9\n");
			printf("          UPPERCASE character\n");
			printf("          lowercase character\n");
			printf("          symbol character : !@#$^&*\n");
		}
	} while (digitCount != 2 && lowerCaseCount != 2 && upperCaseCount != 2 && lowerCaseCount != 2);
}

