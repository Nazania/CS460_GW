//Authors: Nazania Barraza, Ashley Lopez
//Team V
//Project 1
#include <iomanip>
#include <cstdlib>
#include "LexicalAnalyzer.h"

using namespace std;

//static string token_names[] = { "EOF_T" };
static string token_names[] = {	"ERROR_T", "MINUS_T", "NUMLIT_T", "PLUS_T", "IDKEY_T", "LISTOP_T", "EQUALTO_T", "GTE_T", "GT_T", "LTE_T", "LT_T", "MULT_T", "DIV_T", "LPAREN_T", "RPAREN_T", "QUOTE_T",  "EOF_T" };

LexicalAnalyzer::LexicalAnalyzer (char * filename)
{ // This function will initialize the lexical analyzer class
  input.open(filename);
  listing.open("TeamV.lst");
  debug.open("TeamV.gdb");
  token = NONE_T;
  line = "";
  linenum = 1;
  pos = 0;
  lexeme = "";
  errors = 0;
  datacont = ' ';
}

LexicalAnalyzer::~LexicalAnalyzer ()
{ // This function will complete the execution of the lexical analyzer class
  input.close();
  listing.close();
  debug.close();
  token = NONE_T;
  line = "";
  linenum = 0;
  pos = 0;
  lexeme = "";
  errors = 0;
  datacont = ' ';
}

token_type LexicalAnalyzer::GetToken ()
{ // This function will find the next lexeme int the input file and return the token_type value associated with that lexeme
  char data = ' ';

  if(input.eof())
    {// new problem, errors are incrementing wrong, its too many or correct need to fix
      listing << "There are " << errors << " in this file." << endl;
	cout << errors << "in input.eof first if statement " << endl;
      return EOF_T;
    }
//if the data is continuing then make token be what ever this spot is representing in
//the matrix
  if(datacont != ' ' && datacont != '\n')
  {// something wrong with this if statement,
	// supposed to go in here if it is continuing 
      token = checkMatrix(datacont, 0);
      cout << errors << "  Errors in if statement 2" << endl;
  }
  else
    {
      input.get(data);
      line+= data;
      token = checkMatrix(data, 0);
	cout << errors << "  Errors in the else statement 2" << endl;
    }
  while (token == ENDL_T)
//while loop formats the ending state while it reads the file
//this is why the .lst file has what it has in it with the line numbers
    {
      listing << linenum << ": " << line;
      linenum++;
      line = "";
      token = checkMatrix(datacont, 0);
	cout << errors << "in while loop for token == ENDL_T" << endl;
    }
//it grabs the token
  if(token == ERROR_T)
  {// thinks the '?' is an error even when it is attached to a word 
    cout << errors << " before incrementing the errors variable" << endl;
    errors++;
    cout << errors<< " incrementing if statement that keeps track of errors" << endl;	
  }
  return token;
}

