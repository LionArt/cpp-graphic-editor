#include <ApplicationManager.h>

using namespace std;

std::vector<sf::Vector2f> CalcCubicBezier(
        const sf::Vector2f &start,
        const sf::Vector2f &end,
        const sf::Vector2f &startControl,
        const sf::Vector2f &endControl,
        const size_t numSegments)
{
    std::vector<sf::Vector2f> ret;
    if (!numSegments) // Any points at all?
        return ret;

    ret.push_back(start); // First point is fixed
    float p = 1.f / numSegments;
    float q = p;
    for (size_t i = 1; i < numSegments; i++, p += q) // Generate all between
        ret.push_back(p * p * p * (end + 3.f * (startControl - endControl) - start) +
                      3.f * p * p * (start - 2.f * startControl + endControl) +
                      3.f * p * (startControl - start) + start);
    ret.push_back(end); // Last point is fixed
    return ret;
}

status checkPressedButton(sf::Vector2i v, status current)
{
    if((int)current<6 || current==status::Bezier)
    {
        if((v.x>=801 && v.x<=833) && (v.y>=0 && v.y<=31))
        {
            cout<<"Rysowanie linii."<<endl;
            return status::Line;
        }
        else if((v.x>=834 && v.x<=866) && (v.y>=0 && v.y<=31))
        {
            cout<<"Rysowanie okregu."<<endl;
            return status::Circle;
        }
        else if((v.x>=867 && v.x<=899) && (v.y>=0 && v.y<=31))
        {
            cout<<"Rysowanie prostokata."<<endl;
            return status::Rectangle;
        }
        else if((v.x>=801 && v.x<=833) && (v.y>=33 && v.y<=64))
        {
            cout<<"Wczytywanie pliku PPMP3."<<endl;
            return status::PPMP3;
        }
        else if((v.x>=834 && v.x<=866) && (v.y>=33 && v.y<=64))
        {
            cout<<"Wczytywanie pliku JPG/PNG."<<endl;
            return status::JPGPNG;
        }
        else if((v.x>=867 && v.x<=899) && (v.y>=33 && v.y<=64))
        {
            cout<<"RGB/CMYK."<<endl;
            return status::RGBCMYK;
        }
        else if((v.x>=801 && v.x<=833) && (v.y>=66 && v.y<=99))
        {
            cout<<"Wczytywanie obrazu i operacje na nim."<<endl;
            return status::Image;
        }
        else if((v.x>=834 && v.x<=866) && (v.y>=66 && v.y<=99))
        {
            cout<<"Rysowanie linii Beziera."<<endl;
            return status::Bezier;
        }
        else if((v.x>=867 && v.x<=899) && (v.y>=66 && v.y<=99))
        {
            cout<<"Transformacja objektow 2D."<<endl;
            return status::Transform;
        }
        else return current;
    }
    else if((int)current>=6 && (int)current<13)
    {
        if((v.x>=801 && v.x<=833) && (v.y>=0 && v.y<=31))
        {
            cout<<"Powrot do poprzedniego menu."<<endl;
            return status::Start;
        }
        else if((v.x>=834 && v.x<=866) && (v.y>=0 && v.y<=31))
        {
            cout<<"Kolor RGB."<<endl;
            return status::RGB;
        }
        else if((v.x>=867 && v.x<=899) && (v.y>=0 && v.y<=31))
        {
            cout<<"Kolor CMYK."<<endl;
            return status::CMYK;
        }
        else if((v.x>=801 && v.x<=833) && (v.y>=33 && v.y<=64))
        {
            cout<<"Aktualny kolor."<<endl;
            return status::Color;
        }
        else if((v.x>=834 && v.x<=866) && (v.y>=33 && v.y<=64))
        {
            cout<<"Wyswietlenie kostki RGB."<<endl;
            return status::RGBCUBE;
        }
        else if((v.x>=867 && v.x<=899) && (v.y>=33 && v.y<=64))
        {
            cout<<"Wyswietlenie stozka HSV."<<endl;
            return status::HSVCONE;
        }
        else return current;
    }
     else if((int)current>12 && (int)current<29)
    {
        if((v.x>=834 && v.x<=866) && (v.y>=0 && v.y<=31))
        {
            cout<<"Dodawanie."<<endl;
            return status::ImageAdd;
        }
        else if((v.x>=867 && v.x<=899) && (v.y>=0 && v.y<=31))
        {
            cout<<"Odejmowanie."<<endl;
            return status::ImageSubstract;
        }
        else if((v.x>=801 && v.x<=833) && (v.y>=33 && v.y<=64))
        {
            cout<<"Mnozenie."<<endl;
            return status::ImageMultiply;
        }
        else if((v.x>=834 && v.x<=866) && (v.y>=33 && v.y<=64))
        {
            cout<<"Dzielenie."<<endl;
            return status::ImageDivide;
        }
        else if((v.x>=867 && v.x<=899) && (v.y>=33 && v.y<=64))
        {
            cout<<"Zmiana jasnosci."<<endl;
            return status::ImageBrightness;
        }
        else if((v.x>=801 && v.x<=833) && (v.y>=66 && v.y<=97))
        {
            cout<<"Zmiana skali szarosci."<<endl;
            return status::ImageGray;
        }
        else if((v.x>=834 && v.x<=866) && (v.y>=66 && v.y<=97))
        {
            cout<<"Rozszerzenie histogramu."<<endl;
            return status::ImageH1;
        }
        else if((v.x>=867 && v.x<=899) && (v.y>=66 && v.y<=97))
        {
            cout<<"Wyrownanie histogramu."<<endl;
            return status::ImageH2;
        }
        else if((v.x>=801 && v.x<=833) && (v.y>=99 && v.y<=130))
        {
            cout<<"Binaryzacja z progiem podanym przez uzytkownika."<<endl;
            return status::ImageBinTresh;
        }
        else if((v.x>=834 && v.x<=866) && (v.y>=99 && v.y<=130))
        {
            cout<<"Binaryzacja z procentowa selekcja koloru czarnego."<<endl;
            return status::ImageBinBlack;
        }
        else if((v.x>=867 && v.x<=899) && (v.y>=99 && v.y<=130))
        {
            cout<<"Binaryzacja z selekcja iteratywna sredniej."<<endl;
            return status::ImageBinMean;
        }
        else if((v.x>=801 && v.x<=833) && (v.y>=132 && v.y<=163))
        {
            cout<<"Binaryzacja z selekcja entropii."<<endl;
            return status::ImageBinEntropy;
        }
        else if((v.x>=834 && v.x<=866) && (v.y>=132 && v.y<=163))
        {
            cout<<"Binaryzacja z bledem minimalnym."<<endl;
            return status::ImageBinMinimumError;
        }
        else if((v.x>=867 && v.x<=899) && (v.y>=132 && v.y<=163))
        {
            cout<<"Binaryzacja z metoda rozmytego bledu minimalnego."<<endl;
            return status::ImageBinFuzzyMinimumError;
        }
        else if((v.x>=801 && v.x<=833) && (v.y>=165 && v.y<=196))
        {
             cout<<"Dylatacja."<<endl;
            return status::Dilatation;
        }
        else if((v.x>=834 && v.x<=866) && (v.y>=165 && v.y<=196))
        {
             cout<<"Erozja."<<endl;
            return status::Erosion;
        }
        else if((v.x>=867 && v.x<=899) && (v.y>=165 && v.y<=196))
        {
             cout<<"Otwarcie."<<endl;
            return status::Open;
        }
        else if((v.x>=801 && v.x<=833) && (v.y>=198 && v.y<=229))
        {
             cout<<"Zamkniecie."<<endl;
            return status::Close;
        }
        else if((v.x>=801 && v.x<=833) && (v.y>=0 && v.y<=31))
        {
             cout<<"Powrot do poprzedniego menu."<<endl;
            return status::Start;
        }
        else return current;
    }
    else if((int)current>29 && (int)current<34)
    {
        if((v.x>=801 && v.x<=833) && (v.y>=0 && v.y<=31))
        {
             cout<<"Powrot do poprzedniego menu."<<endl;
            return status::Start;
        }
        else if((v.x>=834 && v.x<=866) && (v.y>=0 && v.y<=31))
        {
             cout<<"Zmiana pozycji obiektu."<<endl;
            return status::Move;
        }
        else if((v.x>=867 && v.x<=899) && (v.y>=0 && v.y<=31))
        {
             cout<<"Skalowanie obiektu."<<endl;
            return status::Resize;
        }
        else if((v.x>=801 && v.x<=833) && (v.y>=32 && v.y<=64))
        {
             cout<<"Obrocenie obiektu."<<endl;
            return status::Degree;
        }
        else
        return current;
    }
    else return current;
}

