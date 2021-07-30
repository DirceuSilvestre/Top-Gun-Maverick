void simulador(SDL_Window *janela, SDL_Renderer *renderer);
void endgame(SDL_Window *janela, SDL_Renderer *renderer);
void menu(SDL_Window *janela, SDL_Renderer *renderer)
{
    title.sizeImg = createRect( 0.15 * WIDTH, 8, 0.70 * WIDTH, 0.30 * HEIGHT);

    star = setElement(
        "star",
        IMG_Load("png/estrela.png"),
        createRect(0, 0, 102, 97),
        createRect((WIDTH/2 - (0.3*WIDTH)/2) - 0.07*WIDTH, 0.355*HEIGHT, 0.05*WIDTH, 0.08*HEIGHT)
    );

    history_name[0] = setElement(
        "history_name[0]",
        IMG_Load("png/historia-apagado.png"),
        createRect(0, 0, 386, 93),
        createRect((WIDTH/2 - (0.3*WIDTH)/2), 0.35*HEIGHT, 0.3*WIDTH,0.09*HEIGHT)
    );
    
    history_name[1] = setElement(
        "history_name[1]",
        IMG_Load("png/historia-aceso.png"),
        createRect(0, 0, 386, 93),
        createRect((WIDTH/2 - (0.3*WIDTH)/2), 0.35*HEIGHT, 0.3*WIDTH,0.09*HEIGHT)
    );

    fly_name[0] = setElement(
        "fly_name[0]",
        IMG_Load("png/pilotar-apagado.png"),
        createRect(0, 0, 359, 93),
        createRect((WIDTH/2 - (0.3*WIDTH)/2), 0.45*HEIGHT, 0.27*WIDTH,0.09*HEIGHT)
    );

    fly_name[1] = setElement(
        "fly_name[1]",
        IMG_Load("png/pilotar-aceso.png"),
        createRect(0, 0, 359, 93),
        createRect((WIDTH/2 - (0.3*WIDTH)/2), 0.45*HEIGHT, 0.27*WIDTH,0.09*HEIGHT)
    );

    topguns_name[0] = setElement(
        "topguns_name[0]",
        IMG_Load("png/topguns-apagado.png"),
        createRect(0, 0, 415, 93),
        createRect((WIDTH/2 - (0.3*WIDTH)/2), 0.55*HEIGHT, 0.27*WIDTH,0.09*HEIGHT)
    );

    topguns_name[1] = setElement(
        "topguns_name[1]",
        IMG_Load("png/topguns-aceso.png"),
        createRect(0, 0, 415, 93),
        createRect((WIDTH/2 - (0.3*WIDTH)/2), 0.55*HEIGHT, 0.27*WIDTH,0.09*HEIGHT)
    );

    simulator_name[0] = setElement(
        "simulator_name[0]",
        IMG_Load("png/simulador-apagado.png"),
        createRect(0, 0, 499, 93),
        createRect((WIDTH/2 - (0.3*WIDTH)/2), 0.65*HEIGHT, 0.35*WIDTH,0.09*HEIGHT)
    );
 
    simulator_name[1] = setElement(
        "simulator_name[1]",
        IMG_Load("png/simulador-aceso.png"),
        createRect(0, 0, 499, 93),
        createRect((WIDTH/2 - (0.3*WIDTH)/2), 0.65*HEIGHT, 0.35*WIDTH,0.09*HEIGHT)
    );

    options_name[0] = setElement(
        "options_name[0]",
        IMG_Load("png/opcoes-apagado.png"),
        createRect(0, 0, 335, 93),
        createRect((WIDTH/2 - (0.3*WIDTH)/2), 0.75*HEIGHT, 0.24*WIDTH,0.09*HEIGHT)
    );  

    options_name[1] = setElement(
        "options_name[1]",
        IMG_Load("png/opcoes-aceso.png"),
        createRect(0, 0, 335, 93),
        createRect((WIDTH/2 - (0.3*WIDTH)/2), 0.75*HEIGHT, 0.24*WIDTH,0.09*HEIGHT)
    );     

    credits_name[0] = setElement(
        "credits_name[0]",
        IMG_Load("png/creditos-apagado.png"),
        createRect(0, 0, 418, 93),
        createRect((WIDTH/2 - (0.3*WIDTH)/2), 0.85*HEIGHT, 0.3*WIDTH,0.09*HEIGHT)
    );

    credits_name[1] = setElement(
        "credits_name[1]",
        IMG_Load("png/creditos-aceso.png"),
        createRect(0, 0, 418, 93),
        createRect((WIDTH/2 - (0.3*WIDTH)/2), 0.85*HEIGHT, 0.3*WIDTH,0.09*HEIGHT)
    );

	int seletor = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;

	while( 1 )
	{
		SDL_Event event;
        while (SDL_PollEvent(&event))
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
                		case SDL_SCANCODE_DOWN:               			
                			playSound(3);
                 	  		seletor++;
                  	  		if(seletor > 5) seletor = 0; 
                  	  		star.sizeImg.y += 0.10*HEIGHT;
                  	  		if(star.sizeImg.y > 0.94*HEIGHT) star.sizeImg.y = 0.355*HEIGHT;
                  	  		break;
                		case SDL_SCANCODE_UP:
                			playSound(3);               
                  	  		seletor--;
                  	  		if(seletor < 0) seletor = 5;
                  	  		star.sizeImg.y -= 0.10*HEIGHT;
                  	  		if(star.sizeImg.y < 0.350*HEIGHT) star.sizeImg.y = 0.85*HEIGHT;
                  	  		break;
                		case SDL_SCANCODE_RETURN:
                  	  		switch(seletor)
                    		{
                        		case 0://historia do jogo
                            		history1(janela, renderer);
                        			return;
                            		break;
                        		case 1://iniciar o jogo
                                    random_sound();
                                    random_song();
                            		take_off(janela, renderer);
                            		return;
                            		break;
                        		case 2://instruções
                            		topgun(janela, renderer);
                        			return;
                            		break;
                        		case 3://creditos
                                    random_song();
                            		simulador(janela, renderer);
                        			return;
                            		break;
                            	case 4://sair
                            		options(janela, renderer);
                					return;
                					break;
                				case 5:
                					credits_function(janela, renderer);
                					return;
                					break;
                    		}
                    		break;
                	}
                	break;   
            }
    	}

    	switch(seletor)
    	{
    		case 0:
                a = 1;
				b = 0;
                c = 0;
                d = 0;
                e = 0;
                f = 0;
    			break;

    		case 1:
                a = 0;
                b = 1;
                c = 0;
				d = 0;
                e = 0;
                f = 0;
    			break;

    		case 2:
                a = 0;
				b = 0;
                c = 1;
                d = 0;
                e = 0;
                f = 0;
    			break;

    		case 3:
                a = 0;
				b = 0;
                c = 0;
                d = 1;
                e = 0;
                f = 0;
    			break;

    		case 4:
                a = 0;
				b = 0;
                c = 0;
                d = 0;
                e = 1;
                f = 0;
    			break;

    		case 5:
                a = 0;
				b = 0;
                c = 0;
                d = 0;
                e = 0;
                f = 1;
    			break;

    	}

    	SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, title.Texture, &title.cut, &title.sizeImg);
		SDL_RenderCopy(renderer, star.Texture, &star.cut, &star.sizeImg);
		SDL_RenderCopy(renderer, history_name[a].Texture, &history_name[a].cut, &history_name[a].sizeImg);
		SDL_RenderCopy(renderer, fly_name[b].Texture, &fly_name[b].cut, &fly_name[b].sizeImg);
		SDL_RenderCopy(renderer, topguns_name[c].Texture, &topguns_name[c].cut, &topguns_name[c].sizeImg);
		SDL_RenderCopy(renderer, simulator_name[d].Texture, &simulator_name[d].cut, &simulator_name[d].sizeImg);
		SDL_RenderCopy(renderer, options_name[e].Texture, &options_name[e].cut, &options_name[e].sizeImg);
		SDL_RenderCopy(renderer, credits_name[f].Texture, &credits_name[f].cut, &credits_name[f].sizeImg);
		SDL_RenderPresent(renderer);

	}
    return;
}

