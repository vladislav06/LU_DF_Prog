class Darray{
private:
    int n;
    int* arr;
    void fill_array();
public:
    Darray(int n);
    Darray(Darray* darray);
    ~Darray();
    float array_avg();
    void print_array();

};
