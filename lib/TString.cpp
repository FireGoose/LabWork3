//
// Created by Andrey on 20.04.2025.
//

#include <iostream>
#include "TString.h"
#include <string.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wwritable-strings"

using namespace std;


TString::TString()
{
    len = 0;
    str = new char[1] {'\0'};
}

TString::TString(char* str_, int len_) : len(len_)
{
    if (len_ < 0)
        throw("Invalid length");
    str = new char[len + 1];
    for (int i = 0; i < len; ++i)
        str[i] = str_[i];
    str[len] = '\0';
}

TString::TString(char* str_)
{
    len = strlen(str_);
    str = new char[len + 1];
    copy(str_, str_ + len + 1, str);
    str[len] = '\0';
}

TString::TString(const TString& s)
{
    len = s.len;
    copy(s.str, s.str + len + 1, str);
}

TString::TString(TString&& s) noexcept
{
    str = s.str;
    len = s.len;
    s.str = nullptr;
    s.len = 0;
}

TString::~TString()
{
    if (str != nullptr)
        delete[] str;
    str = nullptr;
}

const char* TString::GetStr()
{
    return str;
}

int TString::GetLen() const
{
    return len;
}

void TString::SetStr(const char* str_)
{
    len = strlen(str_);
    delete[] str;
    str = new char[len + 1];
    copy(str_, str_ + len + 1, str);
}

void TString::SetLen(int len_)
{
    if (len_ < 0)
        throw("Invalid length");
    else if (len == len_)
        return;

    char* str_ = new char[len_ + 1];
    int l = std::min(len, len_);
    for (int i = 0; i < l; ++i)
        str_[i] = str[i];
    for (int i = l; i < len_; ++i)
        str_[i] = '0';
    str_[len_] = '\0';

    str = str_;
    len = len_;
}

TString TString::operator+(const TString& s) const 
{
    TString res;
    res.len = len + s.len;
    res.str = new char[res.len + 1];

    if (str)
        copy(str, str + len, res.str);
    if (s.str)
        copy(s.str, s.str + s.len + 1, res.str + len);

    return res;
}

TString TString::operator*(int c) const 
{
    if (c < 0)
        throw("Invalid multiplier");
    if (c == 0)
        return TString();

    TString res;
    res.len = c * len;
    res.str = new char[res.len + 1];

    for (int i = 0; i < c; ++i)
    {
        copy(str, str + len, res.str + i * len);
    }
    res.str[res.len] = '\0';

    return res;
}

TString& TString::operator=(const TString& s) 
{
    if (this != &s) 
    {
        delete[] str;
        len = s.len;
        str = new char[len + 1];
        copy(s.str, s.str + len + 1, str);
    }
    return *this;
}

char& TString::operator[](size_t i)
{
    return str[i];
}

bool TString::operator==(const TString& s) const {
    if (len != s.len)
        return false;
    return std::equal(str, str + len, s.str);
}

ostream& operator<<(std::ostream& o, TString& s)
{
    o << s.GetStr();
    return o;
}

istream& operator>>(std::istream& is, TString& str) {
    char buffer[256];
    if (is >> buffer)
    {
        str.SetStr(buffer);
    }
    return is;
}

#pragma clang diagnostic pop