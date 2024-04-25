#include <iostream>
#include <graphics.h>
#define LEFT 1
#define RIGHT 4
#define TOP 8
#define BOTTOM 2

using namespace std;

int xmin, xmax, ymin, ymax;
int clipped_x1, clipped_y1, clipped_x2, clipped_y2;

int getRegionCode(float x, float y)
{
    int code = 0;
    if (x < xmin)
        code |= LEFT;
    if (x > xmax)
        code |= RIGHT;
    if (y < ymin)
        code |= TOP;
    if (y > ymax)
        code |= BOTTOM;

    return code;
}

bool midpointsubdivision(float x1, float y1, float x2, float y2)
{
    int code1 = getRegionCode(x1, y1);
    int code2 = getRegionCode(x2, y2);
    if (code1 == 0 && code2 == 0)
    {
        clipped_x1 = x1;
        clipped_y1 = y1;
        clipped_x2 = x2;
        clipped_y2 = y2;
        return true;
    }
    else if ((code1 & code2) != 0)
    {
        return false;
    }

    float xm, ym;
    xm = (x1 + x2) / 2;
    ym = (y1 + y2) / 2;
    int codem = getRegionCode(xm, ym);

    if (codem != 0)
    {
        if ((code1 & codem) != 0)
        {
            x1 = xm;
            y1 = ym;
            return midpointsubdivision(x1, y1, x2, y2);
        }
        else if ((code2 & codem) != 0)
        {
            x2 = xm;
            y2 = ym;
            return midpointsubdivision(x1, y1, x2, y2);
        }
    }

    clipped_x1 = x1;
    clipped_y1 = y1;
    clipped_x2 = x2;
    clipped_y2 = y2;
    return true;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;

    cout << "Enter the co-ordinates of window (BLRU)" << endl;
    cin >> xmin >> ymin >> xmax >> ymax;
    rectangle(xmin, ymin, xmax, ymax);
    cout << "Enter the coordinates (Terminal Points) of the line: ";
    cin >> x1 >> y1 >> x2 >> y2;
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(GREEN);
    line(x1, y1, x2, y2);
    delay(3000);

    if (midpointsubdivision(x1, y1, x2, y2))
    {
        setcolor(YELLOW);
        line(clipped_x1, clipped_y1, clipped_x2, clipped_y2);
    }
    else
    {
        cout << "Line completely outside the window." << endl;
    }
    cout << clipped_x1 << clipped_y1 << clipped_x2 << clipped_y2 << endl;

    getch();
    closegraph();
    return 0;
}
