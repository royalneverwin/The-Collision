#include "page.hpp"

bool page::loadPage(std::string dir) {
    init();

    if (!FileExists(dir.c_str())) {
        fprintf(stderr, ("[loadPage] file " + dir + " not exists\n").c_str());
        return false;
    }

    char buffer[10000];
    LoadFileData(dir.c_str(), (uint*)buffer);

    std::stringstream sstream(buffer);

    uint n;
    sstream >> n;
    rectangleButton button1;
    for (int i = 0; i < n; ++i) {
        sstream >> button1.rectangle.x >> button1.rectangle.y
            >> button1.rectangle.width >> button1.rectangle.height
            >> button1.texture >> button1.event;
        rtButtons.push_back(button1);
    }

    sstream >> n;
    circleButton button2;
    for (int i = 0; i < n; ++i) {
        sstream >> button2.position.x >> button2.position.y >> button2.r
            >> button1.texture >> button1.event;
        ccButtons.push_back(button2);
    }

    sstream >> n;
    Text text;
    for (int i = 0; i < n; ++i) {
        sstream >> text.content >> text.position.x >> button2.position.y
            >> text.fontSize >> text.color.r >> text.color.g >> text.color.b >> text.color.a;
        texts.push_back(text);
    }

    sstream >> n;
    Object block;
    for (int i = 0; i < n; ++i) {
        sstream >> block.rectangle.x >> block.rectangle.y
            >> block.rectangle.width >> block.rectangle.height
            >> block.angle >> block.sound >> block.texture;
        blocks.push_back(block);
    }

    sstream >> n;
    Nboards = n;
    Object board; uint number;
    for (int i = 0; i < n; ++i) {
        sstream >> board.rectangle.x >> board.rectangle.y
            >> board.rectangle.width >> board.rectangle.height
            >> board.angle >> block.sound >> board.texture >> number;
        boardsMenu[i] = board;
        boardsNumber[i] = number;
    }

    sstream >> n;
    Ball ball;
    for (int i = 0; i < n; ++i) {
        sstream >> ball.position.x >> ball.position.y >> ball.v.x >> ball.v.y;
        balls.push_back(ball);
    }

    return true;
}

// void page::savePage(std::string dir) {
//     char buffer[10000];

//     std::stringstream sstream(buffer);

//     sstream << rectangleButton.size();
//     rectangleButton button1;
//     for (int i = 0; i < n; ++i) {
//         sstream >> button1.rectangle.x >> button1.rectangle.y
//             >> button1.rectangle.width >> button1.rectangle.height
//             >> button1.texture >> button1.event;
//         rtButtons.push_back(button1);
//     }

//     sstream >> n;
//     circleButton button2;
//     for (int i = 0; i < n; ++i) {
//         sstream >> button2.position.x >> button2.position.y >> button2.r
//             >> button1.texture >> button1.event;
//         ccButtons.push_back(button2);
//     }

//     sstream >> n;
//     Text text;
//     for (int i = 0; i < n; ++i) {
//         sstream >> text.content >> text.position.x >> button2.position.y
//             >> text.fontSize >> text.color.r >> text.color.g >> text.color.b >> text.color.a;
//         texts.push_back(text);
//     }

//     sstream >> n;
//     Object block;
//     for (int i = 0; i < n; ++i) {
//         sstream >> block.rectangle.x >> block.rectangle.y
//             >> block.rectangle.width >> block.rectangle.height
//             >> block.angle >> block.sound >> block.texture;
//         blocks.push_back(block);
//     }

//     sstream >> n;
//     Nboards = n;
//     Object board; uint number;
//     for (int i = 0; i < n; ++i) {
//         sstream >> board.rectangle.x >> board.rectangle.y
//             >> board.rectangle.width >> board.rectangle.height
//             >> board.angle >> block.sound >> board.texture >> number;
//         boardsMenu[i] = board;
//         boardsNumber[i] = number;
//     }

//     sstream >> n;
//     Ball ball;
//     for (int i = 0; i < n; ++i) {
//         sstream >> ball.position.x >> ball.position.y >> ball.v.x >> ball.v.y;
//         balls.push_back(ball);
//     }

//     SaveFileData(dir.c_str(), (uint*)buffer);
// }

