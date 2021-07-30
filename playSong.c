int opcao_musica = 1, opcao_efeito = 1, volume_musica = 128, volume_efeito = 128; //0 - sem som, 1 - música, 2 - instrumental 

void options_sound(int choice1)
{
	opcao_musica = choice1;
	return;
}

void volume_music(int choice2)
{
	volume_musica = choice2;
	return;
}

void options_effects(int choice3)
{
	opcao_efeito = choice3;
}

void volume_effects(int choice4)
{
	volume_efeito = choice4;
	return;
}


void playSong(int choice)
{
	switch(opcao_musica)
	{
		case 0:
			Mix_PauseMusic();
			volume_musica = 0;
			break;

		case 1:
			switch(choice)
			{
				case 0:
					Mix_PauseMusic();
					break;

				case 1:
					music = Mix_LoadMUS("instrumental/anthem_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, -1);
					break;

				case 2:
					music = Mix_LoadMUS("musicas/destination_unknown_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 3:
					music = Mix_LoadMUS("musicas/great_fire_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 4:
					music = Mix_LoadMUS("musicas/might_wings_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 5:
					music = Mix_LoadMUS("musicas/playing_the_boys_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 6:
					music = Mix_LoadMUS("musicas/through_fire_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 7:
					music = Mix_LoadMUS("musicas/danger_zone_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 8:
					music = Mix_LoadMUS("musicas/take_my_breath_romantica.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 9:
					music = Mix_LoadMUS("instrumental/danger_zone_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 10:
					music = Mix_LoadMUS("instrumental/great_fire_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 11:
					music = Mix_LoadMUS("instrumental/mighty_wings_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 12:
					music = Mix_LoadMUS("instrumental/play_the_boys_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 13:
					music = Mix_LoadMUS("instrumental/through_fire_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 14:
					music = Mix_LoadMUS("instrumental/memories_despedida_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 15:
					music = Mix_LoadMUS("musicas/heaven_eyes_desped.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 16:
					music = Mix_LoadMUS("musicas/lost_lovefealing_game_over.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 17:
					music = Mix_LoadMUS("sons/de_volta.wav");
					Mix_VolumeMusic(128);
					Mix_PlayMusic(music, 1);
					break;

			}
			break;
	}
	return;
}

void playSound(int choice)
{
	
	switch(opcao_efeito)
	{
		case 0:
			Mix_PauseMusic();
			volume_efeito = 0;
			break;

		case 1:
			switch(choice)
			{
				case 0:
					Mix_PauseMusic();
					break;

				case 1:
					music = Mix_LoadMUS("sons/abertura.wav");
					Mix_PlayMusic(music, 1);
					break;

				case 2:
					sound = Mix_LoadWAV("sons/sou_maverick.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;	

				case 3:
					sound = Mix_LoadWAV("sons/click.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 4:
					sound = Mix_LoadWAV("sons/ranking.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 5:
					shot = Mix_LoadWAV("sons/laser4.wav");
					Mix_VolumeChunk(shot, 64);
					Mix_PlayChannel(-1, shot, 0);

			}
			break;
	}
	return;
}

void random_sound( )
{
	int x;
	srand( (unsigned)time(NULL) );
	x = rand()%10;
	switch(opcao_efeito)
	{
		case 0:
			Mix_PauseMusic();
			volume_efeito = 0;
			break;

		case 1:
			switch(x)
			{

				case 1:
					sound = Mix_LoadWAV("sons/enfrentar_elite.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 2:
					sound = Mix_LoadWAV("sons/primeiro_teste.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;	

				case 3:
					sound = Mix_LoadWAV("sons/marcar_pontos.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 4:
					sound = Mix_LoadWAV("sons/enfrentar_elite.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 5:
					sound = Mix_LoadWAV("sons/primeiro_teste.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;	

				case 6:
					sound = Mix_LoadWAV("sons/marcar_pontos.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 7:
					sound = Mix_LoadWAV("sons/enfrentar_elite.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 8:
					sound = Mix_LoadWAV("sons/primeiro_teste.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;	

				case 9:
					sound = Mix_LoadWAV("sons/marcar_pontos.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;
				

			}
			break;
	}
	return;
}

void random_song() //0 não está em jogo, 1 está em jogo
{
	int x; 
	srand( (unsigned)time(NULL) );
	x = rand()%10;
	switch(opcao_musica)
	{
		case 0:
			Mix_PauseMusic();
			volume_musica = 0;
			break;

		case 1:
			switch(x)
			{

				case 1:
					music = Mix_LoadMUS("musicas/danger_zone_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 2:
					music = Mix_LoadMUS("musicas/destination_unknown_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 3:
					music = Mix_LoadMUS("musicas/great_fire_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 4:
					music = Mix_LoadMUS("musicas/might_wings_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 5:
					music = Mix_LoadMUS("musicas/playing_the_boys_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 6:
					music = Mix_LoadMUS("musicas/through_fire_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 7:
					music = Mix_LoadMUS("musicas/danger_zone_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 8:
					music = Mix_LoadMUS("musicas/might_wings_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 9:
					music = Mix_LoadMUS("musicas/through_fire_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;
			
			}
			break;

		case 2:
			switch(x)
			{

				case 1:
					music = Mix_LoadMUS("instrumental/anthem_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 2:
					music = Mix_LoadMUS("instrumental/danger_zone_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 3:
					music = Mix_LoadMUS("instrumental/great_fire_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 4:
					music = Mix_LoadMUS("instrumental/mighty_wings_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 5:
					music = Mix_LoadMUS("instrumental/play_the_boys_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 6:
					music = Mix_LoadMUS("instrumental/through_fire_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 7:
					music = Mix_LoadMUS("instrumental/danger_zone_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 8:
					music = Mix_LoadMUS("instrumental/mighty_wings_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 9:
					music = Mix_LoadMUS("instrumental/through_fire_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

			}

	}
	return;
}

void playRadio(int choice)
{
	if(opcao_musica == 2)
	{
		opcao_musica = 1;
	}
	switch(opcao_musica)
	{
		case 0:
			Mix_PauseMusic();
			volume_musica = 0;
			break;

		case 1:
			switch(choice)
			{
				case 0:
					Mix_PauseMusic();
					break;

				case 1:
					music = Mix_LoadMUS("instrumental/anthem_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 2:
					music = Mix_LoadMUS("musicas/destination_unknown_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 3:
					music = Mix_LoadMUS("musicas/great_fire_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 4:
					music = Mix_LoadMUS("musicas/might_wings_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 5:
					music = Mix_LoadMUS("musicas/playing_the_boys_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 6:
					music = Mix_LoadMUS("musicas/through_fire_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 7:
					music = Mix_LoadMUS("musicas/danger_zone_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 8:
					music = Mix_LoadMUS("musicas/take_my_breath_romantica.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 9:
					music = Mix_LoadMUS("instrumental/danger_zone_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 10:
					music = Mix_LoadMUS("instrumental/great_fire_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 11:
					music = Mix_LoadMUS("instrumental/mighty_wings_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 12:
					music = Mix_LoadMUS("instrumental/play_the_boys_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;	

				case 13:
					music = Mix_LoadMUS("instrumental/through_fire_animada.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

				case 14:
					music = Mix_LoadMUS("instrumental/memories_despedida_instru.wav");
					Mix_VolumeMusic(volume_musica);
					Mix_PlayMusic(music, 1);
					break;

			}
			break;
	}
	return;
}

void efeitos_jogo(int a)
{
	switch(opcao_efeito)
	{
		case 0:
			volume_efeito = 0;
			break;

		case 1:
			switch(a)
			{
				case 0:
					sound = Mix_LoadWAV("sons/pouco_combustivel.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 1:
					sound = Mix_LoadWAV("sons/sem_combustivel.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 2:
					sound = Mix_LoadWAV("sons/droga_maverick.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 3:
					sound = Mix_LoadWAV("sons/retorno_base.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 4:
					sound = Mix_LoadWAV("sons/genial_voo.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 5:
					shot = Mix_LoadWAV("sons/olha_passarinho.wav");
					Mix_VolumeChunk(shot, volume_efeito);
					Mix_PlayChannel(-1, shot, 0);
					break;

				case 6:
					sound = Mix_LoadWAV("sons/ta_demais.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 7:
					sound = Mix_LoadWAV("sons/chefe_de_fase.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 8:
					sound = Mix_LoadWAV("sons/maverick_corajoso.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 9:
					sound = Mix_LoadWAV("sons/ficou_boa.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;

				case 10:
					explosion = Mix_LoadWAV("sons/explode.wav");
					Mix_VolumeChunk(explosion, 76);
					Mix_PlayChannel(-1, explosion, 0);
					break;

				case 11:
					sound = Mix_LoadWAV("sons/necessidade_velocidade.wav");
					Mix_VolumeChunk(sound, volume_efeito);
					Mix_PlayChannel(-1, sound, 0);
					break;
					
			}
	}
	return;
}
        		
        		
