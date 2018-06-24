#include "hugeint.h"
#include "func.h"

string HugeInt::GetNum () const
{
    return (m_isMinus ? "-" : "") + m_strNum;
}
void HugeInt::SetNum (string num)
{
    if (num == "") {
        m_strNum = ""; //@change?
        m_isMinus = false;
        return;
    }
    if (*num.begin () == '+') {
        num.erase (0, 1);
    }
    m_isMinus = (*num.begin () == '-');
    if (m_isMinus) {
        num.erase (0, 1);
    }
    if (num[0] == '0' && num.size() > 1) {
        if (num[1] == 'x' || num[1] == 'X') {
            num.erase (0, 2);
            m_strNum = OthersToDec (num, 16).GetNum ();
        }
        else {
            num.erase (0, 1);
            m_strNum = OthersToDec (num, 8).GetNum ();
        }
    }
    else {
        for (size_t i = 0; i < num.size (); ++i) {
            if (!isdigit (num[i])) {
                throw invalid_argument ("ILLEGAL_SYMBOL_IN_NUMBER");
            }
        }
        m_strNum = num;
    }
}

void EraseZero (string &n)
{
    if (n[0] == '-') {
        while (n[1] == '0' && n.size () > 1) {
            n.erase (1, 1);
        }
    }
    else {
        while (n[0] == '0' && n.size () > 1) {
            n.erase (0, 1);
        }
    }
}

ostream& operator<<(ostream& os, const HugeInt& hugeint)
{
    os << hugeint.GetNum ();
    return os;
}
istream& operator>> (istream& is, HugeInt& hugeint)
{
    string num;
    is >> num;
    hugeint.SetNum (num);
    return is;
}

HugeInt operator- (HugeInt num)
{
    num.m_isMinus = !num.m_isMinus;
    return num;
}
HugeInt operator+ (HugeInt left, HugeInt right)
{
    string &a = left.m_strNum, &b = right.m_strNum;
    string sum;
    int lena, lenb, flag = 0;
    bool sumMinus = false, aMinus = left.m_isMinus, bMinus = right.m_isMinus;
    if (aMinus && bMinus) {
        sumMinus = true;
    }
    else if (aMinus) {
        return (right - left.abs ());
    }
    else if (bMinus) {
        return (left - right.abs ());
    }
    if (b.size () > a.size ()) {
        a.swap (b);
    }
    lenb = b.size ();
    lena = a.size ();
    for (int i = 0;; ++i) {
        if (i < lenb) {
            if ((a[lena - 1 - i] - '0') + (b[lenb - 1 - i] - '0') + flag > 9) {
                sum.insert (0, to_string (flag + (a[lena - 1 - i] - '0') + (b[lenb - 1 - i] - '0') - 10));
                flag = 1;
            }
            else {
                sum.insert (0, to_string (flag + (a[lena - 1 - i] - '0') + (b[lenb - 1 - i] - '0')));
                flag = 0;
            }
        }
        else if (i == lena) {
            sum.insert (0, (flag == 1 ? "1" : ""));
            break;
        }
        else {
            sum.insert (0, to_string ((a[lena - 1 - i] - '0' + flag) % 10));
            flag = a[lena - 1 - i] - '0' + flag > 9;
        }
    }
    return (sumMinus ? '-' + sum : sum);
}
HugeInt operator- (HugeInt left, HugeInt right)
{
    string& a = left.m_strNum, &b = right.m_strNum;
    string diff;
    int lena, lenb, flag = 0;
    bool diffMinus = false, aMinus = left.m_isMinus, bMinus = right.m_isMinus;
    if (aMinus && bMinus) {
        return (right.abs() - left.abs());
    }
    else if (aMinus) {
        return "-" + (left.abs() + right).GetNum (); //@improve?
    }
    else if (bMinus) {
        return (left + right.abs());
    }
    if (left < right) {
        diffMinus = true;
        a.swap (b);
        //return "-" + (right - left).GetNum (); //@change?
    }
    lena = a.size ();
    lenb = b.size ();
    for (int i = 0;; ++i) {
        if (i < lenb) {
            if ((a[lena - 1 - i] - '0') - (b[lenb - 1 - i] - '0') - flag < 0) {
                diff.insert (0, to_string ((a[lena - 1 - i] - '0') - (b[lenb - 1 - i] - '0') + 10 - flag));
                flag = 1;
            }
            else {
                diff.insert (0, to_string ((a[lena - 1 - i] - '0') - (b[lenb - 1 - i] - '0') - flag));
                flag = 0;
            }
        }
        else if (i == lena) {
            break;
        }
        else {
            if (a[lena - 1 - i] - '0' - flag < 0) {
                diff.insert (0, to_string (a[lena - 1 - i] - '0' + 10 - flag));
                flag = 1;
            }
            else {
                diff.insert (0, to_string (a[lena - 1 - i] - '0' - flag));
                flag = 0;
            }
        }
    }
    if (diffMinus) {
        diff.insert (0, "-");
    }
    EraseZero (diff);
    return diff;
}
HugeInt operator* (HugeInt left, HugeInt right)
{
    string& a = left.m_strNum, &b = right.m_strNum;
    bool productMinus = false, aMinus = left.m_isMinus, bMinus = right.m_isMinus;
    if (aMinus ^ bMinus) { //xor
        productMinus = true;
    }
    HugeInt product (0), tempSum (0);
    int lena = a.size ();
    int lenb = b.size ();
    for (int i = 0; i < lenb; ++i) {
        for (int j = 0; j < b[i] - '0'; ++j) {
            tempSum += left.abs ();
        }
        tempSum.m_strNum.append (lenb - 1 - i, '0');
        product += tempSum;
        tempSum = 0;
    }
    if (productMinus) {
        product.m_isMinus = true;
    }
    return product;
}
HugeInt operator/ (HugeInt left, HugeInt right)
{
    string& a = left.m_strNum, &b = right.m_strNum;
    bool quotientMinus = false, aMinus = left.m_isMinus, bMinus = right.m_isMinus;
    if (aMinus ^ bMinus) { //xor
        quotientMinus = true;
    }
    if (b == "0") {
        throw invalid_argument("DIVIDE_ZERO_ERROR");
    }
    HugeInt quotient, remainder; // division procedure remainder
    int digit; //times of doing cycle-subtract
    int lena = a.size ();
    int lenb = b.size ();
    if (right.abs() > left.abs()) {
        return 0;
    }
    remainder = a.substr (0, lenb - 1);
    for (int i = 0; i <= lena - lenb; ++i) {
        digit = 0;
        remainder.m_strNum.append (1, a[lenb - 1 + i]);
        EraseZero (remainder.m_strNum); //erase previous 0
        while ((remainder - b) >= 0) { 
            remainder -= b;
            digit++;
        }
        quotient.m_strNum.append (1, digit + '0');
    }
    EraseZero (quotient.m_strNum);
    if (quotientMinus) {
        quotient.m_isMinus = true;
    }
    return quotient;
}
HugeInt& HugeInt::operator+= (HugeInt num)
{
    this->SetNum ((*this + num).GetNum ());
    return *this;
}
HugeInt& HugeInt::operator-= (HugeInt num)
{
    this->SetNum ((*this - num).GetNum());
    return *this;
}
HugeInt& HugeInt::operator*= (HugeInt num)
{
    this->SetNum ((*this * num).GetNum ());
    return *this;
}
HugeInt& HugeInt::operator/= (HugeInt num)
{
    this->SetNum ((*this / num).GetNum ());
    return *this;
}

