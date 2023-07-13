#include <iostream>
#include <string>

#include "animal.h"
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

Vertebrate::Vertebrate() {
	this->characteristics = new string[characteristics_size];
	this->set_common_characteristics();
	constructor_call_count++;
}
Vertebrate::Vertebrate(const Vertebrate& obj) {
	this->body_temperature_dependency = obj.body_temperature_dependency;
	this->metabolism = obj.metabolism;
	this->skin_covering = obj.skin_covering;
	this->type_of_breath = obj.type_of_breath;
	this->moving_type = obj.moving_type;
	this->heart_chamber_count = obj.heart_chamber_count;
	this->characteristics_size = obj.characteristics_size;
	this->characteristics = new string[this->characteristics_size];
	for (int i = 0; i < this->characteristics_size; i++) {
		this->characteristics[i] = obj.characteristics[i];
	}

}

Vertebrate::Vertebrate(Vertebrate&& obj) {
	this->body_temperature_dependency = obj.body_temperature_dependency;
	this->metabolism = obj.metabolism;
	this->skin_covering = obj.skin_covering;
	this->type_of_breath = obj.type_of_breath;
	this->moving_type = obj.moving_type;
	this->heart_chamber_count = obj.heart_chamber_count;
	this->characteristics_size = obj.characteristics_size;
	this->characteristics = obj.characteristics;
	obj.characteristics = nullptr;
	obj.characteristics_size = 0;
}

Vertebrate& Vertebrate::operator = (const Vertebrate& obj) {
	if (this != &obj) {
		this->body_temperature_dependency = obj.body_temperature_dependency;
		this->metabolism = obj.metabolism;
		this->skin_covering = obj.skin_covering;
		this->type_of_breath = obj.type_of_breath;
		this->moving_type = obj.moving_type;
		this->heart_chamber_count = obj.heart_chamber_count;
		this->characteristics_size = obj.characteristics_size;
		delete[] this->characteristics;
		this->characteristics = nullptr;
		this->characteristics = new string[this->characteristics_size];
		for (int i = 0; i < this->characteristics_size; i++) {
			this->characteristics[i] = obj.characteristics[i];
		}
	}
	return *this;
}

Vertebrate& Vertebrate::operator = (Vertebrate&& obj) {
	if (this != &obj) {
		this->body_temperature_dependency = obj.body_temperature_dependency;
		this->metabolism = obj.metabolism;
		this->skin_covering = obj.skin_covering;
		this->type_of_breath = obj.type_of_breath;
		this->moving_type = obj.moving_type;
		this->heart_chamber_count = obj.heart_chamber_count;
		this->characteristics_size = obj.characteristics_size;
		delete[] this->characteristics;
		this->characteristics = nullptr;
		this->characteristics = obj.characteristics;
		obj.characteristics = nullptr;
		obj.characteristics_size = 0;
	}
	return *this;
}

void Vertebrate::set_common_characteristics() {
	this->characteristics[0] = "Backbone";
	this->characteristics[1] = "Flexible dorsal rod";
	this->characteristics[2] = "Nerve hollow with brain";
	this->characteristics[3] = "Three layers of cells as an embryo";
	this->characteristics[4] = "Body cavity";
	this->characteristics[5] = "Tissues and organs";
	this->characteristics[6] = "Endoskeleton";
}
void Vertebrate::voice() {
	cout << "Sound of a vertebrate animal isn't always identical to others, it can be absent at all;" << endl;
}
void Vertebrate::move() {
	cout << "Moving type of a vertebrate animal isn't always identical to others;" << endl;
}
void Vertebrate::set_body_temperature_dependency(string dep) {
	lower_case(&dep);
	if (dep == "dependent" || dep == "independent") {
		this->body_temperature_dependency = dep;
	}
}
void Vertebrate::set_metabolism(string met) {
	lower_case(&met);
	if (met == "low" || met == "high") {
		this->metabolism = met;
	}
}
void Vertebrate::set_skin_covering(string skin_cover) {
	lower_case(&skin_cover);
	if (skin_cover == "fur" || skin_cover == "feathers" || skin_cover == "dry scales" || skin_cover == "wet scales" || skin_cover == "moist") {
		this->skin_covering = skin_cover;
	}
}

void Vertebrate::set_heart_chamber_count(int count) {
	if (count >= 2 && count <= 4) {
		this->heart_chamber_count = count;
	}
}
void Vertebrate::set_type_of_breath(string breath) {
	lower_case(&breath);
	if (breath == "only lungs" || breath == "lungs and skin" || breath == "lungs and sacs" || breath == "gills") {
		this->type_of_breath = breath;
	}
}

