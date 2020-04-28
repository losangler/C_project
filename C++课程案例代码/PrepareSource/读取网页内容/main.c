#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")

void ReadPage(char* host)
{
    WSADATA data;
	//winsock�汾2.2
	int err = WSAStartup(MAKEWORD(2, 2), &data);
	if (err)
		return ;
    //��������ȡ�Է�������
	struct hostent *h = gethostbyname(host);
	if (h == NULL)
		return ;
    //IPV4
	if (h->h_addrtype != AF_INET)
		return ;
	struct in_addr ina;
	//����IP
	memmove(&ina, h->h_addr, 4);
	LPSTR ipstr = inet_ntoa(ina);
	//Socket��װ
	struct sockaddr_in si;
	si.sin_family = AF_INET;
	si.sin_port = htons(80);
	si.sin_addr.S_un.S_addr = inet_addr(ipstr);
	int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	connect(sock, (SOCKADDR*)&si, sizeof(si));
	if (sock == -1 || sock == -2)
		return ;
    //��������
	char request[1024] = "GET /?st=1 HTTP/1.1\r\nHost:";
	strcat(request, host);
    strcat(request, "\r\nConnection:Close\r\n\r\n");
    int ret = send(sock, request, strlen(request), 0);
    //��ȡ��ҳ����
    FILE *f = fopen("recieved.txt", "w");
    int isstart = 0;
    while (ret > 0)	{
        const int bufsize = 1024;
        char* buf = (char*)calloc(bufsize, 1);
        ret = recv(sock, buf, bufsize - 1, 0);
        fprintf(f, "%s", buf);
        free(buf);
    }
    fclose(f);
	closesocket(sock);
	WSACleanup();
	printf("��ȡ��ҳ���ݳɹ����ѱ�����recieved.txt��");

}
//������ֻ������IPV4��http����
//�����txt�ļ��ü��±���ʱ���뽫�����Ϊutf8��������Ĭ�ϵ�ASCII�����������������롣
int main()
{
    //�ٶ�����ֱ���������ӣ�https://www.baidu.com/s?wd=�����ؼ���
    ReadPage("www.baidu.com");
    return 0;
}
