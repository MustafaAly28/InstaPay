#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream> 
#include <windows.h> 
#include "DataLayer.h"
#include <cstdlib>
#include <ctime>
//#include "MainMenu.h"
using namespace std;
using namespace DataLayer;
//using namespace MainMenu;
namespace Login {

    void Register();
    void LoGin();
    void HaveAccount();
    void FirstAccount();
    int UserIndex;

    int FindUser(string Name, string Pass) {
        for (int i = 0; i < AddingUsersCounter; i++) {
            if (Name == Users[i].UserName && Pass == Users[i].Password) {
                return i;
            }
        }
        return -1;
    }
   

    bool ValidePhone(string Phone) {//اجمد حاجة عملتها حتي الأن بيتشك علي انه 11 رقم وكمان يكونوا مصري فودافون اورنج اتصالات هكذا

        if (Phone.length() != 11) { cout << "The number must be 01XXXXXXXX!\n"; return false; }
        if (Phone[0] != '0' || Phone[1] != '1') { cout << "Invalid Number! please make sure it's correct." << endl; return false; }

        char ThirdNum = Phone[2];
        if (ThirdNum != '0' && ThirdNum != '1' && ThirdNum != '2' && ThirdNum != '5') {
            cout << "Invalid Number! please make sure it's correct." << endl; return false;
        }

        for (int i = 0;i < Phone.length();i++) {
            if (Phone[i] < '0' || Phone[i]> '9') {
                cout << "Invalid Number! please make sure it's correct." << endl;
                return false;
            }
        }
        for (int i = 0;i < AddingUsersCounter;i++) {
            if (Users[i].Phone == Phone) {

                cout << "This number is not available!" << endl;

                return false;

            }
        }

        return true;
    }




    void ShowLoading() {
        cout << "\nConnecting to Instapay Servers ";
        for (int i = 0; i < 3; i++) {
            Sleep(500); // بينتظر نص ثانية (500 مللي ثانية)
            cout << ".";
        }
        cout << "\n";
        system("cls"); // بيمسح الشاشة بعد ما يخلص
    }



    bool StrongPassword(string Pass) {
        bool HasSymbol = false;

        if (Pass.length() < 8) {
            cout << "[!] Password too short! Minimum length is 8 characters.\n";
            return false;
        }
        for (int i = 0; i < Pass.length();i++) {
            if (Pass[i] == '@' || Pass[i] == '#' || Pass[i] == '$' || Pass[i] == '%' || Pass[i] == '&' || Pass[i] == '!') {
                HasSymbol = true;
            }
        }
        if (!HasSymbol) { cout << "Password must include symbol! (#,$,@)\n"; return false; }
        return true;
    }




    bool ValidEmail(string Email) {
        string AllowedDomains[] = { "@gmail.com", "@yahoo.com", "@outlook.com", "@hotmail.com",//17 Domains
            "@icloud.com", "@aol.com", "@msn.com","@live.com", "@cox.net", "@me.com", "@comcast.net",//GMass
            "@ymail.com", "@sbcglobal.net", "@att.net", "@hotmail.it", "@kw.com", "@mail.ru" };//كل الدومينات بتاعة الايميلات دي جايبها من الموقع ده اشهر دومينات  

        int CounterAt = 0;
        int CounterDot = 0;
        bool DomainFound = false;
        for (int i = 0;i < Email.length();i++) {

            if (Email[i] == ' ') {
                cout << "[!] No spaces allowed!\n";return false;
            }
            //if (Email[Email.length()-4] != '.' || Email[Email.length() - 3] != 'c' || Email[Email.length() - 2] != 'o' || Email[Email.length() - 1] != 'm') { cout << "[!] Invalid Email format!\n"; return false; }الكلين كود يبكي في الزاوية

            if (Email[i] == '@') CounterAt++;
            if (Email[i] == '.') CounterDot++;
        }

        for (int i = 0;i < AddingUsersCounter;i++) {
            if (Email == Users[i].Email) { cout << "This Email is not available!" << endl; return false; }
        }
        if (CounterAt != 1 || CounterDot < 1) {
            cout << "[!] Invalid Email format!\n";
            return false;
        }
        for (int i = 0; i < 17;i++) {
            if (Email.find(AllowedDomains[i]) != string::npos)
            {
                DomainFound = true;
            }
        }
        if (!DomainFound) { cout << "[!] Please use a valid email provider \n"; return false; }
        return true;
    }


    string ConvertToLower(string S) {
        for (int i = 0; i < S.length(); i++) {
            S[i] = tolower(S[i]);
        }
        return S;
    }

    string ConvertToUpper(string S) {
        for (int i = 0; i < S.length(); i++) {
            S[i] = toupper(S[i]);
        }
        return S;
    }


