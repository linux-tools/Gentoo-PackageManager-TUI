#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("\n\
    Please choose your language:\n\
    1.Engliah\n\
    2.Chinese\n\
    Please choose:");
    int choose_Language;
    scanf("%d",&choose_Language);
    while (1)
    {
        if (choose_Language == 1)
        {
            system("cd /usr/bin && sudo ln -sf gentoo-packagemanager-en gentoo-packagemanager");
            break;
        }
        else if (choose_Language == 2)
        {
            system("cd /usr/bin && sudo ln -sf gentoo-packagemanager-zh gentoo-packagemanager");
            break;
        }
        else
        {
            system("clear");
            printf("\n\
            Please choose your language:\n\
            1.Engliah\n\
            2.Chinese\n\
            Please choose:");
            scanf("%d",&choose_Language);
        }
    }
    return 0;   
}