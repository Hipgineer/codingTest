#include <iostream>
#include <vector>
using namespace std;

struct vec2
{
    int x;
    int y;
    vec2(int ix, int iy)
    {
        x = ix;
        y = iy;
    };

    vec2 operator+(vec2 v1) {return vec2(v1.x+x, v1.y+y);};
    vec2 operator-(vec2 v1) {return vec2(x-v1.x, y-v1.y);};
};

struct line
{
    vec2 sta;
    vec2 end;
    line(vec2 ista, vec2 iend)
    {
        sta = ista;
        end = iend;
    };
};

inline bool crossTest(line &l1, line &l2)
{
    // l1.sta.x - l1.end.x
    return true;
}

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> group;

    vector<line> arrLine;
    vector<int> lineGroup;
    arrLine.resize(N);
    vector<line>::iterator ptrLine;
    // for (ptrLine = arrLine.begin(); ptrLine != arrLine.end(); ++ptrLine)
    // {
    //     scanf("%d %d %d %d", &ptrLine->sta.x,&ptrLine->sta.y,&ptrLine->end.x, &ptrLine->end.y);
        
    //     // bool 
    //     // for (int ii = 0; ii < group.size(); ++ii)
    //     // {
            
    //     // }
    // }


}
