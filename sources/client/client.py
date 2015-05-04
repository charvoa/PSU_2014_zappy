import socket

s = socket.socket()
host = socket.gethostname()
port = 4242

s.connect((host, port))

while True:
    var = input("$> ")
    s.send(var.encode())
    print(s.recv(1024))
    if var == "exit":
        print("Goodbye")
        break
s.close
