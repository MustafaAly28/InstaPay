#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include"FilesLayer.h"
#include"DataLayer.h"
#include "Login.h"
#include "MainMenu.h"
#include "Services.h"
#include"CheckTransactions.h"
#include "Validation.h"

using namespace Validation;
using namespace File;
using namespace Print;
using namespace Date;

using namespace DataLayer;
using namespace Login;
using namespace MainMenu;
using namespace std;

int main() {
    File::Access_LoadUsersListFromFiles(Users, PersonalInfoFile, AccountsInfoFile, AddressInfoFile, TransactionsInfoFile);

    srand((unsigned int)time(0));
    system("color 0E");
    Login::HaveAccount();

    File::Access_SaveUsersToFiles(Users, AccountsInfoFile, AddressInfoFile, PersonalInfoFile);
}