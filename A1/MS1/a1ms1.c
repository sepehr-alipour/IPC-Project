// #############################################################################################
//
//  Assignment:  1 
//  Milestone:   1
//  Description: Main logic/tester
//
// +---------------------------------------------------------+
// | *** The contents of this file is NOT to be modified *** |    
// +---------------------------------------------------------+
//
//                         HOWEVER....
//
// In the development of your solution, you can...
// -----------------------------------------------
// - Comment out the lines of code which call a function you have not yet developed
//   (See each tester function definition to see where you can do this)
// - Uncomment the lines of code previously commented to return the file to its
//   original state so you may fully test your solution.
// 
// #############################################################################################
// #############################################################################################
//  Assignment: 1 
//  Milestone : 1
// #############################################################################################
// Student Name  : 
//  Student ID    : 
//  Student Email : 
//  Course Section: IPC 144 NMM
// #############################################################################################
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "commonHelpers.h"

// -----------------------------------------
// Function Prototypes
void test01_getInteger(void);
void test02_getPositiveInteger(void);
void test03_getIntFromRange(void);
void test04_getIntFromRange(void);
void test05_getDouble(void);
void test06_getPositiveDouble(void);
void test07_getCharOption(void);
void test08_getCString(void);
void test09_getCString(void);
void test10_getCString(void);

// -----------------------------------------
// Main: Entry-point to the application
int main(void)
{
    printf("Assignment 1 Milestone 1\n");
    printf("=============================================\n\n");

    // -----------------------------------------
    // Unit Tests:

    // Integer testers
    test01_getInteger();
    test02_getPositiveInteger();
    test03_getIntFromRange();
    test04_getIntFromRange();

    // Double testers
    test05_getDouble();
    test06_getPositiveDouble();

    // Char tester
    test07_getCharOption();

    // C string testers
    test08_getCString();
    test09_getCString();
    test10_getCString();

    printf("Assignment #1 Milestone #1 completed!\n");

    return 0;
}

// -----------------------------------------
// Function Definitions

void test01_getInteger(void)
{
    int intValue;

    printf("TEST #1 - Instructions:\n"
        "1) Enter the word 'error'  [ENTER]\n"
        "2) Enter the number '-100' [ENTER]\n"
        ":>");

    // You may want to comment the next line if you have not yet created the getInteger function:
    intValue = getInteger();

    printf("////////////////////////////////////////\n");
    printf("TEST #1 RESULT: ");
    if (intValue == -100)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

void test02_getPositiveInteger(void)
{
    int intValue;

    printf("TEST #2 - Instructions:\n"
        "1) Enter the number '-100' [ENTER]\n"
        "2) Enter the number '200'  [ENTER]\n"
        ":>");

    // You may want to comment the next line if you have not yet created the getInteger function:
    intValue = getPositiveInteger();

    printf("////////////////////////////////////////\n");
    printf("TEST #2 RESULT: ");
    if (intValue == 200)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

void test03_getIntFromRange(void)
{
    int intValue;

    printf("TEST #3 - Instructions:\n"
        "1) Enter the word 'error' [ENTER]\n"
        "2) Enter the number '-4'  [ENTER]\n"
        "3) Enter the number '12'  [ENTER]\n"
        "4) Enter the number '-3'  [ENTER]\n"
        ":>");

    // You may want to comment the next line if you have not yet created the getInteger function:
    intValue = getIntFromRange(-3, 11);

    printf("////////////////////////////////////////\n");
    printf("TEST #3 RESULT: ");
    if (intValue == -3)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

void test04_getIntFromRange(void)
{
    int intValue;

    printf("TEST #4 - Instructions:\n"
        "1) Enter the number '14' [ENTER]\n"
        ":>");

    // You may want to comment the next line if you have not yet created the getInteger function:
    intValue = getIntFromRange(-40, 14);

    printf("////////////////////////////////////////\n");
    printf("TEST #4 RESULT: ");
    if (intValue == 14)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

void test05_getDouble(void)
{
    double dblValue;

    printf("TEST #5 - Instructions:\n"
        "1) Enter the word 'error'     [ENTER]\n"
        "2) Enter the number '-150.75' [ENTER]\n"
        ":>");

    // You may want to comment the next line if you have not yet created the getInteger function:
    dblValue = getDouble();

    printf("////////////////////////////////////////\n");
    printf("TEST #5 RESULT: ");
    if (dblValue == -150.75)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

void test06_getPositiveDouble(void)
{
    double dblValue;

    printf("TEST #6 - Instructions:\n"
        "1) Enter the number '-22.11' [ENTER]\n"
        "2) Enter the number '225.55' [ENTER]\n"
        ":>");

    // You may want to comment the next line if you have not yet created the getInteger function:
    dblValue = getPositiveDouble();

    printf("////////////////////////////////////////\n");
    printf("TEST #6 RESULT: ");
    if (dblValue == 225.55)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

void test07_getCharOption(void)
{
    char charValue;

    printf("TEST #7 - Instructions:\n"
        "1) Enter the character 'R' [ENTER]\n"
        "2) Enter the character 'p' [ENTER]\n"
        "3) Enter the character 'r' [ENTER]\n"
        ":>");

    // You may want to comment the next line if you have not yet created the getInteger function:
    charValue = getCharOption("qwerty");

    printf("////////////////////////////////////////\n");
    printf("TEST #7 RESULT: ");
    if (charValue == 'r')
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

void test08_getCString(void)
{
    char cstringValue[7];

    printf("TEST #8: - Instructions:\n"
        "1) Enter the word 'horse'  [ENTER]\n"
        "2) Enter the word 'SENECA' [ENTER]\n"
        ":>");

    // You may want to comment the next line if you have not yet created the getInteger function:
    getCString(cstringValue, 6, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #8 RESULT: ");
    printf("%s (Answer: SENECA)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");
}

void test09_getCString(void)
{
    char cstringValue[7];

    printf("TEST #9: - Instructions:\n"
        "1) Enter the words 'Seneca College' [ENTER]\n"
        "2) Enter the word 'IPC'             [ENTER]\n"
        ":>");

    // You may want to comment the next line if you have not yet created the getInteger function:
    getCString(cstringValue, 3, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #9 RESULT: ");
    printf("%s (Answer: IPC)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");
}

void test10_getCString(void)
{
    char cstringValue[7];

    printf("TEST #10: - Instructions:\n"
        "1) Enter the word 'ipc'    [ENTER]\n"
        "2) Enter the word 'SCHOOL' [ENTER]\n"
        ":>");

    // You may want to comment the next line if you have not yet created the getInteger function:
    getCString(cstringValue, 4, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #10 RESULT: ");
    printf("%s (Answer: SCHOOL)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");
}