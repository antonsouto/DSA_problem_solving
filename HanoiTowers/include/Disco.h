#ifndef DISCO_H
#define DISCO_H



using namespace std;


class Disco {

    private:
    int tamaño;
    static int count;
    
    
    public:
    Disco();
    ~Disco();
    int getTamaño() const;

};

#endif