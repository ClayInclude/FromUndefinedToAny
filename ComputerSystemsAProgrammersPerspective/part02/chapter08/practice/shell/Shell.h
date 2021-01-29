/**
 * Shell
 * @author Clay
 * @date 2021/1/29
 */

#ifndef FROM_UNDEFINED_TO_ANY_SHELL_H
#define FROM_UNDEFINED_TO_ANY_SHELL_H

#define MAX_ARGS 128

#include <stdbool.h>
#include "csapp.h"
#include "Job.h"

void eval(char *cmdline);

bool parseline(char *buffer, char *argv[]);

bool builtinCommand(char *argv[]);

#endif //FROM_UNDEFINED_TO_ANY_SHELL_H
