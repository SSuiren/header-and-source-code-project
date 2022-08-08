/*
taiquan evans
8/7/2022
*/

//file for the apps on phone

//calls for the header file
#include "Header.h"

//vairables
string The_word;
string used;
string sofar;

int wrong;

//declaration
bool match(char letter, string word);
//declaration
char askGuess(string usedLettersStr);

int simulations = 1;


//guessing game
int keywords()
{



	const int Max_wrong = 5;

	string usrname;
	string password;
	string key;


	// Display Title of the program to the user
	system("Title CIA: Decripting Test.");
	cout << "CIA: DECRIPTION TEST" << endl;

	// Ask the recruit to log in using their name
	cout << "login" << endl;
	cin >> usrname;
	cout << "password" << endl;
	cin >> password;

	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	cout << "welcome " << usrname << endl;
	cout << endl;
	cout << endl;


	// Display an overview of what Keywords II is to the recruit 
	cout << "this program is meant to test whether you are able to decrpt codes and find the secret messages." << endl;
	cout << endl;

	// Display directions to the recruit on how to use Keywords
	cout << usrname << " you will be given 10 secret messages to decript, you have 5 tries. If you fail you'll be sent back to the beginning of training, good luck!" << endl;


	// Create a collection of 10 words you had written down manually
	vector<string>words;
	words.push_back("bomb");
	words.push_back("spy");
	words.push_back("killer");
	words.push_back("hideout");
	words.push_back("government");
	words.push_back("disease");
	words.push_back("harddrive");
	words.push_back("location");
	words.push_back("leader");

	// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
	srand(time(0));
	random_shuffle(words.begin(), words.end());

	The_word = words[0];
	wrong = 0;
	//Show player how much of the secret word he or she has guessed
	sofar = string(The_word.size(), '-');

	used = "";

	// Display the simulation # is starting to the recruit. 
	cout << "the simulation will begin when you press any key" << endl;
	cin >> key;

	cout << "here is a list of words that may be the answer, but they are mixed up" << endl;

	cout << "bmbo, pys, kliler, hediout, govrenment, deseasi, hradrdvie, lcaitono, laedre" << endl;

	// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
	while ((Max_wrong > wrong) && (sofar != The_word))
	{
		// Tell recruit how many incorrect guesses he or she has left
		cout << "you have " << (Max_wrong - wrong) << " chances left." << endl;

		// Show recruit the letters he or she has guessed
		cout << "you've used the following letters " << used << endl;


		cout << "the word so far is " << sofar << endl;

		//Add the new guess to the group of used letters
		used += askGuess(used);
	}



	// If the recruit has made too many incorrect guesses
	if (wrong == Max_wrong)
	{
		char again;
		//      Tell the recruit that he or she has failed the Keywords II course.
		cout << usrname << " You've failed the test, but don't fret, Try again! y/n" << endl;

		cout << "the word was " << The_word << endl;

		cin >> again;

		cin.clear(); //clear and ignore cin
		cin.ignore();

		again = tolower(again);

		system("cls");

		//Increment the number of simulations ran counter
		++simulations;

		if (again == 'y')
		{
			++simulations;

			return 100;
		}

		if (again == 'n')
		{
			cout << "it seems your not cut out for this, leave " << usrname << "." << endl;
			return 0;
		}
	}
	else if (The_word == sofar)
	{
		//Congratulate the recruit on guessing the secret words
		cout << "good job " << usrname << " you got it correct" << endl;

		cout << "the word was " << The_word << endl;

		if (simulations < 3)
		{
			char ready;
			cout << " but it's not over " << usrname << " ready to go again?" << endl;
			cin >> ready;

			cin.clear(); //clear and ignore cin
			cin.ignore();

			system("cls");

			//Increment the number of simulations ran counter
			++simulations;

			//Move program execution back up to // Display the simulation # is starting to the recruit. 

		}
		else if (simulations >= 3)
		{
			// Ask the recruit if they would like to run the simulation again
			char again;
			cout << usrname << " you've passed, but if you want to still practice you may. y/n" << endl;
			cin >> again;

			cin.clear(); //clear and ignore cin
			cin.ignore();

			system("cls");
			again = tolower(again);

			// If the recruit wants to run the simulation again
			if (again == 'y')
			{
				//Increment the number of simulations ran counter
				++simulations;

				return 100;
			}
			else if (again == 'n')
			{
				//Display End of Simulations to the recruit
				cout << "good job " << usrname << ". you are dismissed." << endl;
				cout << "ended at simulation number: " << simulations << endl;
				return 0;
			}
		}
	}

	// Otherwise 
	//     Pause the Simulation with press any key to continue

}

