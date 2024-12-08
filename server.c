#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    char response[] = 
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n\r\n"
        "<h1>Hello World</h1>";

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(server_fd);
        exit(1);
    }

    if (listen(server_fd, 10) == -1) {
        perror("Listen failed");
        close(server_fd);
        exit(1);
    }

    printf("Server is running on http://localhost:8080\n");

    while ((client_fd = accept(server_fd, NULL, NULL)) != -1) {
        write(client_fd, response, sizeof(response) - 1);
        close(client_fd);
    }

    close(server_fd);
    return 0;
}
