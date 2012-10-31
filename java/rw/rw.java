class lock{}
class rw extends Thread
{
	static boolean writing=false;
	static int readcount=0;
	int mode;
	static lock l=new lock();

	rw(int m)
	{
		mode=m;
	}

	public void acqreadlock()
	{
		synchronized(l)
		{
			while(writing)
			{
				try
				{
					l.wait();
				}catch(InterruptedException e){}
			}
			readcount++;
		}
	}
	public void rlsreadlock()
	{
		synchronized(l)
		{
			readcount--;
			l.notifyAll();
		}
	}
	public void acqwritelock()
	{
		synchronized(l)
		{
			while(writing||readcount>0)
			{
				try
				{
					l.wait();
				}catch(InterruptedException e){}
			}
			writing=true;
		}
	}
	public void rlswritelock()
	{
		synchronized(l)
		{
			writing=false;
			l.notifyAll();
		}
	}
	public void read()
	{
		while(true)
		{
			acqreadlock();
			System.out.println("reading");
			rlsreadlock();
			try
			{
				Thread.sleep(1000);
			}catch(InterruptedException e){}
		}
	}
	public void write()
	{
		while(true)
		{
			acqwritelock();
			System.out.println("\twriting");
			rlswritelock();
			try
			{
				Thread.sleep(1000);
			}catch(InterruptedException e){}
		}
	}
	public void run()
	{
		if(mode==0)
			read();
		else
			write();
	}
}

class Main
{
	public static void main(String S[])
	{
		int i=0;
		rw[] a=new rw[6];
		a[0]=new rw(1);
		a[1]=new rw(1);
		a[2]=new rw(1);
		a[3]=new rw(0);
		a[4]=new rw(0);
		a[5]=new rw(0);
		while(i<6)
			a[i++].start();
	}
}
