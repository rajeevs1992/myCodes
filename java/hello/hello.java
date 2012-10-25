class hello extends Thread
{
	static int count=0;
	int tnum=0;
	hello(int t)
	{
	 tnum=t;
	}
	public void run()
	{
		while(count<10)
		{
			count++;
			System.out.println(count+" Hello "+tnum);
			try
			{
				Thread.sleep(10);
			}
			catch(InterruptedException e)
			{
			}
		}
		System.exit(0);
	}
}
class main
{
	public static void main(String argv[])
	{
		hello h1=new hello(1);
		hello h2=new hello(2);
		h1.start();
		h2.start();


	}
}
