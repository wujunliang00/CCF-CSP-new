//不看请容易误认为是广搜，坑
//Dijkstra
#include<iostream>
#include<vector>
#include<queue>
#include<mem.h>
#define ULLONG unsigned long long
#define MAX_LIMIT 1001
using namespace std;
ULLONG N,M;

class Path
{
public:
    ULLONG next;
    ULLONG length;
    ULLONG type;
    Path(ULLONG t,ULLONG n,ULLONG len){type = t;next = n;length = len;}
};
//路径
vector<Path> path[MAX_LIMIT];
ULLONG get_result();
int main()
{
    cin >>N >>M;
    for(ULLONG i=0;i < M;i++)
    {
        ULLONG t,a,b;
        ULLONG c;
        cin >>t >>a >>b >>c;
        path[a].push_back(Path(t,b,c));
        path[b].push_back(Path(t,a,c));
    }
    cout <<get_result();
    return 0;
}
ULLONG get_result()
{
    //distance第一列代表到该结点之前连续的小路总长，
    //第二列代表到该点的总疲劳
    ULLONG distance[N+1][3];
    bool visit[N+1] = {false,};

    //从1开始
    ULLONG key = 1;
    memset(distance,0xff,8*3*(N+1));
    visit[key] = true;
    distance[1][2] = 0;
    distance[1][1] = 0;

    //1到各点的距离：1、结尾为1结点的小路总长 2、总疲劳
    for(ULLONG i=0;i < path[key].size();i++)
    {
        ULLONG next = path[key][i].next;
        ULLONG len = path[key][i].length;
        ULLONG type = path[key][i].type;
        if(type == 1)
        {
            distance[next][2] = len*len;
            distance[next][1] = len;
        }
        else
        {
            distance[next][2] = len;
            distance[next][1] = 0;
        }
    }
    //更新、所有点访问过以后结束
    while(true)
    {
        ULLONG Max = 0xFFFFFFFFFFFFFFFF;
        key = 0;
        //寻找疲劳最小的点
        for(ULLONG i=1;i <= N;i++)
        {
            if(i == key || visit[i]) continue;
            if(distance[i][2] < Max)
            {
                key = i; Max = distance[i][2];
            }
        }
        if(key == 0) break;
        visit[key] = true;
        //以该点为中间点，更新1到各点的疲劳
        for(ULLONG i=0;i < path[key].size();i++)
        {
            ULLONG next = path[key][i].next;
            ULLONG len = path[key][i].length;
            ULLONG type = path[key][i].type;
            if(visit[next]) continue;
            ULLONG new_distance = 0;
            //大路，直接加距离，之前的小路到此断了，连续小路长度置为0
            if(type == 0)
            {
                new_distance = len+distance[key][2];
                if(new_distance < distance[next][2])
                {
                    distance[next][2] = new_distance;
                    distance[next][1] = 0;
                }
            }
            //小路
            else
            {
                //之前又连续的小路，则加上现在小路距离求疲劳再加上：总的疲劳减去之前小路的疲劳，因为重复了
                if(distance[key][1] != 0)
                    new_distance = (distance[key][1]+len)*(distance[key][1]+len)+distance[key][2]-distance[key][1]*distance[key][1];
                //之前没有小路，则直接加当前小路的平方
                else
                    new_distance = len*len+distance[key][2];
                if(new_distance < distance[next][2])
                {
                    distance[next][2] = new_distance;
                    //小路长度增加
                    distance[next][1] = len+distance[key][1];
                }
            }
        }
    }
    return distance[N][2];
}