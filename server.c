#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define SERVPORT 4444

int main(void)
{
	int sockfd,client_fd,client_fd_shoudong;
	int sin_size;int recvbytes;
	char buf[256];char sendbytes[256];
	struct sockaddr_in my_addr,remote_addr; 

     	sockfd=socket(AF_INET,SOCK_STREAM,0);
     	if(sockfd==-1)
     	{
     		perror("socket");
     		exit(1);
     	}

     	bzero(&my_addr,sizeof(struct sockaddr_in) );

    	my_addr.sin_family=AF_INET;
     	my_addr.sin_port=htons(SERVPORT);

     	inet_aton("127.0.0.1",&my_addr.sin_addr);

    	if(bind(sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))
    	==-1)
	{
	        	perror("bind"); 
	        	exit(1);
	}

	if(listen(sockfd,10)==-1)
	{
	           perror("listen");
	           exit(1);
	}

	sin_size=sizeof(struct sockaddr_in);
	client_fd=accept(sockfd,(struct sockaddr *)&remote_addr,&sin_size);
	client_fd_shoudong=accept(sockfd,(struct sockaddr *)&remote_addr,&sin_size);
	
	while(1)
  	{
		memset(buf,0,256);
		recvbytes=recv(client_fd,buf,256,0);
		buf[recvbytes]='\0';

    		printf("%s",buf);  
    		memset(sendbytes,0,256);
   		scanf("%s",sendbytes);
    		send(client_fd,sendbytes,strlen(sendbytes),0);

    		if( strcmp(sendbytes,"c") == 0 ){}    
    		if( strcmp(sendbytes,"f") == 0 ){}   
    		if( strcmp(sendbytes,"d")==0 )
    		 {
			while(1)
			{
				memset(buf,0,256);
				recvbytes=recv(client_fd_shoudong,buf,256,0);
				printf("%s",buf);  memset(sendbytes,0,256);
				scanf("%s",sendbytes);
				send(client_fd_shoudong,sendbytes,strlen(sendbytes),0);
				if( strcmp(sendbytes,"9")==0 )
			     	{
			     		break;
			     	}
			}

           	}   
	    	if( strcmp(sendbytes,"e")==0 )
	    	{  
	    		break;
	    	}
   	 }
 
	close(client_fd);
    	close(sockfd);
}










