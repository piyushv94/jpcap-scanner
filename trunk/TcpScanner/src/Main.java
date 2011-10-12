
public class Main {

	/**
	 * @param args
	 */
	public static Devices devices=new Devices();
	public static Captor captor;
	public static Result result;
	public static void main(String[] args) 
	{
		devices.showDevices();
		result=new Result(1024,"220.181.111.147");
		captor=new Captor(devices.getDevices());
	}

}
