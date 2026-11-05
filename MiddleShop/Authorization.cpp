#include "Authorization.hpp"

void Start(){
	while (true) {
		if (Login()) {

		}
		else {
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
		std::wcout << L"\n\n\n\t\t\tДобро пожаловать!\n\n\t\t\tЧижик";
		std::wcout << L"Введите логин или \"exit\" для выхода: ";
		Getline(login);
		if (login == L"exit" || login == L"Exit") {
			return false;
		}
		else {
			std::wcout << L"Введите пароль: ";
			Getline(pass);

		}
	}
	return false;
}