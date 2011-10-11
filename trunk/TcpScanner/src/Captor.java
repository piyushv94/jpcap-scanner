import java.io.IOException;

import jpcap.*;
import jpcap.packet.*;
class Receiver implements  PacketReceiver
{   
	//longIP to inet
   public void receivePacket(Packet packet)
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
public class Captor {
	JpcapCaptor captor;
	Captor()
	{
		
	}
	Captor(NetworkInterface t)
	{
		try {
			captor = JpcapCaptor.openDevice(t,65535,false,20);
			System.out.println(t.name+" has been opened");
			captor.setFilter("tcp", true);
			captor.loopPacket(-1, new Receiver());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public void stopLoop()
	{
		captor.breakLoop();
	}

}
