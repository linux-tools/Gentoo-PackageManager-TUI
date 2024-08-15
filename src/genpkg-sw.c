#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("\n\
    Please choose your language:\n\
    1.English\n\
    2.Chinese\n\
    Please choose:");
    int choose_Language;
    scanf("%d",&choose_Language);
    while (1)
    {
        if (choose_Language == 1)
        {
            system("sudo ln -sf /usr/bin/genpkg-en /usr/bin/genpkg");
            break;
        }
        else if (choose_Language == 2)
        {
            system("sudo ln -sf /usr/bin/genpkg-zh /usr/bin/genpkg");
            break;
        }
        else
        {
            system("clear");
            printf("\n\
            Please choose your language:\n\
            1.English\n\
            2.Chinese\n\
            Please choose:");
            scanf("%d",&choose_Language);
        }
    }
    return 0;   
}