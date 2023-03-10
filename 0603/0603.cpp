
#include"Book.h"
#include <iostream>
#include<Windows.h>
#include"FileBook.h"
using namespace std;
//Создайте класс Book
//Необходимо хранить данные : Автор, Название, Издательство,
//Год, Количество, страниц.
//Создать массив объектов.Вывести :
//	■ список книг заданного автора;
//■ список книг, выпущенных заданным издательством;
//■ список книг, выпущенных после заданного года.
//Используйте explicit конструктор и константные функции - члены
//(например, для отображения данных о книге и т.д.)
int main()
{
	int size = 2;
	setlocale(LC_ALL, "");
	Book b{"Пехов Алексей : "," //Хроники Сиалы//",(char*)" Издательсво  1",2000,498};
	Book b1{ "Громыко Ольга : "," //Верные враги//",(char*)" Издательство  2",2007,689 };
	Book* books = new Book[2]{b, b1};//массив обьектов
	//books->ShowAutorBook(cout,"Пехов :",2);
	//books->ShowBookPublisher(cout, "Издательсво 1",2);
	//books->ShowBookYear(cout, 1900);
	FileBook fb{ (char*)"text.txt" };
	fb.SaveBookFile(books, 2);
	Book* books2 = fb.LoadBookFile();


}

