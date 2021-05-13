#include "headers.hpp"
#include "object/object.hpp"
#include "page/page.hpp"

const int pageNumber = 6;
const std::string pageNames[] = {"START", "SELECT", "GAME", "PAUSE", "END","DEVELOPERS"};

std::string pageName;
int pageID;

//处理pause
std::string prevPageName;

std::vector<Texture> textures;
std::vector<Sound> sounds; 
Object boardsMenu[MAXBOARDS];

//如何获胜
std::vector<int> WinMode1{1, 1, 5, 5, 6, 6, 5};
std::vector<int> WinMode2{4, 4, 3, 3, 2, 2, 1};
std::vector<int> WinMode3{5, 5, 4, 4, 3, 3, 2};
/*如果三关都获胜，会触发音乐*/
bool ifWin1;
bool ifWin2;
bool ifWin3;

void sourceLoader() {
    textures.clear();
    textures.push_back(LoadTexture("../resource/textures/circle25.png"));           // 0
    textures.push_back(LoadTexture("../resource/textures/square200.png"));          // 1
    textures.push_back(LoadTexture("../resource/textures/piano.png"));              // 2
    textures.push_back(LoadTexture("../resource/textures/pausebackground.png"));    // 3
    textures.push_back(LoadTexture("../resource/textures/square100.png"));          // 4
    textures.push_back(LoadTexture("../resource/textures/continue.png"));           // 5
    textures.push_back(LoadTexture("../resource/textures/circle_green.png"));       // 6
    textures.push_back(LoadTexture("../resource/textures/circle_red.png"));         // 7

    textures.push_back(LoadTexture("../resource/textures/C4-1.png"));
    textures.push_back(LoadTexture("../resource/textures/C4-2.png"));
    textures.push_back(LoadTexture("../resource/textures/C4-3.png"));
    textures.push_back(LoadTexture("../resource/textures/C4-4.png"));
    textures.push_back(LoadTexture("../resource/textures/C4-5.png"));
    textures.push_back(LoadTexture("../resource/textures/C4-6.png"));
    textures.push_back(LoadTexture("../resource/textures/C4-7.png"));
    textures.push_back(LoadTexture("../resource/textures/C5-1.png"));

    textures.push_back(LoadTexture("../resource/textures/end.png"));                // 16
    textures.push_back(LoadTexture("../resource/textures/note1.png"));
    textures.push_back(LoadTexture("../resource/textures/note2.png"));
    textures.push_back(LoadTexture("../resource/textures/note3.png"));
    textures.push_back(LoadTexture("../resource/textures/note4.png"));
    textures.push_back(LoadTexture("../resource/textures/note5.png"));              // 21

    sounds.clear();
    sounds.push_back(LoadSound("../resource/sounds/C4-1.mp3"));
    sounds.push_back(LoadSound("../resource/sounds/C4-2.mp3"));
    sounds.push_back(LoadSound("../resource/sounds/C4-3.mp3"));
    sounds.push_back(LoadSound("../resource/sounds/C4-4.mp3"));
    sounds.push_back(LoadSound("../resource/sounds/C4-5.mp3"));
    sounds.push_back(LoadSound("../resource/sounds/C4-6.mp3"));
    sounds.push_back(LoadSound("../resource/sounds/C4-7.mp3"));
    sounds.push_back(LoadSound("../resource/sounds/C5-1.mp3"));
    sounds.push_back(LoadSound("../resource/sounds/star.mp3"));
    sounds.push_back(LoadSound("../resource/sounds/HighQuality.mp3")); // 9

    Rectangle rec;
    rec.x = rec.y = 0.0f;
    rec.width = boardWidth, rec.width = boardHeight;

    for (int i = 0; i < 8; ++i) {
        boardsMenu[i] = Object(rec, 0.0f, i, 6 + i);
    }
}

Ball default_ball;
Object default_block;

page pages[pageNumber];

