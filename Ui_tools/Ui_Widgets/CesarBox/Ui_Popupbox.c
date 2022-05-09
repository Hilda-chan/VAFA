//INCLUDE LIBRAIRIES
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//INCLUDE CRYPTO PART
#include "../../../Crypto_tools/Cipher_C/caesar.c"

sfText * SetText(char str[], int x, int y, sfFont *f, sfColor col, int size)
{


    sfVector2f coord = {x,y};
    sfText *string = sfText_create();
    sfText_setString(string, str);
    sfText_setPosition(string, coord);
    sfText_setCharacterSize(string, size);
    sfText_setFont(string, f);
    sfText_setColor(string, col);
    return string;
}

char* concat(char c, char str[])
{
    char *res = malloc(2 * sizeof(char));
    res[0] = c;
    res[1] = '\0';
    strcat(str, res);
    return str;
}

char* c_to_s(char c)
{
    char *res = malloc(3 * sizeof(char));
    res[0] = c;
    res[1] = ' ';
    res[2] = '\0';
    return res;
}


void Call_Cesear(char font[], char Box[])
{
    sfRenderWindow *pop;
    sfVideoMode video_mode = {800, 400, 32};
    sfEvent event;
    sfTexture *empty = sfTexture_createFromFile(Box, NULL);

    char * param1 = malloc(sizeof(char)*100);
    char * param2 = malloc(sizeof(char)*100);
    sfText *par1;
    sfText *par2;
    sfVector2i mouse_pos;
    int boxnb = 1;

    sfSprite *img = sfSprite_create();
    sfFont * f;
    f = sfFont_createFromFile(font);

    pop = sfRenderWindow_create(video_mode, "Cesear parameters",
            sfClose | sfResize, NULL);

    sfSprite_setTexture(img, empty, sfFalse);

    memset(param1, 0, sizeof(char)*100);
    memset(param2, 0, sizeof(char)*100);

    while(sfRenderWindow_isOpen(pop))
    {
        sfRenderWindow_display(pop);
        sfRenderWindow_drawSprite(pop, img, NULL);

        par1 = SetText(param1, 235, 140, f, sfBlack, 25);
        sfRenderWindow_drawText(pop, par1, NULL);

        par2 = SetText(param2, 235, 260, f, sfBlack, 25);
        sfRenderWindow_drawText(pop, par2, NULL);

        while(sfRenderWindow_pollEvent(pop, &event))
        {
            if(event.type == sfEvtClosed)
            {
                sfRenderWindow_close(pop);
            }
            if(event.type == sfEvtMouseButtonPressed)
            {
                mouse_pos = sfMouse_getPositionRenderWindow(pop);

                if(mouse_pos.x > 220 && mouse_pos.y > 125
                         && mouse_pos.x < 685 && mouse_pos.y < 180)
                    boxnb = 1;

                if(mouse_pos.x > 220  && mouse_pos.y > 240 
                    && mouse_pos.x < 690 && mouse_pos.y < 290)
                    boxnb = 2;

                if(mouse_pos.x > 685 && mouse_pos.y > 125
                         && mouse_pos.x < 735 && mouse_pos.y < 180)
                    param1[strlen(param1)-1] = '\0';

                if(mouse_pos.x > 690  && mouse_pos.y > 240 
                    && mouse_pos.x < 735 && mouse_pos.y < 290)
                    param2[strlen(param2)-1] = '\0';


                if(mouse_pos.x > 587  && mouse_pos.y > 328
                       && mouse_pos.x < 735 && mouse_pos.y < 377)
                    GrCaesar(param2, param1);
        }
            if(event.type == sfEvtTextEntered)
            {
                if(boxnb == 1)
                    concat( (char) event.text.unicode, param1);
                if(boxnb == 2)
                    concat( (char) event.text.unicode, param2);
            }
        }
    }
}
