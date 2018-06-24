/*
巨型整数类头文件
包含HugeInt类及重载运算符
*/

#include <iostream>
#include <string> 
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <stdexcept> // invalid_argument

using namespace std;

#ifndef HUGEINT_H_
#define HUGEINT_H_
class HugeInt
{
public:
    HugeInt () {
        SetNum ("");
    }
    HugeInt (const int num_) {
        SetNum (to_string (num_));
    }
    HugeInt (const long long num_) {
        SetNum (to_string (num_));
    }
    HugeInt (const char* num_) {
        SetNum (num_);
    }
    HugeInt (string num_) {
        SetNum (num_);
    }
    HugeInt (const HugeInt& hugeint) = default;
    ~HugeInt () {}

    string GetNum () const;
    void SetNum (string num_);

    HugeInt& operator=(const HugeInt& hugeInt) = default;
    friend HugeInt operator- (HugeInt num);
    friend HugeInt operator+ (HugeInt left, HugeInt right);
    friend HugeInt operator- (HugeInt left, HugeInt right);
    friend HugeInt operator* (HugeInt left, HugeInt right);
    friend HugeInt operator/ (HugeInt left, HugeInt right);
    friend HugeInt operator^ (HugeInt left, HugeInt right);
    friend HugeInt operator% (HugeInt left, HugeInt right);
    HugeInt& operator+= (HugeInt num);
    HugeInt& operator-= (HugeInt num);
    HugeInt& operator*= (HugeInt num);
    HugeInt& operator/= (HugeInt num);
    friend bool operator> (HugeInt left, HugeInt right);
    friend bool operator< (HugeInt left, HugeInt right);
    friend bool operator>= (HugeInt left, HugeInt right);
    friend bool operator<= (HugeInt left, HugeInt right);
    friend bool operator== (HugeInt left, HugeInt right);
    friend bool operator!= (HugeInt left, HugeInt right);
    HugeInt& operator++ ();
    HugeInt& operator-- ();
    HugeInt operator++ (int);
    HugeInt operator-- (int);

    HugeInt& abs ();

    string toOct ();
    string toHex ();

private:
    string m_strNum;
    bool m_isMinus;
};

void EraseZero (string &n);

ostream& operator<< (ostream& os, const HugeInt& right);
istream& operator>> (istream& left, HugeInt &right);

#endif // HUGEINT_H_