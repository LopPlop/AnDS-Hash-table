#pragma once

#include <iostream>

template <typename T>
class table_iterator;

template <typename T>
class hash_table
{
	friend class table_iterator<T>;

public:
	// Итераторы
	typedef table_iterator<T> iterator;
	typedef table_iterator<const T> const_iterator;

	iterator begin() { return iterator(this); }
	iterator end() { return iterator(0); }

	const_iterator begin() const { return const_iterator(this); }
	const_iterator end() const { return const_iterator(0); }

	hash_table() // конструктор
	{
		memset(_keys, 0, sizeof(_keys));
	}

	~hash_table() // деструктор
	{
	}

	unsigned capacity() // размер таблицы
	{
		return sizeof(_keys) / sizeof(double);
	}

	unsigned count() // количество элементов
	{
		return _count;
	}

	bool empty() // опрос на пустоту
	{
		return _count == 0;
	}

	void clear() // очистка
	{
		memset(_keys, 0, sizeof(_keys));
		_count = 0;
	}

	T get(double key) // поиск по ключу
	{
		if (key < 10000.0 || key > 15000.0)
		{
			throw "Exception (10000 < k < 15000)!";
		}

		unsigned i = hash(convol(key));

		while (_keys[i] != 0.0 && _keys[i] != key)
			i = hash_square(convol(key), i);

		if (_keys[i] == 0.0)
		{
			throw "Key doesn't exist!";
		}

		return _values[i];
	}

	void insert(double key, T value) // вставка пары ключ-значение
	{
		if (key < 10000.0 || key > 15000.0)
		{
			throw "Exception (10000 < k < 15000)! ";
		}

		unsigned i = hash(convol(key));
		prob = 0;

		while (++prob && _keys[i] != 0.0 && _keys[i] != key)
			i = hash_square(convol(key), i);

		if (_keys[i] == 0.0)
			++_count;

		_keys[i] = key;
		_values[i] = value;
	}

	void remove(double key) // удаление значения
	{
		if (key < 10000.0 || key > 15000.0)
		{
			throw "Exception (10000 < k < 15000)! ";
		}

		unsigned i = hash(convol(key));
		prob = 0;

		while (++prob && _keys[i] != 0.0 && _keys[i] != key)
			i = hash_square(convol(key), i);

		if (_keys[i] == 0.0)
			return;

		_keys[i] = 0.0;
		--_count;
	}

	void set_presentation_form(int f)
	{
		if (f <= 0 || f > 1)
			return;

		present_form = f;
	}

	int presentation_form()
	{
		return present_form;
	}

	void print_struct()
	{
		for (int i = 0; i < 10000; i++)
		{
			if (_keys[i] != 0)
			{
				std::cout << _keys[i] << ": " << _values[i] << std::endl;
			}
		}
	}

	int prob_count()
	{
		return prob;
	}

protected:
	double _keys[10000]; // массив с ключами
	T _values[10000]; // массив с данными

	unsigned _count = 0;
	int present_form = 0;
	int prob = 0;

	unsigned convol(double k) // свертка ключа
	{
		return (unsigned)(k - 10000.0) * 2 + 10000;
	}

	unsigned hash(int k_convol) // хэширование
	{
		return k_convol % 9973;
	}

	unsigned hash_square(unsigned k_convol, unsigned h) // квадратичное хэширование
	{
		return (k_convol % 9973 + 7 * h + 3 * h * h) % 9973;
	}
};

// Шаблонный класс прямой итератор
template <typename T>
class table_iterator : public std::iterator<std::input_iterator_tag, T>
{
	friend class hash_table<T>;

public:
	table_iterator(const table_iterator& it) : _table(it._table), _index(it._index) {}

	bool operator!=(table_iterator const& other) const { return _table != other._table || _index != other._index; }
	bool operator==(table_iterator const& other) const { return _table == other._table && _index == other._index; }

	table_iterator& operator++()
	{
		++_index;

		if (_index != (unsigned)-1)
			while (_index < _table->capacity() && _table->_keys[_index] == 0.0)
				++_index;

		if (_index >= _table->capacity())
			_index = (unsigned)-1;

		return *this;
	}

	T& operator *()
	{
		if (_index == (unsigned)-1)
			throw "Exception";

		return _table->_values[_index];
	}

private:
	table_iterator(typename hash_table<T>* table) : _table(table), _index((unsigned)-1)
	{
		if (table == 0)
			return;

		_index = 0;

		while (_index < table->capacity() && table->_keys[_index] == 0.0)
			++_index;

		if (_index >= table->capacity())
			_index = (unsigned)-1;
	}

	typename hash_table<T>* _table;
	unsigned _index;
};
