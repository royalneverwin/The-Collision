#ifndef _H_OBJECT
#define _H_OBJECT

#include "../headers.hpp"

class Object;
class Ball;

class Object{
private:
public:
    Rectangle rectangle;
    float angle;        // anticlockwise
    
    uint sound;
    uint texture;
    
    bool isClicked;
	float lightness;

    inline Object() {}
	inline Object(Rectangle rectangle, float angle, uint sound, uint texture):
        rectangle(rectangle), angle(angle), sound(sound), texture(texture) {
        isClicked = false;
        lightness = 1.0;
    }
    
    // to be complement 
    bool checkClick(Vector2 mouse) const;
    void touched(std::vector<Sound> &sounds) ; // set lightness & sound
    void timeGoesBy() ; // lightness change
};

class Ball {
private:
public:
    Vector2 position;
    float r;
    Vector2 v;
    uint texture;

    float rotation;//rotate when ball is a music notation

	float lightness;
    bool isClicked;

    inline Ball() {}
	inline Ball(Vector2 position, float r, Vector2 v, uint texture, float _rotation = 0): 
        position(position), r(r), v(v), texture(texture), rotation(_rotation){isClicked = false;}

	void touched();
	void timeGoesBy();  //change position while the ball is moving
    bool checkClick(Vector2 mouse) const ;
};

struct rectangleButton {
    Rectangle rectangle;
    uint texture;
    std::string event;

    inline rectangleButton() {}
    inline rectangleButton(Rectangle rectangle, uint texture, std::string event): 
        rectangle(rectangle), texture(texture), event(event) {}
    
    bool checkClick(Vector2 mouse) const; // need complete
};

struct circleButton {
    Vector2 position;
    float r;
    uint texture;
    std::string event;

    inline circleButton() {}
    inline circleButton(Vector2 position, float r, uint texture, std::string event): 
        position(position), r(r), texture(texture), event(event) {}
    
    bool checkClick(Vector2 mouse) const; // need complete
};

struct Text {
    std::string content;
    Vector2 position;
    float fontSize;
    Color color;

    inline Text() {}
    inline Text(std::string content, Vector2 position, float fontSize, Color color):
        content(content), position(position), fontSize(fontSize), color(color) {}
};

#endif