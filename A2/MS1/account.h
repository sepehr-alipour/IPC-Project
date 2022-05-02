// #############################################################################################
//  Assignment: 2 
//  Milestone : 1
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

struct Person {
	char fullName[30 + 1]; //consider \0 character
	int brithYear;
	double income;
	char country[30 + 1];//consider \0 character
};
struct UserLogin {
	char userName[10 + 1];//consider \0 character
	char password[8 + 1];//consider \0 character
};
struct Account {
	int  number;
	char type;
	struct Person person;
	struct UserLogin userLogin;
};

void getAccount(struct Account* account, struct AccountTicketingData* ticketingData);
void getPerson(struct Person* person);
void getUserLogin(struct UserLogin* userLogin);
void updateAccount(struct Account* account);
void updatePerson(struct Person* person);
void updateUserLogin(struct UserLogin* userLogin);
void getUserName(char* username);
void getPassword(char* password);
#endif // !ACCOUNT_H_
