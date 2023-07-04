#include <iostream>
#include "animal.cpp"

using namespace std;

int Vertebrate::constructor_call_count = 0;

void test() {


	//Fish m_1, m_2;
	//Reptile m_1, m_2;
	//Amphibian m_1, m_2;
	//Bird m_1, m_2;
	Mammal m_1, m_2;

	m_1.set_weight(5);
	m_2.set_weight(10);


	if (m_1 > m_2) {
		std::cout << "m_1 weight is greater" << std::endl;
	}
	else if (m_1 < m_2) {
		std::cout << "m_2 weight is greater" << std::endl;
	}
	else {
		std::cout << "m_1 and m_2 are equal" << std::endl;
	}

	m_1();

	std::cout << "Animal default constructor called " << Vertebrate::constructor_call_count++ << " times." << std::endl;
	
	
	/*Vertebrate* f_2 = new Fish("Snapper");
	Cold_Blooded* f_1 = new Fish("Snapper");
	Fish* f = new Fish("Snapper");*/
	
	/*f->get_type();
	f_2->voice();
	f_2->move();
	f_1->voice();
	f_1->move();
	f->voice();
	f->move();*/


	/*Vertebrate* r_2 = new Reptile("Snake");
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
	f = f_1 = f_2 = r = r_2 = r_3 = a = a_1 = a_2 = b = b_1 = b_2  m = m_1 = m_2 = nullptr;*/
}

int main() {

	test();
	return 0;
}