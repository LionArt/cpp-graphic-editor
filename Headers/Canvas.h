#define MAX_CANVAS_WIDTH 1366
#define MAX_CANVAS_HEIGHT 768

class Canvas
{
    private:
    int width;
    int height;
    public:
    Canvas();
    void setWidth(int width);
    void setHeight(int height);
    int getWidth();
    int getHeight();
};
