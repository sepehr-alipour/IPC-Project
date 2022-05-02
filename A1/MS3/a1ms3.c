// #############################################################################################
//  Assignment: 1 
//  Milestone : 3
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "account.h"
#include "accountTicketingUI.h"

// ------------------------------------------------------------------
// Main entry point to application:

int main(void)
{
	// *** NOTE: No other variables are allowed to be declared ***
	struct Account account = { 0 };                             // *** DO NOT MODIFY THIS LINE ***

	printf("Assignment 1 Milestone 3 - Tester\n");              // *** DO NOT MODIFY THIS LINE ***
	printf("=============================================\n");  // *** DO NOT MODIFY THIS LINE ***

	// ---------------------------------------------------------
	// Account Data
	// ---------------------------------------------------------
	// Input (new record)
	//________________(__________________);   // Call function to get user input for a new "Account"
	getAccount(&account);
	// ---------------------------------------------------------
	// Person Data
	// ---------------------------------------------------------
	// Input (new record)
	//________________(__________________);   // Call function to get user input for a new "Person"
	getPerson(&account.person);
	// ---------------------------------------------------------
	// UserLogin Data
	// ---------------------------------------------------------
	// Input (new record)
	//________________(__________________);   // Call function to get user input for a new "UserLogin"
	getUserLogin(&account.userLogin);
	// ---------------------------------------------------------
	// Display formatted Account details
	// ---------------------------------------------------------
	//_______________________________;         // Call function to display the account detail header
	// ________________(__________________);   // Call function to display an account detail record

	putchar('\n');
	printf("Account, Person, and User Login test completed!\n");  // *** DO NOT MODIFY THIS LINE ***
	displayAccountDetailHeader();
	displayAccountDetailRecord(&account);
	return 0;       // *** DO NOT MODIFY THIS LINE ***
}
