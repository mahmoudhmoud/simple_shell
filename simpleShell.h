#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

char **str_tokeniz(char *line);
void prompt(void);
int exe_comd(char **comd, char **argv, int child_cnt);
void free_arr(char **array);
char *locate_path(char *command);

/*string functions*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);

/*built-in*/
int command_builtin(char **comd);
void exe_builtin(char **comd, char **argv);

void command_err(char **command, char **argv, int count);
#endif

