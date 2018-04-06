#include <Canvas.h>
#include <iostream>

using namespace std;

Canvas::Canvas()
{
    cout<<"Utworzenie obiektu kanwy."<<endl;
}

int Canvas::getHeight()
{
    return height;
}

int Canvas::getWidth()
{
    return width;
}

void Canvas::setHeight(int h)
{
    height=h;
    cout<<"Wysokosc kanwy zostala ustawiona na "<<h<<"."<<endl;
}

void Canvas::setWidth(int w)
{
    width=w;
     cout<<"Szerokosc kanwy zostala ustawiona na "<<w-65<<"."<<endl;
}