void callMenu(SDL_Window *janela, SDL_Renderer *renderer)
{
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
                            menu(janela, renderer);
                            return;
                            break;
                    }
                    break;
            }
        }
        
        //tamanho_img_enter.w = 0;
    	//tamanho_img_enter.h = 0;

    	title.sizeImg.x += 7;
    	title.sizeImg.y -= 20;
    	title.sizeImg.w -= 14;
		title.sizeImg.h -= 4.31;

		if(title.sizeImg.y <= 0.02*HEIGHT)
		{
			menu(janela, renderer);
			return;
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, title.Texture, &title.cut, &title.sizeImg);
		SDL_RenderPresent(renderer);

		SDL_Delay(100);
    }
    return;
}

void gameTitle(SDL_Window *janela, SDL_Renderer *renderer)
{
	int contador = 0;

	press_enter = setElement(
		"press_enter",
        IMG_Load("png/pressione_enter.png"),
		createRect(0,0,789,96),
		createRect((WIDTH/2 - 500/2),0.8*HEIGHT,0,0)
		);
	//press_enter.Surface = IMG_Load("png/pressione_enter.png");
    //press_enter.Texture = SDL_CreateTextureFromSurface(renderer, press_enter.Surface);
	
	title = setElement(
		"title",
        IMG_Load("png/titulo.png"),
		createRect(0,0,1245,360),
		createRect((WIDTH/2 - (0.81*WIDTH)/2),0.26*HEIGHT,0.81*WIDTH,0.35*HEIGHT)
	);
	//title.Surface = IMG_Load("png/titulo.png");
	//title.Texture = SDL_CreateTextureFromSurface(renderer, title.Surface);

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
                    		callMenu(janela, renderer);
                    		return;
                    		break;
                	}
                	break;
            }
        }
        contador += 1;
        title.sizeImg = createRect((WIDTH/2 - (0.81*WIDTH)/2),0.26*HEIGHT,0.81*WIDTH,0.35*HEIGHT);

        switch(contador)
        {
        	case 14:
        		playSound(2);			
        		break;

        	case 24:
                playSong(1);
        		break;

      		case 32:
      		    press_enter.sizeImg.w = 500;
        		press_enter.sizeImg.h = 70;
        		break;

        	case 42:
    	    	press_enter.sizeImg.w = 0;
        		press_enter.sizeImg.h = 0;
    	    	break;

    	    case 52:
    	    	contador = 31;
    	    	break;
        }
		
        SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, title.Texture, &title.cut, &title.sizeImg);
		SDL_RenderCopy(renderer, press_enter.Texture, &press_enter.cut, &press_enter.sizeImg);
		SDL_RenderPresent(renderer);
		SDL_Delay(100);
	}
	return;
}

void callGameTitle(SDL_Window *janela, SDL_Renderer *renderer)
{
    title = setElement(
        "title",
        IMG_Load("png/titulo.png"),
        createRect(0,0,1245,360),
        createRect(WIDTH/2,HEIGHT/2,0,0)
    );

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
            }
        }
 
        title.sizeImg.x -= ((0.81*WIDTH)/2)/10;
        title.sizeImg.y -= (0.25*HEIGHT)/10;
        title.sizeImg.w += (0.81*WIDTH)/10;
        title.sizeImg.h += (0.35*HEIGHT)/10;

        if(title.sizeImg.x <= (WIDTH/2 - (0.81*WIDTH)/2))
        {
        	gameTitle(janela, renderer);
        	return;
        }

        SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, title.Texture, &title.cut, &title.sizeImg);
		SDL_RenderPresent(renderer);
		SDL_Delay(100);
	}

	return;
}
