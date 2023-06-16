#include <iostream>
#include <string>
using namespace std;

void lower_case(string* str) {
	char ch;
	for (int i = 0; i < (*str).size(); i++) {
		if ((*str)[i] >= 64 && (*str)[i] <= 90) {
			ch = (*str)[i] + 32;
			(*str)[i] = ch;
		}
	}
}

bool is_valid_string(string str, int size = 20) {
	bool is_valid = true;
	for (int i = 0; i < size; i++) {
		if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122 || str[i] == 32) {
			return is_valid;
		}
	}
	return is_valid;
}

class Vertebrate {
	string body_temperature_dependency;
	string metabolism;
	string skin_covering;
	string type_of_breath;
	string moving_type;
	int heart_chamber_count;

public:
	void set_body_temperature_dependency(string dep) {
		lower_case(&dep);
		if (dep == "dependent" || dep == "independent") {
			this->body_temperature_dependency = dep;
		}
	}
	void set_metabolism(string met) {
		lower_case(&met);
		if (met == "low" || met == "high") {
			this->metabolism = met;
		}
	}
	void set_skin_covering(string skin_cover) {
		lower_case(&skin_cover);
		if (skin_cover == "fur" || skin_cover == "feathers" || skin_cover == "dry scales" || skin_cover == "wet scales" || skin_cover == "moist") {
			this->skin_covering = skin_cover;
		}
	}

	void set_heart_chamber_count(int count) {
		if (count >= 2 && count <= 4) {
			this->heart_chamber_count = count;
		}
	}
	void set_type_of_breath(string breath) {
		lower_case(&breath);
		if (breath == "only lungs" || breath == "lungs and skin" || breath == "lungs and sacs" || breath == "gills") {
			this->type_of_breath = breath;
		}
	}

	void set_moving_type(string move) {
		lower_case(& move);
		if (move == "walking" || move == "walking and flying" || move == "walking and crawling" || move == "swimming" || move == "walking and swimming") {
			this->moving_type = move;
		}
	}

	string get_body_temperature_dependency() {
		return this->body_temperature_dependency;
	}
	string get_metabolism() {
		return this->metabolism;
	}
	string get_skin_covering() {
		return this->skin_covering;
	}

	string get_type_of_breath() {
		return this->type_of_breath;
	}

	string get_moving_type() {
		return this->moving_type;
	}

	int get_heart_chamber_count() {
		return this->heart_chamber_count;
	}
	void print_data() {
		cout << "Body temperature: " << this->body_temperature_dependency << ";" << endl;
		cout << "Metabolysm level: " << this->metabolism << ";" << endl;
		cout << "Skin covering type: " << this->skin_covering << ";" << endl;
		cout << "Type of breath: " << this->type_of_breath << ";" << endl;
		cout << "Type of moving: " << this->moving_type << ";" << endl;
		cout << "Heart type: " << this->heart_chamber_count << " chambered;" << endl;
	}
};

class Cold_Blooded : public Vertebrate {
	string thermoregulation;

public:
	Cold_Blooded() {
		this->set_body_temperature_dependency("Dependent");
		this->set_metabolism("Low");
	}
	void set_thermoregulation(string t_reg) {
		lower_case(&t_reg);
		if (t_reg == "poikilothermy" || t_reg == "ectothermy" || t_reg == "heterothermy") {
			this->thermoregulation = t_reg;
		}
	}
	string get_thermoregulation() {
		return this->thermoregulation;
	}

	void print_cold_blooded_data() {
		cout << this->thermoregulation << endl;
		cout << get_body_temperature_dependency() << endl;
		cout << get_skin_covering() << endl; 
	}
	
};

