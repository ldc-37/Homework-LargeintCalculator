/*
��������ͷ�ļ�
����ע����ҳ�桢���Գ��򡢰�Ȩ��Ϣ������ת��������
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

