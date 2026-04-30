#pragma once
#include<iostream>
#include<string>
#include"DataLayer.h"
#include"FilesLayer.h"
#include"Login.h"
using namespace std;
using namespace Login;

namespace MainMenu
{
    void ShowDateTime();
    int AccountIndex;
}

using namespace  MainMenu;

namespace CheckTransaction
{
    /*bool isLoggedIn()
    {
        if (CurrentUserIndex == -1)
        {
            cout << "\n Error: Please login first!\n";
            return false;
        }
        return true;
    }*/

    void PrintTransactionHeader(string title)
    {
        cout << "\n==========================================\n";
        cout << "           " << title << "           ";
        cout << "\n==========================================\n";
    }

    /* string maskPhone(string phone)
     {

         int visibleStart = 3;
         int visibleEnd = 2;
         string masked = "";

         masked += phone.substr(0, visibleStart);
         for (int i = visibleStart; i < (int)phone.length() - visibleEnd; i++)
             masked += "*";
         masked += phone.substr(phone.length() - visibleEnd);

         return masked;
     }*/

    void PrintSingleTransaction(StTransactions Transaction, int Number)
    {
        cout << "Transaction # " << Number << " #" << endl;
        cout << "  - From   : " << Transaction.PhoneNumber_From << endl;
        cout << "  - To     : " << Transaction.PhoneNumber_To << endl;
        cout << "  - Amount : " << Transaction.Amount << " EGP" << endl;
        cout << "  - Date   : " << Transaction.Date << endl;
        cout << "------------------------------------------\n";
    }
    //  عرض جميع عمليات الإيداع التي تمت
    //void CheckDeposits()
    //{
    //    StAccount CurrentAccount = Users[UserIndex].AccountsList[AccountIndex];
    //    PrintTransactionHeader("DEPOSITS HISTORY");

    //    // التحقق من وجود عمليات إيداع
    //    if (CurrentAccount.DepositsCount == 0)
    //    {
    //        cout << "   No deposits found.\n";
    //    }
    //    else
    //    {
    //        for (int i = 0; i < CurrentAccount.DepositsCount; i++)
    //        {

    //            PrintSingleTransaction(CurrentAccount.Deposits[i], i + 1);
    //        }
    //    }
    //    cout << "==========================================\n";
    //}

    ////  عرض جميع عمليات السحب التي تمت
    //void CheckWithdrawals()
    //{
    //    StAccount CurrentAccount = Users[UserIndex].AccountsList[AccountIndex];
    //    PrintTransactionHeader("WITHDRAWALS HISTORY");

    //    // التحقق من وجود عمليات سحب 
    //    if (CurrentAccount.WithdrawalsCount == 0)
    //    {
    //        cout << "  No withdrawals found.\n";
    //    }

    //    else
    //    {
    //        for (int i = 0; i < CurrentAccount.WithdrawalsCount; i++)
    //        {

    //            PrintSingleTransaction(CurrentAccount.Withdrawals[i], i + 1);
    //        }
    //    }
    //    cout << "==========================================\n";
    //}

    //void CheckSentTransactions()
    //{

    //    StAccount CurrentAccount = Users[UserIndex].AccountsList[AccountIndex];
    //    PrintTransactionHeader("SENT TRANSACTIONS");

    //    if (CurrentAccount.TransactionsCountFrom == 0)       // Users[CurrentUserIndex].TransactionsCountFrom = currentUser.TransactionsCountFrom
    //    {
    //        cout << "   No sent transactions found.\n";
    //    }
    //    else
    //    {
    //        for (int i = 0; i < CurrentAccount.TransactionsCountFrom; i++)
    //            PrintSingleTransaction(CurrentAccount.TransactionsFrom[i], i + 1);
    //    }
    //    cout << "==========================================\n";
    //}

    //void CheckReceivedTransactions()
    //{

    //    StAccount CurrentAccount = Users[UserIndex].AccountsList[AccountIndex];
    //    PrintTransactionHeader("RECEIVED TRANSACTIONS");

    //    if (CurrentAccount.TransactionsCountTo == 0)        //Users[CurrentUserIndex].TransactionsCountTo = currentUser.TransactionsCountTo
    //    {
    //        cout << "   No received transactions found.\n";
    //    }
    //    else
    //    {
    //        for (int i = 0; i < CurrentAccount.TransactionsCountTo; i++)
    //            PrintSingleTransaction(CurrentAccount.TransactionsTo[i], i + 1);
    //    }
    //    cout << "==========================================\n";
    //}

    void CheckTransactions()
    {

        PrintTransactionHeader(" TRANSACTIONS ");

        //CheckSentTransactions();

        //CheckReceivedTransactions();

        //CheckDeposits();

        //CheckWithdrawals();

    }
}