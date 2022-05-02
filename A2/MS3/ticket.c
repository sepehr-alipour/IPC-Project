// #############################################################################################
//  Assignment: 2 
//  Milestone : 4
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################

// Uses the time.h library to obtain current year information
// Get the current 4-digit year from the system
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "commonHelpers.h"
#include "ticket.h"
#include "accountTicketingUI.h"

void displayTicketHeadr(void) {
	printf("------ ----- --------------- ------ ------------------------------ --------\n");
	printf("Ticket Acct# Full Name       Status Subject                        Messages\n");
	printf("------ ----- --------------- ------ ------------------------------ --------\n");
	return;
}
void displayTicketRecords(struct Ticket* tickets, int length, int mode) {
	int i, hasTicket, status;
	do {
		displayTicketHeadr();

		for (i = 0; i < length; i++)
		{

			if (tickets[i].id != 0)
			{
				if (mode == 0 && tickets[i].status == 1 && tickets[i].messageNumbers == 1) {
					printf("%06d %5d %-15s %-6s %-30s %5d\n",
						tickets[i].id
						, tickets[i].accountNumber
						, tickets[i].messages->fullName
						, "ACTIVE"
						, tickets[i].subject
						, tickets[i].messageNumbers);
					status = tickets[i].status;
				}
				else if (mode == 2 && tickets[i].status == 1) {
					printf("%06d %5d %-15s %-6s %-30s %5d\n",
						tickets[i].id
						, tickets[i].accountNumber
						, tickets[i].messages->fullName
						, "ACTIVE"
						, tickets[i].subject
						, tickets[i].messageNumbers);
					status = tickets[i].status;

				}
				else if (mode == 1 && tickets[i].status == 0) {

					printf("%06d %5d %-15s %-6s %-30s %5d\n",
						tickets[i].id
						, tickets[i].accountNumber
						, tickets[i].messages->fullName
						, "CLOSED"
						, tickets[i].subject
						, tickets[i].messageNumbers);
					status = tickets[i].status;

				}

			}


		}
		printf("------ ----- --------------- ------ ------------------------------ --------\n");
		printf("\nEnter the ticket number to view the messages or\n");
		printf("0 to return to previous menu: ");
		hasTicket = displayTicketRecord(tickets, length, status);

	} while (hasTicket == 0);
	printf("\n");
	return;
}
int displayTicketRecord(const struct Ticket* tickets, int length, int status) {
	int option, i, hasTicket = 0, indexTicket, backMenu = 0;

	option = getInteger();
	if (option == 0) {
		backMenu = 1;
		return backMenu;
	}
	for (i = 0; i < length; i++)
	{
		if (option == tickets[i].id && tickets[i].status == status)
		{
			hasTicket = 1;
			indexTicket = i;
		}
	}
	if (!hasTicket)
	{
		printf("\nERROR: Invalid ticket number.\n\n");
		pauseExecution();
	}
	else {
		printf("\n================================================================================\n");
		printf("%06d (%s) Re: %s\n",
			tickets[indexTicket].id
			, tickets[indexTicket].status == 0 ? "CLOSED" : "OPEN"
			, tickets[indexTicket].subject);
		printf("================================================================================\n");

		for (i = 0; tickets[indexTicket].messages[i].type != 0; i++)
		{
			printf("%s (%s):\n", tickets[indexTicket].messages[i].type == 'C' ? "CUSTOMER" : "AGENT", tickets[indexTicket].messages[i].fullName);
			printf("   %s\n\n", tickets[indexTicket].messages[i].message);
		}
		pauseExecution();
	}
	return backMenu;
}

void addTicket(struct Ticket* tickets, struct Account* account, int maxAccountLength, int maxTicketLength) {
	int i, indexTicke, hasFree = 0;
	int greatest = 0;
	char confirmation;
	int indexAccount = findAccountIndexByAcctNum(-1, account, maxAccountLength, 1);
	if (account[indexAccount].type == 'A') {
		printf("\nERROR: Agent accounts can't have tickets!\n");
		return;
	}
	for (i = 0; i < maxTicketLength; i++)
	{
		if (tickets[i].id == 0 && hasFree == 0) {
			hasFree = 1;
			indexTicke = i;

		}
		if (greatest < tickets[i].id)
			greatest = tickets[i].id;
	}

	if (hasFree == 0)
		printf("ERROR: Ticket listing is FULL, call ITS Support!");
	else
	{

		struct Ticket newTicket = { 0 };
		struct Message newMessage = { 0 };
		strcpy(newMessage.fullName, account[indexAccount].person.fullName);
		newMessage.type = account[indexAccount].type;
		newTicket.id = greatest + 1;
		newTicket.accountNumber = account[indexAccount].number;
		newTicket.status = 1;
		newTicket.messageNumbers = 1;
		printf("\n");
		displayAccountDetailHeader();
		displayAccountDetailRecord(&account[indexAccount]);
		printf("\nAdd a new ticket for this customer? ([Y]es|[N]o): ");
		confirmation = getCharOption("yYnN");
		if (confirmation == 'Y' || confirmation == 'y') {
			printf("\nNew Ticket (Ticket#:%06d)", newTicket.id);
			printf("\n----------------------------------------\n");
			printf("Enter the ticket SUBJECT (30 chars. maximum): ");
			getCString(newTicket.subject, 1, 30);
			newTicket.messages[0] = newMessage;
			printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
			getCString(newTicket.messages[0].message, 1, 150);
			tickets[indexTicke] = newTicket;
			printf("\n*** New ticket created! ***\n");
		}

	}
	return;
}

