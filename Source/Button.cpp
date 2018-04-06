#include <Button.h>

Button::Button(string n,int w,int h,sf::Texture &t)
{
    name=n;
    posx=w;
    posy=h;
    sprite.setTexture(t);
    sprite.setPosition(sf::Vector2f(w,h));
}
