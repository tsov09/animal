#include <iostream>
#include <string>
using namespace std;

#ifndef ANIMAL_H
#define ANIMAL_H

class Vertebrate {
	string body_temperature_dependency;
	string metabolism;
	string skin_covering;
	string type_of_breath;
	string moving_type;
	int heart_chamber_count;
	int characteristics_size = 7;
	string* characteristics;
	void set_common_characteristics();
public:
	Vertebrate();
	Vertebrate(const Vertebrate& obj);
	Vertebrate& operator = (const Vertebrate& obj);
	~Vertebrate();
	virtual void voice();
	virtual void move();
	void set_body_temperature_dependency(string dep);
	void set_metabolism(string met);
	void set_skin_covering(string skin_cover);

	void set_heart_chamber_count(int count);
	void set_type_of_breath(string breath);
	void set_moving_type(string move);

	string get_body_temperature_dependency();
	string get_metabolism();
	string get_skin_covering();
	string get_type_of_breath();
	string get_moving_type();

	int get_heart_chamber_count();

	void print_common_characteristics();
	void print_data();
};

class Cold_Blooded : public Vertebrate {
	string thermoregulation;
public:
	Cold_Blooded();
	Cold_Blooded(const Cold_Blooded& obj);
	Cold_Blooded& operator = (const Cold_Blooded& obj);
	~Cold_Blooded();
	void voice() override;
	void move() override;
	void set_thermoregulation(string t_reg);
	string get_thermoregulation();
	void print_cold_blooded_data();
};

class Fish : public Cold_Blooded {
	string type;
public:
	Fish();
	Fish(string t);
	Fish(const Fish& obj);
	Fish& operator = (const Fish& obj);
	~Fish();
	void voice() override;
	void set_type(string t);
	void move() final;
	void get_data();
	void get_type();
};

class Reptile : public Cold_Blooded {
	string type;
	string sound;
public:
	Reptile();
	Reptile(string t);
	Reptile(const Reptile& obj);
	Reptile& operator = (const Reptile& obj);
	~Reptile();
	void voice() override;
	void set_sound(string s);
	void move() override;
	void set_type(string t);
	void get_data();
	void get_type();
};


class Amphibian : public Cold_Blooded {
	string type;
	string sound = "not set";
public:
	Amphibian();
	Amphibian(string t);
	Amphibian(const Amphibian& obj);
	Amphibian& operator = (const Amphibian& obj);
	~Amphibian();
	void voice() override;
	void set_sound(string s);
	void move() override;
	void set_type(string t);
	void get_data();
	void get_type();
};


class Warm_Blooded : public Vertebrate {
public:
	Warm_Blooded();
	~Warm_Blooded();
	void print_warm();
	void voice() override;
	void move() override;
};

class Bird : public Warm_Blooded {
	string type;
	string sound;
public:
	Bird();
	Bird(string t);
	Bird(const Bird& obj);
	Bird& operator = (const Bird& obj);
	~Bird();
	void voice() override;
	void set_sound(string s);
	void move() override;
	void set_type(string t);
	void get_data();
	void get_type();
};

class Mammal : public Warm_Blooded {
	string type;
	string sound = "not set";
public:
	Mammal();
	Mammal(string t);
	Mammal(const Mammal& obj);
	Mammal& operator = (const Mammal& obj);
	~Mammal();
	void voice() override;
	void set_sound(string s);
	void move() override;
	void set_type(string t);
	void get_data();
	void get_type();
};

#endif