HugeInt operator^ (HugeInt left, HugeInt right)
{
    HugeInt pow = 1;
    right += 1;
    while (--right > 0) {
        pow *= left;
    }
    return pow;
}
HugeInt operator% (HugeInt left, HugeInt right)
{
    return left - left / right * right;
}

bool operator> (HugeInt left, HugeInt right)
{
    string a = left.m_strNum, b = right.m_strNum;
    bool aMinus = left.m_isMinus, bMinus = right.m_isMinus;
    if (aMinus && bMinus) {
        return (right.abs () > left.abs ());
    }
    else if (aMinus) {
        return false;
    }
    else if (bMinus) {
        return true;
    }
    int lena = a.size (), lenb = b.size ();
    if (lena > lenb) {
        return true;
    }
    else if (lena < lenb) {
        return false;
    }
    else {
        for (int i = 0; i < lena; ++i) {
            if (a[i] < b[i]) {
                return false;
            }
            else if (a[i] > b[i]) {
                return true;
            }
        }
    }
    return false; //equal
}
bool operator< (HugeInt left, HugeInt right)
{
    return ((left <= right) && (left.m_strNum != right.m_strNum));
}
bool operator>= (HugeInt left, HugeInt right)
{
    return ((left > right) || (left == right));
}
bool operator<= (HugeInt left, HugeInt right)
{
    return !(left > right);
}
bool operator== (HugeInt left, HugeInt right)
{
    return (left.m_strNum == right.m_strNum);
}
bool operator!= (HugeInt left, HugeInt right)
{
    return !(left == right);
}

HugeInt& HugeInt::operator-- () {
    *this -= 1;
    return *this;
}
HugeInt& HugeInt::operator++ () {
    *this += 1;
    return *this;
}
HugeInt HugeInt::operator++ (int)
{
    HugeInt ret = *this;
    ++(*this);
    return ret;
}
HugeInt HugeInt::operator-- (int)
{
    HugeInt ret = *this;
    --(*this);
    return ret;
}

HugeInt& HugeInt::abs ()
{
    m_isMinus = false;
    return *this;
}

string HugeInt::toOct ()
{
    return DecToOthers (*this, 8);
}
string HugeInt::toHex ()
{
    return DecToOthers (*this, 16);
}