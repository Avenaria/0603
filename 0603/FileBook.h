#pragma once
#include"Book.h"
#include <iostream>
#include<Windows.h>
using namespace std;


#define READ "r"
#define WRITE "W"
#define APPEND "a"

class FileBook
{
	FILE* file;
	 char* path;
	 friend class Book;
	
	
public:
	FileBook(char* p) :path{ new char[100] } {
		strcpy_s(path, 100, p);
		
	
	}
	void SaveBookFile(Book* books,int size);
	Book* LoadBookFile();

};

