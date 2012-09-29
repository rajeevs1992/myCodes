import java.util.Scanner;
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

class Tree
{
	Node root=null;
	Scanner in;
	Tree()
	{
		in = new Scanner(System.in);
	}
	void insert()
	{
//		System.out.print("\nEnter the item ");
		int item=Integer.parseInt(in.nextLine());
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
//					System.out.println("Already in list");
					break;
				}
		return;
	}
	void postorder(Node n)
	{
		if(n!=null)
		{
			postorder(n.left);
			postorder(n.right);
			System.out.print(n.data+" ");
		}
	}
	public static void main(String args[])
	{
		Tree t=new Tree();
		int ch=0;
		while(ch<=5)
		{
//			System.out.print("1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Delete\n6.Exit\nEnter choice ");
			ch=Integer.parseInt(t.in.nextLine());
			switch(ch)
			{
			case 1:
				t.insert();
				break;
			case 4:
				t.postorder(t.root);
				System.out.println();
				ch=6;
				break;
			}
		}
	}
}
