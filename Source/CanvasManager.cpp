#include <CanvasManager.h>
#include <iostream>

using namespace std;

CanvasManager::CanvasManager()
{
    cout<<"Utworzona zostala instancja menadzera kanwy."<<endl;
}

void CanvasManager::setCanvasSize(Canvas &canvas)
{
    int w=0,h=0;
    while(w<=0 || w>MAX_CANVAS_WIDTH)
    {
        cout<<"Podaj szerokosc kanwy."<<endl;
        cin>>w;
        if(w<=0 || w>MAX_CANVAS_WIDTH)
        {
            cout<<"Szerokosc nie moze byc rowna/mniejsza 0 oraz wieksza niz "<<MAX_CANVAS_WIDTH<<"."<<endl;
        }

    }
    canvas.setWidth(w+65);
    while(h<=0 || h>MAX_CANVAS_HEIGHT)
    {
        cout<<"Podaj wysokosc kanwy."<<endl;
        cin>>h;
        if(h<=0 || h>MAX_CANVAS_HEIGHT)
        {
            cout<<"Wysokosc nie moze byc rowna/mniejsza 0 oraz wieksza niz "<<MAX_CANVAS_HEIGHT<<"."<<endl;
        }
    }
    canvas.setHeight(h);
}

int CanvasManager::getWidth(Canvas &canvas)
{
    return canvas.getWidth();
}

int CanvasManager::getHeight(Canvas &canvas)
{
    return canvas.getHeight();
}