token_type LexicalAnalyzer::checkMatrix(char c, int oldstate)
{
  float m[30][22] = {{16.2,18.2,20.2,22.2,23.2,23.2,26.2,23.2,23.2,23.2,6.0,29.2,17.2,11.0,12.0,13.0,14.0,15.0,-1.0,0.0,0.0, -2.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0, -1.0},
		     {1.1,18.2,20.2,1.1,1.1,1.1,1.1,1.1,1.1,1.1,1.1,1.1,1.1,1.1,1.1,1.1,1.1,1.1,1.0,1.1,1.1,1.1},
		     {10.1,10.1,10.1,10.1,10.1,10.1,10.1,10.1,10.1,10.1,9.0,10.1,10.1,10.1,10.1,10.1,10.1,10.1,10.0,10.1,10.1,10.1},
		     {0.1,0.1,19.2,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.0,0.1,0.1,0.1},
		     {2.1,2.1,19.2,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.0,2.1,2.1,2.1},
		     {2.1,21.2,20.2,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.0,2.1,2.1,2.1},
		     {2.1,2.1,19.2,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.0,2.1,2.1,2.1},
		     {3.1,18.2,20.2,3.1,3.1,3.1,3.1,3.1,3.1,3.1,3.1,3.1,3.1,3.1,3.1,3.1,3.1,3.1,3.0,3.1,3.1,3.1},
		     {4.1,4.1,25.2,4.1,23.2,23.2,23.2,23.2,23.2,23.2,4.1,4.1,4.1,4.1,4.1,4.1,4.1,4.1,4.0,24.2,4.0,4.1},
		     {4.1,4.1,25.2,4.1,23.2,23.2,23.2,23.2,23.2,23.2,4.1,4.1,4.1,4.1,4.1,4.1,4.1,4.1,4.0,24.2,4.0,4.1},
		     {4.1,4.1,25.2,4.1,23.2,23.2,23.2,23.2,23.2,23.2,4.1,4.1,4.1,4.1,4.1,4.1,4.1,4.1,4.0,24.2,4.0,4.1},
		     {4.1,4.1,25.2,4.1,23.2,27.2,23.2,28.2,23.2,23.2,4.1,4.1,4.1,4.1,4.1,4.1,4.1,4.1,4.0,24.2,4.0,4.1},
		     {4.1,4.1,25.2,4.1,23.2,23.2,23.2,28.2,5.0,23.2,4.1,4.1,4.1,4.1,4.1,4.1,4.1,4.1,4.0,24.2,4.0,4.1},
		     {4.1,4.1,25.2,4.1,23.2,23.2,23.2,28.2,5.0,23.2,4.1,4.1,4.1,4.1,4.1,4.1,4.1,4.1,4.0,24.2,4.0,4.1},
		     {8.1,8.1,8.1,8.1,8.1,8.1,8.1,8.1,8.1,8.1,7.0,8.1,8.1,8.1,8.1,8.1,8.1,8.1,8.0,8.1,8.1,8.1}};

  float newstate = 0.0;
//takes the input from the input file and then stores the char in pos
//if this position ends up being negative 1 it will error out since that doesnt
//exist
  pos = theChar(c);
	cout << c << endl;
	// old state never changes 
	cout << oldstate << endl;
  if(pos == -1)
    return ERROR_T;
  // new state now becomes the number that is found in the matrix with this info
  newstate = m[oldstate][pos];
  //how to handle the different states in the matrix and what it should do when it comes across one of theses things
  if(isEndState0(newstate) == true)
    {
      datacont = ' ';
	cout << newstate << endl;
	cout << errors << " check matrix if statement one " << endl; 
      return token_type(int(newstate)); /// might be just int(newstate)
    }
  else if(isEndState1(newstate) == true)
    {
      datacont = c;
      lexeme = c;
	cout << newstate<< endl;
      return token_type(int(newstate));
    }
  else if(isContState(newstate) == true)
    {
      datacont = ' ';
      lexeme+= c;
	cout << newstate << endl;
      //input.get(c);
      return checkMatrix(c, int(newstate));
    }
  return token;// EOF_T actually stopped it after the first letter

}

int LexicalAnalyzer::theChar(char c)
{ // returns correstponding column index for matrix
  if(c == '-') // dash
    return 0;
  else if(c == '.')
    return 1;
  else if(c == '+')
    return 3;
  else if(c == '=')
    return 10;
  else if(c == '>')
    return 11;
  else if(c == '<')
    return 12;
  else if(c == '*')
    return 13;
  else if(c == '/')
    return 14;
  else if(c == '(')
    return 15;
  else if(c == ')')
    return 16;
  else if(c == '\'')
    return 17;
  else if(c == ' ')
    return 18;
  else if(c == '_')
    return 19;
  else if(c == '?')
    return 20;
  else if(c == '\n')
    return 21;
  else if(c == 'a')
    return 5;
  else if(c == 'c')
    return 6;
  else if(c == 'd')
    return 7;
  else if(c == 'r')
    return 8;
  else if(isNumber(c) == true)
    return 2;
  else if(isCapital(c) == true)
    return 4;
  else if(isLowerCase(c) == true)
    return 9;
}

bool LexicalAnalyzer::isNumber(char c)
{//checks to see if the analyzer is getting a number
  if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
    return true;
  return false;
}

bool LexicalAnalyzer::isCapital(char c)
{//checks to see if the analyzer is getting a capital letter and then returns true or false depending on the situation
  if (c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z')
    return true;
  return false;
}

bool LexicalAnalyzer::isLowerCase(char c)
{//checks to see if it is a lower case letter. then returns true or false to help the code run smoothly like the previous 2 functions
  if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z')
    return true;
  return false;
}

bool LexicalAnalyzer::isEndState0(float n)
{//if the number that it comes across in the matrix is 0.0 then return true
  float check = n - float(int(n));
  if(check == 0.0)
    return true;
  return false;
}

bool LexicalAnalyzer::isEndState1(float n)
{// if the number that it finds has a .1 value it will return true or false for EndState1
  float check = n - float(int(n));
  if(check == 0.1 || check == (-0.1))
    return true;
  return false;
}

bool LexicalAnalyzer::isContState(float n)
{//if the number in the matrix contains a .2 then it is still continuing with the current lexeme
	cout << n << endl;
  float check = n - float(int(n));
	cout << check << " after the math " << endl;
  if(check == 0.2)
    return true;
  return false;
}

string LexicalAnalyzer::GetTokenName (token_type t) const
{ // The GetTokenName function returns a string containing the name of the token passed to it.
  //return token_names[t];
  return "";
}

string LexicalAnalyzer::GetLexeme () const
{
	// This function will return the lexeme found by the most recent call to
	// the get_token function
  return lexeme;
  //return "";
}

void LexicalAnalyzer::ReportError (const string & msg)
{
	// This function will be called to write an error message to a file
  debug << lexeme << setw(10) << token_names[token] << endl;
}



