#include "include/openbreath.h"

Command OpenBreath::commands[] = {
    { .command = "help", .description = "Prints this command", .callback = &OpenBreath::PrintHelp},
    { .command = "release", .description = "Releases terminal and resumes normal operation", .callback = &OpenBreath::ReleaseTerminal },
    { .command = "default info", .description = "Shows default pattern info", .callback = &OpenBreath::DefaultPatternInfo },
    { .command = "s", .description = "Hooks terminal from normal opration", .callback = &OpenBreath::Hook },
    { .command = "stop motor", .description = "Sets motor speed to 0%", .callback = &OpenBreath::StopMotor },
    {NULL, NULL, NULL}
};