#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

char **str_tokeniz(char *line);
void prompt(void);
int exe_comd(char **comd, char **argv);
void free_arr(char **array);

#endif
