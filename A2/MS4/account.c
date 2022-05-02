// #############################################################################################
//  Assignment: 2 
//  Milestone : 4
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################
#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "commonHelpers.h"
#include "account.h"
#include "accountTicketingUI.h"

void getAccount(struct Account* accounts, int index, int length) {
	int i;
	int greatest = 0;
	for (i = 0; i < length; i++)
	{
		if (greatest < accounts[i].number)
			greatest = accounts[i].number;
	}
	struct Account newAccount = { 0 };
	newAccount.number = greatest + 1;
	printf("New Account Data (Account#:%d)\n", newAccount.number);
	printf("----------------------------------------\n");
	printf("Enter the account type (A=Agent | C=Customer): ");
	newAccount.type = getCharOption("AC");
	getPerson(&newAccount.person);
	if (newAccount.type == 'A')
		getUserLogin(&newAccount.userLogin);
	accounts[index] = newAccount;
	return;
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
	return;
}
void getUserLogin(struct UserLogin* userLogin) {

	printf("\n");
	printf("User Login Data Input\n");                  
	printf("----------------------------------------\n");

	getUserName(userLogin->userName);
	getPassword(userLogin->password);
	return;
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
				printf("ERROR:  The user login must NOT contain whitespace characters.\n");
				break;
			}
			else
			{
				invalid = 0;
			}


		}

	} while (invalid == 1);
	return;
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
		printf("Enter the password (must be %d chars in length): ", MAX_SIZE_PASSWORD);
		getCString(password, MAX_SIZE_PASSWORD, MAX_SIZE_PASSWORD);

		for (i = 0; password[i] != '\0'; i++)
		{
			if (isdigit(password[i]))
			{
				digitCount++;
			}
			else if (password[i] > 'a' && password[i] < 'z')
			{
				lowerCaseCount++;
			}
			else if (password[i] > 'A' && password[i] < 'Z')
			{
				upperCaseCount++;
			}
			else if (password[i] == '@'
				|| password[i] == '!'
				|| password[i] == '#'
				|| password[i] == '$'
				|| password[i] == '^'
				|| password[i] == '&'
				|| password[i] == '*')
			{
				symbolCount++;
			}

		}
		if (digitCount < 2 || lowerCaseCount < 2 || upperCaseCount < 2 || symbolCount < 2)
		{
			printf("SECURITY: Password must contain 2 of each:\n");
			printf("          Digit: 0-9\n");
			printf("          UPPERCASE character\n");
			printf("          lowercase character\n");
			printf("          symbol character: !@#$%%^&*\n");
		}
	} while (digitCount != 2 || lowerCaseCount != 2 || upperCaseCount != 2 || symbolCount != 2);
	return;
}

int loadAccounts(struct Account* accounts, int length)
{
	FILE* fp = NULL;
	int i = 0;
	char filename[] = "accounts.txt";
	fp = fopen(filename, "r");
	if (fp != NULL) {
		while (i < length && fscanf(fp, "%d~%c~%31[^~]~%d~%lf~%31[^\n~]~"
			, &accounts[i].number
			, &accounts[i].type
			, accounts[i].person.fullName
			, &accounts[i].person.brithYear
			, &accounts[i].person.income
			, accounts[i].person.country) != EOF) {
			if (accounts[i].type == 'A')
			{

				fscanf(fp, "%11[^~]~%9[^\n]\n"
					, accounts[i].userLogin.userName
					, accounts[i].userLogin.password
				);
			}
			i++;
		}

		fclose(fp);
		fp = NULL;
	}
	else {
		printf("Failed to open file\n");
	}

	return i;
}
int saveAccounts(struct Account* accounts, int length)
{
	int i, counter = 0;
	FILE* fp = fopen("accounts.txt", "w");
	if (fp != NULL)
	{
		for (i = 0; i < length; i++)
		{
			if (accounts[i].number > 0)
			{
				fprintf(fp, "%d~%c~%s~%d~%.2lf~%s"
					, accounts[i].number
					, accounts[i].type
					, accounts[i].person.fullName
					, accounts[i].person.brithYear
					, accounts[i].person.income
					, accounts[i].person.country

				);
				if (accounts[i].type == 'A')
				{
					fprintf(fp, "~%s~%s\n"
						, accounts[i].userLogin.userName
						, accounts[i].userLogin.password
					);
				}
				else
				{
					fprintf(fp, "\n");
				}
				counter++;
			}
		}
		fclose(fp);
		fp = NULL;
	}
	return counter;
}


