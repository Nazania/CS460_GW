//Authors: Nazania Barraza, Ashley Lopez 
//Team V
//Project 1
#include <iostream>
#include <iomanip>
#include <fstream>
#include "SyntacticalAnalyzer.h"

using namespace std;

SyntacticalAnalyzer::SyntacticalAnalyzer (char * filename)
{
	lex = new LexicalAnalyzer (filename);
	token_type t;
	while ((t = lex->GetToken()) != EOF_T)
	{
	  ///cout << "In SyntacticalAnalyser constructor while loop " << lex->GetLexeme() << endl;

	  // get a token
	  // write its name to the debug file
	  // write the corresponding lexeme to the debug file
	  //lex->ReportError();
	}
}

SyntacticalAnalyzer::~SyntacticalAnalyzer ()
{
	delete lex;
}
