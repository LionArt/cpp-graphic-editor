#include <Canvas.h>

class CanvasManager
{
    public:
    CanvasManager();
    void setCanvasSize(Canvas &canvas);
    int getWidth(Canvas &canvas);
    int getHeight(Canvas &canvas);
};
