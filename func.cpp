#include "func.h"
#include "hugeint.h"

void ShowCopyright ()
{
    cout << "Copyright (c) 2017-2018 李定成(221701331). All Rights Reserved." << endl << endl;
}

void ShowTime ()
{
    time_t now = time (0);
    struct tm nowTime;
    localtime_s (&nowTime, &now);
    int hour = nowTime.tm_hour;
    int min = nowTime.tm_min;
    int sec = nowTime.tm_sec;
    int year = 1900 + nowTime.tm_year;
    int month = 1 + nowTime.tm_mon;
    int day = nowTime.tm_mday;
    int weekNum = nowTime.tm_wday;
    const char *weekChn[] = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };
    const char *week = weekChn[weekNum];

    cout << "当前日期时间：" << year << '.' << month << '.' << day << '(' << week << ") ";
    cout << (hour < 10 ? "0" : "") << hour << ':' << (min < 10 ? "0" : "") << min << ':' << (sec < 10 ? "0" : "") << sec << endl;
}

void ShowUI ()
{
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl <<
        "+    A : 进入计算器             +" << endl <<
        "+    B : 进入数据测试           +" << endl <<
        "+    C : 进入进制转换           +" << endl <<
        "+    Q : 退出程序               +" << endl <<
        "+-+-+-+-+-+-+-+-+-++-+--+-+-+-+-+" << endl <<
        "请选择：";
}

void Calculator ()
{
    system ("cls");
    cout << "请输入两个操作数以及操作符，中间以空格隔开。" << endl
        << "支持的操作符有：+ - * / ^ %" << endl
        << "例如：123456789 * 987654321" << endl << endl
        << "请输入表达式：";
    HugeInt a, b;
    char flag;
    cin >> a;
    cin >> flag;
    cin >> b;
    clock_t s_time = clock ();
    try {
        switch (flag)
        {
        case '+':cout << "计算结果：" << (a + b) << endl; break;
        case '-':cout << "计算结果：" << (a - b) << endl; break;
        case '*':cout << "计算结果：" << (a * b) << endl; break;
        case '/':cout << "计算结果：" << (a / b) << endl; break;
        case '^':cout << "计算结果：" << (a ^ b) << endl; break;
        case '%':cout << "计算结果：" << (a % b) << endl; break;
        default:cout << "符号错误！" << endl;
        }
    }
    catch (const char* e) {
        cout << e << endl;
    }
    clock_t e_time = clock ();
    cout << "计算用时 : " << (double)(e_time - s_time) / CLOCKS_PER_SEC << "s" << endl;
    system ("pause");
}