//创建开始界面的page
void initGameStartSceen(page &startpage){
    startpage.init();
    //Text Part:
    
    startpage.gameStart = true;

    //title
    Vector2 position;
    position.x = titleWidth;
    position.y = titleHeight;
    Text title("The Collision", position, titleFontSize, GOLD);
    startpage.texts.push_back(title);

    //Start
    Vector2 posForStart;
    posForStart.x = startWidth;
    posForStart.y = startHeight;
    Text start("START", posForStart, startFontSize, BLACK);
    startpage.texts.push_back(start);

    // //Setting
    // Vector2 posForSet;
    // posForSet.x = setWidth;
    // posForSet.y = setHeight;
    // Text setting("SETTING", posForSet, setFontSize, BLACK);
    // startpage.texts.push_back(setting);

    // //Exit
    // Vector2 posForExit;
    // posForExit.x = exitWidth;
    // posForExit.y = exitHeight;
    // Text exit("EXIT", posForExit, exitFontSize, BLACK);
    // startpage.texts.push_back(exit);

    // Select
    Vector2 posForSelect;
    posForSelect.x = selectWidth;
    posForSelect.y = selectHeight;
    Text select("SELECT", posForSelect, selectFontSize, BLACK);
    startpage.texts.push_back(select);

    // Developers
    Vector2 posForDevelopers;
    posForDevelopers.x = developersWidth;
    posForDevelopers.y = developersHeight;
    Text developers("DEVELOPERS", posForDevelopers, developerFontSize, BLACK);
    startpage.texts.push_back(developers);


    //Rectangle Part:
    //Start:
    Rectangle recForStart;
    recForStart.x = startRecWidth;
    recForStart.y = startRecHeight;
    recForStart.width = 200;
    recForStart.height = 200;
    rectangleButton startButton(recForStart, 1, "JUMP_GAME1");
    startpage.rtButtons.push_back(startButton);


    //Select:
    Rectangle recForSelect;
    recForSelect.x = selectRecWidth;
    recForSelect.y = selectRecHeight;
    recForSelect.width = 200;
    recForSelect.height = 200;
    rectangleButton selectButton(recForSelect, 1, "JUMP_SELECT");
    startpage.rtButtons.push_back(selectButton);

    //Developers:
    Rectangle recForDevelopers;
    recForDevelopers.x = developersRecWidth;
    recForDevelopers.y = developersRecHeight;
    recForDevelopers.width = 200;
    recForDevelopers.height = 200;
    rectangleButton developersButton(recForDevelopers, 4, "JUMP_DEVELOPERS");
    startpage.rtButtons.push_back(developersButton);

    //Balls Part:
    Vector2 posFormusic1;
    Vector2 posFormusic2;
    Vector2 posFormusic3;
    Vector2 posFormusic4;
    Vector2 posFormusic5;
    posFormusic1.x = 100;
    posFormusic1.y = 50;
    posFormusic2.x = 250;
    posFormusic2.y = 50;
    posFormusic3.x = 350;
    posFormusic3.y = 50;
    posFormusic4.x = 550;
    posFormusic4.y = 50;
    posFormusic5.x = 650;
    posFormusic5.y = 50;
    Vector2 vFormusic1;
    Vector2 vFormusic2;
    Vector2 vFormusic3;
    Vector2 vFormusic4;
    Vector2 vFormusic5;
    vFormusic1.x = 100;
    vFormusic1.y = 100;
    vFormusic2.x = 140;
    vFormusic2.y = 60;
    vFormusic3.x = 40;
    vFormusic3.y = 160;
    vFormusic4.x = 80;
    vFormusic4.y = 120;
    vFormusic5.x = 20;
    vFormusic5.y = 180;
    Ball musicNotation1(posFormusic1, ballSize, vFormusic1, 0, 30);
    Ball musicNotation2(posFormusic2, ballSize, vFormusic2, 0, 270);
    Ball musicNotation3(posFormusic3, ballSize, vFormusic3, 0, 50);
    Ball musicNotation4(posFormusic4, ballSize, vFormusic4, 0, 70);
    Ball musicNotation5(posFormusic5, ballSize, vFormusic5, 0, 120);
    startpage.balls.push_back(musicNotation1);
    startpage.balls.push_back(musicNotation2);
    startpage.balls.push_back(musicNotation3);
    startpage.balls.push_back(musicNotation4);
    startpage.balls.push_back(musicNotation5);

    //board
    Rectangle recForBelow;
    recForBelow.x = 0;
    recForBelow.y = 590;
    recForBelow.width = 800;
    recForBelow.height = 10;
    Rectangle recForAbove;
    recForAbove.x = 0;
    recForAbove.y = 0;
    recForAbove.width = 800;
    recForAbove.height = 10;
    Rectangle recForLeft;
    recForLeft.x = 10;
    recForLeft.y = 0;
    recForLeft.width = 600;
    recForLeft.height = 10;
    Rectangle recForRight;
    recForRight.x = 800;
    recForRight.y = 0;
    recForRight.width = 600;
    recForRight.height = 10;
    Object below(recForBelow, 0, 0, 0);
    Object above(recForAbove, 0, 0, 0);
    Object left(recForLeft, 90, 0, 0);
    Object right(recForRight, 90, 0, 0);
    startpage.boards.push_back(below);
    startpage.boards.push_back(above);
    startpage.boards.push_back(left);
    startpage.boards.push_back(right);

    //Music Notations Part:
    Rectangle recForBackMusic1;
    Rectangle recForBackMusic2;
    Rectangle recForBackMusic3;
    Rectangle recForBackMusic4;
    Rectangle recForBackMusic5;
    Rectangle recForBackMusic6;
    Rectangle recForBackMusic7;
    Rectangle recForBackMusic8;
}

