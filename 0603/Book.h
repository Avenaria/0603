#pragma once
#include"Book.h"
#include <iostream>
#include<Windows.h>
using namespace std;

class Book
{
	char _autor[25];
	char _nameBook[25];
	char* _publisher;
	int _year;
	int _pages;
	
public:
	Book(const char* a, const char* n, char* p, int y, int page) {
		_year = y;
		_publisher = { (p)? new char[strlen(p) + 1]: new char[25]};
		_pages = page;
		strcpy_s(_autor, a);
		strcpy_s(_nameBook, n);
		if(p)strcpy_s(_publisher, strlen(p) + 1, p);
		
	}

	Book():Book("\0","\0",nullptr, 0,0) {
	}
	 ostream& ShowAutorBook(ostream& in,const char* autor, int size) {
		
		 for (int i{ 0 }; i <size; i++) {
			 if(!strcmp(this[i]._autor,autor))

			 in << " Имя автора  :" << this[i]._autor << "Книга : " << this[i]._nameBook;
			 
		 }
		 return in;


	 }

	 ostream& ShowBookPublisher(ostream& in, const char* publisher, int size) {
		 
		 for (int i{ 0 }; i < size; i++) {

			 if (strcmp(this[i]._publisher, publisher))

				 in << "Издательство  :" << this[i]._publisher << "Книга : " << this[i]._nameBook;

		 }
		 return in;

	 }
	 ostream& ShowBookYear(ostream& in, int yar) {

		 for (int i{ 0 }; i < sizeof(this); i++) {
			 if (this->_year > yar) {
				 in << "После данного года выпущены книги  :" << this[i]._nameBook;
			 }
			 else  in << "таких книг нет  ";
			 
		 }
		 return in;
	 }
};

