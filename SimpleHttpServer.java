import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

// I think Java is the most fucking programming language.

public class SimpleHttpServer {
    public static void main(String[] args) throws Exception {
        ServerSocket serverSocket = new ServerSocket(8080);
        System.out.println("Server is running on http://localhost:8080");

        while (true) {
            Socket clientSocket = serverSocket.accept();
            OutputStream output = clientSocket.getOutputStream();
            String response = 
                "HTTP/1.1 200 OK\r\n" +
                "Content-Type: text/html\r\n\r\n" +
                "<h1>Hello World</h1>";
            output.write(response.getBytes());
            output.flush();
            clientSocket.close();
        }
    }
}