void Vertebrate::set_moving_type(string move) {
	lower_case(&move);
	if (move == "walking"
		|| move == "swimming"
		|| move == "walking and crawling"
		|| move == "walking and swimming"
		|| move == "walking and flying"
		|| move == "walking, flying and swimming") {
		this->moving_type = move;
	}
}

string Vertebrate::get_body_temperature_dependency() {
	return this->body_temperature_dependency;
}
string Vertebrate::get_metabolism() {
	return this->metabolism;
}
string Vertebrate::get_skin_covering() {
	return this->skin_covering;
}

string Vertebrate::get_type_of_breath() {
	return this->type_of_breath;
}

string Vertebrate::get_moving_type() {
	return this->moving_type;
}
int Vertebrate::get_weight() {
	return this->weight;
}

int Vertebrate::get_heart_chamber_count() {
	return this->heart_chamber_count;
}

void Vertebrate::print_common_characteristics() {
	cout << "{" << endl;
	for (int i = 0; i < this->characteristics_size - 1; i++) {
		cout << "    " << this->characteristics[i] << "," << endl;
	}
	cout << "    " << this->characteristics[this->characteristics_size - 1] << endl << "}";
}

void Vertebrate::print_data() {
	cout << "Body temperature: " << this->body_temperature_dependency << ";" << endl;
	cout << "Metabolysm level: " << this->metabolism << ";" << endl;
	cout << "Skin covering type: " << this->skin_covering << ";" << endl;
	cout << "Type of breath: " << this->type_of_breath << ";" << endl;
	cout << "Type of moving: " << this->moving_type << ";" << endl;
	cout << "Heart type: " << this->heart_chamber_count << " chambered;" << endl;
	cout << "Common characteristics: ";
	this->print_common_characteristics();
}
 Vertebrate::~Vertebrate() {
	//cout << "Vertebrate destructor" << endl;
	delete[] this->characteristics;
}



Cold_Blooded::Cold_Blooded() {
	this->set_body_temperature_dependency("Dependent");
	this->set_metabolism("Low");
}
Cold_Blooded::Cold_Blooded(const Cold_Blooded& obj) {
	this->thermoregulation = obj.thermoregulation;
}
Cold_Blooded::Cold_Blooded(Cold_Blooded&& obj) {
	this->thermoregulation = obj.thermoregulation;
}
Cold_Blooded& Cold_Blooded::operator = (const Cold_Blooded& obj) {
	if (this != &obj) {
		this->thermoregulation = obj.thermoregulation;
	}
	return *this;
}
Cold_Blooded& Cold_Blooded::operator = (Cold_Blooded&& obj) {
	if (this != &obj) {
		this->thermoregulation = obj.thermoregulation;
	}
	return *this;
}
void Cold_Blooded::voice() {
	cout << "Sound of a cold blooded animal isn't always identical to others, it can be absent at all;" << endl;
}
void Cold_Blooded::move(){
	cout << "Moving type of a cold blooded animal isn't always identical to others;" << endl;
}
void Cold_Blooded::set_thermoregulation(string t_reg) {
	lower_case(&t_reg);
	if (t_reg == "poikilothermy" || t_reg == "ectothermy" || t_reg == "heterothermy") {
		this->thermoregulation = t_reg;
	}
}
string Cold_Blooded::get_thermoregulation() {
	return this->thermoregulation;
}
void Cold_Blooded::print_cold_blooded_data() {
	cout << this->thermoregulation << endl;
	cout << get_body_temperature_dependency() << endl;
	cout << get_skin_covering() << endl;
}
Cold_Blooded::~Cold_Blooded() {
	//cout << "Cold_Blooded destructor" << endl;
}



