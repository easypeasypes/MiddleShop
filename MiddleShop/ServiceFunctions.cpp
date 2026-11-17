#include "ServiceFunctions.hpp"
void Getline(std::wstring& str){
	std::getline(std::wcin, str, L'\n');
}
bool IsNumber(const std::wstring& str){
	if (str.size() <= 0 || str.size() >= 10) {
		std::wcout << L"Ошибка длины. Максимум 9 значное число\n\n";
		Sleep(1500);
		return false;
	}
	for (size_t i = 0; i < str.size(); i++){
		if (!std::isdigit(str[i])) {
			std::wcout << L"Введённые данные не являются числом\n\n";
			Sleep(1500);
			return false;
		}
	}
}
