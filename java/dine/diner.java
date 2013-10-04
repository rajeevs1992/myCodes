import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Global
{
    public static int[] FORKS = {0,0,0,0,0};
    public static Lock mutex = new ReentrantLock();
}
class Philosopher extends Thread
{
    int id;

    private boolean getAvailability(int side)
    {
        if(side == 0)
        {
            if(Global.FORKS[(this.id + 1)%5] == 0)
                return true;
            else
                return false;
        }
        else
        {
            if(Global.FORKS[this.id] == 0)
                return true;
            else
                return false;
        }
    }

    private void grab(int side)
    {
        if(side == 0)
            Global.FORKS[(this.id + 1)%5] = 1;
        else
            Global.FORKS[this.id] = 1;
    }

    private void release(int side)
    {
        if(side == 0)
            Global.FORKS[(this.id + 1)%5] = 0;
        else
            Global.FORKS[this.id] = 0;
    }


	Philosopher(int id)
	{
		this.id=id;
	}


	public void run()
	{
        while(true)
        {
        Global.mutex.lock();
        if(this.getAvailability(0) && getAvailability(1))
        {
            this.grab(0);
            this.grab(1);
            Global.mutex.unlock();
            System.out.println(this.id+1 + " is eating");
            try
            {
                sleep(1000);
            }
            catch (Exception e) {}
            Global.mutex.lock();
            this.release(0);
            this.release(1);
            Global.mutex.unlock();
            try
            {
                sleep(1000);
            }
            catch (Exception e) {}
        }
        else
        {
            Global.mutex.unlock();
            System.out.println(this.id+1 + " is thinking");
            try
            {
                sleep(1000);
            }
            catch (Exception e) {}
        }
    	}
    }
}

class Main
{
	public static void main(String argv[])
	{
		Philosopher[] B=new Philosopher[5];
		B[0]=new Philosopher(0);
		B[1]=new Philosopher(1);
		B[2]=new Philosopher(2);
		B[3]=new Philosopher(3);
		B[4]=new Philosopher(4);
		int i=0;
		while(i<5)
			B[i++].start();
	}
}
