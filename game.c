//Configurações da nave
float SHIP_MOVE_SPEED = 6;
float LASER_MOVE_SPEED = 25;
int lifeTakenShipLaser1 = 1;
int lifeTakenShipLaser2 = 2;

//Configurações do tanque de combustível e da estrela
float LIFECOMB_MOVE_SPEED = 12;
float SPECIALSTAR_MOVE_SPEED = 12;

//Configurações dos inimigos
int enemieHeart = 2;
float ENEMIE_MOVE_SPEED = 48;

//Configurações das bombas
int bombHeart = 1;
float BOMB_MOVE_SPEED = 60; //esse valor aqui, indico não diminuir pq pode dar problema

//Configurações do Chefão
int bossHeart = 360; //360
int lifeTakenBossLaser1 = 10;
float BOSSENEMIELASER_MOVE_SPEED = 15;
float BOSSENEMIE_MOVE_SPEED = 10;
float BOSSENEMIE_MOVE_SPEED_VERTICAL = 5;

//Total de inimigos mortos pro chefão surgir
int totalDeadEnemiesToFinalBoss = 80; //80 

//Total de inimigos mortos pras bombas surgirem
int totalDeadEnemiesToStartBombs = 55; //(tem que ser menor que o totalDeadEnemiesToFinalBoss)

//Diminuição do score a cada inimigo destruído
int ponto_por_inimigo = 100;
int ponto_por_Lifecomb = 50; 
int ponto_por_specialStar = 50; 

/* Não pode alterar */
float heightShipWithoutShadow;
int initialLife = 100;
float MARGIN = 0.005 * WIDTH;
float TOPMARGIN = 0.005 * WIDTH + HEIGHT*0.1;
int lastIndexOfLasers = 0;
int lastIndexOfExplosions = 0;
int lastIndexOfEnemieBossLasers = 0;
int deadEnemies = 0; 
int bossShooting = 0;
int stopShip1Lasers = 0;
float wExplosion;
float hExplosion;
int startBombs = 0;
int ponto_jogador = 100000;
int contador = 0;

/* ----------------- FUNÇÕES PRA VOCÊ COLOCAR AS MÚSICAS E EFEITOS QUE QUISER ----------------- */

void effectsCallBoss(void){
    //efeitos para quando a fase do Chefão inicia
    efeitos_jogo(7); //(coloquei uma musica qualquer, pode mudar)
}

void effectsCallBombs(void){
    //efeitos para quando a fase das Bombas inicia
    efeitos_jogo(11); //(coloquei uma musica qualquer, pode mudar)
}

void effectsCollisionShipAndEnemie(void){
    //efeitos para quando a Nave e um Inimigo colidem
}

void effectsCollisionShipAndLifecomb(void){
    //efeitos para quando a Nave e o Tanque de Combustível colidem
    playSound(3);
}

void effectsCollisionShipAndSpecialStar(void){
    //efeitos para quando a Nave e a Estrela Especial colidem
    playSound(3);
}

void effectsCollisionShipAndBossLasers(void){
    //efeitos para quando a Nave e os Lasers do Chefão colidem
    efeitos_jogo(10);
}

void effectsCollisionShipLasersAndEnemie(void){
    //efeitos para quando os Lasers da Nave e os Inimigos colidem
    efeitos_jogo(10);
}

void effectsCollisionShipLasersAndBoss(void){
    //efeitos para quando os Lasers da Nave e o Chefão colidem
    efeitos_jogo(10);
}

void effectsShootLaser1(void){
    //efeitos para quando o laser menor é disparado
    playSound(5);
}

void effectsShootLaser2(void){
    //efeitos para quando o laser maior é disparado
    playSound(5);
}

void effectsEnemyDowned(void){
    //efeitos pra quando um inimigo é destruído
} 

void callGameOver(SDL_Window *janela, SDL_Renderer *renderer){
    //ações para quando o jogador perde
    FILE *grava;
    grava = fopen( "apoio.txt", "r+");
    fprintf(grava, "%d", ponto_jogador);
    fclose(grava);
    ponto_jogador = 100000;
    efeitos_jogo(2);
    gameover(janela, renderer);
}
/*
void callWin(SDL_Window *janela, SDL_Renderer *renderer){
    //ações para quando o jogador ganha
    contador++;
    if(contador==1){efeitos_jogo(8);efeitos_jogo(10);}
    if(contador>70){ship1.element.sizeImg.y -= 2 * SHIP_MOVE_SPEED;}
    if(contador>=145){FILE *grava;grava = fopen( "apoio.txt", "r+");fprintf(grava, "%d", ponto_jogador);
    fclose(grava);ponto_jogador=100000;gameover(janela, renderer);}
}*/



/* -------------------------------------- FUNÇÕES DO JOGO -------------------------------------- */