//创建选择关卡界面的page
void initGameSelectSceen(page &selectpage){
    selectpage.init();
    
    selectpage.gameStart = true;

    PlaySoundMulti(sounds[8]);
    //Text Part:

    //title
    Vector2 position;
    position.x = selectTitleWidth;
    position.y = selectTitleHeight;
    Text selectTitle("PIANO", position, selectTitleFontSize, BLUE);
    selectpage.texts.push_back(selectTitle);

    //1.1
    Vector2 posFor1_1;
    posFor1_1.x = Width1_1;
    posFor1_1.y = Height1_1;
    Text game1_1("1 - 1", posFor1_1, FontSize1_1, BLACK);
    selectpage.texts.push_back(game1_1);

    //1.2
    Vector2 posFor1_2;
    posFor1_2.x = Width1_2;
    posFor1_2.y = Height1_2;
    Text game1_2("1 - 2", posFor1_2, FontSize1_2, BLACK);
    selectpage.texts.push_back(game1_2);

    //1.3
    Vector2 posFor1_3;
    posFor1_3.x = Width1_3;
    posFor1_3.y = Height1_3;
    Text game1_3("1 - 3", posFor1_3, FontSize1_3, BLACK);
    selectpage.texts.push_back(game1_3);

    //Rectangle Part:
    //1.1:
    Rectangle recFor1_1;
    recFor1_1.x = RecWidth1_1;
    recFor1_1.y = RecHeight1_1;
    recFor1_1.width = 200;
    recFor1_1.height = 200;
    rectangleButton Button1_1(recFor1_1, 1, "JUMP_GAME1");
    selectpage.rtButtons.push_back(Button1_1);

    //1.2:
    Rectangle recFor1_2;
    recFor1_2.x = RecWidth1_2;
    recFor1_2.y = RecHeight1_2;
    recFor1_2.width = 200;
    recFor1_2.height = 200;
    rectangleButton Button1_2(recFor1_2, 1, "JUMP_GAME2");
    selectpage.rtButtons.push_back(Button1_2);
    
    //1.3:
    Rectangle recFor1_3;
    recFor1_3.x = RecWidth1_3;
    recFor1_3.y = RecHeight1_3;
    recFor1_3.width = 200;
    recFor1_3.height = 200;
    rectangleButton Button1_3(recFor1_3, 1, "JUMP_GAME3");
    selectpage.rtButtons.push_back(Button1_3);

    Rectangle piano;
    piano.x = 0;
    piano.y = 0;
    piano.width = 800;
    piano.height = 300;
    rectangleButton backGround(piano, 2, "NONE");
    selectpage.rtButtons.push_back(backGround);
}

