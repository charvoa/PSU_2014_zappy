import signal

from ModuleConnect import *
from GetOptions import *

def signal_handler(signal, frame):
    print('You pressed Ctrl+C')
    sys.exit(0)

def send_message(s, var):
    s.send(var.encode())

def get_message():
    signal.signal(signal.SIGINT, signal_handler)
    return input('$> ')

def execute(s):
    while True:
        var = get_message()
        send_message(s, var)
        print(s.recv(1024))
        if var == "exit":
            print("Goodbye")
            break
        s.close

def main():
    mc = ModuleConnect()
    s = mc.connect(4242)
    p = GetOptions()
    p.parse_opt()
    execute(s)

if __name__ == "__main__":
    main()
