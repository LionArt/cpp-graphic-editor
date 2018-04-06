#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class TextureManager
{
    private:
    public:
    bool loadTexture(vector <sf::Texture> &textures, string name, string filename);
};
