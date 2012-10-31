import java.io.*;
class Node
{
	int data;
	Node left;
	Node right;
	Node(int d)
	{
		data=d;
		left=null;
		right=null;
	}
}

class Main
{
	public static void main(String args[])
	{
		Read r=new Read();
		Tree t=new Tree();
		int ch=1,a,b;
		while(ch==1)
		{
			t.insert();
			System.out.print("Enter more?y/n");
			ch=r.readInt();
		}
		System.out.println("Enter the first node ");
		a=r.readInt();
		System.out.println("Enter the first second ");			
		b=r.readInt();
		Lca l=new Lca(a,b,t);
		l.start();
	}
}
class Lca extends Thread
{
	int a,b,key,bit;
	boolean af=false,bf=false;
	Node root;

	Lca(int a,int b,Tree t)
	{
		this.a=a;
		this.b=b;
		this.root=t;
	}
	Lca(int key,Tree t,int mode)
	{
		this.key=key;
		this.bit=mode;
		this.root=t;
	}

	public void parse()
	{
		Node t=root;
		while(true)
		{
			af=false;
			bf=false;
			if(t!=null)
			{
				Lca left=new Lca(a,t.left,0);
				Lca right=new Lca(b,t.right,1);
				left.start();
				right.start();
				try{
					Thread.join(left);
					}catch(InterruptedException e){}
				try{
					Thread.join(left);
					}catch(InterruptedException e){}
				if(af && bf)
				{
					System.out.println("LCA is "+t.data);
					System.exit(0);
				}
				else if(af)
					t=t.left;
				else
					t=t.right;
			}
		}
	}
	public void run()
	{
		if(root.search(root,key))
		{
			if(bit==0)
				af=true;
			else
				bf=true;
		}
	}
}
class Tree
{
	Node root=null;
	public boolean search(Node t,int key)
	{
		if(t!=null)
		{
			if(key==t.data)
				return true;
			else if(key<t.data)
				return search(t.left,key);
			else
				return search(t.right,key);
		}
		return false;
	}
	void insert()
	{
		Read r=new Read();
		System.out.print("\nEnter the item ");
		int item=r.readInt();
		Node n=new Node(item);
		Node t=root;
		if(root==null)
			root=n;
		else
			while(true)
				if(t.data>n.data)
					if(t.left==null)
					{
						t.left=n;
						break;
					}
					else
						t=t.left;
				else if(t.data<n.data)
					if(t.right==null)
					{
						t.right=n;
						break;
					}
					else
						t=t.right;
				else
				{
					System.out.println("Already in list");
					break;
				}
		return;
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