void TestData ()
{
    system ("cls");
/*
    try {
        HugeInt n0 (-2147483648L);
    }
    catch (...) {
        cout << "执行HugeInt n0(-2147483648L);后出现数据溢出异常!\n";
    }*/

        HugeInt n1 (2147483647L);
        cout << "执行HugeInt n1(2147483647L);后n1为：" << n1 << endl;
        HugeInt n2 (-2147483647L);
        cout << "执行HugeInt n2(-2147483647L);后n2为：" << n2 << endl;
        HugeInt n3 (+777);
        cout << "执行HugeInt n3(+777);后n3为：" << n3 << endl;
        cout << endl;

        HugeInt n4 ("-12345678901234");
        cout << "执行HugeInt n4(\"-12345678901234\");后n4为：" << n4 << endl;
        HugeInt n5 ("+9876543210987654321098");
        cout << "执行HugeInt n5(\"+9876543210987654321098\");后n5为：" << n5 << endl;
        HugeInt n6 ("12345678901234567890");
        cout << "执行HugeInt n6(\"12345678901234567890\");后n6为：" << n6 << endl;
        cout << endl;
        HugeInt n7 ("01234567012345670");
        cout << "执行HugeInt n7(\"01234567012345670\");后n7为：" << n7 << endl;
        cout << "执行HugeInt n7(\"012345678901234567890\");后n71为：";
        try {
            HugeInt n71 ("012345678901234567890");
            cout << n71 << endl;
        }
        catch (invalid_argument e) {
            cout << e.what () << endl;
        }
        HugeInt n8 ("0x1234aA56bC78Ef90d0a1234567890");
        cout << "执行HugeInt n8(\"0x1234aA56bC78Ef90d0a1234567890\");后n8为：" << n8 << endl;
        HugeInt n9 ("0X98aEa7654a3be210f12c34dd567890");
        cout << "执行HugeInt n9(\"0X98aEa7654a3be210f12c34dd567890\");后n9为：" << n9 << endl;

        cout << "n6至n9对应八进制为：" << endl;
        cout << n6.toOct () << endl;
        cout << n7.toOct () << endl;
        cout << n8.toOct () << endl;
        cout << n9.toOct () << endl;

        cout << "n6至n9对应十六进制为：" << endl;
        cout << n6.toHex () << endl;
        cout << n7.toHex () << endl;
        cout << n8.toHex () << endl;
        cout << n9.toHex () << endl;


        n4 = -n4;
        cout << "执行n4=-n4;后n4为：" << n4 << endl;
        n6 = -n6;
        cout << "执行n6=-n6;后n6为：" << n6 << endl;
        cout << endl;

        try {
            cout << n4 + n5 << endl;
        }
        catch (...) {
            cout << "执行cout<<n4+n5<<endl;后出现数据溢出异常!\n";
        }
        cout << "n4+n3=" << n4 + n3 << endl;
        cout << endl;

        n4 += n1;
        cout << "执行n4+=n1;后n4为：" << n4 << endl;
        n6 += n2;
        cout << "执行n6+=n2;后n6为：" << n6 << endl;
        n4 += 88888L;
        cout << "执行n4+=88888L;后n4为：" << n4 << endl;
        n4 += "1111";
        cout << "执行n4+=\"1111\";后n4为：" << n4 << endl;
        cout << endl;

        cout << "n4+6666666L=" << n4 + 6666666L << endl;
        cout << "n4+\"66666666666666666666\"="
            << n4 + "66666666666666666666" << endl;
        cout << endl;

        system ("pause");
        cout << endl;

        cout << "n5当前值为：" << n5 << endl;
        cout << "6666666L+n5=" << 6666666L + n5 << endl;
        cout << "HugeInt(6666666L)+6666=" << HugeInt (6666666L) + 6666 << endl;
        cout << "HugeInt(666666L)+\"66666666666666666\"="
            << HugeInt (666666L) + "66666666666666666" << endl;
        cout << endl;

        cout << "\"888\"+n5=" << "888" + n5 << endl;
        cout << "HugeInt(\"888\")+666L=" << HugeInt ("888") + 666L << endl;
        cout << "HugeInt(\"888\")+\"666\"=" << HugeInt ("888") + "666" << endl;
        cout << endl;

        cout << "n2当前值为：" << n2 << endl;
        cout << "n5当前值为：" << n5 << endl;
        n2 = ++n5;
        cout << "执行n2=++n5;后n2为：" << n2 << "  n5为：" << n5 << endl;
        n2 = n5++;
        cout << "执行n2=n5++;后n2为：" << n2 << "  n5为：" << n5 << endl;
        cout << endl;

        system ("pause");
        cout << endl;

        if (n5 > n6) cout << n5 << '>' << n6 << '\n';
        if (n5 >= n6) cout << n5 << ">=" << n6 << '\n';
        if (n5 > 5555L) cout << n5 << ">5555L\n";
        if (n6 > "-99999999999999999999")
            cout << n6 << ">\"-99999999999999999999\"\n";
        if (!(n6 > -5555L)) cout << n6 << "<=-5555L\n";;
        if (n6 <= -5555L) cout << n6 << "<=-5555L\n";;
        if (n5 > n2) cout << n5 << '>' << n2 << '\n';

        HugeInt n10, n11 (-0L);
        if (!(n10 > n11)) cout << "0<=-0\t\t";
        if (n10 == n11) cout << "0==-0\n";

        if (!(n5 == n6)) cout << n5 << "!=" << n6 << '\n';
        if (!(n6 == n5)) cout << n6 << "!=" << n5 << '\n';
        if (!(n5 == 5555L)) cout << n5 << "!=5555L\n";
        if (!(n5 == n2)) cout << n5 << "!=" << n2 << '\n';
        if (n5 != n2) cout << n5 << "!=" << n2 << '\n';
        if (n5 == n5) cout << n5 << "==" << n5 << '\n';
        if (n5 >= n5) cout << n5 << ">=" << n5 << '\n';
        if (n5 <= n5) cout << n5 << "<=" << n5 << '\n';
        cout << endl;

        system ("pause");
        cout << endl;

        n3 = -n3;
        n5 = -n5;
        cout << "n1当前值为：" << n1 << endl;
        cout << "n2当前值为：" << n2 << endl;
        cout << "n3当前值为：" << n3 << endl;
        cout << "n4当前值为：" << n4 << endl;
        cout << "n5当前值为：" << n5 << endl;
        cout << "n6当前值为：" << n6 << endl;
        cout << endl;

        cout << "n3+n5=" << n3 + n5 << endl;
        cout << "n1+n5=" << n1 + n5 << endl;
        cout << "n5+n1=" << n5 + n1 << endl;
        cout << "n4-n2=" << n4 - n2 << endl;
        cout << "n5-n3=" << n5 - n3 << endl;
        cout << "n4-n3=" << n4 - n3 << endl;
        cout << "n5-n1=" << n5 - n1 << endl;
        n5 -= n1;
        cout << "执行n5-=n1;后n5为：" << n5 << endl;
        cout << endl;

        cout << "n2当前值为：" << n2 << endl;
        cout << "n5当前值为：" << n5 << endl;
        n2 = --n5;
        cout << "执行n2=--n5;后n2为：" << n2 << "  n5为：" << n5 << endl;
        n2 = n5--;
        cout << "执行n2=n5--;后n2为：" << n2 << "  n5为：" << n5 << endl;
        cout << endl;

        system ("pause");
        cout << endl;

        cout << "n3当前值为：" << n3 << endl;
        cout << "n3*0L=" << n3 * 0L << endl;
        cout << "n3*1L=" << n3 * 1L << endl;
        cout << "4L*n3=" << 4L * n3 << endl;
        cout << "\"-99999\"*n3=" << "-99999"*n3 << endl;
        cout << "n3*n3=" << n3 * n3 << endl;
        cout << "n1当前值为：" << n1 << "\t\t";
        cout << "n1*n3=" << n1 * n3 << endl;
        cout << endl;

        n3 *= 99999L;
        cout << "执行n3*=99999L;后n3为：" << n3 << endl;
        try {
            cout << "n5当前值为：" << n5 << endl;
            cout << "n5*5L=" << n5 * 5L << endl;
        }
        catch (...) {
            cout << "执行cout<<\"n5*5L=\"<<n5*5L<<endl;后出现数据溢出异常!\n";
        }
        cout << endl;

        system ("pause");
        cout << endl;

        try {
            cout << "n3/0L=" << n3 / 0L << endl;
        }
        catch (...) {
            cout << "执行cout<<\"n3/0L=\"<<n3/0L<<endl;后出现除0异常!\n";
        }
        cout << "0L/n3=" << 0L / n3 << endl;
        cout << "n3当前值为：" << n3 << '\t';
        cout << "n3/10001L=" << n3 / 10001L << '\t';
        cout << "n3/(n3+1)=" << n3 / (n3 + 1) << endl;

        cout << "n5当前值为：" << n5 << endl;
        cout << "n6当前值为：" << n6 << endl;
        cout << "n5/n6=" << n5 / n6 << endl;
        cout << "n6/n5=" << n6 / n5 << endl;

        n3 /= -99999L;
        cout << "执行n3/=-99999L;后n3为：" << n3 << endl;

        cout << "9999L/n3=" << 9999L / n3 << endl;
        cout << "\"-99990\"/n3=" << "-99990" / n3 << endl;
        cout << endl;

    try {
        cout << "n3%0L=" << n3 % 0L << endl;
    }
    catch (...) {
        cout << "执行cout<<\"n3%0L=\"<<n3%0L<<endl;后出现除0异常!\n";
    }
    cout << "n3当前值为：" << n3 << "\t\t\t";
    cout << "0L%n3=" << 0L % n3 << endl;
    cout << "n3%101L=" << n3 % 101L << '\t';
    cout << "n3%(-101L)=" << n3 % (-101L) << '\t';
    cout << "-n3%101L=" << -n3 % 101L << '\t';
    cout << "-n3%(-101L)=" << -n3 % (-101L) << '\n';
    cout << "9999L%n3=" << 9999L % n3 << endl;
    cout << "\"-99990\"%n3=" << "-99990"%n3 << endl;
    cout << endl;

    system ("pause");

    HugeInt m1 ("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
    HugeInt m2 (-123);
    cout << "m1=" << m1 << endl;
    cout << "m2=" << m2 << endl;
    cout << "m1+m2=" << m1 + m2 << endl;
    cout << "m1-m2=" << m1 - m2 << endl;
    cout << "m1*m2=" << m1 * m2 << endl;
    cout << "m1/m2=" << m1 / m2 << endl;
    cout << "m1%m2=" << m1 % m2 << endl;


    cout << "------测试结束------" << endl;
    system ("pause");
}

void BaseConversion ()
{
    system ("cls");
    string number;
    int radixFrom, radixTo;
    cout << "请输入待转换的数字：";
    cin >> number;
    cout << "请输入该数字进制（2~36）：";
    cin >> radixFrom;
    cout << "请输入目标进制（2~36):";
    cin >> radixTo;
    cout << "转换结果为：" << DecToOthers (OthersToDec (number, radixFrom), radixTo) << endl;
    system ("pause");
}

string DecToOthers (HugeInt num, int radix)
{
    string result;
    do
    {
        if ((num % radix) > 9 && radix > 10) {
            result.insert (0, 1, (char)(stoi((num % radix).GetNum ()) - 10 + 'A'));
        }
        else {
            result.insert (0, (num % radix).GetNum ());
        }
        num /= radix;
    } while (num != 0);
    return result;
}

HugeInt OthersToDec (string num, int radix)
{
    HugeInt result (0);
    int len = num.size ();
    for (int i = 0; i < len; ++i) {
        if (num[len - i - 1] - '0' < min (radix, 10) && num[len - i - 1] - '0' >= 0) {
            result += (num[len - i - 1] - '0') * (HugeInt(radix) ^ i);
        }
        else if (isupper (num[len - i - 1]) && num[len - i - 1] < 'A' + radix - 10) {
            result += (num[len - i - 1] - 'A' + 10) * (HugeInt (radix) ^ i);
        }
        else if (islower (num[len - i - 1]) && num[len - i - 1] < 'a' + radix - 10){
            result += (num[len - i - 1] - 'a' + 10) * (HugeInt (radix) ^ i);
        }
        else {
            throw invalid_argument("ILLEGAL_SYMBOL_IN_NUMBER");
        }
    }
    return result;
}

