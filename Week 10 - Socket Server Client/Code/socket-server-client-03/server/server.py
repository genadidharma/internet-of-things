import socket
from threading import Thread
from datetime import datetime

# Multithreaded Python server
class ClientThread(Thread):

    def __init__(self, ip, port):
        Thread.__init__(self)
        self.ip = ip
        self.port = port
        print("Incoming connection from " + ip + ":" + str(port))

    def run(self):
            while True:
                try:
                    data = conn.recv(2048)
                    if len(data) == 0:
                        break

                    hours,_,_ = map(int, data.decode('utf8').split(':'))

                    MESSAGE = self.get_part_of_day(int(hours))
                    print("Good ", MESSAGE)
                    conn.send(MESSAGE.encode("utf8"))
                except Exception as e:
                    print(e)
                    break

    def get_part_of_day(self, h):
        return (
            "morning"
            if 5 <= h <= 11
            else "afternoon"
            if 12 <= h <= 17
            else "evening"
            if 18 <= h <= 22
            else "night"
        )


TCP_IP = "0.0.0.0"
TCP_PORT = 9000
BUFFER_SIZE = 20

tcpServer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcpServer.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
tcpServer.bind((TCP_IP, TCP_PORT))
threads = []

while True:
    tcpServer.listen(4)
    print("Server started on " + TCP_IP + " port " + str(TCP_PORT))
    (conn, (ip, port)) = tcpServer.accept()
    newthread = ClientThread(ip, port)
    newthread.start()
    threads.append(newthread)

for t in threads:
    t.join()
