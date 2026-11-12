#include "Authorization.hpp"
#include "Storage.hpp"
#include <io.h>
#include <fcntl.h>
int main() {
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	Start();
	delete[]userId;
	delete[]loginArr;
	delete[]passArr;
	delete[]statusArr;

	if (!IsStorageCreated) {
	delete[]nameArr;
	delete[]idArr;
	delete[]countArr;
	delete[]priceArr;
	}
	return 0;
}
/*
Систему авторизации:	логин пароль, вход
Продажи:	выбор товара, оплата, нал/безнал, чек, галя - отмена
Склад:	показать товары, пополнение, списание, изменение цены 
Пользователи:	супер администратор, администратор, пользователь
Служебные функции:	всяка для работы программы
*/
