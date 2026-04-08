//#include <iostream>
//#include <string>
//#include <cmath>
//#include <ctime>
//#include <fstream>
//#include <iomanip>
//#include <cstdlib>
//
//using namespace std;
//
//struct Transaction {
//    string fromPhone;    // رقم هاتف المرسل 
//    string toPhone;      // رقم هاتف المستقبل 
//    double amount;       // المبلغ المحول 
//};
//
//struct Account {
//    string cardNo;          // رقم الكارت 
//    string holderName;      // اسم صاحب الحساب 
//    int cvvCode;            // كود الـ CVV 
//    string expirationDate;  // تاريخ الانتهاء 
//    string bankName;        // اسم البنك 
//    double balance;         // الرصيد هيبقى قيمة عشوائية من اول 0 لغاية 1000
//};
//
//struct User {
//    int id;                      // المعرف الفريد للمستخدم 
//    string userName;             // اسم المستخدم 
//    string password;             // كلمة المرور 
//    string email;                // البريد الإلكتروني 
//    string address;              // العنوان 
//    string phone;                // رقم التليفون
//    Account userAccounts[3];     // كل مستخدم ليه بحد اقصي 3 حسابات
//    int accountsCount = 0;           // عدد الحسابات المضافة فعلياً
//};
//const int numUsers = 10;
//User users[numUsers];
//Transaction transactions[numUsers];
//int userCount = 0;
//int transactionCount = 0;
//int currentUserIndex = -1;
//void login();
//void signIn();
//void mainWindow();
//void transfer();
//void checkBalance();
//void addNewAccount();
//void checkTransactions();
//void saveToFile();
//void loadFromFile();
//void userInfo();
//void donate();
////task member 1
//void signIn() {
//    string confirmPassword;
//    cout << "\t\t\t\t============================================\n";
//    cout << "\t\t\t\t                  SIGN IN\n";
//    cout << "\t\t\t\t============================================\n";
//    
////2- اليوزر هيكتب الايميل بتاعو 
//    cout << "Enter your Email : ";
//    cin >> users[userCount].email;
////3- اليوزر هيسجل رقم الفون بتاعو
//    cout << "Enter Phone number : ";
//    cin >> users[userCount].phone;
////4- اليوزر هيكتب العنوان بتاعو 
//    cout << "Enter your address : ";
//    getline(cin >> ws, users[userCount].address);
////5- اليوزر هيكتب ال username 
//    cout << "Enter your username : ";
//    getline(cin >> ws, users[userCount].userName);
////6- اليوزر هيعمل الباسوورد بتاعو
//    cout << "Enter a new password : ";
//    cin >> users[userCount].password;
//
////7- هتعمل كونفيرم للباسوورد ولو الكونفيرم باسوورد مش نفس الباسوورد هتطلع رسالة بتقول ان الكونفيرم باسوورد not match
//    
//    do
//    {
//    cout << "Confirm Password : ";
//    cin >> confirmPassword;
//    if (confirmPassword != users[userCount].password)
//    {
//        cout << "Error!\n";
//        
//    }
//    
//
//    } while (confirmPassword != users[userCount].password);
//    userCount++;
//    cout << "----------------------------------------------------------------------------------------------------------------------\n";
//    login();
//    
//};
//void login() {
//    string phoneNum;
//    string pass;
//    cout << "\t\t\t\t============================================\n";
//    cout << "\t\t\t\t                  LOGIN\n";
//    cout << "\t\t\t\t============================================\n";
//    //1- اليوزر هيسجل رقم التليفون بتاعو
//    cout << "Enter your phone number : ";
//    cin >> phoneNum;
//    //2- اليوزر هيكتب كلمة السر بتاعتو
//    cout << "Enter your password : ";
//    cin >> pass;
//    //لو في حاجة غلط سواء رقم التليفون مش موجود قبل كده اصلا او كلمة السر غلط
//    bool found = false;
//    for (int i = 0; i < userCount; i++)
//    {
//        if (phoneNum == users[i].phone && pass == users[i].password) {
//            found = true;
//            currentUserIndex = i;
//            break;
//
//        }
//    }
//    if (found)
//    {
//        cout << "login successfully." << endl;
//        cout << "-----------------------------------------------------------------------------------------------------------------\n";
//        mainWindow();
//    }
//    else
//    {
//        cout << "The phone number or password is incorrect!" << endl;
//        cout << "-----------------------------------------------------------------------------------------------------------------\n";
//        signIn();
//    }
//    // هتعرض رسالة تعرفو ان في حاجة غلط 
//    
//};
//
//
////task member 2
//void mainWindow() {
//    int choise;
//    cout << "\t\t\t\t============================================\n";
//    cout << "\t\t\t\t                  MAIN WINDOW\n";
//    cout << "\t\t\t\t============================================\n";
//    if (currentUserIndex == -1)
//    {
//        cout << "No accounts has sign in." << endl;
//    }
//    
//    else
//    {
//        cout << "[1] Check Balance" << endl;
//        cout << "[2] add new Account" << endl;
//        cout << "[3] Transfer\n";
//        cout << "[4] Transactions\n";
//        cout << "[5] Info\n";
//        cout << "[6] donate\n";
//        cout << "Enter your choise from (1-6) : ";
//        cin >> choise;
//    }
//    
//    // دي الصفحة الرئيسية اللي هتعرضلو فيها كل حاجة ممكن هو يختارها
//    // زي مثلا (i.e. Check Balance, add new Account, Transfer, etc.)
//};
//
//
//
//
////task member 3
//void transfer() {
//    // 1. اختيار الحساب المرسل
//    // 2. إدخال رقم هاتف المستقبل والتأكد من وجوده 
//    // 3. التأكد من كفاية الرصيد 
//    // 4. الخصم والإضافة وتحديث المصفوفة
//}
//void checkBalance() {
//    // عرض رصيد حساب معين يختاره المستخدم 
//}
//
//// task member 4
//void addNewAccount() {
//    // إضافة حساب بنكي جديد للمستخدم الحالي 
//    // يعني المستخدم ممكن يضيف حساب جديد بنفس رقم التليفون
//    //The cardNo, HolderName, CVV_Code, expireation Date and BankName are added manually by the user, the balance is set to random value starting from 1000.
//}
//
//void checkTransactions() {
//    // عرض العمليات التي تخص المستخدم الحالي فقط 
//}
//
//
//// task member 5
//void saveToFile() {
//    // حفظ كل المصفوفات في ملفات .txt 
//}
//
//void loadFromFile() {
//    // تحميل البيانات من الملفات للمصفوفات عند التشغيل 
//}
//
//// task member 6
//void userInfo() {
//    // هتعرض كل المعلومات اللي تخص اليوزر
//}
//
//void donate() {
//
//}
//int main() {
//    login();
//    mainWindow();
//
//
//}
#include<iostream>
#include"FilesLayer.h"
#include"Services.h"

using namespace Print;
using namespace std;
using namespace File;

int main()
{
	File::FillDataToUsersListFromFiles(Users, PersonalInfoFile, AccountsInfoFile, AddressInfoFile);

	for (int Position = 0; Position < 2; Position++)
	{
		Print::PrintData(Users[Position]);
	}
	return 0;

}