void clearAll(void){
    for(int j=0; j<MAX_ENEMIES; j++){
        if(enemies[j].status == 1){
            enemies[j].status = 0;
        }
    }

    for(int j=0; j<MAX_LASERS; j++){
        if(lasers[j].status == 1){
            lasers[j].status = 0;
        }
    }

    if(enemieBoss.status == 1) {
        enemieBoss.status = 0;
    }

    for(int j=0; j<MAX_ENEMIEBOSSLASERS ; j++){
        if(enemieBossLasers[j].status == 1){
            enemieBossLasers[j].status = 0;
        }
    }

    for(int j=0; j<MAX_EXPLOSIONS; j++){
        if(explosions[j].status == 1){
            explosions[j].status = 0;
        }
    }
}


DestructiveObject createLaser(char * name, char * fileName, int lifeTaken, float xLaser, float yLaser, float wLaser, float hLaser){
    DestructiveObject laser = setDestructiveObject(
        setElement(
            name,
            IMG_Load(fileName),
            createRect(0,0,10,54),
            createRect(xLaser, yLaser, wLaser, hLaser)
        ),
        lifeTaken
    );
    laser.status = 1;
    return laser;
}

DestructiveObject createLaser1(void){
    effectsShootLaser1();
    return createLaser(
        "laser1",
        "png/Laser1-1.png",
        lifeTakenShipLaser1, 
        ship1.element.sizeImg.x + ship1.element.sizeImg.w/2 - ship1.element.sizeImg.w*0.3/3,
        ship1.element.sizeImg.y,
        ship1.element.sizeImg.w*0.3,
        heightShipWithoutShadow*0.9
    );
}

DestructiveObject createLaser2(void){
    effectsShootLaser2();
    return createLaser(
        "laser2",
        "png/Laser1-2.png",
        lifeTakenShipLaser2,
        ship1.element.sizeImg.x + ship1.element.sizeImg.w/2 - ship1.element.sizeImg.w*0.3/2,
        ship1.element.sizeImg.y,
        ship1.element.sizeImg.w*0.3,
        heightShipWithoutShadow*0.9
    );
}

DestructiveObject createEnemieBossLaser1(float xEnemieBossLaser){
    effectsShootLaser1();
    return createLaser(
        "bossLaser1",
        "png/Laser2-1.png",
        lifeTakenBossLaser1, 
        xEnemieBossLaser,
        enemieBoss.element.sizeImg.y + (enemieBoss.element.sizeImg.h - heightShipWithoutShadow*0.9),
        ship1.element.sizeImg.w*0.3,
        heightShipWithoutShadow*0.9
    );
}

DestructiveObject createEnemieBossLaser1Left(void){
    return createEnemieBossLaser1(enemieBoss.element.sizeImg.x + enemieBoss.element.sizeImg.w/4);
}

DestructiveObject createEnemieBossLaser1Right(void){
    return createEnemieBossLaser1(enemieBoss.element.sizeImg.x + enemieBoss.element.sizeImg.w/4 + enemieBoss.element.sizeImg.w/2);
}


Element createExplosion(float x, float y, float w, float h){
    Element explosion = setElement(
            "explosion",
            IMG_Load("png/explosao.png"),
            createRect(0,0,64,64),
            createRect(x,y,w,h)
        );
    explosion.status = 1;
    return explosion;
}

void updateArrayExplosions(SDL_Rect explodedSizeImg){
    explosions[lastIndexOfExplosions] = createExplosion(
        explodedSizeImg.x + (explodedSizeImg.w - explodedSizeImg.w*0.9)/2,
        explodedSizeImg.y,
        explodedSizeImg.w*0.9,
        heightShipWithoutShadow*0.9
    );

    lastIndexOfExplosions++;
    if(lastIndexOfExplosions==MAX_EXPLOSIONS){
        lastIndexOfExplosions = 0;
    }
}

void updateArrayExplosionsGeneric(SDL_Rect explodedSizeImg){
    explosions[lastIndexOfExplosions] = createExplosion(
        explodedSizeImg.x,
        explodedSizeImg.y,
        explodedSizeImg.w,
        explodedSizeImg.h
    );

    lastIndexOfExplosions++;
    if(lastIndexOfExplosions==MAX_EXPLOSIONS){
        lastIndexOfExplosions = 0;
    }
}

void emergeBombs(float targetX, float targetY, float targetW, float targetH){
    /*if(deadEnemies >= totalDeadEnemiesToFinalBoss){
        return;
    }*/

    //bombs
    float wBomb = 0.076 * WIDTH;
    float hBomb = 0.030 * HEIGHT;
    float xBomb;
    float yBomb = targetY + targetH*0.2;
    int directionXBomb;
    SDL_Surface *img;
    int randomNumberBombs = rand()% (2);
    if(startBombs==1){
        switch(randomNumberBombs){
            case 0:
                img = IMG_Load("png/bomba-esq.png");
                xBomb = WIDTH;
                directionXBomb = -1;
                break;
            case 1:
                img = IMG_Load("png/bomba-dir.png");
                xBomb = 0;
                directionXBomb = 1;
                break;
        }
        enemies[3] = setEnemie(
            setElement(
                "enemieBomb",
                img,
                createRect(0,0,411,122),          
                createRect(xBomb,yBomb,wBomb,hBomb) 
            ),
            bombHeart,
            directionXBomb,
            0
        );
        enemies[3].status = 1;
    }
}

