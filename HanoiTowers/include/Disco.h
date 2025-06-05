#ifndef DISCO_H
#define DISCO_H

#include <vector>


using namespace std;


class Disco {

    private:
    int tamaño;
    static int count;
    static vector<int> tamañosUsados;
    
    
    public:
    Disco();
    Disco(int);
    ~Disco();
    int getTamaño() const;
    void print();

};

#endif