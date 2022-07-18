//
// Created by »ªË¶ on 18/7/2022.
//

#include "string1.h"
#include <cstring>

using std::cout;
using std::cin;

int String1::num_strings = 0;

int String1::HowMany() {
    return num_strings;
}

String1::String1(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str,s);
    num_strings++;
    //cout<<num_strings<<": \""<<str<<"\" object created \n";
}

String1::String1()
{
    len = 4;
    str = new char[1];
    str = nullptr;
    num_strings++;
    //cout<<num_strings<<": \""<<str<<"\" object created \n";
}

String1::~String1()
{
    //cout<<": \""<<str<<"\" object deleted, ";
    --num_strings;
    //cout<<num_strings<<" left\n";
    delete [] str;
}

String1::String1(const String1 & st) {
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str,st.str);
}

String1 & String1::operator = (const String1 &st)
{
    if(this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str,st.str);
    return *this;
}

String1 & String1::operator=(const char * s) {
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str,s);
    return *this;
}

char & String1::operator[](int i) {
    return str[i];
}

const char & String1::operator[](int i) const {
    return str[i];
}

bool operator < (const String1 & st1,const String1 & st2)
{
    return (std::strcmp(st1.str,st2.str) < 0);
}

bool operator > (const String1 & st1,const String1 & st2)
{
    return st2<st1;
}

bool operator == (const String1 & st1,const String1 & st2)
{
    return (std::strcmp(st1.str,st2.str) == 0);
}

std::ostream & operator << (std::ostream & os , const String1 & st)
{
    os << st.str;
    return os;
}

std::istream & operator >> (std::istream & is , String1 & st)
{
    char temp[String1::CINLIM];
    is.get(temp,String1::CINLIM);
    if(is)
        st = temp;
    while(is && is.get()!='\n')
        continue;
    return is;
}