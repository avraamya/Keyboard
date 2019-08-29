#pragma once
#include "Key.h"

#define MAX_KEYS 101
#define MIN_KEYS 1
#define MAX_LANG 3
#define DEF_LANG "English"
#define DEF_EMPTY "EMPTY"
#define MIN_LANG 1
#define MAX_SPECIAL_KEYS 4
#define MIN_SPECIAL_KEYS 0


class Keyboard
{
private:
	char** languages; //array of lang
	int const num_lang;
	Key **Keys;//*************************************
	int num_keys;
	int num_special_keys;//need to be const?

public:
	/*getters in-line*/
	char** get_languages()const { return languages; };
	int get_num_lang()const { return num_lang; };
	Key** get_keys()const { return Keys; };
	int get_num_keys()const { return num_keys; };
	int	get_num_special_keys()const { return num_special_keys; };

	/*setter*/
	void set_languages(const char**);
	//void set_num_lang(const int);
	void set_keys(const Key**);
	void set_num_keys(const int);
	void set_num_special_keys(const int);

	/*constractors*/
	Keyboard();
	Keyboard(int num_lang, int num_special_keys, int num_keys);
	Keyboard(const char** languages, int num_lang, const Key ** keys, int num_keys);
	Keyboard(const Keyboard &kb);

	/*destractors*/
	~Keyboard();

	/*print*/
	void print_keys();
	void print_pressed_keys();
	void print_special_keys();
	void print_language();

	/*****functions*****/
	bool add_lenguage(const char* language);
	bool remove_lenguage(int index);
	bool add_key(Key key);
	bool replace_special_key(Key src, Key target);
	int find(int key_code);


};


