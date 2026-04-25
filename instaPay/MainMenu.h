#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream> 
#include <windows.h>
#include "DataLayer.h"
#include "Login.h"
#include <cstdlib>
#include <ctime>
#include <cctype>
//#include"Funcs.h"
//using namespace Funcs;
using namespace Login;
using namespace std;
using namespace DataLayer;
//using namespace Login;

namespace MainMenu
{

    //int UserIndex = -1;
    int CounterAttempts = 0;
   
    void WithDraw();
    void Deposit();

        void ShowLoading() {
            cout << "\nLoading";
            for (int i = 0; i < 3; i++) {
                cout << ".";
                Sleep(500); //Delay Time Between Itration
            }

            cout << "\n";
        }           // Loading
        void ShowDateTime() {
            time_t now = time(0);
            char dt[26];
            ctime_s(dt, sizeof(dt), &now);

            cout << "Date & Time: " << dt;
        }           //Show Date And Time
        void SystemSecurity() {



            for (int i = 10; i >= 0; i--) {
                system("cls");
                cout << "\n\t\tProtection system";
                cout << "\n\t\t " << i << "s" << endl;
                Sleep(1000);

            }
            cout << "\n";
        }

        ////int GetUserChoice() {
        //    int Choice;
        //    cout << "\n\t\tEnter Your Choice from (0-9)\n";
        //    cout << "\t\t";
        //    cin >> Choice;
        //    return Choice;
        //}
        //bool ValidChoice(int Choice) {
        //    bool ChoiceInSide = true;

        //    if (Choice >= 0 && Choice <= 9)
        //    {
        //        return ChoiceInSide;
        //    }//Validation For Choices
        //    else
        //    {

        //        return !ChoiceInSide;
        //    }



        //}
        //int GetValidChoice() {
        //    int Choice;

        //    while (true) {
        //        Choice = GetUserChoice();
        //        if (ValidChoice(Choice))
        //            return Choice;

        //        cout << "\n\t\tInvalid Choice";
        //    }

        //}

        

        
        void mainWindow() {



            system("Color 0E"); // Color The Font


            cout << "\n\t\t========================================";
            cout << "\n\t\t            INSTAPAY EGYPT             ";
            cout << "\n\t\t========================================";
            cout << "\n\t\t  1. Check Balance      2. Add Account";
            cout << "\n\t\t  3. Transfer           4. User Info";
            cout << "\n\t\t  5. Transactions       6. Donation";
            cout << "\n\t\t  7. Deposit            8. Withdraw";
            cout << "\n\t\t  9. Logout             0.Exist    ";
            cout << "\n\t\t========================================";

            int Choice;
            cout << "\nEnter Your Choice from (0-9) : ";
            cin >> Choice;

            switch (Choice) {
            case 1:

               // CheckBalance();

                break;
            case 2:
                //AddNewAccount();

                break;
            case 3:

                //Transfer();

                break;
            case 4:

                //UserInfo();


                break;
            case 5:

                //CheckTransactions();

                break;
            case 6:

                //Donate();

                break;
            case 7:
                CounterAttempts = 0;
                Deposit();

                break;
            case 8:
                CounterAttempts = 0;
                WithDraw();

                break;

            case 9:
                ShowLoading();
                system("cls");
                LoGin();

                break;

            default:
                cout << "Invalid Choice";

            }



        }





        string GetCardNumber() {
            string CardNumber;
            cout << "\nEnter CardNumber As XXXX XXXX XXXX XXXX : ";
            cin.ignore();
            getline(cin, CardNumber);
            return CardNumber;
        }

