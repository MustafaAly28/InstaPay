#pragma once
#include<iostream>
#include<string>
#include"DataLayer.h"
using namespace std;

namespace Login
{
	string ReadUserName()
	{
		string UserName = "";

		cout << "Enter Your UserName : \n";
		getline(cin >> ws, UserName);

		return UserName;
	}

	string ReadPassword()
	{
		string PassWord = "";
		cout << "Enter Your PassWord : \n";
		getline(cin >> ws, PassWord);

		return PassWord;
	}

	bool IsUserExactlyExist(const StUser Users[USERS_COUNT], const StUser& User)
	{
		bool IsUserExist = true;

		for (int PositionUser = 0; PositionUser < USERS_COUNT; PositionUser++)
		{
			if (Users[PositionUser].UserName == User.UserName && Users[PositionUser].Password == User.Password)
				return IsUserExist;
		}
		return !IsUserExist;
	}

	bool LogInUser(StUser Users[USERS_COUNT], StUser& User)
	{
		bool IsLogIn = true;

		if (IsUserExactlyExist(Users, User))
			return IsLogIn;

		return !IsLogIn;
	}

	void LogIn(StUser& User, StUser Users[USERS_COUNT])
	{
		system("cls");

		cout << "\t\t =====================================\n";
		cout << "\t\t =========== Log In Screen ===========\n";
		cout << "\t\t =====================================\n";

		do
		{
			User.UserName = ReadUserName();
			User.Password = ReadPassword();

			if (LogInUser(Users, User))
				cout << "Done Log In \n";

			cout << "\n===============================================\n";
			cout << "\nInValid Data, UserName Or Password Is Not Right \n";
			cout << "\n===============================================\n\n";

		} while (true);

	}

}

namespace Print
{
	void PrintData(const StUser& User)
	{
		cout << "\n_______________________________________________________________________________\n";
		cout << "Address Data Of Client : \n";
		cout << "-----------------------\n";
		cout << "Street Address : " << User.AdressUser.Street << endl;
		cout << "City Name      : " << User.AdressUser.City << endl;
		cout << "Home Number    : " << User.AdressUser.HomeNumber << endl;

		cout << "=======================\n";

		cout << "Account Data Of Client \n";
		cout << "-----------------------\n";
		cout << "Bank Name   : " << User.AccountUser.BankName << endl;
		cout << "Card Number : " << User.AccountUser.CardNumber << endl;
		cout << "CVV Code    : " << User.AccountUser.CVVCode << endl;
		cout << "Holder Name : " << User.AccountUser.HolderName << endl;
		cout << "Expiration Date : " << User.AccountUser.ExpirationDate << endl;

		cout << "=======================\n";

		cout << "Personal Data Of Client \n";
		cout << "-----------------------\n";
		cout << "Name  : " << User.UserName << endl;
		cout << "Id    : " << User.Id << endl;
		cout << "PassWord : " << User.Password << endl;
		cout << "Email : " << User.Email << endl;
		cout << "Phone : " << User.Phone << endl;

		cout << "=======================\n";
		cout << "\n_______________________________________________________________________________\n";
	}
}