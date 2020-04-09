#include "include/openbreath.h"

Command OpenBreath::commands[] = {
    { .command = "help", .description = "Prints this command", .callback = &OpenBreath::PrintHelp},

    {NULL, NULL, NULL}
};