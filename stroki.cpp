#include <iostream>
#include <string>
#include <random>

using namespace std;

string del_sumbol(string word, bool flag);


string del_sumbol(string word, bool flag) {
	string result;
	for (char c : word) {
		char b = tolower(c);
		bool condition = b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u';
		if (flag ? condition : !condition)
			continue;
		result += c;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int choice;
	string word;
	cout << "ОПЕРАЦИИ СО СТРОКАМИ" << endl;
	cout << "1. reverse" << endl;
	cout << "2. removeVowels" << endl;
	cout << "3. removeConsonants" << endl;
	cout << "4. shuffle" << endl;

	cout << "\nВведите операцию: " << endl;
	cin >> choice;
	cout << "\nВведите слово: " << endl;
	cin >> word;

	switch (choice)
	{
	case 1:
		reverse(word.begin(), word.end());
		cout << word;
		break;
	case 2:
		cout << del_sumbol(word, true);
		break;
	case 3:
		cout << del_sumbol(word, false);
		break;
	case 4:
		random_device rd;
		mt19937 g(rd());
		shuffle(word.begin(), word.end(), g);
		cout << word << endl;
		break;
	}
}