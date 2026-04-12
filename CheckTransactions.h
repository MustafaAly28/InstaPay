#pragma once
#include<iostream>
#include<string>
#include"DataLayer.h"
#include"FilesLayer.h"
namespace CheckTransaction
{
    void PrintSingleTransaction(StTransactions Transaction , int Number)
    {
        cout << "Transaction # " << Number <<" <<#"<< endl;
        cout << "  - From   : " << Transaction.fromPhone << endl;
        cout << "  - To     : " << Transaction.toPhone << endl;
        cout << "  - Amount : " << Transaction.amount << " EGP" << endl;
        cout << "  - Date   : " << Transaction.date << endl;
        cout << "------------------------------------------\n";
    }
    void PrintTransactionHider()
    {
        cout << "\n==========================================\n";
        cout << "                TRANSACTIONS                  ";
        cout << "\n==========================================\n";
    }
    void checkTransactions() 
    {
       
        if (CurrentUserIndex == -1)             //  Check if the user is not logged in (-1 means no user is logged in)
        {
            cout << "\n Error: Access Denied: Please login first!\n";
                                            // Fanction login()
            return;
        }
 
        string myPhone = Users[CurrentUserIndex].Phone;    // get the phone number of the current user from the Users array
        bool found = false;

        PrintTransactionHider();
        
        for (int i = 0; i < TransactionCount; i++)    // loop through the entire Transactions array up to the current count
        {
           
            if (Transactions[i].fromPhone == myPhone || Transactions[i].toPhone == myPhone)      // Check if the user is either the sender (fromPhone) or the receiver (toPhone)
            {
                found = true;

                PrintSingleTransaction(Transactions[i], i + 1);
               
            }
        }
        
        
        if (!found)                                // if the loop finished and no matching transactions were found
        {
            cout << "   No transactions found for your account. \n";
            cout << "==========================================\n";
        }
    }


}
