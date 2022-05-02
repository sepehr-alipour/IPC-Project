// #############################################################################################
//  Assignment: 2 
//  Milestone : 1
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################
#ifndef ACCOUNT_TICKETING_UI_H_
#define ACCOUNT_TICKETING_UI_H_
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
void applicationStartup(struct AccountTicketingData* ticketingData);
int menuLogin(const struct Account* accounts, int length);
void menuAgent(struct AccountTicketingData* ticketingData, const struct Account* account);
int findAccountIndexByAcctNum(int accountID, const struct Account* accounts, int length, int shouldPromt);
void displayAllAccountDetailRecords(const struct Account* accounts, int length);
void pauseExecution(void);
void addAccount();
void modifyAccount();
void deleteAccount();
#endif // !ACCOUNT_TICKETING_UI_H_
