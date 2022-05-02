// #############################################################################################
//  Assignment: 2 
//  Milestone : 2
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################

#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#define MAX_SIZE_USERNAME 10
#define MAX_SIZE_PASSWORD 8 
#define MAX_SIZE_STRING 30
struct Person {
	char fullName[MAX_SIZE_STRING + 1]; //consider \0 character
	int brithYear;
	double income;
	char country[MAX_SIZE_STRING + 1];//consider \0 character
};
struct UserLogin {
	char userName[MAX_SIZE_USERNAME + 1];//consider \0 character
	char password[MAX_SIZE_PASSWORD + 1];//consider \0 character
};
struct Account {
	int  number;
	char type;
	struct Person person;
	struct UserLogin userLogin;
};

void getAccount(struct Account* accounts,int index, int length);
void getPerson(struct Person* person);
void getUserLogin(struct UserLogin* userLogin);
void updateAccount(struct Account* account);
void updatePerson(struct Person* person);
void updateUserLogin(struct UserLogin* userLogin);
void getUserName(char* username);
void getPassword(char* password);
#endif // !ACCOUNT_H_
