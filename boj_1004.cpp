#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    vector<int> res;

    scanf("%d", &T);
    for (int tt = 0 ; tt < T ; ++tt)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int N = 0;
        int cx = 0;
        int cy = 0;
        int r = 0;
        int count = 0;
        scanf("%d",&N);
        for (int nn = 0 ; nn< N ; ++nn)
        {
            scanf("%d %d %d",&cx, &cy, &r);
            int dr1 = (cx-x1)*(cx-x1) + (cy-y1)*(cy-y1);
            int dr2 = (cx-x2)*(cx-x2) + (cy-y2)*(cy-y2);
            if ((dr1 < r*r)&&(dr2 < r*r)) continue;
            else if ((dr1 >= r*r)&&(dr2 >= r*r)) continue;
            else count++; 
        }
        res.push_back(count);
    }

    for (int tt = 0; tt < T ; ++tt)
    {
        printf("%d\n",res[tt]);
    }
}
