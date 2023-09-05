// launchAngleCalculator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "math.h"



//计算从原点发射抛射物到目标坐标所需要的角度
float  calculate_launch_angle(Vector2 Object ,float bulletVelocity) {

	const float g = 9.8f;
	float root = pow(bulletVelocity, 4) - g * (g * pow(Object.x, 2) + 2 * Object.y * pow(bulletVelocity, 2));
	if (root < 0) {
		return NAN;
	}
	return atan((pow(bulletVelocity, 2) - sqrt(root)) / (g * Object.x));

}


int main()
{		
    std::cout << "Hello World!\n";

	Vector3 Object = {120.f,100.f,0.f};
	Vector3 Player= { 100.f,0.f,0.f };
	
	float x_distance = sqrt(pow(Object.x - Player.x, 2) + pow(Object.z - Player.z, 2));
	float y_distance = Object.y - Player.y;
	Vector2 Position = { x_distance,y_distance };

	float angle = calculate_launch_angle(Position,900.f);
	std::cout << "lANUCH ANGLE:"<<angle;
}
