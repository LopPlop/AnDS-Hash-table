#include <iostream>
#include <locale>

#include "hash_table.h"

using namespace std;

void test_rand(int n)
{
	hash_table<int> tab;

	for (int i = 0; i < n; i++)
	{
		tab.insert(rand() % 5000 + 10000, 1);
	}

	cout << "����������� ����������: " << (double)tab.count() / tab.capacity() << endl << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	hash_table<int> tab;
	hash_table<int>::iterator it = tab.begin();

	double key;
	int k, val;

	do
	{
		cout << "1  - ������ �������" << endl;
		cout << "2  - ���������� ���������" << endl;
		cout << "3  - ����� �� �������" << endl;
		cout << "4  - �������" << endl;
		cout << "5  - ����� �� �����" << endl;
		cout << "6  - ������� ���� ����-��������" << endl;
		cout << "7  - �������� ��������" << endl;
		cout << "8  - ������ ��������� begin()" << endl;
		cout << "9  - ������ ��������� end()" << endl;
		cout << "10 - �������� ��������" << endl;
		cout << "11 - �������� �������� �� ������� ���������" << endl;
		cout << "12 - ������� � ���������� �������� ���������" << endl;
		cout << "13 - ���-������� � ��������� ��������" << endl;
		cout << "14 - ���-������� � �������� ����������" << endl;
		cout << "15 - ����� ����� �������������" << endl;
		cout << "16 - ����� ��������� ���-������� �� �����" << endl;
		cout << "17 - ����� ����� ����, ����������� ��������� ���������" << endl;
		cout << "18 - ������������ ������������" << endl;
		cout << "0  - �����" << endl;
		cout << "����>> ";

		cin >> k;

		try
		{
			switch (k)
			{
			case 1:
				cout << tab.capacity() << endl << endl;
				break;

			case 2:
				cout << tab.count() << endl << endl;
				break;

			case 3:
				cout << tab.empty() << endl;
				break;

			case 4:
				tab.clear();
				cout << endl;
				break;

			case 5:
				cout << "����: ";
				cin >> key;
				cout << tab.get(key) << endl << endl;
				break;

			case 6:
				cout << "����: ";
				cin >> key;
				cout << "��������: ";
				cin >> val;
				tab.insert(key, val);
				cout << endl;
				break;

			case 7:
				cout << "����: ";
				cin >> key;
				tab.remove(key);
				cout << endl;
				break;

			case 8:
				it = tab.begin();
				cout << endl;
				break;

			case 9:
				it = tab.end();
				cout << endl;
				break;

			case 11:
				if (it != tab.end())
					cout << *it << endl << endl;
				else
					cout << "Exception" << endl << endl;
				break;

			case 12:
				++it;
				cout << endl;
				break;

			case 13:
				tab.set_presentation_form(0);
				break;

			case 14:
				tab.set_presentation_form(1);
				break;

			case 15:
				if (tab.presentation_form() == 0)
					cout << "���-������� � ��������� ��������" << endl << endl;
				else
					cout << "���-������� � �������� ����������" << endl << endl;
				break;

			case 16:
				tab.print_struct();
				break;

			case 17:
				cout << tab.prob_count() << endl << endl;
				break;

			case 18:
				cout << "���������� ������: ";
				cin >> val;
				test_rand(val);
				break;

			case 0:
				return 0;
			}
		}
		catch (const char* const e)
		{
			cout << e << endl << endl;
		}

	} while (k != 0);

	return 0;
}
