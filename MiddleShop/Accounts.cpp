#include "Accounts.hpp"

size_t userSize = 3;
size_t currentId = 0;
std::wstring currentStatus;

std::wstring* loginArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
std::wstring* passArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
std::wstring* statusArr = new std::wstring[userSize]{ L"SuperAdmin", L"Admin", L"User" };

size_t* userId = new size_t[userSize] {0, 1, 2};
double* salesArr = 0;
double* fineArr = 0;
size_t maxLogin = 12;
size_t minLogin = 5;
size_t maxPass = 16;
size_t minPass = 8;
bool isSetCreated = false;
std::unordered_set<wchar_t> loginSymbols;
std::unordered_set<wchar_t> passSymbols;
void ShowUsers(int mode){
	if (mode == 0) {
		system("cls");
		std::wcout << L"ID\t" << std::left << std::setw(maxLogin) << L"Логин\t" << std::setw(maxPass) << L"Пароль\t" << std::setw(statusArr[0].size() + 2) << L"Роль\t" << L"Продажи\t\t" << L"Штрафы\n\n";
		// остановились
		std::wcout << "\n\n";
		system("pause");
	}
}
void ChangeAccounts() {
	if (!isSetCreated) {
		CreateSet();
	}
	std::wstring choose;
	while (true) {
		system("cls");
		std::wcout << L"\n\n\t\tРедактирование учётных записей";
		std::wcout << L"1 - Создать новый аккаунт\n";
		std::wcout << L"2 - Показать всех сотрудников\n";
		std::wcout << L"3 - Изменить логин\n";
		std::wcout << L"4 - Изменить уровень доступа\n";
		std::wcout << L"5 - Редактировать премии и штрафы сотрудничества\n";
		std::wcout << L"0 - Выход\n";
		std::wcout << L"Ввод: ";
		Getline(choose);
		if (choose == L"1") {

		}
		else if (choose == L"2") {

		}
		else if (choose == L"3") {

		}
		else if (choose == L"4") {

		}
		else if (choose == L"5") {

		}
		else if (choose == L"6") {

		}
		else if (choose == L"0") {
			std::wcout << L"Выход из настроек админа\n\n";
			Sleep(1500);
			break;
		}
		else {
			Err();
		}
	}
}
void CreateNewAccount() {
	std::wstring chooseLogin, choosePass, chooseStatus, choose;
	while (true) {
		while (true) {
			system("cls");
			std::wcout << L"Введите логин для нового пользователя или \"exit\" для выхода: ";
			Getline(chooseLogin);
			if (chooseLogin == L"exit" || chooseLogin == L"Exit") {
				std::wcout << L"Отмена создания учётной записи\n\n";
				Sleep(1500);
				return;
			}
			if (CheckLogin(chooseLogin)) {
				break;
			}
		}
		while (true) {
			system("cls");
			std::wcout << L"Введите логин для нового пользователя или \"exit\" для выхода: ";
			Getline(choosePass);
			if (choosePass == L"exit" || choosePass == L"Exit") {
				std::wcout << L"Отмена создания учётной записи\n\n";
				Sleep(1500);
				return;
			}
			if (CheckLogin(choosePass)) {
				break;
			}
		}
		while (true) {
			system("cls");
			std::wcout << L"Введите логин для нового пользователя или \"exit\" для выхода: \n\n";
			std::wcout << L"1 - Сотрудник\n";
			std::wcout << L"2 - Администратор\n\n";
			std::wcout << L"Ввод: ";
			Getline(choose);
			if (choose == L"exit" || choose == L"Exit") {
				std::wcout << L"Отмена создания учётной записи\n\n";
				Sleep(1500);
				return;
			}
			if (choose == L"1") {
				chooseStatus = L"User";
				break;
			}
			else if (choose == L"2") {
				std::wcout << L"Для подтверждения введите пароль Супер Администратора: ";
				Getline(choose);
				if (choose == passArr[0]) {
					chooseStatus = L"Admin";
					break;
				}
				else {
					Err();
				}
			}
			else {
				Err();
			}
		}
		while (true) {
			system("cls");
			std::wcout << L"Логин: " << chooseLogin << L"\n";
			std::wcout << L"Пароль: " << choosePass << L"\n";
			std::wcout << L"Роль: " << chooseStatus << L"\n";
			std::wcout << L"Подтвердить?\n1 - Да\n2 - Отмена\n\nВвод: ";
			Getline(choose);
			if (choose == L"1") {
				std::wcout << L"Создание аккаунта";
				for (size_t i = 0; i < 3; i++){
					Sleep(650);
					std::wcout << L" .";
				}
				Sleep(650);
				ArrPushBack(userId, userSize);
				ArrPushBack(loginArr, userSize);
				ArrPushBack(passArr, userSize);
				ArrPushBack(statusArr, userSize);
				ArrPushBack(fineArr, userSize);
				ArrPushBack(salesArr, userSize);
				userSize++;
				userId[userSize - 1] = userSize - 1;
				loginArr[userSize - 1] = chooseLogin;
				passArr[userSize - 1] = choosePass ;
				statusArr[userSize - 1] = chooseStatus;
				fineArr[userSize - 1] = 0.0;
				salesArr[userSize - 1] = 0.0;
				std::wcout << L"\n\nУчётная запись создана\n\n";
				Sleep(1500);
				break;
			}
			else if (choose == L"2") {
				std::wcout << L"Отмена создания учётной записи\n";
				Sleep(1500);
				break;
			}
			else {
				Err();
			}
		}
	}
}
bool CheckLogin(const std::wstring& login) {
		if (login.size() < minLogin || login.size() > maxLogin) {
				std::wcout << "LОшибка длины логина! Допустимо от " << minLogin << L" до " << maxLogin << L" символов \n\n";
				Sleep(1500);
				return false;
			}
		if (!IsNotSame(login, loginArr, userSize)) {
				std::wcout << L"Такой пользователь уже создан\n\n";
				Sleep(1500);
				return false;
			}
			int count = 0;
		for (size_t i = 0; i < login.size(); i++) {
				if (!loginSymbols.count(login[i])) {
					std::wcout << L"Некорректные символ в логине\nДопустимые символы: A-Z, a-z, 0-9\n\n";
					Sleep(1400);
					return false;
				}
				if (std::iswdigit(login[i]) && count) {
					count++;
				}
			}
		if (count >= 4) {
				return true;
			}
		else {
				std::wcout << L"Слишком мало буквенных символов! Минимум 4 символа верхнего или нижнего регистров!\n\n";
				Sleep(1600);
				return false;
		}
	}
