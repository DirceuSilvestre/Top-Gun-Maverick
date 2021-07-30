//Configurações da nave
float SHIP_MOVE_SPEED1 = 6;
float LASER_MOVE_SPEED1 = 20;
int lifeTakenShipLaser11 = 1;
int lifeTakenShipLaser21 = 2;

//Configurações do tanque de combustível e da estrela
float LIFECOMB_MOVE_SPEED1 = 10;
float SPECIALSTAR_MOVE_SPEED1 = 10;

//Configurações dos inimigos
int enemieHeart1 = 2;
float ENEMIE_MOVE_SPEED1 = 40;

//Configurações das bombas
int bombHeart1 = 1;
float BOMB_MOVE_SPEED1 = 60; //esse valor aqui, indico não diminuir pq pode dar problema

//Configurações do Chefão
int bossHeart1 = 120;
int lifeTakenBossLaser11 = 3;
float BOSSENEMIELASER_MOVE_SPEED1 = 15;
float BOSSENEMIE_MOVE_SPEED1 = 2;
float BOSSENEMIE_MOVE_SPEED_VERTICAL1 = 5;

//Total de inimigos mortos pro chefão surgir
int totalDeadEnemiesToFinalBoss1 = 60; 

//Total de inimigos mortos pras bombas surgirem
int totalDeadEnemiesToStartBombs1 = 25; //(tem que ser menor que o totalDeadEnemiesToFinalBoss)

//Diminuição do score a cada inimigo destruído
int ponto_por_inimigo1 = 100;
int ponto_por_Lifecomb1 = 50; 
int ponto_por_specialStar1 = 50; 

/* Não pode alterar */
float heightShipWithoutShadow1;
int initialLife1 = 100;
float MARGIN1 = 0.005 * WIDTH;
float TOPMARGIN1 = 0.005 * WIDTH + HEIGHT*0.1;
int lastIndexOfLasers1 = 0;
int lastIndexOfExplosions1 = 0;
int lastIndexOfEnemieBossLasers1 = 0;
int deadEnemies1 = 0; 
int bossShooting1 = 0;
int stopShip1Lasers1 = 0;
float wExplosion1;
float hExplosion1;
int startBombs1 = 0;
int contador1 = 0;

/* ----------------- FUNÇÕES PRA VOCÊ COLOCAR AS MÚSICAS E EFEITOS QUE QUISER ----------------- */

void effectsCallBoss1(void){
    //efeitos para quando a fase do Chefão inicia
    playRadio(7); //(coloquei uma musica qualquer, pode mudar)
}

void effectsCallBombs1(void){
    //efeitos para quando a fase das Bombas inicia
    playRadio(6); //(coloquei uma musica qualquer, pode mudar)
}

void effectsCollisionShipAndEnemie1(void){
    //efeitos para quando a Nave e um Inimigo colidem
}

void effectsCollisionShipAndLifecomb1(void){
    //efeitos para quando a Nave e o Tanque de Combustível colidem
    playSound(3);
}

void effectsCollisionShipAndSpecialStar1(void){
    //efeitos para quando a Nave e a Estrela Especial colidem
    playSound(3);
}

void effectsCollisionShipAndBossLasers1(void){
    //efeitos para quando a Nave e os Lasers do Chefão colidem
}

void effectsCollisionShipLasersAndEnemie1(void){
    //efeitos para quando os Lasers da Nave e os Inimigos colidem
}

void effectsCollisionShipLasersAndBoss1(void){
    //efeitos para quando os Lasers da Nave e o Chefão colidem
}

void effectsShootLaser11(void){
    //efeitos para quando o laser menor é disparado
    playSound(5);
}

void effectsShootLaser21(void){
    //efeitos para quando o laser maior é disparado
    playSound(5);
}

void effectsEnemyDowned1(void){
    //efeitos pra quando um inimigo é destruído
} 