bool checkCanvas(sf::Vector2i v)
{
    if((v.x<=800 && v.x>=0) && (v.y>=0 && v.y<=600))
    {
        return 1;
    }
    else
    return 0;
}

int scaleInRGB(int x, int scale)
{
    double temp,percent;
    percent=double(scale)/100;
    temp=double(x/percent);
    x=round(255*(double(temp/100)));
    return x;
}

void CMYKtoRGB(double cyan, double magenta, double yellow, double black, int &red, int &green, int &blue)
{
    red=(255*(1-cyan)*(1-black));
    green=(255*(1-magenta)*(1-black));
    blue=(255*(1-yellow)*(1-black));
}

void RGBtoCMYK(int red,int green,int blue, double &cyan, double &magenta, double &yellow, double &black)
{
    double r,g,b,maximum;
    r=double(red)/255;
    g=double(green)/255;
    b=double(blue)/255;
    maximum=max(r,b);
    maximum=max(maximum,g);
    black=1-maximum;
    if(black!=1)
    {
        cyan=((1-r-black)/(1-black));
        magenta=((1-g-black)/(1-black));
        yellow=((1-b-black)/(1-black));
    }
    else
    {
        cyan=0;
        magenta=0;
        yellow=0;
    }
}

void RGBtoHSL(int red,int green,int blue,double &hue,double &saturation,double &luminosity)
{
    double r,g,b,maximum,minimum,delta;
    r=double(red)/255;
    g=double(green)/255;
    b=double(blue)/255;
    maximum=max(r,b);
    minimum=min(r,b);
    maximum=max(maximum,g);
    minimum=min(minimum,g);
    delta=maximum-minimum;
    hue=0;
    saturation=0;
    luminosity=(double)(maximum+minimum)/2;
    if(delta!=0)
    {
        saturation=delta/(1-abs((2*luminosity)-1));
        if(maximum==r)
        {
            hue=((g-b)/delta);
            hue=6*hue;
        }
        else if(maximum==g)
        {
            hue=6*(((b-r)/delta)+2);
        }
        else if(maximum==b)
        {
            hue=6*(((r-g)/delta)+4);
        }
    }
    hue=hue*10;
    hue=round(hue);
    hue=(int)hue;
    if(hue<0)
    hue=hue+360;
}

void HSLtoRGB(double hue,double saturation, double luminosity,int &red, int &green, int&blue)
{
    double r,g,b,c,x,m;
    int h;
    c=(1-(abs((2*luminosity)-1)))*saturation;
    h=hue/60;
    x=c*(1-abs(fmod((h),2)-1));
    m=luminosity-(c/2);
    if(hue>=0 && hue<60)
    {
        r=c;
        g=x;
        b=0;
    }
    else if(hue>=60 && hue<120)
    {
        r=x;
        g=c;
        b=0;
    }
    else if(hue>=120 && hue<180)
    {
        r=0;
        g=c;
        b=x;
    }
    else if(hue>=180 && hue<240)
    {
        r=0;
        g=x;
        b=c;
    }
    else if(hue>=240 && hue<300)
    {
        r=x;
        g=0;
        b=c;
    }
    else if(hue>=300 && hue<360)
    {
        r=c;
        g=0;
        b=x;
    }
    red=round((r+m)*255);
    green=round((g+m)*255);
    blue=round((b+m)*255);

}

ApplicationManager::ApplicationManager()
{
    cout<<"Utworzona zostala instancja menadzera aplikacji."<<endl;
}

bool ApplicationManager::prepareWindow(sf::RenderWindow &window,CanvasManager &cm)
{
    window.create(sf::VideoMode(898,600),"Edytor graficzny",sf::Style::Default);
    return 1;
}

