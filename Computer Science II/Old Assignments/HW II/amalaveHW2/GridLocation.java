/*
 * GridLocation.java
 * Contains the class GridLocation, which represents a location in the world instance
 * Part of Homework 2, part 1
*/

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import javax.swing.JPanel;
import javax.swing.border.LineBorder;

/**
 * Represents a single grid location (i.e., one row/column position)
 * Within a 2D grid in a Graphical User Interface (GUI)
 */
public class GridLocation extends JPanel					     
{
    private static final int WIDTH = 50;
    private static final int HEIGHT = 50;
    
    protected int row;
    protected int col;

    protected Color backgroundColor;
    protected Creature creature;

    public GridLocation(int r, int c)
    {
	setBorder(new LineBorder(Color.BLACK));

	row = r;
	col = c;

	backgroundColor = Color.WHITE;
	setBackground(backgroundColor);

	creature = null;
    }
    public int getRow()
    {
	return row;
    }
    public int getColumn()
    {
	return col;
    }
    public void setBackgroundColor(Color color)
    {
	backgroundColor = color;
	setBackground(backgroundColor);
	repaint();
    }

    //Adds creature to grid
    public void setCreature(Creature c)
    {
	creature = c;
	repaint();
    }

    //Removes creature from grid
    public void removeCreature()
    {
	creature = null;
	repaint();
    }
    public boolean hasPredator()
    {
	if (creature != null)
	    return creature.isPredator();
	else
	    return false;
    }
    public boolean equals(Object o)
    {
	if (o == null)
	    return false;
	if (o == this)
	    return true;
	if (!(o instanceof GridLocation))
	    return false;

	GridLocation other = (GridLocation)o;

	return row == other.row && col == other.col;
    }
    public String toString()
    {
	return "(" + row + ", " + col +")";
    }
    public Dimension getPreferredSize()
    {
	return new Dimension(WIDTH, HEIGHT);
    }
    protected void paintComponent(Graphics g)
    {
	super.paintComponent(g);
	
	if (creature != null)
	    g.drawImage(creature.getImage(), 0, 0, null);
    }
}
