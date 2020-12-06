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

    protected Fly fly;
    protected Frog frog;

    public GridLocation(int r, int c)
    {
	setBorder(new LineBorder(Color.BLACK));

	row = r;
	col = c;

	backgroundColor = Color.WHITE;
	setBackground(backgroundColor);

	fly = null;
	frog = null;
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
    public void setFly(Fly f)
    {
	fly = f;
	repaint();
    }
    public void setFrog(Frog f)
    {
	frog = f;
	repaint();
    }
    public void removeFly()
    {
	fly = null;
	repaint();
    }
    public void removeFrog()
    {
	frog = null;
	repaint();
    }
    public boolean hasPredator()
    {
	return frog != null;
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
	if (fly != null)
	    g.drawImage(fly.getImage(), 0, 0, null);
	if (frog != null)
	    g.drawImage(frog.getImage(), 0, 0, null);
    }
}
