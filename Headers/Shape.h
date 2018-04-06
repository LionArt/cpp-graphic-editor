#include <SFML/Graphics.hpp>

using namespace std;

enum class shape{Line,Rectangle,Circle,Bezier};

class Shape
{
    public:
    shape type;
    sf::VertexArray vertices;
    sf::RectangleShape rectangle;
    sf::CircleShape circle;
    sf::Vertex line[2]=
    {
        sf::Vertex(),
        sf::Vertex()
    };
    vector<sf::Vector2f> points;
    Shape(shape type);
};
