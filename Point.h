#if !defined(__POINT_H__)
#define __POINT_H__

class Point
{
protected:
	float x;
	float y;

public:
	Point(const float x, const float y);
	~Point();

	float getX() const;
	float getY() const;

	void setX(const float x);
	void setY(const float y);

	Point translate(const Point &p) const;
};

#endif /* __POINT_H__ */