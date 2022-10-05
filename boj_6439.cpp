#include <iostream>
using namespace std;

struct BoxAndLine
{
    int boxXmin;
    int boxYmin;
    int boxXmax;
    int boxYmax;
    int linXsta;
    int linYsta;
    int linXend;
    int linYend;

    void reset()
    {
        int tmp;
        if (boxXmin > boxXmax)
        {
            tmp = boxXmax;
            boxXmax = boxXmin;
            boxXmin = tmp;
        }
        if (boxYmin > boxYmax)
        {
            tmp = boxYmax;
            boxYmax = boxYmin;
            boxYmin = tmp;
        }
    }

    bool checkXaxis()
    {
        if ((boxXmin <= linXsta) && (boxXmax >= linXsta))
            return true;
        if ((boxXmin <= linXend) && (boxXmax >= linXend))
            return true;
        if ((boxXmin >= min(linXend, linXsta)) && (boxXmin <= max(linXend, linXsta)))
            return true;
        return false;
    }

    bool checkYaxis()
    {
        if ((boxYmin <= linYsta) && (boxYmax >= linYsta))
            return true;
        if ((boxYmin <= linYend) && (boxYmax >= linYend))
            return true;
        if ((boxYmin >= min(linYend, linYsta)) && (boxYmin <= max(linYend, linYsta)))
            return true;
        return false;
    }

    bool checkLineAxis()
    {
        int dx11, dx12, dx21, dx22;
        int dy11, dy12, dy21, dy22;
        dx11 = boxXmin - linXsta;
        dy11 = boxYmin - linYsta;
        dx12 = boxXmax - linXsta;
        dy12 = boxYmax - linYsta;

        dx21 = boxXmin - linXend;
        dy21 = boxYmin - linYend;
        dx22 = boxXmax - linXend;
        dy22 = boxYmax - linYend;
        if (dx11 * dy21 - dx21 * dy11 < 0)
        {
            if (dx11 * dy22 - dx21 * dy12 < 0)
                if (dx12 * dy21 - dx22 * dy11 < 0)
                    if (dx12 * dy22 - dx22 * dy12 < 0)
                        return false;
        }
        else if (dx11 * dy21 - dx21 * dy11 > 0)
        {
            if (dx11 * dy22 - dx21 * dy12 > 0)
                if (dx12 * dy21 - dx22 * dy11 > 0)
                    if (dx12 * dy22 - dx22 * dy12 > 0)
                        return false;
        }

        return true;
    }
};

int main()
{
    int T;
    BoxAndLine BL;
    scanf("%d", &T);

    for (int tt = 0; tt < T; ++tt)
    {
        bool result = false;
        scanf("%d %d %d %d %d %d %d %d",
              &BL.linXsta, &BL.linYsta, &BL.linXend, &BL.linYend,
              &BL.boxXmin, &BL.boxYmin, &BL.boxXmax, &BL.boxYmax);
        BL.reset();
        if (BL.checkXaxis())
            if (BL.checkYaxis())
                if (BL.checkLineAxis())
                    result = true;
        
        if (result) 
            printf("T\n");
        else 
            printf("F\n");
    }

    return 0;
}
