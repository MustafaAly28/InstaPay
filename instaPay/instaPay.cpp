#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Transaction {
    string FromPhone;    // رقم هاتف المرسل 
    string ToPhone;      // رقم هاتف المستقبل 
    double Amount;       // المبلغ المحول 
};

struct Account {
    string CardNo;          // رقم الكارت 
    string HolderName;      // اسم صاحب الحساب 
    string CvvCode;            // كود الـ CVV 
    string ExpirationDate;  // تاريخ الانتهاء 
    string BankName;        // اسم البنك 
    double Balance;         // الرصيد هيبقى قيمة عشوائية من اول 0 لغاية 1000
};

struct User {
    int Id;                      // المعرف الفريد للمستخدم 
    string UserName;             // اسم المستخدم 
    string Password;             // كلمة المرور 
    string Email;                // البريد الإلكتروني 
    string Address;              // العنوان 
    string Phone;                // رقم التليفون
    Account UserAccounts[3];     // كل مستخدم ليه بحد اقصي 3 حسابات
    int AccountsCount = 0;  
    Transaction transactions[NumUsers];         // عدد الحسابات المضافة فعلياً
};
const int NumUsers = 10;
User Users[NumUsers];

int UserCount = 0;
int TransactionCount = 0;
int CurrentUserIndex = -1;
void Login();
void SignUp();
void Menu();
void MainWindow();
void Transfer();
void Deposit();
void Witdraw();
void CheckBalance();
void AddNewAccount();
void CheckTransactions();
void SaveToFile();
void LoadFromFile();
void UserInfo();
void Donate();

void SignUp() {

};
void Login() {

};

void Menu() {

}

void MainWindow() {

};
void Witdraw() {

}
void Deposit() {

}



void Transfer() {

}
void CheckBalance() {

}


void AddNewAccount() {

}

void CheckTransactions() {

}



void SaveToFile() {

}

void LoadFromFile() {

}


void UserInfo() {

}

void Donate() {

}
int main() {

}