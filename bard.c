// Network/ Internet Congestion Control 
// developed by Christopher W. Brown and Bard Ai
// helping code checkers you.com and Chat GPT
// Created By Myself and this couldn't have been possible
// thank you Google. This code is initialy for linux kernal.
// Created on July 16th 11:30 pm Philippine time.
// An American in the Philippines made this using a 
// Infinix cellphone. Original version of this was for peso wifi
// I decided to make this for the world to use.
// One day hopefully Free BSD and Net BSD will consider it.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
struct Connection {
double congestion_window;
};
struct HashTable {
struct Connection *connections;
int size;
};
void hash_table_init(struct HashTable *table, int size) {
table->connections = malloc(sizeof(struct Connection) * size);
if (table->connections == NULL) {
printf("Failed to allocate memory for hash table connections.\n");
exit(1);
}
table->size = size;
}
void hash_table_insert(struct HashTable *table, int key, struct Connection
connection) {
int index = key % table->size;
table->connections[index] = connection;
}
struct Connection *hash_table_lookup(struct HashTable *table, int key) {
int index = key % table->size;
return &table->connections[index];
}
double congestion_control(double congestion_window_size, size_t
packet_size) {
congestion_window_size = 100; // Initialize the variable
double favorable_size = congestion_window_size * (100 / packet_size);
// Calculate the Packet Delay Variation (PDV) for each packet.
double pdv = get_pdv();
// If the PDV is above a certain threshold, then reduce the congestion
window size
// by a percentage that is proportional to the severity of the
disturbance.
if (pdv > 100) {
congestion_window_size = congestion_window_size * 0.9;
}
// If the PDV is below a certain threshold, then increase the congestion
window size
// by a percentage that is proportional to the bandwidth of the network.
else if (pdv < 50) {
congestion_window_size = congestion_window_size * 1.1;
}
return congestion_window_size;
}
double get_round_trip_time() {
struct timeval send_time, recv_time;
struct sockaddr_in dest;
int sockfd;
int fromlen = sizeof(struct sockaddr);
sockfd = socket(AF_INET, SOCK_DGRAM, 0);
if (sockfd < 0) {
perror("socket");
exit(1);
}
dest.sin_family = AF_INET;
dest.sin_port = htons(80);
dest.sin_addr.s_addr = inet_addr("www.google.com");
gettimeofday(&send_time, NULL);
sendto(sockfd, NULL, 0, 0, (struct sockaddr *)&dest, sizeof(dest));
recvfrom(sockfd, NULL, 0, 0, (struct sockaddr *)&dest, &fromlen);
gettimeofday(&recv_time, NULL);
return (recv_time.tv_sec - send_time.tv_sec) +
(recv_time.tv_usec - send_time.tv_usec) / 1000000.0;
}
double get_bandwidth() {
// Query a network monitoring service to get the current bandwidth.
double bandwidth = 100000;
return bandwidth;
}
double get_pdv() {
// Monitor the network for signs of congestion.
//double pdv = 0.0;
double pdv = 100.0;
return pdv;
}
int main() {
double congestion_window_size = 100;
size_t packet_size = 1000;
//double new_congestion_window =
congestion_control(congestion_window_size,
//packet_size);
//printf("The new congestion window size is %f\n", new_congestion_window);
return 0;
}
