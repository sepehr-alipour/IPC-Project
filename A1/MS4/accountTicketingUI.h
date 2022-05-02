// #############################################################################################
//  Assignment: 1 
//  Milestone : 4
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################
#ifndef ACCOUNT_TICKETING_UI_H_
#define ACCOUNT_TICKETING_UI_H_
#include"account.h"

void displayAccountDetailHeader(void);
void displayAccountDetailRecord(const struct Account* account);
void applicationStartup(struct Account accounts[], int length);
int menuLogin(const struct Account accounts[], int length);
void menuAgent(struct Account accounts[], int length, const struct Account* account);
int findAccountIndexByAcctNum(int accountID, const struct Account accounts[], int length, int shouldPromt);
void displayAllAccountDetailRecords(const struct Account accounts[], int length);
void pauseExecution(void);
#endif // !ACCOUNT_TICKETING_UI_H_