Fish::Fish() {
	this->set_skin_covering("wet scales");
	this->set_type_of_breath("gills");
	this->set_moving_type("swimming");
	this->set_heart_chamber_count(2);
}
Fish::Fish(string t) {
	this->set_type(t);
	this->set_skin_covering("wet scales");
	this->set_type_of_breath("gills");
	this->set_moving_type("swimming");
	this->set_heart_chamber_count(2);
}
Fish::Fish(const Fish& obj) {
	this->type = obj.type;
}
Fish::Fish(Fish&& obj){
	cout << "Move constructor Fish" << endl;
	this->type = obj.type;
	this->set_skin_covering(obj.get_skin_covering());
	this->set_type_of_breath(obj.get_type_of_breath());
	this->set_moving_type(obj.get_moving_type());
	this->set_heart_chamber_count(obj.get_heart_chamber_count());
}
Fish& Fish::operator = (const Fish& obj) {
	if (this != &obj) {
		this->type = obj.type;
	}
	return *this;
}
Fish& Fish::operator = (Fish&& obj){
	cout << "Move operator assignment Fish" << endl;
	if (this != &obj) {
		this->type = obj.type;
		this->set_skin_covering(obj.get_skin_covering());
		this->set_type_of_breath(obj.get_type_of_breath());
		this->set_moving_type(obj.get_moving_type());
		this->set_heart_chamber_count(obj.get_heart_chamber_count());
	}
	return *this;
}
bool Fish::operator > (const Fish& obj) {
	if (this->weight > obj.weight) {
		return true;
	}
	else {
		return false;
	}
}
bool Fish::operator < (const Fish& obj) {
	if (this->weight < obj.weight) {
		return true;
	}
	else {
		return false;
	}
}
void Fish::cln_vrt() {
	cout << endl;
}
void Fish::voice() {
	cout << "No sound;" << endl;
}
void Fish::set_type(string t) {
	if (is_valid_string(t)) {
		this->type = t;
	}
}
void Fish::set_weight(int w) {
	if (w > 0 && w < 40000) {
		this->weight = w;
	}
}
void Fish::move() {
	cout << "Swimming" << endl;
}
void Fish::get_data() {
	cout << "Type: " << this->type << " fish;" << endl;
	print_data();
}
void Fish::get_type() {
	cout << "Type: " << this->type << ";" << endl;
}
Fish::~Fish() {
	//cout << "Fish destructor" << endl;
}



Reptile::Reptile() {
	this->sound = "not set";
	this->set_skin_covering("dry scales");
	this->set_type_of_breath("only lungs");
	this->set_moving_type("walking and crawling");
	this->set_heart_chamber_count(3);
}
Reptile::Reptile(string t) {
	this->set_type(t);
	this->set_skin_covering("dry scales");
	this->set_type_of_breath("only lungs");
	this->set_moving_type("walking and crawling");
	this->set_heart_chamber_count(3);
}
Reptile::Reptile(const Reptile& obj) {
	this->type = obj.type;
	this->sound = obj.sound;
}
Reptile::Reptile(Reptile&& obj) {
	cout << "Move constructor Reptile" << endl;
	this->type = obj.type;
	this->sound = obj.sound;
	this->set_skin_covering(obj.get_skin_covering());
	this->set_type_of_breath(obj.get_type_of_breath());
	this->set_moving_type(obj.get_moving_type());
	this->set_heart_chamber_count(obj.get_heart_chamber_count());
}
Reptile& Reptile::operator = (const Reptile& obj) {
	if (this != &obj) {
		this->type = obj.type;
		this->sound = obj.sound;

	}
	return *this;
}
Reptile& Reptile::operator = (Reptile&& obj) {
	cout << "Move operator assignment Reptile" << endl;
	if (this != &obj) {
		this->type = obj.type;
		this->sound = obj.sound;
		this->set_skin_covering(obj.get_skin_covering());
		this->set_type_of_breath(obj.get_type_of_breath());
		this->set_moving_type(obj.get_moving_type());
		this->set_heart_chamber_count(obj.get_heart_chamber_count());
	}
	return *this;
}
bool Reptile::operator > (const Reptile& obj) {
	if (this->weight > obj.weight) {
		return true;
	}
	else {
		return false;
	}
}
bool Reptile::operator < (const Reptile& obj) {
	if (this->weight < obj.weight) {
		return true;
	}
	else {
		return false;
	}
}
void Reptile::cln_vrt() {
	cout << endl;
}
void Reptile::voice() {
	if (this->sound.empty()) {
		cout << "A reptile's sound isn's identical to athers;" << endl;
	}
	else {
		cout << "Sound: " << this->sound << ";" << endl;
	}
}
void Reptile::set_sound(string s) {
	if (is_valid_string(s)) {
		this->sound = s;
	}
}
void Reptile::move() {
	cout << "Swimming and crowling or swimming and walking;" << endl;
}
void Reptile::set_type(string t) {
	if (is_valid_string(t)) {
		this->type = t;
	}
}
void Reptile::set_weight(int w) {
	if (w > 0 && w < 3000) {
		this->weight = w;
	}
}
void Reptile::get_data() {
	cout << "Type: " << this->type << " reptile;" << endl;
	print_data();
}
void Reptile::get_type() {
	cout << "Type: " << this->type << ";" << endl;
}
Reptile::~Reptile() {
	//cout << "reptile destructor" << endl;
}

