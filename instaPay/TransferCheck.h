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

        cout << "Your accounts:\n";

        for (int i = 0; i < Users[UserIndex].CountAccounts; i++)
        {
            cout << "[" << i + 1 << "] "
                << Users[UserIndex].AccountsList[i].BankName << endl;
        }

        char choiceSenderYN;

        while (true)
        {
            cout << "Choose your account: ";
            cin >> senderAcc;

            if (senderAcc >= 1 && senderAcc <= Users[UserIndex].CountAccounts)
            {
                break; // valid
            }

            cout << "Invalid sender account.\n";
            cout << "Do you want to try again? (Y/N): ";
            cin >> choiceSenderYN;

            if (choiceSenderYN == 'N' || choiceSenderYN == 'n')
            {
                cout << "Operation cancelled.\n";
                return;
            }
        }

        senderAcc--; // fix index

        // Enter the receiver's phone number to find accounts

        char choiceRecPhoneYN;

        while (true)
        {
            cout << "Enter the receiver's phone number: ";
            cin >> receiverPhone;

            if (receiverPhone == Users[UserIndex].Phone)
            {
                cout << "You can't transfer money to your phone number.\n";
            }
            else
            {
                receiverIndex = -1;

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
                }
                else if (Users[receiverIndex].CountAccounts == 0)
                {
                    cout << "Receiver has no accounts.\n";
                }
                else
                {
                    break; // valid
                }
            }

            cout << "Do you want to try again? (Y/N): ";
            cin >> choiceRecPhoneYN;

            if (choiceRecPhoneYN == 'N' || choiceRecPhoneYN == 'n')
            {
                cout << "Operation cancelled.\n";
                return;
            }
        }

        // Choose the account of the receiver you want to send

        cout << "The receiver's accounts: \n";

        for (int i = 0; i < Users[receiverIndex].CountAccounts; i++)
        {
            cout << "[" << i + 1 << "] "
                << Users[receiverIndex].AccountsList[i].BankName
                << endl;
        }

        char choiceRecAccYN;

        while (true)
        {
            cout << "Choose the account: ";
            cin >> receiverAcc;

            if (receiverAcc >= 1 && receiverAcc <= Users[receiverIndex].CountAccounts)
            {
                break; // valid
            }

            cout << "Invalid receiver account.\n";
            cout << "Do you want to try again? (Y/N): ";
            cin >> choiceRecAccYN;

            if (choiceRecAccYN == 'N' || choiceRecAccYN == 'n')
            {
                cout << "Operation cancelled.\n";
                return;
            }
        }

        receiverAcc--; // fix index

        char choiceAmountYN;

        while (true)
        {
            cout << "Enter amount you want to send: ";
            cin >> amount;

            if (amount > 0)
            {
                if (Users[UserIndex].AccountsList[senderAcc].Balance >= amount)
                {
                    break; // valid
                }
                else
                {
                    cout << "Insufficient balance.\n";
                }
            }
            else
            {
                cout << "Invalid amount.\n";
            }

            cout << "Do you want to try again? (Y/N): ";
            cin >> choiceAmountYN;

            if (choiceAmountYN == 'N' || choiceAmountYN == 'n')
            {
                cout << "Operation cancelled.\n";
                return;
            }
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

        int choice; char choiceBalanceYN;

        while (true)
        {
            cout << "Choose your account: ";
            cin >> choice;

            if (choice >= 1 && choice <= Users[UserIndex].CountAccounts)
            {
                break; // valid
            }

            cout << "Invalid choice!\n";
            cout << "Do you want to try again? (Y/N): ";
            cin >> choiceBalanceYN;

            if (choiceBalanceYN == 'N' || choiceBalanceYN == 'n')
            {
                cout << "Operation cancelled.\n";
                return;
            }
        }

        choice--; // fix index

        cout << "Your Balance is: "
            << Users[UserIndex].AccountsList[choice].Balance
            << endl;
    }

}