    bool ValidBank(string BankName)
    {


        string BankNames[] = { "Bank Al Ahly", "CIB" , "Bank Masr" ,"NBE","ADIB","QNB","FAB" };
        const int CountBank = 7;
        bool IsValid = true;

        for (int Bank = 0; Bank < CountBank; Bank++)
        {
            if (ConvertToLower(BankNames[Bank]) == ConvertToLower(BankName))
            {
                BankName = BankNames[Bank];
                return IsValid;
            }
        }
        return !IsValid;


    }


    //يارب نتجوز   
    bool ValidCardNumber(string CardNumber) {
        if (CardNumber[0] != '5' && CardNumber[0] != '4') {
            cout << "Card number must start with 4 or 5!\n"; return false;
        }
        if (CardNumber.length() != 16) { cout << "Card number must be xxxx xxxx xxxx xxxx!\n"; return false; }
        for (int i = 0; i < CardNumber.length(); i++) {
            if (!isdigit(CardNumber[i])) {
                cout << "Card number must contain only digits!\n"; return false;
            }
        }
        for (int i = 0; i < AddingUsersCounter; i++) {
            for (int j = 0; j < Users[i].CountAccounts; j++) {
                if (CardNumber == Users[i].AccountsList[j].CardNumber) {
                    cout << "This card number is already in use! Please enter a different one." << endl;
                    return false;
                }
            }
        }
        return true;
    }



    bool ValidExpirationDate(string ExpDate) {
        if (ExpDate.length() != 5 || ExpDate[2] != '/') {
            return false;
        }
        string Month = ExpDate.substr(0, 2);
        string Year = ExpDate.substr(3, 2);
        if (!isdigit(Month[0]) || !isdigit(Month[1]) || !isdigit(Year[0]) || !isdigit(Year[1])) {
            return false;
        }
        int MonthInt = stoi(Month);
        if (MonthInt < 1 || MonthInt > 12) {
            return false;
        }
        int YearInt = stoi(Year);
        if (YearInt < 0 || YearInt > 99) {
            return false;
        }
        return true;
    }

    bool ValidCVV(string CVV) {
        if (CVV.length() != 3) { cout << "CVV must be 3 digits!\n"; return false; }
        for (int i = 0; i < CVV.length(); i++) {
            if (!isdigit(CVV[i])) {
                cout << "CVV must contain only digits!\n"; return false;
            }
        }
        return true;
    }


    bool ValidPIN(string PIN) {
        if (PIN.length() != 4) { cout << "PIN must be 4 digits!\n"; return false; }
        for (int i = 0; i < PIN.length(); i++) {
            if (!isdigit(PIN[i])) {
                cout << "PIN must contain only digits!\n"; return false;
            }
        }
        return true;
    }











    void FirstAccount() {
        cout << "Enter your fist account details\n";
        cout << "Avilable Banks : Bank Al Ahly , CIB , Bank Masr , NBE , ADIB , QNB , FAB\n";
        while (true) {
            while (true) {
                string CheckBank;
                cout << "Enter Bank Name : ";
                getline(cin >> ws, CheckBank);
                if (ValidBank(CheckBank)) {
                    Users[UserIndex].AccountsList[0].BankName = CheckBank;
                    break;
                }
                else {
                    cout << "Invalid Bank Name! Please choose from the available banks.\n";
                }
            }
            while (true) {
                string CheckCard;
                cout << "Enter Card Number : ";
                cin >> CheckCard;
                if (ValidCardNumber(CheckCard)) {
                    Users[UserIndex].AccountsList[0].CardNumber = CheckCard;
                    break;
                }
            }

            while (true) {
                string CheckExp;
                cout << "Enter Expiration Date (MM/YY) : \n";
                cin >> CheckExp;
                if (ValidExpirationDate(CheckExp)) {
                    Users[UserIndex].AccountsList[0].ExpirationDate = CheckExp;
                    break;
                }
                else { cout << "Invalid Expiration Date! Please enter a valid date in MM/YY format.\n"; }
            }

            cout << "Enter Holder Name : ";
            cin.ignore();
            getline(cin, Users[UserIndex].AccountsList[0].HolderName);


            while (true) {
                string  CheckCVV;
                cout << "Enter CVV Code : ";
                cin >> CheckCVV;
                if (ValidCVV(CheckCVV)) {
                    Users[UserIndex].AccountsList[0].CVVCode = CheckCVV;
                    break;
                }
            }
            while (true) {
                cout << "Create a 4 digit PIN code for your account : ";
                string CheckPIN;
                cin >> CheckPIN;
                if (ValidPIN(CheckPIN)) {
                    Users[UserIndex].AccountsList[0].PINCode = CheckPIN;
                    break;
                }
            }

        
            Users[UserIndex].AccountsList[0].Balance =( rand() % 9001)+1000; // Random balance between 1000 and 10000
			cout << "your initial balance is : " << Users[UserIndex].AccountsList[0].Balance << endl;
            cout << "\nAccount Registered Successfully!\n";
            Users[UserIndex].CountAccounts++;
			break;  //adding break at the end of while loop
        }
    }