void manageTicket(struct Ticket* tickets, struct Account* account, struct Person person, int maxTicketLength, int maxAccountLength) {
	int ticketNumber, i, option, indextTicket, accountIndex;
	char confirmation;
	printf("\nEnter ticket number: ");
	ticketNumber = getPositiveInteger();
	for (i = 0; i < maxTicketLength; i++)
	{
		if (ticketNumber == tickets[i].id)
		{
			indextTicket = i;
			break;
		}
	}
	accountIndex = findAccountIndexByAcctNum(tickets[indextTicket].accountNumber, account, maxAccountLength, 0);
	do {
		struct Message newMessage = { 0 };

		printf("\n----------------------------------------\n");
		printf("Ticket %06d - Update Options\n", ticketNumber);
		printf("----------------------------------------\n");
		printf("Status  : %s\n", tickets[indextTicket].status == 1 ? "ACTIVE" : "CLOSED");
		printf("Subject : %s\n", tickets[indextTicket].subject);
		printf("Acct#   : %d\n", account[accountIndex].number);
		printf("Customer: %s\n", account[accountIndex].person.fullName);
		printf("----------------------------------------\n");
		printf("1) Add CUSTOMER message\n");
		printf("2) Add AGENT message\n");
		printf("3) Close ticket\n");
		printf("4) Re-activate ticket\n");
		printf("0) Done");
		printf("\nSelection: ");
		option = getIntFromRange(0, 4);

		switch (option)
		{
		case 1:
			printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
			getCString(newMessage.message, 1, 150);
			newMessage.type = 'C';
			strcpy(newMessage.fullName, account[accountIndex].person.fullName);
			tickets[i].messages[tickets[i].messageNumbers] = newMessage;
			tickets[i].messageNumbers += 1;

			break;
		case 2:
			printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
			getCString(newMessage.message, 1, 150);
			newMessage.type = 'A';
			strcpy(newMessage.fullName, person.fullName);
			tickets[i].messages[tickets[i].messageNumbers] = newMessage;
			tickets[i].messageNumbers += 1;
			break;
		case 3:
			if (tickets[i].status == 0)
				printf("\nERROR: Ticket is already closed!\n");
			else {
				printf("\nAre you sure you CLOSE this ticket? ([Y]es|[N]o): ");
				confirmation = getCharOption("yYnN");
				if (confirmation == 'y' || confirmation == 'Y') {

					tickets[i].status = 0;
					printf("\n*** Ticket closed! ***\n");

				}
			}
			break;
		case 4:
			if (tickets[i].status == 1)
				printf("\nERROR: Ticket is already active!\n");
			else {
				printf("\nAre you sure you want to RE-ACTIVATE this closed ticket? ([Y]es|[N]o): ");
				confirmation = getCharOption("yYnN");
				if (confirmation == 'y' || confirmation == 'Y') {

					tickets[i].status = 1;
					printf("\n*** Ticket re-activated! ***\n");

				}
			}
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (option > 0);

	return;
}
int deleteTickets(struct Ticket* tickets, int length, int accountNumber) {
	int i, count = 0;
	for (i = 0; i < length; i++)
	{
		if (tickets[i].accountNumber == accountNumber)
		{
			struct Ticket empty = { 0 };
			tickets[i] = empty;
			count++;
		}
	}
	return count;
}
int loadTickets(struct Ticket* tickets, int length) {
	FILE* fp = NULL;
	int i = 0, j;
	char filename[] = "tickets.txt";
	fp = fopen(filename, "r");
	if (fp != NULL) {
		while (i < length && fscanf(fp, "%d|%d|%d|%31[^|]|%d|"
			, &tickets[i].id
			, &tickets[i].accountNumber
			, &tickets[i].status
			, &tickets[i].subject
			, &tickets[i].messageNumbers

		) != EOF) {
			for (j = 0; j < tickets[i].messageNumbers; j++)
			{
				fscanf(fp, "%c|%31[^|]|%151[^|]|"
					, &tickets[i].messages[j].type
					, &tickets[i].messages[j].fullName
					, tickets[i].messages[j].message);
			}
			fprintf(fp, "\n");
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
void saveTickets(struct Ticket* tickets, int length)
{
	FILE* fp;
	int i = 0, j;
	fp = fopen("tickets.txt", "w");
	if (fp != NULL)
	{
		for (i = 0; i < length; i++)
		{
			if (tickets[i].id > 0) {
				fprintf(fp, "%d|%d|%d|%s|%d"
					, tickets[i].id
					, tickets[i].accountNumber
					, tickets[i].status
					, tickets[i].subject
					, tickets[i].messageNumbers);
				for (j = 0; j < tickets[i].messageNumbers; j++)
				{
					if (tickets[i].messages[j].fullName > 0) {
						fprintf(fp, "|%c|%s|%s"
							, tickets[i].messages[j].type
							, tickets[i].messages[j].fullName
							, tickets[i].messages[j].message);
					}

				}
				fprintf(fp, "\n");
			}
		}


		fclose(fp);
		fp = NULL;
	}
}

