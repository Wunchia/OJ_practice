#pragma comment(lib,"ws2_32.lib")

#include <stdio.h>
#include <winsock2.h>
#include <windows.h>

//socket
//connect
//send  recv
//close

int main(int argc,char *argv[]) {
    WORD sockVersion= MAKEWORD(2,2);
    WSADATA wsaData;
    SOCKET clientSocket;
//    struct sockaddr_in {
//        short	sin_family;
//        u_short	sin_port;
//        struct in_addr	sin_addr;
//        char	sin_zero[8];
//    };
    struct sockaddr_in serverAddr;

    //初始化WSA，加载Winsock库
    if(WSAStartup(sockVersion,&wsaData)!=0){//初始化失败，退出
        printf("failed to initialize Winsock\n");
        return -1;
    }

    //创建客户端套接字，ipv4,SOCK_STREAM代表初始化tcp套接字，TCP协议。如果是SOCK_DGRAM则是udp套接字
    clientSocket= socket(AF_INET,SOCK_STREAM,0);//AF_INET意味着是ipv4
    if(clientSocket==INVALID_SOCKET){
        printf("failed to create socket!\n");
        WSACleanup();
        return -1;
    }


    //设置服务器地址和端口
    const char *serverIP="127.0.0.1";
    const int serverPort=9999;
    serverAddr.sin_family=AF_INET;//代表进行ipv4，如果是ipv6，则为AF_INET6
    serverAddr.sin_addr.s_addr= inet_addr(serverIP);//作用是将一个点分十进制的IP转换成一个网络字节序的整数型数
    serverAddr.sin_port=htons(serverPort);//端口号，htons进行字节序转换，将小端转化成大端
    //127.0.0.1是本地回环地址，用于本地网络通信测试，也可以改为本机的IP地址

    //连接到服务器，如果服务器那边没有在accept，那么这里请求5次后，就会失败
    if(connect(clientSocket,(struct sockaddr *)&serverAddr,sizeof(serverAddr))==SOCKET_ERROR){
        printf("failed to connect to server !\n");
        closesocket(clientSocket);
        WSACleanup();
        return -1;
    }

    printf("connected to server\n");//连接成功

    //发送数据
    char buffer[1024]="I am client";
    if(send(clientSocket,buffer,strlen(buffer),0)==SOCKET_ERROR){
        printf("failed to send data\n");
        return -1;
    };//发送数据给服务端

    //接收数据，recv函数接收数据到buffer，返回值是实际接收到的字节数，失败返回-1
    int bytesRead= recv(clientSocket,buffer,sizeof(buffer),0);
    if(bytesRead<=0){
        printf("connection closed by server\n");
        return -1;
    }
    buffer[bytesRead]='\0';//在接收到的字符串末尾添加结束符
    //打印接收到的数据
    printf("Received:%s\n",buffer);

    closesocket(clientSocket); //关闭套接字,四次挥手
    WSACleanup();//清理winsock库，释放相关资源

    return 0;
}