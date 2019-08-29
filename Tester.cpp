#include "Key.h"
#include "Keyboard.h"
#include <stdio.h>
#include <ctype.h>
using namespace std;

void print_menu();
int main()
{
	cout << "assignment 6 - avraam" << endl;
	char confirm[1];
	bool is_confirm = false;
	int add_keys = 3;
	int num_lang = 0;
	int num_keys = 0;
	int num_special_keys = -1;
	char temp[MAXLEN];
	char values[MAXLEN];
	char description[MAXLEN];
	int len;
	int key_code = 0;

	cout << "Welcome to the Keyboard Tester" << endl;
	cout << "lets start creating your Keyboard now!!" << endl;
	cout << "--------------------------------------------" << endl;
	
	cout << "How many languages do you want to add to your keyboard?" << endl;
	while (num_lang > MAX_LANG || num_lang < MIN_LANG)
	{
		cin >> num_lang;
		if (num_lang > MAX_LANG || num_lang < MIN_LANG)
		{
			cout << "invalid value for number of languages" << endl;
			cout << "How many languages do you want to add to your keyboard?" << endl;
		}
	}
	
	cout << "How many keys for regular keys (numbers and letters) do you want to add to your keyboard?" << endl;
	while (num_keys > MAX_KEYS || num_keys < MIN_KEYS)
	{
		cin >> num_keys;
		if (num_keys > MAX_KEYS || num_keys < MIN_KEYS)
		{
			cout << "invalid value for number of regular keys" << endl;
			cout << "How many keys for regular keys (numbers and letters) do you want to add to your keyboard?" << endl;
		}
	}

	cout << "How many special keys do you want to add to your keyboard?" << endl;
	while (num_special_keys > MAX_SPECIAL_KEYS || num_special_keys < MIN_SPECIAL_KEYS)
	{
		cin >> num_special_keys;
		if (num_special_keys > MAX_SPECIAL_KEYS || num_special_keys < MIN_SPECIAL_KEYS)
		{
			cout << "invalid value for number of special keys" << endl;
			cout << "How many special keys do you want to add to your keyboard?" << endl;
		}
	}

	cout << "--------------------------------------------" << endl;
	cout << "--------------- PROCESSING -----------------" << endl;
	cout << "--------------------------------------------" << endl;

	if (num_lang == 1)
	{
		add_keys = 4;
	}

	Keyboard tester_keyboard(num_lang, num_special_keys, num_keys + num_special_keys + add_keys);
	tester_keyboard.add_lenguage("English");
	cout << "We have automatically set The English Language in your keyboard" << endl;

	if (num_lang == 1)
	{
		tester_keyboard.print_language();
		Key special_key("SPECIAL KEY", 123, "SPECIAL KEY", false, false);
		tester_keyboard.add_key(special_key);
	}
	else
	{
		for (int i = 1; i < num_lang; i++)
		{
			cout << "Enter the rest now:" << endl;
			cout << "Enter language:" << endl;
			cin >> temp;
			cout << endl;
			len = strlen(temp);
			char* str = new char[len + 1];
			strcpy_s(str, len + 1, temp);
			tester_keyboard.add_lenguage(str);
		}

		tester_keyboard.print_language();
	}
	cout << "--------------------------------------------" << endl;
	cout << "---------------TEST  PASSED-----------------" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "--------------- PROCESSING -----------------" << endl;
	cout << "--------------------------------------------" << endl;

	Key control("CONTROL", 1, "CONTROL", false, false);
	Key shift("SHIFT", 2, "SHIFT", false, false);
	Key escape("ESCAPE", 3, "ESCAPE", false, false);

	tester_keyboard.add_key(control);
	tester_keyboard.add_key(shift);
	tester_keyboard.add_key(escape);

	cout << "We are setting The keys: \"CONTROL\",\"SHIFT\",\"ESCAPE\" in your keyboard" << endl; 

	cout << "--------------------------------------------" << endl;
	cout << "---------------TEST  PASSED-----------------" << endl;
	cout << "--------------------------------------------" << endl;
	cout << " " << endl;
	if (num_special_keys!=0)
	{
		cout << "Please set the Special Keys Now" << endl;
		cout << "--------------------------------------------" << endl;

	}
		for (int i = 0; i < num_special_keys; i++)
	{
		is_confirm = false;
		while (is_confirm == false) {
			cout << "Creating key number " << i + 1 << " :" << endl;
			cout << "Enter key code" << endl;
			cin >> key_code;
			while (((key_code > MAX_KEY_CODE_SPECIAL_KEYS || key_code < MIN_KEY_CODE_SPECIAL_KEYS)) || ((tester_keyboard.find(key_code) != -1)))
			{
				cout << "ERROR: invalid special key code!! try again" << endl;
				cout << "Enter key code" << endl;
				cin >> key_code;
			}

			cout << "Enter values seperated by whitespace" << endl;
			//cin >> values;
			cin.ignore();
			cin.getline(values, MAXLEN);
			cout << "Enter description" << endl;
			//cin >> description;
			cin.ignore();
			cin.getline(description, MAXLEN);
			Key tmp(values, key_code, description, false, true);

			cout << "enter \"y\" to confirm:" << endl;
			cin >> confirm;
			putchar(tolower(confirm[0]));
			if (confirm[0] == 'y')
			{
				is_confirm = true;
				tester_keyboard.add_key(tmp);
			}
			else
			{
				cout << "Starting over ..." << endl;
			}
		}
	}

	cout << " " << endl;
	if (num_keys!=0)
	{
		cout << "Please set the regular Keys Now" << endl;
		cout << "--------------------------------------------" << endl;
	}
	for (int i = 0; i < num_keys; i++)
	{
		is_confirm = false;
		while (is_confirm == false) {
			cout << "Creating key number" << i + 1 << " : " << endl;
			cout << "Enter key code" << endl;
			cin >> key_code;
			while (((key_code > MAX_KEYS || key_code < MIN_KEYS)) || ((tester_keyboard.find(key_code) != -1)))
			{
				cout << "ERROR: invalid regular key code!! try again" << endl;
				cout << "Enter key code" << endl;
				cin >> key_code;
			}
			cout << "Enter values seperated by whitespace" << endl;
			//cin >> values;
			cin.ignore();
			cin.getline(values, MAXLEN);
			cout << "Enter description" << endl;
			//cin >> description;
			cin.ignore();
			cin.getline(description, MAXLEN);
			Key tmp(values, key_code, description, false, false);

			cout << "enter \"y\" to confirm:" << endl;
			cin >> confirm;
			confirm[0] = putchar(tolower(confirm[0]));
			if (confirm[0] == 'y')
			{
				is_confirm = true;
				tester_keyboard.add_key(tmp);

			}
			else
			{
				cout << "Starting over ..." << endl;
			}

		}
	}
	char menu;
	while (tester_keyboard.get_keys()[2]->get_is_pressed() == false)
	{
		print_menu();
		cin >> menu;
		cout << endl;
		putchar(tolower(menu));

		switch (menu)
		{
		case 'a': {
			tester_keyboard.print_keys();
			break;
		}
		case 's': {
			if (((tester_keyboard.find(200) == -1) && (tester_keyboard.find(201) == -1)) && ((tester_keyboard.find(202) == -1) && (tester_keyboard.find(203) == -1)))
			{
				cout << "there are no special keys" << endl;
				break;
			}
			tester_keyboard.print_special_keys();
			break;
		}
		case 'r': {
			if (((tester_keyboard.find(200) == -1) && (tester_keyboard.find(201) == -1)) && ((tester_keyboard.find(202) == -1) && (tester_keyboard.find(203) == -1)))
			{
				cout << "there are no special keys" << endl;
				break;
			}

			tester_keyboard.print_special_keys();
			cout << "enter keycode" << endl;
			cin >> key_code;
			cout << endl;
			cout << "Enter values seperated by whitespace" << endl;
			//cin >> values;
			cin.ignore();
			cin.getline(values, MAXLEN);
			cout << endl;
			cout << "Enter description" << endl;
			//cin >> description;
			cin.ignore();
			cin.getline(description, MAXLEN);
			cout << endl;
			Key tmp(values, key_code, description, false, false);
			key_code = tester_keyboard.find(key_code);
			tester_keyboard.replace_special_key(*(tester_keyboard.get_keys()[key_code]), tmp);
			tester_keyboard.print_special_keys();
			break;
		}
		case 'p': {
			tester_keyboard.print_keys();
			cout << "enter keycode" << endl;
			cin >> key_code;
			cout << endl;
			key_code = tester_keyboard.find(key_code);
			if (key_code == -1)
			{
				cout << "this key not found" << endl;
			}
			else{
				tester_keyboard.get_keys()[key_code]->set_is_pressed(true);
				tester_keyboard.get_keys()[key_code]->print();
			}
			break;
		}
		case 'k': {
			tester_keyboard.print_keys();
			cout << "enter keycode" << endl;
			cin >> key_code;
			cout << endl;
			key_code = tester_keyboard.find(key_code);			
			if (key_code == -1)
			{
				cout << "this key not found" << endl;
			}
			else {
				tester_keyboard.get_keys()[key_code]->print();
			}
			break;
		}
		case 'o': {
			tester_keyboard.print_pressed_keys();
			break;
		}
		case 'h': {
			break;
		}
		default: {
			cout << "Invalid choice!!" << endl;
			break;
		}
		}
	}


	cout << "TEST IS COMPLETED -- TILL WE MEET AGAIN ..." << endl;
	return 0;

}

void print_menu()
{
	cout << endl;
	cout << "---------- TESTER MENU -----------:" << endl;
	cout << "[a|A] - Show all keys information;" << endl;
	cout << "[s|S] - Show only special keys information;" << endl;
	cout << "[r|R] - Replace a special key;" << endl;
	cout << "[p|P] - Press on a key;" << endl;
	cout << "[k|K] - Show key information;" << endl;
	cout << "[o|O] - Show currently pressed keys;  " << endl;
	cout << "[H|h] - Print this Menu again;" << endl;
}
