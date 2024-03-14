#pragma once
#include <fstream>
#include <string>
#include "COutputChannel.h"
#include <vector>
#include <stdlib.h>
#include "CSettingsChannel.h"
using namespace std;
class CGenerating_a_report_file
{
public:
	string str;
	CGenerating_a_report_file(vector < COutputChannel>& Struk_book, vector<CSettingsChannel>& book_Struk_input, string s)
	{
		ofstream file("data\\"+ s + ".txt");
		for (int i = 0; i < Struk_book.size(); i++)
		{
			if (Struk_book[i].cheak_msg && Struk_book[i].cheak_periodicity && Struk_book[i].cheak_id)
			{
				str += "���� " + to_string(Struk_book[i].nubmer_port) + " ������� ������� ID " + to_string(Struk_book[i].id) + "\n";
			}
			else if (Struk_book[i].id==-1)
			{
				str += "������! ���� " + to_string(Struk_book[i].nubmer_port) + " �� ������� id\n";
			}
			else
			{
				if (!Struk_book[i].cheak_msg)
				{
					str += "������! ���������� ��������� �� ���� " + to_string(Struk_book[i].nubmer_port) + " �� ��������� � ��������\n";
					str += "������� ��������� - ";
					for (int z = 0; z < book_Struk_input.size(); z++)
					{
						if (book_Struk_input[z].id == Struk_book[i].id)
						{

							for (int j = 0; j < 8; j++)
							{
								str += book_Struk_input[z].msg[j] + " ";
							}
							break;
						}
					}
					str += "; ���������� - ";
					for (int j = 0; j < 8; j++)
					{
						str += Struk_book[i].msg[j] + " ";
					}
					str += "\n";
				}
				if (!Struk_book[i].cheak_periodicity)
				{
					str += "������! ������� ��������� ��������� �� ����� " + to_string(Struk_book[i].nubmer_port) + " �� ��������� � ��������\n";
					for (int z = 0; z < book_Struk_input.size(); z++)
					{
						if (book_Struk_input[z].id == Struk_book[i].id)
						{
							str += "�������� ������ - " + to_string(book_Struk_input[z].periodicity) + " ���������� - " + to_string(Struk_book[i].periodicity) + "\n";
							break;
						}
					}
				}
			}
			for (int z = 0; z < 2; z++)
			{
				str += "\n";
			}
		}
		file << str;
		file.close();
	}
};