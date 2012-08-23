import java.net.*;
import java.io.*;

class main
{
	public static void main(String arg[])
	{
		Socket s;
		try
		{
			s=new Socket("127.0.0.1",8000);
			BufferedReader r=new BufferedReader(new InputStreamReader(s.getInputStream()));
			PrintStream p=new PrintStream(s.getOutputStream());
			p.println("/views/login.php");
			System.out.println(r.readLine());
		}catch(Exception e)
		{
			System.out.println("error"+e.toString());
		}
		r.close();
		p.close();
		s.close();
	}
}