bool ApplicationManager::loadTextures(vector <sf::Texture> &textures,TextureManager &tm)
{
    tm.loadTexture(textures,"Line","Buttons/line.png");
    tm.loadTexture(textures,"Circle","Buttons/circle.png");
    tm.loadTexture(textures,"Rectangle","Buttons/rectangle.png");
    tm.loadTexture(textures,"PPMP3","Buttons/PPMP3.png");
    tm.loadTexture(textures,"JPGPNG","Buttons/JPGPNG.png");
    tm.loadTexture(textures,"RGBCMYK","Buttons/RGBCMYK.png");
    tm.loadTexture(textures,"Back","Buttons/back.png");
    tm.loadTexture(textures,"RGB","Buttons/RGB.png");
    tm.loadTexture(textures,"CMYK","Buttons/CMYK.png");
    tm.loadTexture(textures,"Color","Buttons/color.png");
    tm.loadTexture(textures,"RGBCube","Buttons/cube.png");
    tm.loadTexture(textures,"HSVCone","Buttons/cone.png");
    tm.loadTexture(textures,"Image","Buttons/image.png");
    tm.loadTexture(textures,"Add","Buttons/add.png");
    tm.loadTexture(textures,"Substract","Buttons/substract.png");
    tm.loadTexture(textures,"Multiply","Buttons/multiply.png");
    tm.loadTexture(textures,"Divide","Buttons/divide.png");
    tm.loadTexture(textures,"Brightness","Buttons/brightness.png");
    tm.loadTexture(textures,"Gray","Buttons/gray.png");
    tm.loadTexture(textures,"H1","Buttons/h1.png");
    tm.loadTexture(textures,"H2","Buttons/h2.png");
    tm.loadTexture(textures,"BinTresh","Buttons/bin_treshold.png");
    tm.loadTexture(textures,"BinBlack","Buttons/bin_blackpercentage.png");
    tm.loadTexture(textures,"BinMean","Buttons/bin_mean.png");
    tm.loadTexture(textures,"BinEntropy","Buttons/bin_entropy.png");
    tm.loadTexture(textures,"BinMinError","Buttons/bin_minerror.png");
    tm.loadTexture(textures,"BinFuz","Buttons/bin_fuz.png");
    tm.loadTexture(textures,"Bezier","Buttons/bezier.png");
    tm.loadTexture(textures,"Transform","Buttons/transform.png");
    tm.loadTexture(textures,"Move","Buttons/move.png");
    tm.loadTexture(textures,"Resize","Buttons/resize.png");
    tm.loadTexture(textures,"Degree","Buttons/degree.png");
    tm.loadTexture(textures,"Dilatation","Buttons/dilatation.png");
    tm.loadTexture(textures,"Erosion","Buttons/erosion.png");
    tm.loadTexture(textures,"Open","Buttons/open.png");
    tm.loadTexture(textures,"Close","Buttons/close.png");
}

bool ApplicationManager::loadButtons(vector <Button> &buttons,vector <sf::Texture> &textures)
{
    Button line("Line",800,0,textures[0]);
    buttons.push_back(line);
    Button circle("Circle",833,0,textures[1]);
    buttons.push_back(circle);
    Button rectangle("Rectangle",866,0,textures[2]);
    buttons.push_back(rectangle);
    Button ppmp3("PPMP3",800,33,textures[3]);
    buttons.push_back(ppmp3);
    Button jpgpng("JPGPNG",833,33,textures[4]);
    buttons.push_back(jpgpng);
    Button rgbcmyk("RGBCMYK",866,33,textures[5]);
    buttons.push_back(rgbcmyk);
    Button back("Back",800,0,textures[6]);
    buttons.push_back(back);
    Button rgb("RGB",833,0,textures[7]);
    buttons.push_back(rgb);
    Button cmyk("CMYK",866,0,textures[8]);
    buttons.push_back(cmyk);
    Button color("Color",800,33,textures[9]);
    buttons.push_back(color);
    Button rgbcube("RGBCube",833,33,textures[10]);
    buttons.push_back(rgbcube);
    Button hsvcone("HSVCone",866,33,textures[11]);
    buttons.push_back(hsvcone);
    Button image("Image",800,66,textures[12]);
    buttons.push_back(image);
    Button add("Add",833,0,textures[13]);
    buttons.push_back(add);
    Button substract("Substract",866,0,textures[14]);
    buttons.push_back(substract);
    Button multiply("Multiply",800,33,textures[15]);
    buttons.push_back(multiply);
    Button divide("Divide",833,33,textures[16]);
    buttons.push_back(divide);
    Button brightness("Brightness",866,33,textures[17]);
    buttons.push_back(brightness);
    Button gray("Gray",800,66,textures[18]);
    buttons.push_back(gray);
    Button h1("H1",833,66,textures[19]);
    buttons.push_back(h1);
    Button h2("H2",866,66,textures[20]);
    buttons.push_back(h2);
    Button bintresh("BinTresh",800,99,textures[21]);
    buttons.push_back(bintresh);
    Button binblack("BinBlack",833,99,textures[22]);
    buttons.push_back(binblack);
    Button binmean("BinMean",866,99,textures[23]);
    buttons.push_back(binmean);
    Button binentropy("BinEntropy",800,132,textures[24]);
    buttons.push_back(binentropy);
    Button binminerror("BinMinError",833,132,textures[25]);
    buttons.push_back(binminerror);
    Button binfuz("BinFuz",866,132,textures[26]);
    buttons.push_back(binfuz);
    Button bezier("Bezier",833,66,textures[27]);
    buttons.push_back(bezier);
    Button transform("Transform",866,66,textures[28]);
    buttons.push_back(transform);
    Button move("Move",833,0,textures[29]);
    buttons.push_back(move);
    Button resize("Resize",866,0,textures[30]);
    buttons.push_back(resize);
    Button degree("Degree",800,33,textures[31]);
    buttons.push_back(degree);
    Button dilatation("Dilatation",800,165,textures[32]);
    buttons.push_back(dilatation);
    Button erosion("Erosion",833,165,textures[33]);
    buttons.push_back(erosion);
    Button open("Open",866,165,textures[34]);
    buttons.push_back(open);
    Button close("Close",800,198,textures[35]);
    buttons.push_back(close);
}

bool ApplicationManager::drawButtons(vector <Button> &buttons,sf::RenderWindow &window)
{
    for(int i=0;i<6;i++)
    {
        window.draw(buttons[i].sprite);
    }
    window.draw(buttons[12].sprite);
    window.draw(buttons[27].sprite);
    window.draw(buttons[28].sprite);
}

bool ApplicationManager::drawRGBCMYKButtons(vector <Button> &buttons,sf::RenderWindow &window)
{
    for(int i=6;i<12;i++)
    {
        window.draw(buttons[i].sprite);
    }
}

bool ApplicationManager::drawImageButtons(vector <Button> &buttons,sf::RenderWindow &window)
{
    window.draw(buttons[6].sprite);
    for(int i=13;i<27;i++)
    {
        window.draw(buttons[i].sprite);
    }
    for(int i=32;i<36;i++)
    {
        window.draw(buttons[i].sprite);
    }
}

bool ApplicationManager::drawTransformButtons(vector <Button> &buttons,sf::RenderWindow &window)
{
    window.draw(buttons[6].sprite);
    for(int i=29;i<32;i++)
    {
        window.draw(buttons[i].sprite);
    }
}

bool ApplicationManager::drawShapes(vector <Shape> &shapes,sf::RenderWindow &window)
{
    for(int i=0;i<shapes.size();i++)
    {
        if(shapes[i].type==shape::Circle)
        window.draw(shapes[i].circle);
        else
        if(shapes[i].type==shape::Rectangle)
        window.draw(shapes[i].rectangle);
        else
        if(shapes[i].type==shape::Line)
        window.draw(shapes[i].line,2,sf::Lines);
        else
        if(shapes[i].type==shape::Bezier)
        window.draw(shapes[i].vertices);
    }
}

