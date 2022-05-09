//INCLUDE LIBRAIRIES
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//INCLUDE CRYPTO PART
#include "../../../Crypto_tools/Cipher_256/SHA256.c"

void Call_SHA256(char font[], char Box[])
{
    sfRenderWindow *pop;
    sfVideoMode video_mode = {800, 400, 32};
    sfEvent event;
    sfTexture *empty = sfTexture_createFromFile(Box, NULL);

    char * param1 = malloc(sizeof(char)*100);
    sfText *par1;
    sfVector2i mouse_pos;
    int boxnb = 0;

    sfSprite *img = sfSprite_create();
    sfFont * f;
    f = sfFont_createFromFile(font);

    pop = sfRenderWindow_create(video_mode, "SHA256 parameters",
            sfClose | sfResize, NULL);

    sfSprite_setTexture(img, empty, sfFalse);

    memset(param1, 0, sizeof(char)*100);

    while(sfRenderWindow_isOpen(pop))
    {
        sfRenderWindow_display(pop);
        sfRenderWindow_drawSprite(pop, img, NULL);

        par1 = SetText(param1, 235, 140, f, sfBlack, 25);
        sfRenderWindow_drawText(pop, par1, NULL);

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

                if(mouse_pos.x > 685 && mouse_pos.y > 125
                         && mouse_pos.x < 735 && mouse_pos.y < 180)
                    param1[strlen(param1)-1] = '\0';

                if(mouse_pos.x > 587  && mouse_pos.y > 328
                       && mouse_pos.x < 735 && mouse_pos.y < 377)
                    Gr256(param1);
        }
            if(event.type == sfEvtTextEntered)
            {
                if(boxnb == 1)
                    concat((char) event.text.unicode, param1);
            }
        }
    }
}
