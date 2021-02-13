#include <errno.h>
#include <signal.h>
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
  int  i = rand() % (9) + 2;
  int count = 0;
  struct timespec it = {i, 0};
  while (1) {
      nanosleep(&it, NULL);
      
  }
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

void parent_work(int k, int m) {
  struct timespec tk = {0, m};
  while (k-- > 0) {
    nanosleep(&tk, NULL);
    if (kill(0, SIGUSR1) < 0)
      ERR("kill");
  }
  if (kill(0, SIGUSR2) < 0)
    ERR("kill");
}
void usage(char *name) {
  fprintf(stderr, "USAGE: %s n m\n", name);
  fprintf(stderr, "n - number of child processes [3;10]\n");
  fprintf(stderr, "m - length of pause in ms [1;500]\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
  int n, m;
  char *k = malloc(5);
  if (argc != 3)
    usage(argv[0]);
  n = atoi(argv[1]);
  m = atoi(argv[2]);

  if (n < 3 || n > 10)
    usage(argv[0]);

  if (m < 1 || m > 500)
    usage(argv[0]);

  create_children(n);

  sethandler(sig_handler, SIGUSR1);
  sethandler(sig_handler, SIGUSR2);
  //  sethandler(sig_handler, SIGTERM);

  while (scanf("%s", k)) {
    if (strcmp(k, "exit") == 0)
      kill(0, SIGTERM);
    else if (atoi(k) >= 2 && atoi(k) <= 20) {
      parent_work(atoi(k), m);
    } else {
      printf("Only [2;20] numbers or exit to end\n");
    }
  }
  free(k);
  while (wait(NULL) > 0)
    ;

  /* while (n > 0) {
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
  } */
  return EXIT_SUCCESS;
}