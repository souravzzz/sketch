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

