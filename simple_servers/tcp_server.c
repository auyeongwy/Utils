#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


static void do_abort(const char* const p_msg);

int main(int argc, char* argv[])
{
	int sock;
	struct protoent *protoent_ptr;
	
	if ((protoent_ptr = getprotobyname("TCP")) == NULL) 
		do_abort("Protocol config error.");
	
	if ((sock = socket(AF_INET, SOCK_STREAM, protoent_ptr->p_proto)) == -1)
		do_abort("Socket error.");
	
	close(sock);
	return 0;
}


static void do_abort(const char* const p_msg)
{
	printf("%s\n", p_msg);
	exit(-1);
}