bool ApplicationManager::handleWindowEvents(status &applicationStatus,sf::RenderWindow &window,status appStatus, vector <Button> &buttons, vector<Shape> &shapes)
{
    sf::RectangleShape rgbcmykrectangle;
    rgbcmykrectangle.setFillColor(sf::Color(0,0,0,255));
    rgbcmykrectangle.setOutlineColor(sf::Color(0,0,0,255));
    rgbcmykrectangle.setSize(sf::Vector2f(400,400));
    rgbcmykrectangle.setPosition(sf::Vector2f(200,100));

    sf::RectangleShape transformrectangle;
    transformrectangle.setFillColor(sf::Color(0,0,0,255));
    transformrectangle.setOutlineColor(sf::Color(0,0,0,255));
    transformrectangle.setSize(sf::Vector2f(400,400));
    transformrectangle.setPosition(sf::Vector2f(200,100));

    sf::VertexArray cube1(sf::Quads,4);
    cube1[0].position=sf::Vector2f(300,200);
    cube1[1].position=sf::Vector2f(500,200);
    cube1[2].position=sf::Vector2f(500,400);
    cube1[3].position=sf::Vector2f(300,400);
    cube1[0].color=sf::Color::Yellow;
    cube1[1].color=sf::Color::White;
    cube1[2].color=sf::Color::Cyan;
    cube1[3].color=sf::Color::Green;
    sf::VertexArray cube2(sf::Quads,4);
    cube2[0].position=sf::Vector2f(352,148);
    cube2[1].position=sf::Vector2f(551,148);
    cube2[2].position=sf::Vector2f(499,200);
    cube2[3].position=sf::Vector2f(300,200);
    cube2[0].color=sf::Color::Red;
    cube2[1].color=sf::Color::Magenta;
    cube2[2].color=sf::Color::White;
    cube2[3].color=sf::Color::Yellow;
    sf::VertexArray cube3(sf::Quads,4);
    cube3[0].position=sf::Vector2f(499,200);
    cube3[1].position=sf::Vector2f(551,148);
    cube3[2].position=sf::Vector2f(551,348);
    cube3[3].position=sf::Vector2f(500,400);
    cube3[0].color=sf::Color::White;
    cube3[1].color=sf::Color::Magenta;
    cube3[2].color=sf::Color::Blue;
    cube3[3].color=sf::Color::Cyan;

    sf::Texture coneTexture;
    sf::Sprite coneSprite;

    sf::Texture imageTexture;
    sf::Sprite imageSprite;

    if(!coneTexture.loadFromFile("cone.jpg"))
    {
        cout<<"Blad podczas odczytywania pliku."<<endl;
        return 0;
    }
    coneSprite.setTexture(coneTexture);
    coneSprite.setPosition(275,150);
    applicationStatus=status::Start;
    sf::Vector2i startingPos;
    sf::Vector2i endingPos;
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                applicationStatus=checkPressedButton(sf::Mouse::getPosition(window),applicationStatus);
                if(checkCanvas(sf::Mouse::getPosition(window)) && applicationStatus!=status::Start)
                {
                    startingPos=sf::Mouse::getPosition(window);
                }
                switch(applicationStatus)
                    {
                        case status::PPMP3:
                            {
                                cout<<"Podaj sciezke pliku PPMP3."<<endl;
                                string file;
                                if(!getline(cin,file))
                                {
                                    cout<<"Niepoprawna nazwa pliku."<<endl;
                                    break;
                                }
                                else
                                {
                                    fstream ppmp3_file;
                                    ppmp3_file.open(file,fstream::in);
                                    if(!ppmp3_file.is_open())
                                    cout<<"Plik nie istnieje."<<endl;
                                    else
                                    {
                                        cout<<"Znaleziono plik."<<endl;
                                        string format;
                                        int width,height,scale;
                                        ppmp3_file>>format>>width>>height>>scale;
                                        if((format!="P3") || (width==0 || height==0))
                                        {
                                            cout<<"Blad podczas wczytywania pliku."<<endl;
                                            ppmp3_file.close();
                                            return 0;
                                        }
                                        sf::Uint8* pixels = new sf::Uint8[width * height * 4];
                                        for(int i=0;i<(width*height);i++)
                                        {
                                            int x,y,z;
                                            ppmp3_file>>x>>y>>z;
                                            x=scaleInRGB(x,scale);
                                            y=scaleInRGB(y,scale);
                                            z=scaleInRGB(z,scale);
                                            pixels[0+(i*4)]=x;
                                            pixels[1+(i*4)]=y;
                                            pixels[2+(i*4)]=z;
                                            pixels[3+(i*4)]=255;
                                        }
                                        ppmp3_file.close();
                                        sf::Texture texture;
                                        sf::Sprite sprite;
                                        texture.create(width,height);
                                        texture.update(pixels);
                                        sprite.setTexture(texture);
                                        sf::RenderWindow tempWindow(sf::VideoMode(width,height),file);
                                        while(tempWindow.isOpen())
                                        {
                                            sf::Event event;
                                            while (tempWindow.pollEvent(event))
                                            {
                                                // "close requested" event: we close the window
                                                if (event.type == sf::Event::Closed)
                                                {
                                                    cout<<"Czy chcesz zapisac plik jako JPG? (T/N)"<<endl;
                                                    char q;
                                                    while((q!='N' && q!='n') && (q!='T') && (q!='t'))
                                                    {
                                                        cin>>q;
                                                    }
                                                    if(q=='T' || q=='t')
                                                    {
                                                        sf::Image img;
                                                        img=texture.copyToImage();
                                                        if(!img.saveToFile((file.substr(0,file.size()-4))+".jpg"))
                                                        cout<<"Nie udalo sie zapisac pliku."<<endl;
                                                        else
                                                        cout<<"Zapisano!"<<endl;
                                                    }
                                                    delete pixels;
                                                    tempWindow.close();
                                                }
                                            }

                                            // clear the window with black color
                                            tempWindow.clear(sf::Color::White);

                                            // draw everything here...
                                            // window.draw(...);

                                            // end the current frame
                                            tempWindow.draw(sprite);
                                            tempWindow.display();
                                        }

                                    }
                                }
                                applicationStatus=status::Start;
                                break;
                            }

                            case status::JPGPNG:
                            {
                                cout<<"Podaj sciezke pliku JPG/PNG."<<endl;
                                string file;
                                if(!getline(cin,file))
                                {
                                    cout<<"Niepoprawna nazwa pliku."<<endl;
                                }
                                else
                                {
                                    fstream jpgpng_file;
                                    jpgpng_file.open(file,fstream::in);
                                    if(!jpgpng_file.is_open())
                                    {
                                        cout<<"Plik nie istnieje."<<endl;
                                    }
                                    else
                                    {
                                            cout<<"Znaleziono plik."<<endl;
                                            sf::Texture texture;
                                            sf::Sprite sprite;
                                            if(!texture.loadFromFile(file))
                                            {
                                                cout<<"Blad podczas odczytywania pliku."<<endl;
                                                break;
                                            }
                                            sprite.setTexture(texture);
                                            sf::RenderWindow tempWindow(sf::VideoMode(texture.getSize().x,texture.getSize().y),file);
                                            while(tempWindow.isOpen())
                                            {
                                                sf::Event event;
                                                while (tempWindow.pollEvent(event))
                                                {
                                                    // "close requested" event: we close the window
                                                    if (event.type == sf::Event::Closed)
                                                        tempWindow.close();
                                                }

                                                // clear the window with black color
                                                tempWindow.clear(sf::Color::White);

                                                // draw everything here...
                                                // window.draw(...);

                                                // end the current frame
                                                tempWindow.draw(sprite);
                                                tempWindow.display();
                                            }

                                        }
                                    }
                                applicationStatus=status::Start;
                                break;
                            }
                        case status::RGB:
                        {
                            int red=-1,green=-1,blue=-1;
                            while((red>255 || red<0) || (green>255 || green<0) || (blue>255 || blue<0))
                            {
                                 cout<<"Podaj kolory RGB."<<endl;
                                 cin>>red>>green>>blue;
                                 cin.clear();
                                 cin.ignore();
                            }
                            rgbcmykrectangle.setFillColor(sf::Color(red,green,blue));
                            rgbcmykrectangle.setOutlineColor(sf::Color(red,green,blue));
                            applicationStatus=status::RGBCMYK;
                            break;
                        }
                        case status::CMYK:
                        {
                            double cyan=-1,magenta=-1,yellow=-1,black=-1;
                            int red=-1,green=-1,blue=-1;
                            while((cyan>1 || cyan<0) || (magenta>1 || magenta<0) || (yellow>1 || yellow<0) || (black>1 || black<0))
                            {
                                 cout<<"Podaj kolory CMYK."<<endl;
                                 cin>>cyan>>magenta>>yellow>>black;
                                 cin.clear();
                                 cin.ignore();
                            }
                            CMYKtoRGB(cyan,magenta,yellow,black,red,green,blue);
                            rgbcmykrectangle.setFillColor(sf::Color(red,green,blue));
                            rgbcmykrectangle.setOutlineColor(sf::Color(red,green,blue));
                            applicationStatus=status::RGBCMYK;
                            break;
                        }
                        case status::Color:
                        {
                            double cyan,magenta,yellow,black;
                            int red,green,blue;
                            red=rgbcmykrectangle.getFillColor().r;
                            green=rgbcmykrectangle.getFillColor().g;
                            blue=rgbcmykrectangle.getFillColor().b;
                            RGBtoCMYK(red,green,blue,cyan,magenta,yellow,black);
                            cout<<"RGB: ("<<red<<":"<<green<<":"<<blue<<")"<<endl;
                            cout<<"CMYK: ("<<cyan<<":"<<magenta<<":"<<yellow<<":"<<black<<")"<<endl;
                            applicationStatus=status::RGBCMYK;
                            break;
                        }
                        case status::Image:
                        {
                            string file;
                            cout<<"Podaj nazwe obrazu."<<endl;
                            cin>>file;
                            cin.clear();
                            cin.ignore();
                            if(!imageTexture.loadFromFile(file))
                            {
                                cout<<"Blad podczas wczytywania obrazu."<<endl;
                                applicationStatus=status::Start;
                                break;
                            }
                            else
                            if(imageTexture.getSize().x>800 || imageTexture.getSize().y>600)
                            {
                                cout<<"Obraz jest za duzy. Maksymalny rozmiar obrazu - 800:600."<<endl;
                                applicationStatus=status::Start;
                                break;
                            }
                            else
                            {
                                applicationStatus=status::ImageLoaded;
                                imageSprite.setTexture(imageTexture);
                            }
                            break;
                        }
                        case status::ImageAdd:
                        {
                            sf::Image temp;
                            int x,add;
                            int r,g,b;
                            cout<<"Podaj wartosc jaka chcesz dodac do obrazu."<<endl;
                            cin>>add;
                            cin.clear();
                            cin.ignore();
                            temp=imageTexture.copyToImage();
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                x=temp.getPixel(j,i).r+add;
                                if(x>255)
                                x=255;
                                else if(x<0)
                                x=0;
                                r=x;

                                x=temp.getPixel(j,i).g+add;
                                if(x>255)
                                x=255;
                                else if(x<0)
                                x=0;
                                g=x;

                                x=temp.getPixel(j,i).b+add;
                                if(x>255)
                                x=255;
                                else if(x<0)
                                x=0;
                                b=x;

                                temp.setPixel(j,i,sf::Color(r,g,b));
                            }
                            imageTexture.loadFromImage(temp);
                            applicationStatus=status::ImageLoaded;
                            break;
                        }

                        case status::ImageSubstract:
                        {
                            sf::Image temp;
                            int x,sub;
                            int r,g,b;
                            cout<<"Podaj wartosc jaka chcesz odjac od obrazu."<<endl;
                            cin>>sub;
                            cin.clear();
                            cin.ignore();
                            temp=imageTexture.copyToImage();
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                x=temp.getPixel(j,i).r-sub;
                                if(x>255)
                                x=255;
                                else if(x<0)
                                x=0;
                                r=x;

                                x=temp.getPixel(j,i).g-sub;
                                if(x>255)
                                x=255;
                                else if(x<0)
                                x=0;
                                g=x;

                                x=temp.getPixel(j,i).b-sub;
                                if(x>255)
                                x=255;
                                else if(x<0)
                                x=0;
                                b=x;

                                temp.setPixel(j,i,sf::Color(r,g,b));
                            }
                            imageTexture.loadFromImage(temp);
                            applicationStatus=status::ImageLoaded;
                            break;
                        }

                        case status::ImageMultiply:
                        {
                            sf::Image temp;
                            int x,mul;
                            int r,g,b;
                            cout<<"Podaj wartosc jaka chcesz pomnozyc z obrazem."<<endl;
                            cin>>mul;
                            cin.clear();
                            cin.ignore();
                            temp=imageTexture.copyToImage();
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                x=temp.getPixel(j,i).r*mul;
                                if(x>255)
                                x=255;
                                else if(x<0)
                                x=0;
                                r=x;

                                x=temp.getPixel(j,i).g*mul;
                                if(x>255)
                                x=255;
                                else if(x<0)
                                x=0;
                                g=x;

                                x=temp.getPixel(j,i).b*mul;
                                if(x>255)
                                x=255;
                                else if(x<0)
                                x=0;
                                b=x;

                                temp.setPixel(j,i,sf::Color(r,g,b));
                            }
                            imageTexture.loadFromImage(temp);
                            applicationStatus=status::ImageLoaded;
                            break;
                        }

                        case status::ImageDivide:
                        {
                            sf::Image temp;
                            int x,div=0;
                            int r,g,b;
                            while(div==0)
                            {
                                cout<<"Podaj wartosc jaka chcesz aby zostala podzielona przez obraz."<<endl;
                                cin>>div;
                                cin.clear();
                                cin.ignore();
                            }
                            temp=imageTexture.copyToImage();
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                x=temp.getPixel(j,i).r/div;
                                if(x>255)
                                x=255;
                                else if(x<0)
                                x=0;
                                r=x;

                                x=temp.getPixel(j,i).g/div;
                                if(x>255)
                                x=255;
                                else if(x<0)
                                x=0;
                                g=x;

                                x=temp.getPixel(j,i).b/div;
                                if(x>255)
                                x=255;
                                else if(x<0)
                                x=0;
                                b=x;

                                temp.setPixel(j,i,sf::Color(r,g,b));
                            }
                            imageTexture.loadFromImage(temp);
                            applicationStatus=status::ImageLoaded;
                            break;
                        }

                        case status::ImageBrightness:
                        {
                            sf::Image temp;
                            int r,g,b,bri=-101;
                            double h,s,l;
                            while(bri<-100 || bri>100)
                            {
                                cout<<"Podaj wartosc jasnosci obrazu (-100-100)."<<endl;
                                cin>>bri;
                                cin.clear();
                                cin.ignore();
                            }
                            temp=imageTexture.copyToImage();
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                r=temp.getPixel(j,i).r;
                                g=temp.getPixel(j,i).g;
                                b=temp.getPixel(j,i).b;
                                RGBtoHSL(r,g,b,h,s,l);
                                l=l+((double)bri/100);
                                if(l<0)
                                l=0;
                                if(l>1)
                                l=1;
                                HSLtoRGB(h,s,l,r,g,b);
                                temp.setPixel(j,i,sf::Color(r,g,b));
                            }
                            imageTexture.loadFromImage(temp);
                            applicationStatus=status::ImageLoaded;
                            break;
                        }
                        case status::ImageGray:
                        {
                            sf::Image temp;
                            int r,g,b,sat=-101;
                            double h,s,l;
                            while(sat<-100 || sat>100)
                            {
                                cout<<"Podaj wartosc szarosci obrazu (-100-100)."<<endl;
                                cin>>sat;
                                cin.clear();
                                cin.ignore();
                            }
                            temp=imageTexture.copyToImage();
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                r=temp.getPixel(j,i).r;
                                g=temp.getPixel(j,i).g;
                                b=temp.getPixel(j,i).b;
                                RGBtoHSL(r,g,b,h,s,l);
                                s=s+((double)sat/100);
                                if(s<0)
                                s=0;
                                if(s>1)
                                s=1;
                                HSLtoRGB(h,s,l,r,g,b);
                                temp.setPixel(j,i,sf::Color(r,g,b));
                            }
                            imageTexture.loadFromImage(temp);
                            applicationStatus=status::ImageLoaded;
                            break;
                        }
                        case status::ImageH1:
                        {
                            sf::Image temp;
                            int r,g,b;
                            double h,s,l,lmax,lmin;
                            temp=imageTexture.copyToImage();
                            r=temp.getPixel(0,0).r;
                            g=temp.getPixel(0,0).g;
                            b=temp.getPixel(0,0).b;
                            RGBtoHSL(r,g,b,h,s,l);
                            lmin=l;
                            lmax=l;
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                r=temp.getPixel(j,i).r;
                                g=temp.getPixel(j,i).g;
                                b=temp.getPixel(j,i).b;
                                RGBtoHSL(r,g,b,h,s,l);
                                if(l>lmax)
                                lmax=l;
                                if(l<lmin)
                                lmin=l;
                            }
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                r=temp.getPixel(j,i).r;
                                g=temp.getPixel(j,i).g;
                                b=temp.getPixel(j,i).b;
                                RGBtoHSL(r,g,b,h,s,l);
                                l=(1/(lmax-lmin))*(l-lmin);
                                if(l>1)
                                l=1;
                                if(l<0)
                                l=0;
                                HSLtoRGB(h,s,l,r,g,b);
                                temp.setPixel(j,i,sf::Color(r,g,b));
                            }
                            imageTexture.loadFromImage(temp);
                            applicationStatus=status::ImageLoaded;
                            break;
                        }
                        case status::ImageBinTresh:
                        {
                            sf::Image temp;
                            int r,g,b,tresh=-1;
                            double h,s,l;
                            while(tresh<0 || tresh>255)
                            {
                                cout<<"Podaj wartosc progu (0-255)."<<endl;
                                cin>>tresh;
                                cin.clear();
                                cin.ignore();
                            }
                            temp=imageTexture.copyToImage();
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                r=temp.getPixel(j,i).r;
                                g=temp.getPixel(j,i).g;
                                b=temp.getPixel(j,i).b;
                                RGBtoHSL(r,g,b,h,s,l);
                                if(round(l*255)>=tresh)
                                {
                                    r=255;
                                    g=255;
                                    b=255;
                                }
                                else
                                {
                                    r=0;
                                    g=0;
                                    b=0;
                                }
                                temp.setPixel(j,i,sf::Color(r,g,b));
                            }
                            imageTexture.loadFromImage(temp);
                            applicationStatus=status::ImageLoaded;
                            break;
                        }
                        case status::ImageBinBlack:
                        {
                            sf::Image temp;
                            int r,g,b,black=-1;
                            double h,s,l;
                            while(black<0 || black>100)
                            {
                                cout<<"Podaj wartosc progu (0-100)."<<endl;
                                cin>>black;
                                cin.clear();
                                cin.ignore();
                            }
                            temp=imageTexture.copyToImage();
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                r=temp.getPixel(j,i).r;
                                g=temp.getPixel(j,i).g;
                                b=temp.getPixel(j,i).b;
                                RGBtoHSL(r,g,b,h,s,l);
                                if(round(l*100)>=black)
                                {
                                    r=255;
                                    g=255;
                                    b=255;
                                }
                                else
                                {
                                    r=0;
                                    g=0;
                                    b=0;
                                }
                                temp.setPixel(j,i,sf::Color(r,g,b));
                            }
                            imageTexture.loadFromImage(temp);
                            applicationStatus=status::ImageLoaded;
                            break;
                        }
                        case status::ImageBinMean:
                        {
                            sf::Image temp;
                            int r,g,b;
                            double h,s,l,mean=0;
                            temp=imageTexture.copyToImage();

                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                r=temp.getPixel(j,i).r;
                                g=temp.getPixel(j,i).g;
                                b=temp.getPixel(j,i).b;
                                RGBtoHSL(r,g,b,h,s,l);
                                mean=mean+l;
                            }
                            mean=mean/(temp.getSize().x*temp.getSize().y);
                            mean=mean*255;
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                r=temp.getPixel(j,i).r;
                                g=temp.getPixel(j,i).g;
                                b=temp.getPixel(j,i).b;
                                RGBtoHSL(r,g,b,h,s,l);
                                if(round(l*255)>=mean)
                                {
                                    r=255;
                                    g=255;
                                    b=255;
                                }
                                else
                                {
                                    r=0;
                                    g=0;
                                    b=0;
                                }
                                temp.setPixel(j,i,sf::Color(r,g,b));
                            }
                            imageTexture.loadFromImage(temp);
                            applicationStatus=status::ImageLoaded;
                            break;
                        }
                        case status::Dilatation:
                        {
                            sf::Image temp;
                            sf::Image temp2;
                            int north,east,south,west;
                            temp=imageTexture.copyToImage();
                            temp2=imageTexture.copyToImage();
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                north=255;
                                east=255;
                                south=255;
                                west=255;
                                if(j!=0)
                                west=temp.getPixel(j-1,i).r;
                                if(j!=(temp.getSize().x-1))
                                east=temp.getPixel(j+1,i).r;
                                if(i!=0)
                                west=temp.getPixel(j,i-1).r;
                                if(i!=(temp.getSize().y-1))
                                east=temp.getPixel(j,i+1).r;
                                if(north==0 || east==0 || south==0 || west==0)
                                temp2.setPixel(j,i,sf::Color(0,0,0));

                            }
                            imageTexture.loadFromImage(temp2);
                            applicationStatus=status::ImageLoaded;
                            break;
                        }
                        case status::Close:
                        {
                            sf::Image temp;
                            sf::Image temp2;
                            int north,east,south,west;
                            temp=imageTexture.copyToImage();
                            temp2=imageTexture.copyToImage();
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                north=255;
                                east=255;
                                south=255;
                                west=255;
                                if(j!=0)
                                west=temp.getPixel(j-1,i).r;
                                if(j!=(temp.getSize().x-1))
                                east=temp.getPixel(j+1,i).r;
                                if(i!=0)
                                west=temp.getPixel(j,i-1).r;
                                if(i!=(temp.getSize().y-1))
                                east=temp.getPixel(j,i+1).r;
                                if(north==0 || east==0 || south==0 || west==0)
                                temp2.setPixel(j,i,sf::Color(0,0,0));

                            }
                            imageTexture.loadFromImage(temp2);
                            temp=imageTexture.copyToImage();
                            temp2=imageTexture.copyToImage();
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                north=0;
                                east=0;
                                south=0;
                                west=0;
                                if(j!=0)
                                west=temp.getPixel(j-1,i).r;
                                if(j!=(temp.getSize().x-1))
                                east=temp.getPixel(j+1,i).r;
                                if(i!=0)
                                west=temp.getPixel(j,i-1).r;
                                if(i!=(temp.getSize().y-1))
                                east=temp.getPixel(j,i+1).r;
                                if(north==255 || east==255 || south==255 || west==255)
                                temp2.setPixel(j,i,sf::Color(255,255,255));

                            }
                            imageTexture.loadFromImage(temp2);
                            applicationStatus=status::ImageLoaded;
                            break;
                        }
                        case status::Erosion:
                        {
                            sf::Image temp;
                            sf::Image temp2;
                            int north,east,south,west;
                            temp=imageTexture.copyToImage();
                            temp2=imageTexture.copyToImage();
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                north=0;
                                east=0;
                                south=0;
                                west=0;
                                if(j!=0)
                                west=temp.getPixel(j-1,i).r;
                                if(j!=(temp.getSize().x-1))
                                east=temp.getPixel(j+1,i).r;
                                if(i!=0)
                                west=temp.getPixel(j,i-1).r;
                                if(i!=(temp.getSize().y-1))
                                east=temp.getPixel(j,i+1).r;
                                if(north==255 || east==255 || south==255 || west==255)
                                temp2.setPixel(j,i,sf::Color(255,255,255));

                            }
                            imageTexture.loadFromImage(temp2);
                            applicationStatus=status::ImageLoaded;
                            break;
                        }
                        case status::Open:
                        {
                            sf::Image temp;
                            sf::Image temp2;
                            int north,east,south,west;
                            temp=imageTexture.copyToImage();
                            temp2=imageTexture.copyToImage();
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                north=0;
                                east=0;
                                south=0;
                                west=0;
                                if(j!=0)
                                west=temp.getPixel(j-1,i).r;
                                if(j!=(temp.getSize().x-1))
                                east=temp.getPixel(j+1,i).r;
                                if(i!=0)
                                west=temp.getPixel(j,i-1).r;
                                if(i!=(temp.getSize().y-1))
                                east=temp.getPixel(j,i+1).r;
                                if(north==255 || east==255 || south==255 || west==255)
                                temp2.setPixel(j,i,sf::Color(255,255,255));

                            }
                            imageTexture.loadFromImage(temp2);

                            temp=imageTexture.copyToImage();
                            temp2=imageTexture.copyToImage();
                            for(int i=0;i<temp.getSize().y;i++)
                            for(int j=0;j<temp.getSize().x;j++)
                            {
                                north=255;
                                east=255;
                                south=255;
                                west=255;
                                if(j!=0)
                                west=temp.getPixel(j-1,i).r;
                                if(j!=(temp.getSize().x-1))
                                east=temp.getPixel(j+1,i).r;
                                if(i!=0)
                                west=temp.getPixel(j,i-1).r;
                                if(i!=(temp.getSize().y-1))
                                east=temp.getPixel(j,i+1).r;
                                if(north==0 || east==0 || south==0 || west==0)
                                temp2.setPixel(j,i,sf::Color(0,0,0));

                            }
                            imageTexture.loadFromImage(temp2);
                            applicationStatus=status::ImageLoaded;
                            break;
                        }
                        case status::Move:
                        {
                            sf::Vector2f v;
                            cout<<"Podaj wektor przesuniecia."<<endl;
                            cin>>v.x>>v.y;
                            cin.clear();
                            cin.ignore();
                            transformrectangle.move(v);
                            applicationStatus=status::Transform;
                            break;
                        }
                        case status::Resize:
                        {
                            sf::Vector2f v;
                            cout<<"Podaj wektor skali."<<endl;
                            cin>>v.x>>v.y;
                            cin.clear();
                            cin.ignore();
                            transformrectangle.scale(v);
                            applicationStatus=status::Transform;
                            break;
                        }
                        case status::Degree:
                        {
                            int angle;
                            cout<<"Podaj kat o jaki chcesz obrocic obiekt."<<endl;
                            cin>>angle;
                            cin.clear();
                            cin.ignore();
                            transformrectangle.rotate(angle);
                            applicationStatus=status::Transform;
                            break;
                        }
                        default:
                        break;
                    }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if(checkCanvas(sf::Mouse::getPosition(window)) && applicationStatus!=status::Start)
                {
                    endingPos=sf::Mouse::getPosition(window);
                    switch(applicationStatus)
                    {
                        case status::Line:
                        {
                            Shape line(shape::Line);
                            line.line[0].position=static_cast<sf::Vector2f>(startingPos);
                            line.line[0].color=sf::Color::Black;
                            line.line[1].position=static_cast<sf::Vector2f>(endingPos);
                            line.line[1].color=sf::Color::Black;
                            shapes.push_back(line);
                            cout<<"Rysuje linie."<<endl;
                            break;
                        }
                        case status::Rectangle:
                        {
                            Shape rectangle(shape::Rectangle);
                            rectangle.rectangle.setOutlineColor(sf::Color::Black);
                            rectangle.rectangle.setOutlineThickness(1);
                            rectangle.rectangle.setFillColor(sf::Color::Transparent);
                            float x=abs(startingPos.x-endingPos.x);
                            float y=abs(startingPos.y-endingPos.y);
                            rectangle.rectangle.setSize(sf::Vector2f(x,y));
                            if(startingPos.y>=endingPos.y && startingPos.x>=endingPos.x)
                            rectangle.rectangle.setPosition(static_cast<sf::Vector2f>(endingPos));
                            else if(startingPos.y<=endingPos.y && startingPos.x<=endingPos.x)
                            rectangle.rectangle.setPosition(static_cast<sf::Vector2f>(startingPos));
                            else if(startingPos.y>=endingPos.y && startingPos.x<=endingPos.x)
                            rectangle.rectangle.setPosition(static_cast<sf::Vector2f>(sf::Vector2i(startingPos.x,endingPos.y)));
                            else if(startingPos.y<=endingPos.y && startingPos.x>=endingPos.x)
                            rectangle.rectangle.setPosition(static_cast<sf::Vector2f>(sf::Vector2i(endingPos.x,startingPos.y)));
                            shapes.push_back(rectangle);
                            cout<<"Rysuje prostokat."<<endl;
                            break;
                        }

                        case status::Circle:
                        {
                            Shape circle(shape::Circle);
                            circle.circle.setOutlineColor(sf::Color::Black);
                            circle.circle.setOutlineThickness(1);
                            circle.circle.setFillColor(sf::Color::Transparent);
                            float radius=(abs(startingPos.y-endingPos.y))/2;
                            circle.circle.setRadius(radius);
                            circle.circle.setPointCount(100);
                            if(startingPos.y>=endingPos.y && startingPos.x>=endingPos.x)
                            circle.circle.setPosition(static_cast<sf::Vector2f>(endingPos));
                            else if(startingPos.y<=endingPos.y && startingPos.x<=endingPos.x)
                            circle.circle.setPosition(static_cast<sf::Vector2f>(startingPos));
                            else if(startingPos.y>=endingPos.y && startingPos.x<=endingPos.x)
                            circle.circle.setPosition(static_cast<sf::Vector2f>(sf::Vector2i(startingPos.x,endingPos.y)));
                            else if(startingPos.y<=endingPos.y && startingPos.x>=endingPos.x)
                            circle.circle.setPosition(static_cast<sf::Vector2f>(sf::Vector2i(endingPos.x,startingPos.y)));
                            shapes.push_back(circle);
                            cout<<"Rysuje okrag."<<endl;
                            break;
                        }
                        case status::Bezier:
                        {
                            Shape bezier(shape::Bezier);
                            bezier.vertices.setPrimitiveType(sf::LinesStrip);
                            bezier.vertices.resize(0);
                            bezier.points =
                            CalcCubicBezier(
                            sf::Vector2f(static_cast<sf::Vector2f>(startingPos)),
                            sf::Vector2f(static_cast<sf::Vector2f>(endingPos)),
                            sf::Vector2f(startingPos.x, startingPos.y+50),
                            sf::Vector2f(endingPos.x, startingPos.y+50),
                            100);
                            for (std::vector<sf::Vector2f>::const_iterator a = bezier.points.begin(); a != bezier.points.end(); ++a)
                            bezier.vertices.append(sf::Vertex(*a, sf::Color::Black));
                            shapes.push_back(bezier);
                            cout<<"Rysuje linie beziera."<<endl;
                            break;
                        }
                    }
                }
            }

        }
        window.clear(sf::Color::White);
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(801, 0),sf::Color::Black),
            sf::Vertex(sf::Vector2f(801, 600),sf::Color::Black)
        };

        sf::RectangleShape rectangle(sf::Vector2f(98,600));
        rectangle.setPosition(802,0);
        /*render()
        {
            clearWindow();
            drawEverything();
            display();
        }*/
        if((int)applicationStatus<6 || applicationStatus==status::Bezier)
        drawShapes(shapes,window);
        else if((int)applicationStatus>=6 && (int)applicationStatus<11)
        window.draw(rgbcmykrectangle);
        else if((int)applicationStatus==11)
        {
            window.draw(cube1);
            window.draw(cube2);
            window.draw(cube3);
        }
        else if((int)applicationStatus==12)
        window.draw(coneSprite);
        else if((int)applicationStatus>=30 && (int)applicationStatus<34)
        window.draw(transformrectangle);
        window.draw(rectangle);
        window.draw(line,2,sf::Lines);
        if((int)applicationStatus<6 || applicationStatus==status::Bezier)
        drawButtons(buttons,window);
        else if((int)applicationStatus>=6 && (int)applicationStatus<13)
        drawRGBCMYKButtons(buttons,window);
        else if(((int)applicationStatus>=13 && (int)applicationStatus<29) || (applicationStatus==status::Dilatation || applicationStatus==status::Erosion || applicationStatus==status::Open || applicationStatus==status::Close))
        {
            drawImageButtons(buttons,window);
            window.draw(imageSprite);
        }
        else
        {
            drawTransformButtons(buttons,window);
        }
        window.display();
    }
}
