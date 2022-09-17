#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    int x1, y1, x2, y2, r1, r2;
    vector<int> res;

    scanf("%d", &N);
    for (int nn = 0 ; nn < N ; ++nn)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        int c = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        int cp= (r1+r2)*(r1+r2);

        if (c == 0)
        {
            if (r1 == r2) res.push_back(-1);
            else res.push_back(0);
        }
        else
        {
            if (c == cp) res.push_back(1);
            else if (c > cp) res.push_back(0);
            else if (c == (max(r1,r2)-min(r1,r2))*(max(r1,r2)-min(r1,r2))) res.push_back(1);
            else if (c < (max(r1,r2)-min(r1,r2))*(max(r1,r2)-min(r1,r2))) res.push_back(0);
            else res.push_back(2);
        }
    }

    for (int nn = 0; nn < N ; ++nn)
    {
        printf("%d\n",res[nn]);
    }
}
