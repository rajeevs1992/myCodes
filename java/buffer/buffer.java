class Semaphore extends Thread
{
	static int S;
	Semaphore(int s)
	{
		S=s;
	}
	void signal()
	{
		S++;
	}
	void wait()
	{
		while(S<=0);	
		S--;
	}
}
