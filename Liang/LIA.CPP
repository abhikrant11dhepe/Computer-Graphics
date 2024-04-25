#include <iostream>
#include <graphics.h>

using namespace std;

void clip(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    float tE = 0, tL = 1;

    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

    for (int i = 0; i < 4; ++i)
    {
        if (p[i] == 0 && q[i] < 0)
        {
            return; // Line is completely outside
        }
        if (p[i] != 0)
        {
            float t = q[i] / p[i];
            if (p[i] < 0)
            {
                if (t > tE)
                    tE = t;
            }
            else
            {
                if (t < tL)
                    tL = t;
            }
        }
    }

    if (tE < tL)
    {
        int xE = x1 + tE * dx;
        int yE = y1 + tE * dy;
        int xL = x1 + tL * dx;
        int yL = y1 + tL * dy;

        line(xE, yE, xL, yL);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xmin, ymin, xmax, ymax;
    int num_vertices;
    cout << "Enter the number of vertices of the polygon: ";
    cin >> num_vertices;
    int vertices[num_vertices][2];

    cout << "Enter the coordinates of the vertices (format: x y):" << endl;
    for (int i = 0; i < num_vertices; ++i)
    {
        cin >> vertices[i][0] >> vertices[i][1];
    }

    cout << "Enter the lower left co-ordinates of the window : ";
    cin >> xmin >> ymin;
    cout << "Enter the upper right co-ordinates of the window : ";
    cin >> xmax >> ymax;

    // Plotting the window
    setcolor(12);
    rectangle(xmin, ymin, xmax, ymax);

    // Plotting the polygon
    setcolor(YELLOW);
    for (int i = 0; i < num_vertices - 1; ++i)
    {
        line(vertices[i][0], vertices[i][1], vertices[i + 1][0], vertices[i + 1][1]);
    }
    line(vertices[num_vertices - 1][0], vertices[num_vertices - 1][1], vertices[0][0], vertices[0][1]);

    // Clipping
    setcolor(GREEN);
    for (int i = 0; i < num_vertices - 1; ++i)
    {

        clip(vertices[i][0], vertices[i][1], vertices[i + 1][0], vertices[i + 1][1], xmin, ymin, xmax, ymax);
    }
    clip(vertices[num_vertices - 1][0], vertices[num_vertices - 1][1], vertices[0][0], vertices[0][1], xmin, ymin, xmax, ymax);

    getch();
    closegraph();
    return 0;
}