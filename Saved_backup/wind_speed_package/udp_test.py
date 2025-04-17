import socket

# Anemometer "192.168.1.31"
# Barometer "192.168.1.34"

TCP_IP = "192.168.1.34"
TCP_PORT = 4001

def main():
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect((TCP_IP, TCP_PORT))
        print("TCP client connected. Press Ctrl+C to stop.")

        while True:
            data = sock.recv(1024)
            if not data:
                break

            decoded_data = data.decode()
            parts = decoded_data.split()

            header = parts[0]
            speed = float(parts[1])
            heading = float(parts[2])
            checksum = parts[3]

            print("Wind Speed:", str(speed))
            print("Heading:   ", str(heading) + "\n")

    except KeyboardInterrupt:
        print("Stopping TCP client.")
    finally:
        sock.close()

if __name__ == "__main__":
    main()
