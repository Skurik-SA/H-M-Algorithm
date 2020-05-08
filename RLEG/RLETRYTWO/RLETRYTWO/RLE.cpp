#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>

using namespace std;

void Archivate();
void Unarchivate();

int main()
{
	Archivate();
	Unarchivate();
}

void Archivate()
{
	string line;
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	unsigned char counter = 1; // —чЄтчик ебаных чисел нахуй

	
	if (fin.is_open() && fout.is_open())
	{
		while (getline(fin, line))
		{
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == line[i + 1])
				{
					while (line[i] == line[i + 1])
					{
						line.erase(i, 1);
						counter++;
					}
					fout << counter << line[i];
					counter = 1;
				}
				else
				{
					fout << counter << line[i];
				}

			}
				fout << endl;
		}
	}
}

void Unarchivate()
{
	string line;
	ifstream fin;
	ofstream fout;
	fin.open("output.txt");
	fout.open("input1.txt");
	unsigned char chislo;
	char symbol;


	if (fin.is_open() && fout.is_open())
	{
		while (getline(fin, line))
		{
			for (int i = 0; i < line.length(); i += 2)
			{
				chislo = line[i];
				symbol = line[i + 1];

				for (int j = 0; j < chislo; j++)
				{
					fout << symbol;
				}
			}
			fout << endl;
		}
	}

}
