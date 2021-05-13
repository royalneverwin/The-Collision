#ifndef _H_PAGE
#define _H_PAGE

#include "../headers.hpp"
#include "../object/object.hpp"

class page {
private:
public:
    bool gameStart, firstPlay;


    std::vector<rectangleButton> rtButtons;
    std::vector<circleButton> ccButtons;
    std::vector<Text> texts;//Store the actual content

    std::vector<Object> blocks;//Stores Pointers only
    std::vector<Object> boards;//Stores Pointers only
    std::vector<Ball> balls;//Stores Pointers only

    uint Nboards;
    Object boardsMenu[MAXBOARDS]; // 8
    uint boardsNumber[MAXBOARDS];

    inline page() {init(); }
    // to be complement 

    inline void init() {
        gameStart = firstPlay = true;
        rtButtons.clear();
        ccButtons.clear();
        texts.clear();
        blocks.clear();
        boards.clear();
        balls.clear();
    }

    bool loadPage(std::string dir) ; // need complete
    void savePage(std::string dir) ;

    void mouseHandler(std::string &event) ;
    void keyBoardHandler(std::string &event) ;

	int checkTouch(Ball b);

	void draw(const std::vector<Texture> &textures) const ;
    void processNextFrame(float deltaT, std::vector<int> &WinMode, int &match) ; // void checkTouch() ; calculate ball's position & v
};

extern std::vector<Texture> textures;
extern std::vector<Sound> sounds; 

#endif