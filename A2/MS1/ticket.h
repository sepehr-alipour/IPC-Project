// #############################################################################################
//  Assignment: 2 
//  Milestone : 1
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################

#ifndef TICKET_H_
#define TICKET_H_

struct Message {
	char type;
	char fullName[30 + 1];
	char message[150 + 1];
};

struct Ticket {
	int id;
	int accountNumber;
	int status;
	char subject[30 + 1];
	int messageNumbers;
	struct Message messages[20];
};

#endif // !TICKET_H_
