/*
taiquan evans
8/7/2022
*/

//file for the phone

#include "Header.h"
#include "calling.h"



int rose()
{
string name;

int a;

string game;

	cout << "welcome I am your virtual assistent, here to help you with manuaring your new phone" << endl;
	
	cout << "please register your name." << endl;
	cin >> name;

	cout << "hello " << name << " your phone comes with  multitude of apps already downloaded at my discresion." << endl;
	retry:
	cout << "if you do not like this function please hit 1 for change or 2 continue!" << endl;
	cin >> a;

	if (a == 1)
	{
		cout << "sorry, that function is not available right now, try again after an update!" << endl;
		goto retry;
	}
	else if (a == 2)
	{
		cout << "great that makes things easier!" << endl;
	}

	back:
	cout << "there are a multiple apps that you can choose from below v. lets try one!" << endl;
	cout << endl;
	cout << "keywords" << endl;
	cout << "blackjack" << endl;
	cout << "story game" << endl;
	cout << "calculator" << endl;
	cin >> game;
	//calls keywords function
	if ("keywords" == game)
	{
		 keywords();
	}
	//calls blackjack function
	else if ("blackjack" == game)
	{
		 blackjack();
	}
	//calls story game function
	else if ("story game" == game || "storygame" == game)
	{
		 life();
	}
	//calls the calculator
	else if ("calculator" == game)
	{
		cout << "sorry this function isn't available back, check again later! thank you!" << endl;
		goto back;

	}
	//sends back if choice is outside what's given
	else
	{
		cout << "no, stop, I gave you your choices. go back" << endl;

		goto back;
	}

	return 0;
}

