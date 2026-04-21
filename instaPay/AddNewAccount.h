#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include"DataLayer.h"
#include"FilesLayer.h"

namespace AddNewAccount
{
    void PrintAddNewAccountHider()
    {
        cout << "\n==========================================\n";
        cout << "                AddNewAcount                  ";
        cout << "\n==========================================\n";
    }


    bool IsValidCardFormat(const string& cardNo)
    {
        if (cardNo.length() != 19)
            return false;

        for (int i = 0; i < 19; i++) {
            if (i == 4 || i == 9 || i == 14)
            {
                if (cardNo[i] != ' ')
                    return false;
            }
            else
            {
                if (!isdigit(cardNo[i]))
                    return false;
            }
        }
        return true;
    }

    //  التحقق من وجود الكارت مسبقاً 
    bool IsCardAlreadyExists(string cardNo)
    {
        for (int i = 0; i < AddingUsersCounter; i++)
        {
            for (int j = 0; j < Users[i].CountAccounts; j++)
            {
                if (Users[i].AccountsList[j].CardNumber == cardNo)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void CardNumber_Validation(StAccount& NewAccount)
    {
        while (true)
        {
            string CardNoInput;
            cout << "Enter 16-digit Card Number: ";
            cin >> CardNoInput;

            // تشييك الطول المبدئي 
            if (CardNoInput.length() != 16)
            {
                cout << "\nError: Card Number must be exactly 16 digits. Try again.\n\n";
                continue;
            }

            // إضافة المسافات  
            CardNoInput.insert(4, " ");
            CardNoInput.insert(9, " ");
            CardNoInput.insert(14, " ");


            if (!IsValidCardFormat(CardNoInput))         // التحقق من الفورمات لل الأرقام
            {
                cout << "\nError: Card Number must contain digits only. Try again.\n\n";
                continue;
            }


            if (IsCardAlreadyExists(CardNoInput))     // التحقق من عدم التكرارة
            {
                cout << "\nError: This Card Number is already registered! Try again.\n\n";
                continue;
            }


            NewAccount.CardNumber = CardNoInput;
            cout << " Success : Card Number accepted  : " << NewAccount.CardNumber << "\n\n";
            break;
        }
    }


   bool IsValidCVVFormat(const string& cvv) 
{
    if (cvv.length() != 3)
        return false;
    for (char c : cvv) 
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

//   مسبقاً( CVV ) دالة تتحقق من وجود الـ   
bool IsCVVAlreadyExists(string cvv) 
{
    for (int i = 0; i < AddingUsersCounter; i++)
    {
        for (int j = 0; j < Users[i].CountAccounts; j++) 
        {
            if (Users[i].AccountsList[j].CVVCode == cvv) 
            {
                return true;
            }
        }
    }
    return false;
}


void CVVCode_Validation(StAccount& NewAccount)
{
    while (true)
    {
        string input;
        cout << "Enter CVV Code (3 digits): ";
        cin >> input;

        // التحقق من الفورمات 3 أرقام
        if (!IsValidCVVFormat(input))
        {
            cout << "\nError: CVV must be exactly 3 digits. Try again.\n\n";
            continue;
        }

        // التحقق من التكرار
        if (IsCVVAlreadyExists(input)) 
        {
            cout << "\nError: CVV Code already exists! Try again.\n\n";
            continue;
        }

        
        NewAccount.CVVCode = input;
        cout << "Success : CVV Code accepted.\n\n";
        break;
    }

}


    void BankName_Validation(StAccount& NewAccount)
    {

        string ValidBanks[3] = { "CIB", "NBE", "BANQUEMISR" };     // (CIB||cib) is Commercial International Bank // (NBE||nbe) is National Bank of Egypt

        while (true)
        {
            cout << "Enter Bank Name  : ";
            cin >> ws;
            getline(cin, NewAccount.BankName);

            //  Convert input to UPPERCASE
            for (int i = 0; i < NewAccount.BankName.length(); i++)
            {
                NewAccount.BankName[i] = toupper(NewAccount.BankName[i]);
            }

            bool bankFound = false;
            for (int i = 0; i < 3; i++)
            {
                if (NewAccount.BankName == ValidBanks[i])
                {
                    bankFound = true;
                    break;
                }
            }

            if (!bankFound)
            {
                cout << "\nError: Invalid Bank Name! . Try again.\n\n";
                continue;
            }

            break;
        }


    }


    StAccount GenerateExpirationDate()
    {
        StAccount ExpiryDate;
        int MonthRandom = 1 + rand() % 12;               // Generate random month between 1 to 12 .
        int YearRandom = 26 + rand() % 5;               // Generate random year starting from 2026 .

        string Year = to_string(YearRandom);
        string Month = "";
        if (MonthRandom < 10)

            Month = "0" + to_string(MonthRandom);

        else

            Month = to_string(MonthRandom);

        ExpiryDate.ExpirationDate = Month + "/" + Year;   //    ( 04/26 )

        return  ExpiryDate;
    }


    double GenerateRandomBalance()           
    {

        double BalanceCard = 1000 + rand() % 5000;
        return   BalanceCard;
    }


    StAccount ReadNewAccountData()
    {
        StAccount NewAccount;


        PrintAddNewAccountHider();

        NewAccount.ExpirationDate = GenerateExpirationDate().ExpirationDate;

        NewAccount.Balance = GenerateRandomBalance();   

        cout << "Enter Holder Name : ";
        cin >> ws;                                                 // clear buffer before reading string 
        getline(cin, NewAccount.HolderName);

        CardNumber_Validation(NewAccount);
        CVVCode_Validation(NewAccount);
        BankName_Validation(NewAccount);

        cout << "Expiration Date  : " << NewAccount.ExpirationDate << endl;
        cout << "Balance          : " << NewAccount.Balance << endl;

        //cout << "Card Number      : " << NewAccount.CardNumber << endl;
        //cout << "CVV Code         : " << NewAccount.CVVCode << endl;
        //cout << "Expiration Date  : " << NewAccount.ExpirationDate<<endl;
        //cout << "Balance          :" << NewAccount.Balance << endl;

        return NewAccount;
    }

    void ShowLoading()
    {
        cout << "\nProcessing ";
        for (int i = 0; i < 3; i++) {
            Sleep(500);       // بينتظر نص ثانية (500 مللي ثانية)
            cout << ".";
        }
        cout << "\n";
        system("cls");        // بيمسح الشاشة بعد ما يخلص
    }



    void addNewAccount()
    {

        if (CurrentUserIndex == -1)             // Check if the user is not logged in ( -1 means no user is logged in)
        {
            cout << "\nError: Access Denied: Please login first\n";
            // call Fanction => login();
            return;
        }
        if (Users[CurrentUserIndex].CountAccounts >= 3)          // Check if the user is reached maximum limit of Accounts
        {
            cout << "\nError:You reached maximum limit of Accounts .\n";
            return;
        }

        StAccount NewAccount = ReadNewAccountData();    //  the reading function to prepare the account structure


        int CurrentAccPos = Users[CurrentUserIndex].CountAccounts;      // Store the account data in the specific user's slot
        Users[CurrentUserIndex].AccountsList[CurrentAccPos] = NewAccount;    // Store the account data in the specific user's slot
        Users[CurrentUserIndex].CountAccounts++;           // increase UserAccounts is 3 .
        TotalSystemAccount++;                             // increase  SystemAccounts .
       
        ShowLoading();

        cout << "\nAccount added successfully for [" << Users[CurrentUserIndex].UserName << "] ✅\n";
    }

}
