void opening(SDL_Window *window, SDL_Renderer *renderer){

	int counter = 0;

    openingElement = setElement(
        "opening",
        IMG_Load("png/abertura.png"),
        createRect(0,0,1920,1080),
        createRect(0,0,WIDTH,HEIGHT)
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
        
        counter++;
        if (counter > 171)
        {
        	callGameTitle(window, renderer);
            return;
        	break;
        }
		
        SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, openingElement.Texture, &openingElement.cut, &openingElement.sizeImg);
		SDL_RenderPresent(renderer);
		SDL_Delay(fps);
	}
	return;
}