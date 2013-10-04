class Lock{}
class BoundedBuffer extends Thread
{
	static public int count=0;
	int BUFSIZE=10;
	int mode,id,sl;
	static Lock L=new Lock();
	BoundedBuffer(int m,int id,int sl)
	{
		mode=m;
		this.id=id;
		this.sl=sl;
	}
	public void additem()
	{
		synchronized(L)
		{
			while(count==BUFSIZE)
			{
				try
				{
					L.wait();
				}catch(InterruptedException e){}
			}
			count++;
			System.out.println("\tProduced by "+id);
			if(count==1)
				L.notifyAll();
		}
	}
	public void remitem()
	{
		synchronized(L)
		{
			while(count==0)
			{
				try
				{
					L.wait();
				}catch(InterruptedException e){}
			}
			count--;
			System.out.println("Consumed by "+id);
			if(count==BUFSIZE-1)
				L.notifyAll();
		}
	}
	public void produce()
	{
		while(true)
		{
			additem();
			try
			{
				Thread.sleep(sl);
			}catch(InterruptedException e){}
		}
	}
	public void consume()
	{
		while(true)
		{
			remitem();
			try
			{
				Thread.sleep(sl);
			}catch(InterruptedException e){}
		}
	}
	public void run()
	{
		if(mode==0)
			produce();
		else
			consume();
	}
}

class Main
{
	public static void main(String argv[])
	{
		BoundedBuffer[] B=new BoundedBuffer[4];
		B[0]=new BoundedBuffer(0,1,1000);
		B[1]=new BoundedBuffer(1,2,1000);
		B[2]=new BoundedBuffer(1,3,1000);
		B[3]=new BoundedBuffer(1,4,1000);
		int i=0;
		while(i<4)
			B[i++].start();
	}
}
