// #######################################################################
//
//  Assignment: 1 
//  Milestone:  MS4
//  Main logic/test
//
// #######################################################################
// #############################################################################################
//  Assignment: 1 
//  Milestone : 4
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################

// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
//                   DO NOT MODIFY THIS FILE!!!!
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "account.h"
#include "accountTicketingUI.h"

// Macro's: helpers for default data
#define ACCOUNT_SIZE 50
#define INIT_DATA_SIZE 5

// Function Prototype for populating some default values
void populateAccounts(struct Account accounts[], int arrSize);

// Main entry-point to the application
int main(void)
{
    struct Account accounts[ACCOUNT_SIZE] = { {0} };

    // setup some test accounts:
    populateAccounts(accounts, ACCOUNT_SIZE);

    // launch application logic
    applicationStartup(accounts, ACCOUNT_SIZE);
 
    return 0;
}

void populateAccounts(struct Account accounts[], int arrSize)
{
    int i, max = arrSize < INIT_DATA_SIZE ? arrSize : INIT_DATA_SIZE;
    struct Account tmp[INIT_DATA_SIZE] = {
        { 50001, 'C', {"Silly Sally", 1990, 150000.10, "CANADA"}, {"", ""}  },
        { 50028, 'A',    {"Fred Flintstone", 1972, 2250400.22, "AFRICA"}, {"Bedrock-10", "yabadaba"} },
        { 50004, 'C', {"Betty Boop", 1978, 250800.74, "INDIA"}, {"", ""}},
        { 50008, 'A',    {"Will Smith", 1952, 2350600.82, "U.S.A."}, {"MIBAgent-J", "theboss1"} },
        { 50020, 'C', {"Shrimpy Shrimp", 2000, 350500.35, "KOREA"}, {"", ""} }
    };
	
    for (i = 0; i < max; i++)
    {
        accounts[i] = tmp[i];
    }
}
