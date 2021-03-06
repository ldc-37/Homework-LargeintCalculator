/********************************************
* Copyright (c) 2017-2018 李定成(221701331). All Rights Reserved.
* 个人信息：
*   班级：软件工程3班
*   学号：221701331
*   姓名：李定成
*   电话：18806035755
*   邮件地址：791551236@qq.com
* 程序名称：巨型整数类（计算器）
* 开发环境：Visual Studio 2017
* 运行环境：Windows 10
* 最后修改日期：2018.6.9
* 特别感谢：221701423同学
* 描述：本程序定义了巨型整数类，并实现两个巨型整数之间的四则运算以及乘方和取余运算，附带进制转换功能。
*********************************************/

//程序入口文件
#include "hugeint.h"
#include "func.h"

int main ()
{
    while (1) {
    ShowCopyright ();
    ShowTime ();
    ShowUI ();

    char o = toupper (_getch());
        switch (o)
        {
        case 'A':Calculator (); break;
        case 'B':TestData (); break;
        case 'C':BaseConversion (); break;
        case 'Q':exit (0);
        case '\0':break; //@temporary-solved!!

        default:cout << "输入有误，请重新输入" << endl; Sleep (1000);
        }
        system ("cls");
    }

    return 0;
}
