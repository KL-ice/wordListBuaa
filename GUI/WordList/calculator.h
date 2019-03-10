#ifndef CALCULATOR_H
#define CALCULATOR_H


class Calculator
{
public:
    Calculator();
    void setWordsMost(bool flag);
    void setAllowCircle(bool flag);
    void setHeadChar(int ch);
    void setTailChar(int ch);
    void setTextIn(char *text);
    char* getTextOut();
    void core();


public:
    bool wordsMost = true;//为true是-w，为false是-c
    bool allowCircle = false;
    int headChar = 0;//为0表示不设置首字母
    int tailChar = 0;//为0表示不设置尾字母

    char *textIn;
    char *textOut;

    //TODO: 存储文件内容

};

#endif // CALCULATOR_H
