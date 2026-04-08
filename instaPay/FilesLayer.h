#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"DataLayer.h"
#include"FilesSigns.h"
using namespace std;

namespace File
{
	StAddress ConvertAddressDataLineToStructure(string LineOfDataAddress)
	{
		string AddressInfo[3] = {};
		short Counter = 0;
		StAddress Address;
		int Position = 0;

		while ((Position = LineOfDataAddress.find(SepratorAddressData)) != string::npos)
		{
			string PartDataLine = LineOfDataAddress.substr(0, Position);

			if (PartDataLine != "") {
				AddressInfo[Counter] = PartDataLine;
				Counter++;
			}
			LineOfDataAddress.erase(0, Position + SepratorAddressData.length());
		}

		if (LineOfDataAddress != "")
			AddressInfo[Counter] = LineOfDataAddress;

		Address.Street = AddressInfo[0];
		Address.City = AddressInfo[1];
		Address.HomeNumber = AddressInfo[2];

		return Address;
	}

	StAccount ConvertAccountDataLineToStructure(string LineOfDataAccount)
	{
		string AccountInfo[6] = {};
		short Counter = 0;
		StAccount Account;
		int Position = 0;

		while ((Position = LineOfDataAccount.find(SepratorAccountData)) != string::npos)
		{
			string PartDataLine = LineOfDataAccount.substr(0, Position);

			if (PartDataLine != "") {
				AccountInfo[Counter] = PartDataLine;
				Counter++;
			}
			LineOfDataAccount.erase(0, Position + SepratorAccountData.length());
		}

		if (LineOfDataAccount != "")
			AccountInfo[Counter] = LineOfDataAccount;

		Account.CardNumber = AccountInfo[0];
		Account.HolderName = AccountInfo[1];
		Account.BankName = AccountInfo[2];
		Account.CVVCode = AccountInfo[3];
		Account.ExpirationDate = AccountInfo[4];
		Account.Balance = stod(AccountInfo[5]);

		return Account;
	}

	void ConvertPersonalDataLineToStructure(string LineOfDataPersonal, StUser& User)
	{
		string PersonalInfo[5] = {};
		short Counter = 0;
		int Position = 0;

		while ((Position = LineOfDataPersonal.find(SepratorPersonalData)) != string::npos)
		{
			string PartDataLine = LineOfDataPersonal.substr(0, Position);

			if (PartDataLine != "") {
				PersonalInfo[Counter] = PartDataLine;
				Counter++;
			}
			LineOfDataPersonal.erase(0, Position + SepratorPersonalData.length());
		}

		if (LineOfDataPersonal != "")
			PersonalInfo[Counter] = LineOfDataPersonal;

		User.UserName = PersonalInfo[0];
		User.Id = stoi(PersonalInfo[1]);
		User.Password = PersonalInfo[2];
		User.Phone = PersonalInfo[3];
		User.Email = PersonalInfo[4];

	}

	void FillAccountsFromFile(const string& FileNameAccount, StUser Users[])
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
					Users[Counter].AccountUser = ConvertAccountDataLineToStructure(AccountDataLine);
					Counter++;
				}
			}
		}
		FileAccount.close();

	}

	void FillAddressFromFile(const string& FileNameAddress, StUser Users[])
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
				Users[Counter].AdressUser = ConvertAddressDataLineToStructure(AddressDataLine);
				Counter++;
			}
		}
		FileAddress.close();
	}

	void FillPersonalFromFile(const string& FileNamePersonal, StUser Users[])
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

	void FillDataToUsersListFromFiles(StUser Users[USERS_COUNT], const string PerosnalFile, const string& AccountsFile, const string& AddressFile)
	{
		// -- Move Data Personal From File To Attributes Personal  -- 
		FillPersonalFromFile(PersonalInfoFile, Users);

		// -- Move Data Accounts From File To Attributes Accounts  -- 
		FillAccountsFromFile(AccountsInfoFile, Users);

		// -- Move Data Address From File To Attributes Address    -- 
		FillAddressFromFile(AddressInfoFile, Users);
	}
}
