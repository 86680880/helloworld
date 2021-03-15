#include <iostream>
#include <algorithm>
using namespace std;
int pre[5005];
int n, m; //n�����㣬m����

struct ENode {
    int from, to, dis;
    bool operator<(ENode p) {
        return dis < p.dis;
    }
}M[200005];

int Find(int x) {
    return x == pre[x] ? pre[x] : pre[x] = Find(pre[x]);
}

int kurskal() {
    sort(M, M + m);
    int N = n, res = 0;
    for (int i = 0; i < m && N > 1; i++) {
        int fx = Find(M[i].from), fy = Find(M[i].to);
        if (fx != fy) {
            pre[fx] = fy;
            N--;//�ҵ���һ���ߣ���N����1��ʱ������Ѿ��ҵ�N-1�����ˣ��������
            res += M[i].dis;
        }
    }
    if (N == 1)//ѭ�����꣬N������1 ����û���ҵ����ʵ�N-1������������С������
        return res;
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        pre[i] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &M[i].from, &M[i].to, &M[i].dis);;
    }
    int ans = kurskal();
    if (ans != -1)
        cout << ans << endl;
    else
        cout << "orz" << endl;
    return 0;
}
