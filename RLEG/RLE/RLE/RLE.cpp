#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void Archivate();
void UnArchivate();
void Arch();

int main()
{
	Arch();
	//UnArchivate();


	return 0;
}

void Archivate()
{
	vector<int> kount; // ������������ ������ �����, ������� ����������� ����������� ����� �����-�� ����������� ������ � ������� ������
	string inp; // ���-�� ��������� ��� ���� ������
	string line; // ����������, ������, ������� ����������� ��� ������ �����
	ifstream fin;
	ofstream fout;

	fin.open("input.txt");
	fout.open("output.txt");

	if (fin.is_open() && fout.is_open()) // �������� ����� ��� ���
	{
		int m = 0; // ����������, ������� �������� �� ������ ������ �������� ������� kount

		while (getline(fin, line)) // ������ �����
		{
			int count = 1;

			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == line[i + 1])
				{
					while (line[i] == line[i + 1])
					{

						line.erase(i, 1);
						count++;

					}
				}
				kount.push_back(count);
				count = 1;
			}

			for (int i = 0; i < line.length(); i++)
			{
				fout << char(kount[m++]) << line[i];
			}

			fout << endl;
		}
	}
	fin.close();
	fout.close();

}

void Arch()
{
	vector<char> kounter; // ������ ��� �������� ���� ��������
	string line; // ���������� ������ ��� ���������� ����� �� �������
	ifstream fin; // ������
	ofstream fout; // ������
	bool index = 0; // ����

	fin.open("input.txt");
	fout.open("output.txt",fstream::binary);

	if (fin.is_open() && fout.is_open())
	{
		int m = 0;

		while (getline(fin, line))
		{

			int count = 1;

			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == line[i + 1])
				{
					index = 1;

					while (line[i] == line[i + 1])
					{
						line.erase(i, 1);
						count++;
					}

					fout << count << line[i];

					count = 1;
				}
				else if (index == 1)
				{
					fout << line[i];
				}

			}

			fout << endl;
		}
	}

	fin.close();
	fout.close();
}





void UnArchivate()
{
	ofstream fout;//��������
	ifstream fin;//�������
	fin.open("output.txt");//�������� ��������
	fout.open("input1.txt");//�������� ���������

	if (fout.is_open() && fin.is_open())//���� ����� ���������
	{
		cout << "���� ������ ��� ������������\n";
		bool is_for_one = 0;//����� ��������
		char cur;
		unsigned char counter = 0;
		while (fin.get(cur))//��������� ������� �������
		{
			if (counter == 0 && !is_for_one)//���� �� �������� ����� ����������� � ������ ������� �� ����������� ������ ������� ������ �������� ������ ���� ������������ ������
			{
				if (cur == 0)
				{
					is_for_one = 1;
				}
				else
				{
					counter = cur;
				}

			}
			else if (is_for_one)//���� ������� ����� ������ �����������
			{
				if (cur == 0)//���� ������� ������ ����� ��������������� ����� ���� ����������� �����
				{
					is_for_one = 0;
				}
				else//� ������ �� ������, ������ ������� �������
				{
					fout << cur;
				}
			}
			else //���� ���� �������
			{
				while (counter > 0)//���� ������� �� ����� 0 ������ �������� ������� � ����
				{
					fout << cur;
					counter--;
				}
			}

		}
	}
	else//���� �� ��������
	{
		cout << "Cann't open file" << endl;
	}
	fin.close();
	fout.close();
}