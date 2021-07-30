void gameTitle(SDL_Window *window, SDL_Renderer *renderer);

void credits_function(SDL_Window *window, SDL_Renderer *renderer)
{

    credits = setElement(
        "credits",
        IMG_Load("png/creditos.png"),
        createRect(0,0,1440,900),
        createRect(0,0,WIDTH,HEIGHT)
    );

    playSong(14);

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
                	}
                	break;

            }
        }
		
        SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, credits.Texture, &credits.cut, &credits.sizeImg);
		SDL_RenderPresent(renderer);
		SDL_Delay(fps);
	}
	return;
}