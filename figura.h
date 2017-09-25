#ifndef FIGURA_H
#define FIGURA_H
#include <vector>
#define PI 3.14159265
using namespace std;

class Figura{

private:
    vector<vector<int> > points;
public:
    Figura();
    void addPoint(int x, int y);
    void printaPontos();
    void translada(int x, int y);
    void rotaciona(int angulo);
    void escala(int modulo);
    vector<vector<int> > retornaPontos();
    vector<int> retornaCM();

};

#endif // FIGURA_H
