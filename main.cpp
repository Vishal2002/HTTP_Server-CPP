#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
using namespace std;

const int PORT = 8080;

void handleRequest(int clientSocket) {
    const string response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, Vishal!";
    send(clientSocket, response.c_str(), response.size(), 0);
    close(clientSocket);
}

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize = sizeof(struct sockaddr_in);

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "Error creating socket" << endl;
        return EXIT_FAILURE;
    }

    // Setup server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        cerr << "Error binding socket" << endl;
        close(serverSocket);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 10) == -1) {
        cerr << "Error listening for connections" << endl;
        close(serverSocket);
        return EXIT_FAILURE;
    }

    cout << "Server listening on port " << PORT << endl;

    while (true) {
        // Accept a connection
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrSize);
        if (clientSocket == -1) {
            cerr << "Error accepting connection" << endl;
            close(serverSocket);
            return EXIT_FAILURE;
        }

        // Handle the request
        handleRequest(clientSocket);
    }

    // Close the server socket
    close(serverSocket);

    return EXIT_SUCCESS;
}
