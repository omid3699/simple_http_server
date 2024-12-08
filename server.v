import net

fn main() {
    mut listener := net.listen_tcp(.ip6, ':8080') or { panic(err) }
    println('Server is running on http://localhost:8080')

    for {
        mut conn := listener.accept() or { continue }
        response := 'HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello World</h1>'
        conn.write_string(response) or { continue }
        conn.close() or {}
    }
}
