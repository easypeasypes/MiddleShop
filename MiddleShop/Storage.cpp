#include "Storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
extern bool IsStorageCreated = false;
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
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(30) << nameArr[i] << L"\t\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		system("pause");
	}
}
void AddProduct(){
	std::wstring chooseId, chooseCount, choose;
	int id = 0;
	size_t count = 0;
	while (true) {

	}
}