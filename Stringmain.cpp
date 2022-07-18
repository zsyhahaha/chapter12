#include <iostream>
#include <cstdlib>
#include <ctime>
#include "string1.h"

using namespace std;

const int Arsize = 10;
const int Maxlen = 81;

int main() {
    String1 name;
    cout<<"Hi,What's your name?\n";
    cin>>name;

    cout<<name<<", please enter up to "<<Arsize<<" short sayings (empty line to quit) :"<<endl;
    String1 sayings[Arsize];
    char temp[Maxlen];
    int i;
    for(i = 0;i < Arsize;i++)
    {
        cout<<i+1<<": ";
        cin.get(temp,Maxlen);
        while (cin && cin.get()!='\n')
            continue;
        if(!cin||temp[0]=='\0')
            break;
        else
            sayings[i] = temp;
    }
    int total = i;

    if(total > 0)
    {
        cout<<"Here are your sayings: \n";
        for (int i = 0; i < total; i++)
            cout<<sayings[i][0]<<": "<<sayings[i]<<endl;

        int shortest = 0;
        int first = 0;
        for(int i = 0; i < total; i++)
        {
            if(sayings[i].lenth() < sayings[shortest].lenth())
                shortest = i;
            if(sayings[i] < sayings[first])
                first = i;
        }
        cout<<"Shortest saying: "<<sayings[shortest]<<endl;
        cout<<"First alphabetically: "<<sayings[first]<<endl;
        srand(time(0));
        int choice = rand() % total;
        String1 * favorite = new String1(sayings[choice]);
        cout<<"My favorite saying is: "<<* favorite<<endl;
        cout<<"The program used "<<String1::HowMany()<<" string objects"<<endl;
        cout<<"Bye."<<endl;
    }
    else
        cout<<"Not input!"<<endl;
   // system("pause");
    return 0;
}

