void foto_recorde(SDL_Window *janela, SDL_Renderer *renderer);
void gravar_recorde(SDL_Window *janela, SDL_Renderer *renderer)
{
	char pontuacao1[nove], pontuacao2[nove], pontuacao3[nove], pontuacao4[nove], pontuacao5[nove], pontuacao6[nove];
	char nome1[nove], nome2[nove], nome3[nove], nome4[nove], nome5[nove], nome6[nove];
	int numeros[9];
	int ponto_jogador, posicao;
	char vetor[9] = {'e','s','c','r','e','v', 'a'};
	char texto5[] = "parabens";
	char texto6[] = "temos um novo recorde";
    int numeros1[5] = {666};
    int i = 0, contador = 0;

    corte_img_simulador.x = 0;
    corte_img_simulador.y = 0;
    corte_img_simulador.w = 8*48;
    corte_img_simulador.h = 50;

    tamanho_img_simulador.x = WIDTH/2 - 4*48;
    tamanho_img_simulador.y = 0.7*HEIGHT;
    tamanho_img_simulador.w = 8*48;
    tamanho_img_simulador.h = 50;

    options_image = setElement(
        "options_image",
        IMG_Load("png/opcoes.png"),
        createRect(0,0,1600,1200),
        createRect(0,0,WIDTH,HEIGHT)
    );

    parabens = setElement( //texto1 = game over
		"parabens",
		TTF_RenderText_Solid(fonte, texto5, color_red),
		createRect(0, 0, 8*48, 48),
		createRect(3 * WIDTH/12, HEIGHT/16.4, 6 * WIDTH/12, 0.20 * HEIGHT)
	);

	novoRecorde = setElement( //texto1 = game over
		"novoRecorde",
		TTF_RenderText_Solid(fonte, texto6, color_blue),
		createRect(0, 0, 21*48, 48),
		createRect(WIDTH/12, 0.4 * HEIGHT, 10 * WIDTH/12, 0.15 * HEIGHT)
	);

    //text_surface=TTF_RenderText_Solid(fonte,"Hello World!",color);

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
			numeros[i] = ponto_jogador;
			posicao = i;
			break;
		}
	}

	efeitos_jogo(4);

	playSong(5);

    while( 1 )
    {
        
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(janela);
                    Mix_Quit();
                    TTF_Quit();
                    SDL_Quit();
                    return;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.scancode)
                    {
                        case SDL_SCANCODE_RETURN:
                            vetor[8] = '\0';
                            switch(posicao)
                            {
                            	case 0:
                            		strcpy(nome1, vetor);
                            		break;

                            	case 1:
                            		strcpy(nome2, vetor);
                            		break;

                            	case 2:
                            		strcpy(nome3, vetor);
                            		break;

                            	case 3:
                            		strcpy(nome4, vetor);
                            		break;

                            	case 4:
                            		strcpy(nome5, vetor);
                            		break;

                            	case 5:
                            		strcpy(nome6, vetor);
                            		break;
                            }
                            FILE *recorde;
                            recorde = fopen( "recordes.txt", "r+");
                            fprintf(recorde, "%s\n", nome1);
							fprintf(recorde, "%d\n", numeros[0]);
							fprintf(recorde, "%s\n", nome2);
							fprintf(recorde, "%d\n", numeros[1]);
							fprintf(recorde, "%s\n", nome3);
							fprintf(recorde, "%d\n", numeros[2]);
							fprintf(recorde, "%s\n", nome4);
							fprintf(recorde, "%d\n", numeros[3]);
							fprintf(recorde, "%s\n", nome5);
							fprintf(recorde, "%d\n", numeros[4]);
							fprintf(recorde, "%s\n", nome6);
							fprintf(recorde, "%d\n", numeros[5]);
							fclose(recorde);
							efeitos_jogo(5);
							foto_recorde(janela, renderer);
                            break;

                        case SDL_SCANCODE_BACKSPACE:
                            i--;
                            vetor[i] = '-';
                            break;

                        case SDL_SCANCODE_A:
                            vetor[i] = 'A';
                            i++;
                            break;

                        case SDL_SCANCODE_B:
                            vetor[i] = 'B';
                            i++;
                            break;

                        case SDL_SCANCODE_C:
                            vetor[i] = 'C';
                            i++;
                            break;

                        case SDL_SCANCODE_D:
                            vetor[i] = 'D';
                            i++;
                            break;

                        case SDL_SCANCODE_E:
                            vetor[i] = 'E';
                            i++;
                            break;

                        case SDL_SCANCODE_F:
                            vetor[i] = 'F';
                            i++;
                            break;

                        case SDL_SCANCODE_G:
                            vetor[i] = 'G';
                            i++;
                            break;

                        case SDL_SCANCODE_H:
                            vetor[i] = 'H';
                            i++;
                            break;

                        case SDL_SCANCODE_I:
                            vetor[i] = 'I';
                            i++;
                            break;

                        case SDL_SCANCODE_J:
                            vetor[i] = 'J';
                            i++;
                            break;

                        case SDL_SCANCODE_K:
                            vetor[i] = 'K';
                            i++;
                            break;

                        case SDL_SCANCODE_L:
                            vetor[i] = 'L';
                            i++;
                            break;

                        case SDL_SCANCODE_M:
                            vetor[i] = 'M';
                            i++;
                            break;

                        case SDL_SCANCODE_N:
                            vetor[i] = 'N';
                            i++;
                            break;

                        case SDL_SCANCODE_O:
                            vetor[i] = 'O';
                            i++;
                            break;

                        case SDL_SCANCODE_P:
                            vetor[i] = 'P';
                            i++;
                            break;

                        case SDL_SCANCODE_Q:
                            vetor[i] = 'Q';
                            i++;
                            break;

                        case SDL_SCANCODE_R:
                            vetor[i] = 'R';
                            i++;
                            break;

                        case SDL_SCANCODE_S:
                            vetor[i] = 'S';
                            i++;
                            break;

                        case SDL_SCANCODE_T:
                            vetor[i] = 'T';
                            i++;
                            break;

                        case SDL_SCANCODE_U:
                            vetor[i] = 'U';
                            i++;
                            break;

                        case SDL_SCANCODE_V:
                            vetor[i] = 'V';
                            i++;
                            break;

                        case SDL_SCANCODE_W:
                            vetor[i] = 'W';
                            i++;
                            break;

                        case SDL_SCANCODE_X:
                            vetor[i] = 'X';
                            i++;
                            break;

                        case SDL_SCANCODE_Y:
                            vetor[i] = 'Y';
                            i++;
                            break;

                        case SDL_SCANCODE_Z:
                            vetor[i] = 'Z';
                            i++;
                            break;

                    }
                    break;      
            }
            
        if(i > 8)
        {
            vetor[8] = '\0';
            i = 0;
        }
        else if(i < 0)
        {
            i = 8;
        }

        contador++;
		if (contador == 30){efeitos_jogo(8);}
		if(contador>=21){contador=21;}
            
        text_surface = TTF_RenderText_Solid(fonte, vetor, color);
        texture_palavra = SDL_CreateTextureFromSurface(renderer, text_surface);
               
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, options_image.Texture, &options_image.cut, &options_image.sizeImg);
        SDL_RenderCopy(renderer, texture_palavra, &corte_img_simulador, &tamanho_img_simulador);
        SDL_RenderCopy(renderer, parabens.Texture, &parabens.cut, &parabens.sizeImg);
        SDL_RenderCopy(renderer, novoRecorde.Texture, &novoRecorde.cut, &novoRecorde.sizeImg);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }

    return;
}
