// #############################################################################################
//  Assignment: 1 
//  Milestone : 3
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################

#include <stdio.h>
#include "commonHelpers.h"
#include "accountTicketingUI.h"
#include "account.h"

void displayAccountDetailHeader()
{
	printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
	printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
}
void displayAccountDetailRecord(const struct Account* account)
{
	int i;
	char pass[10];
	for (i = 0; account->userLogin.password[i] != '\0'; i++)
	{

		pass[i] = i % 2 == 0 ? account->userLogin.password[i] : '*';
	}
	pass[i] = 0;
	printf("%05d %-9s %-15s %5d %11.2lf %-10s %-10s %8s\n"
		, account->number
		, account->type == 'A' ? "AGENT" : "Customer"
		, account->person.fullName
		, account->person.brithYear
		, account->person.income
		, account->person.country
		, account->userLogin.userName
		, pass);
}