/*************************************************************************
TITLE:  Program to implement Liang Barsky Line Clipping Algorithm.
*************************************************************************/

#include <iostream.h>
#include <conio.h>
#include <graphics.h>
int main()
{
    int gd = DETECT, gm;      // Detects the graphics drivers automatically
    initgraph(&gd, &gm, " "); // Initialize to graphics mode

    int x1, y1, x2, y2, xmax, xmin, ymax, ymin, xx1, yy1, xx2, yy2, dx, dy, i;
    int p[4], q[4];
    float t1, t2, t[4];

    // To plot the quadrants
    line(0, 240, 639, 240);
    line(320, 0, 320, 479);
    outtextxy(295, 243, "0,0");
    setcolor(WHITE);

    // To plot the window
    cout << " Enter the lower left co-ordinates of the window : ";
    cin >> xmin >> ymin; // Lower left co-ordinates of the window
    cout << " Enter the upper right co-ordinates of the window : ";
    cin >> xmax >> ymax; // Upper right co-ordinates of the window
    setcolor(12);
    rectangle(320 + xmin, 240 - ymin, 320 + xmax, 240 - ymax); // Plot the window

    // To plot the line to be clipped
    cout << " Enter x1 : ";
    cin >> x1; // X co-ordinate of the first point of the line
    cout << " Enter y1 : ";
    cin >> y1; // Y co-ordinate of the first point of the line
    cout << " Enter x2 : ";
    cin >> x2; // X co-ordinate of the second point of the line
    cout << " Enter y2 : ";
    cin >> y2; // Y co-ordinate of the second point of the line

    line(320 + x1, 240 - y1, 320 + x2, 240 - y2); // Plotting the line

    dx = x2 - x1; // Difference between the x-co-ordinates
    dy = y2 - y1; // Difference between the y-co-ordinates

    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;
    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;

    // To check if the line to be clipped lies inside the window or not
    for (i = 0; i < 4; i++)
    {
        if (p[i] != 0)
        {
            t[i] = (float)q[i] / p[i];
        }
        else if (p[i] == 0 && q[i] < 0)
            cout << " The line lies completely outside the window.";
        else if (p[i] == 0 && q[i] >= 0)
            cout << " The line lies completely inside the window.";
    }
    if (t[0] > t[2])
    {
        t1 = t[0];
    }
    else
    {
        t1 = t[2];
    }
    if (t[1] < t[3])
    {
        t2 = t[1];
    }
    else
    {
        t2 = t[3];
    }
    if (t1 < t2) // If t1<t2 then draw a line from (xx1, yy1) to (xx2,yy2)
    {
        xx1 = x1 + t1 * dx;
        xx2 = x1 + t2 * dx;
        yy1 = y1 + t1 * dy;
        yy2 = y1 + t2 * dy;
        cout << " The line after clipping is displayed.";
        setcolor(WHITE);
        line(320 + xx1, 240 - yy1, 320 + xx2, 240 - yy2);
    }
    else // If the line crosses over the window, you will see (xx1, yy1) and (xx2,yy2) are intersection between line and edge
    {
        cout << " The line lies out of the window.";
    }
    getch();      // Pauses the Output Console until a key is pressed
    closegraph(); // Closes the graphics mode
    return 0;
}
