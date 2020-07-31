#include <iostream>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <string>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

int main()
{
	// Initialze winsock
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0)
	{
		cerr << "Can't Initialize winsock! Quitting" << endl;
		exit(1);
	}

	// Create a socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << "Can't create a socket! Quitting" << endl;
		exit(1);
	}

	// Bind the ip address and port to a socket
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY; // Could also use inet_pton .... 

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	// Tell Winsock the socket is for listening 
	listen(listening, SOMAXCONN);

	// Wait for a connection
	sockaddr_in client;
	int clientSize = sizeof(client);

	SOCKET clientSocket1 = accept(listening, (sockaddr*)&client, &clientSize);
	char buf[4096];
	char* a = "Wait";
	send(clientSocket1, a, sizeof(a) + 1, 0);

	sockaddr_in client2;
	int clientSize2 = sizeof(client2);
	SOCKET clientSocket2 = accept(listening, (sockaddr*)&client2, &clientSize2);
	a = "Client 2";
	send(clientSocket2, a, sizeof(a) + 1, 0);
	

	// Close listening socket
	closesocket(listening);

	// While loop: accept and echo message back to client
	a = "GO";
	send(clientSocket2, a, sizeof(a) + 1, 0);
	a = "GO";
	send(clientSocket1, a, sizeof(a) + 1, 0);
	

	while (true)
	{
		ZeroMemory(buf, 4096);

		// Wait for client to send data
		int bytesReceived = recv(clientSocket1, buf, 4096, 0);
		if (bytesReceived == SOCKET_ERROR)
		{
			cerr << "Error in recv(). Quitting" << endl;
			break;
		}

		if (bytesReceived == 0)
		{
			cout << "Client disconnected " << endl;
			break;
		}

		cout << string(buf, 0, bytesReceived) << endl;
		// Echo message to client 2
		send(clientSocket2, buf, bytesReceived + 1, 0);

		// Wait for client2 to send data
		int bytesReceived2 = recv(clientSocket2, buf, 4096, 0);
		if (bytesReceived2 == SOCKET_ERROR)
		{
			cerr << "Error in recv(). Quitting" << endl;
			break;
		}

		if (bytesReceived2 == 0)
		{
			cout << "Client disconnected " << endl;
			break;
		}

		cout << string(buf, 0, bytesReceived2) << endl;
		// Echo message to client 1
		send(clientSocket1, buf, bytesReceived2 + 1, 0);


	}

	// Close the socket
	closesocket(clientSocket1);
	closesocket(clientSocket2);

	// Cleanup winsock
	WSACleanup();

	system("pause");
	return 0;
}