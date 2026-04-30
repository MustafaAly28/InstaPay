#pragma once
#include "DataLayer.h"
#include "FilesLayer.h"
#include "Login.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include<iomanip>

namespace MainMenu {
    void mainWindow();
}
using namespace std;

namespace UserProfile
{

    void ShowUserAccountProfile(int UserIndex, int SelectedAccountIndex)
    {
        system("cls");
        cout << "\t\t\t----------------------------------------------------" << endl;
        cout << "\t\t\tBank Name : " << Users[UserIndex].AccountsList[SelectedAccountIndex].BankName << endl;
        cout << "\t\t\tCard Number : " << Users[UserIndex].AccountsList[SelectedAccountIndex].CardNumber << endl;
        cout << "\t\t\tHolder Name : " << Users[UserIndex].AccountsList[SelectedAccountIndex].HolderName << endl;
        cout << "\t\t\tCVV Code : " << Users[UserIndex].AccountsList[SelectedAccountIndex].CVVCode << endl;
        cout << "\t\t\tExpiration Date : " << Users[UserIndex].AccountsList[SelectedAccountIndex].ExpirationDate << endl;
        cout << "\t\t\tBalance : " << Users[UserIndex].AccountsList[SelectedAccountIndex].Balance << endl << endl;
        cout << "\t\t\t----------------------------------------------------" << endl;
        system("pause");
        system("cls");
    }

    void ShowUserAdvancedProfile(int UserIndex)
    {

        cout << "-----------Linked Bank Accounts------------" << endl << endl;

        int AvailableAccountsCount = 0;
        int AccountIndices[3];
        for (int i = 0; i < 3; i++) {
            if (Users[UserIndex].AccountsList[i].BankName != "") {
                AvailableAccountsCount++;
                AccountIndices[AvailableAccountsCount] = i; //نخزين ال index الحقيقي

                cout << "  " << i + 1 << "- " << Users[UserIndex].AccountsList[i].BankName << endl;

            }

            cout << endl;
        }


        int choice;
        while (true) {

            cout << " Select Number of Account To View Advanced Details (1-" << AvailableAccountsCount << ") Or Press 0 To Back To MainMenu : ";
            cin >> choice;
            if (choice < 1 || choice > AvailableAccountsCount) {
                cout << "Invalid Choice, Please Try Again." << endl;
                continue;
            }
            else if (choice == 0) {
                // return to main menu 
                MainMenu::mainWindow();
            }

            else {
                break;

            }


        }

        int SelectedAccountIndex = AccountIndices[choice];
        int Counter = 3;
        while (Counter > 0) {
            string EnteredPin;
            cout << "Enter 4-digit PIN For " << Users[UserIndex].AccountsList[SelectedAccountIndex].BankName << ": ";
            cin >> EnteredPin;
            Counter--;
            if (EnteredPin == Users[UserIndex].AccountsList[SelectedAccountIndex].PINCode) {
                ShowUserAccountProfile(UserIndex, SelectedAccountIndex);
                break;

            }
            else {
                cout << "Incorrect PIN, Please Try Again." << endl << "   Remaining Attempts: " << Counter << endl;

            }
        }
    }

    // عرض البيانات الاساسية للمستخدم
    void ShowUserBasicProfile(int UserIndex) {

        cout << "_______________________________________ User Profile ______________________________________________" << endl << endl;

        cout << left << setw(20) << "| Name ";
        cout << setw(20) << "| Phone ";
        cout << setw(20) << "| Email ";
        cout << setw(20) << "| Home Number ";
        cout << setw(20) << "| Street ";
        cout << setw(10) << "| City ";
        cout << endl << "__________________________________________________________________________________________" << endl;
        cout << left << setw(20) << "| " << Users[UserIndex].UserName;
        cout << left << setw(20) << "| " << Users[UserIndex].Phone;
        cout << left << setw(20) << "| " << Users[UserIndex].Email;
        cout << left << setw(20) << "| " << Users[UserIndex].Address.HomeNumber;
        cout << left << setw(20) << "| " << Users[UserIndex].Address.Street;
        cout << left << setw(10) << "| " << Users[UserIndex].Address.City;
        cout << endl << "__________________________________________________________________________________________________" << endl;

        system("pause");
        //cout << "Name         : " <<<< endl;
        //cout << "Phone Number : " << Users[UserIndex].Phone << endl;
        //cout << "Email        : " <<  << endl;
        //cout << "Address      : " << Users[UserIndex].Address.HomeNumber << " - " << Users[UserIndex].Address.Street << " - " << Users[UserIndex].Address.City << endl << endl;
        ShowUserAdvancedProfile(UserIndex);
    }
}
