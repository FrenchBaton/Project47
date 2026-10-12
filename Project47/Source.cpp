#include<iostream>
#include<map>
#include<string>
using namespace std;

typedef pair<string, string> myp;
typedef pair<string, int> mypi;
class Dictionary
{
	map<string, string> dict;
public:
	Dictionary() {}
	void Add(string w1, string w2) {
		dict.insert(myp(w1, w2));
	}

	void Print() {
		for (auto ptr = dict.begin(); ptr != dict.end(); ptr++) {
			cout << "Word: " << ptr->first << "\nTranslate: " << ptr->second << "\n\n";
		}
		cout << endl;
	}

	void Find(string w) {
		auto ptr = dict.find(w);
		if (ptr != dict.end()) {
			cout << "Word: " << ptr->first << "\nTranslate: " << ptr->second << "\n\n";
		}
		else {
			cout << "Not found\n";
		}
	}

	void Delete(string w) {
		auto ptr = dict.find(w);
		if (ptr != dict.end()) {
			dict.erase(ptr->first);
		}
		else {
			cout << "Not found\n";
		}
	}
};

class PhoneBook
{
	map<string, string> book;
public:
	PhoneBook() {}
	void Add(string name, string num) {
		book.insert(myp(name, num));
	}

	void Print() {
		for (auto ptr = book.begin(); ptr != book.end(); ptr++) {
			cout << "Name: " << ptr->first << "\nNumber: " << ptr->second << "\n\n";
		}
		cout << endl;
	}
	void Find(string name) {
		auto ptr = book.find(name);
		if (ptr != book.end()) {
			cout << "Name: " << ptr->first << "\nNumber: " << ptr->second << "\n\n";
		}
		else {
			cout << "Not found\n";
		}
	}
};

class Student
{
	string name;
	double middleScore;
public:
	Student() {
		name = "NAME";
		middleScore = 0;
	}

	Student(string n, double ms) {
		name = n;
		middleScore = ms;
	}

	double GetScore() { return middleScore; }

	void Print() {
		cout << "Name: " << name << "\nScore: " << middleScore << endl;
		cout << endl;
	}
};

typedef pair<int, Student> myps;

int main() {
	Dictionary d;
	d.Add("ads", "dfff");
	d.Add("as", "fff");
	d.Add("ask", "ffggf");

	d.Print();
	d.Delete("ask");
	d.Print();

	map<int, Student> std;

	std.insert(myps(0, Student("ST1", 3)));
	std.insert(myps(1, Student("ST2", 5)));
	std.insert(myps(2, Student("ST3", 9)));

	for (auto ptr = std.begin(); ptr != std.end(); ptr++) {
		ptr->second.Print();
	}
	cout << endl;

	PhoneBook pb;
	pb.Add("N1", "+123 000 0000");
	pb.Add("N2", "+123 123 0000");
	pb.Add("N3", "+123 000 1234");

	pb.Print();
	pb.Find("N2");

	return 0;
}