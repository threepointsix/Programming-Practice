#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define ERR(source)                                                            \
  (fprintf(stderr, "%s:%d\n", __FILE__, __LINE__), perror(source),             \
   kill(0, SIGKILL), exit(EXIT_FAILURE))

volatile sig_atomic_t sig_count = 0;

void sethandler(void (*f)(int), int sigNo) {
  struct sigaction act;
  memset(&act, 0, sizeof(struct sigaction));
  act.sa_handler = f;
  if (-1 == sigaction(sigNo, &act, NULL))
    ERR("sigaction");
}

void sig_handler(int sig) { sig_count++; }

void child_work() {
  srand(time(NULL) * getpid());
  int xxx = rand() % (1401) + 100;
  struct timespec t = {xxx/1000, xxx%1000};
  nanosleep(&t, NULL);
  printf("PID: %lu I was sleeping for %dms\n", (long)getpid(), xxx);
}

void create_children(int n) {
  pid_t s;
  // for(n--; n >= 0; n--)
  while (n--) {
    if ((s = fork()) < 0)
      ERR("Fork:");
    if (!s) // i.e. if s == 0 !!!!
    {
      child_work();
      exit(EXIT_SUCCESS);
    }
  }
}

void usage(char *name) {
  fprintf(stderr, "USAGE: %s n m\n", name);
  fprintf(stderr, "n - number of child processes [3;10]\n");
  fprintf(stderr, "m - length of pause in ms [1;500]\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
  int n;
  if (argc != 2)
    usage(argv[0]);
  n = atoi(argv[1]);
  // m = atoi(argv[2]);
  create_children(n);

  while (n > 0) {
    sleep(1);
    pid_t pid;
    for (;;) {
      pid = waitpid(0, NULL, WNOHANG);
      if (pid > 0)
        n--;
      if (0 == pid)
        break;
      if (0 >= pid) {
        if (ECHILD == errno)
          break;
        ERR("waitpid:");
      }
    }
  }
  return EXIT_SUCCESS;
}