bool CheckPass(const std::wstring& pass) {
	if (pass.size() < minPass || pass.size() > maxPass) {
		std::wcout << "LОшибка длины пароля! Допустимо от " << minPass << L" до " << maxPass << L" символов \n\n";
		Sleep(1500);
		return false;
	}
	if (!IsNotSame(pass, passArr, userSize)) {
		std::wcout << L"Такой пользователь уже создан\n\n";
		Sleep(1500);
		return false;
	}
	int symbolCount = 0, letterCount = 0, letterCapCount = 0, numberCount = 0;
	for (size_t i = 0; i < pass.size(); i++) {
		if (!loginSymbols.count(pass[i])) {
			std::wcout << L"Некорректные символ в логине\nДопустимые символы: A-Z, a-z, 0-9 и спец символы\n\n";
			Sleep(1400);
			return false;
		}
		if (std::iswdigit(pass[i]) && numberCount < 2) {
			numberCount++;
		}
		else if (pass[i] >= L'A' && pass[i] <= L'Z' && letterCapCount < 1) {
			letterCapCount++;
		}
		else if (pass[i] >= L'a' && pass[i] <= L'z' && letterCapCount < 4) {
			letterCapCount++;
		}
		else {
			symbolCount++;
		}
	}
	if (symbolCount > 0 && letterCount > 3 && letterCapCount > 0 && numberCount > 1) {
		return true;
	}
	else {
		std::wcout << L"Некорректный пароль! Минимальные требования:\nЦифры - 2 и более\nНижний регистр - 4 и более\nВерхний регистр букв - 1 и более\nСпециальные символы - 1 и более\n\n";
		Sleep(1600);
		return false;
	}
}
void CreateSet() {
	for (wchar_t i = L'0'; i <= L'9'; i++)
	{
		loginSymbols.insert(i);
	}
	for (wchar_t i = L'A'; i <= L'Z'; i++)
	{
		loginSymbols.insert(i);
	}	for (wchar_t i = L'a'; i <= L'z'; i++)
	{
		loginSymbols.insert(i);
	}
	for (wchar_t i = L'!'; i <= L'~'; i++)
	{
		passSymbols.insert(i);
	}
	isSetCreated = true;
}