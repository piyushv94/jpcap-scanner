import java.io.IOException;
import java.net.*;


public class BasicScan {
	public boolean basicResult=false;
	BasicScan(InetAddress ip,int port)
	{
		try 
		{
			Socket s=new Socket(ip,port);
			Result.count++;
			Result.isOpen[port]=true;
			Result.type[port]=ScanType.Basic;
			basicResult=true;
		} 
		catch (IOException e) 
		{
		}
	}
}
