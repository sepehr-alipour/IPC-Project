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
#include "account.h"

void getAccount(struct Account* account) {
	printf("Account Data: New Record\n");
	printf("----------------------------------------\n");
	printf("Enter the account number: ");
	account->number = getPositiveInteger();
	printf("\nEnter the account type (A=Agent | C=Customer): ");
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
}
void getUserLogin(struct UserLogin* userLogin) {

	printf("\n");
	printf("User Login Data Input\n");                    // *** DO NOT MODIFY THIS LINE ***
	printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***

	// Add the necessary code to get user input for each UserLogin member:
	// !!! <STUDENT CODE HERE> !!!
	printf("Enter user login (10 chars max): ");
	getCString(userLogin->userName, 1, 10);
	printf("Enter the password (must be 8 chars in length): ");
	getCString(userLogin->password, 8, 8);
}