// week04assignment.cpp : Returns the amount of vowels in a document passed to it from the command line
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//declare constants
const int WIDTH = 75;
const string STR1 = "Welcome to my Letter Count Program ";
const string STRA = "The number of A's: ";
const string STRE = "The number of E's: ";
const string STRI = "The number of I's: ";
const string STRO = "The number of O's: ";
const string STRU = "The number of U's: ";
const string STRD = "The number of D's: ";
const string STRJ = "The number of J's: ";
const string STRC = "The number of C's: ";
const string STR2 = "The vowel count is: ";


int main(int argc, char* argv[])
{	//the exe name is the first arg, desired document the second
	if (argc < 2)
	{
		cout << "Error with amount of args.." << endl;
		return 1;
	}
	//create variable of file, open the parameter passed from the console
	ifstream iFile;
	iFile.open(argv[1]); 
	if (!iFile) // is the file open? t/f
	{
		cout << "Error with file name.." << endl;
		return 1;
	}
	char c; // each letter in the file that will be read
	int iVowelCount = 0,
		totalA = 0,
		totalE = 0,
		totalI = 0,
		totalO = 0,
		totalU = 0,
		totalD = 0,
		totalJ = 0,
		totalC = 0;
	
	
	while (iFile.get(c)) // while there are still characters in the file...
	{
		switch (toupper(c)) // to avoid much redundancy
		{
		case 'A':
			totalA++;
			iVowelCount++;
			break;
		case 'E':
			totalE++;
			iVowelCount++;
			break;
		case 'I':
			totalI++;
			iVowelCount++;
			break;
		case 'O':
			totalO++;
			iVowelCount++;
			break;
		case 'U':
			totalU++;
			iVowelCount++;
			break;

		case 'D':
			totalD++;
			break;
		case 'J':
			totalJ++;
			break;
		case 'C':
			totalC++;
			break;
		}
	}
	//use format manipulators to beautify the console
	cout << setfill('*') << setw(WIDTH) << ' ' << endl; 
	cout << setw((WIDTH /2)- (STR1.length()/2)) << ' ' << STR1 << setw((WIDTH/2) - (STR1.length()/2)) << " " << endl;
	cout << setw(WIDTH) << ' ' << endl;

	cout << "\n";
	cout << "Analyzing file " << argv[1] << "..." << endl;
	cout << "\n";

	// display the results to the user
	cout << STRA << setfill('.') << setw(WIDTH - STRA.length()) << "." << totalA << endl;
	cout << STRE << setw(WIDTH - STRE.length()) << "." << totalE << endl;
	cout << STRI << setw(WIDTH - STRI.length()) << "." << totalI << endl;
	cout << STRO << setw(WIDTH - STRO.length()) << "." << totalO << endl;
	cout << STRU << setw(WIDTH - STRU.length()) << "." << totalU << endl;
	cout << STRD << setw(WIDTH - STRD.length()) << "." << totalD << endl;
	cout << STRJ << setw(WIDTH - STRJ.length()) << "." << totalJ << endl;
	cout << STRC << setw(WIDTH - STRC.length()) << "." << totalC << endl;
	cout << STR2 << setw(WIDTH - STR2.length()) << "." << iVowelCount << endl;


	system("pause");
	iFile.close();

	return 0;
}