inline bool match(char letter, string word)
{
	return (word.find(letter) != string::npos);
}

char askGuess(string usedLettersStr)
{
	char guess;
	// Create an int var to count the number of simulations being run starting at 1

	cout << "simulation number: " << simulations << endl;
	//Move program execution back up to // Display the simulation # is starting to the recruit. 

	cout << "Enter your guess: ";
	cin >> guess;

	guess = tolower(guess); //make uppercase since secret word in uppercase
	//while (used.find(guess) != string::npos)
	while (match(guess, used))
	{

		//While recruit has entered a letter that he or she has already guessed
		cout << "You've already guessed " << guess << endl;

		//Get recruit's next guess
		cout << "Enter your guess: ";
		cin >> guess;
		guess = tolower(guess);
	}

	//If the guess is in the secret word
	//if (THE_WORD.find(guess) != string::npos)
	if (match(guess, The_word))
	{

		//Tell the recruit the guess is correct
		cout << "That's right! " << guess << " is in the word.\n";

		//Update the word guessed so far with the new letter
		for (int i = 0; i < The_word.length(); ++i)
			if (The_word[i] == guess)
				sofar[i] = guess;
	}
	//  Otherwise
	else
	{

		//      Tell the recruit the guess is incorrect
		cout << "Sorry, " << guess << " isn't in the word.\n";
		//Increment the number of incorrect guesses the recruit has made
		++wrong;
	}

	return guess;
}


//--------------------------------------------------------------------------------------
//blackjack

//vairables to represent my strings, explained more later.
struct Difinetraits
{
	//rrepresents the type
	string type;
	//represents the face of the card
	string value;
	//represents the value of the card
	int specialvalue;
	//represents the status of the card in or out of play
	int cardstatus;

} Deck[53];




int blackjack()
{

string types[4] = { "Clubs","Diamond","Spades","Hearts" };
string face[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
					"Nine", "Ten", "Jack", "Queen", "King" };
string status[3] = { "in play", "indeck", "discarded" };
int cardvalues[13] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

	//viarables
	int no;
	int yes;
	int hit;
	int stay;
	int New_face = 0;
	int dealt = 0;
	int values = 0;

	// turns the strings into a integers and randomizes the card that is pulled.
	for (int x = 0; x < 52; x++)
	{
		//randomizes the face pulled.
		Deck[x].value = face[New_face];
		//randomizes the type of card class, and connects the integer
		Deck[x].type = types[x % 13];
		//connects the integer and string
		Deck[x].specialvalue = cardvalues[x % 13];
		//keeps the cards status remembered so it doesn't duplicate. and connects the integer
		Deck[x].cardstatus = rand() % 3;
		//makes it start with all cards and then move to the next. stops repeating cards
		if ((x + 1) % 13 == 0)
			New_face++;
	}

	string card;

	//allows you to repeat
retry:
	cout << "ready? yes=1 or no=2" << endl;
	cin >> yes;
	if (yes == 1)
	{


		cout << "" << endl;
		cout << "Lets Begin." << endl;

		//limits the amount of play
		for (int j = 0; j < 2; j++)
		{
			//allows repeat
		again:
			cout << "player " << j + 1 << "' has " << endl;
			//limits the cards given
			for (int i = 0; i < 2; i++)
			{
				//keeps te status of the cards
				Deck[dealt].cardstatus = 0;
				cout << Deck[dealt].value << " of " << Deck[dealt].type << endl;
				//holds the values of the cards that are pulled.
				values += Deck[dealt].specialvalue;
				//makes it start with all cards and then move to the next.stops repeating cards.
				dealt++;
			}
			cout << "total: " << values << endl;
			cout << "hit? press 1, else 2 " << endl;
			cin >> hit;
			if (hit == 1)
			{
				goto again;
			}

			//statement that lets you win or lose.
			if (values == 21)
			{
				cout << "You Win!" << endl;
				cout << "play again? yes or no..." << endl;
				cin >> yes;

				if (yes == 1)
				{
					goto retry;
				}
				else (yes == 2);
				{
					return 0;
				}

			}
			else if (values > 21 || values < values)
			{
				cout << "You lose! try again?" << endl;
				cout << "play again? yes or no..." << endl;
				cin >> yes;

				if (yes == 1)
				{
					goto retry;
				}
				else (yes == 2);
				{
					return 0;
				}

			}

		}
	}
	else
		return 0;
};

