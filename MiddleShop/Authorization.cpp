#include "Authorization.hpp"
#include "Accounts.hpp"
void Start(){
	while (true) {
		if (Login()) {
			if (currentStatus == L"SuperAdmin") {
				CreateStorage();
				SuperAdminMenu();
			}
			else if (currentStatus == L"Admin") {
				// TO_DO
				std::wcout << L"Admin menu не сделано";
			}
			else if (currentStatus == L"User") {
				// TO_DO
				std::wcout << L"User menu не сделано";
			}
			else { std::wcerr << L"\n\n_CURRENT_STATUS_LOGIN_ERROR_\n\n"; }
		}
		else {
			system("cls");
			std::wcout << L"Всего доброго\n";
			Sleep(1500);
			break;
		}
	}
}
bool Login() {
	std::wstring login, pass;
	while (true) {
		system("cls");
		std::wcout << L"\n\n\n\t\t\tДобро пожаловать!\n\n\t\t\t\"Чижик\" ";
		std::wcout << L"Введите логин или \"exit\" для выхода: ";
		Getline(login);
		if (login == L"exit" || login == L"Exit") {
			return false;
		}
		else {
			std::wcout << L"Введите пароль: ";
			Getline(pass);
			for (size_t i = 0; i < userSize; i++){
				if(login == loginArr[i] && pass == passArr[i]) {
					std::wcout << L"Добро пожаловать " << loginArr[i] << L"\n";
					std::wcout << L"Ваш уровень доступа: " << statusArr[i] << L"\n";
					currentId = userId[i];
					currentStatus = statusArr[i];
					Sleep(2000);
					return true;
				}
			}
			std::wcout << L"Неверно, по новой\n\n";
			Sleep(1500);
		}
	}
	return false;
}
void SuperAdminMenu(){
	std::wstring choose;
	while (true) {
		system("cls");
		std::wcout << L"1 - Начать продажу\n";
		std::wcout << L"2 - Показать склад\n";
		std::wcout << L"3 - Пополнить товары\n";
		std::wcout << L"4 - Списать товары\n";
		std::wcout << L"5 - Изменить цены\n";
		std::wcout << L"6 - Редактировать склад\n";
		std::wcout << L"7 - Редактировать сотрудников\n";
		std::wcout << L"8 - Отчёт о прибыли\n";
		std::wcout << L"0 - Выход\n";
		std::wcout << L"Ввод: ";
		Getline(choose);
		if (choose == L"1") {

		}
		else if (choose == L"2") {
			ShowStorage();
		}
		else if (choose == L"3") {
			AddProduct();
		}
		else if (choose == L"4") {
			RemoveProduct();
		}
		else if (choose == L"5") {
			ChangePrice();
		}
		else if (choose == L"6") {
			ChangeStorage();
		}
		else if (choose == L"7") {

		}
		else if (choose == L"8") {

		}
		else if (choose == L"0") {

		}
		else {
			Err();
		}
	}
}
