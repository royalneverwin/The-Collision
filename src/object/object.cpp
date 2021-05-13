#include "object.hpp"

float Func(float k,float b,float x) {
	return k * x + b;
}

//calculate distance between two points
float getPointDistance(float x1, float y1, float x2, float y2){
	return (float)sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

//calculate distance between a point and a line
float getPointLineDistance(float k, float b, float x, float x1, float y1){
	return (float)abs((k*x1-y1+b)/(sqrt(k*k+1)));
}

bool Object::checkClick(Vector2 mouse) const{
    Vector2 p1, p2, p3, p4;
    p1.x = rectangle.x, p1.y = rectangle.y;
    p2.x = rectangle.x, p2.y = rectangle.y + rectangle.height;
    p3.x = rectangle.x + rectangle.width, p3.y = rectangle.y + rectangle.height;
    p4.x = rectangle.x + rectangle.width, p4.y = rectangle.y;
    
    p2 = Vector2Add(p1, Vector2Rotate(Vector2Subtract(p2, p1), angle));
    p3 = Vector2Add(p1, Vector2Rotate(Vector2Subtract(p3, p1), angle));
    p4 = Vector2Add(p1, Vector2Rotate(Vector2Subtract(p4, p1), angle));

    float v1 = Vector2DotProduct(Vector2Subtract(p2, p1), Vector2Subtract(mouse, p1));
    float v2 = Vector2DotProduct(Vector2Subtract(p3, p2), Vector2Subtract(mouse, p2));
    float v3 = Vector2DotProduct(Vector2Subtract(p4, p3), Vector2Subtract(mouse, p3));
    float v4 = Vector2DotProduct(Vector2Subtract(p1, p4), Vector2Subtract(mouse, p4));

    return v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0;
}
void Object::touched(std::vector<Sound> &sounds){
    // printf("touched\n");
	lightness = maxLightness;
    PlaySoundMulti(sounds[sound]);
}
void Object::timeGoesBy(){
	if(abs(lightness - defaultLightness) < lightnessEpsilon )
		return;
	lightness = (lightness - defaultLightness) * depressRate + defaultLightness;
	return;
}

void Ball::timeGoesBy(){
	position.x += v.x;
	position.y += v.y;
	if(abs(lightness - defaultLightness) < lightnessEpsilon )
		return;
	lightness = (lightness - defaultLightness) * depressRate + defaultLightness;
	return;
}

void Ball::touched(){
	lightness = maxLightness;
}

bool rectangleButton::checkClick(Vector2 mouse) const{
    float wid = rectangle.width;
	float hei = rectangle.height;
	float centerX = rectangle.x;
	float centerY = rectangle.y;
	float clickedX = mouse.x;
	float clickedY = mouse.y;
	if(clickedX >= centerX && clickedX <= centerX + wid && clickedY >= centerY && clickedY <= centerY + hei){
		return true;
	}
	return false;
}

bool Ball::checkClick(Vector2 mouse) const{
    Vector2 dist = Vector2Subtract(position, mouse);
    return Vector2Length(dist) <= r;
}

bool circleButton::checkClick(Vector2 mouse) const{
    return false;
}