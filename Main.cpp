#include <iostream>
#include "Application.h"

int main()
{
    Application app;
    if(app.run()==0)
    cout<<"Blad z uruchomieniem programu."<<endl;
    return 0;
}
