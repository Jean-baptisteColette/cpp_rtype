#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iomanip>
#include "main.hpp"
#define BUFSIZE 1024

#include "../../common/tools/Data.hpp"

int main(int argc, char **argv)
{
  int sockfd, portno, n;
  int serverlen;
  struct sockaddr_in serveraddr;
  struct hostent *server;
  char *hostname;
  char buf[BUFSIZE];

  // check command line arguments
  if (argc != 3)
  {
    fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
    exit(0);
  }
  hostname = argv[1];
  portno = atoi(argv[2]);

  // socket: create the socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0)
    std::cout << "ERROR opening socket\n";

  // gethostbyname: get the server's DNS entry
  server = gethostbyname(hostname);
  if (server == NULL)
  {
    fprintf(stderr, "ERROR, no such host as %s\n", hostname);
    exit(0);
  }

  /* build the server's Internet address */
  bzero((char *)&serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
        (char *)&serveraddr.sin_addr.s_addr, server->h_length);
  serveraddr.sin_port = htons(portno);
  /*  while (42)
  {

    struct t_connection c;
    struct t_die d;
    struct t_attack a;
    struct t_moove m;

    c.opcode = sizeof(struct t_connection);
    c.idPlayer = 46563;
    d.opcode = sizeof(t_die);
    a.opcode = sizeof(t_attack);
    m.opcode = sizeof(t_moove);

    char *c_ = new char[sizeof(struct t_connection)];
    char *d_ = new char[sizeof(t_die)];
    char *a_ = new char[sizeof(t_attack)];
    char *m_ = new char[sizeof(t_moove)];

    //Data::serialise(c, c_);
    Data::serialise(d, d_);
    Data::serialise(a, a_);
    Data::serialise(m, m_);

    memcpy(c_, &c, sizeof(struct t_connection));

    struct t_test x;
    char *x_ = new char[sizeof(t_test)];

    x.a = 'a';
    x.b = 4242;
    memset(x_, 0, sizeof(t_test));
    memcpy(x_, &x, sizeof(t_test));

    std::cout << " X = " << x_ << std::endl;

    int i = 0;
    serverlen = sizeof(serveraddr);

    bzero(buf, BUFSIZE);
    printf("Please enter msg: ");
    fgets(buf, BUFSIZE, stdin);

    while (i < 5)
    {
      n = sendto(sockfd, x_, sizeof(struct t_test), 0, (struct sockaddr *)&serveraddr, serverlen);
      // n = sendto(sockfd, d_, strlen(d_), 0, (struct sockaddr*)&serveraddr, serverlen);
      // n = sendto(sockfd, a_, strlen(a_), 0, (struct sockaddr*)&serveraddr, serverlen);
      // n = sendto(sockfd, m_, strlen(m_), 0, (struct sockaddr*)&serveraddr, serverlen);

      i++;
    }*/
  while (42)
  {

    bzero(buf, BUFSIZE);
    printf("Please enter msg: ");
    fgets(buf, BUFSIZE, stdin);
    t_connection t;
    t_attack a;
   // t_moove m;
    t_die d;
    a.opcode = sizeof(t_attack);
    //m.opcode = sizeof(t_moove);
    d.opcode = 80;

    t.opcode  = 0x0A;
    
    //m.idPlayer = 4242;
    //m.x = 4243;
    //m.y = 4244;

    //a.idPlayer = 4242;
    //a.power = 50;

    //d.idPlayer = 4242;

    int i = 0;
    //    while (i < 1000)
    //{
    const char *tmp = "coucou";
    //sendto(sockfd, tmp, 6, 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

        sendto(sockfd, &t, sizeof(struct t_connection), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

     sendto(sockfd, &a, sizeof(struct t_attack), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

   // sendto(sockfd, &m, sizeof(struct t_moove), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    sendto(sockfd, &d, sizeof(struct t_die), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
      i++;
      //}
  }
  /* send the message to the server */
  // if (n < 0)
  //  std::cout << "ERROR in sendto\n";
  //else
  //printf("msg sent\n");
  //}
  /* print the server's reply */
  //  n = recvfrom(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&serveraddr, (socklen_t *)&serverlen);
  //if (n < 0)
  //std::cout << "ERROR in recvfrom\n";
  //printf("Echo from server: %s", buf);
  return 0;
}

/*
int main(void)
{
  struct sockaddr_in si_other;
  int s, i, slen=sizeof(si_other);
  char buf[BUFLEN];
  if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
    diep("socket");
  memset((char *) &si_other, 0, sizeof(si_other));
  si_other.sin_family = AF_INET;
  si_other.sin_port = htons(PORT);
  if (inet_aton(SRV_IP, &si_other.sin_addr)==0) {
    fprintf(stderr, "inet_aton() failed\n");
    exit(1);
  }
  for (i=0; i<NPACK; i++) {
    printf("Sending packet %d\n", i);
    sprintf(buf, "This is packet %d\n", i);
    if (sendto(s, buf, BUFLEN, 0, &si_other, slen)==-1)
      diep("sendto()");
  }
  close(s);
  return 0;
  }*/