// 创建暂停菜单界面的page
void initGameMenuSceen(page &menupage){
    menupage.init();
    //Text Part:
    menupage.gameStart = true;

    //title
    Vector2 position;
    position.x = menuWidth;
    position.y = menuHeight;
    Text menu("MENU", position, menuFontSize, WHITE);
    menupage.texts.push_back(menu);

    //back to game
    Vector2 posForReturn;
    posForReturn.x = returnWidth;
    posForReturn.y = returnHeight;
    Text ret("BACK TO GAME", posForReturn, returnFontSize, WHITE);
    menupage.texts.push_back(ret);

    //return to main menu
    Vector2 posForMain;
    posForMain.x = mainWidth;
    posForMain.y = mainHeight;
    Text Mamenu("BACK TO MAIN", posForMain, mainFontSize, WHITE);
    menupage.texts.push_back(Mamenu);

    //Rectangle Part:
    //BACK TO GAME:
    Rectangle recForReturn;
    recForReturn.x = returnRecWidth;
    recForReturn.y = returnRecHeight;
    recForReturn.width = 600;
    recForReturn.height = 100;
    rectangleButton returnButton;
    if(prevPageName == "GAME1"){
        returnButton = rectangleButton(recForReturn, 1, "JUMP_GAME1");
    } else if(prevPageName == "GAME2"){
        returnButton = rectangleButton(recForReturn, 1, "JUMP_GAME2");
    } else if(prevPageName == "GAME3"){
        returnButton = rectangleButton(recForReturn, 1, "JUMP_GAME3");
    } else{
        returnButton = rectangleButton(recForReturn, 1, "JUMP_START");
    }
    menupage.rtButtons.push_back(returnButton);

    //BACK TO MAIN MENU:
    Rectangle recForMain;
    recForMain.x = mainRecWidth;
    recForMain.y = mainRecHeight;
    recForMain.width = 600;
    recForMain.height = 100;
    rectangleButton mainButton(recForMain, 1, "JUMP_START");
    menupage.rtButtons.push_back(mainButton);

    Rectangle background;
    background.x = 0;
    background.y = 0;
    background.width = 800;
    background.height = 600;
    rectangleButton backGround(background, 3, "NONE");
    menupage.rtButtons.push_back(backGround);
}

