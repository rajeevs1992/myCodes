class Lock{}
class BoundedBuffer extends Thread
{
	static public int full=0,empty=10;
	int mode;
	static Lock L=new Lock();
	BoundedBuffer(int m)
	{
		mode=m;
	}
	public void claimEmpty()
	{
		synchronized(L)
		{
		while(empty<=0)
		{
			try
			{
				L.wait();
			}catch(InterruptedException e){}
		}
			empty--;
		}
	}
	public void claimFull()
	{
		synchronized(L)
		{
		while(full<=0)
		{
			try
			{
				L.wait();
			}catch(InterruptedException e){}
		}
			full--;
		}
	}
	public void consume()
	{
		synchronized(L)
		{
			claimFull();
			System.out.println("Consumed a full ");
			empty++;
			L.notifyAll();
			try
			{
				Thread.sleep(1000);
			}catch(InterruptedException e){}
		}
	}
	public void produce()
	{
		synchronized(L)
		{
			claimEmpty();
			System.out.println("Produced a full ");
			full++;
			L.notifyAll();
			try
			{
				Thread.sleep(1000);
			}catch(InterruptedException e){}
		}
	}
	public void run()
	{
		if(mode==0)
			consume();
		else
			produce();
	}
}

class Main
{
	public static void main(String argv[])
	{
		BoundedBuffer[] B=new BoundedBuffer[10];
		B[0]=new BoundedBuffer(0);
		B[1]=new BoundedBuffer(0);
		B[2]=new BoundedBuffer(0);
		B[3]=new BoundedBuffer(0);
		B[4]=new BoundedBuffer(0);
		B[5]=new BoundedBuffer(0);
		B[6]=new BoundedBuffer(1);
		int i=0;
		while(i<7)
			B[i++].start();
	}
}
