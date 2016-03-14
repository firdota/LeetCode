#include<iostream>
#include<vector>
using namespace std;
struct Line
{
	int x1;
	int y1;
	int x2;
	int y2;
	Line(int a, int b, int c, int d) :x1(a), y1(b), x2(c), y2(d){}
};
class Solution {
public:
	bool isSelfCrossing(vector<int>& x) {
		if (x.size() < 4)
			return false;
		Line *rightLine = new Line(0, 0, 0, x.at(0));
		Line *upLine = new Line(-x.at(1), x.at(0), 0, x.at(0));
		Line *leftLine = new Line(-x.at(1), x.at(0) - x.at(2), -x.at(1), x.at(0));
		Line *downLine = new Line(-x.at(1), x.at(0) - x.at(2), -x.at(1) + x.at(3), x.at(0) - x.at(2));
		if (x.at(2) <= x.at(0) && x.at(3) >= x.at(1))
			return true;
		int curX = x.at(3) - x.at(1), curY = x.at(0) - x.at(2), i = 4;
		while (i < x.size())
		{
			if (i % 4 == 0)//up
			{
				if (curX == rightLine->x1&&curY + x.at(i) >= rightLine->y1&&curY + x.at(i) <= rightLine->y2)//cross with rightLine
					return true;
				if (curX >= upLine->x1&&curX <= upLine->x2&&curY + x.at(i) >= upLine->y1)//cross with upLine
					return true;
				if (curX <= rightLine->x1 || curY + x.at(i) < rightLine->y1)
				{
					rightLine->x1 = curX;
					rightLine->y1 = curY;
					curY += x.at(i);
					rightLine->x2 = curX;
					rightLine->y2 = curY;
				}
				else if (curY + x.at(i) >= rightLine->y1)
				{
					leftLine = rightLine;
					rightLine->x1 = curX;
					rightLine->y1 = curY;
					curY += x.at(i);
					rightLine->x2 = curX;
					rightLine->y2 = curY;
				}
			}
			if (i % 4 == 1)//left
			{

			}
		}
		return false;
	}
};
int main()
{

}
