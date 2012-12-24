#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>

#define ROW 7
#define COL 2000

#define LARGE 2147483647
#define MOD 2147483647
#define HL 31

using namespace std;

class sketch
{
public:
	sketch(int r, int c);
	~sketch();
    int insert(int key, int amount=1);
    int remove(int key, int amount=1);
	int frequency(int);
    void normalize();
	void print();

private:
    int row, col;
	int **matrix;
	int *A, *B;
	int hash(int key, int i);
};

sketch::sketch(int r, int c) 
{
    if(r<=0)
        row = ROW;
    else
        row = r;

    if(c<=0)
        col = COL;
    else
        col = c;

    matrix = new int* [row];
    for(int i=0; i<row; i++)
        matrix[i] = new int[col];

    A = new int[row];
    B = new int[row];

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			matrix[i][j] = 0;
		}
		A[i] = rand();
		B[i] = rand(); 
	}
}

sketch::~sketch()
{
    for(int i=0; i<row; i++)
        delete[] matrix[i];

    delete [] matrix;
    delete [] A;
    delete [] B;
}

int sketch::insert(int key, int amount)
{
    if(amount <= 0)
        return -1;

    for(int i=0; i<row; i++)
    {
        int h = hash(key,i);
        matrix[i][h] += amount;
    }

    return 0;
}

int sketch::remove(int key, int amount)
{
    if(amount <= 0)
        return -1;

    for(int i=0; i<row; i++)
    {
        int h = hash(key,i);
        matrix[i][h] -= amount;
    }

    return 0;
}

int sketch::frequency(int key)
{
	int minf=LARGE;

	for (int i = 0; i < row; ++i)
	{
		int f = matrix[i][hash(key,i)];
		if(f<minf)
		{
			minf = f;
		}
	}
	return minf;
}

int sketch::hash(int k, int i)
{
	int a = A[i];
	int b = B[i];

	int result = a*k + b;
	result = ((result >> HL) + result) & MOD;
	
	return (int)(result%col);
}

void sketch::normalize()
{
    for(int i = 0; i < row; ++i)
    {
        int min = LARGE;
        for(int j = 0; j < col; ++j)
        {
            if(matrix[i][j] < min)
                min = matrix[i][j];
        }
        for(int j = 0; j < col; ++j)
        {
            matrix[i][j] -= min;
        }
    }
}

void sketch::print()
{
	for (int i = 0; i < row; ++i)
	{
		cout << "|";
		for (int j = 0; j < col; ++j)
		{
			cout << setw(4) << matrix[i][j] << " | ";
		}
		cout << endl;
	}
}
