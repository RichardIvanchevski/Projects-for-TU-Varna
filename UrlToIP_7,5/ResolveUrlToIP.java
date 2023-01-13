import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

public class ResolveUrlToIP {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Please enter hostname to find IP address");
        String hostname = scanner.nextLine();

        try {
            inet = InetAddress.getByName(hostname);  
        } catch (UnknownHostException e) {
            System.out.println("Error while trying to resolve the given URL");
        }
        // Getting IP address from hostname in Java
        String IPAddress = null;
        if (inet != null) {
            IPAddress = inet.getHostAddress();
        }
        System.out.printf("IP address of host %s  is %s %n", hostname, IPAddress);
    }
}



