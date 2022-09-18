#include <iostream>
#include <cmath>
using namespace std;

int64_t computeTriArea(int64_t x0, int64_t y0, int64_t x1, int64_t y1, int64_t x2, int64_t y2)
{
    int64_t v1x = x1 - x0;
    int64_t v1y = y1 - y0;
    int64_t v2x = x2 - x1;
    int64_t v2y = y2 - y1;

    return (v1x*v2y - v1y*v2x);
}

int main()
{
    int64_t N;
    int64_t x0,x1,x2,y0,y1,y2;

    scanf("%lld", &N);
    scanf("%lld %lld", &x0, &y0);
    scanf("%lld %lld", &x1, &y1);
    scanf("%lld %lld", &x2, &y2);
    int64_t sumArea = computeTriArea(x0, y0, x1, y1, x2, y2);
    for (int64_t nn = 0 ; nn < N-3 ; ++nn)
    {
        x1 = x2;
        y1 = y2;
        scanf("%lld %lld", &x2,&y2);
        sumArea += computeTriArea(x0, y0, x1, y1, x2, y2);
    }

    sumArea = abs(sumArea);
    printf("%lld", sumArea/2);
    if (sumArea&1) printf(".5\n");
    else printf(".0\n");
}
