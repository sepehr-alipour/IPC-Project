// #############################################################################################
//  Assignment: 2 
//  Milestone : 4
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################
#ifndef ACCOUNT_TICKETING_UI_H_
#define ACCOUNT_TICKETING_UI_H_
#include "commonHelpers.h"
#include "account.h"
#include "ticket.h"


struct AccountTicketingData
{
	struct Account* accounts;
	// array of accounts 
	const int ACCOUNT_MAX_SIZE;
	// maximum elements for account array 
	struct Ticket* tickets;
	// array of tickets 
	const int TICKET_MAX_SIZE;
	// maximum elements for ticket array 
};

void displayAccountDetailHeader(void);
void displayAccountDetailRecord(const struct Account* account);
void displayAllAccountDetailRecords(const struct Account* accounts, int length);
void applicationStartup(struct AccountTicketingData* ticketingData);
int menuLogin(const struct Account* accounts, int length);
void menuAgent(struct AccountTicketingData* ticketingData, const struct Account* account);
int findAccountIndexByAcctNum(int accountID, const struct Account* accounts, int length, int shouldPromt);
void pauseExecution(void);
void addAccountMenu(struct AccountTicketingData* ticketingData);
void modifyAccountMenu(struct AccountTicketingData* ticketingData);
void deleteAccountMenu(struct AccountTicketingData* ticketingData, int accountNumber);
void updateAccountTypeMenu(struct Account* account);
void updatePersonMenu(struct Person* person);

#endif // !ACCOUNT_TICKETING_UI_H_
