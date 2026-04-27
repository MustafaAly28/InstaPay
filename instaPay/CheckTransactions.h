#pragma once
#include<iostream>
#include<string>
#include"DataLayer.h"
#include"FilesLayer.h"
#include"Login.h"
using namespace std;
using namespace Login;
namespace CheckTransaction
{
    using namespace std;

    // bool isLoggedIn()
    // {
    //     if (UserIndex == -1)
    //     {
    //         cout << "\n Error: Please login first!\n";
    //         return false;
    //     }
    //     return true;
    // }

    void PrintTransactionHeader(string title)
    {
        cout << "\n==========================================\n";
        cout << "           " << title << "           ";
        cout << "\n==========================================\n";
    }

    string maskPhone(string phone)
    {

        int visibleStart = 3;
        int visibleEnd = 2;
        string masked = "";

        masked += phone.substr(0, visibleStart);
        for (int i = visibleStart; i < (int)phone.length() - visibleEnd; i++)
            masked += "*";
        masked += phone.substr(phone.length() - visibleEnd);

        return masked;
    }

    void PrintSingleTransaction(StTransactions Transaction, int Number)
    {
        cout << "Transaction # " << Number + 1<< " #" << endl;
        cout << "  - From   : " << maskPhone(Transaction.PhoneNumber_From) << endl;
        cout << "  - To     : " << maskPhone(Transaction.PhoneNumber_To) << endl;
        cout << "  - Amount : " << Transaction.Amount << " EGP" << endl;
        cout << "  - Date   : " << Transaction.Date << endl;
        cout << "------------------------------------------\n";
    }

    void CheckSentTransactions()
    {

        StUser CurrentUser = Users[UserIndex];
        PrintTransactionHeader("SENT TRANSACTIONS");

        if (CurrentUser.TransactionsCountFrom == 0)       // Users[CurrentUserIndex].TransactionsCountFrom = currentUser.TransactionsCountFrom
        {
            cout << "   No sent transactions found.\n";
        }
        else
        {
            for (int i = 0; i < CurrentUser.TransactionsCountFrom; i++)
                PrintSingleTransaction(CurrentUser.TransactionsFrom[i], i + 1);
        }
        cout << "==========================================\n";
    }

    void CheckReceivedTransactions()
    {

        StUser CurrentUser = Users[UserIndex];
        PrintTransactionHeader("RECEIVED TRANSACTIONS");

        if (CurrentUser.TransactionsCountTo == 0)        //Users[CurrentUserIndex].TransactionsCountTo = currentUser.TransactionsCountTo
        {
            cout << "   No received transactions found.\n";
        }
        else
        {
            for (int i = 0; i < CurrentUser.TransactionsCountTo; i++)
                PrintSingleTransaction(CurrentUser.TransactionsTo[i], i + 1);
        }
        cout << "==========================================\n";
    }
    void ShowDepositTransaction() {
        // هتعرض فيها عمليات الايداع

    }


    void ShowWithDrawTransaction() {
        // هتعرض فيها عمليات الايداع

    }

    void CheckTransactions()
    {
        // if (!isLoggedIn())
        //     return;

        PrintTransactionHeader(" TRANSACTIONS ");

        CheckSentTransactions();

        CheckReceivedTransactions();

        StUser CurrentUser = Users[UserIndex];

        // bool HasAny = (CurrentUser.TransactionsCountFrom > 0 || CurrentUser.TransactionsCountTo > 0);

        // if (!HasAny)
        // {
        //     cout << "   No Transactions found.\n";
        // }

        // cout << "==========================================\n";
    }

}

