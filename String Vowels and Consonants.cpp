//This program will have the user enter a string and will calculate the number of vowels and or consonants
//Pedro Ayala
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int SIZE = 80;    //max size of the string

int NumVowels (char *, int);            //function to get num of vowels
int NumConsonants (char *, int);        //function to get num of consonants
char SecondIn (char *);                 //function to get another input

int main()
{
    char input[SIZE];    //input array
    char response;       //menu select variable

    int numVow = 0;     //counter for vowels
    int numCon = 0;     //counter for consonants

    bool running = true;    //boolean to keep the program running

    char *ptr = 0;             //initialize pointer
    ptr = new char[SIZE];

    //user inputs string
    cout << "Enter a string: ";         //
    cin.getline (input, SIZE);          //
    int length = strlen(input);         //get length of string
    ptr = input;                        //assign input to pointer

    do
    {   ////////////////////////
        ////  Menu select  ////
        //////////////////////
        cout << " " << endl;
        cout << "A.  Count the number of vowels in the string" << endl;
        cout << "B.  Count the number of consonants in the string" << endl;
        cout << "C.  Count both the vowels and consonants in the string" << endl;
        cout << "D.  Enter another string" << endl;
        cout << "E.  Exit the program" << endl;
        cin >> response;    //user input

        //conditionals for upper and lower case responses
        if (response == 'A' or response == 'a')
        {
            numVow = NumVowels (ptr, length);   //call function to count vowels returning an int
            cout << "Number of vowels in the string: " << numVow << endl;
        }
        else if (response == 'B' or response == 'b')
        {
            numCon = NumConsonants (ptr, length);   //call function to count consonants returning an int
            cout << "Number of consonants in the string: " << numCon << endl;
        }
        else if (response == 'C' or response == 'c')
        {
            numVow = NumVowels (ptr, length);   //call function to count vowels returning an int
            cout << "Number of vowels in the string: " << numVow << endl;
            numCon = NumConsonants (ptr, length);   //call function to count consonants returning an int
            cout << "Number of consonants in the string: " << numCon << endl;
        }
        else if (response == 'D' or response == 'd')
        {
            *ptr = SecondIn(ptr);   //assign input to pointer from a function to get another input
            length = strlen(ptr);   //get length of string
        }
        else if (response == 'E' or response == 'e')
        {
            running = false;    //if press E exit loop
        }
        else
        {
            cout << "Response is invalid" << endl;  //input check for loop
        }
    }
    while (running == true);    //if running loop program

	return 0;
}

//////////////////////////////////////////////
////  function to get number of vowels  /////
////////////////////////////////////////////
int NumVowels (char *ptr, int length)
{
    int numVow = 0;     //counter for vowels

    //list of possible vowels
    char vowels[10] = {'a', 'A', 'e', 'E', 'i', 'I' ,'o', 'O' , 'u', 'U'};

    //loop to find number of vowels
    for (int i = 0; i < length; i++)
    {
        if (isalpha(ptr[i]))    //check if character is a letter
        {
            for (int x = 0; x < 10; x++)    //loop to go through each vowel possibility per character
            {
                if (ptr[i] == vowels[x])    //check if character is a vowel
                {
                    numVow++;   //increment vowels counter
                }
            }
        }
    }

    return numVow;  //return number of vowels
}

/////////////////////////////////////////////////
////  function to get number of consonants  ////
///////////////////////////////////////////////
int NumConsonants (char *ptr, int length)
{
    int numCon = 0;     //counter for consonants

    //list of possible vowels, I will use vowels because there are
    //less vowels than consonants to check through
    char vowels[10] = {'a', 'A', 'e', 'E', 'i', 'I' ,'o', 'O' , 'u', 'U'};

    //loop to find number of consonants
    for (int i = 0; i < length; i++)
    {
        if (isalpha(ptr[i]))    //check if character is a letter
        {
            //check if not a vowel
            if (ptr[i] != 'a' and ptr[i] != 'A' and ptr[i] != 'e' and ptr[i] != 'E' and ptr[i] != 'i' and ptr[i] != 'I' and ptr[i] != 'o' and ptr[i] != 'O'  and ptr[i] != 'u' and ptr[i] != 'U')
            {
                numCon++;   //increment consonants counter
            }
        }
    }

    return numCon;  //return number of consonants
}

//////////////////////////////////////////
////  function to get another input  ////
////////////////////////////////////////
char SecondIn (char *ptr)
{
    char input[SIZE];    //input array

    //user inputs string
    cout << "Enter another string: ";
    cin.getline (input, SIZE);      //this get line does not read spaces therefore unable to put spaces in the input
    cin.getline (input, SIZE);      //and skips input entirely. So I put it twice to be able to input but you still can't put spaces
    ptr = input;    //assign input to pointer

    return *ptr;    //return pointer to main
}

