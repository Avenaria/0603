#include "FileBook.h"
#include"Book.h"
#include <iostream>
#include<Windows.h>
using namespace std;




void FileBook:: SaveBookFile(Book* books, int size) {
	if (!fopen_s(&file, path, APPEND)) {
		for (int i{ 0 }; i < size; i++) {
			fprintf_s(file, "%s", books[i]._nameBook, strlen(books[i]._nameBook)*sizeof(char));//%s передаём строку, дружим
			fprintf(file, "%s", books[i]._autor);//%s передаём строку, дружим
			fprintf(file, "%d", books[i]._pages);//%d передаём числа, дружим
			fprintf(file, "%s", books[i]._publisher);//%s передаём строку, дружим
			fprintf(file, "%d\n", books[i]._year);//%d передаём xbckf, дружим
			
		}
	}


};
Book* FileBook::LoadBookFile() {//считывание с файла 
	int count = 0;
	char* s = new char[100];
	if (!fopen_s(&file, path, READ)) {
		while (!feof(file)) {
			fgets(s,100,file);
			count++;
		}


	}
	fclose(file);
	Book* books = new Book[count];
	int i{ 0 };
	char publisher[25];
	if (!fopen_s(&file, path, READ)) {
		while (!feof(file)) {
			fscanf_s(file, "%s", books[i]._nameBook, sizeof(books[i]._nameBook));
			fscanf_s(file, "%s", books[i]._autor, sizeof(books[i]._nameBook));
			fscanf_s(file, "%s", books[i]._publisher, sizeof(books[i]._nameBook));// 
			fscanf_s(file, "%d", books[i]._pages, sizeof(books[i]._nameBook));
			fscanf_s(file, "%d", books[i]._year, sizeof(books[i]._nameBook));
			i++;

		}
	}
	fclose(file);
	return books;
};