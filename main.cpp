#include <windows.h>
#include <gl/glut.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "figura.h"

using namespace std;

int size_x = 640;
int size_y = 480;

Figura *f1 = new Figura();

float toRGBf(int x);
void draw();
void init();
void myMouse(int button, int state, int x, int y);
void drawLines();
void myKeyboard(int key, int x, int y);
void myKeyboard(unsigned char key, int x, int y);

float toRGBf(int x){
    return (float)x/255;
}

void draw(){

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    drawLines();

    glFlush();
}

void drawLines(){

    glBegin(GL_LINE_STRIP);
        for(int i = 0; i < f1->retornaPontos().at(0).at(0); i++)
            glVertex2i(f1->retornaPontos().at(i+1).at(0) , f1->retornaPontos().at(i+1).at(1) );
    glEnd();
    glFlush();
}

void init(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0 , size_x, 0, size_y);
    glClearColor(toRGBf(85), toRGBf(125), toRGBf(145), 1.0f);
}

void myMouse(int button, int state, int x, int y){

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        f1->addPoint(x, (y-size_y)*-1);
        draw();
    }else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        f1->printaPontos();
    }

}

void myKeyboard(int key, int x, int y){

    switch(key){
        case GLUT_KEY_UP:
            cout << "up!" << endl;
            f1->translada(0, 5);
            draw();
            break;

        case GLUT_KEY_DOWN:
            cout << "down!" << endl;
            f1->translada(0, -5);
            draw();
            break;

        case GLUT_KEY_RIGHT:
            cout << "right!" << endl;
            f1->translada(5, 0);
            draw();
            break;

        case GLUT_KEY_LEFT:
            cout << "left!" << endl;
            f1->translada(-5, 0);
            draw();
            break;
    }
}

void myKeyboard(unsigned char key, int x, int y){

    switch(key){
        case 'r':
            cout << "Horario!"<<endl;
            f1->rotaciona(10);
            draw();

            break;

        case 'R':
            cout << "Anti Horario!"<<endl;
            f1->rotaciona(-10);
            draw();
            break;

        case 'e':
            cout << "[+] Escalar" << endl;
            f1->escala(2);
            draw();
            break;

        case 'E':
            cout << "[-] Escalar" << endl;
            f1->escala(-2);
            draw();
            break;
    }
}




int main(void){

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(size_x,size_y);
    glutInitWindowPosition(400,200);
    glutCreateWindow("Transformacoes");
    init();
    glutDisplayFunc(draw);
    glutMouseFunc(myMouse);
    glutSpecialFunc(myKeyboard);
    glutKeyboardFunc(myKeyboard);

    glutMainLoop();
}

