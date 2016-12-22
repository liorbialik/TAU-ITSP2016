#pragma once
/*
ex3 - Header.h:
- The header file for BankManager.c which contains the execution for all commands in Command file.
- This file contains the definitions, used structs and the decleration which used to call the main
function in BankManager.c
*/

#ifndef BankManager_H
#define BankManager_H

///* Constants: */


/* Libraries: */
#include <Windows.h>


///* Struct Declarations: */
// struct for a single account
typedef struct account {
	unsigned long int accountNumber;
	long long initialBalance;
	long long currentBalance;
	long long totalDepositeSum;
	long long totalWithdrawalSum;
	long long ammountOfDeposits;
	long long ammountOfWithdrawals;
	// another field for the account's mutex
	struct account *nextInList;
}account;


// struct that will be using the the runtimeLogFile
typedef struct logFile {
	FILE logFile;
	// another field for the logFile's mutex
}logFile;


// struct for all accounts
typedef struct allAccounts {
	account *accountListHeadPtr;
	unsigned long long totalNumberOfAccounts;
	logFile *runtimeLogFilePtr;
} allAccounts; //Added allAccounts as a name for the struct

/* Function Declarations: */

// enumerations for possible commands:
enum inputCommands { createAccountCmd, closeAccountCmd, printBalancesCmd, depositeCmd, withdrawalCmd };

// struct for parsing the command line
struct Parsing {
	char *command;
	unsigned long long AccountNumber;
	double Amount;
	int commandTypePosition;
};

struct Parsing ParseLineIntoCommand(char *);


int executeBankManager(int argc, char *argv[]);

#endif#pragma once
#pragma once