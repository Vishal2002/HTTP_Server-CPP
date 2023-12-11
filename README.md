# Simple C++ HTTP Server

This is a minimalistic C++ program that creates a basic HTTP server. The server listens on port 8080 and responds with a simple "Hello, Vishal!" message for every incoming HTTP request.

## Usage

1. **Compile the code:**

    ```bash
    g++ main.cpp -o http_server
    ```

2. **Run the executable:**

    ```bash
    ./http_server
    ```

3. **Open your web browser and navigate to [http://localhost:8080](http://localhost:8080).**

## Customization

You can customize the response message by editing the `handleRequest` function in the code:

```cpp
const string response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, Vishal!";
