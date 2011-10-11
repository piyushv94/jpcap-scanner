import java.io.IOException;

import jpcap.*;
import jpcap.packet.*;
class Receiver implements  PacketReceiver
{   
    /*ÊµÀýreceivePacket·½·¨*/
   public void receivePacket(Packet packet)
   {
     if(((TCPPacket)packet).dst_port==4139)
     System.out.println(packet);
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
			captor.setFilter("tcp", true);
			captor.loopPacket(-1, new Receiver());
			System.out.println(t.name+" has been opened");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
