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

	cout << "Коэффициент заполнения: " << (double)tab.count() / tab.capacity() << endl << endl;
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
		cout << "1  - Размер таблицы" << endl;
		cout << "2  - Количество элементов" << endl;
		cout << "3  - Опрос на пустоту" << endl;
		cout << "4  - Очистка" << endl;
		cout << "5  - Поиск по ключу" << endl;
		cout << "6  - Вставка пары ключ-значение" << endl;
		cout << "7  - Удаление значения" << endl;
		cout << "8  - Запрос итератора begin()" << endl;
		cout << "9  - Запрос итератора end()" << endl;
		cout << "10 - Изменить значение" << endl;
		cout << "11 - Значение элемента на позиции итератора" << endl;
		cout << "12 - Переход к следующему значению итератора" << endl;
		cout << "13 - Хеш-таблица с цепочками коллизий" << endl;
		cout << "14 - Хеш-таблица с открытой адресацией" << endl;
		cout << "15 - Опрос формы представления" << endl;
		cout << "16 - Вывод структуры хеш-таблицы на экран" << endl;
		cout << "17 - Опрос числа проб, выполненных последней операцией" << endl;
		cout << "18 - Тестирование трудоемкости" << endl;
		cout << "0  - Выход" << endl;
		cout << "Ввод>> ";

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
				cout << "Ключ: ";
				cin >> key;
				cout << tab.get(key) << endl << endl;
				break;

			case 6:
				cout << "Ключ: ";
				cin >> key;
				cout << "Значение: ";
				cin >> val;
				tab.insert(key, val);
				cout << endl;
				break;

			case 7:
				cout << "Ключ: ";
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
					cout << "Хеш-таблица с цепочками коллизий" << endl << endl;
				else
					cout << "Хеш-таблица с открытой адресацией" << endl << endl;
				break;

			case 16:
				tab.print_struct();
				break;

			case 17:
				cout << tab.prob_count() << endl << endl;
				break;

			case 18:
				cout << "Количество ключей: ";
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
