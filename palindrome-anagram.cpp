/*  
	 *Password: securekey123
	 *Programmer: SANTECO, Enrique S.
	 *Date Created: 4/9/2024
	 *Terminal No: 34
	 *Program: BMCS
	 *Course / Section: CSS122L/BM1
*/

#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;

#include<conio.h>
#include<windows.h>
string sort(string str);//reaaranging the orders of string to test if its anagram
bool areAnagrams(string str1,string str2);//process the strgin if anagram anf returns the value 1 or 0
string RemSpacePunct(string str);//function that removes space and punctation in aa string

////////////////////////////////

void palindrome(char sal[120]);//testing whether the c-string value is palindrome or not
void password();//asking the user to enter the password
char menu();//displaying choices a,b, and c then returns the answer
void quit();//asking the user if he/she wants to quit
string EnterPassword();//processing if the password is correct and diplaying it with "*" sign

int main()
{
    char let, ans;
    cout << "Enter Password: ";
    password(); // Call password function for entering password

    do
    {
        ans = menu(); // Display the menu

        switch (ans)
        {
        case 'a':
        {
            char word[120] = "placeholder";
            palindrome(word); // Function for Palindrome
        }
        break;

        case 'b':
        {
            string str1, str2;
            cout << "[b] Check if strings are Anagram" << endl;
            cout << "Testing whether the following strings are anagrams:" << endl;

            cout << "Enter String 1: ";
            cin >> str1;
            cout << "Enter String 2: ";
            cin.ignore();
            getline(cin, str2);

            cout << "String 1: " << str1 << endl;
            cout << "String 2: " << str2 << endl;

            if (areAnagrams(str1, str2)) // Function for Anagrams
                cout << "They are anagrams" << endl;
            else
                cout << "They are NOT anagrams" << endl;
        }
        break;

        case 'c':
        {
			cout << "Goodbye.";
            quit();
        }
        break;
        }

        do
		{
		    cout << "Do you want to try again [y/n]" << endl;
		    cout << "Choice: ";
		    cin >> let;
		    let = tolower(let);
		    	if (let == 'y')
		    	system("cls"); // Clear the screen
		} while (let != 'n' && let != 'y');
		
    } while (let == 'y');
    system("pause");

    return 0;
}

void quit()
{
    exit(0);
}

string EnterPassword()
{
    string password;
    char c;
    while ((c = _getch()) != '\r')
    {
        if (c == '\b' && password.length() > 0)
        {
            cout << "\b \b";
            password.erase(password.length() - 1); // Erase the last character
        }
        else if (c != '\b')
        {
            cout << "*";
            password.push_back(c);
        }
    }
    cout << endl;
    
    return password;
}

char menu()
{
    char choice;

    cout << "[a] Check the Palindrome" << endl;
    cout << "[b] Testing if strings are Anagrams" << endl;
    cout << "[c] Quit" << endl;
    cout << "Your choice: ";
    cin >> choice;

    return choice;
}

void password()
{
    const int maxAttempts = 3;
    int attempts = 0;
    string pass;
    
    do
    {
        pass = EnterPassword();
        if (pass != "securekey123")
        {
            cout << "Sorry incorrect password" << endl;
            attempts++;
            if (attempts == maxAttempts)
            {
                cout << "You have reached the maximum attempt for password." << endl;
                quit();
            }
        }
    } while (pass != "securekey123"); 
}

string sort(string str)
{
    sort(str.begin(), str.end());

    return str;
}

bool areAnagrams(string str1, string str2)
{
    str1 = sort(RemSpacePunct(str1));
    str2 = sort(RemSpacePunct(str2));
    
    return str1 == str2;
}

string RemSpacePunct(string str)
{
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
    
    return str;
}

void palindrome(char sal[120])
{
    cout << "[a] Check the palindrome" << endl;
    cout << "Input a word: ";
    cin >> sal;
    char temp[120];
    
    for (int i = 0; i < 120; i++)

        temp[i] = sal[i];

    strrev(sal);
    
    cout << "In reverse order: " << sal << endl;

    int result = strcmp(temp, sal);

    if (result == 0)
    {
        cout << "The word is a palindrome!" << endl;
    }

    else
    {
        cout << "The word is not a palindrome!" << endl;
    }
}