void page::draw(const std::vector<Texture> &textures) const {
    Vector2 position;
    position.x = position.y = 0.0f;
    for (auto button: rtButtons) {
        // DrawRectangleLines(button.rectangle.x, button.rectangle.y,
        //    button.rectangle.width, button.rectangle.height, BLACK);
        DrawTexture(textures[button.texture], button.rectangle.x, button.rectangle.y, WHITE);
    }

    for (auto button: ccButtons) {
        Rectangle rec;
        rec.x = button.position.x - button.r;
        rec.y = button.position.y - button.r;
        rec.height = rec.width = button.r * 2.0;

        // DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, BLACK);
        DrawTexture(textures[button.texture], rec.x, rec.y, WHITE);
    }
    
    for (auto text: texts) {
        DrawText(text.content.c_str(), text.position.x, text.position.y, text.fontSize, text.color);
    }

    for (auto block: blocks) {
        Vector2 position;
        position.x = 0.0;
        position.y = 0.0;
        DrawRectanglePro(block.rectangle, position, block.angle, GRAY);
    }

    for (auto board: boards) {
        Vector2 position;
        position.x = 0.0;
        position.y = 0.0;
        DrawRectanglePro(board.rectangle, position, board.angle, GRAY);
    }

    for (auto ball: balls) {
        DrawTexture(textures[ball.texture], ball.position.x - ball.r
            , ball.position.y - ball.r, WHITE);
    }
}

void page::mouseHandler(std::string &event) {
    event = "NONE";

    Vector2 mouse = GetMousePosition();
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        for (auto& block: blocks) {
            if (block.isClicked) {
                fprintf(stderr, "mouse release\n");
                block.isClicked = false;
                return;
            }
        }
        for (auto& board: boards) {
            if (board.isClicked) {
                fprintf(stderr, "mouse release\n");
                board.isClicked = false;
                return;
            }
        }
        for (auto& ball: balls) {
            if (ball.isClicked) {
                ball.v = Vector2Subtract(mouse, ball.position);
                ball.v.x *= 2.0, ball.v.y *= 2.0;
                ball.isClicked = false;
                gameStart = true;
                return;
            }
        }


        for (auto& button: rtButtons) {
            if (button.checkClick(mouse)) {
                event = button.event;
                return;
            }
        }
        for (auto& button: ccButtons) {
            if (button.checkClick(mouse)) {
                event = button.event;
                return;
            }
        }
        for (auto& block: blocks) {
            if (block.checkClick(mouse)) {
                fprintf(stderr, "mouse pick\n");
                block.isClicked = true;
                return;
            }
        }
        for (auto& board: boards) {
            if (board.checkClick(mouse)) {
                fprintf(stderr, "mouse pick\n");
                board.isClicked = true;
                return;
            }
        }
        for (auto& ball: balls) {
            if (ball.checkClick(mouse)) {
                ball.v.x = ball.v.y = 0.0f;
                ball.isClicked = true;
                return;
            }
        }
    }

    return;
}

void page::keyBoardHandler(std::string &event) {
    Object *selectItem = NULL;
    for (auto& block: blocks) {
        if (block.isClicked) {
            selectItem = &block;
            break;
        }
    }
    for (auto& board: boards) {
        if (board.isClicked) {
            selectItem = &board;
            break;
        }
    }

    if (selectItem != NULL && IsKeyDown(KEY_R)) {
        selectItem->angle += 5.0f;
    }

    if (IsKeyPressed(KEY_P)) {
        event = "JUMP_PAUSE";
    }

    return;
}


//check if a ball has touched sth, returns >= 0 (index of the object)if touched an Object,
//returns -1 if didn't touch anything
//returns -2 if touches the horizental frame
//returns -3 if touches the vertical frame
float innerProduct(float x1, float y1, float x2, float y2){
	return x1 * x2 + y1 * y2;
}

float len(float deltaX, float deltaY){
	return sqrt(deltaX * deltaX + deltaY * deltaY);
}

