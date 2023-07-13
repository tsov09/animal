#include <iostream>
#include "animal.cpp"

using namespace std;

int Vertebrate::constructor_call_count = 0;

void test() {

	cout << endl;
	Fish f_1(move(Fish("Shark")));
	cout << endl;
	f_1.get_type();
	f_1.print_data();
	cout << endl << endl;
	f_1 = move(Fish("Catfish"));
	cout << endl;
	f_1.get_type();
	f_1.print_data();
	cout << endl << endl;

	cout << endl;
	Reptile r_1(move(Reptile("Crocodile")));
	cout << endl;
	r_1.get_type();
	r_1.print_data();
	cout << endl << endl;
	r_1 = move(Reptile("Snake"));
	cout << endl;
	r_1.get_type();
	r_1.print_data();
	cout << endl << endl;

	cout << endl;
	Amphibian a_1(move(Amphibian("Frog")));
	cout << endl;
	a_1.get_type();
	a_1.print_data();
	cout << endl << endl;
	a_1 = move(Amphibian("Salamander"));
	cout << endl;
	a_1.get_type();
	a_1.print_data();
	cout << endl << endl;

	cout << endl;
	Mammal m_1(move (Mammal("Dolphin")));
	cout << endl;
	m_1.get_type();
	m_1.print_data();
	cout << endl << endl;
	m_1 = move(Mammal("Cat"));
	cout << endl;
	m_1.get_type();
	m_1.print_data();
	cout << endl << endl;

	Bird b_1(move(Bird("Parrot")));
	cout << endl;
	b_1.get_type();
	b_1.print_data();
	cout << endl << endl;
	b_1 = move(Bird("Owl"));
	cout << endl;
	b_1.get_type();
	b_1.print_data();



}

int main() {

	test();
	return 0;
}