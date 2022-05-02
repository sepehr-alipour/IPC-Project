// #############################################################################################
//  Assignment: 2 
//  Milestone : 2
// #############################################################################################
//  Student Name  : Sepehr Alipour 
//  Student ID    : 107296212
//  Student Email : salipour2@myseneca.ca
//  Course Section: IPC 144 NMM
// #############################################################################################
#ifndef COMMONHELPERS_H_
#define COMMONHELPERS_H_

int currentYear(void);
void clearStandardInputBuffer(void);
int getInteger(void);
int getPositiveInteger(void);
double getDouble(void);
double getPositiveDouble(void);
int getIntFromRange(int lowerBound, int upperBound);
char getCharOption(const char string[]);
void getCString(char* string, int lowerBounds, int upperBounds);
void upperCase(char* string);
#endif // !COMMON_HELPERS_H_
