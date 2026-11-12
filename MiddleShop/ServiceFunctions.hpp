#ifndef _SERVICE_FUNCTIONS_HPP_
#define _SERVICE_FUNCTIONS_HPP_

#include <string>
#include <iostream>
#include <Windows.h>
#include <iomanip>
inline void Err() {
	std::wcout << L"Некорректный ввод\n\n";
	Sleep(1500);
}
void Getline(std::wstring& str);
template<typename ArrType>
void FillArray(ArrType* dynamiArr, ArrType* staticArr, size_t commonSize) {
	for (size_t i = 0; i < commonSize; i++){
		dynamiArr[i] = staticArr[i];
	}
}
#endif // !_SERVICE_FUNCTIONS_HPP_