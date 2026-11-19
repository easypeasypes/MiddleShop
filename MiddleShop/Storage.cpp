#include "Storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
double maxPrice = 9999;
extern bool IsStorageCreated = false;
size_t maxStorageSize = 1000;
size_t currentStorageSize = 0;
void CreateStorage(int mode) {
	if (mode == 0 && !IsStorageCreated) {
	const size_t staticSize = 10;

	size_t idArrStatic[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::wstring nameArrStatic[staticSize]{
		L"Хлеб",L"Молоко",L"Колбаса",L"Макароны",L"Кетчуп",
		L"Чипсы",L"Кириешки",L"Масло",L"Булка (с чем то)",L"Холодец(бесценный)"
	};//							   1	 2	   3	4   5	6	 7	   8	9	10
	double priceArrStatic[staticSize]{ 67, 66.99, 122, 70, 90, 100, 9.99, 200, 33, 9999 };
	size_t countArrStatic[staticSize]{ 50,  30,	  30, 100, 90, 150, 200, 50,   40,   1 };
	sizeSt = staticSize;
	idArr = new size_t[sizeSt];
	nameArr = new std::wstring[sizeSt];
	countArr = new size_t[sizeSt];
	priceArr = new double[sizeSt];

	FillArray(idArr, idArrStatic, sizeSt);
	FillArray(nameArr, nameArrStatic, sizeSt);
	FillArray(countArr, countArrStatic, sizeSt);
	FillArray(priceArr, priceArrStatic, sizeSt);

	for (size_t i = 0; i < sizeSt; i++)
	{
		currentStorageSize += countArrStatic[i];
	}
	IsStorageCreated = true;
	}
	else if (mode == 1) {

	}
	else {
		std::wcout << L"\nСклад уже создан\n";
	}
}
void ShowStorage(int mode){
	if (mode == 0) {
		system("cls");
		std::wcout << L"ID\t" << std::left << std::setw(38) << L"Название товара\t" << L"Кол-во \t" << L"Цена \n\n";
		for (size_t i = 0; i < sizeSt; i++){
			std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(30) << nameArr[i] << L"\t\t" << countArr[i] << L"\t" << std::setprecision(2) << priceArr[i] << L"\n";
		}
		system("pause");
	}
	else if (mode == 1) {
		std::wcout << L"\t\t\tЗаполненность склада \"Чижик\"\n\n";
		std::wcout << L"ID\t" << std::left << std::setw(38) << L"Название товара\t" << L"Кол-во \t\n";
		for (size_t i = 0; i < sizeSt; i++) {
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(30) << nameArr[i] << L"\t\t" << countArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Заполненность склада: " << currentStorageSize << L" из " << maxStorageSize << L"\n\n";
	}
	else if (mode == 2) {
		std::wcout << L"\t\t\tСписание у склада \"Чижик\"\n\n";
		std::wcout << L"ID\t" << std::left << std::setw(38) << L"Название товара\t" << L"Кол-во \t\n";
		for (size_t i = 0; i < sizeSt; i++) {
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(30) << nameArr[i] << L"\t\t" << countArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Заполненность склада: " << currentStorageSize << L" из " << maxStorageSize << L"\n\n";
	}
	else if (mode == 3) {
		std::wcout << L"\t\t\tИзменение цены \"Чижик\"\n\n";
		std::wcout << L"ID\t" << std::left << std::setw(38) << L"Название товара\t" << L"Цена \t\n";
		for (size_t i = 0; i < sizeSt; i++) {
			std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(30) << nameArr[i] << L"\t\t" << std::setprecision(2) << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
	}
	else if (mode == 4) {
		system("cls");
		std::wcout << L"\n\n\t\t\tТовары \"Чижик\"\n\n";
		std::wcout << L"ID\t" << std::left << std::setw(38) << L"Название товара\t" << L"Цена \t\n";
		for (size_t i = 0; i < sizeSt; i++) {
			std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(30) << nameArr[i] << L"\t\t" << std::setprecision(2) << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
	}
	else {
		std::wcerr << L"_SHOW_STORAGE_MODE_MODE_NOT_FOUND_";
	}
}
void AddProduct(){
	std::wstring chooseId, chooseCount, choose;
	int id = 0;
	size_t count = 0;
	while (true) {
		system("cls");
		ShowStorage(1);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit") {
			std::wcout << L"Завершение операции пополнения товара\n\n";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId)) {
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1) {
				Err();
			}
			else {
				std::wcout << L"ВВедите количество товара для пополнения: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount)) {
					count = std::stoull(chooseCount);
					if (count < 0 || count > maxStorageSize - currentStorageSize) {
						std::wcout << L"Некорректное количество! На складе осталось " << maxStorageSize - currentStorageSize << L" Свободных мест";
						Sleep(2000);
					}
					else {
						while (true) {
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> " << countArr[id] + count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
							Getline(choose);
							if (choose == L"1") {
								std::wcout << L"Товар успешно пополнен\n\n";
								countArr[id] += count;
								currentStorageSize += count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2") {
								std::wcout << L"Отмена пополнения " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else {
								Err();
							}
						}
					}
				}
			}
		}
	}
}
void RemoveProduct(){
	std::wstring chooseId, chooseCount, choose;
	int id = 0;
	size_t count = 0;
	while (true) {
		system("cls");
		ShowStorage(2);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit") {
			std::wcout << L"Завершение операции списания товара\n\n";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId)) {
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1) {
				Err();
			}
			else {
				std::wcout << L"ВВедите количество товара для списания: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount)) {
					count = std::stoull(chooseCount);
					if (count < 0 || count > countArr[id]) {
						std::wcout << L"Некорректное количество! На складе осталось " << countArr[id] << L" выбранного товара\n\n";
						Sleep(2000);
					}
					else {
						while (true) {
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> " << countArr[id] - count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
							Getline(choose);
							if (choose == L"1") {
								std::wcout << L"Товар успешно списан\n\n";
								countArr[id] -= count;
								currentStorageSize -= count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2") {
								std::wcout << L"Отмена списания " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else {
								Err();
							}
						}
					}
				}
			}
		}
	}
}
void ChangePrice(){
	std::wstring chooseId, choosePrice, choose;
	int id = 0;
	double price = 0;
	while (true) {
		system("cls");
		ShowStorage(3);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit") {
			std::wcout << L"Завершение операции списания товара\n\n";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId)) {
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1) {
				Err();
			}
			else {
				std::wcout << L"ВВедите количество новую цену: ";
				Getline(choosePrice);
				if (IsNumber(choosePrice)) {
					price = std::stod(choosePrice);
					if (price < 0 || price > maxPrice) {
						std::wcout << L"Некорректное цена! Максимально возможная цена: " << maxPrice << L" рублей\n\n";
						Sleep(2000);
					}
					else {
						while (true) {
							system("cls");
							std::wcout << nameArr[id] << L"\t" << priceArr[id] << L" -----> " << price << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
							Getline(choose);
							if (choose == L"1") {
								std::wcout << L"Успешное изменение цены\n\n";
								priceArr[id] = price;
								// :)
								Sleep(1500);
								break;
							}
							else if (choose == L"2") {
								std::wcout << L"Отмена изменения цены " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else {
								Err();
							}
						}
					}
				}
			}
		}
	}
}
void ChangeStorage(){
	std::wstring choose;
	while (true) {
		system("cls");
		std::wcout << L"1 - Добавление нового товара\n";
		std::wcout << L"2 - Изменить название товара\n";
		std::wcout << L"3 - Удаление\n";
		std::wcout << L"4 - Изменить лимиты склада\n";
		std::wcout << L"0 - Выход\n";
		std::wcout << L"Ввод: ";
		Getline(choose);
		if (choose == L"1") {
			AddNewProduct();
		}
		else if (choose == L"2") {
			ChangeProductName();
		}
		else if (choose == L"3") {
		
		}
		else if (choose == L"4") {
		
		}
		else if (choose == L"0") {
			return;
		}
		else {
			Err();
		}
	}
}
void AddNewProduct() {
	std::wstring chooseName, chooseCount, choosePrice, choose;
	size_t count = 0;
	double price = 0;
	while (true) {
		while (true) {
			system("cls");
			std::wcout << L"Введите название нового товара или \"exit\" для выхода: ";
			Getline(chooseName);
			if (chooseName == L"exit" || chooseName == L"Exit") {
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}
			if (chooseName.size() < 3 || chooseName.size() > 40) {
				std::wcout << L"Ошибка длины названия товара\nДопустимое значение от 3 до 40 символов\nКол-во символов в названии вашего нового товара: " << chooseName.size() << L"\n\n";
				Sleep(1600);
				continue;
			}
			if (IsNotSame(chooseName, nameArr, sizeSt)) {
				break;
			}
			else {
				std::wcout << L"Данный товар уже есть на складе\n\n";
			}
		}
		while (true) {
			system("cls");
			std::wcout << L"Заполненность склада: " << currentStorageSize << L" из " << maxStorageSize << L"\n\n";
			std::wcout << L"Введите количество нового товара или \"exit\" для выхода: ";
			Getline(chooseCount);
			if (chooseCount == L"exit" || chooseCount == L"Exit") {
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}
			if (IsNumber(chooseCount)) {
				count = std::stoull(chooseCount);
				if (count < 0 || count > maxStorageSize - currentStorageSize) {
					std::wcout << L"Некорректное количество! На складе осталось " << maxStorageSize - currentStorageSize << L" Свободных мест";
					Sleep(2000);
				}
				else {
				break;
				}
			}	

		}
		while (true) {
			system("cls");
			std::wcout << L"Введите стоимость нового товара или \"exit\" для выхода: ";
			Getline(choosePrice);
			if (choosePrice == L"exit" || choosePrice == L"Exit") {
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}
			if (IsNumber(choosePrice)) {
				price = std::stod(choosePrice);
				if (price < 0 || price > maxPrice) {
					std::wcout << L"Некорректное цена! Максимально возможная цена: " << maxPrice << L" рублей\n\n";
					Sleep(2000);
				}
				else {
					break;
				}
			}
		}
		while (true) {
			system("cls");
			std::wcout << L"Новый товар: " << chooseName << L"\n";
			std::wcout << L"Кол-во: " << count << L"\n";
			std::wcout << L"Цена: " << price << L"\n";
			std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
			Getline(choose);
			if (choose == L"1") {
				system("cls");
				std::wcout << L"Загрузка новых данных в базу данных";
				for (size_t i = 0; i < 3; i++)
				{
					Sleep(650);
					std::wcout << L".";
				}
				Sleep(300);
				system("cls");
				ArrPushBack(idArr, sizeSt);
				ArrPushBack(nameArr, sizeSt);
				ArrPushBack(countArr, sizeSt);
				ArrPushBack(priceArr, sizeSt);
				sizeSt++;
				idArr[sizeSt - 1] = sizeSt;
				nameArr[sizeSt - 1] = chooseName;
				countArr[sizeSt - 1] = count;
				priceArr[sizeSt - 1] = price;
				currentStorageSize += count;
				// :)
				std::wcout << L"\n\nНовый товар успешно добавлен\n\n";
				Sleep(1500);
				break;
			}
			else if (choose == L"2") {
				std::wcout << L"Отмена\n\n";
				Sleep(1400);
				break;
			}
			else {
				Err();
			}
		}
	}
}
void ChangeProductName(){
	std::wstring chooseName;
	while (true) {
		system("cls");
		ShowStorage(4); // остановились
		std::wcout << L"Введите название нового товара или \"exit\" для выхода: ";
		Getline(chooseName);
		if (chooseName == L"exit" || chooseName == L"Exit") {
			std::wcout << L"Отмена добавления нового товара\n\n";
			Sleep(1500);
			return;
		}
		if (chooseName.size() < 3 || chooseName.size() > 40) {
			std::wcout << L"Ошибка длины названия товара\nДопустимое значение от 3 до 40 символов\nКол-во символов в названии вашего нового товара: " << chooseName.size() << L"\n\n";
			Sleep(1600);
			continue;
		}
		if (IsNotSame(chooseName, nameArr, sizeSt)) {
			break;
		}
		else {
			std::wcout << L"Данный товар уже есть на складе\n\n";
		}
	}
}
