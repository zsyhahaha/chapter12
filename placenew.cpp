//
// Created by »ªË¶ on 18/7/2022.
//
#include <iostream>
#include <string>
#include <new>

using namespace std;
const int BUF = 512;

class Test
{
private:
    string words;
    int number;
public:
    Test(const string & s = "Testing",int n = 0)
    {
        words = s;
        number = n;
        cout<<words<<" constructed\n";
    }
    ~Test()
    {
        cout<<words<<" destroyed\n";
    }
    void show() const
    {
        cout<<words<<", "<<number<<endl;
    }
};

int main()
{
    char * buffer = new char[BUF];
    Test * pc1, * pc2;
    pc1 = new (buffer) Test;
    pc2 = new Test("Heap1",20);

    cout<<"Memory block address: \nbuffer:"<<(void *)buffer<<"    heap: "<<pc2<<endl;
    cout<<"Memory contents:\n";
    cout<<pc1<<": ";
    pc1->show();
    cout<<pc2<<": ";
    pc2->show();

    Test * pc3,* pc4;
    pc3 = new (buffer + sizeof (Test)) Test("Bad idea",6);
    pc4 = new Test("Heap2",10);

    cout<<pc3<<": ";
    pc3->show();
    cout<<pc4<<": ";
    pc4->show();

    delete pc2;
    delete pc4;

    pc3->~Test();
    pc1->~Test();

    delete [] buffer;
    cout<<"Done"<<endl;
    return 0;
}