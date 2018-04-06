#include <iostream>
#include <SFML/Graphics.hpp>
#include <CanvasManager.h>
#include <TextureManager.h>
#include <Button.h>
#include <Shape.h>
#include <cmath>
#include <fstream>

enum class status{Start,Line,Rectangle,Circle,Options,PPMP3,JPGPNG,RGBCMYK,RGB,CMYK,Color,RGBCUBE,HSVCONE,Image,ImageLoaded,ImageAdd,ImageSubstract,ImageMultiply,ImageDivide,ImageBrightness,ImageGray,ImageH1,ImageH2,ImageBinTresh,ImageBinBlack,ImageBinMean,ImageBinEntropy,ImageBinMinimumError,ImageBinFuzzyMinimumError,Bezier,Transform,Move,Resize,Degree,Dilatation,Erosion,Open,Close};

class ApplicationManager
{
    public:
    ApplicationManager();
    bool prepareWindow(sf::RenderWindow &window,CanvasManager &cm);
    bool handleWindowEvents(status &applicationStatus,sf::RenderWindow &window, status appStatus, vector <Button> &buttons, vector <Shape> &shapes);
    bool loadTextures(vector <sf::Texture> &textures,TextureManager &tm);
    bool loadButtons(vector <Button> &buttons, vector <sf::Texture> &textures);
    bool drawButtons(vector <Button> &buttons,sf::RenderWindow &window);
    bool drawRGBCMYKButtons(vector <Button> &buttons,sf::RenderWindow &window);
    bool drawImageButtons(vector <Button> &buttons,sf::RenderWindow &window);
    bool drawTransformButtons(vector <Button> &buttons,sf::RenderWindow &window);
    bool drawShapes(vector <Shape> &shapes,sf::RenderWindow &window);
};
