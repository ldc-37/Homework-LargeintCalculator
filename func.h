/*
其他函数头文件
包含注程序页面、测试程序、版权信息、进制转换函数等
*/

#include "hugeint.h"

#include <iostream>
#include <cstring>
#include <ctime> //get time
#include <conio.h> //_getch ()
#include <windows.h> //Sleep ()
#include <cctype>  //isupper ()
#include <stdexcept> // invalid_argument

using namespace std;

#ifndef FUNC_H_
#define FUNC_H_

void ShowTime ();
void ShowCopyright ();
void ShowUI ();

void Calculator ();

void TestData ();
void BaseConversion ();

string DecToOthers (HugeInt num, int radix);
HugeInt OthersToDec (string num, int radix);

#endif // !FUNC_H_

