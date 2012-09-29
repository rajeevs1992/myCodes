import java.io.*;
class Vector
{
	int dim;
	Read r;
	Vector(int dim)
	{
		this.dim=dim;
		r=new Read();
	}
	void add(Real v1,Real v2)
	{
		if(v1.dim==v2.dim)
		{
			Real sum;
			sum=new Real(v1.dim,0);
			int i=0;
			for(i=0;i<v1.dim;i++)
			{
				sum.coeffts[i]=v1.coeffts[i]+v2.coeffts[i];
			}
			System.out.println("\nResult of Addition:");
			display(sum);
		}
	}
	void display(Real v)
	{
		int i=0;
		System.out.print("[");
		for(i=0;i<v.dim;i++)
		{
			System.out.print(v.coeffts[i]+" ");
		}
		System.out.print("]");
	}
	void multiply(Real v,int s)
	{
		Real sum;
		sum=new Real(v.dim,0);
		int i=0;
		for(i=0;i<v.dim;i++)
		{
			sum.coeffts[i]=v.coeffts[i]*s;
		}
		System.out.println("\nResult of scalar multiplication:");
		display(sum);
	}
}

class Real extends Vector
{
	int[] coeffts;
	Real(int dim)
	{
		super(dim);
		coeffts=new int[dim];
		int i;
		for(i=0;i<super.dim;i++)
		{
			System.out.print("\nEnter the coefficient "+(i+1)+" ");
			coeffts[i]=super.r.readInt();
		}
	}
	Real(int dim,int flag)
	{
		super(dim);
		coeffts=new int[dim];
		int i;
		for(i=0;i<super.dim;i++)
		{
			coeffts[i]=0;
		}
	}

}
class Complex extends Vector
{
	int [][] coeffts;
	Complex(int dim)
	{
		super(dim);
		coeffts=new int[dim][2];
		int i=0;
		for(i=0;i<dim;i++)
		{
			System.out.print("\nEnter the real coefficient "+(i+1)+" ");
			coeffts[i][0]=super.r.readInt();
			System.out.print("\nEnter the complex coefficient "+(i+1)+" ");
			coeffts[i][1]=super.r.readInt();
		}
	}
	Complex(int dim,int flag)
	{
		super(dim);
		coeffts=new int[dim][2];
		int i;
		for(i=0;i<super.dim;i++)
		{
			coeffts[i][0]=0;
			coeffts[i][1]=0;
		}
	}

	void add(Complex c)
	{
		Complex s;
		s=new Complex(dim,0);
		if(dim==c.dim)
		{
			int i=0;
			for(i=0;i<dim;i++)
			{
				s.coeffts[i][0]=coeffts[i][0]+c.coeffts[i][0];
				s.coeffts[i][1]=coeffts[i][1]+c.coeffts[i][1];
			}
		}
		System.out.println("\nResult of Addition:");
		display(s);
	}

	void multiply(int num)
	{
		int i=0;
		Complex s;
		s=new Complex(dim,0);
		for(i=0;i<dim;i++)
		{
			s.coeffts[i][0]=coeffts[i][0]*num;
			s.coeffts[i][1]=coeffts[i][1]*num;
		}
		System.out.println("\nResult of scalar multiplication:");
		display(s);
	}
	void display(Complex c)
	{
		int i=0;
		System.out.print("[");
		for(i=0;i<c.dim;i++)
		{
			System.out.print("("+c.coeffts[i][0]+" "+c.coeffts[i][1]+") ");
		}
		System.out.print("]");
	}

}
class Main
{
	public static void main(String argv[])
	{
		Read r;
		r=new Read();
		System.out.println("Enter vector type\t1.Real\t2.Complex");
		int vtype=r.readInt();
		System.out.println("Enter vector dimension");
		int vdim=r.readInt();
		switch(vtype)
		{
			case 1:
				Real a,b;
				Vector c;
				a=new Real(vdim);
				c=new Vector(vdim);
				System.out.println("\n1.Addition\t2.Scalar");
				switch(r.readInt())
				{
					case 1:
						b=new Real(vdim);
						c.add(a,b);
						break;
					case 2:
						System.out.println("\nEnter scalar ");
						c.multiply(a,r.readInt());
						break;
				}
				break;
						
			case 2:
				Complex a1,b1;
				a1=new Complex(vdim);
				System.out.println("\n1.Addition\t2.Scalar");
				switch(r.readInt())
				{
					case 1:
						b1=new Complex(vdim);
						a1.add(b1);
						break;
					case 2:
						System.out.println("\nEnter scalar ");
						a1.multiply(r.readInt());
						break;
				}
				break;
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
