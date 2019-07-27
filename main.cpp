#include "Person.h"

using namespace std;

// If you are using Linux, set bLinux = true;
const bool bLinux = false;

void pauseConsole();
void clearConsole();
void readMainArguments(int argc, char** argv);
void getFileArgument(int argc, char** argv, string &filename);
int showMenu();

int main(int argc, char** argv) 
{
	int i, j; 
	ifstream inFile;
	string filename;

	vector<Person> people_list;
	vector<Person> chosen_list;

	readMainArguments(argc, argv);
	getFileArgument(argc, argv, filename);

	inFile.open(filename.c_str());
	if(inFile.is_open())
	{
		string firstName;
		string lastName;
		char gender;
		int birthYear;
		int birthMonth;
		int birthDay;

		while(inFile >> firstName >> lastName >> gender >> birthYear >> birthMonth >> birthDay)
		{
			people_list.push_back(Person(firstName, lastName, gender, birthYear, birthMonth, birthDay));
		}

		inFile.close();
	}
	else
	{
		cerr << "Error : Cannot locate the input file '" << filename.c_str() << "'. Program cannot continue. . .\n";
		pauseConsole(); return 0;
	}
	
	bool bQuit = false;
	while(bQuit == false)
	{
		int choice = showMenu();
		switch(choice)
		{
			case 1 : 
			{
				int peopleFound;
				string lastName;
				cout << "+ Please enter a person's last name : "; cin >> lastName;

				peopleFound = 0;
				for(i = 0; i < people_list.size(); i++)
				{
					if(people_list[i].findName(lastName) == lastName)
					{
						// Avoid duplicate
						for(j = 0; j < (int)chosen_list.size(); j++)
						{
							if(chosen_list[j].getLastName() == lastName && chosen_list[j].getFirstName() == people_list[i].getFirstName()) break;
						}

						if(j == chosen_list.size()) chosen_list.push_back(people_list[i]);
			
						cout << "Found '" << people_list[i].getFirstName() << " " << people_list[i].getLastName() << "'" << endl;
						cout << "+ Name : " << people_list[i].getFirstName() << " " << people_list[i].getLastName() << endl;
						cout << "+ Gender : " << people_list[i].getGender() << endl;
						cout << "+ Birth date : " << people_list[i].getBirthDay() << "/" << people_list[i].getBirthMonth() << "/" << people_list[i].getBirthYear() << endl << endl;

						peopleFound++;
					}
				}

				if(peopleFound == 0)
				{
					cout << "+ Cannot find a person with the last name being " << lastName << ". Please try again\n\n";
				}
				pauseConsole();
			}
			break;
			case 2 : 
			{
				cout << "All person's information you have entered : " << endl;
				if(chosen_list.size() > 0)
				{
					for(i = 0; i < (int)chosen_list.size(); i++)
					{
						cout << i + 1 << ". " << chosen_list[i].getLastName() << endl;
						cout << "+ Name : " << chosen_list[i].getFirstName() << " " << chosen_list[i].getLastName() << endl;
						cout << "+ Gender : " << chosen_list[i].getGender() << endl;
						cout << "+ Birth date : " << chosen_list[i].getBirthDay() << "/" << chosen_list[i].getBirthMonth() << "/" << chosen_list[i].getBirthYear() << endl << endl;
					}
				}
				else
				{
					cout << "Sorry, there is no entry entered at the moment. Please try at a later time\n\n";
				}

				cout << "Please press any key to return to our Menu. . ."; 
				cin.ignore();
				cin.get();
			}
			break;
			case 3 : 
			{
				bQuit = true;
			}
			break;
		}
	}

	cout << endl;
	cout << "Thank you for using our program. . .\n";
	pauseConsole();

	return 0;
}

void pauseConsole()
{
	if(bLinux == true)
	{
		cout << "Please press any key to continue. . .";
		cin.ignore(); cin.get();
	}
	else
	{
		system("pause");
	}
}

void clearConsole()
{
	const char *clearCommand = (bLinux) ? "clear" : "cls";
	system(clearCommand);
}

int showMenu()
{
	int choice;
	clearConsole();

	cout << "1. Enter person's information\n";
	cout << "2. Print out person's information\n";
	cout << "3. Exit\n\n";

	while(true)
	{
		cout << "Enter choice : "; cin >> choice;
		if(choice >= 1 && choice <= 3) return choice;

		if(!cin)
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "You have entered an invalid choice. Please try again\n\n";
	}
}

void readMainArguments(int argc, char** argv)
{
	int i;
    cout << "Have " << argc << " argument(s) : " << endl;

    for (i = 0; i < argc; i++) 
	{
        cout << argv[i] << endl;
    }
	cout << endl;
}

void getFileArgument(int argc, char** argv, string &filename)
{
	if(argc == 2)
	{
		filename = argv[1];
	}
	else
	{
		cout << "The second argument not found. The default input file will be \"Input.txt\"" << endl;
		filename = "Input.txt";
	}
}