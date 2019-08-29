#include "Key.h"

/*setters*/
void Key::set_values(const char values[])
{
	strcpy_s(this->values, MAXLEN, values);
}

void Key::set_is_shiftable(const bool is_shiftable)
{
	this->is_shiftable = is_shiftable;
}


void Key::set_description(const char * description)
{
	int len = strlen(description) + 1;
	this->description = new char[len];
	if (this->description == NULL)
	{
		cout << "Error: manufactur name memory allocation";
		exit(EXIT_FAILURE);
	}
	assert(this->description != 0);
	strcpy_s(this->description, len, description);
}

void Key::set_is_pressed(const bool is_pressed)
{
	this->is_pressed = is_pressed;
}

/*constractor*/

Key::Key()
	:key_code{ 0 }, is_shiftable{ 0 }, is_pressed{ 0 }
{
	set_description("---");
	set_values("---");
}

Key::Key(const char * val, const unsigned int code, const char * descrip, bool shift, bool press)
	:key_code{ code },is_shiftable{ shift }, is_pressed{ press }
{
	set_description(descrip);
	set_values(val);
}

Key::Key(const Key & k)
	:key_code{ k.key_code }, is_shiftable{ k.is_shiftable }, is_pressed{ k.is_pressed }
{
	char* temp_values = new char[strlen(k.values) + 1];
	strcpy_s(temp_values, strlen(k.values) +1 , k.values);
	this->set_values(temp_values);

	char* temp_description = new char[strlen(k.description) + 1];
	strcpy_s(temp_description, strlen(k.description) + 1, k.description);
	this->set_description(temp_description);
}
/*destractor*/
Key::~Key()
{
}

/*print*/
void Key::print()
{
	//bool shift = is_shiftable;
	bool press = this->is_pressed;
	bool special_Key;
	if (this->key_code >= MIN_KEY_CODE_SPECIAL_KEYS && this->key_code <= MAX_KEY_CODE_SPECIAL_KEYS)
	{
		special_Key = true;
	}
	else {
		special_Key = false;
	}

	printf("Code: %8u | ", this->key_code);

	printf("Special Key: %8s | ", special_Key ? "true" : "false");

	//printf("Shiftable: %8s | ", shift ? "true" : "false");
	//printf("Shiftable: %20s |", is_shiftable);
	//printf("Is pressed: %20s | ", is_pressed);
	printf("Pressed %8s | ", press ? "true" : "false");
	printf("Values: %15s | ", this->values);
	printf("Description: %15s | \n", this->description);

	/*cout << setfill(' ') << setw(20) << "Code: " << key_code << "|" ;
	cout << setfill(' ') << setw(20) << "Shiftable: " << is_shiftable << "|" ;
	cout << setfill(' ') << setw(20) << "Is pressed: " << is_pressed << "|" << endl;
	cout << setfill(' ') << setw(20) << "Values: " << values << "|" ;
	cout << setfill(' ') << setw(20) << "Description: " << description << "|";*/
}



