import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        WebCrawler crawler = new WebCrawler();
        String rootURL = scanner.nextLine();
        crawler.crawl(rootURL, 100);
    }
}