// 创建game界面的page
void initGameSceen(page &gamepage){
    gamepage.init();
    gamepage.gameStart = false;

    //Rectangle Part:
    //button1:
    Rectangle recForBt1;
    recForBt1.x = bt1Width;
    recForBt1.y = buttonHeight;
    recForBt1.width = 100;
    recForBt1.height = 100;
    rectangleButton Button1(recForBt1, 4, "GEN_BOARD0");
    rectangleButton Button1_(recForBt1, 8, "GEN_BOARD0");
    gamepage.rtButtons.push_back(Button1);
    gamepage.rtButtons.push_back(Button1_);

    //button2:
    Rectangle recForBt2;
    recForBt2.x = bt2Width;
    recForBt2.y = buttonHeight;
    recForBt2.width = 100;
    recForBt2.height = 100;
    rectangleButton Button2(recForBt2, 4, "GEN_BOARD1");
    rectangleButton Button2_(recForBt2, 9, "GEN_BOARD1");
    gamepage.rtButtons.push_back(Button2);
    gamepage.rtButtons.push_back(Button2_);

    //button3:
    Rectangle recForBt3;
    recForBt3.x = bt3Width;
    recForBt3.y = buttonHeight;
    recForBt3.width = 100;
    recForBt3.height = 100;
    rectangleButton Button3(recForBt3, 4, "GEN_BOARD2");
    rectangleButton Button3_(recForBt3, 10, "GEN_BOARD2");
    gamepage.rtButtons.push_back(Button3);
    gamepage.rtButtons.push_back(Button3_);

    //button4:
    Rectangle recForBt4;
    recForBt4.x = bt4Width;
    recForBt4.y = buttonHeight;
    recForBt4.width = 100;
    recForBt4.height = 100;
    rectangleButton Button4(recForBt4, 4, "GEN_BOARD3");
    rectangleButton Button4_(recForBt4, 11, "GEN_BOARD3");
    gamepage.rtButtons.push_back(Button4);
    gamepage.rtButtons.push_back(Button4_);

    //button5:
    Rectangle recForBt5;
    recForBt5.x = bt5Width;
    recForBt5.y = buttonHeight;
    recForBt5.width = 100;
    recForBt5.height = 100;
    rectangleButton Button5(recForBt5, 4, "GEN_BOARD4");
    rectangleButton Button5_(recForBt5, 12, "GEN_BOARD4");
    gamepage.rtButtons.push_back(Button5);
    gamepage.rtButtons.push_back(Button5_);

    //button6:
    Rectangle recForBt6;
    recForBt6.x = bt6Width;
    recForBt6.y = buttonHeight;
    recForBt6.width = 100;
    recForBt6.height = 100;
    rectangleButton Button6(recForBt6, 4, "GEN_BOARD5");
    rectangleButton Button6_(recForBt6, 13, "GEN_BOARD5");
    gamepage.rtButtons.push_back(Button6);
    gamepage.rtButtons.push_back(Button6_);

    //button7:
    Rectangle recForBt7;
    recForBt7.x = bt7Width;
    recForBt7.y = buttonHeight;
    recForBt7.width = 100;
    recForBt7.height = 100;
    rectangleButton Button7(recForBt7, 4, "GEN_BOARD6");
    rectangleButton Button7_(recForBt7, 14, "GEN_BOARD6");
    gamepage.rtButtons.push_back(Button7);
    gamepage.rtButtons.push_back(Button7_);

    //button8:
    Rectangle recForBt8;
    recForBt8.x = bt8Width;
    recForBt8.y = buttonHeight;
    recForBt8.width = 100;
    recForBt8.height = 100;
    rectangleButton Button8(recForBt8, 4, "GEN_BOARD7");
    rectangleButton Button8_(recForBt8, 15, "GEN_BOARD7");
    gamepage.rtButtons.push_back(Button8);
    gamepage.rtButtons.push_back(Button8_);

    // edges
    
    //ball:
    Vector2 posForBall;
    posForBall.x = ballWidth;
    posForBall.y = ballHeight;
    Vector2 vForBall;
    vForBall.x = 0;// changable
    vForBall.y = 0;//changable
    Ball ball(posForBall, ballSize, vForBall, 0, 0);//texture, rotation
    gamepage.balls.push_back(ball);

    //Pause button
    Rectangle recForPause;
    recForPause.x = pauseWidth;
    recForPause.y = pauseHeight;
    recForPause.width = 100;
    recForPause.height = 100;
    rectangleButton pause(recForPause, 5, "JUMP_PAUSE");
    gamepage.rtButtons.push_back(pause);

    //Winning Count
    Rectangle recForWin1;
    Rectangle recForWin2;
    Rectangle recForWin3;
    Rectangle recForWin4;
    Rectangle recForWin5;
    Rectangle recForWin6;
    Rectangle recForWin7;
    recForWin1.x = 0;
    recForWin2.x = 20;
    recForWin3.x = 40;
    recForWin4.x = 60;
    recForWin5.x = 80;
    recForWin6.x = 100;
    recForWin7.x = 120;
    recForWin1.y = 120;
    recForWin2.y = 120;
    recForWin3.y = 120;
    recForWin4.y = 120;
    recForWin5.y = 120;
    recForWin6.y = 120;
    recForWin7.y = 120;
    recForWin1.width = 20;
    recForWin2.width = 20;
    recForWin3.width = 20;
    recForWin4.width = 20;
    recForWin5.width = 20;
    recForWin6.width = 20;
    recForWin7.width = 20;
    recForWin1.height = 20;
    recForWin2.height = 20;
    recForWin3.height = 20;
    recForWin4.height = 20;
    recForWin5.height = 20;
    recForWin6.height = 20;
    recForWin7.height = 20;
    rectangleButton win1(recForWin1, 0, "NONE");
    rectangleButton win2(recForWin2, 0, "NONE");
    rectangleButton win3(recForWin3, 0, "NONE");
    rectangleButton win4(recForWin4, 0, "NONE");
    rectangleButton win5(recForWin5, 0, "NONE");
    rectangleButton win6(recForWin6, 0, "NONE");
    rectangleButton win7(recForWin7, 0, "NONE");
    gamepage.rtButtons.push_back(win1);
    gamepage.rtButtons.push_back(win2);
    gamepage.rtButtons.push_back(win3);
    gamepage.rtButtons.push_back(win4);
    gamepage.rtButtons.push_back(win5);
    gamepage.rtButtons.push_back(win6);
    gamepage.rtButtons.push_back(win7);
}