/* -------- A função cria 3 inimigos para atacar a nave de acordo com a posição X da nave (targetXandW) -------- */
void emergeEnemies(float targetX, float targetY, float targetW, float targetH){
    if(deadEnemies >= totalDeadEnemiesToFinalBoss){
        return;
    }

    float targetXandW = targetX + targetW;
    float cutXEnemie;

    float wEnemie = 0.056 * WIDTH;
    float hEnemie = 0.090 * HEIGHT;
    float xEnemie;
    float yEnemie = 0;

    int randomNumberEnemie = rand()% (MAX_ENEMIES);

    int directionXEnemie;
    for(int i=0;i<MAX_ENEMIES; i++){
        if(enemies[i].status != 1){
            switch(i){
                case 0:
                    cutXEnemie = 6.7;
                    xEnemie = (targetX + targetW/2) - (targetY + heightShipWithoutShadow); 
                    directionXEnemie = 1;
                    break;
                case 1:
                    cutXEnemie = 9;
                    xEnemie = targetXandW - wEnemie;
                    directionXEnemie = 0;
                    break;
                case 2:
                    cutXEnemie = 11.3;
                    xEnemie = (targetX + targetW/2) + (targetY);  
                    directionXEnemie = -1;
                    break;
            }
            enemies[i] = setEnemie(
                setElement(
                    "enemie",
                    IMG_Load("png/inimigo.png"),
                    createRect(cutXEnemie*28,0,28,30),          
                    createRect(xEnemie,yEnemie,wEnemie,hEnemie) 
                ),
                enemieHeart,
                directionXEnemie,
                1
            );
        }
    }
    enemies[randomNumberEnemie].status=1;

    //emergeBombs(targetX, targetY, targetW, targetH);
}

void decreaseLife(SDL_Window *janela, SDL_Renderer *renderer, int decrease){
    ship1.life -= decrease;
    //printf("ship1.life : %d\n",ship1.life);
    if(ship1.life == 60){efeitos_jogo(0);}
    if(ship1.life % (initialLife/5) == 0){
        if(ship1.life > 0){ //life.cut.y < 78 * 4
            life.cut.y += 78;
        } else {
            //Game over
            clearAll();
            callGameOver(janela,renderer);
        }
    }
}

void emergestar(void){
    specialStar.status = 1;
    specialStar.sizeImg.y = 0;
    int limitespecialStar = WIDTH - specialStar.sizeImg.w - MARGIN;
    int randomNumberspecialStar = rand()% (limitespecialStar);
    specialStar.sizeImg.x = (float) randomNumberspecialStar + MARGIN;    
}

void emergelifeComb(void){
    lifeComb.status = 1;
    lifeComb.sizeImg.y = 0;
    int limitelifeComb = WIDTH - lifeComb.sizeImg.w - MARGIN;
    int randomNumberlifeComb = rand()% (limitelifeComb);
    lifeComb.sizeImg.x = (float) randomNumberlifeComb + MARGIN; 
}

//Atualiza a posição central da nave
SDL_Rect updateMid(Element objectElement, float heightObject){
    float wMid = objectElement.sizeImg.w * 0.5;
    return createRect(
        objectElement.sizeImg.x + objectElement.sizeImg.w/2 - wMid/2 ,
        objectElement.sizeImg.y,
        wMid,
        heightObject
    );
}

int coinFlipAddicted(){
    // quanto maior o número no switch, menor a probabilidade de vir -1
    switch(rand()% 45){
        case 0:
            return -1;
            break;
        default:
            return 1;
    }
}

