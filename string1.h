//
// Created by »ªË¶ on 18/7/2022.
//

#ifndef CHAPTER12_STRING1_H
#define CHAPTER12_STRING1_H

#include <iostream>

class String1 {
private:
    char * str;
    int len;
    static int num_strings;
    static const int  CINLIM = 80;
public:
    String1(const char * s);
    String1();
    ~String1();
    String1(const String1 &);
    int lenth () const {return len;}

    String1 & operator = (const String1 &);
    String1 & operator = (const char *);
    char & operator [] (int i);
    const char & operator [] (int i) const;

    friend bool operator < (const String1 & st1,const String1 & st2);
    friend bool operator > (const String1 & st1,const String1 & st2);
    friend bool operator == (const String1 & st1,const String1 & st2);
    friend std::ostream & operator << (std::ostream & os , const String1 & st);
    friend std::istream & operator >> (std::istream & is , String1 & st);

    static int HowMany();
};


#endif //CHAPTER12_STRING1_H
