#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <debugFunc.h>

int main() {
    while (1)
    {
        char buffer[2];
        memset(buffer, 0, 2);
        printf("1) Enter Passphrase\n2) Debug\n");
        printf("Your choice: ");

        int choice = 0;
        fgets(buffer, 2, stdin);
        choice = buffer[0] - '0';

        switch (choice)
        {
            case 1:
            {
                printf("Enter passphrase: ");
                fgets(buffer, 2, stdin);

                printf("Something went wrong. Use the debug function. MemAddr: %p\n", debugFunc);
            }
            break;
            case 2:
            {
                while (1)
                {
                    char inputBuffer[12];

                    printf("Calling debug function at %p, are you sure you want to do this (Y/N)? ", getDbgFuncAddr());
                    gets(inputBuffer);

                    if (inputBuffer[0] == 'y' || inputBuffer[0] == 'Y')
                    {
                        debugFunc();
                    }
                    else if (inputBuffer[0] == 'n' || inputBuffer[0] == 'N')
                    {
                        break;
                    }
                }
            }
            break;
        }
    }
}
