#include "figura.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#define PI 3.14159265

using namespace std;

Figura::Figura(){
    vector<int> aux;
    aux.push_back(0);
    points.push_back(aux);
}

void Figura::addPoint(int x, int y){

    vector<int> aux;
    aux.push_back(x);
    aux.push_back(y);
    points.push_back(aux);
    points.at(0).at(0)++;
}

void Figura::printaPontos(){
    for(int i = 0; i < points.size(); i++){
        if(points.at(i).size() == 2){
            cout << "x: " << points.at(i).at(0) << "  y: " << points.at(i).at(1) << endl;
        }
        else
            cout << points.at(i).at(0) << endl;
    }
}

vector<vector<int> > Figura::retornaPontos(){
    return points;
}

void Figura::translada(int x, int y){

    for(int i = 1; i < points.size(); i++){
        points.at(i).at(0)+=x;
        points.at(i).at(1)+=y;
    }
}

void Figura::rotaciona(int angulo){

    int aux_x;
    int aux_y;

    vector<int> CM = retornaCM();
    cout << "antigo CM" << endl << "x:  " << CM.at(0) << "  y:  " << CM.at(1) << endl;
    translada(-CM.at(0), -CM.at(1));
    cout << "novo CM: " << endl << "x:  " << retornaCM().at(0) << "  y:  " << retornaCM().at(1) << endl;

    for(int i = 1; i < points.size(); i++){
        aux_x = points.at(i).at(0);
        aux_y = points.at(i).at(1);

        points.at(i).at(0) = aux_x*cos(angulo*PI/180) - aux_y*sin(angulo*PI/180);
        points.at(i).at(1) = aux_x*sin(angulo*PI/180) + aux_y*cos(angulo*PI/180);

    }
    translada(CM.at(0), CM.at(1));

}

void Figura::escala(int modulo){

    int aux_x;
    int aux_y;

    vector<int> CM = retornaCM();
    cout << "antigo CM" << endl << "x:  " << CM.at(0) << "  y:  " << CM.at(1) << endl;
    translada(-CM.at(0), -CM.at(1));
    cout << "novo CM: " << endl << "x:  " << retornaCM().at(0) << "  y:  " << retornaCM().at(1) << endl;

    for(int i = 1; i < points.size(); i++){
        if(modulo>0){
            points.at(i).at(0) *= modulo;
            points.at(i).at(1) *= modulo;
        }else
            if(modulo<0){
                points.at(i).at(0) /= -modulo;
                points.at(i).at(1) /= -modulo;
            }
    }
    translada(CM.at(0), CM.at(1));
}

vector<int> Figura::retornaCM(){
    int aux_x = 0;
    int aux_y = 0;
    vector<int> CM;

    for(int i = 1; i < points.size(); i++){
        aux_x += points.at(i).at(0);
        aux_y += points.at(i).at(1);
    }

    aux_x /= points.at(0).at(0);
    aux_y /= points.at(0).at(0);

    CM.push_back(aux_x);
    CM.push_back(aux_y);

    return CM;
}


