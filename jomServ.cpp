#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <limits.h>

#define PORT 8989
#define BUFSIZE 4096
#define SOCKETERROR (-1)
#define SERVER_BACKLOG 1

typedef struct sockaddr_in SA_IN;
typedef struct sockaddr SA;

void handle_connection(int client_socket);
int check(int exp, const char *msg);

int main(int argc, char **argv)
{
        struct client_var
        {
                int adresa;
                char nume[10];
                int bila = 0;
                int nr_adv = 0;
        }
        client_var client[8];
        int jomterry = 0;
        int server_socket, client_socket, addr_size, nr_con;
        SA_IN server_addr, client_addr;

        check((server_socket = socket(AF_INET, SOCK_STREAM, 0)), "Eroare la crearea socket-ului");

//initializam structura adresei
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(PORT);

        check(bind(server_socket,(SA*)&server_addr, sizeof(server_addr)), "Eroare la bind");
        check(listen(server_socket, SERVER_BACKLOG), "Eroare la listen");

while(true){

        printf("Se asteapta conexiunea...\n")
        //Se asteapta si se accepta conexiunea
        if(nr_con <= 8){
        addr_size = sizeof(SA_IN);

        check(client_socket = accept(server_socket, (SA*)&client_addr, (socklen_t*)&addr_size), "Eroare la acceptare");

        printf("Conectare reusita !\n");
        nr_con = nr_con+1;

        if(jomterry == 0 || jomterry == 1)
        handle_connection(client_socket);

//se verifica daca exista clienti care au primit 3 avertismente si daca sunt, sunt deconectati
        for(int i = 0, i <= 7, i = i + 1)
        if(client[i].nr_adv == 3)
        close(client[i].adresa);
        }
}//while

int handle_connection(int client_socket){
        char buffer[BUFSIZE];
        size_t bytes_read;
        int msgsize = 0;
		
//citim mesajul de la client
        while((bytes_read = read(client_socket, buffer+msgsize, sizeof(buffer)-msgsize-1)) > 0 )
        {
                msgsize += bytes_read;
                if(msgsize > BUFSIZE-1 || buffer[msgsize-1] == '\n') break;
        }
        strcpy(client[nr_con].nume, buffer)
        client[nr_con].adresa = client_socket;

//se verifica clientii daca au numele terry sau jom si daca intalnim le oferim o bila
        if(jomterry == 0){
        if((strcmp(client[nr_con].nume, "Terry") || strcmp(client[nr_con].bume, "Jom")) == 1){
        client[nr_con].bila = 1;
        jomterry = 1;
        if(write(client_socket, jomterry, sizeof(jomterry)) < 0){
                printf("Eroare la trimitere bila!")
                return 0;}
        }}
		
//daca s-a gasit un terry sau un jom atunci verificam daca clientul a trimis mesaj de avertisment
        if(jomterry == 1){
        if(strcmp(buffer, "avertisment") == 1)
        for(int i = 0, i <= 7, i = i + 1)
        if(client[i].bila == 0)
        client[i].nr_adv = client[i].nr_adv + 1;
        }

        return jomterry;
}
return 0;
}
