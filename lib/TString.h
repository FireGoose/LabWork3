//
// Created by Andrey on 20.04.2025.
//

#pragma once
#include <iostream>

using namespace std;


class TString
{
protected:
    char* str;
    int len;
public:
    TString();
    TString(char* str_, int len_);
    TString(char* str_);
    TString(const TString& s);
    TString(TString&& s) noexcept;
    ~TString();

    const char* GetStr();
    int GetLen() const;

    void SetStr(const char* str_);
    void SetLen(int len_);

    TString operator+(const TString& s) const;
    TString operator*(int c) const;
    TString& operator=(const TString& s);

    char& operator[](size_t i);

    bool operator==(const TString& s) const;

    friend std::ostream& operator<<(std::ostream& o, TString& s);
    friend std::istream& operator>>(std::istream& i, TString& s);
};

