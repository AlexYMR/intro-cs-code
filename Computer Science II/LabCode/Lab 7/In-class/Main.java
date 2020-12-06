public class Main{
    public static void main(String[] args){
	AbstractIntList list = new IntLinkedList();
	list.add(4);
	list.add(6);
	list.add(7);
	list.add(1,1);
	System.out.println(list);
	list.add(0,0);
	list.add(4,10);
	System.out.println(list);
	int val = list.remove(5);
	System.out.println(val);
	System.out.println(list);
	int val2 = list.remove(2);
	System.out.println(val2);
	System.out.println(list);
    }
}
