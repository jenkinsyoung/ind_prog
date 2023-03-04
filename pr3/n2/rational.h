#pragma once
class rational
{
private:
	int a, b;
public:
	rational();
	~rational();
	rational(int a1, int b1);
	void set(int a1, int b1);
	void show();
};