// 800 * 500
int page::checkTouch(Ball b){    
    //check board touch
    int cnt = -1;
	for(int i = 0; i < boards.size(); ++i){   //check if the ball has touched the board
        Object board = boards[i];
        // ++cnt;
		// float x1 = board.rectangle.x;
		// float y1 = board.rectangle.y;
        // float width = board.rectangle.width;
		// float height = board.rectangle.height;
		// float ang = board.angle;

		// float boardVecX = width * cos(ang / 180.0 * PI);
		// float boardVecY = width * sin(ang / 180.0 * PI);

        // float ballVecX = b.position.x - x1;
        // float ballVecY = b.position.y - y1;

		// float ballVecX1 = ballVecX - boardVecX;
		// float ballVecY1 = ballVecY - boardVecY;

		// float cosTheta1 = innerProduct(boardVecX,boardVecY,ballVecX, ballVecY) / (len(ballVecX,ballVecY) * len(boardVecX,boardVecY));
        // float cosTheta2 = innerProduct(boardVecX,boardVecY,ballVecX1, ballVecY1) / (len(ballVecX1,ballVecY1) * len(boardVecX,boardVecY));

        // // if (i == 3) printf("%f %f\n", cosTheta1, cosTheta2);

		// float Theta1 = acos(cosTheta1);

		// if(!(cosTheta1 >= 0 && cosTheta2 <= 0))
		// 	continue;

        // float dis1 = len(ballVecX,ballVecY) * sin(Theta1);

        // if(dis1 > b.r)
        //     continue;
        // return cnt;

        Vector2 p1, p2;
        p1.x = board.rectangle.x, p1.y = board.rectangle.y;
        p2.x = board.rectangle.x + board.rectangle.width, p2.y = board.rectangle.y;
        p2 = Vector2Add(p1, Vector2Rotate(Vector2Subtract(p2, p1), board.angle));

        Vector2 l1, l2, l;
        l = Vector2Subtract(p2, p1);
        l1 = Vector2Subtract(b.position, p1);
        l2 = Vector2Subtract(b.position, p2);

        float v1 = Vector2DotProduct(l, l1);
        float v2 = Vector2DotProduct(l, l2);

        if (v1 >= 0 && v2 <= 0) {
            float length = std::abs(l1.x * l.y - l1.y * l.x) / len(l.x, l.y);
            if (length <= b.r) return i;
        }
	}
    //check if the ball touches the horizental or vertical frame
    // if(abs(b.position.x - frameWidth) < b.r)
	// 	return -2;
    // if(abs(b.position.y - frameHeight) < b.r)
	// 	return -3;
	return -1;

}

void page::processNextFrame(float deltaT, std::vector<int> &WinMode, int &match){
    deltaT = std::min(deltaT, 0.5f);
    deltaT = std::max(deltaT, 0.03f);

    Vector2 mouse = GetMousePosition();
    if (gameStart) {
        for(auto& b : balls){
            int tmp = checkTouch(b);

            if (tmp != -1){
                float ang;
                if(tmp >= 0){
                    Object touchedBoard = boards[tmp];
                    touchedBoard.touched(sounds);
                    ang = touchedBoard.angle;
                    if (match >=0 && match < 7) {
                        if (touchedBoard.sound + 1 == WinMode[match])
                            rtButtons[17 + match].texture = 6;
                        else rtButtons[17 + match].texture = 7;
                        match++;
                    }
                }
                else {
                    if(tmp == -2)   //horizental touch
                        ang = 0;
                    else ang = 90;  //vertical touch
                }
                float cosAng = cos(ang / 180.0 * PI);
                float sinAng = sin(ang / 180.0 * PI);
                float speeda = b.v.x;
                float speedb = b.v.y;
                b.v.x = speeda * cos(2 * ang / 180.0 * PI) + speedb * sin(2 * ang / 180.0 * PI);
                b.v.y = speeda * sin(2 * ang / 180.0 * PI) - speedb * cos(2 * ang / 180.0 * PI);

                // printf("occur %f %f %f\n", ang, b.v.x, b.v.y);
            }

            b.position.x += b.v.x * deltaT;
            b.position.y += b.v.y * deltaT;
        }
    }

    // 被选中的物体
    Object *selectItem = NULL;
    for (auto& block: blocks) {
        if (block.isClicked) {
            selectItem = &block;
            break;
        }
    }
    for (auto& board: boards) {
        if (board.isClicked) {
            selectItem = &board;
            break;
        }
    }
    if(selectItem != NULL) {
        selectItem->rectangle.x = mouse.x;
        selectItem->rectangle.y = mouse.y;
    }
}