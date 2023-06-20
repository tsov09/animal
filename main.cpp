#include <iostream>
#include "animal.cpp"

using namespace std;

void test() {
	cout << endl;

	Fish* f = new Fish("Snapper");
	//f->get_data();
	f->get_type();
	f->voice();
	f->move();
	cout << endl;


	/*Fish* f_1 = f;
	f_1->get_data();
	cout << endl;
	f_1->voice();
	cout << endl;


	Fish* f_2 = new Fish("Shark");
	f_2->get_data();
	cout << endl;
	f_2->voice();
	cout << endl;

	f_2 = f;
	f_2->get_data();
	cout << endl;
	f->voice();
	cout << endl;*/

	Reptile* r = new Reptile("Alligator");
	//r->get_data();
	//cout << endl;
	r->set_sound("bellow");
	r->get_type();
	r->voice();
	r->move();

	cout << endl;

	/*Reptile* r_1 = new Reptile("Snake");
	r_1->get_data();
	cout << endl;
	r_1->set_sound("hiss");
	r_1->voice();
	cout << endl;

	Reptile* r_2 = r_1;
	r_2->get_data();
	cout << endl;
	r_2->voice();
	cout << endl;

	r_2 = r;
	r_2->get_data();
	cout << endl;
	r_2->voice();
	cout << endl;*/


	Amphibian* a = new Amphibian("Frog");
	//a->get_data();
	//cout << endl;
	a->set_sound("ribbit");
	a->get_type();
	a->voice();
	a->move();
	cout << endl;

	/*Amphibian* a_1 = new Amphibian("Salamander");
	a_1->get_data();
	cout << endl;
	a_1->voice();
	cout << endl;

	Amphibian* a_2 = a_1;
	a_2->get_data();
	cout << endl;
	a_2->voice();
	cout << endl;

	a_2 = a;
	a_2->get_data();
	cout << endl;
	a_2->voice();
	cout << endl;*/

	Bird* b = new Bird("Parrot");
	//b->get_data();
	//cout << endl;
	b->set_sound("caw");
	b->get_type();
	b->voice();
	b->move();
	cout << endl;

	/*Bird* b_1 = new Bird("Owl");
	b_1->get_data();
	cout << endl;
	b_1->set_sound("hoot");
	b_1->voice();
	cout << endl;


	Bird* b_2 = b_1;
	b_2->get_data();
	cout << endl;
	b_2->voice();
	cout << endl;

	b_2 = b;
	b_2->get_data();
	cout << endl;
	b_2->voice();
	cout << endl;*/

	Mammal* m = new Mammal("Dog");
	//m->get_data();
	//cout << endl;
	m->set_sound("woof");
	m->get_type();
	m->voice();
	m->move();
	cout << endl;

	/*Mammal* m_1 = new Mammal("Cat");
	m_1->get_data();
	cout << endl;
	m_1->set_sound("meow");
	m_1->voice();
	cout << endl;

	Mammal* m_2 = m;
	m_2->get_data();
	cout << endl;
	m_2->voice();
	cout << endl;

	m_2 = m_1;
	m_2->get_data();
	cout << endl;
	m_2->voice();
	cout << endl;*/

}

int main() {
	test();
	return 0;
}