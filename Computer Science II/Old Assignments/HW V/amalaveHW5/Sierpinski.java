/*
 * Sierpinski.java
 * Contains the class Sierpinski, whose methods draw a Sierpinski carpet based on a level parameter
 * Part of Homework 5, Problem 2
 */

import java.awt.Point;
import java.awt.Polygon;
import java.awt.Graphics;
import java.awt.Color;
import javax.swing.*;

public class Sierpinski extends JFrame
{
    protected static Graphics graphics;
    protected static int level;

    protected static final int SIZE = 243;

    public Sierpinski(int level)
    {
	super("Sierpinski Carpet");

	this.level = level;

	setSize(SIZE, SIZE + 24);
	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	setVisible(true);
    }
    //Draws rectangles recursively by taking a rectangle and sub-dividing it 9 times, omitting the middle rectangle
    public static void drawSquare(Point p1, Point p2, int level, Graphics g)
    {
	if (level == 0) {
            Polygon p = new Polygon();
	    p.addPoint(p1.x, p1.y);
	    p.addPoint(p2.x, p1.y);
	    p.addPoint(p2.x, p2.y);
	    p.addPoint(p1.x, p2.y);
	    g.drawPolygon(p);
        } else {
	    Point pt1 = new Point( p1.x+(p2.x-p1.x)/3, p1.y+(p2.y-p1.y)/3 );
	    Point pt2 = new Point( p1.x, p1.y+(p2.y-p1.y)/3 );
	    Point pt3 = new Point( p1.x+(p2.x-p1.x)/3, p1.y+2*((p2.y-p1.y)/3) );
	    Point pt4 = new Point( p1.x, p1.y+2*((p2.y-p1.y)/3) );
	    Point pt5 = new Point( p1.x+(p2.x-p1.x)/3, p2.y );
	    Point pt6 = new Point( p1.x+(p2.x-p1.x)/3, p1.y );
	    Point pt7 = new Point( p1.x+2*((p2.x-p1.x)/3), p1.y+(p2.y-p1.y)/3 );
	    Point pt8 = new Point( p1.x+(p2.x-p1.x)/3, p1.y+2*((p2.y-p1.y)/3) );
	    Point pt9 = new Point( p1.x+2*((p2.x-p1.x)/3), p2.y );
	    Point pt10 = new Point( p1.x+2*((p2.x-p1.x)/3), p1.y );
	    Point pt11 = new Point( p2.x, p1.y+(p2.y-p1.y)/3 );
	    Point pt12 = new Point( p1.x+2*((p2.x-p1.x)/3), p1.y+(p2.y-p1.y)/3 );
	    Point pt13 = new Point( p2.x, p1.y+2*((p2.y-p1.y)/3) );
	    Point pt14 = new Point( p1.x+2*((p2.x-p1.x)/3), p1.y+2*((p2.y-p1.y)/3) );

	    drawSquare(p1,pt1,level-1,g);
	    drawSquare(pt2,pt3,level-1,g);
	    drawSquare(pt4,pt5,level-1,g);
	    drawSquare(pt6,pt7,level-1,g);
	    drawSquare(pt8,pt9,level-1,g);
	    drawSquare(pt10,pt11,level-1,g);
	    drawSquare(pt12,pt13,level-1,g);
	    drawSquare(pt14,p2,level-1,g);
        }
    }

    @Override
    public void paint(Graphics g)
    {
	graphics = g;
	
	Point p1 = new Point(0, 24);
	Point p2 = new Point(SIZE, SIZE + 24);

	drawSquare(p1, p2, level, graphics);
    }
    
    public static void main(String [] args)
    {
	int level = Integer.parseInt(args[0]);
	Sierpinski s = new Sierpinski(level);	
    }
}