//创建end界面的page
void initEndSceen(page& endpage){
    endpage.init();

    PlaySoundMulti(sounds[9]);

    //background:
    Rectangle background;
    background.x = 0;
    background.y = 0;
    background.width = 800;
    background.height = 600;
    rectangleButton backGround(background, 16, "JUMP_START");
    endpage.rtButtons.push_back(backGround);
}

// 创建制作人的页面
void initDeveloperSceen(page &menu2page){
    menu2page.init();
    //Text Part:

    //title
    Vector2 position;
    position.x = menuWidth - 100;
    position.y = menuHeight;
    Text menu("Developers:", position, menuFontSize, WHITE);
    menu2page.texts.push_back(menu);

    //names
	Vector2 position1;
	position1.x = menuWidth1;
	position1.y = menuHeight1;
	Text menu1("SZP", position1, showFontSize, WHITE);
	menu2page.texts.push_back(menu1);

    Vector2 position2;
	position2.x = menuWidth2;
	position2.y = menuHeight2;
	Text menu2("WXH", position2, showFontSize, WHITE);
	menu2page.texts.push_back(menu2);

    Vector2 position3;
	position3.x = menuWidth3;
	position3.y = menuHeight3;
	Text menu3("YAL", position3, showFontSize, WHITE);
	menu2page.texts.push_back(menu3);

	//return to main menu
    Vector2 posForMain;
    posForMain.x = mainWidth + 100;
    posForMain.y = mainHeight + 80;
    Text Mamenu("BACK TO MAIN", posForMain, 30, WHITE);
    menu2page.texts.push_back(Mamenu);


    //BACK TO MAIN MENU:
    Rectangle recForMain;
    recForMain.x = mainRecWidth + 100;
    recForMain.y = mainRecHeight + 80;
    recForMain.width = 200;
    recForMain.height = 200;
    rectangleButton mainButton(recForMain, 1, "JUMP_START");
    menu2page.rtButtons.push_back(mainButton);

    Rectangle background;
    background.x = 0;
    background.y = 0;
    background.width = 800;
    background.height = 600;
    rectangleButton backGround(background, 3, "NONE");
    menu2page.rtButtons.push_back(backGround);
}

