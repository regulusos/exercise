#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void do_cd(char *argv[]);
void execute_new(char *argv[]);
