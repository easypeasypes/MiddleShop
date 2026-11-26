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
extern double* salesArr;
extern double* fineArr;
extern size_t maxLogin;
extern size_t minLogin;
extern size_t maxPass;
extern size_t minPass;
extern bool isSetCreated;
extern std::unordered_set<wchar_t> loginSymbols;
extern std::unordered_set<wchar_t> passSymbols;
void ShowUsers(int mode = 0);
void ChangeAccounts();
void CreateNewAccount();
bool CheckLogin(const std::wstring& login);
void CreateSet();
#endif // !_ACCOUNTS_HPP_