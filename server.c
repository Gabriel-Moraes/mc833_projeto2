// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#include "actions.h"

// #define SockAddr struct sockaddr
#define PORT 8080
#define MAX 200
#define MAXLINE 1024
char* removeNewLinesServer(char* data){
    int len = strlen(data);
    int i;
    for(i=0;i < len ; i++){
        if(data[i]=='\n' || data[i] == '\t'|| data[i] == '\r') {
            data[i] = 0;
        }
    }
    return data;
}

void exchangeMessages(int sock, struct sockaddr_in clientAddress, char* buff) {
    // char buff[MAX];
    socklen_t lenAddress = sizeof(clientAddress);
    // Loop infinito para manter a troca de mensagens
	// Zera o conteúdo do buffer
    // bzero(buff, MAX);
    // Le a mensagem recebida e copia para o buffer
    // read(sock, buff, sizeof(buff));
	// Printa a mensagem recebida
    // printf("Mensagem recebida do cliente %d: %s\n", sock, buff);
	// char* buff2 = removeNewLinesServer(buff);
	printf("esse e o buffer %s<\n", buff);
	printf("esse e o sock %d<\n", sock);
	//printf("o request é: %s\n", buff);
	int requestError = treatClientActionRequest(sock, buff, clientAddress);
	if (requestError == -2) {
	    
        sendto(sock, "5", strlen("5"),
	MSG_CONFIRM, (const struct sockaddr *) &clientAddress,
		lenAddress);
        sendto(sock, "exit\n", strlen("exit\n"),
	MSG_CONFIRM, (const struct sockaddr *) &clientAddress,
		lenAddress);
		printf("Cliente %d saiu do servidor...\n", sock);
	} else if (requestError < 0) {
        sendto(sock, "16", strlen("16"),
	MSG_CONFIRM, (const struct sockaddr *) &clientAddress,
		lenAddress);
        sendto(sock, "Açao invalida!\n", strlen("Açao invalida!\n"),
	MSG_CONFIRM, (const struct sockaddr *) &clientAddress,
		lenAddress);
		printf("requisicao: %d", requestError);
	}
    
}
// Driver code
int main() {
	char buffer[MAX];
	bzero(buffer, MAX);
	// char *hello = "Hello from server";
	struct sockaddr_in serverAddress, clientAddress;
	// int client_socket[10];
    int master_socket;
    // Inicializa o vetor de sockets 
	// for (i=0; i < 10; i++) {
	// 	client_socket[i] = 0;
	// }
    // Cria o socket mestre
	master_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if (master_socket == 0) {
		printf("Falha ao criar o socket... Erro: %d\n", errno);
		exit(-1);
	} else {
		printf("Socket criado com sucesso!\n");
	}

	
	memset(&serverAddress, 0, sizeof(serverAddress));
	
	// Atribui valores da porta, do tipo de IP e dos endereços aceitos para o servidor
	serverAddress.sin_family = AF_INET; // IPv4
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_port = htons(PORT);
	
	// Bind the socket with the server address
    int bindReturn = bind(master_socket, (const struct sockaddr*)&serverAddress, sizeof(serverAddress));
	if ( bindReturn < 0 )
	{
		printf("Falha ao realizar o bind... Erro: %d\n", errno);
		exit(-1);
	} else {
		printf("Bind realizado com sucesso!\n");
	}
	while (1) {
		bzero(buffer, MAX);

		int n;
		memset(&clientAddress, 0, sizeof(clientAddress));
		int lenAddress = sizeof(clientAddress); 
		//para ler o dado que está vindo do cliente
		printf("lendo mensagem do cliente...\n");
		n = recvfrom(master_socket, (char*)buffer, MAX,
					MSG_WAITALL, (struct sockaddr *) &clientAddress,
					(socklen_t *)&lenAddress);
		buffer[n] = '\0';
		printf("Mensagem recebida do Cliente : %s\n", buffer);
		
		exchangeMessages(master_socket, clientAddress, buffer);

		// sendto(master_socket, (const char *)hello, strlen(hello),
		// 	MSG_CONFIRM, (const struct sockaddr *) &clientAddress,
		// 		lenAddress);
		// printf("Hello message sent.\n");
	}
	
	
	return 0;
}