        bool ValidCardNumber(string CardNumber) {
            if (CardNumber[0] != '5' && CardNumber[0] != '4')
            {
                cout << "Card number must start with 4 or 5!\n"; return false;
            }
            if (CardNumber.length() != 16)
            {
                cout << "Card number must be xxxx xxxx xxxx xxxx!\n"; return false;
            }
            for (int i = 0; i < CardNumber.length(); i++)
            {
                if (!isdigit(CardNumber[i]))
                {
                    cout << "Card number must contain only digits!\n"; return false;
                }
            }


            return true;
        }
        string GetValidCardNumber(string CardNumber) {


            while (true)
            {

                CardNumber = GetCardNumber();
                if (ValidCardNumber(CardNumber))
                {
                    cout << "Onther Check";
                    ShowLoading();
                    return CardNumber;

                }
                cout << "\nInvalid Card Number";
                CounterAttempts++;


                if (CounterAttempts == 3) {
                    SystemSecurity();
                    system("cls");
                }


            }




        }
        int AccountSearch(string CardNumber)
        {

            int i = -1;
            while (i == -1) {

                for (i = 0; i < Users[UserIndex].CountAccounts; i++) // Know  Which Any Account Belong To His Card Number
                {
                    if (Users[UserIndex].AccountsList[i].CardNumber == CardNumber)
                    {

                        return i;


                    }
                }
                cout << "invalid Card Number\n";
                CounterAttempts++;
                CardNumber = GetValidCardNumber(CardNumber);
            }


        }

        double GetAmount() {
            double Amount;
            cout << "\nAmount : ";
            cin >> Amount;
            return Amount;
        }
        bool ValidUserAmount(double Amount) {
            if (Amount > 0) {

                return true;
            }
            return false;
        }
        double GetValidAmount(double Amount, int CounterAttempts = 0) {


            while (true)
            {
                Amount = GetAmount();
                if (ValidUserAmount(Amount))
                    return Amount;

                cout << "\nInvalid Amount";

                CounterAttempts++;
                if (CounterAttempts == 3)
                {
                    SystemSecurity();
                    system("cls");
                }
            }


        }
        double EnsureBalance(double Amount, int AccountIndex, int CounterAttempts = 0) {
            double DiscountAmount = Amount + Amount * 0.01;

            bool ValidBalance;
            CounterAttempts = 0;
            cout << "\nYou only have 3 attempts";
            while (DiscountAmount >= Users[UserIndex].AccountsList[AccountIndex].Balance)
            {

                cout << "\nAmount Not Found";
                Amount = GetValidAmount(Amount);
                DiscountAmount = Amount + Amount * 0.01;
                CounterAttempts++;
                if (CounterAttempts == 3)
                    SystemSecurity();
            }
            return DiscountAmount;
        }

        void Deposit() {

            double Amount = 0;
            string CardNumber;
            int AccountIndex;
            bool ValidAmount;



            cout << "\nYou only have 3 attempts";
            CardNumber = GetValidCardNumber(CardNumber);
            AccountIndex = AccountSearch(CardNumber);
            cout << "\nYou only have 3 attempts";
            Amount = GetValidAmount(Amount);


            Users[UserIndex].AccountsList[AccountIndex].Balance += Amount;
            ShowLoading();
            cout << "\n====================================\n";
            cout << "       TRANSACTION SUCCESSFUL       \n";
            cout << "====================================\n";
            cout << "Amount : " << Amount << " EGP\n";
            cout << "New Balance: " << Users[UserIndex].AccountsList[AccountIndex].Balance << " EGP\n";
            ShowDateTime();
            cout << "====================================\n";

        }
        void WithDraw() {
            double Amount = 0;
            string CardNumber;
            int AccountIndex;
            bool ValidAmount;
            double TotalAmount;




            cout << "\nYou only have 3 attempts";
            CardNumber = GetValidCardNumber(CardNumber);
            AccountIndex = AccountSearch(CardNumber);
            cout << "\nYou only have 3 attempts";
            Amount = GetValidAmount(Amount); // amount positive
            TotalAmount = EnsureBalance(Amount, AccountIndex); // amount+taxes<= Balance

            Users[UserIndex].AccountsList[AccountIndex].Balance -= TotalAmount;// Amount+taxes
            ShowLoading();
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


        //void ExecuteUserChoice(int Choice)
        //{


        //    switch (Choice) {
        //    case 1:

        //        CheckBalance();

        //        break;
        //    case 2:
        //        AddNewAccount();

        //        break;
        //    case 3:

        //        Transfer();

        //        break;
        //    case 4:

        //        UserInfo();


        //        break;
        //    case 5:

        //        CheckTransactions();

        //        break;
        //    case 6:

        //        Donate();

        //        break;
        //    case 7:
        //        CounterAttempts = 0;
        //        Deposit();

        //        break;
        //    case 8:
        //        CounterAttempts = 0;
        //        WithDraw();

        //        break;

        //    case 9:
        //        ShowLoading();
        //        system("cls");
        //        LoGin();

        //        break;


        //    }
        //}
    }
