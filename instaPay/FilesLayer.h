#pragma once
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include<iostream>
#include<string>
#include<fstream>
#include"DataLayer.h"
#include"FilesSigns.h"
using namespace DataLayer;
using namespace std;

/*				----  Instructions For Dealing With Files Operations (For Our Team)  ----
			 1. Use (LoadUsersListFromFiles()) Function To Fill Users Array From Files
			 2. After Doing Transaction Operation, Execute (AddTransactionToUser()) Function To Add This Operation
*/
namespace Date
{
	string CleanDate(const string& Text)
	{
		string Line = "";
		for (size_t i = 0; i < Text.length(); i++)
			if (Text[i] != '\n')
				Line += Text[i];

		return Line;
	}

	string GetDateNow()
	{
		time_t TimeNow = time(0);
		char* Date = ctime(&TimeNow);

		return CleanDate(Date);
	}
}

namespace File
{
	void SplitTextToData(string LineData, string DataParts[], const string SperatorInLine)
	{
		int Position = 0;
		int Counter = 0;


		while ((Position = LineData.find(SperatorInLine)) != string::npos)
		{
			string PartData = LineData.substr(0, Position);

			if (PartData != "")
			{
				DataParts[Counter] = PartData;
				Counter++;
			}

			LineData.erase(0, Position + SperatorInLine.length());
		}

		if (!LineData.empty())
			DataParts[Counter] = LineData;
	}

	/* ------------------- Conversion Lines To Structures Like Data Layer Structure -------------------*/

	StAddress GetAddressFromLine(string LineOfDataAddress)
	{
		string AddressInfo[3] = {};
		StAddress Address;

		SplitTextToData(LineOfDataAddress, AddressInfo, SepratorAddressData);

		Address.Street = AddressInfo[0];
		Address.City = AddressInfo[1];
		Address.HomeNumber = AddressInfo[2];

		return Address;
	}

	StAccount GetAccountFromLine(string LineOfDataAccount)
	{
		string AccountInfo[7] = {};
		StAccount Account;

		SplitTextToData(LineOfDataAccount, AccountInfo, SepratorAccountData);

		Account.CardNumber = AccountInfo[0];
		Account.PINCode = AccountInfo[1];
		Account.HolderName = AccountInfo[2];
		Account.BankName = AccountInfo[3];
		Account.CVVCode = AccountInfo[4];
		Account.ExpirationDate = AccountInfo[5];
		Account.Balance = stod(AccountInfo[6]);

		return Account;
	}

	StTransactions GetDataTransactionFromLine(string LineDataTransaction)
	{
		StTransactions TransactionsHistory;
		string TransactionsParts[4];

		SplitTextToData(LineDataTransaction, TransactionsParts, SepratorTransactionData);

		TransactionsHistory.PhoneNumber_From = TransactionsParts[0];
		TransactionsHistory.PhoneNumber_To = TransactionsParts[1];
		TransactionsHistory.Date = TransactionsParts[2];
		TransactionsHistory.Amount = stoi(TransactionsParts[3]);

		return TransactionsHistory;
	}

	void ConvertPersonalDataLineToStructure(string LineOfDataPersonal, StUser& User)
	{
		string PersonalInfo[5] = {};
		SplitTextToData(LineOfDataPersonal, PersonalInfo, SepratorPersonalData);

		User.UserName = PersonalInfo[0];
		User.Id = stoi(PersonalInfo[1]);
		User.Password = PersonalInfo[2];
		User.Phone = PersonalInfo[3];
		User.Email = PersonalInfo[4];

	}

	/* ------------------- Conversion Structures To One Line Like Line Of Its File -------------------*/

	string GetAddressLine(const StUser& User)
	{
		string AddressLine = "";
		return (User.Address.Street + "/#/" + User.Address.City + "/#/" + User.Address.HomeNumber);
	}

