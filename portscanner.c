// code tutorial here: http://www.binarytides.com/tcp-connect-port-scanner-c-code-linux-sockets/
// understanding syn-syn-ack: http://www.inetdaemon.com/tutorials/internet/tcp/3-way_handshake.shtml

#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // Required for the read () function
#include <arpa/inet.h> // Required for inet_pton()

int main(int argc, char **argv){

    struct hostent *host;
    int err, i, sock, start, end;
    char hostname[100];
    struct sockaddr_in sa;

    printf("Enter hostname or IP:");
    fgets(hostname, sizeof(hostname), stdin); // Read up to 100 characters.
    hostname[strcspn(hostname, "\n")] = '\0';  // Remove the newline character at the end

    printf("\n");

    printf("Enter start port number: ");
    scanf("%d", &start);

    printf("\n");

    printf("Enter end port number: ");
    scanf("%d", &end);
    
    // Init. 'sa' structure to zero.
    memset(&sa, 0, sizeof(sa)); // Clear the structure
    sa.sin_family = AF_INET;

    // If the hostname is a valid IP, use inet_pton to convert it.
    if (inet_pton(AF_INET, hostname, &sa.sin_addr) <= 0) {
        // If it's not a valid IP, try resolving the hostname
        if ((host = gethostbyname(hostname)) != NULL) {
            memcpy(&sa.sin_addr, host->h_addr, host->h_length);
        } else {
            perror("Hostname resolution failed");
            exit(2);
        }
    }

    // Scan the specified port range
    for(i = start;  i <= end; i++){
        printf("Scanning port %i\n",i);

        sa.sin_port = htons(i);
        sock = socket(AF_INET, SOCK_STREAM, 0);

        // Check if socket creation failed
        if(sock < 0){
            perror("Socket creation failed");
            exit(1);    
        }

        err = connect(sock, (struct sockaddr*)&sa, sizeof sa);

        if (err < 0){
            // If connection fails, the port is closed
            printf("Port %i is closed\n", i);
        }
        else {
            // If connection succeeds, the port is open
            printf("Port %i is open\n", i);
        }
        close(sock);
    }
    return 0;
}
