#ifndef LEX_H
#define LEX_H

#include <iostream>
#include <fstream>

using namespace std;

//enum token_type {NONE = -1, EOF_T, NUM_TOKENS};
enum token_type { ENDL_T = -2, NONE_T, ERROR_T, MINUS_T, NUMLIT_T, PLUS_T, IDKEY_T, LISTOP_T, EQUALTO_T, GTE_T, GT_T, LTE_T, LT_T, MULT_T, DIV_T, LPAREN_T, RPAREN_T, QUOTE_T, EOF_T };

class LexicalAnalyzer 
{
 public:
  LexicalAnalyzer (char * filename);
  ~LexicalAnalyzer ();
  token_type GetToken ();
  token_type checkMatrix(char c, int oldstate);
  int theChar(char c);
  bool isNumber(char c);
  bool isCapital(char c);
  bool isLowerCase(char c);
  bool isEndState0(float n);
  bool isEndState1(float n);
  bool isContState(float n);
  string GetTokenName (token_type t) const;
  string GetLexeme () const;
  void ReportError (const string & msg);
 private:
  ifstream input; // to open file
  ofstream listing; // creates the .lst file
  ofstream debug; // creates the .gdb file
  token_type token;
  string line;
  int linenum;
  int pos;
  string lexeme;
  int errors;
  char datacont;
};
	
#endif
