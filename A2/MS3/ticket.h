// #############################################################################################
//  Assignment: 2 
//  Milestone : 4
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################

#ifndef TICKET_H_
#define TICKET_H_
#include "account.h"
#define MAX_SIZE_USERNAME 10
#define MAX_SIZE_PASSWORD 8 
#define MAX_SIZE_STRING 30
#define MAX_SIZE_MESSAGE 20
#define MAX_SIZE_DETAIL 150
struct Message {
	char type;
	char fullName[MAX_SIZE_STRING + 1];
	char message[MAX_SIZE_DETAIL + 1];
};

struct Ticket {
	int id;
	int accountNumber;
	int status;
	char subject[MAX_SIZE_STRING + 1];
	int messageNumbers;
	struct Message messages[MAX_SIZE_MESSAGE];
};
void addTicket(struct Ticket* tickets, struct Account* account, int maxAccountLength, int maxTicketLength);
int deleteTickets(struct Ticket* tickets, int length, int accountNumber);
int displayTicketRecord(const struct Ticket* tickets, int lenght, int status);
void displayTicketHeadr(void);
void displayTicketRecords(struct Ticket* tickets, int length, int mode);
void manageTicket(struct Ticket* tickets, struct Account* account, struct Person person, int maxTicketLength, int maxAccountLength);
void manageTicket(struct Ticket* tickets, struct Account* account, struct Person person, int maxTicketLength, int maxAccountLength);
int loadTickets(struct Ticket* tickets, int length);
void saveTickets(struct Ticket* tickets, int length);

#endif // !TICKET_H_
