#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "sketch.cpp"

int main(int argc, char const *argv[])
{
    int row=8, col=4096, mult=1000;

    srand (time(NULL));
    sketch s(row,col);
    int i, f, r, c=0, d=0;

    cout << "MEMORY USED: " << row*col*sizeof(int)/1024 << "KB" << endl;

    for (i = 0; i < mult*1000; ++i)
    {
        s.insert(987654);
        s.insert(876543);

        c+=2;
    }

    for (i = 0; i < mult*100; ++i)
    {
        s.insert(1111);
        s.insert(2222);
        s.insert(3333);
        s.insert(4444);

        c+=4;
    }

    for (i = 0; i < mult*50; ++i)
    {
        s.insert(999);
        s.insert(999999);

        c+=2;
    }

    for (i = 0; i < mult*10; ++i)
    {
        s.insert(10);
        s.insert(100);
        s.insert(1000);
        s.insert(10000);
        s.insert(100000);
        s.insert(1000000);

        c+=6;
    }

    for (int i = 0; i < mult; ++i)
    {
        s.insert(12345);
        s.insert(23456);
        s.insert(34567);

        c+=3;
    }

    for (i = 0; i < mult*1000; ++i)
    {
        r = rand();
        if(
            r==987654||r==876543
            ||r==1111||r==2222||r==3333||r==4444
            ||r==999||r==999999
            ||r==10||r==100||r==1000||r==10000||r==100000||r==1000000
            ||r==12345||r==23456||r==34567
            )
        {
            continue;
        }

        s.insert(r);
        d++;
    }

    s.normalize();

    cout << "TOTAL INSERTS: " << c+d << endl;
    cout << "--------" << "--------" << "--------" << endl;
    cout << "ITEM#   " << "EXPECTED" << "  ACTUAL" << endl;
    cout << "--------" << "--------" << "--------" << endl;
    cout << "987654  " <<setw(8) << mult*1000 << setw(8) << s.frequency(987654)  << endl;
    cout << "1111    " <<setw(8) << mult*100  << setw(8) << s.frequency(1111)    << endl;
    cout << "2222    " <<setw(8) << mult*100  << setw(8) << s.frequency(2222)    << endl;
    cout << "3333    " <<setw(8) << mult*100  << setw(8) << s.frequency(3333)    << endl;
    cout << "4444    " <<setw(8) << mult*100  << setw(8) << s.frequency(4444)    << endl;
    cout << "999     " <<setw(8) << mult*50   << setw(8) << s.frequency(999)     << endl;
    cout << "999999  " <<setw(8) << mult*50   << setw(8) << s.frequency(999999)  << endl;
    cout << "10      " <<setw(8) << mult*10   << setw(8) << s.frequency(10)      << endl;
    cout << "100     " <<setw(8) << mult*10   << setw(8) << s.frequency(100)     << endl;
    cout << "1000    " <<setw(8) << mult*10   << setw(8) << s.frequency(1000)    << endl;
    cout << "10000   " <<setw(8) << mult*10   << setw(8) << s.frequency(10000)   << endl;
    cout << "100000  " <<setw(8) << mult*10   << setw(8) << s.frequency(100000)  << endl;
    cout << "1000000 " <<setw(8) << mult*10   << setw(8) << s.frequency(1000000) << endl;
    cout << "12345   " <<setw(8) << mult      << setw(8) << s.frequency(12345)   << endl;
    cout << "23456   " <<setw(8) << mult      << setw(8) << s.frequency(23456)   << endl;
    cout << "34567   " <<setw(8) << mult      << setw(8) << s.frequency(34567)   << endl;
    cout << "RANDOM  " <<setw(8) << d <<endl<<endl;

    return 0;
}
