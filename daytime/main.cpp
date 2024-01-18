#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <memory>
#include <string>
#include <unistd.h>
#include <stdexcept>
using namespace std;
class crit_error:public std::runtime_error
{
public:
    crit_error(const std::string& s):std::runtime_error(s) {}
};
int main()
{
    try {
        struct sockaddr_in servaddr;
        int sock=socket(AF_INET,SOCK_DGRAM,0);
        if (sock<0) {
            throw crit_error ("Ошибка создания сокета");
        }
        int buff_size=1024;
        std::unique_ptr<char[]> buffer(new char[buff_size]);
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(13);
        inet_aton("82.179.90.12",&servaddr.sin_addr);
        int send_b=sendto(sock,nullptr,0,0,(struct sockaddr*)&servaddr,sizeof(servaddr));
        if (send_b<0) {
            throw crit_error ("Ошибка отправки собщения серверу");
        }
        int recv_b=recvfrom(sock,buffer.get(),buff_size-1,0,0,0);
        if (recv_b<0) {
            throw crit_error ("Ошибка приема собщения от сервера");
        }
        buffer[recv_b]='\n';
        string message(buffer.get(),recv_b);
        cout<<"Текущее время: "+message;
        close(sock);
    } catch(crit_error &e) {
        cout<<e.what()<<endl;
    }
    return 0;
}
