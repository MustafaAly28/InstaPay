#pragma once
#include<iostream>
#include<string>
using namespace std;

const string PersonalInfoFile = "Personal.txt";
const string AccountsInfoFile = "Accounts.txt";
const string AddressInfoFile = "Address.txt";
const int USERS_COUNT = 10;
int AddingUsersCounter = 0; // each Adding User , Do Increament For This Counter

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
	string HolderName;
};

struct StUser
{
	string UserName;
	int Id;
	string Phone;
	string Password;
	string Email;
	StAddress AdressUser;
	StAccount AccountUser;
};

StUser Users[USERS_COUNT];