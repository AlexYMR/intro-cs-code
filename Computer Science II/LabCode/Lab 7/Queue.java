
public class Queue
{
    IntLinkedList list;

    public Queue()
    {
	list = new IntLinkedList();
    }

    public void enqueue(int value)
    {
	list.add(value);
    }

    public int dequeue()
    {
	return list.remove(list.numItems-1);
    }

    public int peek()
    {
	return list.tail;
    }

    public int size()
    {
	return list.numItems;
    }

    public boolean isEmpty()
    {
	return list.numItems == 0;
    }
}
