#include "calculator.h"

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
char* Calculator::getTextOut(){
    return textOut;
}
void Calculator::core(){
    textOut = textIn;
}
