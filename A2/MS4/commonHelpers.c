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

#include <time.h>
#include <stdio.h>
#include "commonHelpers.h"
int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}


// As demonstrated in the course notes: https://ict.senecacollege.ca//~ipc144/pages/content/formi.html#buf 
// Empty the standard input buffer 
void clearStandardInputBuffer(void) {
	while (getchar() != '\n') {
		; // On purpose: do nothing 
	}
}
int getInteger() {
	char returnChar = '0';
	int number;
	do {
		scanf("%d%c", &number, &returnChar);
		if (returnChar == '\n')
			return number;
		else {
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
	} while (returnChar != '\n');

	return number;
}
int getPositiveInteger() {

	int number = 0;
	do {
		number = getInteger();
		if (number > 0)
			return number;
		else {
			printf("ERROR: Value must be a positive integer greater than zero: ");
		}
	} while (number <= 0);
	return number;
}

double getDouble() {
	char returnChar;
	double number;
	do {
		scanf("%lf%c", &number, &returnChar);
		if (returnChar != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	} while (returnChar != '\n');
	return number;
}
double getPositiveDouble() {

	double number;
	do {
		number = getDouble();
		if (number <= 0)
		{
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
	} while (number <= 0);
	return number;
}
int getIntFromRange(int lowerBound, int upperBound) {

	int number;
	do {
		number = getInteger();
		if (number >= lowerBound && number <= upperBound)
			return number;
		else {
			printf("ERROR: Value must be between %d and %d inclusive: ", lowerBound, upperBound);
		}
	} while (number <= lowerBound || number >= upperBound);
	return number;
}

char getCharOption(const char string[]) {
	char character;
	char returnChar = 0;
	int hasChar = 0;
	int i;

	do {
		scanf("%c%c", &character, &returnChar);
		if (returnChar == '\n') {
			for (i = 0; string[i] != '\0'; i++)
			{
				if (character == string[i])
					hasChar++;
			}

		}
		else {
			clearStandardInputBuffer();

		}
		if (hasChar == 0) {
			printf("ERROR: Character must be one of [%s]: ", string);
		}
		else {
			return character;
		}


	} while (hasChar == 0);
	return character;
}

void getCString(char* string, int lowerBounds, int upperBounds) {
	char word[200] = { 0 };
	int i, stringLength, isInvalid;
	char returnChar = 0;

	do {
		isInvalid = 0;
		scanf("%[^\n]%c", word, &returnChar);

		if (returnChar == '\n')
		{
			for (stringLength = 0; word[stringLength] != '\0'; stringLength++)
			{

			}
			if (lowerBounds == upperBounds && stringLength != lowerBounds) {
				printf("ERROR: String length must be exactly %d chars: ", lowerBounds);
				isInvalid++;
			}
			else if (stringLength > upperBounds) {
				printf("ERROR: String length must be no more than %d chars: ", upperBounds);
				isInvalid++;
			}
			else if (stringLength < lowerBounds || stringLength > upperBounds) {
				printf("ERROR: String length must be between %d and %d chars: ", lowerBounds, upperBounds);
				isInvalid++;
			}


			else {

				for (i = 0; word[i] != '\0'; i++)
					string[i] = word[i];
				string[i] = 0;
			}

		}
		else {
			isInvalid++;
			//clearStandardInputBuffer();
		}
	} while (isInvalid > 0);

}
void upperCase(char* string) {
	int i;
	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] >= 'a' && string[i] <= 'z')
			string[i] -= 32;
	}
	return;
}
