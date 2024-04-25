   char centerText[20], radiusText[20];
    sprintf(centerText, "Center: (%d, %d)", cx, cy);
    sprintf(radiusText, "Radius: %d", r);
    outtextxy(10, 10, centerText);
    outtextxy(10, 30, radiusText);