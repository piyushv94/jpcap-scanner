import java.net.InetAddress;
import java.net.UnknownHostException;

enum ScanType
{
	Basic,SYN,FIN,ACK;
}
public class Result {
	public static boolean[] isOpen;//mark if port i is open or not
	public static int count=0;//how many port has been tested
	public static int numOfPorts;//number of ports need to be tested
	public static InetAddress ipAddress;//target IP address
	public static ScanType[] type;//method to test
	Result()//default constructor
	{
		
	}
	Result(int num,String IP)// assign the number of the ports and the target IP address
	{
		numOfPorts=num;
		isOpen=new boolean[num];
		type=new ScanType[num];
		try 
		{
			ipAddress=InetAddress.getByName(IP);
		} 
		catch (UnknownHostException e) 
		{
			e.printStackTrace();
		}
	}
	static String getServiceType(int i)//not complete(we can get the type of the service by the port it uses)
	{
		String ret="ServiceType";
		return ret;
	}
	public static void showResult()//show the result of the host
	{
		Main.captor.stopLoop();
		System.out.println(ipAddress+":");
		for(int i=0;i<numOfPorts;i++)
		{
			if(isOpen[i])
			{
				System.out.println("  "+ i +"is open,scan by "+ type +"known as"+ getServiceType(i));
			}
		}
	}
	
}
