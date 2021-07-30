void condicao(int a);
void options(SDL_Window *window, SDL_Renderer *renderer){

    options_image = setElement(
        "options_image",
        IMG_Load("png/opcoes.png"),
        createRect(0,0,1600,1200),
        createRect(0,0,WIDTH,HEIGHT)
    );

    star_options[0] = setElement(
        "star_options[0]",
        IMG_Load("png/estrela.png"),
        createRect(0, 0, 102, 97),
        createRect(WIDTH/2 - 64 - 6*48 - 0.07*WIDTH, HEIGHT/14 * 2, 0.05*WIDTH, HEIGHT/16)
    );

    star_options[1] = setElement(
        "star_options[1]",
        IMG_Load("png/estrela.png"),
        createRect(0, 0, 102, 97),
        createRect(WIDTH/2 - 64 - 6*48 - 0.07*WIDTH, HEIGHT/14 * 4, 0.05*WIDTH, HEIGHT/16)
    );

    star_options[2] = setElement(
        "star_options[2]",
        IMG_Load("png/estrela.png"),
        createRect(0, 0, 102, 97),
        createRect(WIDTH/2 - 64 - 7*48 - 0.07*WIDTH, HEIGHT/14 * 6, 0.05*WIDTH, HEIGHT/16)
    );

    star_options[3] = setElement(
        "star_options[3]",
        IMG_Load("png/estrela.png"),
        createRect(0, 0, 102, 97),
        createRect(WIDTH/2 - 64 - 6*48 - 0.07*WIDTH, HEIGHT/14 * 8, 0.05*WIDTH, HEIGHT/16)
    );

    star_options[4] = setElement(
        "star_options[4]",
        IMG_Load("png/estrela.png"),
        createRect(0, 0, 102, 97),
        createRect(WIDTH/2 - 64 - 8*48 - 0.07*WIDTH, HEIGHT/14 * 10, 0.05*WIDTH, HEIGHT/16)
    );

    star_options[5] = setElement(
        "star_options[5]",
        IMG_Load("png/estrela.png"),
        createRect(0, 0, 102, 97),
        createRect(WIDTH/2 - 64 - 5*48 - 0.07*WIDTH, HEIGHT/14 * 12, 0.05*WIDTH, HEIGHT/16)
    );

    playSong(6);

    char volume_musicas[] = "volume";
    char radio[] = "radio";
    char musicas[] = "musicas", efeitos[] = "efeitos", volume_efeitos[] = "volume", continues[] = "continue";
    char musicas2[15] = "Com Voz", volume_musicas2[15] = "Maximo", efeitos2[15] = "Com Som", volume_efeitos2[15] = "Maximo", continues2[2] = "0", radio2[2] = "0";

    int a = 1, b = 2, c = 1, d = 2, e, f = 6, controle = 0;

    cut_musicas = createRect(0, 0, 6*48, HEIGHT/14);

    sizeImg_musicas = createRect(WIDTH/2 - 64 - 6*48, HEIGHT/14 * 2, 6*48, HEIGHT/14);

    cut_volume_musicas = createRect(0, 0, 6*48, HEIGHT/14);

    sizeImg_volume_musicas = createRect(WIDTH/2 - 64 - 6*48, HEIGHT/14 * 4, 6*48, HEIGHT/14);
    
    cut_efeitos = createRect(0, 0, 7*48, HEIGHT/14);
    
    sizeImg_efeitos = createRect(WIDTH/2 - 64 - 7*48, HEIGHT/14 * 6, 7*48, HEIGHT/14);
    
    cut_volume_efeitos = createRect(0, 0, 6*48, HEIGHT/14);
    
    sizeImg_volume_efeitos = createRect(WIDTH/2 - 64 - 6*48, HEIGHT/14 * 8, 6*48, HEIGHT/14);
    
    cut_continues = createRect(0, 0, 8*48, HEIGHT/14);
    
    sizeImg_continues = createRect(WIDTH/2 - 64 - 8*48, HEIGHT/14 * 10, 8*48, HEIGHT/14);
    
    cut_radio = createRect(0, 0, 5*48, HEIGHT/14);
    
    sizeImg_radio = createRect(WIDTH/2 - 64 - 5*48, HEIGHT/14 * 12, 5*48, HEIGHT/14);

    
    cut_musicas2 = createRect(0, 0, 10*48, HEIGHT/14);
    
    sizeImg_musicas2 = createRect(WIDTH/2 + 64, HEIGHT/14 * 2, 10*48, HEIGHT/14);
    
    cut_volume_musicas2 = createRect(0, 0, 5*48, HEIGHT/14);
    
    sizeImg_volume_musicas2 = createRect(WIDTH/2 + 64, HEIGHT/14 * 4, 5*48, HEIGHT/14);
    
    cut_efeitos2 = createRect(0, 0, 7*48, HEIGHT/14);
    
    sizeImg_efeitos2 = createRect(WIDTH/2 + 64, HEIGHT/14 * 6, 7*48, HEIGHT/14);
    
    cut_volume_efeitos2 = createRect(0, 0, 5*48, HEIGHT/14);
    
    sizeImg_volume_efeitos2 = createRect(WIDTH/2 + 64, HEIGHT/14 * 8, 5*48, HEIGHT/14);
    
    cut_continues2 = createRect(0, 0, 2*48, HEIGHT/14);
    
    sizeImg_continues2 = createRect(WIDTH/2 + 64 + 2*48, HEIGHT/14 * 10, 2*48, HEIGHT/14);
    
    cut_radio2 = createRect(0, 0, 2*48, HEIGHT/14);
    
    sizeImg_radio2 = createRect(WIDTH/2 + 64 + 2*48, HEIGHT/14 * 12, 2*48, HEIGHT/14);


	while( 1 )
	{
		SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    Mix_Quit();
                    TTF_Quit();
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return;
                    break;

                case SDL_KEYDOWN:
                	switch (event.key.keysym.scancode)
                	{
                		case SDL_SCANCODE_RETURN:
                    		playSound(0);
                    		gameTitle(window, renderer);
                    		return;
                    		break;

                        case SDL_SCANCODE_UP:
                            controle--;
                            if(controle < 0){controle = 5;};
                            break;

                        case SDL_SCANCODE_DOWN:
                            controle++;
                            if(controle > 5){controle = 0;};
                            break;

                        case SDL_SCANCODE_LEFT:
                            if(controle == 0){a--; if(a<0){a=2;}};
                            if(controle == 1){b--; if(b<0){b=2;}};
                            if(controle == 2){c--; if(c<0){c=1;}};
                            if(controle == 3){d--; if(d<0){d=2;}};
                            if(controle == 4){e--; if(e<0){e=5;}};
                            if(controle == 5){f--; if(f<1){f=14;}playSong(0);playRadio(f);};
                            break;

                        case SDL_SCANCODE_RIGHT:
                            if(controle == 0){a++; if(a>2){a=0;}};
                            if(controle == 1){b++; if(b>2){b=0;}};
                            if(controle == 2){c++; if(c>1){c=0;}};
                            if(controle == 3){d++; if(d>2){d=0;}};
                            if(controle == 4){e++; if(e>5){e=0;}};
                            if(controle == 5){f++; if(f>14){f=1;}playSong(0);playRadio(f);};
                            break;

                	}
                	break;

            }
        }
        
        switch(a)
        {
            case 0:
                strcpy(musicas2, "Sem Som");
                options_sound(0);
                break;

            case 1:
                strcpy(musicas2, "Com Voz");
                options_sound(1);
                break;

            case 2:
                strcpy(musicas2, "Instrumental");
                options_sound(2);
                break;
        }

        switch(b)
        {
            case 0:
                strcpy(volume_musicas2,"Baixo");
                volume_music(64);
                break;

            case 1:
                strcpy(volume_musicas2,"Medio");
                volume_music(96);
                break;

            case 2:
                strcpy(volume_musicas2,"Maximo");
                volume_music(128);
                break;
        }

        switch(c)
        {
            case 0:
                strcpy(efeitos2,"Sem Som");
                options_effects(0);
                break;

            case 1:
                strcpy(efeitos2,"Com Som");
                options_effects(1);
                break;
        }

        switch(d)
        {
            case 0:
                strcpy(volume_efeitos2,"Baixo");
                volume_effects(64);
                break;

            case 1:
                strcpy(volume_efeitos2,"Medio");
                volume_effects(96);
                break;

            case 2:
                strcpy(volume_efeitos2,"Maximo");
                volume_effects(128);
                break;
        }
        
        sprintf(continues2, "%d", e);
        condicao(e);
        sprintf(radio2, "%d", f);

        surface_musicas = TTF_RenderText_Solid(fonte, musicas, color);
        texture_musicas = SDL_CreateTextureFromSurface(renderer, surface_musicas);
        
        surface_volume_musicas = TTF_RenderText_Solid(fonte, volume_musicas, color);
        texture_volume_musicas = SDL_CreateTextureFromSurface(renderer, surface_volume_musicas);
        
        surface_efeitos = TTF_RenderText_Solid(fonte, efeitos, color);
        texture_efeitos = SDL_CreateTextureFromSurface(renderer, surface_efeitos);
        
        surface_volume_efeitos = TTF_RenderText_Solid(fonte, volume_efeitos, color);
        texture_volume_efeitos = SDL_CreateTextureFromSurface(renderer, surface_volume_efeitos);
        
        surface_continues = TTF_RenderText_Solid(fonte, continues, color);
        texture_continues = SDL_CreateTextureFromSurface(renderer, surface_continues);
        
        surface_radio = TTF_RenderText_Solid(fonte, radio, color);
        texture_radio = SDL_CreateTextureFromSurface(renderer, surface_radio);


        surface_musicas2 = TTF_RenderText_Solid(fonte1, musicas2, color);
        texture_musicas2 = SDL_CreateTextureFromSurface(renderer, surface_musicas2);
        
        surface_volume_musicas2 = TTF_RenderText_Solid(fonte1, volume_musicas2, color);
        texture_volume_musicas2 = SDL_CreateTextureFromSurface(renderer, surface_volume_musicas2);
        
        surface_efeitos2 = TTF_RenderText_Solid(fonte1, efeitos2, color);
        texture_efeitos2 = SDL_CreateTextureFromSurface(renderer, surface_efeitos2);
        
        surface_volume_efeitos2 = TTF_RenderText_Solid(fonte1, volume_efeitos2, color);
        texture_volume_efeitos2 = SDL_CreateTextureFromSurface(renderer, surface_volume_efeitos2);
        
        surface_continues2 = TTF_RenderText_Solid(fonte1, continues2, color);
        texture_continues2 = SDL_CreateTextureFromSurface(renderer, surface_continues2);
        
        surface_radio2 = TTF_RenderText_Solid(fonte1, radio2, color);
        texture_radio2 = SDL_CreateTextureFromSurface(renderer, surface_radio2);


        SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, options_image.Texture, &options_image.cut, &options_image.sizeImg);
        SDL_RenderCopy(renderer, star_options[controle].Texture, &star_options[controle].cut, &star_options[controle].sizeImg);
        SDL_RenderCopy(renderer, texture_musicas, &cut_musicas, &sizeImg_musicas);
        SDL_RenderCopy(renderer, texture_volume_musicas, &cut_volume_musicas, &sizeImg_volume_musicas);
        SDL_RenderCopy(renderer, texture_efeitos, &cut_efeitos, &sizeImg_efeitos);
        SDL_RenderCopy(renderer, texture_volume_efeitos, &cut_volume_efeitos, &sizeImg_volume_efeitos);
        SDL_RenderCopy(renderer, texture_continues, &cut_continues, &sizeImg_continues);
        SDL_RenderCopy(renderer, texture_radio, &cut_radio, &sizeImg_radio);
        SDL_RenderCopy(renderer, texture_musicas2, &cut_musicas2, &sizeImg_musicas2);
        SDL_RenderCopy(renderer, texture_volume_musicas2, &cut_volume_musicas2, &sizeImg_volume_musicas2);
        SDL_RenderCopy(renderer, texture_efeitos2, &cut_efeitos2, &sizeImg_efeitos2);
        SDL_RenderCopy(renderer, texture_volume_efeitos2, &cut_volume_efeitos2, &sizeImg_volume_efeitos2);
        SDL_RenderCopy(renderer, texture_continues2, &cut_continues2, &sizeImg_continues2);
        SDL_RenderCopy(renderer, texture_radio2, &cut_radio2, &sizeImg_radio2);        
		SDL_RenderPresent(renderer);
		SDL_Delay(fps);
	}
	return;
}