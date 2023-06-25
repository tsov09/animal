#include <iostream>
#include "animal.cpp"

using namespace std;

void test() {
	cout << endl;

	Vertebrate* f_2 = new Fish("Snapper");
	Cold_Blooded* f_1 = new Fish("Snapper");
	Fish* f = new Fish("Snapper");
	f->get_type();
	f_2->voice();
	f_2->move();
	f_1->voice();
	f_1->move();
	f->voice();
	f->move();
	cout << endl;

	Vertebrate* r_2 = new Reptile("Snake");
	Cold_Blooded* r_3 = new Reptile("Snake");
	Reptile* r = new Reptile("Snake");
	r->set_sound("bellow");
	r->get_type();
	r->voice();
	r->move();
	r_3->voice();
	r_3->move();
	r_2->voice();
	r_2->move();

	cout << endl;


	Vertebrate* a_1 = new Amphibian("frog");
	Cold_Blooded* a_2 = new Amphibian("frog");
	Amphibian* a = new Amphibian("Frog");
	a->set_sound("ribbit");
	a->get_type();
	a->voice();
	a->move();
	a_1->voice();
	a_1->move();
	a_2->voice();
	a_2->move();

	cout << endl;


	Vertebrate* b_1 = new Bird("Parrot");
	Warm_Blooded* b_2 = new Bird("Parrot");
	Bird* b = new Bird("Parrot");
	b->set_sound("caw");
	b->get_type();
	b->voice();
	b->move();
	b_1->voice();
	b_1->move();
	b_2->voice();
	b_2->move();

	cout << endl;


	Vertebrate* m_1 = new Mammal("Dog");
	Warm_Blooded* m_2 = new Mammal("Dog");
	Mammal* m = new Mammal("Dog");
	m->set_sound("woof");
	m->get_type();
	m->voice();
	m_1->move();
	m_1->voice();
	m_2->move();m->voice();
	m_2->move();


	delete f, f_1, f_2, r, r_2, r_3, a, a_1, a_2, b, b_1, b_2, m, m_1, m_2;
}

int main() {
	test();
	return 0;
}