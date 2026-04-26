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
#define _CRT_SECURE_NO_WARNINGS
//#include"Funcs.h"
//using namespace Funcs;
using namespace Login;
using namespace std;
//using namespace Login;
namespace Login { extern int UserIndex; }
namespace MainMenu
{
    void Deposit();
    void WithDraw();
    /*int UserIndex =-1;*/
    int CounterAttempts = 0;


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
        

        cout << "Date & Time: " << ctime(&now);
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

    string GetPIN() {
        string PIN;
        cout << "\nEnter PIN : ";
        cin >> PIN;

        return PIN;
    }

    void CheckPIN(string PIN, int AccountIndex) {

        cout << "\nYou only have 3 attempts";
        while (true)
        {

            PIN = GetPIN();

            if (Users[UserIndex].AccountsList[AccountIndex].PINCode == PIN)
            {
                CounterAttempts = 0;
                system("cls");
                return;


            }

            cout << "Invalid PIN Or Does Not Exist";
            CounterAttempts++;


            if (CounterAttempts == 3) {
                CounterAttempts = 0;
                SystemSecurity();
                system("cls");
            }

        }




    }

    bool Exist = false;

    void AskUser(char Answer)
    {
        while (Answer != 'Y' && Answer != 'y' && Answer != 'N' && Answer != 'n')
        {

            cout << "Answer Must Be Y/N ";
            cout << "Answer : ";
            cin >> Answer;
        }
        if (Answer == 'N' || Answer == 'n')
        {
            cout << "Thank You";
            Exist = true;
        }
    }
    void mainWindow() {

        bool ValidChoice;
        while (true) {

            system("Color 0E"); // Color The Font

            cout << "\n========================================";
            cout << "\n            INSTAPAY EGYPT             ";
            cout << "\n========================================";
            cout << "\n  1. Check Balance      2. Add Account";
            cout << "\n  3. Transfer           4. User Info";
            cout << "\n  5. Transactions       6. Donation";
            cout << "\n  7. Deposit            8. Withdraw";
            cout << "\n  9. Logout             0.Exist    ";
            cout << "\n========================================";




            char Answer;
            int Choice;
            do
            {

                cout << "\nEnter Your Choice from (0-9) : ";
                cin >> Choice;


                if (Choice >= 0 && Choice <= 9)
                {

                    ValidChoice = true;
                }
                else
                {
                    cout << "Invalid Choice !";
                    ValidChoice = false;
                }

            } while (ValidChoice == false);

            switch (Choice) {
            case 1:
                //CheckBalance();

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
                cout << "For Main Menu Y/y To Exist N/n ";
                cout << "Answer : ";
                cin >> Answer;
                AskUser(Answer);

                break;
            case 8:
                CounterAttempts = 0;
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

            default:
                Exist = true;
                cout << "Thank You";

            }
            if (Exist)
                break;
        }


    }


    string GetCardNumber() {
        string CardNumber;
        cout << "\nEnter CardNumber As XXXX XXXX XXXX XXXX : ";
        cin >> CardNumber;
        return CardNumber;
    }

    /*    bool ValidCardNumber(string CardNumber) {
            bool ValidCardNumber= true;
            if (CardNumber[0] != '5' && CardNumber[0] != '4')
            {
                cout << "Card number must start with 4 or 5!\n"; ValidCardNumber = false;

            }
            if (CardNumber.length() != 16)
            {
                cout << "Card number must be xxxx xxxx xxxx xxxx!\n"; ValidCardNumber = false;
            }
            for (int i = 0; i < CardNumber.length(); i++)
            {
                if (!isdigit(CardNumber[i]))
                {
                    cout << "Card number must contain only digits!\n"; ValidCardNumber = false;
                }
            }


            return ValidCardNumber;
        }*/
        /*  string GetValidCardNumber(string CardNumber) {

              cout << "\nYou only have 3 attempts";
              while (true)
              {

                  CardNumber = GetCardNumber();
                  if (ValidCardNumber(CardNumber)==true)
                  {
                      CounterAttempts = 0;

                      ShowLoading();
                      return CardNumber;

                  }
                  cout << "Invalid Card Number";
                  CounterAttempts++;


                  if (CounterAttempts == 3) {
                      CounterAttempts = 0;
                      SystemSecurity();
                      system("cls");
                  }


              }




          }*/
    bool CheckAccountExist(string CardNumber)
    {


        for (int Index = 0; Index < 3; Index++) // Know  Which Any Account Belong To His Card Number
        {
            if (Users[UserIndex].AccountsList[Index].CardNumber == CardNumber)
            {


                return true;

            }
        }
        return false;
    }

    double GetAmount() {
        double Amount;
        cout << "\nAmount : ";
        cin >> Amount;
        return Amount;
    }

    double GetValidAmount(double Amount, int AccountIndex, bool OperatorDeposite = false) {
        bool ValidAmount = true;

        cout << "\nYou only have 3 attempts";
        do
        {
            ValidAmount = true;
            Amount = GetAmount();
            if (Amount <= 0)
            {
                cout << "Amount Must Be positive";
                ValidAmount = false;

            }
            if (OperatorDeposite)
            {
                if ((Amount + Amount * 0.01) > Users[UserIndex].AccountsList[AccountIndex].Balance)//taxex+amount
                {

                    cout << "Balance Not Enough";
                    ValidAmount = false;

                }
            }
            if (ValidAmount == false)
                CounterAttempts++;




            if (CounterAttempts == 3)
            {
                CounterAttempts = 0;
                SystemSecurity();
                system("cls");
            }

        } while (ValidAmount == false);
        CounterAttempts = 0;
        return Amount;
    }

    void Deposit() {

        double Amount = 0;
        string CardNumber;
        int AccountIndex ;
        bool ValidAmount;








        while (true)
        {

            CardNumber = GetCardNumber();
            if (CheckAccountExist(CardNumber) == true)
                break;
            else
                cout << "Invalid Card Number Or Does Not Exist";        

        }

        for (int Index = 0; Index < 3; Index++) // Know  Which Any Account Belong To His Card Number
        {
            if (Users[UserIndex].AccountsList[Index].CardNumber == CardNumber)
            {

                AccountIndex = Index;


            }
        }
   
            
           
            Amount = GetValidAmount(Amount,AccountIndex);
            string PIN;
           
            
            CheckPIN(PIN, AccountIndex);

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
            int AccountIndex={};
            string PIN;
          
           
           

            while (true)
            {

                CardNumber = GetCardNumber();
                if (CheckAccountExist(CardNumber) == true)
                    break;
                else
                    cout << "Invalid Card Number Or Does Not Exist";

            }

            for (int Index = 0; Index < 3; Index++) // Know  Which Any Account Belong To His Card Number
            {
                if (Users[UserIndex].AccountsList[Index].CardNumber == CardNumber)
                {

                    AccountIndex = Index;


                }
            }

            Amount = GetValidAmount(Amount,AccountIndex,true);
        
            
            CheckPIN(PIN, AccountIndex);

            Users[UserIndex].AccountsList[AccountIndex].Balance -= (Amount + Amount * 0.01);// Amount+taxes
            ShowLoading();
            cout << "\n====================================\n";
            cout << "       TRANSACTION SUCCESSFUL       \n";
            cout << "====================================\n";
            cout << "Amount : " << Amount << " EGP\n";
            cout << "Taxes : " << Amount * 0.01 << " EGP\n";
            cout << "Amount was Drawen : " << (Amount+Amount*0.01) << " EGP\n";
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
