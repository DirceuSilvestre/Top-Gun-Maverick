void history2(SDL_Window *janela, SDL_Renderer *renderer)
{
	int contador = 0, a = 0;

	plane = setElement(
        "plane",
        IMG_Load("png/menu.png"),
        createRect(900, 670, 410, 300),
        createRect(0.72 * WIDTH, 0.73 * HEIGHT, 0, 0)
    );

    letra2 = setElement(
        "letra2",
        IMG_Load("png/letra2.png"),
        createRect(0, 0, 741, 555),
        createRect( 0.03 * WIDTH, 0.03 * HEIGHT, 0.40 * WIDTH, 0.51 * HEIGHT)
    );

	historia2[0] = setElement(
        "historia2[0]",
        IMG_Load("png/moto1.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[1] = setElement(
        "historia2[1]",
        IMG_Load("png/moto2.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[2] = setElement(
        "historia2[2]",
        IMG_Load("png/moto3.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[3] = setElement(
        "historia2[3]",
        IMG_Load("png/moto4.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[4] = setElement(
        "historia2[4]",
        IMG_Load("png/moto5.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[5] = setElement(
        "historia2[5]",
        IMG_Load("png/moto6.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[6] = setElement(
        "historia2[6]",
        IMG_Load("png/moto7.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[7] = setElement(
        "historia2[7]",
        IMG_Load("png/moto8.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[8] = setElement(
        "historia2[8]",
        IMG_Load("png/moto9.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[9] = setElement(
        "historia2[9]",
        IMG_Load("png/moto10.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[10] = setElement(
        "historia2[10]",
        IMG_Load("png/moto11.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[11] = setElement(
        "historia2[11]",
        IMG_Load("png/moto12.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[12] = setElement(
        "historia2[12]",
        IMG_Load("png/moto13.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[13] = setElement(
        "historia2[13]",
        IMG_Load("png/moto14.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[14] = setElement(
        "historia2[14]",
        IMG_Load("png/moto15.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[15] = setElement(
        "historia2[15]",
        IMG_Load("png/moto16.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[16] = setElement(
        "historia2[16]",
        IMG_Load("png/moto17.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[17] = setElement(
        "historia2[17]",
        IMG_Load("png/moto18.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[18] = setElement(
        "historia2[18]",
        IMG_Load("png/moto19.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[19] = setElement(
        "historia2[19]",
        IMG_Load("png/moto20.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[20] = setElement(
        "historia2[20]",
        IMG_Load("png/moto21.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[21] = setElement(
        "historia2[21]",
        IMG_Load("png/moto22.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[22] = setElement(
        "historia2[22]",
        IMG_Load("png/moto23.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[23] = setElement(
        "historia2[23]",
        IMG_Load("png/moto24.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[24] = setElement(
        "historia2[24]",
        IMG_Load("png/moto25.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[25] = setElement(
        "historia2[25]",
        IMG_Load("png/moto26.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[26] = setElement(
        "historia2[26]",
        IMG_Load("png/moto27.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[27] = setElement(
        "historia2[27]",
        IMG_Load("png/moto28.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[28] = setElement(
        "historia2[28]",
        IMG_Load("png/moto29.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[29] = setElement(
        "historia2[29]",
        IMG_Load("png/moto30.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[30] = setElement(
        "historia2[30]",
        IMG_Load("png/moto31.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[31] = setElement(
        "historia2[31]",
        IMG_Load("png/moto32.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[32] = setElement(
        "historia2[32]",
        IMG_Load("png/moto33.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[33] = setElement(
        "historia2[33]",
        IMG_Load("png/moto34.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[34] = setElement(
        "historia2[34]",
        IMG_Load("png/moto35.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[35] = setElement(
        "historia2[35]",
        IMG_Load("png/moto36.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[36] = setElement(
        "historia2[36]",
        IMG_Load("png/moto37.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[37] = setElement(
        "historia2[37]",
        IMG_Load("png/moto38.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[38] = setElement(
        "historia2[38]",
        IMG_Load("png/moto39.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[39] = setElement(
        "historia2[39]",
        IMG_Load("png/moto40.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[40] = setElement(
        "historia2[40]",
        IMG_Load("png/moto41.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[41] = setElement(
        "historia2[41]",
        IMG_Load("png/moto42.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[42] = setElement(
        "historia2[42]",
        IMG_Load("png/moto43.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[43] = setElement(
        "historia2[43]",
        IMG_Load("png/moto44.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[44] = setElement(
        "historia2[44]",
        IMG_Load("png/moto45.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[45] = setElement(
        "historia2[45]",
        IMG_Load("png/moto46.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[46] = setElement(
        "historia2[46]",
        IMG_Load("png/moto47.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[47] = setElement(
        "historia2[47]",
        IMG_Load("png/moto48.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[48] = setElement(
        "historia2[48]",
        IMG_Load("png/moto49.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[49] = setElement(
        "historia2[49]",
        IMG_Load("png/moto50.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[50] = setElement(
        "historia2[50]",
        IMG_Load("png/moto51.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[51] = setElement(
        "historia2[51]",
        IMG_Load("png/moto52.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia2[52] = setElement(
        "historia2[52]",
        IMG_Load("png/moto53.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );

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
							gameTitle(janela, renderer);
							return;
							break;
					}
					break;
			}
		}

		contador++;
		a++;

		if(a>=53){a=0;}

		if(contador > 60)
		{
			plane.sizeImg.w = 0.18 * WIDTH;
			plane.sizeImg.h = 0.18 * HEIGHT;
		}
		if(contador > 65)
		{
			plane.sizeImg.w = 0;
			plane.sizeImg.h = 0;
			contador = 55;
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, historia2[a].Texture, &historia2[a].cut, &historia2[a].sizeImg);
		SDL_RenderCopy(renderer, letra2.Texture, &letra2.cut, &letra2.sizeImg);
		SDL_RenderCopy(renderer, plane.Texture, &plane.cut, &plane.sizeImg);
		SDL_RenderPresent(renderer);
		SDL_Delay(120);
	}
	return;
}

void history1(SDL_Window *janela, SDL_Renderer *renderer)
{
	int contador = 0;

	plane = setElement(
        "plane",
        IMG_Load("png/menu.png"),
        createRect(900, 670, 410, 300),
        createRect(0.72 * WIDTH, 0.73 * HEIGHT, 0, 0)
    );

    letra1 = setElement(
        "letra1",
        IMG_Load("png/letra1.png"),
        createRect(0, 0, 773, 490),
        createRect( WIDTH - 0.48 * WIDTH, 0.08 * HEIGHT, 0.43 * WIDTH, 0.56 * HEIGHT)
    );

	historia1[0] = setElement(
        "historia1[0]",
        IMG_Load("png/joga1.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[1] = setElement(
        "historia1[1]",
        IMG_Load("png/joga2.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[2] = setElement(
        "historia1[2]",
        IMG_Load("png/joga3.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[3] = setElement(
        "historia1[3]",
        IMG_Load("png/joga4.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[4] = setElement(
        "historia1[4]",
        IMG_Load("png/joga5.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[5] = setElement(
        "historia1[5]",
        IMG_Load("png/joga6.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[6] = setElement(
        "historia1[6]",
        IMG_Load("png/joga7.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[7] = setElement(
        "historia1[7]",
        IMG_Load("png/joga8.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[8] = setElement(
        "historia1[8]",
        IMG_Load("png/joga9.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[9] = setElement(
        "historia1[9]",
        IMG_Load("png/joga10.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[10] = setElement(
        "historia1[10]",
        IMG_Load("png/joga11.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[11] = setElement(
        "historia1[11]",
        IMG_Load("png/joga12.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[12] = setElement(
        "historia1[12]",
        IMG_Load("png/joga13.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[13] = setElement(
        "historia1[13]",
        IMG_Load("png/joga14.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[14] = setElement(
        "historia1[14]",
        IMG_Load("png/joga15.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[15] = setElement(
        "historia1[15]",
        IMG_Load("png/joga16.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[16] = setElement(
        "historia1[16]",
        IMG_Load("png/joga17.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[17] = setElement(
        "historia1[17]",
        IMG_Load("png/joga18.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[18] = setElement(
        "historia1[18]",
        IMG_Load("png/joga19.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[19] = setElement(
        "historia1[19]",
        IMG_Load("png/joga20.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[20] = setElement(
        "historia1[20]",
        IMG_Load("png/joga21.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[21] = setElement(
        "historia1[21]",
        IMG_Load("png/joga22.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[22] = setElement(
        "historia1[22]",
        IMG_Load("png/joga23.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[23] = setElement(
        "historia1[23]",
        IMG_Load("png/joga24.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[24] = setElement(
        "historia1[24]",
        IMG_Load("png/joga25.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[25] = setElement(
        "historia1[25]",
        IMG_Load("png/joga26.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[26] = setElement(
        "historia1[26]",
        IMG_Load("png/joga27.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[27] = setElement(
        "historia1[27]",
        IMG_Load("png/joga28.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[28] = setElement(
        "historia1[28]",
        IMG_Load("png/joga29.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[29] = setElement(
        "historia1[29]",
        IMG_Load("png/joga30.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[30] = setElement(
        "historia1[30]",
        IMG_Load("png/joga31.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[31] = setElement(
        "historia1[31]",
        IMG_Load("png/joga32.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[32] = setElement(
        "historia1[32]",
        IMG_Load("png/joga33.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[33] = setElement(
        "historia1[33]",
        IMG_Load("png/joga34.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[34] = setElement(
        "historia1[34]",
        IMG_Load("png/joga35.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[35] = setElement(
        "historia1[35]",
        IMG_Load("png/joga36.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[36] = setElement(
        "historia1[36]",
        IMG_Load("png/joga37.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[37] = setElement(
        "historia1[37]",
        IMG_Load("png/joga38.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[38] = setElement(
        "historia1[38]",
        IMG_Load("png/joga39.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[39] = setElement(
        "historia1[39]",
        IMG_Load("png/joga40.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[40] = setElement(
        "historia1[40]",
        IMG_Load("png/joga41.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[41] = setElement(
        "historia1[41]",
        IMG_Load("png/joga42.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[42] = setElement(
        "historia1[42]",
        IMG_Load("png/joga43.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );
    historia1[43] = setElement(
        "historia1[43]",
        IMG_Load("png/joga44.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT)
    );

    int a = 0;

	playSong(7);
	music = Mix_LoadMUS("musicas/danger_zone_animada.wav");
	Mix_PlayMusic(music, -1);


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
							history2(janela, renderer);
							return;
							break;
					}
					break;
			}
		}

		contador++;
		a++;

		if(a>=44){a=0;}

		if(contador > 60)
		{
			plane.sizeImg.w = 0.18 * WIDTH;
			plane.sizeImg.h = 0.18 * HEIGHT;
		}
		if(contador > 65)
		{
			plane.sizeImg.w = 0;
			plane.sizeImg.h = 0;
			contador = 55;
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, historia1[a].Texture, &historia1[a].cut, &historia1[a].sizeImg);
		SDL_RenderCopy(renderer, letra1.Texture, &letra1.cut, &letra1.sizeImg);
		SDL_RenderCopy(renderer, plane.Texture, &plane.cut, &plane.sizeImg);
		SDL_RenderPresent(renderer);
		SDL_Delay(150);
	}
	return;
}