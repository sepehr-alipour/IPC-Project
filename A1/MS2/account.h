// #############################################################################################
//  Assignment: 1 
//  Milestone : 2
// #############################################################################################
// Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################
#define MAXIMUM_LENGTH 30
struct Person {
	char fullName[30+1]; //consider \0 character
	int brithYear;
	double income;
	char country[30+1];//consider \0 character
};
struct UserLogin {
	char userName[10+1];//consider \0 character
	char password[8+1];//consider \0 character
};
struct Account {
	int  number;
	char type;
};