    void Register() {
        if (AddingUsersCounter >= USERS_COUNT) {
            cout << "System Full!" << endl;
            return;
        }

        cout << "========= Register =========" << endl;

        bool IsTaken;
        string TempName;
        cin.ignore(1000, '\n');
        do {
            IsTaken = false;
            cout << "Enter your name : ";
            //cin >> tempName;
            getline(cin, TempName);

            for (int i = 0; i < AddingUsersCounter; i++) {
                if (TempName == Users[i].UserName) {
                    IsTaken = true;
                    cout << "This name already taken! enter another name.\n" << endl;
                    break;
                }
              }
        } while (IsTaken);

        Users[AddingUsersCounter].UserName = TempName;

        


        string CheckEmail;
        bool EmailFalse;
        while (true) {
            cout << "Enter email : ";

            cin >> CheckEmail;
            EmailFalse = ValidEmail(CheckEmail);
            if (EmailFalse) {
                Users[AddingUsersCounter].Email = CheckEmail;
                break;
            }
        } while (!EmailFalse);

         



        bool TestPhone = false;
        do {

            cout << "Enter phone : ";
            cin >> Users[AddingUsersCounter].Phone;
            TestPhone = ValidePhone(Users[AddingUsersCounter].Phone);


        } while (TestPhone == false);
        
		cout << "Enter your address details\n";
		cout << "-----------------------------\n";
		cout << "Enter city : ";
        getline(cin>>ws, Users[AddingUsersCounter].Address.City);
        cout << "Enter street name : ";
		getline(cin>>ws, Users[AddingUsersCounter].Address.Street);
        cout << "Enter home number : ";
		getline(cin>>ws, Users[AddingUsersCounter].Address.HomeNumber);
        cout << "-----------------------------\n";
        string Pass, Confirm;
        do {
            while (true) {
                cout << "Enter password : ";
                cin >> Pass;

                if (StrongPassword(Pass)) { break; }

            }

            cout << "Confirm password : ";
            cin >> Confirm;

            if (Pass != Confirm) cout << "Passwords do not match! Try again." << endl;
        } while (Pass != Confirm);

        Users[AddingUsersCounter].Password = Confirm;
        

        Users[AddingUsersCounter].Id = AddingUsersCounter + 1;
        AddingUsersCounter++;
		cout << "Sign Up Successful!\n";
		cout << "Your ID is : " << Users[AddingUsersCounter - 1].Id << endl;
        LoGin();

        //SaveToFile(); // حفظ البيانات في الملف
       // ShowLoading();
        //cout << "User Registered Successfully!" << endl;
        cin.ignore();
    }

    void LoGin() {
        ShowLoading();
        cout << "================================" << "\n";
        cout << "            INSTAPAY            " << "\n";
        cout << "================================" << "\n";

        // يفضل تشيل ShowLoading() من هنا عشان ملهاش لازمة تظهر قبل ما اليوزر يكتب حاجة

        string CheckName, CheckPassword;
        int Counter = 0;

        cout << "Three Attempts to login\n";

        // شيلنا الـ cin.ignore من هنا عشان متعملش تعليقة للبرنامج

        do {
            cout << "\n========= Login Page ========" << endl;
            cout << "Enter your name : ";

          
            if (cin.peek() == '\n') cin.ignore();
            getline(cin, CheckName);

            cout << "Enter your password : ";
            cin >> CheckPassword;
            cin.ignore(1000, '\n');

            UserIndex = FindUser(CheckName, CheckPassword);

            if (UserIndex != -1) {
                ShowLoading();
                cout << "Login Successful! Welcome, " << Users[UserIndex].UserName << " Your ID : " << Users[UserIndex].Id << endl;

               
                if (Users[UserIndex].CountAccounts == 0) {
                    FirstAccount();
                }

                
                //MainMenu::mainWindow(); 

                return; 
            }
            else {
                cout << "Invalid!! username or password." << endl;
                Counter++;
                
            }

        } while (Counter < 3);

        
        cout << "\n[!] Access Denied. Returning to start..." << endl;
    }
    void HaveAccount() {
        char Choice;
        cout << "Do you have an account? (Y/N) : ";
        cin >> Choice;
        if (Choice == 'Y' || Choice == 'y') {
            ShowLoading();
            LoGin();
        }
        else if (Choice == 'N' || Choice == 'n') {
            ShowLoading();
            Register();
        }
        else {
            cout << "Invalid choice! Please enter Y or N.\n";
            HaveAccount();
        }
    }
}
