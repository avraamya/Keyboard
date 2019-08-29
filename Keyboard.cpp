#include "Keyboard.h"

/*setters*/

void Keyboard::set_languages(const char ** languages)
{
	this->languages = new char*[num_lang];
	for (int i = 0; i < num_lang; i++)
	{
		strcpy_s(this->languages[i], strlen(languages[i]) + 1, languages[i]);
	}
}

/*void Keyboard::set_num_lang(const int num_lang)
{
	if (num_lang < MIN_LANG || num_lang>MAX_LANG)
	{
		this->num_lang = MIN_LANG;
	}
	else
	{
		this->num_lang = num_lang;
	} 
}*/

void Keyboard::set_keys(const Key ** keys)
{
	this->Keys = new Key*[num_keys];
	for (int i = 0; i < num_keys; i++) {
		this->Keys[i] = NULL;
	}
}

void Keyboard::set_num_keys(const int num_keys)
{
	if (num_keys < MIN_KEYS || num_keys>MAX_KEYS)
	{
		this->num_keys = MIN_KEYS;
	}
	else
	{
		this->num_keys = num_keys;
	}
}

void Keyboard::set_num_special_keys(const int num_special_keys)
{
	if (num_special_keys < MIN_SPECIAL_KEYS || num_special_keys>MAX_SPECIAL_KEYS)
	{
		this->num_special_keys = MIN_SPECIAL_KEYS;
	}
	else
	{
		this->num_special_keys = num_special_keys;
	}
}
/*constractors*/

Keyboard::Keyboard()
	:num_lang{1}, num_keys{1}, num_special_keys{0}
{
	//this->languages{ nullptr };
	this->languages = new char*[num_lang];
	languages[0] = new char[strlen("English")+1];
	strcpy_s(languages[0], strlen("English") + 1, "English");

	Key k;
	this->Keys = new Key*[num_keys];
	Keys[0] = &k;
}

Keyboard::Keyboard(int num_lang, int num_special_keys, int num_keys)
	:num_lang{ num_lang }, num_special_keys{ num_special_keys }, num_keys{ num_keys }
{
	this->languages = new char*[this->num_lang];
	for (int i = 0; i < this->num_lang; i++)
	{
		this->languages[i] = NULL;
	}

	this->Keys = new Key*[this->num_keys];
	for (int i = 0; i < this->num_keys; i++)
	{
		this->Keys[i] = NULL;
	}
}

Keyboard::Keyboard(const char ** languages, int num_lang,const Key ** keys, int num_keys)
	:num_keys{ num_keys }, num_lang{ num_lang }
{
	this->set_languages(languages);
	this->set_keys(keys);
	int count = 0;
	for (int i = 0; i < num_keys; i++)
	{
		if (keys[i]->get_key_code() >= MIN_KEY_CODE_SPECIAL_KEYS)
		{
			count++;
		}
	}
	set_num_special_keys(count);
}

Keyboard::Keyboard(const Keyboard &other)
	:num_lang{ other.num_lang }, num_keys{ other.num_keys }, num_special_keys{ other.num_special_keys }
{
	for (int i = 0; i < num_lang; i++)
	{
		int len = strlen(other.languages[i]) + 1;
		this->languages[i] = new char[len];
		if (this->languages[i] == NULL)
		{
			cout << "Error: manufactur name memory allocation";
			exit(EXIT_FAILURE);
		}
		strcpy_s(this->languages[i], len, other.languages[i]);
	}

	for (int i = 0; i < other.num_keys; i++)
	{
		//Keys[i]->{other.keys[i]->};
		this->Keys[i] = other.Keys[i];
	}

}

/*destractors*/
Keyboard::~Keyboard()
{
	cout << "destractor called: " << endl;
}

/*****print*****/
void Keyboard::print_keys()
{
	cout << endl;
	for (int i = 0; i < num_keys; i++)
	{
		if (Keys[i] != NULL&& Keys[i]->get_description() !="EMPTY")
		{
			Keys[i]->print();
		}	
	}
}

void Keyboard::print_pressed_keys()
{
	bool check = false;
	cout << endl;
	for (int i = 0; i < num_keys; i++)
	{
		if (Keys[i]->get_is_pressed()) {
			Keys[i]->print();
			check = true;
		}
	}
	if (check == false)
	{
		cout << "No Keys are pressed..." << endl;
	}
}

void Keyboard::print_special_keys()
{
	cout << endl;
	for (int i = 0; i < num_keys; i++)
	{
		if (Keys[i]->get_key_code()>= MIN_KEY_CODE_SPECIAL_KEYS) {
			Keys[i]->print();
		}
	}
}

void Keyboard::print_language()
{
	cout << endl;
	for (int i = 0; i < this->get_num_lang(); i++)
	{
		cout << i + 1 << ". "<< languages[i]<<endl;
	}
}

/*****functions*****/
bool Keyboard::add_lenguage(const char * language)//assume that size of array is not 3 - but that size the user insert.
{

	for (int i = 0; i < num_lang; i++)
	{
		if ((languages[i]==NULL)|| (languages[i] == "EMPTY"))
		{
			//((strncmp(languages[i], DEF_EMPTY, strlen(DEF_EMPTY) == 0))
			this->languages[i] = new char[strlen(language) + 1];
			strcpy_s(this->languages[i], strlen(language) + 1, language);
			cout << languages[i] << " added. " << endl;
			return true;
		}
	}
	cout << " no language is added. " << endl;
	return false;
}

bool Keyboard::remove_lenguage(int index)//assume that size of array is not 3 - but that size the user insert.
{
	if (languages[index] != NULL)
	{
		cout << languages[index] << " deleted. " << endl;
		//((strncmp(languages[i], DEF_EMPTY, strlen(DEF_EMPTY) == 0))
		strcpy_s(this->languages[index], strlen("EMPTY") + 1, "EMPTY");
		return true;
	}
	cout << " no language is deleted. " << endl;
	return false;
}

bool Keyboard::add_key(Key key)
{
	for (int i = 0; i < num_keys; i++)
	{
		if (Keys[i] == NULL)
		{
			cout << "key code: " << key.get_key_code() << " is added" << endl;
			this->Keys[i] = &key;
			return true;
		}
	}
	cout << "no key is added. " << endl;
	return false;
}

bool Keyboard::replace_special_key(Key src, Key target)
{
	for (int i = MIN_KEY_CODE_SPECIAL_KEYS; i <= MAX_KEY_CODE_SPECIAL_KEYS; i++)
	{
		if(target.get_key_code()== src.get_key_code())
		{
			if (this->Keys[i]->get_key_code() == target.get_key_code())
			{
				this->Keys[i] = &target;
				return true;
			}	
		}		
	}
	return false;
}

int Keyboard::find(int key_code)
{
	for (int i = 0; i < num_keys; i++)
	{
		if (Keys[i] == NULL)
		{
			return -1;
		}
		if (Keys[i]->get_key_code() == key_code)
		{
			return i;
		}
	}
	return -1;
}
