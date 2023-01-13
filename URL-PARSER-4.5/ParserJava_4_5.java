import java.net.MalformedURLException;
import java.net.URL; // URL PARSER
import java.util.Scanner;

public class ParserJava_4_5 {
 
    public static void checkURL(String urlString) {
        try {
            URL url = new URL(urlString);
            System.out.println("Valid URL: " + url.toString());
        } catch (MalformedURLException e) {
            System.out.println("Not a valid URL");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a URL: ");
        String urlString = scanner.nextLine();
        while (!urlString.equals("stop")) {  
            checkURL(urlString);
            System.out.print("Enter a URL: ");
            urlString = scanner.nextLine();
        }
    }
}
m