Amphibian::Amphibian() {
	this->set_skin_covering("moist");
	this->set_type_of_breath("lungs and skin");
	this->set_moving_type("walking and swimming");
	this->set_heart_chamber_count(3);
}
Amphibian::Amphibian(string t) {
	this->set_type(t);
	this->set_skin_covering("moist");
	this->set_type_of_breath("lungs and skin");
	this->set_moving_type("walking and swimming");
	this->set_heart_chamber_count(3);
}
Amphibian::Amphibian(const Amphibian& obj) {
	this->type = obj.type;
	this->sound = obj.sound;
}
Amphibian::Amphibian(Amphibian&& obj) {
	cout << "Move constructor Amphibian" << endl;
	this->type = obj.type;
	this->sound = obj.sound;
	this->set_skin_covering(obj.get_skin_covering());
	this->set_type_of_breath(obj.get_type_of_breath());
	this->set_moving_type(obj.get_moving_type());
	this->set_heart_chamber_count(obj.get_heart_chamber_count());
}
Amphibian& Amphibian::operator = (const Amphibian& obj) {
	if (this != &obj) {
		this->type = obj.type;
		this->sound = obj.sound;
	}
	return *this;
}
Amphibian& Amphibian::operator = (Amphibian&& obj) {
	cout << "Move operator assignment Amphibian" << endl;
	if (this != &obj) {
		this->type = obj.type;
		this->sound = obj.sound;
		this->set_skin_covering(obj.get_skin_covering());
		this->set_type_of_breath(obj.get_type_of_breath());
		this->set_moving_type(obj.get_moving_type());
		this->set_heart_chamber_count(obj.get_heart_chamber_count());
	}
	return *this;
}
bool Amphibian::operator > (const Amphibian& obj) {
	if (this->weight > obj.weight) {
		return true;
	}
	else {
		return false;
	}
}
bool Amphibian::operator < (const Amphibian& obj) {
	if (this->weight < obj.weight) {
		return true;
	}
	else {
		return false;
	}
}
void Amphibian::cln_vrt() {
	cout << endl;
}
void Amphibian::voice() {
	if (this->sound.empty()) {
		cout << "A amphibian's sound isn's identical to athers;" << endl;
	}
	else {
		cout << "Sound: " << this->sound << ";" << endl;
	}
}
void Amphibian::set_sound(string s) {
	if (is_valid_string(s)) {
		this->sound = s;
	}
}
void Amphibian::move() {
	cout << "Swimming and walking or Swimming and crawling;" << endl;
}
void Amphibian::set_type(string t) {
	if (is_valid_string(t)) {
		this->type = t;
	}
}
void Amphibian::set_weight(int w) {
	if (w > 0 && w < 20) {
		this->weight = w;
	}
}
void Amphibian::get_data() {
	cout << "Type: " << this->type << " amphibian;" << endl;
	print_data();
}
void Amphibian::get_type() {
	cout << "Type: " << this->type << ";" << endl;
}
Amphibian::~Amphibian() {
	//cout << "Amphibian destructor" << endl;
}


Warm_Blooded::Warm_Blooded() {
	this->set_body_temperature_dependency("Independent");
	this->set_metabolism("high");
	this->set_heart_chamber_count(4);

}
void Warm_Blooded::print_warm() {
	cout << this->get_body_temperature_dependency() << endl;
	cout << this->get_metabolism() << endl;
	cout << this->get_heart_chamber_count() << endl;
}
void Warm_Blooded::voice() {
	cout << "Voice of a warm blooded animal isn't always identical to others;" << endl;
}
void Warm_Blooded::move() {
	cout << "walking and swimming or flying and walking or flying, swimming and walking;" << endl;
}
Warm_Blooded::~Warm_Blooded() {
	//cout << "Warm blooded destructor" << endl;
}



