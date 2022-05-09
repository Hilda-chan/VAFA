//INCLUDE LIBRAIRIES
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../../../Math_Tools/curve/graph.c"

void Call_Plot(char font[], char Box[])
{
    sfRenderWindow *pop;
    sfVideoMode video_mode = {800, 400, 32};
    sfEvent event;
    sfTexture *empty = sfTexture_createFromFile(Box, NULL);

    char * param1 = malloc(sizeof(char)*100);
    char * param2 = malloc(sizeof(char)*100);
    char * param3 = malloc(sizeof(char)*100);
    sfText *par1;
    sfText *par2;
    sfText *par3;
    sfVector2i mouse_pos;
    int boxnb = 0;

    sfSprite *img = sfSprite_create();
    sfFont * f;
    f = sfFont_createFromFile(font);

    pop = sfRenderWindow_create(video_mode, "Plotting parameters",
            sfClose | sfResize, NULL);

    sfSprite_setTexture(img, empty, sfFalse);

    memset(param1, 0, sizeof(char)*100);
    memset(param2, 0, sizeof(char)*100);
    memset(param3, 0, sizeof(char)*100);

    while(sfRenderWindow_isOpen(pop))
    {
        sfRenderWindow_display(pop);
        sfRenderWindow_drawSprite(pop, img, NULL);

        par1 = SetText(param1, 230, 110, f, sfBlack, 25);
        sfRenderWindow_drawText(pop, par1, NULL);

        par2 = SetText(param2, 230, 190, f, sfBlack, 25);
        sfRenderWindow_drawText(pop, par2, NULL);
        
        par3 = SetText(param3, 230, 270, f, sfBlack, 25);
        sfRenderWindow_drawText(pop, par3, NULL);

        while(sfRenderWindow_pollEvent(pop, &event))
        {
            if(event.type == sfEvtClosed)
            {
                sfRenderWindow_close(pop);
            }
            if(event.type == sfEvtMouseButtonPressed)
            {
                mouse_pos = sfMouse_getPositionRenderWindow(pop);

                if(mouse_pos.x > 220 && mouse_pos.y > 90
                         && mouse_pos.x < 685 && mouse_pos.y < 141)
                    boxnb = 1;

                if(mouse_pos.x > 220  && mouse_pos.y > 172 
                         && mouse_pos.x < 690 && mouse_pos.y < 223)
                    boxnb = 2;
                    
                if(mouse_pos.x > 220  && mouse_pos.y > 250 
                         && mouse_pos.x < 687 && mouse_pos.y < 302)
                    boxnb = 3;

                if(mouse_pos.x > 687 && mouse_pos.y > 93
                         && mouse_pos.x < 735 && mouse_pos.y < 143)
                    param1[strlen(param1)-1] = '\0';

                if(mouse_pos.x > 691  && mouse_pos.y > 176 
                    && mouse_pos.x < 736 && mouse_pos.y < 224)
                    param2[strlen(param2)-1] = '\0';
                    
                if(mouse_pos.x > 690  && mouse_pos.y > 254
                    && mouse_pos.x < 735 && mouse_pos.y < 302)
                    param3[strlen(param3)-1] = '\0';

                if(mouse_pos.x > 587  && mouse_pos.y > 328
                       && mouse_pos.x < 735 && mouse_pos.y < 377)
                    GrPlot(param1, param2, param3);
        }
            if(event.type == sfEvtTextEntered)
            {
                if(boxnb == 1)
                    concat((char) event.text.unicode, param1);
                if(boxnb == 2)
                    concat((char) event.text.unicode, param2);
                if(boxnb == 3)
                    concat((char) event.text.unicode, param3);
            }
        }
    }
}
