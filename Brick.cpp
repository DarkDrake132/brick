#include "Brick.h"

void Brick::drawRect(float x, float y, float width, float height)
{
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
}

float Brick::get_brick_pos_x()
{
	return brick_pos_x;
}

float Brick::get_brick_pos_y()
{
	return brick_pos_y;
}

float Brick::get_brick_width()
{
	return brick_width;
}

float Brick::get_brick_height()
{
	return brick_height;
}

void Brick::set_brick_pos_x(float x)
{
	this->brick_pos_x = x;
}

void Brick::set_brick_pos_y(float y)
{
	this->brick_pos_y = y;
}

void Brick::set_brick_width(float w)
{
	this->brick_width = w;
}

void Brick::set_brick_height(float h)
{
	this->brick_height = h;
}


int Brick::get_exist()
{
	return exist;
}


void Brick::updateBrick(Ball& ball, int & level)
{
	// fly a bit
	float ball_pos_x = ball.get_ball_pos_x();
	float ball_dir_x_1 = ball.get_dir_x_1();
	float ball_pos_y = ball.get_ball_pos_y();
	float ball_dir_y_1 = ball.get_dir_y_1();
	float ball_speed = ball.get_ball_speed();
	float ball_size = ball.get_ball_size();

	ball_pos_x += ball_dir_x_1 * ball_speed;
	ball_pos_y += ball_dir_y_1 * ball_speed;

	if (level == 1)
	{
		if (ball_pos_y < brick_pos_y + brick_height && ball_pos_y + ball_size > brick_pos_y&& ball_pos_x + ball_size > brick_pos_x&& ball_pos_x < brick_pos_x + brick_width)
		{
			this->~Brick();
		}
	}
	if (level == 2 || level == 3 || level == 4)
	{
		if (ball_pos_y < brick_pos_y + brick_height && ball_pos_y + ball_size > brick_pos_y&& ball_pos_x + ball_size > brick_pos_x&& ball_pos_x < brick_pos_x + brick_width && exist == 1)
		{
			this->~Brick();
			int y = -ball.get_dir_y_1();
			ball.set_dir_y_1(y);
		
		}
	}

}

void Brick::set_exist(int x)
{
	this->exist = x;
}


Brick::Brick()
{
	this->brick_width = 150;
	this->brick_height = 20;
}

Brick::~Brick()
{
	this->exist = 0;
	this->brick_height = 0;
	this->brick_width = 0;
	this->brick_pos_x = 0;
	this->brick_pos_y = 0;
}