void game(SDL_Window *janela, SDL_Renderer *renderer)
{
    deadEnemies = 0;
    startBombs = 0;

    /* -------- Criação do cenário -------- */
    scenery = setElement(
        "scenery",
        IMG_Load("png/cenario.png"),
        createRect(0,(9000 - HEIGHT),WIDTH,HEIGHT),
        createRect(0,0,WIDTH,HEIGHT)
    );

    /* -------- Criação e dimensões da nave com sombra -------- */
    float wShip = 0.056 * WIDTH;
    float hShip = 0.221 * HEIGHT;
    float xShip = WIDTH/2 - wShip;
    float yShip = HEIGHT - hShip * 1.5;
    ship1 = setShip(
        setElement(
            "ship1",
            IMG_Load("png/f14-1.png"),
            createRect(45,0,29,71), //x, y, w, h
            createRect(xShip,yShip,wShip,hShip)
        ),
        initialLife
    );
    heightShipWithoutShadow = ship1.element.sizeImg.h/2.25;

    /* -------- Criação e dimensões da parte central da nave (que será atingida) -------- */
    midShip1 = setElement(
        "midShip1",
        IMG_Load("png/combustivel.png"), 
        createRect(0, 0, 512, 512),
        updateMid(ship1.element, heightShipWithoutShadow)
    );

    /* -------- Criação e dimensões da vida -------- */
    float wLife = 0.196 * WIDTH;
    float hLife = 0.076 * HEIGHT;
    float xLife = 0.015 * WIDTH;
    float yLife = 0.025 * HEIGHT;
    life = setElement(
        "life",
        IMG_Load("png/gasolina.png"),
        createRect(0,0,287,78),  
        createRect(xLife,yLife,wLife,hLife)  
    );

    /* -------- Criação e dimensões do combustivel da vida-------- */
    float wlifeComb = 0.04*WIDTH;
    lifeComb = setElement(
        "lifeComb",
        IMG_Load("png/oleo.png"),
        createRect(0, 0, 512, 512),
        createRect(WIDTH/2, 0, wlifeComb, 0.06*HEIGHT)
    );

    /* -------- Criação e dimensões da estrela de efeito especial-------- */
    float wSpecialStar = 0.04*WIDTH;
    specialStar = setElement(
        "specialStar",
        IMG_Load("png/estrela.png"),
        createRect(0, 0, 102, 97),
        createRect(WIDTH/2, 0, wSpecialStar, 0.06*HEIGHT)
    );

    /* -------- Criação e dimensões do Chefão -------- */
    float wenemieBoss = 4.3 * ship1.element.sizeImg.w;
    float henemieBoss = 3.4 * heightShipWithoutShadow;
    float xenemieBoss = WIDTH/2 - wenemieBoss + wenemieBoss/2;
    float yenemieBoss = 0 - 2*henemieBoss;
    int directionXenemieBoss = 1;
    enemieBoss = setEnemie(
        setElement(
            "enemieBoss",
            IMG_Load("png/boss.png"),
            createRect(0,0,113,147),          
            createRect(xenemieBoss,yenemieBoss,wenemieBoss,henemieBoss) 
        ),
        bossHeart,
        directionXenemieBoss,
        0
    );

    /* -------- Pontuação -------- */
    char pontos[7];
    
    /* -------- Sistemas de tempo  -------- */
    Uint32 lastTick = SDL_GetTicks();
    Uint32 lastTickNewEnemies = SDL_GetTicks();
    Uint32 lastTickEmergelifeComb = SDL_GetTicks();
    Uint32 lastTickEmergespecialStar = SDL_GetTicks();
    Uint32 lastTickEnemieBossShooting = SDL_GetTicks();
    Uint32 lastTickNewBombs = SDL_GetTicks();

    /* -------- Tempo decorrido desde que pegou o a SpecialStar  -------- */
    Uint32 lastGetspecialStar;

    /* -------- Looping do jogo -------- */
    while(1)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
                case SDL_QUIT:
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(janela);
                    SDL_Quit();
                    return;
                    break;

                case SDL_KEYDOWN:
                    switch(event.key.keysym.scancode)
                    {
                        case SDL_SCANCODE_RETURN:
                            playSound(0);
                            Mix_FreeChunk(sound);
                            Mix_FreeChunk(shot);
                            Mix_FreeChunk(explosion);
                            gameTitle(janela, renderer);
                            return;
                            break;
                    }
                    break;

            }
        }

        if(enemieBoss.heart == 40){enemieBoss.element.cut.x=114;}

        /* ------------------------------------ MÚSICA ------------------------------------ */
        if(Mix_PlayingMusic() == 0){
            random_song();
        }


        /* --------------------------- PEGAR O ESTADO DO TECLADO --------------------------- */
        const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);


        /* -------------------------- VERIFICA SE DEVE INICIAR A FASE DO CHEFÃO  -------------------------- */
        if(deadEnemies >= totalDeadEnemiesToFinalBoss && enemieBoss.heart > 0 && enemieBoss.status == 0){
            enemieBoss.status = 1;
            effectsCallBoss();
        }

        /* -------------------------- VERIFICA SE DEVE INICIAR A FASE DAS BOMBAS  -------------------------- */
        if(deadEnemies >= totalDeadEnemiesToStartBombs && enemieBoss.status == 0 && startBombs == 0){
            startBombs = 1;
            effectsCallBombs();
        }

        if(enemieBoss.heart <= 0)
        {
            contador++;
            if(contador==1){efeitos_jogo(8);}
            if(contador>70){ship1.element.sizeImg.y -= 2 * SHIP_MOVE_SPEED;}
            if(contador>=145){FILE *grava;grava = fopen( "apoio.txt", "r+");fprintf(grava, "%d", ponto_jogador);
            fclose(grava);ponto_jogador=100000;gameover(janela, renderer);}
        }

        /* ------------------------------- SISTEMAS DE TEMPO ------------------------------- */

        /* -------- Fps do jogo -------- */
        Uint32 curTick = SDL_GetTicks();
        Uint32 diff = curTick - lastTick;
        if(diff>fps){
            /* -------- Atualizando sistema de tempo para o fps -------- */
            lastTick = curTick;

            /* -------- Movimentação de cenário -------- */
            scenery.cut.y -= 5;
            if(scenery.cut.y - HEIGHT <= 10){
                scenery.cut.y = 9000 - HEIGHT;
            }

            /* -------- Tiro é disparado pelo usuário -------- */
            if(keyboardState[SDL_SCANCODE_Z]){
                if(stopShip1Lasers == 0){
                    lasers[lastIndexOfLasers] = (ship1.specialLaser == 0) ? createLaser1() : createLaser2();
                    lastIndexOfLasers++;
                    if(lastIndexOfLasers==MAX_LASERS){
                        lastIndexOfLasers = 0;
                    }
                }
            }

            /* -------- Atualização do sistema de pontuação -------- */
            //ponto_jogador++;
            sprintf(pontos, "%d", ponto_jogador);
            score = setElement(
                "score",
                TTF_RenderText_Solid(fonte1, pontos, color),
                createRect(0, 0, 6*48, 50),
                createRect(0.220 * WIDTH, 0.025 * HEIGHT, 6 * 0.028 * WIDTH, 0.062 * HEIGHT)
            );

            /* -------- Movimentação dos Inimigos -------- */
            for(int i=0;i<MAX_ENEMIES;i++){
                if(enemies[i].status == 1){
                    if(enemies[i].element.sizeImg.y > HEIGHT ){
                        enemies[i].status = 0;
                    } else {
                        float move_speed;
                        if( strcmp(enemies[i].element.name, "enemie") == 0 ){
                            move_speed = ENEMIE_MOVE_SPEED;
                        }
                        if( strcmp(enemies[i].element.name, "enemieBomb") == 0 ){
                            move_speed = BOMB_MOVE_SPEED;
                        }
                        enemies[i].element.sizeImg.y += enemies[i].directionY * move_speed;
                        enemies[i].element.sizeImg.x += enemies[i].directionX * move_speed;
                    }
                }
            }

            /* -------- Movimentação do tanque de combustível -------- */
            if(lifeComb.sizeImg.y > HEIGHT){
                lifeComb.status = 0;
            } else {
                lifeComb.sizeImg.y += LIFECOMB_MOVE_SPEED;
            }

            /* -------- Movimentação da estrela -------- */
            if(specialStar.sizeImg.y > HEIGHT){
                specialStar.status = 0;
            } else {
                specialStar.sizeImg.y += SPECIALSTAR_MOVE_SPEED;
            }

            /* -------- Movimentação das explosões -------- */
            for(int i=0; i<MAX_EXPLOSIONS; i++){
                if(explosions[i].status == 1){
                    explosions[i].cut.x += 64;
                }
                if(explosions[i].cut.x >= 1024){
                    explosions[i].status == 0;
                }
            }

            /* -------- Movimentação e Disparos do Boss  -------- */
            if(enemieBoss.status == 1){
                /* -------- Movimentação vertical do Boss -------- */
                if(enemieBoss.element.sizeImg.y < TOPMARGIN){
                    stopShip1Lasers = 1;
                    enemieBoss.element.sizeImg.y += BOSSENEMIE_MOVE_SPEED_VERTICAL;
                } else {
                    stopShip1Lasers = 0;
                    if(bossShooting == 0){
                        /* -------- Movimentação horizontal do Boss -------- */
                        enemieBoss.element.sizeImg.x += enemieBoss.directionX * ENEMIE_MOVE_SPEED;
                        if(enemieBoss.element.sizeImg.x > WIDTH - enemieBoss.element.sizeImg.w - MARGIN
                            || enemieBoss.element.sizeImg.x < MARGIN){
                            enemieBoss.directionX *= -1;
                        } else {
                            enemieBoss.directionX *= coinFlipAddicted();
                        }
                    } else {
                        /* -------- Disparos do Boss -------- */
                        enemieBossLasers[lastIndexOfEnemieBossLasers] = createEnemieBossLaser1Left(); lastIndexOfEnemieBossLasers++;
                        enemieBossLasers[lastIndexOfEnemieBossLasers] = createEnemieBossLaser1Right(); lastIndexOfEnemieBossLasers++;
                        if(lastIndexOfEnemieBossLasers > MAX_ENEMIEBOSSLASERS - 3){
                            lastIndexOfEnemieBossLasers = 0;
                        }
                    }
                }
            }
        }

        /* --------  Surgimento de novos inimigos -------- */
        Uint32 curTickNewEnemies = SDL_GetTicks();
        Uint32 diffNewEnemies = curTickNewEnemies - lastTickNewEnemies;
        if(diffNewEnemies>newEnemies){
            lastTickNewEnemies = curTickNewEnemies;
            emergeEnemies(ship1.element.sizeImg.x, ship1.element.sizeImg.y, ship1.element.sizeImg.w, ship1.element.sizeImg.h);
        }

        /* --------  Surgimento de novas bombas -------- */
        Uint32 curTickNewBombs = SDL_GetTicks();
        Uint32 diffNewBombs = curTickNewBombs - lastTickNewBombs;
        if(diffNewBombs>newBombs){
            lastTickNewBombs = curTickNewBombs;
            emergeBombs(ship1.element.sizeImg.x, ship1.element.sizeImg.y, ship1.element.sizeImg.w, ship1.element.sizeImg.h);
        }

        /* --------  Surgimento de tanques de gasolina -------- */
        Uint32 curTickEmergelifeComb = SDL_GetTicks();
        Uint32 diffEmergelifeComb = curTickEmergelifeComb - lastTickEmergelifeComb;
        if(diffEmergelifeComb>fpsEmergeLifeComb){
            lastTickEmergelifeComb = curTickEmergelifeComb;
            emergelifeComb();    
        }

        /* --------  Surgimento da estrela especial -------- */
        Uint32 curTickEmergespecialStar = SDL_GetTicks();
        Uint32 diffEmergespecialStar = curTickEmergespecialStar - lastTickEmergespecialStar;
        if(diffEmergespecialStar>fpsEmergespecialStar){
            lastTickEmergespecialStar = curTickEmergespecialStar;
            emergestar();
        }

        /* -------- Tempo de duração do laser especial -------- */
        Uint32 curTickspecialLaser = SDL_GetTicks();
        Uint32 diffspecialLaser = curTickspecialLaser - lastGetspecialStar;
        if(diffspecialLaser > fpsspecialLaser){
            ship1.specialLaser = 0;
        }

        /* -------- Tempo para disparos dos lasers do Boss -------- */
        Uint32 curTickEnemieBossShooting = SDL_GetTicks();
        Uint32 diffEnemieBossShooting = curTickEnemieBossShooting - lastTickEnemieBossShooting;
        if(diffEnemieBossShooting > fpsEnemieBossWhileShoot){
            bossShooting = 0; //parar disparos
        }
        if(diffEnemieBossShooting > fpsEnemieBossShooting){
            lastTickEnemieBossShooting = curTickEnemieBossShooting;
            bossShooting = 1; //iniciar disparos
        }




        /* ------------------------------ MOVIMENTAÇÃO LASERS ------------------------------ */
        
        //Movimentação dos lasers da Nave
        for(int i=0;i<MAX_LASERS;i++){
            if(lasers[i].element.sizeImg.y < 0 - lasers[i].element.sizeImg.h){
                lasers[i].status = 0;
            } else {
                lasers[i].element.sizeImg.y -= LASER_MOVE_SPEED;
            }
        }

        //Movimentação dos lasers do Chefão
        for(int i=0;i<MAX_ENEMIEBOSSLASERS;i++){
            if(enemieBossLasers[i].element.sizeImg.y > HEIGHT){
                enemieBossLasers[i].status = 0;
            } else {
                enemieBossLasers[i].element.sizeImg.y += BOSSENEMIELASER_MOVE_SPEED;
            }
        }



        /* ---------------------------------- COLISÕES ------------------------------------- */

        midShip1.sizeImg = updateMid(ship1.element, heightShipWithoutShadow);

        /* -------- Colisão dos lasers da Nave com os Inimigos -------- */
        for(int i=0; i<MAX_ENEMIES; i++){
            for(int j=0; j<MAX_LASERS; j++){
                if(lasers[j].status == 1 && enemies[i].status == 1){
                    if(SDL_HasIntersection(&lasers[j].element.sizeImg, &enemies[i].element.sizeImg)){
                        effectsCollisionShipLasersAndEnemie();

                        enemies[i].heart -= lasers[j].lifeTaken;

                        wExplosion = enemies[i].element.sizeImg.w * 0.3;
                        hExplosion = enemies[i].element.sizeImg.h * 0.3;
                        explosionPoint = createRect(
                            lasers[j].element.sizeImg.x - wExplosion/2 + lasers[j].element.sizeImg.w/2,
                            enemies[i].element.sizeImg.y + enemies[i].element.sizeImg.h - hExplosion,
                            wExplosion,
                            hExplosion
                        );
                        updateArrayExplosionsGeneric(explosionPoint);

                        if(enemies[i].heart<=0){
                            effectsEnemyDowned();
                            updateArrayExplosions(enemies[i].element.sizeImg);
                            enemies[i].status = 0;
                            ponto_jogador += ponto_por_inimigo;
                            deadEnemies++;
                        }
                        lasers[j].status = 0;
                        efeitos_jogo(10);
                    }
                }
            }
        }

        /* -------- Colisão da Nave com os Inimigos -------- */
        for(int i=0; i<MAX_ENEMIES; i++){
            if(SDL_HasIntersection(&midShip1.sizeImg, &enemies[i].element.sizeImg) && enemies[i].status==1){
                effectsCollisionShipAndEnemie();
                enemies[i].status = 0;
                updateArrayExplosions(ship1.element.sizeImg);
                decreaseLife(janela, renderer, initialLife/5);
                efeitos_jogo(10);
            }
        }

        /* -------- Colisão da Nave com o Tanque de Combustivel -------- */
        if(SDL_HasIntersection(&midShip1.sizeImg, &lifeComb.sizeImg) && lifeComb.status==1){
            effectsCollisionShipAndLifecomb();
            lifeComb.status = 0;
            life.cut.y = 0;
            ship1.life = initialLife;
            ponto_jogador += ponto_por_Lifecomb;
        }

        /* -------- Colisão da Nave com a Estrela Especial -------- */
        if(SDL_HasIntersection(&midShip1.sizeImg, &specialStar.sizeImg) && specialStar.status==1){
            effectsCollisionShipAndSpecialStar();
            specialStar.status = 0;
            lastGetspecialStar = SDL_GetTicks();
            ship1.specialLaser = 1;
            ponto_jogador += ponto_por_specialStar;
        }

        /* -------- Colisão dos lasers do Chefão com a Nave -------- */
        for(int j=0; j<MAX_ENEMIEBOSSLASERS ; j++){
            if(enemieBossLasers[j].status == 1){
                if(SDL_HasIntersection(&enemieBossLasers[j].element.sizeImg, &midShip1.sizeImg)){
                    
                    effectsCollisionShipAndBossLasers();

                    wExplosion = ship1.element.sizeImg.w * 0.5;
                    hExplosion = heightShipWithoutShadow * 0.5;
                    explosionPoint = createRect(
                        enemieBossLasers[j].element.sizeImg.x - wExplosion/2 + lasers[j].element.sizeImg.w/2,
                        ship1.element.sizeImg.y + heightShipWithoutShadow/2 - hExplosion/2,
                        wExplosion,
                        hExplosion
                    );
                    updateArrayExplosionsGeneric(explosionPoint);

                    enemieBossLasers[j].status = 0;
                    decreaseLife(janela, renderer, enemieBossLasers[j].lifeTaken);
                    efeitos_jogo(10);
                }
            }
        }

        /* -------- Colisão dos lasers da Nave com o Chefão -------- */
        for(int j=0; j<MAX_LASERS; j++){
            if(lasers[j].status == 1 && enemieBoss.status == 1){
                if(SDL_HasIntersection(&lasers[j].element.sizeImg, &enemieBoss.element.sizeImg)){
                    effectsCollisionShipLasersAndBoss();

                    enemieBoss.heart -= lasers[j].lifeTaken;

                    wExplosion = enemieBoss.element.sizeImg.w * 0.16;
                    hExplosion = enemieBoss.element.sizeImg.h * 0.2;
                    explosionPoint = createRect(
                        lasers[j].element.sizeImg.x - wExplosion/2 + lasers[j].element.sizeImg.w/2,
                        enemieBoss.element.sizeImg.y + enemieBoss.element.sizeImg.h - hExplosion,
                        wExplosion,
                        hExplosion
                    );
                    updateArrayExplosionsGeneric(explosionPoint);

                    if(enemieBoss.heart<=0){
                        updateArrayExplosionsGeneric(enemieBoss.element.sizeImg);
                        enemieBoss.status = 0;
                        ponto_jogador += ponto_por_inimigo;
                    }

                    lasers[j].status = 0;
                }
            }
        }

        /* --------------------------------- AÇÕES TECLADO --------------------------------- */

        if(keyboardState[SDL_SCANCODE_LEFT]){
            if(ship1.element.sizeImg.x > MARGIN)
                ship1.element.sizeImg.x -= SHIP_MOVE_SPEED;
            ship1.element.cut = createRect(0,0,19,71);          
        }
        else {
            ship1.element.cut = createRect(45,0,29,71);
        }
        
        if(keyboardState[SDL_SCANCODE_RIGHT]){
            if(ship1.element.sizeImg.x < WIDTH - ship1.element.sizeImg.w - MARGIN)
                ship1.element.sizeImg.x += SHIP_MOVE_SPEED;
            ship1.element.cut = createRect(99,0,19,71);
        } 

        int newTopMargin = TOPMARGIN;
        if(keyboardState[SDL_SCANCODE_UP]){
            if(enemieBoss.status == 1){
                newTopMargin += enemieBoss.element.sizeImg.h + MARGIN;
            }
            if(ship1.element.sizeImg.y > newTopMargin)
                ship1.element.sizeImg.y -= SHIP_MOVE_SPEED;
        }

        if(keyboardState[SDL_SCANCODE_DOWN]){
            if(ship1.element.sizeImg.y < HEIGHT - heightShipWithoutShadow - MARGIN)
                ship1.element.sizeImg.y += SHIP_MOVE_SPEED;
        }

        /* --------------------------------- RENDERIZAÇÃO --------------------------------- */
        
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, scenery.Texture, &scenery.cut, &scenery.sizeImg);

        for(int i=0;i<MAX_LASERS;i++){
            if(lasers[i].status==1){
                SDL_RenderCopy(renderer, lasers[i].element.Texture, &lasers[i].element.cut, &lasers[i].element.sizeImg);
            }
        }

        for(int i=0;i<MAX_ENEMIEBOSSLASERS;i++){
            if(enemieBossLasers[i].status==1){
                SDL_RenderCopy(renderer, enemieBossLasers[i].element.Texture, &enemieBossLasers[i].element.cut, &enemieBossLasers[i].element.sizeImg);
            }
        }

        for(int i=0;i<MAX_ENEMIES;i++){
            if(enemies[i].status==1){
                SDL_RenderCopy(renderer, enemies[i].element.Texture, &enemies[i].element.cut, &enemies[i].element.sizeImg);
            } 
            
        }

        if(lifeComb.status==1){
            SDL_RenderCopy(renderer, lifeComb.Texture, &lifeComb.cut, &lifeComb.sizeImg);
        }

        if(specialStar.status==1){
            SDL_RenderCopy(renderer, specialStar.Texture, &specialStar.cut, &specialStar.sizeImg);
        }

        SDL_RenderCopy(renderer, ship1.element.Texture, &ship1.element.cut, &ship1.element.sizeImg);

        if(enemieBoss.status==1){
            SDL_RenderCopy(renderer, enemieBoss.element.Texture, &enemieBoss.element.cut, &enemieBoss.element.sizeImg);
        }
    
        //SDL_RenderCopy(renderer, midShip1.Texture, &midShip1.cut, &midShip1.sizeImg);

        for(int i=0;i<MAX_EXPLOSIONS;i++){
            if(explosions[i].status==1){
                SDL_RenderCopy(renderer, explosions[i].Texture, &explosions[i].cut, &explosions[i].sizeImg);
            }
        }
        
        SDL_RenderCopy(renderer, life.Texture, &life.cut, &life.sizeImg);
        
        SDL_RenderCopy(renderer, score.Texture, &score.cut, &score.sizeImg);
        
        SDL_RenderPresent(renderer);

    }
    return;
}



