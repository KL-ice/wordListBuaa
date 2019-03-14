#include "calculator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <QDebug>
#include "Readin.h"
#include <windows.h>

using namespace std;
typedef int(*p_gen_chain_word)(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
typedef int(*p_gen_chain_char)(char* words[], int len, char* result[], char head, char tail, bool enable_loop);


Calculator::Calculator()
{

}

void Calculator::setWordsMost(bool flag){
    this->wordsMost = flag;
}
void Calculator::setAllowCircle(bool flag){
    this->allowCircle = flag;
}
void Calculator::setHeadChar(int ch){
    this->headChar = ch;
}
void Calculator::setTailChar(int ch){
    this->tailChar = ch;
}
void Calculator::setTextIn(char *text){
    this->textIn = text;
}
//string Calculator::getTextOut(){
//	string s;
//	s = textOut;
//    return s;
//}
char* Calculator::getTextOut() {
	return textOut;
}
void Calculator::core(){
	textOut = new char[11000];
	strcpy(textOut, "");

	try {

		HINSTANCE CoreDLL = LoadLibrary(L"Core.dll");
		if (CoreDLL == NULL) {
			cout << "File 'Core.dll' not found." << endl;
			exit(1);
		}
		p_gen_chain_word gen_chain_word = (p_gen_chain_word)GetProcAddress(CoreDLL, "gen_chain_word");
		p_gen_chain_char gen_chain_char = (p_gen_chain_char)GetProcAddress(CoreDLL, "gen_chain_char");
		if (gen_chain_word == NULL || gen_chain_char == NULL) {
			cout << "Invalid file 'Core.dll'." << endl;
			exit(1);
		}

		char *FileInName = (char*)malloc(100 * sizeof(char));
		strcpy(FileInName, "word_list_in.txt");
		ofstream infile(FileInName);
		if (!infile) {
			throw "can't open file.";
		}
		else {
			int i;
			for (i = 0;i < strlen(textIn);i++) {
				infile << textIn[i];
			}
		}
		infile.close();

		//写入文件后将文件名传入readin进行处理
		Readin *readin = new Readin();
		readin->GetWords(FileInName);
		qDebug() << readin->Words;
		qDebug() << readin->WordNum;

		int resultLen = 0;
		char ** result = new char *[11000];
		if (this->wordsMost)
		{
			resultLen = gen_chain_word(readin->Words, readin->WordNum, result, this->headChar, this->tailChar, this->allowCircle);
		}
		else
		{
			resultLen = gen_chain_char(readin->Words, readin->WordNum, result, this->headChar, this->tailChar, this->allowCircle);
		}

		//输出
		ofstream outfile("solution.txt");
		int i;
		for (i = 0; i < resultLen; i++)
		{
			outfile << result[i] << endl;
		}
		outfile.close();

		//GUI显示
		for (i = 0; i < resultLen; i++) {
			strcat(textOut, result[i]);
			strcat(textOut, "\n");
		}
	}
	catch (const char* msg)
	{
		strcpy(textOut, msg);
	}
	catch (...)
	{
		strcpy(textOut, "Error");
	}


}
