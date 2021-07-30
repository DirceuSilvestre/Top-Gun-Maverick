void corte(SDL_Window *janela, SDL_Renderer *renderer);

void gravar_recorde(SDL_Window *janela, SDL_Renderer *renderer);

int continues = 0;

void condicao(int a)
{
	continues = a;
}

void gameover(SDL_Window *janela, SDL_Renderer *renderer)
{
	char acabou[] = "game over", sim[] = "sim (<---)", nao[] = "nao (--->)", denovo[] = "Quer continuar?";

	texto1 = setElement( //texto1 = game over
		"texto1",
		TTF_RenderText_Solid(fonte, acabou, color),
		createRect(0, 0, 9*48, 50),
		createRect(WIDTH/12, 70, 10 * WIDTH/12, 0.20 * HEIGHT)
	);

	texto2 = setElement( //texto1 = quer continuar
		"texto2",
		TTF_RenderText_Solid(fonte1, denovo, color),
		createRect(0, 0, 15*48, 50),
		createRect(WIDTH/12, 400, 10 * WIDTH/12, 0.10 * HEIGHT)
	);

	texto3 = setElement( //texto1 = sim
		"texto3",
		TTF_RenderText_Solid(fonte1, sim, color),
		createRect(0, 0, 10*48, 50),
		createRect(WIDTH/12, texto2.sizeImg.y + 130, 4 * WIDTH/12, 0.10 * HEIGHT)
	);

	texto4 = setElement( //texto1 = nao
		"texto4",
		TTF_RenderText_Solid(fonte1, nao, color),
		createRect(0, 0, 10*48, 50),
		createRect(7 * WIDTH/12, texto2.sizeImg.y + 130, 4 * WIDTH/12, 0.10 * HEIGHT)
	);

	char nome1[nove], nome2[nove], nome3[nove], nome4[nove], nome5[nove], nome6[nove];
	int numeros[9], ponto_jogador, novo_recorde = 0;

	FILE *recorde;
	FILE *grava;
	grava = fopen( "apoio.txt", "r");
	fscanf(grava, "%d", &ponto_jogador);
	fclose(grava);

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

	for(int i = 0; i < 6; i++)
	{
		if(ponto_jogador > numeros[i])
		{
			novo_recorde = 1;
			break;
		}
	}

	playSong(16);

	int tempo = 0;

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
						case SDL_SCANCODE_LEFT:
							if(continues > 0){
								playSound(0);
								continues--;
								corte(janela, renderer);
							}
							break;

						case SDL_SCANCODE_RIGHT:
							playSound(0);
							if(novo_recorde == 1){gravar_recorde(janela, renderer);}
							else {endgame(janela, renderer);};
							break;

						case SDL_SCANCODE_RETURN:
							playSound(0);
							if(novo_recorde == 1){gravar_recorde(janela, renderer);}
							else {endgame(janela, renderer);};
							endgame(janela, renderer);
							break;

					}
					break;
			}
		}

		tempo++;
		if(tempo>180){tempo=90;}


		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texto1.Texture, &texto1.cut, &texto1.sizeImg);
		if(continues > 0 && tempo >= 40)
		{			
			SDL_RenderCopy(renderer, texto2.Texture, &texto2.cut, &texto2.sizeImg);
			SDL_RenderCopy(renderer, texto3.Texture, &texto3.cut, &texto3.sizeImg);
			SDL_RenderCopy(renderer, texto4.Texture, &texto4.cut, &texto4.sizeImg);
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(fps);
	}
	return;
}