void take_off(SDL_Window *janela, SDL_Renderer *renderer)
{
    /*
    aircraft_carrier = setElement(
        "aircraft_carrier",
        IMG_Load("png/trans3.png"),
        createRect(0,0,1440,900),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );

    up_ship1 = setElement(
        "up_ship1",
        IMG_Load("png/trans3-1.png"),
        createRect(0,0,1440,1440),   //cut: x, y, w, h
        createRect(0,0,WIDTH,1440) //sizeImg: x, y, w, h
    );
    */
    decolar[0] = setElement(
        "decolar[0]",
        IMG_Load("png/decolar1.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );

    decolar[1] = setElement(
        "decolar[1]",
        IMG_Load("png/decolar2.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[2] = setElement(
        "decolar[2]",
        IMG_Load("png/decolar3.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[3] = setElement(
        "decolar[3]",
        IMG_Load("png/decolar4.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[4] = setElement(
        "decolar[4]",
        IMG_Load("png/decolar5.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[5] = setElement(
        "decolar[5]",
        IMG_Load("png/decolar6.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[6] = setElement(
        "decolar[6]",
        IMG_Load("png/decolar7.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[7] = setElement(
        "decolar[7]",
        IMG_Load("png/decolar8.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[8] = setElement(
        "decolar[8]",
        IMG_Load("png/decolar9.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[9] = setElement(
        "decolar[9]",
        IMG_Load("png/decolar10.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    
    decolar[10] = setElement(
        "decolar[1]",
        IMG_Load("png/decolar11.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[11] = setElement(
        "decolar[11]",
        IMG_Load("png/decolar12.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[12] = setElement(
        "decolar[12]",
        IMG_Load("png/decolar13.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[13] = setElement(
        "decolar[13]",
        IMG_Load("png/decolar14.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[14] = setElement(
        "decolar[14]",
        IMG_Load("png/decolar15.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[15] = setElement(
        "decolar[15]",
        IMG_Load("png/decolar16.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[16] = setElement(
        "decolar[16]",
        IMG_Load("png/decolar17.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[17] = setElement(
        "decolar[17]",
        IMG_Load("png/decolar18.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[18] = setElement(
        "decolar[18]",
        IMG_Load("png/decolar19.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[19] = setElement(
        "decolar[19]",
        IMG_Load("png/decolar20.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[20] = setElement(
        "decolar[20]",
        IMG_Load("png/decolar21.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[21] = setElement(
        "decolar[21]",
        IMG_Load("png/decolar22.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[22] = setElement(
        "decolar[22]",
        IMG_Load("png/decolar23.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[23] = setElement(
        "decolar[23]",
        IMG_Load("png/decolar24.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[24] = setElement(
        "decolar[24]",
        IMG_Load("png/decolar25.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );
    decolar[25] = setElement(
        "decolar[25]",
        IMG_Load("png/decolar26.png"),
        createRect(0,0,1920,1080),   //cut: x, y, w, h
        createRect(0,0,WIDTH,HEIGHT) //sizeImg: x, y, w, h
    );

    int a = 0;
    while(1)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
                case SDL_QUIT:
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(janela);
                    SDL_Quit();
                    return;
                    break;

                case SDL_KEYDOWN:
                    switch(event.key.keysym.scancode)
                    {
                        case SDL_SCANCODE_ESCAPE:
                            playSound(0);
                            gameTitle(janela, renderer);
                            return;
                            break;

                        case SDL_SCANCODE_RETURN:
                            game(janela, renderer);
                            return;
                            break;

                    }
                    break;

            }
        }

        a++;
        if(a>=26)
        {
            game(janela, renderer);
            return;
            break;
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, decolar[a].Texture, &decolar[a].cut, &decolar[a].sizeImg);
        //SDL_RenderCopy(renderer, aircraft_carrier.Texture, &aircraft_carrier.cut, &aircraft_carrier.sizeImg);
        //SDL_RenderCopy(renderer, up_ship1.Texture, &up_ship1.cut, &up_ship1.sizeImg);
        SDL_RenderPresent(renderer);
        SDL_Delay(125);

    }
    return;
}
