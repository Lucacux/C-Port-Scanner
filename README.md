# TCP Port Scanner in C

This is a simple port scanner written in C for POSIX systems that uses TCP sockets to check whether the ports on a server are open or closed. The program allows the user to input a hostname or IP address, and a range of ports to scan.

## Description

The code attempts to establish a TCP connection to each port within the specified range. If the connection succeeds, the port is marked as open; if it fails, the port is marked as closed. This scan is done with a very basic approach using the `connect()` function from C sockets.

### Features

- Scans a range of ports.
- Supports scanning by hostname or direct IP address.
- Displays the status of each port (open or closed).
- Uses low-level Linux (POSIX) sockets, providing a better understanding of network behavior at the code level.

## Requirements

This program requires a POSIX system and standard libraries for socket handling:

- `<stdio.h>`
- `<sys/socket.h>`
- `<errno.h>`
- `<netdb.h>`
- `<string.h>`
- `<stdlib.h>`
- `<unistd.h>`
- `<arpa/inet.h>`
## Compilation

To compile the program, open a terminal in the directory where the `tcp_port_scanner.c` file is located and run the following command:

```bash
gcc -o tcp_port_scanner tcp_port_scanner.c
