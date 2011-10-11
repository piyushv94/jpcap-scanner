
public class Main {

	/**
	 * @param args
	 */
	public static Devices devices=new Devices();
	public static Captor captor;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		devices.showDevices();
		captor=new Captor(devices.getDevices());
	}

}