void buttonEventHandler(std::string event) {
    if (event == "NONE") return;
    
    fprintf(stderr, "Event %s touch off\n", event.c_str());

    if (event == "JUMP_START") {
        pageName = "START";
        pageID = 0;
        // if (!pages[pageID].loadPage("../resource/page/start.txt")) {
        //     fprintf(stderr, "[EVENT HANDLER] JUMP_START ERROR, DO NOT FIND FILE resource/page/start.txt\n");
        //     return;
        // }
    }
    else if (event == "JUMP_SELECT") {
        pageName = "SELECT";
        pageID = 1;
        // if (!pages[pageID].loadPage("../resource/page/select.txt")) {
        //     fprintf(stderr, "[EVENT HANDLER] JUMP_SELECT ERROR, DO NOT FIND FILE resource/page/select.txt\n");
        //     return;
        // }
    }
    else if (event.substr(0, 9) == "JUMP_GAME") { // to be complement
        std::string num = event.substr(9);
        pageName = event.substr(5);
        pageID = 2;
        // if (!pages[pageID].loadPage("../resource/page/game"+ num + ".txt")) {
        //     fprintf(stderr, ("[EVENT HANDLER] JUMP_GAME ERROR, DO NOT FIND FILE resource/page/game"+ num + ".txt\n").c_str());
        //     return;
        // }
    }
    else if(event == "JUMP_PAUSE") {
        prevPageName = pageName;
        pageName = "PAUSE";
        pageID = 3;
        // if (!pages[pageID].loadPage("../resource/page/pause.txt")) {
        //     fprintf(stderr, "[EVENT HANDLER] JUMP_PAUSE ERROR, DO NOT FIND FILE resource/page/pause.txt\n");
        //     return;
        // }
    }
    else if (event == "JUMP_END") {
        pageName = "END";
        pageID = 4;
    }
    else if(event == "JUMP_DEVELOPERS"){
		pageName = "DEVELOPERS";
		pageID = 5;
	}
    else if (event.substr(0, 9) == "GEN_BOARD") { // to be complement 
        int num;
        sscanf(event.c_str() + 9, "%d", &num);
        if (num < 0 || num >= MAXBOARDS) {
            fprintf(stderr, "[EVENT HANDLER] GEN_BOARD ERROR, CODE %s\n", event.c_str());
            return;
        }

        Object tmp = boardsMenu[num];
        Vector2 pos = GetMousePosition();
        tmp.rectangle.x = pos.x, tmp.rectangle.y = pos.y;
        tmp.rectangle.width = boardWidth, tmp.rectangle.height = boardHeight;
        tmp.isClicked = true;

        pages[pageID].boards.push_back(tmp);
    }
    else if (event.substr(0, 9) == "GEN_BLOCK") { // to be complement 
        Object tmp = default_block;
        Vector2 pos = GetMousePosition();
        tmp.rectangle.x = pos.x, tmp.rectangle.y = pos.y;
        tmp.isClicked = true;

        pages[pageID].blocks.push_back(tmp);
    }
    else if (event == "GEN_BALL") { // to be complement
        Ball tmp = default_ball;
        tmp.position = GetMousePosition();
        pages[pageID].balls.push_back(default_ball);
    }
    else {
        fprintf(stderr, "Unknown Type of event: %s\n", event.c_str());
    }

    fprintf(stderr, "Switch to %s\n", pageName.c_str());
}

void initalize() {
    default_ball.r = ballSize;
    default_ball.rotation = 0.0f;
    default_ball.v.x = 100.0f;
    default_ball.v.y = 0.0f;

    default_block.rectangle.width = blockWidth;
    default_block.rectangle.height = blockHeight;
    default_block.angle = 0.0f;
    default_block.texture = 0;
}



