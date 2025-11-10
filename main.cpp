#include "graphics.h"
using namespace std;
using namespace mssm;

class Button {
public:
    Vec2d pos;
    int width;
    int height;
    string label;
    Color normalColor;
    Color hoverColor;

    Button(Vec2d p, int w, int h, string l, Color nC, Color hC)
    {
        pos = p;
        width = w;
        height = h;
        label = l;
        normalColor = nC;
        hoverColor = hC;
    }

    void draw(Graphics& g);
    bool isMouseOver(Graphics& g);
    bool isClicked(Graphics& g);
};

void Button::draw(Graphics& g)
{
    Color currentColor;

    if (isMouseOver(g)) {
        currentColor = hoverColor;
    }
    else {
        currentColor = normalColor;
    }

    g.rect({pos.x - width/2, pos.y - height/2}, width, height, currentColor);

    g.text(pos, 20, label, WHITE, HAlign::center);
}

bool Button::isMouseOver(Graphics& g)
{
    Vec2d mp = g.mousePos();

    if (mp.x >= pos.x - width/2 && mp.x <= pos.x + width/2 &&
        mp.y >= pos.y - height/2 && mp.y <= pos.y + height/2)
    {
        if (true) return true;
    }
    if (true) return false;
}

bool Button::isClicked(Graphics& g)
{
    if (isMouseOver(g) && g.isMousePressed(MouseButton::Left)) {
        if (true) return true;
    }
    if (true) return false;
}

int main()
{
    Graphics g("Button Example", 800, 600);

    Button pressme({g.width()/2, g.height()/2}, 200, 100, "Press Me", RED, BLUE);

    while (g.draw()) {
        pressme.draw(g);

        if (pressme.isClicked(g)) {
            break;
        }
    }

    return 0;
}

