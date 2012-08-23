import java.io.*;
abstract class Shape
{
	public abstract float area();
	public abstract float perimeter();
}

abstract class Polygon extends Shape
{
	float height;
	float base;
	Polygon(float b,float h)
	{
		base=b;
		height=h;
	}
	Polygon()
	{
		height=0;
		base=0;
	}
}
abstract class Curve extends Shape
{
	float x;
	float y;
	Curve(float x,float y)
	{
		this.x=x;
		this.y=y;
	}
}

class Rectangle extends Polygon
{
	Rectangle(float b,float h)
	{
		super(b,h);
	}
	public float area()
	{
		return super.height*super.base;
	}
	public float perimeter()
	{
		return 2*(super.height+super.base);
	}
}

class Square extends Rectangle
{
	Square(float edge)
	{
		super(edge,edge);
	}
}

class Triangle extends Polygon
{
	float a,b,c;
	Triangle(float a,float b,float c)
	{
		this.a=a;
		this.b=b;
		this.c=c;
	}
	public float area()
	{
		float s=perimeter()/2;
		return (float)Math.sqrt(s*(s-a)*(s-b)*(s-c));
	}
	public float perimeter()
	{
		return a+b+c;
	}
}

class Ellipse extends Curve
{
	Ellipse(float x,float y)
	{
		super(x,y);
	}
	Ellipse(float x)
	{
		super(x,x);
	}
	public float area()
	{
		return (float)Math.PI*super.x*super.y;
	}
	public float perimeter()
	{
		float x=super.x;
		float y=super.y;
		return 2*(float)Math.PI*(float)Math.sqrt(.5*((x*x)+(y*y)));
	}
}

class Circle extends Ellipse
{
	Circle(float r)
	{
		super(r,r);
	}
}
class main
{
	public static void main(String args[])
	{
		int ch=0,opr=0;
		Read r=new Read();
		while(ch<=5)
		{
			System.out.print("Select Shape\n1.Rectangle\n2.Square\n3.Triangle\n4.Circle\n5.Ellipse\n6.Exit ");
			ch=r.readInt();
			if(ch <= 5)
			{
				System.out.print("\nEnter operation\n1.Area\n2.Perimeter ");
				opr=r.readInt();
			}
			switch(ch)
			{
			case 1:
				System.out.print("\nEnter the length and breadth ");
				Rectangle re=new Rectangle(r.readInt(),r.readInt());
				if(opr==1)
					System.out.println("Area is "+re.area());
				else if(opr==2)
					System.out.println("Perimeter is "+re.perimeter());
				break;
			case 2:
				System.out.print("\nEnter side ");
				Square s=new Square(r.readInt());
				if(opr==1)
					System.out.println("Area is "+s.area());
				else if(opr==2)
					System.out.println("Perimeter is "+s.perimeter());
				break;
			case 3:
				System.out.print("\nEnter sides ");
				Triangle t=new Triangle(r.readInt(),r.readInt(),r.readInt());
				if(opr==1)
					System.out.println("Area is "+t.area());
				else if(opr==2)
					System.out.println("Perimeter is "+t.perimeter());
				break;
			case 4:
				System.out.print("\nEnter radius ");
				Circle c=new Circle(r.readInt());
				if(opr==1)
					System.out.println("Area is "+c.area());
				else if(opr==2)
					System.out.println("Perimeter is "+c.perimeter());
				break;
			case 5:
				System.out.print("\nEnter major axis and minor axis ");
				Ellipse e=new Ellipse(r.readInt()/2,r.readInt()/2);
				if(opr==1)
					System.out.println("Area is "+e.area());
				else if(opr==2)
					System.out.println("Perimeter is "+e.perimeter());
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
