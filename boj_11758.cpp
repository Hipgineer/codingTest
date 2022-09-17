#include <iostream>
using namespace std;

int main()
{
    int x1,y1;
    int x2,y2;
    int x3,y3;

    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    
    int v1x = x2-x1;
    int v1y = y2-y1;

    int v2x = x3-x2;
    int v2y = y3-y2;
    
    if (v1x*v2y - v1y*v2x > 0 ) printf("1\n");
    else if (v1x*v2y - v1y*v2x < 0 ) printf("-1\n");
    else printf("0\n");
}
