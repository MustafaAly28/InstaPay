#pragma once
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
namespace DataLayer{
const string PersonalInfoFile = "Personal.txt";
const string AccountsInfoFile = "Accounts.txt";
const string AddressInfoFile = "Address.txt";
const string TransactionsInfoFile = "TransactionsHistory.txt";
const int USERS_COUNT = 10;
int AddingUsersCounter = 0;
const int MAX_TRANSACTIONS_PER_USER = 10;
int AddingTransactionsCounter = 0;


struct StAddress
{
	string Street;
	string City;
	string HomeNumber;
};

struct StAccount
{
	double Balance;
	string CVVCode;
	string ExpirationDate;
	string BankName;
	string CardNumber;
	string PINCode;
	string HolderName;
	StTransactions TransactionsFrom[MAX_TRANSACTIONS_PER_USER]; // Transactions (From) History Of User
	StTransactions TransactionsTo[MAX_TRANSACTIONS_PER_USER];  // Transactions (To) History Of User
	StTransactions Deposits[MAX_TRANSACTIONS_PER_USER];
	StTransactions Withdrawals[MAX_TRANSACTIONS_PER_USER];
	int TransactionsCountFrom = 0;
	int TransactionsCountTo = 0;
	int DepositsCount = 0;
	int WithdrawalsCount = 0;
};

struct StTransactions
{
	string PhoneNumber_From;
	string PhoneNumber_To;
	string Date;
	double Amount;
};

struct StUser
{
	string UserName;
	int Id;
	string Phone;
	string Password;
	string Email;
	StAddress Address;
	StAccount Account;											    // Each User Can Create One Account Only
	StAccount AccountsList[3];	   							    // Each User Can Create Three Accounts Only 
	
	int CountAccounts = 0;
	
};

StUser Users[USERS_COUNT];
}
