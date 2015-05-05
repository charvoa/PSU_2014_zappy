import socket
import signal
import sys

def signal_handler(signal, frame):
    print('You pressed Ctrl+C')
    sys.exit(0)

def connect():
    s = socket.socket()
    host = socket.gethostname()
    port = 4242
    s.connect((host, port))
    return s;

def read_message():
    signal.signal(signal.SIGINT, signal_handler)
    return input("$> ")

def send_message(s, var):
    s.send(var.encode())

def execute(s):
    while True:
        var = read_message()
        send_message(s, var)
        print(s.recv(1024))
        if var == "exit":
            print("Goodbye")
            break
        s.close

def main():
    s = connect()
    execute(s)

if __name__ == "__main__":
    main()
