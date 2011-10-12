import java.io.IOException;
import jpcap.*;
import jpcap.packet.*;
class Receiver implements  PacketReceiver
{   
   public void receivePacket(Packet packet)//callback function for handle the packet
   {
     if(((TCPPacket)packet).dst_port==4139&&((TCPPacket)packet).src_ip==Result.ipAddress)
     {
    	 Result.isOpen[((TCPPacket)packet).dst_port]=true;
    	 Result.count++;
     }
     if(Result.count==Result.numOfPorts)
     {
    	 Result.showResult();
     }
   }
}
public class Captor {//capture the packet
	JpcapCaptor captor;
	Captor()//default constructor
	{
		
	}
	Captor(NetworkInterface t)//bind to a interface
	{
		try {
			captor = JpcapCaptor.openDevice(t,65535,false,20);//bind the interface
			System.out.println(t.name+" has been opened");
			captor.setFilter("tcp", true);//only capture the TCP packet
			captor.loopPacket(-1, new Receiver());//register for a callback function and start listening
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public void stopLoop()//stop listening
	{
		captor.breakLoop();
	}

}
