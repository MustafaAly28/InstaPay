#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream> 
#include "DataLayer.h"
#include "Login.h"
#include <cstdlib>
#include <ctime>
#include <cctype>
#include"UserProfile.h"
#include"AddNewAccount.h"
#include "TransferCheck.h"
//#include"CheckTransactions.h"
#define _CRT_SECURE_NO_WARNINGS
//using namespace CheckTransaction;
using namespace Login;
using namespace std;
using namespace AddNewAccount;
using namespace TransferBalanceAndCheck;
using namespace UserProfile;

namespace MainMenu
{
    void Deposit();
    void WithDraw();
    bool Exist = false;

    void AskUser(char Answer) {

        while (Answer != 'Y' && Answer != 'y' && Answer != 'N' && Answer != 'n')
        {
            cout << "invalid Answer \n";
            cout << "Answer Must Be Y/N ";
            cout << "Answer : ";
            cin >> Answer;
        }
        if (Answer == 'y' || Answer == 'Y')
        {

            ShowLoading();
            system("cls");
        }
        else

            Exist = true;
    }
    void mainWindow() {

        bool ValidChoice;
        char Answer;
        int Choice;
        while (true) {

            system("Color 0E"); // Color The Font

            cout << "\n\t\t\t\t========================================";
            cout << "\n\t\t\t\t            INSTAPAY EGYPT             ";
            cout << "\n\t\t\t\t========================================";
            cout << "\n\t\t\t\t  1. Check Balance      2. Add Account";
            cout << "\n\t\t\t\t  3. Transfer           4. User Info";
            cout << "\n\t\t\t\t  5. Transactions       6. Donation";
            cout << "\n\t\t\t\t  7. Deposit            8. Withdraw";
            cout << "\n\t\t\t\t  9. Logout             0.Exit    ";
            cout << "\n\t\t\t\t========================================\n";




            do
            {

                cout << "\t\t\t\tEnter Your Choice from (0-9) : ";
                cin >> Choice;


                if (Choice >= 0 && Choice <= 9)
                {

                    ValidChoice = true;
                }
                else
                {
                    cout << "Invalid Choice ! \n";
                    ValidChoice = false;
                }

            } while (ValidChoice == false);
            ShowLoading();
            system("cls");

            switch (Choice) {
            case 1:
                checkBalance();
                cout << "To Main Menu Y/y To Exist N/n ";
                cout << "Answer : ";
                cin >> Answer;
                AskUser(Answer);
                break;
            case 2:
                addNewAccount();
                cout << "For Main Menu Y/y To Exist N/n ";
                cout << "Answer : ";
                cin >> Answer;
                AskUser(Answer);

                break;
            case 3:

                transfer();
                cout << "For Main Menu Y/y To Exist N/n ";
                cout << "Answer : ";
                cin >> Answer;
                AskUser(Answer);

                break;

            case 4:
                ShowUserBasicProfile(UserIndex);
                break;

            case 5:

                //CheckTransactions();
                cout << "For Main Menu Y/y To Exist N/n ";
                cout << "Answer : ";
                cin >> Answer;
                AskUser(Answer);

                break;
            case 6:

                //Donate();

                break;
            case 7:
                Deposit();
                cout << "For Main Menu Y/y To Exist N/n ";
                cout << "Answer : ";
                cin >> Answer;
                AskUser(Answer);

                break;
            case 8:
                WithDraw();
                cout << "For Main Menu Y/y To Exist N/n ";
                cout << "Answer : ";
                cin >> Answer;
                AskUser(Answer);
                break;

            case 9:
                ShowLoading();
                system("cls");
                LoGin();
                break;

            case 0:
                cout << "Thank You";
                Exist = true;

            }
            if (Exist) {
                ShowLoading();
                system("cls");
                break;
            }
        }


    }
    void ShowDateTime() {
        time_t now = time(0);
        cout << "Date & Time: " << ctime(&now);
    }           //Show Date And Time

    double GetValidAmount() {              // تاخذ مبلغ موجب واكبر من الصفر
        double Amount;
        while (true)
        {

            cout << "Enter Your Amount : \n";
            cin >> Amount;

            if (Amount > 0)
                return Amount;
            cout << "Amount Must Be positive";



        }

    }
    bool CheckPIN(string PIN, int AccountIndex) {           // تشيك الرمز موجود في السيستم 


        if (Users[UserIndex].AccountsList[AccountIndex].PINCode == PIN)
        {


            return true;


        }

        return false;

    }