Bird::Bird() {
	this->set_skin_covering("feathers");
	this->set_type_of_breath("lungs and sacs");
	this->set_moving_type("walking and flying");
}
Bird::Bird(string t) {
	this->set_type(t);
	this->set_skin_covering("feathers");
	this->set_type_of_breath("lungs and sacs");
	this->set_moving_type("walking and flying");
}
Bird::Bird(Bird&& obj) {
	cout << "Move constructor Bird" << endl;
	this->type = obj.type;
	this->sound = obj.sound;
	this->set_skin_covering(obj.get_skin_covering());
	this->set_type_of_breath(obj.get_type_of_breath());
	this->set_moving_type(obj.get_moving_type());
}
Bird::Bird(const Bird& obj) {
	this->type = obj.type;
	this->sound = obj.sound;
}
Bird& Bird::operator = (const Bird& obj) {
	if (this != &obj) {
		this->sound = obj.sound;
		this->type = obj.type;
	}
	return *this;
}
Bird& Bird::operator = (Bird&& obj) {
	cout << "Move operator assignment Bird" << endl;
	if (this != &obj) {
		this->sound = obj.sound;
		this->type = obj.type;
		this->set_skin_covering(obj.get_skin_covering());
		this->set_type_of_breath(obj.get_type_of_breath());
		this->set_moving_type(obj.get_moving_type());
	}
	return *this;
}
bool Bird::operator > (const Bird& obj) {
	if (this->weight > obj.weight) {
		return true;
	}
	else {
		return false;
	}
}
bool Bird::operator < (const Bird& obj) {
	if (this->weight < obj.weight) {
		return true;
	}
	else {
		return false;
	}
}
void Bird::cln_vrt() {
	cout << endl;;
}
void Bird::voice() {
	if (this->sound.empty()) {
		cout << "A bird's sound isn's identical to athers;" << endl;
	}
	else {
		cout << "Sound: " << this->sound << ";" << endl;
	}
}
void Bird::set_sound(string s) {
	if (is_valid_string(s)) {
		this->sound = s;
	}
}
void Bird::move() {
	cout << "Flying and walking or flying, swimming and walking;" << endl;
}
void Bird::set_type(string t) {
	if (is_valid_string(t)) {
		this->type = t;
	}
}
void Bird::set_weight(int w) {
	if (w > 0 && w < 150) {
		this->weight = w;
	}
}
void Bird::get_data() {
	cout << "Type: " << this->type << " bird;" << endl;
	print_data();
}
void Bird::get_type() {
	cout << "Type: " << this->type << ";" << endl;
}
Bird::~Bird() {
	//cout << "Bird destructor" << endl;
}



Mammal::Mammal() {
	this->set_skin_covering("fur");
	this->set_type_of_breath("only lungs");
	this->set_moving_type("walking");
}
Mammal::Mammal(string t) {
	this->set_type(t);
	this->set_skin_covering("fur");
	this->set_type_of_breath("only lungs");
	this->set_moving_type("walking");
}
Mammal::Mammal(const Mammal& obj) {
	this->type = obj.type;
	this->sound = obj.sound;
}
Mammal::Mammal(Mammal&& obj) {
	cout << "Move constructor Mammal" << endl;
	this->type = obj.type;
	this->sound = obj.sound;
	this->set_skin_covering(obj.get_skin_covering());
	this->set_type_of_breath(obj.get_type_of_breath());
	this->set_moving_type(obj.get_moving_type());
}
Mammal& Mammal::operator = (const Mammal& obj) {
	if (this != &obj) {
		this->type = obj.type;
		this->sound = obj.sound;
	}
	return *this;
}
Mammal& Mammal::operator = (Mammal&& obj) {
	cout << "Move operator assignment Mammal" << endl;
	if (this != &obj) {
		this->type = obj.type;
		this->sound = obj.sound;
		this->set_skin_covering(obj.get_skin_covering());
		this->set_type_of_breath(obj.get_type_of_breath());
		this->set_moving_type(obj.get_moving_type());
	}
	return *this;
}
bool Mammal::operator > (const Mammal& obj) {
	if (this->weight > obj.weight) {
		return true;
	}
	else {
		return false;
	}
}
bool Mammal::operator < (const Mammal& obj) {
	if (this->weight < obj.weight) {
		return true;
	}
	else {
		return false;
	}
}
void Mammal::cln_vrt() {
	cout << endl;
}
void Mammal::voice() {
	if (this->sound.empty()) {
		cout << "A mammal's sound isn's identical to athers;" << endl;
	}
	else {
		cout << "Sound: " << this->sound << ";" << endl;
	}
}
void Mammal::set_sound(string s) {
	if (is_valid_string(s)) {
		this->sound = s;
	}
}
void Mammal::move() {
	cout << "Walking and swimming or only walking;" << endl;
}
void Mammal::set_type(string t) {
	if (is_valid_string(t)) {
		this->type = t;
	}
}
void Mammal::set_weight(int w) {
	if (w > 0 && w < 200000) {
		this->weight = w;
	}
}
void Mammal::get_data() {
	cout << "Type: " << this->type << " mammal;" << endl;
	print_data();
}
void Mammal::get_type() {
	cout << "Type: " << this->type << ";" << endl;
}
Mammal::~Mammal() {
	//cout << "Mammal destructor" << endl;
}
