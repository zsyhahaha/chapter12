//
// Created by 华硕 on 18/7/2022.
//
#include "queue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
    srand(time(0));

    cout<<"Case study: Bank of HAT\n";
    cout<<"Enter maximum size of queue: ";
    int qs;
    cin>>qs;
    Queue line1(qs);
    Queue line2(qs);

    cout<<"Enter the number of simulation hours: ";
    int hours;
    cin>>hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout<<"Enter the average number of customers per hour: ";
    double perhour;
    cin>>perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time1 = 0;
    int wait_time2 = 0;
    long line_wait = 0;
    for(int cycle = 0;cycle < cyclelimit; cycle++)
    {
        if(newcustomer(min_per_cust))
        {
            if(line1.isfull() && line2.isfull())
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);
                if (line1.queuecount() <= line2.queuecount()) //第一台ATM机人数小于第二台;
                {
                    line1.enqueue(temp); //顾客排在第一队;
                }
                else
                {
                    line2.enqueue(temp); //否则排在第二队;
                }
            }
        }
        if (wait_time1 <= 0 && !line1.isempty())
        {
            line1.dequeue(temp);
            wait_time1 = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time1 > 0)
        {
            wait_time1--;
        }
        sum_line += line1.queuecount();
        if (wait_time2 <= 0 && !line2.isempty())
        {
            line2.dequeue(temp);
            wait_time2 = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time2 > 0)
        {
            wait_time2--;
        }
        sum_line += line2.queuecount();

    }

    if(customers > 0)
    {
        cout<<"customers accepted: "<<customers<<endl;
        cout<<"  customers served: "<<served<<endl;
        cout<<"         turnaways: "<<turnaways<<endl;
        cout<<"average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout<<(double) sum_line / cyclelimit << endl;
        cout<<" average wait time: "<<(double)line_wait / served << " minutes\n";
    }
    else
        cout<<"No customers!\n";
    cout<<"Done."<<endl;
    return 0;
}

bool newcustomer(double x)
{
    return (rand() * x / RAND_MAX < 1);
}