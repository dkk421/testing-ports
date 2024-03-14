#pragma once
#include <iostream>
#include <vector>
#include "COutputChannel.h"
#include "CSettingsChannel.h"
using namespace std;
class �Short_check
{
public:
	�Short_check(vector<COutputChannel>& book2, vector<CSettingsChannel>& book)
	{
		char str[8]="";
		for (int i = 0; i < book.size(); i++)
		{
			if (!book[i].type_id)
			{
				for (int j = 0; j < book2.size(); j++)
				{
					if (book[i].id == book2[j].id && book2[j].cheak_id)
					{
						for (int z = 0; z < 8; z++)
						{
							if (book[i].msg[z] != book2[j].msg[z])
							{
								book2[j].cheak_msg = false;
								printf("������! ���������� ��������� �� ��������� � ��������. �������� ��������� - %u %u %u %u %u %u %u %u, ���������� ��������� - %u %u %u %u %u %u %u %u\n", book[i].msg[0],
									book[i].msg[1], book[i].msg[2], book[i].msg[3], book[i].msg[4], book[i].msg[5], book[i].msg[6], book[i].msg[7], book2[j].msg[0],
									book2[j].msg[1], book2[j].msg[2], book2[j].msg[3], book2[j].msg[4], book2[j].msg[5], book2[j].msg[6], book2[j].msg[7]);
								break;
							}
							else
							{
								book2[j].cheak_msg = true;
							}
						}
						if (book2[j].periodicity<int(book[i].periodicity * 1.1) && book2[j].periodicity>int(book[i].periodicity * 0.9))
						{
							book2[j].cheak_periodicity = true;
						}
						else
						{
							printf("������ ��� ��������� id- %i, �� ��������� �����. �������� �������� - %i, ���������� - %i\n", book[i].id, book[i].periodicity, book2[j].periodicity);
							book2[j].cheak_periodicity = false;
						}
						break;
					}
					else if (book[i].id == book2[j].id && !book2[j].cheak_id && !book[i].type_id)
					{
						printf("������! ���� %d ������� ��������� c ����� %d. ���������� id - %d\n", book2[j].nubmer_port, book[i].nubmer_port, book[i].id);
					}
					else if (book2[j].id == -1)
					{
						printf("������! ���� - %d �� ������� id\n", book[i].nubmer_port);
					}
				}
			}
		}
	}
};