//-------------------------------------------------------------------------------

//story games function
int life()
{
	string name;

	cout << "hey, enter your name" << endl;
	
	cin >> name;
	cout << "get up " << name << "! It's almost time for school!" << endl;

	cout << "hearing your mother, you hop out of bed and get dress. coming down stairs you see your sister on the couch and your mom at the table with breakfeast." << endl;



	int path;
	cout << "Do you eat breakfeast?" << endl;
	cout << "enter '1' to eat." << endl;
	cout << "enter '2' skip breakfeast." << endl;
retry: cout << "enter your choice ";
	cin >> path;

	if (path == 1)
	{
		cout << "Walking past your sister you see her get up and sit at the table, you have a delicious meal and get ready to leave." << endl;
		cout << "mother: bye anna, bye " << name << ". have a good day at school." << endl;
		cout << "waving back to your mom you and anna leave. after walking for a while anna sees her friends, and goes over to them. ";

		int path2;
		cout << "now that you were left alone, you considered whether to school." << endl;
		cout << "enter '1' go to school " << endl;
	reetry: cout << "enter your choice" << endl;
		cin >> path2;

		if (path2 == 1)
		{
			cout << "you've always gone to school why change it now?" << endl;
			cout << "you arrive at school and head for you class, on the way you notice your best friend ryran talking to someone in the hallway." << endl;
			cout << "ryran: " << name << ", what's up, did you see the new game thats coming out. it's sick, you want to go 50/50 on it?" << endl;
			cout << "No, you say firmly. ryran is annoyed but accepts that he has to wait to get yet another game." << endl;
			cout << "you head to class and sit down for lessons, you pay attention for a little but get board and start playing your phone?" << endl;
			cout << name << "!! startled by the sudden noise, you look up and see your teacher in front of you asking what you are doing. you tell her nothing and hide your phone. she doesn't believe you and has you come to the front of the class." << endl;


			int path3;
			cout << " " << endl;
			cout << "'answer this question if you were paying attention, what is 24 - 32 * 2'" << endl;
			cin >> path3;

			if (path3 == -40)
			{

				cout << "'hmph, it seems as if you were paying attention, go back to your seat.' you head back and sit down waiting for class to end." << endl;
				cout << "after a few classes pass, you head off to the cafiteria with your friend, ya'll sit down and eat while joking and messing around, it was a all around good time. lunch finishes and you have two classes before school ends. you arrive at PE class and and get changed, you come out and the teacher gives you a free day. as you look for something to do you see a couple guys about to play basketball, and your sister getting ready to play something with her friends." << endl;
				cout << " " << endl;

				int path5;
				cout << "you debate on whether you should play with your sister or play basketball." << endl;
				cout << "enter '1' play basketball" << endl;
				cout << "enter '2' play with sister" << endl;
				cout << "enter '3' play by your self" << endl;
			rreetry: cout << "enter your choice" << endl;
				cin >> path5;

				if (path5 == 1)
				{
					cout << "you head over to the group of guys and ask if you can play with them, they agree and the game starts. you score a few points in the beginning surprising even yourself, after a while your head and head, both teams only needing one more shot to win. you pass the ball to one of your teammates while running to the right to set yourself up, but there was no need as your teammate drives the ball in and lands a dunk. you celebrate and praise him for his skills, after you shoot a few hoops for a while till class ends." << endl;
					cout << "once class is done you get changed and go to your last class, you sit by the window and class passes in a breeze. once class ends you leave." << endl;
					cout << "you go hangout with your friends for a little playing games and talking. once it starts to get dark you head home texting your sister to get you a green tea from the store, she telss you 'fine, but your paying me back,' 'obviously' you reply." << endl;
					cout << "you enter the house and your sister hands you the drink saying, 'here' you take it thanking here and head of to your room. you watch tv for a while, until you here your mom. " << name << "!! come down and eat dinner your mom yells. you head down stairs and sit at the dinner table. you eat with your family and talk about your day. after you go to bed and end your day." << endl;
				}
				else if (path5 == 2)
				{
					cout << "you tell yourself that you should hang out with your sister sometimes and walk over to her and ask if you an play with them, she says whatever and that she doesn't care. you team up with your sisters's friend and begin, you are doing ok in the beginning, but soon get your butt handed to you by the other team. after the devistating loss you talk with your sister and friends, while watching some videos on your phone. class soon ends and you all get dressed and leave to your last classes. you sit by the window waiting for class to end, and once it does you leave." << endl;
					cout << "you go hangout with your friends for a little playing games and talking. once it starts to get dark you head home texting your sister to get you a green tea from the store, she telss you 'fine, but your paying me back,' 'obviously' you reply." << endl;
					cout << "you enter the house and your sister hands you the drink saying, 'here' you take it thanking here and head of to your room. you watch tv for a while, until you here your mom. " << name << "!! come down and eat dinner your mom yells. you head down stairs and sit at the dinner table. you eat with your family and talk about your day. after you go to bed and end your day." << endl;
				}
				else if (path5 == 3)
				{
					cout << "you don't feel like playing with anyone you'd rather play your phone alone, so when the teacher isn't looking you sneak behind the bleachers and sit down playing your phone." << endl;
					cout << "you decide to play a guessing game, you need to guess the correct number of the card." << endl;
					blackjack();
					cout << "some time passes and you feel as though you are finally getting to yourself until you hear a girls voice from above." << endl;
					cout << "'what are you doing.'" << endl;
					cout << "you look up and see that it's jess one of the girls from your friend group. you tell her to get down, and she does so coming over to the hiding spot. you explain that you are just playing your phone and that you wanted some alone time. she ignores you subtlely telling her to leave and insteads tells you to play this online game with her, reluictantly you agree and time pass quickly. you get ready to leave and tell jess that you will meet them after school with the rest of the gang and then head off." << endl;
					cout << "once class is done you get changed and go to your last class, you sit by the window and class passes in a breeze. once class ends you leave and meet up with jess." << endl;
					cout << "you both go hangout with your friends for a little playing games and talking. once it starts to get dark you head home texting your sister to get you a green tea from the store, she telss you 'fine, but your paying me back,' 'obviously' you reply." << endl;
					cout << "you enter the house and your sister hands you the drink saying, 'here' you take it thanking here and head of to your room. you watch tv for a while, until you here your mom. " << name << "!! come down and eat dinner your mom yells. you head down stairs and sit at the dinner table. you eat with your family and talk about your day. after you go to bed and end your day." << endl;
				}
				else
				{
					cout << "wrong, try again" << endl;
					goto rreetry;
				}
			}
			else
			{
				cout << "'so you weren't paying attention, give me your phone you won't be getting it back until the end of school.' reluctantly you hand your phone and sit back down waiting for class to end." << endl;
				cout << "after a few classes pass, you head off to the cafiteria with your friend, ya'll sit down and eat while joking and messing around, it was a all around good time, or at least it would have been if your teacher didn't take your phone. a few friends say your over reacting aand that you'll get it at the end of the day, but your still annoyed that it was taken at all. lunch finishes and you have two classes before school ends. you arrive at PE class and and get changed, you come out and the teacher gives you a free day. as you look for something to do you see a couple guys about to play basketball, and your sister getting ready to play something with her friends." << endl;


				int path4;
				cout << "you debate on whether you should play with your sister or play basketball." << endl;
				cout << "enter '1' play basketball" << endl;
				cout << "enter '2' play with sister" << endl;
				cout << "enter '3' play by your self" << endl;
			rretry: cout << "enter your choice" << endl;
				cin >> path4;

				if (path4 == 1)
				{
					cout << "you head over to the group of guys and ask if you can play with them, they agree and the game starts. you score a few points in the beginning surprising even yourself, after a while your head and head, both teams only needing one more shot to win. you pass the ball to one of your teammates while running to the right to set yourself up, but there was no need as your teammate drives the ball in and lands a dunk. you celebrate and praise him for his skills, after you shoot a few hoops for a while till class ends." << endl;
					cout << "once class is done you get changed and go to your last class, you sit by the window and class passes in a breeze. you leave and head for your maths teacher asking for your phone back, she hands it to you and tells you not to let it happen again. you pay no mind and hurry outside." << endl;
					cout << "you go hangout with your friends for a little playing games and talking. once it starts to get dark you head home texting your sister to get you a green tea from the store, she telss you 'fine, but your paying me back,' 'obviously' you reply." << endl;
					cout << "you enter the house and your sister hands you the drink saying, 'here' you take it thanking here and head of to your room. you watch tv for a while, until you here your mom. " << name << "!! come down and eat dinner your mom yells. you head down stairs and sit at the dinner table. you eat with your family and talk about your day making sure to leaving out the fact that you got in trouble with the teacher. after you go to bed and end your day" << endl;
				}
				else if (path4 == 2)
				{
					cout << "you tell yourself that you should hang out with your sister sometimes and walk over to her and ask if you an play with them, she says whatever and that she doesn't care. you team up with your sisters's friend and begin, you are doing ok in the beginning, but soon get your butt handed to you by the other team. after the devistating loss you talk with your sister and friends, while also playing a couple more games. class soon ends and you all leave to your classes. you sit by the window waiting for class to end, and once it does you leave and head for your maths teacher asking for your phone back, she hands it to you and tells you not to let it happen again. you pay no mind and hurry outside." << endl;
					cout << "you go hangout with your friends for a little playing games and talking. once it starts to get dark you head home texting your sister to get you a green tea from the store, she telss you 'fine, but your paying me back,' 'obviously' you reply." << endl;
					cout << "you enter the house and your sister hands you the drink saying, 'here' you take it thanking here and head of to your room. you watch tv for a while, until you here your mom. " << name << "!! come down and eat dinner your mom yells. you head down stairs and sit at the dinner table. you eat with your family and talk about your day making sure to leaving out the fact that you got in trouble with the teacher. after you go to bed and end your day" << endl;
				}
				else if (path4 == 3)
				{
					cout << "you decided to not play with anyone and instead wonder around doing a multitude of differenrt things. at first you jogged around the gym, once you got bored of that, you grabbed a soccer ball and began kicking it around, after a while of randomness class ends." << endl;
					cout << "once class is done you get changed and go to your last class, you sit by the window and class passes in a breeze. you leave and head for your maths teacher asking for your phone back, she hands it to you and tells you not to let it happen again. you pay no mind and hurry outside." << endl;
					cout << "you go hangout with your friends for a little playing games and talking. once it starts to get dark you head home texting your sister to get you a green tea from the store, she tells you 'fine, but your paying me back,' 'obviously' you reply." << endl;
					cout << "you enter the house and your sister hands you the drink saying, 'here' you take it thanking here and head of to your room. you watch tv for a while, until you here your mom. " << name << "!! come down and eat dinner your mom yells. you head down stairs and sit at the dinner table. you eat with your family and talk about your day making sure to leaving out the fact that you got in trouble with the teacher. after you go to bed and end your day" << endl;
				}
				else
				{
					cout << "wrong, try again" << endl;
					goto rretry;
				}
			}

		}
		else
		{
			cout << "wrong, try again" << endl;
			goto reetry;
		}

	}

	else if (path == 2)
	{
		cout << "you tell your mom that your not hungry and sit down waiting for your sister to finish eating" << endl;
		cout << "Don't cry to me when your hungry at school, your mother says. ignoring here remark you grab your bookbag and make for the door with your sister, saying bye to your mom as you leave." << endl;
		cout << "mother: bye anna, bye " << name << ". have a good day at school." << endl;
		cout << " waving back to your mom, you and anna left, after walking for a while anna saw her friends, and went over to them.";

		int path2;
		cout << "now that you were left alone, you considered whether to school." << endl;
		cout << "enter '1' go to school " << endl;
	reeetry: cout << "enter your choice" << endl;
		cin >> path2;

		if (path2 == 1)
		{
			cout << "you've always gone to school why change it now?" << endl;
			cout << "you arrive at school and head for you class, on the way you notice your best friend ryran talking to someone in the hallway" << endl;
			cout << "ryan: " << name << ", what's up, did you see the new game thats coming out. it's sick, you want to go 50/50 on it?" << endl;
			cout << "Nah, you say firmly. ryan is annoyed but accepts that he has to wait to get yet another game" << endl;
			cout << "you head to class and sit down for lessons, you pay attention for a little but get bored and start playing your phone?" << endl;
			cout << name << "!! startled you look up and see your teacher in front of you asking what you are doing. you tell her you're doing nothing and hide your phone. she doesn't beleve you and has you come to the front of the class." << endl;


			int path3;
			cout << "'answer this question if you were paying attention, what is 24 - 32 * 2" << endl;
			cin >> path3;

			if (path3 == -40)
			{

				cout << "'hmph, it seems as if you were paying attention, go back to your seat.' you head back and sit down waiting for class to end." << endl;
				cout << "after a few classes pass, you head off to the cafiteria with your friend, ya'll sit down but you don't eat or at least you can't, since your stumach hurts after just one bite, instead you sit with your friends and talk while occasionally playing your phone." << endl;
				cout << " once lunch was over you head to PE class and get changed, oncee you come out the " << endl;

				int path5;
				cout << "you debate on whether you should play with your sister or play basketball." << endl;
				cout << "enter '1' play basketball" << endl;
				cout << "enter '2' play with sister" << endl;
				cout << "enter '3' play by your self" << endl;
			Rreetry: cout << "enter your choice" << endl;
				cin >> path5;

				if (path5 == 1 || 2 || 3)
				{
					cout << "just as your about to chose you get hit by an unbearable pain. no one seems to notice so you reach for your phone and call your mom, you tell her that its happening again" << endl;
					cout << "'what did I tell you, stop acting stuborn all the time, get your sister I'll be there soon,' she says then hangs up. a teacher walks over and asks if somethings wrong you tell them no and try to get away." << endl;
					cout << "you head to your sister and get her attention, she asks what's wrong feeling worried, and just right before you speak everything goes black." << endl;
					cout << "  " << endl;
					cout << "  " << endl;
					cout << "you awake to find that your back at home in your room. your mom enters with a plate of food and says, 'you want try that again?' no you reply, 'that's what I thought, now eat this and go back to sleep you won't be going to school tomorrow." << endl;
					cout << "you eat the food then go to sleep hoping that it won't appear in your dreams." << endl;
				}
				else
				{
					cout << "wrong, try again" << endl;
					goto Rreetry;
				}
			}

			else
			{
				cout << "'so you weren't paying attention, give me your phone you won't be getting it back until the end of school.' reluctantly you hand your phone and sit back down waiting for class to end." << endl;
				cout << "after a few classes pass, you head off to the cafiteria with your friend, ya'll sit down but you don't eat or at least you can't, since your stumach hurts after just one bite, so instead you just talk with your friends and have a good time or at least it would have been if your teacher didn't take your phone. a few friends say your over reacting aand that you'll get it at the end of the day, but your still annoyed that it was taken at all. lunch finishes and you have two classes before school ends. you arrive at PE class and and get changed, you come out and the teacher gives you a free day. as you look for something to do you see a couple guys about to play basketball, and your sister getting ready to play something with her friends." << endl;

				int path4;
				cout << "you debate on whether you should play with your sister or play basketball." << endl;
				cout << "enter '1' play basketball" << endl;
				cout << "enter '2' play with sister" << endl;
				cout << "enter '3' play by your self" << endl;
			Reetry: cout << "enter your choice" << endl;
				cin >> path4;

				if (path4 == 1 || 2 || 3)
				{
					cout << "just as your about to chose you get hit by an unbearable pain. no one seems to notice so you reach for your phone, but remember that it was taken from you, the pain gets worse and worse as time passes and soon you pass out." << endl;
					cout << "  " << endl;
					cout << "  " << endl;
					cout << "you awake to find that your back at home in your room. your mom enters with a plate of food and says, 'you want try that again?' 'no' you reply, 'that's what I thought, now eat this and go back to sleep you won't be going to school tomorrow. also don't forget to thank your sister forgeting you home before that happened." << endl;
					cout << "you eat the food then go to sleep hoping that it won't appear in your dreams." << endl;

				}
				else
				{
					cout << "wrong, try again" << endl;
					goto Reetry;
				}
			}

		}

		else
		{
			cout << "wrong, try again" << endl;
			goto reeetry;
		}


	}

	else
	{
		cout << "wrong, try again" << endl;
		goto retry;
	}


	cout << "chapter 1: end" << endl;

	return 0;
}
