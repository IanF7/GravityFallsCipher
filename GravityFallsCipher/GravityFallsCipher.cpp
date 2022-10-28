#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int main()
{
	//takes input from user
	string input = "";
	//stores letters for inputing them into decipher vector
	string output = "";
	//stores each word in original text
	vector<string> encryption;
	//stores each letter of original text
	vector<string> decipher;
	bool cont = true;
	//prompts user to enter cipher
	cout << "Enter the cipher and enter done to continue: " << endl;
	//while the user has not entered done, it will add values to the encryption vector
	while (cont)
	{
		//takes in input
		cin >> input;
		//if input = done, stops loop
		if (input == "done")
		{
			cont = false;
		}
		//otherwise adds value to most current value of encryption
		else
		{
			encryption.push_back(input);
		}
	}
	//runs through every word in encryption and separates each letter by dashes
	for (int i = 0; i < encryption.size(); i++)
	{
		//sets val equal to the current value of encryption
		string val = encryption[i];
		//runs another for loop that runs through every character in val
		for (int j = 0; j < val.length(); j++)
		{
			//if val is a dash, sets the current value of output to the next value in decipher
			if (val[j] == '-')
			{
				decipher.push_back(output);
				output = "";
			}
			//otherwise it adds the value to output string
			else
			{
				output.push_back(val[j]);
			}
			//if j hits the end of val, sets output to next value in decipher
			if (j == val.length() - 1)
			{
				decipher.push_back(output);
				output = "";
			}
		}
		//adds a space in between each word
		decipher.push_back(" ");
	}
	//creates int  num to store numeric values of letters
	int num = 0;
	//changes each item in decipher from a number to a letter
	for (int i = 0; i < decipher.size(); i++)
	{
		//if value is a space, outputs value
		if (decipher[i] == " ")
		{
			cout << decipher[i];
		}
		//otherwise decrypts value by converting value into an int and then decrypting and
		//outputs end result
		else
		{
			num = 27 - (stoi(decipher[i]) + 3);
			if (num <= 0)
			{
				num += 26;
			}
			num += 96;
			cout << char(num);
		}
	}
}