	string GetAccountLine(const StUser& User)
	{
		string Line = "";

		Line += User.Account.CardNumber + "$";
		Line += User.Account.PINCode + "$";
		Line += User.Account.HolderName + "$";
		Line += User.Account.BankName + "$";
		Line += User.Account.CVVCode + "$";
		Line += User.Account.ExpirationDate + "$";
		Line += to_string(User.Account.Balance);

		return Line;
	}

	string GetPersonalLine(const StUser& User)
	{
		return User.UserName + "#" + to_string(User.Id) + "#" + User.Password + "#" + User.Phone + "#" + User.Email;
	}

	string GetLineTransactionDataFromStructure(const StTransactions& TransactionOperation)
	{
		return (TransactionOperation.PhoneNumber_From + SepratorTransactionData + TransactionOperation.PhoneNumber_To
			+ SepratorTransactionData + Date::GetDateNow() +
			SepratorTransactionData + to_string(TransactionOperation.Amount));
	}

	/* ------------------- Load Data Types From Files -------------------  */

	void LoadAccountsFromFile(const string& FileNameAccount, StUser Users[])
	{
		fstream FileAccount;

		FileAccount.open(FileNameAccount, ios::in);
		int Counter = 0;

		//  --  Account Layer Data File -- 
		if (FileAccount.is_open())
		{
			string AccountDataLine = "";
			while (getline(FileAccount, AccountDataLine))
			{
				if (Counter < AddingUsersCounter)
				{
					Users[Counter].Account = GetAccountFromLine(AccountDataLine);
					Users[Counter].CountAccounts++;
					Counter++;
				}
			}
		}
		FileAccount.close();

	}

	void LoadAddressFromFile(const string& FileNameAddress, StUser Users[])
	{
		fstream FileAddress;
		FileAddress.open(FileNameAddress, ios::in);
		int Counter = 0;

		//  --  Address Layer Data File -- 
		if (FileAddress.is_open())
		{
			string AddressDataLine = "";
			while (getline(FileAddress, AddressDataLine))
			{
				Users[Counter].Address = GetAddressFromLine(AddressDataLine);
				Counter++;
			}
		}
		FileAddress.close();
	}

	void LoadPersonalFromFile(const string& FileNamePersonal, StUser Users[])
	{
		fstream FilePersonal;
		FilePersonal.open(FileNamePersonal, ios::in);
		int Counter = 0;

		//  --  Personal Layer Data File -- 
		if (FilePersonal.is_open())
		{
			string PersonalDataLine = "";
			while (getline(FilePersonal, PersonalDataLine))
			{
				if (Counter <= USERS_COUNT && AddingUsersCounter <= USERS_COUNT)
				{
					ConvertPersonalDataLineToStructure(PersonalDataLine, Users[Counter]);
					Counter++;
				}
			}
			AddingUsersCounter = Counter;
		}
		FilePersonal.close();
	}

	void LoadTransactionsFromFile(StTransactions TransactionsList[], const string& TransactionsFile)
	{
		fstream File;
		File.open(TransactionsFile, ios::in);

		if (File.is_open())
		{
			string LineData = "";
			while (getline(File, LineData))
			{
				TransactionsList[AddingTransactionsCounter] = GetDataTransactionFromLine(LineData);
				AddingTransactionsCounter++;
			}
		}
	}

	/* ------------------- Save Data Of Structures In File ------------------- */

	void SaveToFileAddress(const StUser Users[], int CountUsers, const string& FileAddress)
	{
		fstream File;
		File.open(FileAddress, ios::out);

		if (File.is_open())
		{
			for (int Counter = 0; Counter < CountUsers; Counter++)
			{
				File << GetAddressLine(Users[Counter]) << endl;
			}
		}
		File.close();
	}

	void SaveToFileAccount(const StUser Users[], int CountUsers, const string& FileAccount)
	{
		fstream File;
		File.open(FileAccount, ios::out);

		if (File.is_open())
		{
			for (int Counter = 0; Counter < CountUsers; Counter++)
			{
				File << GetAccountLine(Users[Counter]) << endl;
			}
		}
		File.close();
	}