int main() {
    InitWindow(frameWidth, frameHeight, "MUSIC");
    if (!IsWindowReady()) {
        fprintf(stderr, "Window Init Fail\n");
        return -1;
    }
    fprintf(stderr, "Window Init Success\n");

    InitAudioDevice();
    if (!IsAudioDeviceReady()) {
        fprintf(stderr, "Audio Device Start Fail\n");
    }
    else fprintf(stderr, "Audio Device Start Success\n");

    SetTargetFPS(60);
    
    sourceLoader();

    Image icon = GetTextureData(textures[20]);
    SetWindowIcon(icon);
    SetWindowTitle("γ");


    pageName = "Start";
    pageID = 0;

    initGameStartSceen(pages[pageID]);
    // Rectangle rec;
    // rec.x = 200, rec.y = 200;
    // rec.width = 200, rec.height = 10;
    // tmpPage.boards.push_back(Object(rec, 0.0f, 0, 1));

    std::string event;
    std::vector<int> curMode;
    int match;
    while (!WindowShouldClose()) {
        event = "";

        BeginDrawing();

        ClearBackground(RAYWHITE);

        pages[pageID].draw(textures);

        EndDrawing();

        if (pageID == 2 && pages[pageID].firstPlay) {
            pages[pageID].firstPlay = false;
            match = 0;
            if (pageName == "GAME1") {
                curMode = WinMode1;
                for (int i = 0; i < 7; ++i) {
                    PlaySound(sounds[WinMode1[i] - 1]);
                    _sleep(500);
                }
            }
            else if(pageName == "GAME2") {
                curMode = WinMode2;
                for (int i = 0; i < 7; ++i) {
                    PlaySound(sounds[WinMode2[i] - 1]);
                    _sleep(500);
                }
            }
            else {
                curMode = WinMode3;
                for (int i = 0; i < 7; ++i) {
                    PlaySound(sounds[WinMode3[i] - 1]);
                    _sleep(500);
                }
            }
        }

        pages[pageID].mouseHandler(event);
        pages[pageID].keyBoardHandler(event);

        if (pageID == 2)
            pages[pageID].processNextFrame(1.0f / (float)GetFPS(), curMode, match);
        else pages[pageID].processNextFrame(1.0f / (float)GetFPS(), curMode, match = -1);

        if (pageID == 2 && match >= 7) {
            bool flag = true;
            for (int i = 0; i < 7; ++i)
                if (pages[pageID].rtButtons[17 + i].texture != 6) {
                    flag = false;
                    break;
                }
            if (flag) {
                if (pageName == "GAME1") {
                    ifWin1 = true;
                    event = "JUMP_GAME2";
                }
                else if (pageName == "GAME2") {
                    ifWin2 = true;
                    event = "JUMP_GAME3";
                }
                else if (pageName == "GAME3") {
                    ifWin3 = true;
                    event = "JUMP_END";
                }
                _sleep(1000);
            }
        }

        std::string lastPageName = pageName;

        buttonEventHandler(event);

        if (lastPageName != pageName) {
            StopSoundMulti();
            if (pageID == 0) {
                initGameStartSceen(pages[pageID]);
            }
            else if(pageID == 1) {
                initGameSelectSceen(pages[pageID]);
            }
            else if (pageID == 2) {
                initGameSceen(pages[pageID]);
            }
            else if (pageID == 3) {
                initGameMenuSceen(pages[pageID]);
            }
            else if (pageID == 4) {
                initEndSceen(pages[pageID]);
            }
            else if(pageID == 5){
				initDeveloperSceen(pages[pageID]);
			} 
            else {
                fprintf(stderr, "Unknown pageID %d\n", pageID);
            }
        }


        // pages[pageID].draw(textures);
        // pages[pageID].mouseHandler();
        // pages[pageID].keyboardHandler();

        // if (pages[pageID].button_touch_off()) {
        //     buttonEventHandler(pages[pageID].getButtonEvent());
        // }

        // pages[pageID].processNextFrame(1.0 / (float) GetFPS()) ;
    }

    CloseWindow();
    CloseAudioDevice();
}