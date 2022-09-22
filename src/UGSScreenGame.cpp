#include "UGSScreenGame.h"

UGSScreenGame::UGSScreenGame(Game1playerInfo* gameInfo){
    mPermissionToShow = true;

    std::stringstream ss;

    mBackButton = create_SFsprite("GUI/widgets/back.png");
    mBackButton.setPosition(1150, 10);
    mBGpb       = create_SFsprite("GUI/widgets/screenGame.png");
    mBackground = create_SFsprite("GUI/widgets/BackgroundGame.png");
    mBGpb.setColor(sf::Color(255,255,255,80));

    mTCC_BandBG = create_SFsprite("songs/" + std::to_string(gameInfo->folderCode) + "/picture/poster.png");
    mTCC_BandBG.setScale(0.49,0.49);
    mTCC_BandBG.setPosition(670+2000,130);
    mTCC_BandBG.setColor(sf::Color(255,255,255,160));

    mTCC_BangLogo = create_SFsprite("songs/" + std::to_string(gameInfo->folderCode) + "/picture/logo.png");
    mTCC_BangLogo.setScale(0.8,0.8);
    mTCC_BangLogo.setPosition(1120+2000,340);
    mTCC_BangLogo.setColor(sf::Color(255,255,255,230));

    std::string musicPath;
    std::string sequenceTilePath;
    std::string userName;
    std::string instrumentName;
    std::vector<int> backgrounCodes;
    int velocity;
    ss.str("");
    ss << "songs/" << gameInfo->folderCode << "/audio/"  << gameInfo->instrumentCode << ".ogg";
    musicPath        = ss.str();
    ss.str("");
    ss << "songs/" << gameInfo->folderCode << "/sequence/" << gameInfo->dificultyCode << "/" << gameInfo->instrumentCode << ".txt";
    sequenceTilePath = ss.str();
    userName         = "Player";
    instrumentName   = gameInfo->instrumentName;
    velocity         = gameInfo->speed;

    std::cout << "\n\n";
    std::cout << musicPath << "   music path\n";
    std::cout << sequenceTilePath << "   sequ path\n";
    std::cout << userName << "   user\n";
    std::cout << instrumentName << "   instrument\n";



    //mGameMajor = new UGSGameMajor(-500, 20, velocity, musicPath, sequenceTilePath, userName, instrumentName);
    mGameMajor = new UGSGameMajor(-500, 20, velocity, gameInfo->folderCode, musicPath, gameInfo->backgrounCodes, sequenceTilePath, userName, instrumentName);

    mView      = sf::View(sf::FloatRect(-500,17,500,654));
    mView.setViewport(sf::FloatRect(0.020,0.030,0.37,0.851));

    // ATEN��O: N�O PAGUE ESTE COMENT�RIO!!!
    // - Devido ao TCC, n�o usarei esse widget pois nao irei precisar dele.
    //mScoreMajor = new UGSScoreMajor(87,683);
    mScoreMajor = new UGSScoreMajor(-1000,683);

    mRock = new UGSRock(560,570);
    mRock->setBandName(gameInfo->bandName);
    mRock->setMusicName(gameInfo->misicName);
    //for(int i=0;i<100;i++){ /// COLOQUEI NO LACO FOR PRA EVITAR UM BUG. ELE SO INICIA CORRETAMENTE DEPOIS QUE SE COLOCA V�RIOS VALORES
    mRock->setRockStatus(50);
    //}

    // ATEN��O: N�O PAGUE ESTE COMENT�RIO!!!
    // - Devido ao TCC, n�o usarei esse widget pois nao irei precisar dele.
    //mNotasConsec = new UGSNotasConsecutivas(1085,586);
    mNotasConsec = new UGSNotasConsecutivas(3000,586);

    mMusicPlayer = new UGSMusicPlayer(570, 118);


    ia_logs = create_SFtext("c:/windows/fonts/consola.ttf", 28, sf::Color(255,255,255), "Marco Aurelio 02954");
    ia_logs.setPosition(sf::Vector2f(700,150));


}

UGSScreenGame::UGSScreenGame()
{
    mBGpb       = create_SFsprite("GUI/widgets/screenGame.png");
    mBackground = create_SFsprite("GUI/widgets/BackgroundGame.png");
    mBGpb.setColor(sf::Color(255,255,255,80));

//    mGameMajor = new UGSGameMajor(-500, 20, 8, "80mpm.ogg", "sequence.txt", "", "");

    mView      = sf::View(sf::FloatRect(-500,17,500,654));
    mView.setViewport(sf::FloatRect(0.020,0.030,0.37,0.851));

    mScoreMajor = new UGSScoreMajor(87,683);

    mRock = new UGSRock(560,570);
    for(int i=0;i<100;i++){ /// COLOQUEI NO LACO FOR PRA EVITAR UM BUG. ELE SO INICIA CORRETAMENTE DEPOIS QUE SE COLOCA V�RIOS VALORES
        mRock->setRockStatus(i);
    }

    mNotasConsec = new UGSNotasConsecutivas(1085,586);

    mMusicPlayer = new UGSMusicPlayer(570, 118);

    //ctor
}

UGSScreenGame::~UGSScreenGame()
{
    delete mGameMajor;
    delete mMusicPlayer;
    delete mScoreMajor;
    delete mRock;
    delete mNotasConsec;
    //dtor
}

void UGSScreenGame::draw(sf::RenderWindow& window){
    window.setView(window.getDefaultView());
    window.draw   (mBackground);


    /// Falta resolver o bug do triangulo quando a musica acaba!
    mMusicPlayer->setRange(mGameMajor->getMusicTimeTotal(), mGameMajor->getMusicTimeTotal() - mGameMajor->getMusicTimeCurrent() );//static_cast<float>(mGameMajor->getMusicTimeTotal()), static_cast<float>(mGameMajor->getMusicTimeCurrent()));
    mMusicPlayer->draw    (window);

    mScoreMajor->setScore   (mGameMajor->getScore());
    mScoreMajor->draw       (window);

    mRock->setRockStatus    (mGameMajor->getRock()*5);
    mRock->setScore         (mGameMajor->getScore());
    mRock->setMultiplicator (mGameMajor->getMultiplicator());
    mRock->draw             (window);


    mNotasConsec->draw(window);

    window.setView    (mView);
    mGameMajor->draw  (window);

    window.setView(window.getDefaultView());

    if(mouseColision(mBackButton, window)){
        mBackButton.setColor(sf::Color(255,255,255,255));
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            mPermissionToShow = false;
            mGameMajor->stopAudio();
        }
    } else {
        mBackButton.setColor(sf::Color(255,255,255,120));
    }
    window.draw(mBackButton);

    window.draw(mTCC_BandBG);
    window.draw(mTCC_BangLogo);

    window.draw(ia_logs);
}

bool UGSScreenGame::getPermissionToShow(){
    return mPermissionToShow;
}
