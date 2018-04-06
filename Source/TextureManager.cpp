#include <TextureManager.h>

bool TextureManager::loadTexture(vector <sf::Texture> &textures, string name, string filename)
{
    sf::Texture texture;
    if(!texture.loadFromFile(filename))
    return 0;
    else
    {
        textures.push_back(texture);
        return 1;
    }
}
