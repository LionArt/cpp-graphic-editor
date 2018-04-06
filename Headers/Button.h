#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Button
{
    private:
    string name;
    int posx;
    int posy;
    public:
    Button(string n,int w,int h, sf::Texture &t);
    sf::Sprite sprite;
};