void callGameOver1(SDL_Window *janela, SDL_Renderer *renderer){
    //ações para quando o jogador perde
    efeitos_jogo(2);
    gameover(janela, renderer);
}

void callWin1(SDL_Window *janela, SDL_Renderer *renderer){
    //ações para quando o jogador ganha
}



/* -------------------------------------- FUNÇÕES DO JOGO -------------------------------------- */

void clearAll1(void){
    for(int j=0; j<MAX_ENEMIES1; j++){
        if(enemies[j].status == 1){
            enemies[j].status = 0;
        }
    }

    for(int j=0; j<MAX_LASERS1; j++){
        if(lasers[j].status == 1){
            lasers[j].status = 0;
        }
    }

    if(enemieBoss.status == 1) {
        enemieBoss.status = 0;
    }

    for(int j=0; j<MAX_ENEMIEBOSSLASERS1; j++){
        if(enemieBossLasers[j].status == 1){
            enemieBossLasers[j].status = 0;
        }
    }

    for(int j=0; j<MAX_EXPLOSIONS1; j++){
        if(explosions[j].status == 1){
            explosions[j].status = 0;
        }
    }
}


DestructiveObject createLaser22(char * name, char * fileName, int lifeTaken, float xLaser, float yLaser, float wLaser, float hLaser){
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

DestructiveObject createLaser11(void){
    effectsShootLaser11();
    return createLaser22(
        "laser1",
        "png/Laser1-1.png",
        lifeTakenShipLaser11, 
        ship1.element.sizeImg.x + ship1.element.sizeImg.w/2 - ship1.element.sizeImg.w*0.3/3,
        ship1.element.sizeImg.y,
        ship1.element.sizeImg.w*0.3,
        heightShipWithoutShadow*0.9
    );
}

DestructiveObject createLaser21(void){
    effectsShootLaser21();
    return createLaser(
        "laser2",
        "png/Laser1-2.png",
        lifeTakenShipLaser21,
        ship1.element.sizeImg.x + ship1.element.sizeImg.w/2 - ship1.element.sizeImg.w*0.3/2,
        ship1.element.sizeImg.y,
        ship1.element.sizeImg.w*0.3,
        heightShipWithoutShadow*0.9
    );
}

DestructiveObject createEnemieBossLaser11(float xEnemieBossLaser){
    effectsShootLaser11();
    return createLaser22(
        "bossLaser1",
        "png/Laser2-1.png",
        lifeTakenBossLaser11, 
        xEnemieBossLaser,
        enemieBoss.element.sizeImg.y + (enemieBoss.element.sizeImg.h - heightShipWithoutShadow*0.9),
        ship1.element.sizeImg.w*0.3,
        heightShipWithoutShadow*0.9
    );
}

DestructiveObject createEnemieBossLaser1Left1(void){
    return createEnemieBossLaser1(enemieBoss.element.sizeImg.x + enemieBoss.element.sizeImg.w/4);
}

DestructiveObject createEnemieBossLaser1Right1(void){
    return createEnemieBossLaser1(enemieBoss.element.sizeImg.x + enemieBoss.element.sizeImg.w/4 + enemieBoss.element.sizeImg.w/2);
}


Element createExplosion1(float x, float y, float w, float h){
    Element explosion = setElement(
            "explosion",
            IMG_Load("png/explosao.png"),
            createRect(0,0,64,64),
            createRect(x,y,w,h)
        );
    explosion.status = 1;
    return explosion;
}

void updateArrayExplosions1(SDL_Rect explodedSizeImg){
    explosions[lastIndexOfExplosions] = createExplosion1(
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

void updateArrayExplosionsGeneric1(SDL_Rect explodedSizeImg){
    explosions[lastIndexOfExplosions] = createExplosion1(
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

void emergeBombs1(float targetX, float targetY, float targetW, float targetH){
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
    if(startBombs1==1){
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
            bombHeart1,
            directionXBomb,
            0
        );
        enemies[3].status = 1;
    }
}

/* -------- A função cria 3 inimigos para atacar a nave de acordo com a posição X da nave (targetXandW) -------- */
void emergeEnemies1(float targetX, float targetY, float targetW, float targetH){
    if(deadEnemies >= totalDeadEnemiesToFinalBoss1){
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
                enemieHeart1,
                directionXEnemie,
                1
            );
        }
    }
    enemies[randomNumberEnemie].status=1;

    //emergeBombs(targetX, targetY, targetW, targetH);
}

void decreaseLife1(SDL_Window *janela, SDL_Renderer *renderer, int decrease){
    ship1.life -= decrease;
    //printf("ship1.life : %d\n",ship1.life);
    if(ship1.life % (initialLife/5) == 0){
        if(ship1.life > 0){ //life.cut.y < 78 * 4
            life.cut.y += 78;
        } else {
            //Game over
            clearAll1();
            callGameOver1(janela,renderer);
        }
    }
}

void emergestar1(void){
    specialStar.status = 1;
    specialStar.sizeImg.y = 0;
    int limitespecialStar = WIDTH - specialStar.sizeImg.w - MARGIN;
    int randomNumberspecialStar = rand()% (limitespecialStar);
    specialStar.sizeImg.x = (float) randomNumberspecialStar + MARGIN;    
}

void emergelifeComb1(void){
    lifeComb.status = 1;
    lifeComb.sizeImg.y = 0;
    int limitelifeComb = WIDTH - lifeComb.sizeImg.w - MARGIN;
    int randomNumberlifeComb = rand()% (limitelifeComb);
    lifeComb.sizeImg.x = (float) randomNumberlifeComb + MARGIN; 
}

//Atualiza a posição central da nave
SDL_Rect updateMid1(Element objectElement, float heightObject){
    float wMid = objectElement.sizeImg.w * 0.5;
    return createRect(
        objectElement.sizeImg.x + objectElement.sizeImg.w/2 - wMid/2 ,
        objectElement.sizeImg.y,
        wMid,
        heightObject
    );
}

int coinFlipAddicted1(){
    // quanto maior o número no switch, menor a probabilidade de vir -1
    switch(rand()% 15){
        case 0:
            return -1;
            break;
        default:
            return 1;
    }
}

void simulador(SDL_Window *janela, SDL_Renderer *renderer)
{
    char desvie[] = "desvie com as setas", atire[]= "atire usando z", jogar[] = "Quer jogar?", sim1[] = "sim (J)", nao1[] = "nao (K)";

    mensagem1 = setElement( //texto1 = game over
        "mensagem1",
        TTF_RenderText_Solid(fonte, desvie, color_black),
        createRect(0, 0, 19*48, 50),
        createRect(WIDTH/12, 120, 10 * WIDTH/12, 0.20 * HEIGHT)
    );

    mensagem2 = setElement( //texto1 = game over
        "mensagem2",
        TTF_RenderText_Solid(fonte, atire, color_black),
        createRect(0, 0, 14*48, 50),
        createRect(WIDTH/12, 120, 10 * WIDTH/12, 0.20 * HEIGHT)
    );

    mensagem3 = setElement( //texto1 = game over
        "mensagem3",
        TTF_RenderText_Solid(fonte1, jogar, color_black),
        createRect(0, 0, 11*48, 65),
        createRect(WIDTH/12, 120, 10 * WIDTH/12, 0.20 * HEIGHT)
    );

    mensagem4 = setElement( //texto1 = sim
        "mensagem4",
        TTF_RenderText_Solid(fonte1, sim1, color_black),
        createRect(0, 0, 7*48, 60),
        createRect(WIDTH/12, mensagem3.sizeImg.y + 230, 4 * WIDTH/12, 0.10 * HEIGHT)
    );

    mensagem5 = setElement( //texto1 = nao
        "mensagem5",
        TTF_RenderText_Solid(fonte1, nao1, color_black),
        createRect(0, 0, 7*48, 60),
        createRect(7 * WIDTH/12, mensagem3.sizeImg.y + 230, 4 * WIDTH/12, 0.10 * HEIGHT)
    );

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
    float wenemieBoss = 5 * ship1.element.sizeImg.w;
    float henemieBoss = 3 * heightShipWithoutShadow;
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
        bossHeart1,
        directionXenemieBoss,
        0
    );

    /* -------- Pontuação -------- */
    //char pontos[7];
    //int ponto_jogador = 100000;
    
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

        /* ------------------------------------ MÚSICA ------------------------------------ */
        if(Mix_PlayingMusic() == 0){
            random_song();
        }


        /* --------------------------- PEGAR O ESTADO DO TECLADO --------------------------- */
        const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);


        /* -------------------------- VERIFICA SE DEVE INICIAR A FASE DO CHEFÃO  -------------------------- 
        if(deadEnemies >= totalDeadEnemiesToFinalBoss && enemieBoss.heart > 0 && enemieBoss.status == 0){
            enemieBoss.status = 1;
            effectsCallBoss();
        }

        /* -------------------------- VERIFICA SE DEVE INICIAR A FASE DAS BOMBAS  -------------------------- 
        if(deadEnemies >= totalDeadEnemiesToStartBombs1 && enemieBoss.status == 0 && startBombs == 0){
            startBombs = 1;
            effectsCallBombs();
        }
        */

        /* ------------------------------- SISTEMAS DE TEMPO ------------------------------- */

        /* -------- Fps do jogo -------- */
        Uint32 curTick = SDL_GetTicks();
        Uint32 diff = curTick - lastTick;
        if(diff>fps){
            /* -------- Atualizando sistema de tempo para o fps -------- */
            lastTick = curTick;

            /* -------- Movimentação de cenário -------- */
            scenery.cut.y -= 4;
            if(scenery.cut.y < 0){
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
            //sprintf(pontos, "%d", ponto_jogador);
            /*score = setElement(
                "score",
                TTF_RenderText_Solid(fonte1, pontos, color),
                createRect(0, 0, 6*48, 50),
                createRect(0.220 * WIDTH, 0.025 * HEIGHT, 6 * 0.028 * WIDTH, 0.062 * HEIGHT)
            );

            /* -------- Movimentação dos Inimigos -------- */
            for(int i=0;i<MAX_ENEMIES1;i++){
                if(enemies[i].status == 1){
                    if(enemies[i].element.sizeImg.y > HEIGHT ){
                        enemies[i].status = 0;
                    } else {
                        float move_speed;
                        if( strcmp(enemies[i].element.name, "enemie") == 0 ){
                            move_speed = ENEMIE_MOVE_SPEED1;
                        }
                        if( strcmp(enemies[i].element.name, "enemieBomb") == 0 ){
                            move_speed = BOMB_MOVE_SPEED1;
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
                lifeComb.sizeImg.y += LIFECOMB_MOVE_SPEED1;
            }

            /* -------- Movimentação da estrela -------- */
            if(specialStar.sizeImg.y > HEIGHT){
                specialStar.status = 0;
            } else {
                specialStar.sizeImg.y += SPECIALSTAR_MOVE_SPEED1;
            }

            /* -------- Movimentação das explosões -------- */
            for(int i=0; i<MAX_EXPLOSIONS1; i++){
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
                if(enemieBoss.element.sizeImg.y < TOPMARGIN1){
                    stopShip1Lasers = 1;
                    enemieBoss.element.sizeImg.y += BOSSENEMIE_MOVE_SPEED_VERTICAL1;
                } else {
                    stopShip1Lasers = 0;
                    if(bossShooting == 0){
                        /* -------- Movimentação horizontal do Boss -------- */
                        enemieBoss.element.sizeImg.x += enemieBoss.directionX * ENEMIE_MOVE_SPEED1;
                        if(enemieBoss.element.sizeImg.x > WIDTH - enemieBoss.element.sizeImg.w - MARGIN
                            || enemieBoss.element.sizeImg.x < MARGIN){
                            enemieBoss.directionX *= -1;
                        } else {
                            enemieBoss.directionX *= coinFlipAddicted1();
                        }
                    } else {
                        /* -------- Disparos do Boss -------- */
                        enemieBossLasers[lastIndexOfEnemieBossLasers] = createEnemieBossLaser1Left1(); lastIndexOfEnemieBossLasers++;
                        enemieBossLasers[lastIndexOfEnemieBossLasers] = createEnemieBossLaser1Right1(); lastIndexOfEnemieBossLasers++;
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
        if(diffNewEnemies>newEnemies1){
            lastTickNewEnemies = curTickNewEnemies;
            emergeEnemies1(ship1.element.sizeImg.x, ship1.element.sizeImg.y, ship1.element.sizeImg.w, ship1.element.sizeImg.h);
        }

        /* --------  Surgimento de novas bombas -------- */
        Uint32 curTickNewBombs = SDL_GetTicks();
        Uint32 diffNewBombs = curTickNewBombs - lastTickNewBombs;
        if(diffNewBombs>newBombs){
            lastTickNewBombs = curTickNewBombs;
            emergeBombs1(ship1.element.sizeImg.x, ship1.element.sizeImg.y, ship1.element.sizeImg.w, ship1.element.sizeImg.h);
        }

        /* --------  Surgimento de tanques de gasolina -------- */
        Uint32 curTickEmergelifeComb = SDL_GetTicks();
        Uint32 diffEmergelifeComb = curTickEmergelifeComb - lastTickEmergelifeComb;
        if(diffEmergelifeComb>fpsEmergeLifeComb){
            lastTickEmergelifeComb = curTickEmergelifeComb;
            emergelifeComb1();    
        }

        /* --------  Surgimento da estrela especial -------- */
        Uint32 curTickEmergespecialStar = SDL_GetTicks();
        Uint32 diffEmergespecialStar = curTickEmergespecialStar - lastTickEmergespecialStar;
        if(diffEmergespecialStar>fpsEmergespecialStar){
            lastTickEmergespecialStar = curTickEmergespecialStar;
            emergestar1();
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
                lasers[i].element.sizeImg.y -= LASER_MOVE_SPEED1;
            }
        }

        //Movimentação dos lasers do Chefão
        for(int i=0;i<MAX_ENEMIEBOSSLASERS;i++){
            if(enemieBossLasers[i].element.sizeImg.y > HEIGHT){
                enemieBossLasers[i].status = 0;
            } else {
                enemieBossLasers[i].element.sizeImg.y += BOSSENEMIELASER_MOVE_SPEED1;
            }
        }



        /* ---------------------------------- COLISÕES ------------------------------------- */

        midShip1.sizeImg = updateMid1(ship1.element, heightShipWithoutShadow);

        /* -------- Colisão dos lasers da Nave com os Inimigos -------- */
        for(int i=0; i<MAX_ENEMIES; i++){
            for(int j=0; j<MAX_LASERS; j++){
                if(lasers[j].status == 1 && enemies[i].status == 1){
                    if(SDL_HasIntersection(&lasers[j].element.sizeImg, &enemies[i].element.sizeImg)){
                        effectsCollisionShipLasersAndEnemie1();

                        enemies[i].heart -= lasers[j].lifeTaken;

                        wExplosion = enemies[i].element.sizeImg.w * 0.3;
                        hExplosion = enemies[i].element.sizeImg.h * 0.3;
                        explosionPoint = createRect(
                            lasers[j].element.sizeImg.x - wExplosion/2 + lasers[j].element.sizeImg.w/2,
                            enemies[i].element.sizeImg.y + enemies[i].element.sizeImg.h - hExplosion,
                            wExplosion,
                            hExplosion
                        );
                        updateArrayExplosionsGeneric1(explosionPoint);

                        if(enemies[i].heart<=0){
                            effectsEnemyDowned1();
                            updateArrayExplosions1(enemies[i].element.sizeImg);
                            enemies[i].status = 0;
                            ponto_jogador += ponto_por_inimigo;
                            deadEnemies++;
                        }
                        lasers[j].status = 0;
                    }
                }
            }
        }

        /* -------- Colisão da Nave com os Inimigos -------- */
        for(int i=0; i<MAX_ENEMIES1; i++){
            if(SDL_HasIntersection(&midShip1.sizeImg, &enemies[i].element.sizeImg) && enemies[i].status==1){
                effectsCollisionShipAndEnemie1();
                enemies[i].status = 0;
                updateArrayExplosions1(ship1.element.sizeImg);
                decreaseLife1(janela, renderer, initialLife/5);
            }
        }

        /* -------- Colisão da Nave com o Tanque de Combustivel -------- */
        if(SDL_HasIntersection(&midShip1.sizeImg, &lifeComb.sizeImg) && lifeComb.status==1){
            effectsCollisionShipAndLifecomb1();
            lifeComb.status = 0;
            life.cut.y = 0;
            ship1.life = initialLife;
            ponto_jogador += ponto_por_Lifecomb;
        }

        /* -------- Colisão da Nave com a Estrela Especial -------- */
        if(SDL_HasIntersection(&midShip1.sizeImg, &specialStar.sizeImg) && specialStar.status==1){
            effectsCollisionShipAndSpecialStar1();
            specialStar.status = 0;
            lastGetspecialStar = SDL_GetTicks();
            ship1.specialLaser = 1;
            ponto_jogador += ponto_por_specialStar;
        }

        /* -------- Colisão dos lasers do Chefão com a Nave -------- */
        for(int j=0; j<MAX_ENEMIEBOSSLASERS1 ; j++){
            if(enemieBossLasers[j].status == 1){
                if(SDL_HasIntersection(&enemieBossLasers[j].element.sizeImg, &midShip1.sizeImg)){
                    
                    effectsCollisionShipAndBossLasers1();

                    wExplosion = ship1.element.sizeImg.w * 0.5;
                    hExplosion = heightShipWithoutShadow * 0.5;
                    explosionPoint = createRect(
                        enemieBossLasers[j].element.sizeImg.x - wExplosion/2 + lasers[j].element.sizeImg.w/2,
                        ship1.element.sizeImg.y + heightShipWithoutShadow/2 - hExplosion/2,
                        wExplosion,
                        hExplosion
                    );
                    updateArrayExplosionsGeneric1(explosionPoint);

                    enemieBossLasers[j].status = 0;
                    decreaseLife1(janela, renderer, enemieBossLasers[j].lifeTaken);
                }
            }
        }

        /* -------- Colisão dos lasers da Nave com o Chefão -------- */
        for(int j=0; j<MAX_LASERS; j++){
            if(lasers[j].status == 1 && enemieBoss.status == 1){
                if(SDL_HasIntersection(&lasers[j].element.sizeImg, &enemieBoss.element.sizeImg)){
                    effectsCollisionShipLasersAndBoss1();

                    enemieBoss.heart -= lasers[j].lifeTaken;

                    wExplosion = enemieBoss.element.sizeImg.w * 0.16;
                    hExplosion = enemieBoss.element.sizeImg.h * 0.2;
                    explosionPoint = createRect(
                        lasers[j].element.sizeImg.x - wExplosion/2 + lasers[j].element.sizeImg.w/2,
                        enemieBoss.element.sizeImg.y + enemieBoss.element.sizeImg.h - hExplosion,
                        wExplosion,
                        hExplosion
                    );
                    updateArrayExplosionsGeneric1(explosionPoint);

                    if(enemieBoss.heart<=0){
                        updateArrayExplosionsGeneric1(enemieBoss.element.sizeImg);
                        enemieBoss.status = 0;
                        ponto_jogador += ponto_por_inimigo;
                        callWin1(janela,renderer);
                    }

                    lasers[j].status = 0;
                }
            }
        }



        /* --------------------------------- AÇÕES TECLADO --------------------------------- */

        if(keyboardState[SDL_SCANCODE_LEFT]){
            if(ship1.element.sizeImg.x > MARGIN)
                ship1.element.sizeImg.x -= SHIP_MOVE_SPEED1;
            ship1.element.cut = createRect(0,0,19,71);          
        }
        else {
            ship1.element.cut = createRect(45,0,29,71);
        }
        
        if(keyboardState[SDL_SCANCODE_RIGHT]){
            if(ship1.element.sizeImg.x < WIDTH - ship1.element.sizeImg.w - MARGIN)
                ship1.element.sizeImg.x += SHIP_MOVE_SPEED1;
            ship1.element.cut = createRect(99,0,19,71);
        } 

        int newTopMargin = TOPMARGIN1;
        if(keyboardState[SDL_SCANCODE_UP]){
            if(enemieBoss.status == 1){
                newTopMargin += enemieBoss.element.sizeImg.h + MARGIN;
            }
            if(ship1.element.sizeImg.y > newTopMargin)
                ship1.element.sizeImg.y -= SHIP_MOVE_SPEED1;
        }

        if(keyboardState[SDL_SCANCODE_DOWN]){
            if(ship1.element.sizeImg.y < HEIGHT - heightShipWithoutShadow - MARGIN)
                ship1.element.sizeImg.y += SHIP_MOVE_SPEED1;
        }

        if(keyboardState[SDL_SCANCODE_J])
        {
            take_off(janela, renderer);
        }
        if(keyboardState[SDL_SCANCODE_K])
        {
            menu(janela, renderer);
        }



        /* --------------------------------- RENDERIZAÇÃO --------------------------------- */
        
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, scenery.Texture, &scenery.cut, &scenery.sizeImg);

        for(int i=0;i<MAX_LASERS1;i++){
            if(lasers[i].status==1){
                SDL_RenderCopy(renderer, lasers[i].element.Texture, &lasers[i].element.cut, &lasers[i].element.sizeImg);
            }
        }

        for(int i=0;i<MAX_ENEMIEBOSSLASERS1;i++){
            if(enemieBossLasers[i].status==1){
                SDL_RenderCopy(renderer, enemieBossLasers[i].element.Texture, &enemieBossLasers[i].element.cut, &enemieBossLasers[i].element.sizeImg);
            }
        }

        for(int i=0;i<MAX_ENEMIES1;i++){
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

        for(int i=0;i<MAX_EXPLOSIONS1;i++){
            if(explosions[i].status==1){
                SDL_RenderCopy(renderer, explosions[i].Texture, &explosions[i].cut, &explosions[i].sizeImg);
            }
        }
        
        SDL_RenderCopy(renderer, life.Texture, &life.cut, &life.sizeImg);
        
        SDL_RenderCopy(renderer, score.Texture, &score.cut, &score.sizeImg);

        contador1++;
        if (contador1 >= 0 && contador1 <= 540)
        {
            SDL_RenderCopy(renderer, mensagem1.Texture, &mensagem1.cut, &mensagem1.sizeImg);
        }

        if (contador1 >= 720 && contador1 <= 1260)
        {
            SDL_RenderCopy(renderer, mensagem2.Texture, &mensagem2.cut, &mensagem2.sizeImg);
        }

        if (contador1 > 1440)
        {
            SDL_RenderCopy(renderer, mensagem3.Texture, &mensagem3.cut, &mensagem3.sizeImg);
            SDL_RenderCopy(renderer, mensagem4.Texture, &mensagem4.cut, &mensagem4.sizeImg);
            SDL_RenderCopy(renderer, mensagem5.Texture, &mensagem5.cut, &mensagem5.sizeImg);
        }
        
        SDL_RenderPresent(renderer);

    }
    return;
}