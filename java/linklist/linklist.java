import java.io.*;
class Node
{
    int data;
    Node next=null;
}

class List
{
    Node first=null;
    void append(Node n)
    {
        if(first==null)
        {
            first=n;
            return;
        }
        else
        {
            Node t=first;
            while(t.next!=null)
                t=t.next;
            t.next=n;
            return;
        }
    }
    void del(int token)
    {
        Node t=first;
        if(t!=null)
        {
            if(first.data==token)
            {
                first=first.next;
                return;
            }
                
            while(t.next!=null)
            {
                if(t.next.data==token)
                {
                    t.next=t.next.next;
                    return;
                }
                t=t.next;
            }
            System.out.print("Not found!!!");
            return;
        }
        System.out.print("Empty!!!");
        return;
    }

    void sort()
    {
        Node runner=first,cur_head=first,min=first;
        int temp;
		if(first==null)
		{
        	System.out.print("Empty!!!");
	        return;
		}
        while(cur_head!=null)
        {
			runner=cur_head;
            while(runner!=null)
            {
                if(runner.data<=min.data)
                    min=runner;
                runner=runner.next;
            }
			temp=cur_head.data;
			cur_head.data=min.data;
			min.data=temp;
			cur_head=cur_head.next;
        }
    }


    void display()
    {
        if(first!=null)
        {
            System.out.print("\n");
            Node t=first;
            while(t!=null)
            {
                System.out.print(t.data+" ");
                t=t.next;
            }
            System.out.print("\n");
            return;
        }
        System.out.print("Empty!!!");
        return;
    }
}
class Main
{
    public static void main(String args[])
    {
        Read r=new Read();
        List l=new List();
        int ch=0;
        while(ch!=4)
        {
            System.out.print("1.Insert\n2.Display\n3.Delete\n4.Exit\nEnter choice ");
            ch=r.readInt();
            switch(ch)
            {
                case 1:
                    Node n=new Node();
                    n.data=r.readInt();
                    n.next=null;
                    l.append(n);
                    break;
                case 2:
                    l.display();
                    break;
                case 3:
                    System.out.print("Enter token ");
                    int token=r.readInt();
                    l.del(token);
                    break;
                case 4:
                    l.sort();
					l.display();
                    break;
            }
        }
    }
}

class Read
{
    public int readInt()
    {
        int data;
        InputStreamReader f;
        BufferedReader in;
        f=new InputStreamReader(System.in);
        in=new BufferedReader(f);
        String s="";
        try
        {
            s=in.readLine();
        }catch(IOException e)
        {
            System.out.print("IO error");
        }
        return Integer.parseInt(s);
    }
}
