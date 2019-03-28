#include <string>
#include "GenStack.h"
#include <iostream>
#include <fstream>


using namespace std;

int main(int argc, char **argv)
{

	string line;
	int count;


	GenStack<int, 10> l1; // Track start of delimeter
	GenStack<char, 10> c1; //Track delimeter characters

	ifstream inputStream;

	count = 0;

	inputStream.open(argv[1]);
	if(inputStream.good())
	{
		while(getline(inputStream, line))
		{
			count++;
			for(int i = 0; i < line.length(); ++i)
			{
				if(line[i] == '[' || line[i] == '{' || line[i] == '(')
				{		//Pushes start delimeters onto stack
					c1.push(line[i]);
					l1.push(count);
				}
				else if (line[i] == '}')
				{
					if(line[i] == '}' && c1.top() == '{')
					{
						c1.pop();
						l1.pop();
					}
					else if(line[i] == '}' && c1.top() != '{'){
						cout << "Missing delimeter for " << line[i] << " at line " << count;
						exit(1);
					}
				}

				else if(line[i] == ']')
				{
					if(line[i] == ']' && c1.top() == '[')
					{
						c1.pop();
						l1.pop();
					}
					else if(line[i] == ']' && c1.top() != '[')
					{
						cout << "Missing delimeter for "<< line[i] << " at line " << count;
						exit(1);
					}
				}
				else if(line[i] == ')'){
					if(line[i] == ')' && c1.top() == '(')
					{
						c1.pop();
						l1.pop();
					}
					else if(line[i] == ')' && c1.top() != '(')
					{
						cout << "Missing delimeter for " << line[i] << " at line " << count;
						exit(1);
					}
				}
			}
		}
		inputStream.close();
	}

	while(!c1.empty())
	{		//if stack is still full after transversing input, returns latest delimeter error
		cout << "Missing delimeter for " << c1.pop() << " at line " << l1.pop();
                exit(1);
	}


	return 0;
}
