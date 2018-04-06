#include <iostream>
#include <ApplicationManager.h>
#include <vector>

using namespace std;

class Application
{
    private:
    vector <sf::Texture> textures;
    vector <Shape> shapes;
    vector <Button> buttons;
    vector <uint8_t> color;
    string name="Edytor graficzny";
    status applicationStatus=status::Start;
    ApplicationManager am;
    CanvasManager cm;
    TextureManager tm;
    sf::RenderWindow window;
    Canvas canvas;
    public:
    Application();
    bool run();
};