	void SaveToPersonalFile(StUser Users[], int CountUsers, const string& FilePersonal)
	{
		fstream File;
		File.open(FilePersonal, ios::out);

		if (File.is_open())
		{
			for (int Counter = 0; Counter < CountUsers; Counter++)
			{
				File << GetPersonalLine(Users[Counter]) << endl;
			}
		}
		File.close();
	}

	void AddLineToTransactionsFile(const string& LineDataTransactions, const string& TransactionsFile)
	{
		fstream File;
		File.open(TransactionsFile, ios::app);

		if (File.is_open())
		{
			File << LineDataTransactions << endl;
		}

		File.close();
	}

	/* ------------------- Filteration For Users Transactions -------------------  */

	void FilterTransactions_From_(const StTransactions ListTransactions[], StUser& User)
	{
		for (int Position = 0; Position < AddingTransactionsCounter; Position++)
		{
			if (ListTransactions[Position].PhoneNumber_From == User.Phone)
			{
				User.TransactionsFrom[User.TransactionsCountFrom] = ListTransactions[Position];
				User.TransactionsCountFrom++;
			}
		}
	}

	void FilterTransactions_To_(const StTransactions ListTransactions[], StUser& User)
	{
		for (int Position = 0; Position < AddingTransactionsCounter; Position++)
		{
			if (ListTransactions[Position].PhoneNumber_To == User.Phone)
			{
				User.TransactionsTo[User.TransactionsCountTo] = ListTransactions[Position];
				User.TransactionsCountTo++;
			}
		}
	}

	void FillTransactionUser(const StTransactions ListTransactions[], StUser& User)
	{
		FilterTransactions_From_(ListTransactions, User); // To Fill User (From) Transactions 
		FilterTransactions_To_(ListTransactions, User); // To Fill User (To) Transactions 
	}

	void LoadTransactionsForUsers(StUser Users[], const string& FileTransactions)
	{
		StTransactions ListTransactions[100];
		LoadTransactionsFromFile(ListTransactions, TransactionsInfoFile); // Fill Transactions In Array

		for (int PositionUser = 0; PositionUser < AddingUsersCounter; PositionUser++)
		{
			FillTransactionUser(ListTransactions, Users[PositionUser]);
		}
	}


	/* ----------- You Can Deal With Following Three Functions Only , Don't Use Any Function Else ----------- */


	// If The System In Starting Point Of Processing ,Execute This
	void Access_LoadUsersListFromFiles(StUser Users[USERS_COUNT], const string PerosnalFile, const string& AccountsFile, const string& AddressFile, const string& TransactionFile)
	{
		// -- Move Data Personal From File To Attributes Personal          -- 
		LoadPersonalFromFile(PersonalInfoFile, Users);

		// -- Move Data Accounts From File To Attributes Accounts          -- 
		LoadAccountsFromFile(AccountsInfoFile, Users);

		// -- Move Data Address From File To Attributes Address            -- 
		LoadAddressFromFile(AddressInfoFile, Users);

		// -- Move Data Transactions From File To Attributes  Transaction  -- 
		LoadTransactionsForUsers(Users, TransactionsInfoFile);
	}

	// If You Did Transaction Operation , In End Of Process (Function) Execute This
	void Access_AddTransactionHistoryToFile(const StTransactions& Transaction)
	{
		string LineDataTransaction = GetLineTransactionDataFromStructure(Transaction);
		AddLineToTransactionsFile(LineDataTransaction, TransactionsInfoFile);
	}

	// if The System In Ending Point Of Processing , Execute This
	void Access_SaveUsersToFiles(StUser Users[], const string& AccountsFile, const string& AddressFile, const string& PersonalFile)
	{
		SaveToPersonalFile(Users, AddingUsersCounter, PersonalFile);

		SaveToFileAccount(Users, AddingUsersCounter, AccountsInfoFile);

		SaveToFileAddress(Users, AddingUsersCounter, AddressInfoFile);
	}

}
