/*
	Concurrent LCA computation
	Algorithm:
		*Read the tree
		*Read the 2 nodes whose LCA must be computed a,b and a < b
		*Travaerse the tree starting from root
		*Create 2 threads,one searching for "a" in currentNode.left and other "b" in currentNode.right
		*If found,set corresponding flags "af" (a.k.a "a found") or bf
		*The current node is LCA of a and b if af=bf=true,if found exit.
		*If af is true and bf is false,it means that a and b lie on the left subtree,hence repeat with left child of currentNode as root
		*Else repeat with right child of currentNode as root
*/
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
		Tree t=new Tree(null);
		int a,b,item;
		while(true)
		{
			System.out.print("\nEnter the item ,0 to exit ");
			item=r.readInt();
			if(item==0)
				break;
			t.insert(item);
		}
		System.out.print("Enter the first node ");
		a=r.readInt();
		System.out.print("Enter the second node ");
		b=r.readInt();
		Lca l;
		if(a<b)
			l=new Lca(t,a,b);
		else
			l=new Lca(t,b,a);
		l.parse();
	}
}
class Lca extends Thread
{
	Tree t;
	static int a,b;
	static boolean af,bf;

	Lca(Tree t)
	{
		this.t=t;
		af=false;
		bf=false;
	}

	Lca(Tree t,int a,int b)
	{
		this.t=t;
		this.a=a;
		this.b=b;
		af=false;
		bf=false;
	}

	public void parse()
	{
		Lca l,r;
		Tree left,right;
		Node temp=t.root;
		while(temp !=null)
		{
			left=new Tree(temp.left);
			right=new Tree(temp.right);
			l=new Lca(left);
			r=new Lca(right);
			l.start();
			r.start();
			try
			{
				l.join();
				r.join();
			}catch(InterruptedException e){}
			if(af && bf)
			{
				System.out.println("LCA is "+temp.data);
				System.exit(0);
			}
			else if(af)
				temp=temp.left;
			else
				temp=temp.right;
		}
		
	}

	public void run()
	{
		if(t.search(a))
			af=true;
		else if(t.search(b))
			bf=true;
	}
}
class Tree
{
	Node root=null;
	public boolean search(int key)
	{
		Node t=root;
		while(t!=null)
		{
			if(key==t.data)
				return true;
			else if(key<t.data)
				t=t.left;
			else
				t=t.right;
		}
		return false;
	}
	void insert(int item)
	{
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
	Tree(Node root)
	{
		this.root=root;
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
