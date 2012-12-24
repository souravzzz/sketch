#include "sketch.cpp"

int main(int argc, char const *argv[])
{
    sketch s(4,10);
    unsigned int i, f;
    srand (time(NULL));

    do
    {
        cout << "item >>" ;
        cin >> i;
        s.insert(i);
        f = s.frequency(i);
        cout << "freq >>" << f << endl;
        s.print();
    } while (i>0);
}