class Fish : public Cold_Blooded {
	string type;
public:
	Fish() {
		this->set_skin_covering("wet scales");
		this->set_type_of_breath("gills");
		this->set_moving_type("swimming");
		this->set_heart_chamber_count(2);
	}
	Fish(string t) {
		this->set_type(t);
		this->set_skin_covering("wet scales");
		this->set_type_of_breath("gills");
		this->set_moving_type("swimming");
		this->set_heart_chamber_count(2);

	}
	void set_type(string t) {
		if (is_valid_string(t)) {
			this->type = t;
		}
	}

	void get_data() {
		cout << "Type: " << this->type << " fish;" << endl;
		print_data();
	}
};

class Reptile : public Cold_Blooded {
	string type;

public:
	Reptile() {
		this->set_skin_covering("dry scales");
		this->set_type_of_breath("only lungs");
		this->set_moving_type("walking and crawling");
		this->set_heart_chamber_count(3);
	}
	Reptile(string t) {
		this->set_type(t);
		this->set_skin_covering("dry scales");
		this->set_type_of_breath("only lungs");
		this->set_moving_type("walking and crawling");
		this->set_heart_chamber_count(3);
	}
	void set_type(string t) {
		if (is_valid_string(t)) {
			this->type = t;
		}
	}

	void get_data() {
		cout << "Type: " << this->type << " reptile;" << endl;
		print_data();
	}
};


class Amphibian : public Cold_Blooded {
	string type;
public:
	Amphibian() {
		this->set_skin_covering("moist");
		this->set_type_of_breath("lungs and skin");
		this->set_moving_type("walking and swimming");
		this->set_heart_chamber_count(3);
	}
	Amphibian(string t) {
		this->set_type(t);
		this->set_skin_covering("moist");
		this->set_type_of_breath("lungs and skin");
		this->set_moving_type("walking and swimming");
		this->set_heart_chamber_count(3);
	}
	void set_type(string t) {
		if (is_valid_string(t)) {
			this->type = t;
		}
	}
	void get_data() {
		cout << "Type: " << this->type << " amphibian;" << endl;
		print_data();
	}
};


class Warm_Blooded : public Vertebrate {
public:
	Warm_Blooded() {
		this->set_body_temperature_dependency("Independent");
		this->set_metabolism("high");
		this->set_heart_chamber_count(4);

	}
	void print_warm() {
		cout << this->get_body_temperature_dependency() << endl;
		cout << this->get_metabolism() << endl;
		cout << this->get_heart_chamber_count() << endl;
	}
};

class Bird: public Warm_Blooded {
	string type;
public:
	Bird() {
		this->set_skin_covering("feathers");
		this->set_type_of_breath("lungs and sacs");
		this->set_moving_type("walking and flying");
	}
	Bird(string t) {
		this->set_type(t);
		this->set_skin_covering("feathers");
		this->set_type_of_breath("lungs and sacs");
		this->set_moving_type("walking and flying");
	}
	void set_type(string t) {
		if (is_valid_string(t)) {
			this->type = t;
		}
	}
	void get_data() {
		cout << "Type: " << this->type << " bird;" << endl;
		print_data();
	}
};

class Mammal : public Warm_Blooded {
	string type;
public:
	Mammal() {
		this->set_skin_covering("fur");
		this->set_type_of_breath("only lungs");
		this->set_moving_type("walking");
	}
	Mammal(string t) {
		this->set_type(t);
		this->set_skin_covering("fur");
		this->set_type_of_breath("only lungs");
		this->set_moving_type("walking");
	}
	void set_type(string t) {
		if (is_valid_string(t)) {
			this->type = t;
		}
	}
	void get_data() {
		cout << "Type: " << this->type << " mammal;" << endl;
		print_data();
	}
};


int main() {
	cout << endl;

	Fish f("Snapper");
	f.get_data();
	cout << endl;

	Reptile r("Crocodile");
	r.get_data();
	cout << endl;

	Amphibian a("Frog");
	a.get_data();
	cout << endl;

	Bird b("Parrot");
	b.get_data();
	cout << endl;

	Mammal m("Dog");
	m.get_data();
	cout << endl;

	return 0;
}