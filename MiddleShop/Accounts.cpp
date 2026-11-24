#include "Accounts.hpp"

size_t userSize = 3;
size_t currentId = 0;
std::wstring currentStatus;

std::wstring* loginArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
std::wstring* passArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
std::wstring* statusArr = new std::wstring[userSize]{ L"SuperAdmin", L"Admin", L"User" };

size_t* userId = new size_t[userSize] {0, 1, 2};
void ChangeAccounts() {
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
			if (true){// тут онстановились 
				break;
			}
		}
	}
}