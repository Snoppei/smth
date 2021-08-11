#include "Header.h"

using namespace std;

class Human;

class ArrayClass
{
public:

	int& operator[](int index)
	{
		return arr[index];
	};

private:
	int arr[5]{ 12, 44, 43, 65, 12 };
};

class Cord
{
private:
	int x;
	int y;
public:

	bool operator != (const Cord& other)
	{
		return this->x != x || this->y != y;
	}

	bool operator == (const Cord& other)
	{
		return this->x == other.x && this->y == other.y;
	}

	Cord& operator ++()
	{
		this->x++;

		this->y += 1;

		return *this;
	}

	Cord& operator ++(int value)
	{
		Cord temp(*this);

		this->x++;
		this->y++;

		return temp;
	}

	Cord& operator = (const Cord& other)
	{
		this->x = other.x;
		this->y = other.y;

		return *this;
	};

	Cord(int ValueX, int ValueY)
	{
		x = ValueX;
		y = ValueY;
	}

	void Print()
	{
		cout << "X = " << x << "\tY = " << y << endl << endl;
	}
};

class CoffeeGrinder
{
private:
	bool voltageCheck()
	{
		return true;
	}
public:

	void start()
	{
		if (voltageCheck())
		{
			cout << "Молит" << endl;
		}
		else
		{
			cout << "Не молит" << endl;
		}
	}

};

class DynamicArray
{
private:
	int* arr;
	int size;
public:

	DynamicArray()
	{
		this->size = 10;
		arr = new int[size];
	};


	DynamicArray(int a)
	{
		this->size = a;
		arr = new int[size];
	};


	void FillArray()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = i;
		}
	};

	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
	};

	~DynamicArray()
	{
		delete[] arr;
		arr = nullptr;

		cout << "Деструктор вызван." << endl;
	};
};

class MyClass
{
private:
	int* data;
	int Size;
public:	
	
	MyClass(int size)
	{
		this->data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}
		cout << "Конструктор вызван " << this << endl;
	};

	MyClass(const MyClass &other)
	{
		this->Size = other.Size;
		//this->data = other.data; ЖОПА

		this->data = new int[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout << "Конструктор копирования вызван " << this << endl;
	};

	~MyClass()
	{
		delete[] data;
		cout << "Деструктор вызван " << this << endl;
	};
};

class Human
{
public:

	Human(string Name, int Age, int Weight)
	{
		this->name = Name;
		this->age = Age;
		this->weight = Weight;
	};

	void TakeApple()
	{
		cout << "Человек взял яблоко." << endl;
	}

	void SetName(string Name)
	{
		this->name = Name;
	}

	void SetAge(int Age)
	{
		this->age = Age;
	}

	void SetWeight(int Weight)
	{
		this->weight = Weight;
	}

	void Print();

	friend void foo(Human object);

private:
	int age;
	int weight;
	string name;
};

void foo(Human object)
{
	object.Print();
}

int main()
{
	Human firstHuman("Pavel", 18, 70);

	foo(firstHuman);

	cout << "======================================================" << endl;
	
	firstHuman.SetName("Oleg");
	firstHuman.SetAge(30);
	firstHuman.SetWeight(90);

	foo(firstHuman);

}

void Human::Print()
{
	cout << this->name << endl;
	cout << this->age << endl;
	cout << this->weight << endl;
}
