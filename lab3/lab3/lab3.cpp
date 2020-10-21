#include <iostream>
#include <list>
using namespace std;

class String
{
private:
	list<char> word;
public:
	String() { }
	String(string wor) {
		for (int i = 0; i < wor.size(); i++)
		{
			word.push_back(wor[i]);
		}
	}
	String(const String& ob) {
		for (char i : ob.word)
		{
			word.push_back(i);
		}
		cout << "Отработал копирующий конструкор";
	}

	void AddElem(string inpu) {
		for (int i = 0; i < inpu.size(); i++)
		{
			word.push_back(inpu[i]);
		}
	}

	void Print() {
		string output = "";
		for (char i : word) {
			output += i;
		}
		cout << output;
	}

	static String ConcatStrings(String st1, String st2) {
		string rez = "";
		for (char i : st1.word) {
			rez += i;
		}
		for (char i : st2.word) {
			rez += i;
		}
		String st3(rez);
		return st3;
	}
	void operator++() {
		word.push_front(' ');
	}

	void operator++(int) {
		word.push_back(' ');
	}
	~String()
	{
		word.clear();
	}
};

int main()
{
	setlocale(LC_ALL, "");
    cout << "Введите строку:" << endl;
	string input;
	cin >> input;
	cout << "\n\n" << endl;

	String rez(input);
	cout << "Добавление 2 пробелов и перед строкой, и после строки" << endl;
	rez++;
	rez++;
	++rez;
	++rez;
	rez.Print();
	cout << "\n\n" << endl;
	cout << "Введите строку для конкатенации" << endl;
	cin >> input;
	cout << "\n\n" << endl;

	String buf(input);
	String rezu = String::ConcatStrings(rez, buf);
	cout << "\n\n" << endl;
	rezu.Print();
	cout << "\n\n" << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
