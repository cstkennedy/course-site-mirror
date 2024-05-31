public void drawLines(Graphics g, Dimension d)
{
    int dmin = (d.width < d.height) ? d.width : d.height;

    if (stepSize < 1)
        stepSize = 1;

    Point center = new Point();
    center.x = (double)d.width/2.0;
    center.y = (double)d.height/2.0;

    /*+1*/int k = Math.abs(cycleCounter - cycleLength/2);
    int theta = 60 * cycleCounter / cycleLength; /*-1*/

    for (int i = 0; i < 60; ++i) {
        int radius = dmin/2;
        Point origin = ptOnCircle(6*i/*+1*/+thetai/*-1*/, radius, center);
        int j = i + stepSize;
        while (j >= 60)
            j -= 60;
        while (i != j) {
            Point destination = ptOnCircle(6*j+theta, radius, center);
            Color c = i/*+1*/interpolate(colors[0], colors[1], k, cycleLength/2);i/*-1*/
            g.setColor(c);
            g.drawLine ((int)origin.x, (int)origin.y,
                    (int)destination.x, (int)destination.y);
            j += stepSize;
            while (j >= 60)
                j -= 60;
        }
    }
}
