#define nove 9

SDL_Surface *recorde;

SDL_Texture *texture_recorde;

SDL_Rect corte_img_recorde;
SDL_Rect tamanho_img_recorde;

TTF_Font *nome;
TTF_Font *numero;

//150, 150, 150

void foto_recorde(SDL_Window *janela, SDL_Renderer *renderer)
{
	char pontuacao1[nove], pontuacao2[nove], pontuacao3[nove], pontuacao4[nove], pontuacao5[nove], pontuacao6[nove];
	char nome1[nove], nome2[nove], nome3[nove], nome4[nove], nome5[nove], nome6[nove];
	int numeros[9], contador = 0;

	recorde = IMG_Load("png/ranking.png");

	texture_recorde = SDL_CreateTextureFromSurface(renderer, recorde);

	TTF_Init();

    nome = TTF_OpenFont("TOP-GUN.ttf", 32);
    numero = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSerif-Bold.ttf", 32);

	corte_img_recorde.x = 0;
	corte_img_recorde.y = 0;
	corte_img_recorde.w = 1689;
	corte_img_recorde.h = 1083;

	tamanho_img_recorde.x = 0;
	tamanho_img_recorde.y = 0;
	tamanho_img_recorde.w = WIDTH;
	tamanho_img_recorde.h = HEIGHT;

	FILE *recorde;

	recorde = fopen( "recordes.txt", "r");

	fscanf(recorde, "%s", nome1);
	fscanf(recorde, "%d", &numeros[0]);
	fscanf(recorde, "%s", nome2);
	fscanf(recorde, "%d", &numeros[1]);
	fscanf(recorde, "%s", nome3);
	fscanf(recorde, "%d", &numeros[2]);
	fscanf(recorde, "%s", nome4);
	fscanf(recorde, "%d", &numeros[3]);
	fscanf(recorde, "%s", nome5);
	fscanf(recorde, "%d", &numeros[4]);
	fscanf(recorde, "%s", nome6);
	fscanf(recorde, "%d", &numeros[5]);

	fclose(recorde);

	primeiro = setElement( 
		"primeiro",
		TTF_RenderText_Solid(nome, nome1, color),
		createRect(0, 0, 9*48, 48),
		createRect(1.5 * WIDTH/19,6 * HEIGHT/13, 4 * WIDTH/19, 0.09 * HEIGHT)
	);

	sprintf(pontuacao1, "%d", numeros[0]);

	primeiro_ponto = setElement( 
		"primeiro_ponto",
		TTF_RenderText_Solid(numero, pontuacao1, color),
		createRect(0, 0, 9*48, 48),
		createRect(1.5 * WIDTH/19, 6.90 * HEIGHT/13, 4 * WIDTH/19, 0.09 * HEIGHT)
	);

	segundo = setElement( 
		"segundo",
		TTF_RenderText_Solid(nome, nome2, color),
		createRect(0, 0, 9*48, 48),
		createRect(7.5 * WIDTH/19,6 * HEIGHT/13, 4 * WIDTH/19, 0.09 * HEIGHT)
	);

	sprintf(pontuacao2, "%d", numeros[1]);

	segundo_ponto = setElement( 
		"segundo_ponto",
		TTF_RenderText_Solid(numero, pontuacao2, color),
		createRect(0, 0, 9*48, 48),
		createRect(7.5 * WIDTH/19, 6.90 * HEIGHT/13, 4 * WIDTH/19, 0.09 * HEIGHT)
	);

	terceiro = setElement( 
		"terceiro",
		TTF_RenderText_Solid(nome, nome3, color),
		createRect(0, 0, 9*48, 48),
		createRect(13.5 * WIDTH/19,6 * HEIGHT/13, 4 * WIDTH/19, 0.09 * HEIGHT)
	);

	sprintf(pontuacao3, "%d", numeros[2]);

	terceiro_ponto = setElement( 
		"terceiro_ponto",
		TTF_RenderText_Solid(numero, pontuacao3, color),
		createRect(0, 0, 9*48, 48),
		createRect(13.5 * WIDTH/19, 6.90 * HEIGHT/13, 4 * WIDTH/19, 0.09 * HEIGHT)
	);

	quarto = setElement( 
		"quarto",
		TTF_RenderText_Solid(nome, nome4, color),
		createRect(0, 0, 9*48, 48),
		createRect(1.5 * WIDTH/19, 10 * HEIGHT/13, 4 * WIDTH/19, 0.09 * HEIGHT)
	);

	sprintf(pontuacao4, "%d", numeros[3]);

	quarto_ponto = setElement( 
		"quarto_ponto",
		TTF_RenderText_Solid(numero, pontuacao4, color),
		createRect(0, 0, 9*48, 48),
		createRect(1.5 * WIDTH/19, 10.90 * HEIGHT/13, 4 * WIDTH/19, 0.09 * HEIGHT)
	);

	quinto = setElement( 
		"quinto",
		TTF_RenderText_Solid(nome, nome5, color),
		createRect(0, 0, 9*48, 48),
		createRect(7.5 * WIDTH/19, 10 * HEIGHT/13, 4 * WIDTH/19, 0.09 * HEIGHT)
	);

	sprintf(pontuacao5, "%d", numeros[4]);

	quinto_ponto = setElement( 
		"quinto_ponto",
		TTF_RenderText_Solid(numero, pontuacao5, color),
		createRect(0, 0, 9*48, 48),
		createRect(7.5 * WIDTH/19, 10.90 * HEIGHT/13, 4 * WIDTH/19, 0.09 * HEIGHT)
	);

	sexto = setElement( 
		"sexto",
		TTF_RenderText_Solid(nome, nome6, color),
		createRect(0, 0, 9*48, 48),
		createRect(13.5 * WIDTH/19, 10 * HEIGHT/13, 4 * WIDTH/19, 0.09 * HEIGHT)
	);

	sprintf(pontuacao6, "%d", numeros[5]);

	sexto_ponto = setElement( 
		"sexto_ponto",
		TTF_RenderText_Solid(numero, pontuacao6, color),
		createRect(0, 0, 9*48, 48),
		createRect(13.5 * WIDTH/19, 10.90 * HEIGHT/13, 4 * WIDTH/19, 0.09 * HEIGHT)
	);

	playSong(8);

	efeitos_jogo(5);
	
	while( 1 )
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
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
					switch(event.key.keysym.scancode)
					{
						case SDL_SCANCODE_RETURN:
							playSound(0);
							Mix_FreeChunk(sound);
							endgame(janela, renderer);
							return;
							break;
					}
					break;
			}
		}
		contador++;
		if (contador == 20){efeitos_jogo(9);}
		if (contador == 40){efeitos_jogo(6);}
		if(contador>=46){contador=46;}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture_recorde, &corte_img_recorde, &tamanho_img_recorde);
		SDL_RenderCopy(renderer, primeiro.Texture, &primeiro.cut, &primeiro.sizeImg);
		SDL_RenderCopy(renderer, primeiro_ponto.Texture, &primeiro_ponto.cut, &primeiro_ponto.sizeImg);
		SDL_RenderCopy(renderer, segundo.Texture, &segundo.cut, &segundo.sizeImg);
		SDL_RenderCopy(renderer, segundo_ponto.Texture, &segundo_ponto.cut, &segundo_ponto.sizeImg);
		SDL_RenderCopy(renderer, terceiro.Texture, &terceiro.cut, &terceiro.sizeImg);
		SDL_RenderCopy(renderer, terceiro_ponto.Texture, &terceiro_ponto.cut, &terceiro_ponto.sizeImg);
		SDL_RenderCopy(renderer, quarto.Texture, &quarto.cut, &quarto.sizeImg);
		SDL_RenderCopy(renderer, quarto_ponto.Texture, &quarto_ponto.cut, &quarto_ponto.sizeImg);
		SDL_RenderCopy(renderer, quinto.Texture, &quinto.cut, &quinto.sizeImg);
		SDL_RenderCopy(renderer, quinto_ponto.Texture, &quinto_ponto.cut, &quinto_ponto.sizeImg);
		SDL_RenderCopy(renderer, sexto.Texture, &sexto.cut, &sexto.sizeImg);
		SDL_RenderCopy(renderer, sexto_ponto.Texture, &sexto_ponto.cut, &sexto_ponto.sizeImg);
		SDL_RenderPresent(renderer);
		SDL_Delay(100);
	}
	return;
}