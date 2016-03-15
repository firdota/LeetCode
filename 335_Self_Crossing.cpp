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
				if (curX > rightLine->x1 && curY + x.at(i) >= rightLine->y1&&curY+x.at(i)<=rightLine->y2)
				{
					Line* temp = leftLine;
					leftLine = rightLine;
					rightLine = temp;
				}
				rightLine->x1 = curX;
				rightLine->y1 = curY;
				curY += x.at(i);
				rightLine->x2 = curX;
				rightLine->y2 = curY;
			}
			if (i % 4 == 1)//left
			{
				if (curY == upLine->y1&&curX - x.at(i) >= upLine->x1&&curX - x.at(i) <= upLine->x2)
					return true;
				if (curY >= leftLine->y1&&curY <= leftLine->y2&&curX - x.at(i) <= leftLine->x1)
					return true;
				if (curY > upLine->y1 && curX-x.at(i)>=upLine->x1&&curX-x.at(i)<=upLine->x2)
				{
					Line* temp = downLine;
					downLine = upLine;
					upLine = temp;
				}
				upLine->x1 = curX - x.at(i);
				upLine->y1 = curY;
				upLine->x2 = curX;
				upLine->y2 = curY;
				curX -= x.at(i);
			}
			if (i % 4 == 2)//down
			{
				if (curX == leftLine->x1&&curY - x.at(i) >= leftLine->y1&&curY - x.at(i) <= leftLine->y2)
					return true;
				if (curX >= downLine->x1&&curX <= downLine->x2&&curY - x.at(i) <= downLine->y1)
					return true;
				if (curX < leftLine->x1&&curY - x.at(i) >= leftLine->y1&&curY - x.at(i) <= leftLine->y2)
				{
					Line* temp = rightLine;
					rightLine = leftLine;
					leftLine = temp;
				}
				leftLine->x1 = curX;
				leftLine->y1 = curY - x.at(i);
				leftLine->x2 = curX;
				leftLine->y2 = curY;
				curY -= x.at(i);
			}
			if (i % 4 == 3)//right
			{
				if (curY == downLine->y1&&curX + x.at(i) >= downLine->x1&&curX + x.at(i) <= downLine->x2)//cross with downLine
					return true;
				if (curY >= rightLine->y1&&curY <= rightLine->y2&&curX + x.at(i) >= rightLine->x1)
					return true;
				if (curY < downLine->y1&&curX + x.at(i) >= downLine->x1&&curX + x.at(i) <= downLine->x2)
				{
					Line* temp = upLine;
					upLine = downLine;
					downLine = temp;
				}
				downLine->x1 = curX;
				downLine->y1 = curY;
				curX += x.at(i);
				downLine->x2 = curX;
				downLine->y2 = curY;
			}
			i++;
		}
		return false;
	}
};
int main()
{
	Solution s;
	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(2);
	test.push_back(3);
	cout << s.isSelfCrossing(test) << endl;
}
