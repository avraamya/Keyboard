#pragma once
//include
#include <iostream>
#include <cassert>
#include <iomanip>
#include <string.h>
//#define
#define MAXLEN 30
#define MIN_KEY_CODE_SPECIAL_KEYS 200
#define MAX_KEY_CODE_SPECIAL_KEYS 203

using namespace std;

class Key {
private:
	char values[MAXLEN];//have limit - dinamic
	const unsigned int key_code;
	bool is_shiftable;
	char* description;//dont have limit - dinamic
	bool is_pressed;

public:
	/*getters in-line*/
	char get_values() const { return values[MAXLEN]; }//לא ידעתי שצריך מקסלן
	unsigned int get_key_code() const { return key_code; }
	bool get_is_shiftable() const { return is_shiftable; }
	char* get_description() const { return description; }
	bool get_is_pressed() const { return is_pressed; }

	/*setters*/

	void set_values(const char[]);
	void set_is_shiftable(const bool);
	void set_description(const char*);
	void set_is_pressed(const bool);

	/*constractors*/

	Key();
	Key(const char*, const unsigned int , const char* , bool, bool );
	Key(const Key &k);

	/*destractors*/
	~Key();
	
	/*print*/
	void print();
};

