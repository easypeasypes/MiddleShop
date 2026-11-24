#ifndef _ACCOUNTS_HPP_
#define _ACCOUNTS_HPP_

#include "ServiceFunctions.hpp"	

extern size_t userSize;
extern size_t currentId;
extern std::wstring currentStatus;

extern size_t* userId;
extern std::wstring* statusArr;
extern std::wstring* passArr;
extern std::wstring* loginArr;
void ChangeAccounts();
void CreateNewAccount();
#endif // !_ACCOUNTS_HPP_