    bool CheckAccountExist(string CardNumber)               // تشيك الاكونت موجود في السيستم
    {


        for (int Index = 0; Index < 3; Index++)
        {
            if (Users[UserIndex].AccountsList[Index].CardNumber == CardNumber)
            {


                return true;

            }
        }
        return false;
    }


    bool CheckBalance(double Amount, int AccountIndex) {        // تشيك لو المبلغ الكلي كافي للسحب

        double TotalAmount = Amount + Amount * 0.01;


        if (TotalAmount <= Users[UserIndex].AccountsList[AccountIndex].Balance)//taxex+amount
        {


            return true;

        }
        return false;

    }


    void Deposit() {
        int CounterAttempts = 0;
        double Amount;
        string CardNumber;
        int AccountIndex;

        string PIN;



        while (true)
        {

            cout << "Enter Card Number (16 digits starting with 4 or 5): ";
            cin >> CardNumber; // ياخد  Card Number
            if (CheckAccountExist(CardNumber)) // تشيك لو موجود في السيستم 
                break;
            else
                cout << "Invalid Card Number Or Does Not Exist \n";

        }

        for (int Index = 0; Index < 3; Index++) // تعرف اني حساب هو اختاره 
        {
            if (Users[UserIndex].AccountsList[Index].CardNumber == CardNumber)
            {

                AccountIndex = Index;


            }
        }

        Amount = GetValidAmount(); // ياخد مبلغ موجب واكبر من صفر

        cout << "You only have 3 attempts \n";

        do {
            cout << "Enter a 4 digit PIN code for your account: ";
            cin >> PIN;
            if (CheckPIN(PIN, AccountIndex)) //لو الرمز موجود في الستسم    
                break;
            else
                cout << "invalid PIN !! \n";
            CounterAttempts++;
            if (CounterAttempts == 3) {
                CounterAttempts = 0;
                ShowLoading();
                system("cls");
                mainWindow();
            }



        } while (true);


        Users[UserIndex].AccountsList[AccountIndex].Balance += Amount;// Amount+taxes
        ShowLoading();
        cout << "\n====================================\n";
        cout << "       TRANSACTION SUCCESSFUL       \n";
        cout << "====================================\n";
        cout << "Amount : " << Amount << " EGP\n";
        cout << "New Balance: " << Users[UserIndex].AccountsList[AccountIndex].Balance << " EGP\n";
        ShowDateTime();
        cout << "====================================\n";

    }
    void WithDraw()
    {
        int  CounterAttempts = 0;
        double Amount;
        string CardNumber;
        int AccountIndex;
        string PIN;

        while (true)
        {

            cout << "Enter Card Number (16 digits starting with 4 or 5): ";
            cin >> CardNumber; // ياخد  Card Number
            if (CheckAccountExist(CardNumber)) // تشيك لو موجود في السيستم 
                break;
            else
                cout << "Invalid Card Number Or Does Not Exist \n";

        }

        for (int Index = 0; Index < 3; Index++) // تعرف اني حساب هو اختاره 
        {
            if (Users[UserIndex].AccountsList[Index].CardNumber == CardNumber)
            {

                AccountIndex = Index;


            }
        }

        while (true)
        {
            Amount = GetValidAmount(); // ياخد مبلغ موجب واكبر من صفر
            if (CheckBalance(Amount, AccountIndex)) // (لو المبلغ الكلي  كافي( مبلغ + ضرائب
                break;
            cout << "Insufficient balance !! \n";
        }
        double TotalAmount = Amount + Amount * 0.01;
        cout << "You only have 3 attempts \n";


        do {
            cout << "Enter a 4 digit PIN code for your account: ";
            cin >> PIN;
            if (CheckPIN(PIN, AccountIndex)) //لو الرمز موجود في الستسم    
                break;
            cout << "invalid PIN !! \n";
            CounterAttempts++;

            if (CounterAttempts == 3) {
                CounterAttempts = 0;
                ShowLoading();
                system("cls");
                mainWindow();
            }

        } while (true);


        Users[UserIndex].AccountsList[AccountIndex].Balance -= TotalAmount;

        cout << "\n====================================\n";
        cout << "       TRANSACTION SUCCESSFUL       \n";
        cout << "====================================\n";
        cout << "Amount : " << Amount << " EGP\n";
        cout << "Taxes : " << Amount * 0.01 << " EGP\n";
        cout << "Amount was Drawen : " << TotalAmount << " EGP\n";
        cout << "New Balance: " << Users[UserIndex].AccountsList[AccountIndex].Balance << " EGP\n";
        ShowDateTime();
        cout << "====================================\n";


    }

}