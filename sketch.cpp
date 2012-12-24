#include "sketch.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

#define ROW 7
#define COL 2000

#define LARGE 2147483647
#define MOD 2147483647
#define HL 31

sketch::sketch(int r, int c) 
{
    srand (time(NULL)); 
    row = r>1 ? r : ROW; 
    col = c>1 ? c : COL; 

    A = new int[row];
    B = new int[row];
    matrix = new int* [row];

    for (int i = 0; i < row; ++i)
    {
        matrix[i] = new int[col];
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
    if(amount < 1)
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
    if(amount < 1)
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
        std::cout << "|";
        for (int j = 0; j < col; ++j)
        {
            std::cout << std::setw(4) << matrix[i][j] << " | ";
        }
        std::cout << std::endl;
    }
}

