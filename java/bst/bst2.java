import java.io.*;
class Node {
  int data;
  Node left;
  Node right;
    Node (int d) {
    data = d;
    left = null;
    right = null;
  }
}

class Tree {
  Node root = null;
  void insert () {
    Read r = new Read ();
      System.out.print ("\nEnter the item ");
    int item = r.readInt ();
    Node n = new Node (item);
    Node t = root;
    if (root == null)
      root = n;
    else
      while (true)
	if (t.data > n.data)
	  if (t.left == null) {
	    t.left = n;
	    break;
	  }
	  else
	      t = t.left;
	else if (t.data < n.data)
	  if (t.right == null) {
	    t.right = n;
	    break;
	  }
	  else
	    t = t.right;
	else {
	  System.out.println ("Already in list");
	  break;
	}
    return;
  }
  void preorder (Node n) {
    if (n != null) {
      System.out.print (n.data + " ");
      preorder (n.left);
      preorder (n.right);
    }
  }
  void inorder (Node n) {
    if (n != null) {
      inorder (n.left);
      System.out.print (n.data + " ");
      inorder (n.right);
    }
  }
  void postorder (Node n) {
    if (n != null) {
      postorder (n.left);
      postorder (n.right);
      System.out.print (n.data + " ");
    }
  }
  Node getParent (Node child) {
    Node t = root;
    while (t != null) {
      if (t.left == child || t.right == child)
	return t;
      else if (t.data > child.data)
	t = t.left;
      else if (t.data < child.data)
	t = t.right;
    }
    return null;
  }
  void del (int token) {
    Node t = root;
    Node parent = null;
    while (true)
      if (t != null)
	if (token < t.data)
	  t = t.left;
	else if (token > t.data)
	  t = t.right;
	else if (t.left == null && t.right == null) {
	  parent = getParent (t);
	  if (parent == null)
	    t = null;
	  else if (parent.left == t)
	    parent.left = null;
	  else
	    parent.right = null;
	  break;
	}
	else if (t.left == null) {
	  parent = getParent (t);
	  if (parent == null)
	    t = t.right;
	  else if (parent.left == t)
	    parent.left = t.right;
	  else
	    parent.right = t.right;
	  break;
	}
	else if (t.right == null) {
	  parent = getParent (t);
	  if (parent == null)
	    t = t.left;
	  else if (parent.left == t)
	    parent.left = t.left;
	  else
	    parent.right = t.left;
	  break;
	}
	else {
	  t.data = deletemin (t.right);
	  break;
	}
      else
	break;
  }
  int deletemin (Node n) {
    if (n.left == null) {
      int min = n.data;
      Node p = getParent (n);
      if (p == null)
	n = n.right;
      else if (p.left == n)
	p.left = n.right;
      else
	p.right = n.right;
      return min;
    }
    else
      return deletemin (n.left);
  }
  public static void main (String args[]) {
    Read r = new Read ();
    Tree t = new Tree ();
    int ch = 0;
    while (ch <= 5) {
      System.out.print
	("1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Delete\n6.Exit\nEnter choice ");
      ch = r.readInt ();
      switch (ch) {
      case 1:
	t.insert ();
	break;
      case 2:
	t.preorder (t.root);
	break;
      case 3:
	t.inorder (t.root);
	break;
      case 4:
	t.postorder (t.root);
	break;
      case 5:
	System.out.print ("\nEnter the item to delete ");
	int token = r.readInt ();
	t.del (token);
	break;
      }
    }
  }
}

class Read {
  public int readInt () {
    int data;
    InputStreamReader f;
    BufferedReader in;
      f = new InputStreamReader (System.in);
      in = new BufferedReader (f);
    String s = "";
      try {
      s = in.readLine ();
    } catch (IOException e) {
      System.out.print ("IO error");
    }
    return Integer.parseInt (s);
  }
}
