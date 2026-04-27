#pragma once

#include <iostream>
#include <string>
#include "DataLayer.h"
#include "FilesLayer.h"
#include "Login.h"

using namespace DataLayer;
using namespace Login;
using namespace std;

namespace TransferBalanceAndCheck
{
    void transfer()
    {
        int senderAcc, receiverAcc;
        string receiverPhone;
        double amount;
        int receiverIndex = -1;

        // Choosing your account to send money from 

        cout << "Choose the sender's account:\n";

        for (int i = 0; i < Users[UserIndex].CountAccounts; i++)
        {
            cout << "[" << i + 1 << "] "
                << Users[UserIndex].AccountsList[i].BankName << endl;
        }
        cin >> senderAcc;

        if (senderAcc < 1 || senderAcc > Users[UserIndex].CountAccounts)
        {
            cout << "Invalid sender account.\n";
            return;
        }

        senderAcc--; // fix index

        // Enter the receiver's phone number to find accounts

        cout << "Enter the receiver's phone number: ";
        cin >> receiverPhone;

        if (receiverPhone == Users[UserIndex].Phone)
        {
            cout << "You can't transfer money to your phone number.\n";
            return;
        }

        for (int i = 0; i < AddingUsersCounter; i++)
        {
            if (Users[i].Phone == receiverPhone)
            {
                receiverIndex = i;
                break;
            }
        }

        if (receiverIndex == -1)
        {
            cout << "Receiver not found.\n";
            return;
        }

        if (Users[receiverIndex].CountAccounts == 0)
        {
            cout << "Receiver has no accounts.\n";
            return;
        }

        // Choose the account of the receiver you want to send

        cout << "Choose the receiver's account: \n";

        for (int i = 0; i < Users[receiverIndex].CountAccounts; i++)
        {
            cout << "[" << i + 1 << "] "
                << Users[receiverIndex].AccountsList[i].BankName
                << endl;
        }

        cin >> receiverAcc;

        if (receiverAcc < 1 || receiverAcc > Users[receiverIndex].CountAccounts)
        {
            cout << "Invalid receiver account.\n";
            return;
        }

        receiverAcc--; // fix index

        cout << "Enter amount you want to send: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount.\n";
            return;
        }

        if (Users[UserIndex].AccountsList[senderAcc].Balance < amount)
        {
            cout << "Insufficient balance.\n";
            return;
        }

        // transfer process

        Users[UserIndex].AccountsList[senderAcc].Balance -= amount;
        Users[receiverIndex].AccountsList[receiverAcc].Balance += amount;

        cout << "Transfer successful.\n";

        // (FROM) save transaction

        int transactionFrom = Users[UserIndex].TransactionsCountFrom;

        Users[UserIndex].TransactionsFrom[transactionFrom].PhoneNumber_From =
            Users[UserIndex].Phone;

        Users[UserIndex].TransactionsFrom[transactionFrom].PhoneNumber_To =
            Users[receiverIndex].Phone;

        Users[UserIndex].TransactionsFrom[transactionFrom].Amount = amount;

        Users[UserIndex].TransactionsCountFrom++;

        // (TO) save transaction

        int transactionTo = Users[receiverIndex].TransactionsCountTo;

        Users[receiverIndex].TransactionsTo[transactionTo].PhoneNumber_From =
            Users[UserIndex].Phone;

        Users[receiverIndex].TransactionsTo[transactionTo].PhoneNumber_To =
            Users[receiverIndex].Phone;

        Users[receiverIndex].TransactionsTo[transactionTo].Amount = amount;

        Users[receiverIndex].TransactionsCountTo++;

        AddingTransactionsCounter++;

        // Save the transaction to file

        StTransactions newTransaction;

        newTransaction.PhoneNumber_From = Users[UserIndex].Phone;
        newTransaction.PhoneNumber_To = Users[receiverIndex].Phone;
        newTransaction.Amount = amount;

        File::Access_AddTransactionHistoryToFile(newTransaction);

    }

    void checkBalance()
    {
        cout << "Your accounts:\n";

        for (int i = 0; i < Users[UserIndex].CountAccounts; i++)
        {
            cout << "[" << i + 1 << "] "
                << Users[UserIndex].AccountsList[i].BankName << endl;
        }

        int attempts = 0, choice;
        bool valid = false;

        while (attempts < 3)
        {
            cout << "Choose your account: ";
            cin >> choice;

            if (choice >= 1 && choice <= Users[UserIndex].CountAccounts)
            {
                valid = true;
                break;
            }

            attempts++;

            if (attempts < 3)
                cout << "Invalid choice! You have " << 3 - attempts << " attempt(s) left.\n";
        }

        if (!valid)
        {
            cout << "Too many invalid attempts!\n";
            return;
        }

        choice--; // fix index

        cout << "Your Balance is: "
            << Users[UserIndex].AccountsList[choice].Balance
            << endl;
    }

}