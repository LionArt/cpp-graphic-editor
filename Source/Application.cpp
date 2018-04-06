#include <Application.h>

using namespace std;

Application::Application()
{
    cout<<"Zostala utworzona instancja aplikacji."<<endl;
}
bool Application::run ()
{
    // Utworzenie jednej instancji Application Managera, ktory bedzie zarzadzac funkcjami aplikacji
    // Utworzenie jednej instancji Canvas Managera, ktory bedzie zarzadzac kanwa
    cout<<"Uruchomienie aplikacji."<<endl;
    am.prepareWindow(window,cm); // Przygotowanie okna
    am.loadTextures(textures,tm);
    am.loadButtons(buttons,textures);
    am.handleWindowEvents(applicationStatus,window,applicationStatus,buttons,shapes); // Wyswietlenie okna i przetwarzanie eventow w trakcie jego istnienia
    return 1;
}
