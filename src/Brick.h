#ifndef BRICK_H_
#define BRICK_H_

class Brick {
private:
	unsigned int x;
	unsigned int y;

	unsigned int w;
	unsigned int h;

public:
	unsigned int getH() const;
	unsigned int getW() const;
	unsigned int getX() const;
	unsigned int getY() const;
	void setH(unsigned int h);
	void setW(unsigned int w);
	void setX(unsigned int x);
	void setY(unsigned int y);
};

#endif /* BRICK_H_ */
