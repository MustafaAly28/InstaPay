#pragma once
#include<iostream>
using namespace std;

// This Signs For Serilaization On Data Files
/*
	File (Address Data) => Seprator Or Delimeter Is /#/
	(Street/#/City/#/HomeNumber)

	File (Account  Data) => Seprator Or Delimeter Is $
	(CardNumber$HolderName$BankName$CVVCode$ExpirationDate$Balance)

	File (Personal  Data) => Seprator Or Delimeter Is #
	(UserName#Id#Password#Phone#Email#)
*/

const string SepratorPersonalData = "#";
const string SepratorAccountData = "$";
const string SepratorAddressData = "/#/";