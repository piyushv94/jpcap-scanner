import java.net.InetAddress;
import java.net.UnknownHostException;

enum ScanType
{
	Basic,SYN,FIN,ACK;
}
public class Result {
	public static boolean[] isOpen;
	public static int count=0;
	public static int numOfPorts;
	public static InetAddress ipAddress;
	public static ScanType[] type;
	Result()
	{
		
	}
	Result(int num,String IP)
	{
		numOfPorts=num;
		isOpen=new boolean[num];
		type=new ScanType[num];
		try {
			ipAddress=InetAddress.getByName(IP);
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	static String getServiceType(int i)//not complete
	{
		String ret="ServiceType";
		return ret;
	}
	public static void showResult()
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
