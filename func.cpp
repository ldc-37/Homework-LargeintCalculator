#include "func.h"
#include "hugeint.h"

void ShowCopyright ()
{
    cout << "Copyright (c) 2017-2018 ���(221701331). All Rights Reserved." << endl << endl;
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
    const char *weekChn[] = { "������", "����һ", "���ڶ�", "������", "������", "������", "������" };
    const char *week = weekChn[weekNum];

    cout << "��ǰ����ʱ�䣺" << year << '.' << month << '.' << day << '(' << week << ") ";
    cout << (hour < 10 ? "0" : "") << hour << ':' << (min < 10 ? "0" : "") << min << ':' << (sec < 10 ? "0" : "") << sec << endl;
}

void ShowUI ()
{
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl <<
        "+    A : ���������             +" << endl <<
        "+    B : �������ݲ���           +" << endl <<
        "+    C : �������ת��           +" << endl <<
        "+    Q : �˳�����               +" << endl <<
        "+-+-+-+-+-+-+-+-+-++-+--+-+-+-+-+" << endl <<
        "��ѡ��";
}

void Calculator ()
{
    system ("cls");
    cout << "�����������������Լ����������м��Կո������" << endl
        << "֧�ֵĲ������У�+ - * / ^ %" << endl
        << "���磺123456789 * 987654321" << endl << endl
        << "��������ʽ��";
    HugeInt a, b;
    char flag;
    cin >> a;
    cin >> flag;
    cin >> b;
    clock_t s_time = clock ();
    try {
        switch (flag)
        {
        case '+':cout << "��������" << (a + b) << endl; break;
        case '-':cout << "��������" << (a - b) << endl; break;
        case '*':cout << "��������" << (a * b) << endl; break;
        case '/':cout << "��������" << (a / b) << endl; break;
        case '^':cout << "��������" << (a ^ b) << endl; break;
        case '%':cout << "��������" << (a % b) << endl; break;
        default:cout << "���Ŵ���" << endl;
        }
    }
    catch (const char* e) {
        cout << e << endl;
    }
    clock_t e_time = clock ();
    cout << "������ʱ : " << (double)(e_time - s_time) / CLOCKS_PER_SEC << "s" << endl;
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
        cout << "ִ��HugeInt n0(-2147483648L);�������������쳣!\n";
    }*/

        HugeInt n1 (2147483647L);
        cout << "ִ��HugeInt n1(2147483647L);��n1Ϊ��" << n1 << endl;
        HugeInt n2 (-2147483647L);
        cout << "ִ��HugeInt n2(-2147483647L);��n2Ϊ��" << n2 << endl;
        HugeInt n3 (+777);
        cout << "ִ��HugeInt n3(+777);��n3Ϊ��" << n3 << endl;
        cout << endl;

        HugeInt n4 ("-12345678901234");
        cout << "ִ��HugeInt n4(\"-12345678901234\");��n4Ϊ��" << n4 << endl;
        HugeInt n5 ("+9876543210987654321098");
        cout << "ִ��HugeInt n5(\"+9876543210987654321098\");��n5Ϊ��" << n5 << endl;
        HugeInt n6 ("12345678901234567890");
        cout << "ִ��HugeInt n6(\"12345678901234567890\");��n6Ϊ��" << n6 << endl;
        cout << endl;
        HugeInt n7 ("01234567012345670");
        cout << "ִ��HugeInt n7(\"01234567012345670\");��n7Ϊ��" << n7 << endl;
        cout << "ִ��HugeInt n7(\"012345678901234567890\");��n71Ϊ��";
        try {
            HugeInt n71 ("012345678901234567890");
            cout << n71 << endl;
        }
        catch (invalid_argument e) {
            cout << e.what () << endl;
        }
        HugeInt n8 ("0x1234aA56bC78Ef90d0a1234567890");
        cout << "ִ��HugeInt n8(\"0x1234aA56bC78Ef90d0a1234567890\");��n8Ϊ��" << n8 << endl;
        HugeInt n9 ("0X98aEa7654a3be210f12c34dd567890");
        cout << "ִ��HugeInt n9(\"0X98aEa7654a3be210f12c34dd567890\");��n9Ϊ��" << n9 << endl;

        cout << "n6��n9��Ӧ�˽���Ϊ��" << endl;
        cout << n6.toOct () << endl;
        cout << n7.toOct () << endl;
        cout << n8.toOct () << endl;
        cout << n9.toOct () << endl;

        cout << "n6��n9��Ӧʮ������Ϊ��" << endl;
        cout << n6.toHex () << endl;
        cout << n7.toHex () << endl;
        cout << n8.toHex () << endl;
        cout << n9.toHex () << endl;


        n4 = -n4;
        cout << "ִ��n4=-n4;��n4Ϊ��" << n4 << endl;
        n6 = -n6;
        cout << "ִ��n6=-n6;��n6Ϊ��" << n6 << endl;
        cout << endl;

        try {
            cout << n4 + n5 << endl;
        }
        catch (...) {
            cout << "ִ��cout<<n4+n5<<endl;�������������쳣!\n";
        }
        cout << "n4+n3=" << n4 + n3 << endl;
        cout << endl;

        n4 += n1;
        cout << "ִ��n4+=n1;��n4Ϊ��" << n4 << endl;
        n6 += n2;
        cout << "ִ��n6+=n2;��n6Ϊ��" << n6 << endl;
        n4 += 88888L;
        cout << "ִ��n4+=88888L;��n4Ϊ��" << n4 << endl;
        n4 += "1111";
        cout << "ִ��n4+=\"1111\";��n4Ϊ��" << n4 << endl;
        cout << endl;

        cout << "n4+6666666L=" << n4 + 6666666L << endl;
        cout << "n4+\"66666666666666666666\"="
            << n4 + "66666666666666666666" << endl;
        cout << endl;

        system ("pause");
        cout << endl;

        cout << "n5��ǰֵΪ��" << n5 << endl;
        cout << "6666666L+n5=" << 6666666L + n5 << endl;
        cout << "HugeInt(6666666L)+6666=" << HugeInt (6666666L) + 6666 << endl;
        cout << "HugeInt(666666L)+\"66666666666666666\"="
            << HugeInt (666666L) + "66666666666666666" << endl;
        cout << endl;

        cout << "\"888\"+n5=" << "888" + n5 << endl;
        cout << "HugeInt(\"888\")+666L=" << HugeInt ("888") + 666L << endl;
        cout << "HugeInt(\"888\")+\"666\"=" << HugeInt ("888") + "666" << endl;
        cout << endl;

        cout << "n2��ǰֵΪ��" << n2 << endl;
        cout << "n5��ǰֵΪ��" << n5 << endl;
        n2 = ++n5;
        cout << "ִ��n2=++n5;��n2Ϊ��" << n2 << "  n5Ϊ��" << n5 << endl;
        n2 = n5++;
        cout << "ִ��n2=n5++;��n2Ϊ��" << n2 << "  n5Ϊ��" << n5 << endl;
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
        cout << "n1��ǰֵΪ��" << n1 << endl;
        cout << "n2��ǰֵΪ��" << n2 << endl;
        cout << "n3��ǰֵΪ��" << n3 << endl;
        cout << "n4��ǰֵΪ��" << n4 << endl;
        cout << "n5��ǰֵΪ��" << n5 << endl;
        cout << "n6��ǰֵΪ��" << n6 << endl;
        cout << endl;

        cout << "n3+n5=" << n3 + n5 << endl;
        cout << "n1+n5=" << n1 + n5 << endl;
        cout << "n5+n1=" << n5 + n1 << endl;
        cout << "n4-n2=" << n4 - n2 << endl;
        cout << "n5-n3=" << n5 - n3 << endl;
        cout << "n4-n3=" << n4 - n3 << endl;
        cout << "n5-n1=" << n5 - n1 << endl;
        n5 -= n1;
        cout << "ִ��n5-=n1;��n5Ϊ��" << n5 << endl;
        cout << endl;

        cout << "n2��ǰֵΪ��" << n2 << endl;
        cout << "n5��ǰֵΪ��" << n5 << endl;
        n2 = --n5;
        cout << "ִ��n2=--n5;��n2Ϊ��" << n2 << "  n5Ϊ��" << n5 << endl;
        n2 = n5--;
        cout << "ִ��n2=n5--;��n2Ϊ��" << n2 << "  n5Ϊ��" << n5 << endl;
        cout << endl;

        system ("pause");
        cout << endl;

        cout << "n3��ǰֵΪ��" << n3 << endl;
        cout << "n3*0L=" << n3 * 0L << endl;
        cout << "n3*1L=" << n3 * 1L << endl;
        cout << "4L*n3=" << 4L * n3 << endl;
        cout << "\"-99999\"*n3=" << "-99999"*n3 << endl;
        cout << "n3*n3=" << n3 * n3 << endl;
        cout << "n1��ǰֵΪ��" << n1 << "\t\t";
        cout << "n1*n3=" << n1 * n3 << endl;
        cout << endl;

        n3 *= 99999L;
        cout << "ִ��n3*=99999L;��n3Ϊ��" << n3 << endl;
        try {
            cout << "n5��ǰֵΪ��" << n5 << endl;
            cout << "n5*5L=" << n5 * 5L << endl;
        }
        catch (...) {
            cout << "ִ��cout<<\"n5*5L=\"<<n5*5L<<endl;�������������쳣!\n";
        }
        cout << endl;

        system ("pause");
        cout << endl;

        try {
            cout << "n3/0L=" << n3 / 0L << endl;
        }
        catch (...) {
            cout << "ִ��cout<<\"n3/0L=\"<<n3/0L<<endl;����ֳ�0�쳣!\n";
        }
        cout << "0L/n3=" << 0L / n3 << endl;
        cout << "n3��ǰֵΪ��" << n3 << '\t';
        cout << "n3/10001L=" << n3 / 10001L << '\t';
        cout << "n3/(n3+1)=" << n3 / (n3 + 1) << endl;

        cout << "n5��ǰֵΪ��" << n5 << endl;
        cout << "n6��ǰֵΪ��" << n6 << endl;
        cout << "n5/n6=" << n5 / n6 << endl;
        cout << "n6/n5=" << n6 / n5 << endl;

        n3 /= -99999L;
        cout << "ִ��n3/=-99999L;��n3Ϊ��" << n3 << endl;

        cout << "9999L/n3=" << 9999L / n3 << endl;
        cout << "\"-99990\"/n3=" << "-99990" / n3 << endl;
        cout << endl;

    try {
        cout << "n3%0L=" << n3 % 0L << endl;
    }
    catch (...) {
        cout << "ִ��cout<<\"n3%0L=\"<<n3%0L<<endl;����ֳ�0�쳣!\n";
    }
    cout << "n3��ǰֵΪ��" << n3 << "\t\t\t";
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


    cout << "------���Խ���------" << endl;
    system ("pause");
}

void BaseConversion ()
{
    system ("cls");
    string number;
    int radixFrom, radixTo;
    cout << "�������ת�������֣�";
    cin >> number;
    cout << "����������ֽ��ƣ�2~36����";
    cin >> radixFrom;
    cout << "������Ŀ����ƣ�2~36):";
    cin >> radixTo;
    cout << "ת�����Ϊ��" << DecToOthers (OthersToDec (number, radixFrom), radixTo) << endl;
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

