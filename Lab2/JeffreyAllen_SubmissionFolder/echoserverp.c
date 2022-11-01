/* 
 * echoserverp.c - A concurrent echo server based on processes
 */
/* $begin echoserverpmain */
#include "csapp.h"
void echo(int connfd);

// First, servers typically run for long periods of time, so we must include a SIGCHLD handler that
// reaps zombie children. Since SIGCHLD signals are blocked while the SIGCHLD handler
// is executing, and since Unix signals are not queued, the SIGCHLD handler must be prepared to reap
// multiple zombie children.
void sigchld_handler(int sig) //line:conc:echoserverp:handlerstart
{
    while (waitpid(-1, 0, WNOHANG) > 0);
    return;
} //line:conc:echoserverp:handlerend

int main(int argc, char **argv) 
{
    int listenfd, connfd;
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;

    if (argc != 2) {
      fprintf(stderr, "usage: %s <port>\n", argv[0]);
      exit(0);
    }

    Signal(SIGCHLD, sigchld_handler);
    listenfd = Open_listenfd(argv[1]); // Close copy of connfd to avoid memory leak
    while (1) {
      clientlen = sizeof(struct sockaddr_storage); 
      connfd = Accept(listenfd, (SA *) &clientaddr, &clientlen); // Close copy of connfd to avoid memory leak
      if (Fork() == 0) { 
        Close(listenfd); /* Child closes its listening socket */
        echo(connfd);    /* Child services client */ //line:conc:echoserverp:echofun
        Close(connfd);   /* Child closes connection with client */ //line:conc:echoserverp:childclose
        exit(0);         /* Child exits */
      }
      Close(connfd); /* Parent closes connected socket (important!) */ //line:conc:echoserverp:parentclose
    }
}
/* $end echoserverpmain */
