import java.io.IOException;

import jpcap.*;
import jpcap.packet.*;
public class Devices {
	NetworkInterface devices;
	Devices()
	{
		
	}
	public void showDevices()
	{
		NetworkInterface[] _devices=JpcapCaptor.getDeviceList();
		for(int i=0;i<_devices.length;i++)
		{
			System.out.println(i+": ");
	        System.out.println(_devices[i].name);
	        System.out.print(_devices[i].description);
	        for (NetworkInterfaceAddress a : _devices[i].addresses)    
	        	System.out.println(" address:"+a.address + " " + a.subnet + " "+ a.broadcast);
		}
		System.out.println("Please select your network adapter:");
	    int index=0;
	    try {
			index=System.in.read()-'0';
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	    if(index>0&&index<_devices.length)
	    {
	    	devices=_devices[index];
	    	System.out.println(devices.name+" has been chosen");
	    }
	    
	}
	public NetworkInterface getDevices()
	{
		return devices;
	}

}
