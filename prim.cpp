#include<iostream>//Prim�㷨�ļ�ʵ��(��С����������С����·��)
#include<cstdio>
#include<cstring>
#define inf (0x3f3f3f3f)
using namespace std;
const int maxn = 100 + 15;
int Grape[maxn][maxn];// u ~ v�ڵ�֮��ߵ�Ȩֵ  (-1��ʾ�߲�����)
int d[maxn];//ÿ���ڵ㵽Tree����̾���
int p[maxn];//ÿ���ڵ�ĸ��ڵ�
int n;//n���ڵ�
bool vis[maxn];//�ж�ÿ���ڵ��Ƿ񱻷��ʹ�
void Prim()//���ѡȡһ���ڵ���ΪT
{
    memset(d,inf,sizeof(d));//��ʼ����Ϊ����
    memset(p,-1,sizeof(p));
    d[1] = 0;
    while(true)
    {
        int minconst = inf,u;//Ѱ��T ��V - T֮�����̾���
        for(int i=1;i<=n;++i)
        {
            if(!vis[i]&&d[i]<minconst)
            {
                minconst = d[i];
                u = i;
            }
        }
        if(minconst == inf)
            break;//�Ѿ����
        vis[u] = true;//����u�ڵ�
        //����d
        for(int v=1;v<=n;++v)
        {
            if(!vis[v]&&d[v]>Grape[u][v]&&Grape[u][v]!=-1)//����ڵ�δ�������Ҹ����Ҵ��ڱ�
            {
                d[v] = Grape[u][v];
                p[v] = u;
            }
        }
    }
}
int main()
{
	int m;
    cin>>m>>n;
    memset(Grape,inf,sizeof(Grape));
    for(int i=1;i<=m;++i)
    {
       int x,y,z;
       cin>>x>>y>>z;
       Grape[x][y]=Grape[y][x]=z;
    }//�����ڽ�ͼ
    Prim();
    int sum = 0;
    for(int i=1;i<=n;++i)
    {
        if(p[i]!=-1)
            sum += Grape[i][p[i]];
    }
    cout<<sum<<endl;
}
//����С����������·��
