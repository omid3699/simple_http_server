use std::net::{TcpListener, TcpStream};
use std::io::Write;

fn handle_client(mut stream: TcpStream) {
    let response = 
        "HTTP/1.1 200 OK\r\n\
        Content-Type: text/html\r\n\r\n\
        <h1>Hello World</h1>";
    stream.write_all(response.as_bytes()).unwrap();
}

fn main() {
    let listener = TcpListener::bind("127.0.0.1:8080").unwrap();
    println!("Server is running on http://localhost:8080");

    for stream in listener.incoming() {
        match stream {
            Ok(stream) => handle_client(stream),
            Err(e) => eprintln!("Error: {}", e),
        }
    }
}
