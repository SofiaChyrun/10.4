// ChyrunSofialab10.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab_10_4.cpp
// < Чирун Софія >
// Лабораторна робота № 10.4
// Опрацювання рядків текстового файлу 
// Варіант 18

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

size_t MinLength(const string s)
{
	int k = 0;
	size_t len = 0,
		max;
	size_t start = 0,
		finish;
	string d;
	while ((start = s.find_first_of("abcdfeghijklmnopqrstuvwxyz", start)) != -1)
	{
		finish = s.find_first_not_of("abcdfeghijklmnopqrstuvwxyz", start + 1);
		if (finish == -1)
		   finish = s.length();
		len = finish - start;
		if (k == 0) 
		{
		   max = len;
		}
		k++;
		if (len > max) 
		{
		   max = len;
		}
		start = finish + 1;
	}
	return max;
}

void CreateTXT(char* fname) 
{
	ofstream fout(fname); 
	char ch; 
	string s; 
	do
	{
	   cin.get(); 
	   cin.sync(); 
	   cout << "enter line: "; getline(cin, s); 
	   fout << s << endl; 
	   cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintTXT(char* fname) 
{
	ifstream fin(fname); 
	string s; 
	int i = 0;
	while (getline(fin, s)) 
	{
		cout << s << endl; 
		i++;
		cout << "Length of max groups of words leters for line "<<i<<" : " << MinLength(s) << endl;
		cout << endl;
	}
	cout << endl;
}

void ProcessTXT1(char* fname)
{
	ifstream fin(fname); 
	string s;
	int k = 0; 
	while (getline(fin, s)) 
	{ 
		cout << s << endl;
	}
}

int ProcessTXT2(char* fname) 
{ 
	ifstream fin(fname); 
	string s; 
	int k = 0; 
	while (fin >> s) 
	{
		k++; 
		cout << k << ": " << s << endl;
	}
	return k;
}

int ProcessTXT3(char* fname, char* gname) 
{ 
	ifstream fin(fname); 
	ofstream g(gname); 
	char s[100]; 
	char* w; 
	int k = 0; 
	int kk = 0;
	string ss;
	size_t len = 0;
	int max = 0;
	size_t start = 0, finish;
	char *d;
	while (fin.getline(s, sizeof(s))) 
	{
		w = strtok(s, " .,:;!?-'"); 
		max = 0;
		len = 0;
		d = NULL;
		while (w != NULL) 
		{
			len = strlen(w);
			if (len > max)
			{
			   max = len;
			   d = w;
			   strcpy(d,w);
			}
			k++; 
			w = strtok(NULL, " .,:;!?-'"); 
		}
		g << d << "   " << max << endl;
	}
	ProcessTXT1(gname);
	return k;
}

int main()
{
	char fname[100]; 
	char gname[100]; 
	cout << "enter file name 1: "; cin >> fname;
	CreateTXT(fname); 
	PrintTXT(fname);
	cout << "k(word) = " << ProcessTXT2(fname) << endl;
	cout << "enter file name 2: "; cin >> gname;
	cout << "k(word) = " << ProcessTXT3(fname, gname) << endl;
	return 0;
}
