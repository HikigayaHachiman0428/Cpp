#include <iostream>
#include <queue>
using namespace std;
const int mx = 10010;
const int mm = 100010;
const int inf = 0x3f3f3f3f;

struct e
{
    int t, nxt, w;
} edge[mm];

int head[mx];
int cnt;
int n, m, hp;
int f[mx]; //��Ȩ����
int u[mx];
int dist[mx];
bool inqueue[mx];

void addEdge(int from, int to, int w)
{
    cnt++;
    edge[cnt].t = to;
    edge[cnt].w = w;
    edge[cnt].nxt = head[from];
    head[from] = cnt;
}

bool check(int mid)
{
    // spfa
    memset(dist, 0x3f, sizeof(dist));
    queue<int> q;
    inqueue[1] = true;
    dist[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        inqueue[temp] = false;
        for (int i = head[temp]; i != 0; i = edge[i].nxt)
        {
            int to = edge[i].t;
            int w = edge[i].w;
            if (dist[to] > dist[temp] + w && f[to] <= mid) /*���˵���Ȩ����ĵ�*/
            {
                dist[to] = dist[temp] + w;
                if (!inqueue[to])
                {
                    inqueue[to] = true;
                    q.push(to);
                }
            }
        }
    }

    //��ʱ��dist[n]��Ϊ�ӱ���ǵ��¸��������С��Ѫ
    return dist[n] <= hp;
}

//����һ�����ִ�
//���ִ𰸵ı��ʾ���ö�٣�����֪�ⷶΧ��������ö��ֵ��ֶδӽ�ķ�Χ��Ѱ�ҳ���
//
//��Ŀ��"�������������г���������һ����ȡ�ķ��õ���Сֵ�Ƕ��٣�"
//��仰����˼ʵ������ָ��
//         ����һ��·�� a �� ���庯��f(a)��
//         ����·���ϵ����е�Ȩ���ɵļ���s�� ����f(a)=max(s)
//         ������һ��ͼ������㵽�յ���ڶ���·��a1,a2,a3...
//         �������п��ܵ�·��a1,a2,a3...�������ڶ�Ӧ��f(a1),f(a2),f(a3)...
//         ��f(a1),f(a2),f(a3)...�е���Сֵ
//������˼����Ƕ��֣�����ʲô�أ�
//         �����ֵ�һ����һ��������ļ���
//         ���ȣ����f(a)�ǵ���max(s)�ģ�f(a)һ����һ����Ȩ������������Ľ�Ϊһ����Ȩ
//         �����߹���ÿһ��·���е���С��Ȩf(a)һ����һ��������:������ͼ����͵�Ȩ����ߵ�Ȩ֮��
//         ͨ��������ͼ�ĵ�Ȩ��������Ȼ�������֣�������ͼ�ĵ�Ȩ�������ҳ�һ����Ȩ��
//         �����Ȩ��min(  f(a1)  f(a2)  f(a3) ... ) ���Ǳ������
//�����Ѿ��ҵ��˽�ļ��ϣ���Ȩ���ϡ�
//���ֵ�Ȩ���ϣ�ÿһ�ζ���õ�һ����Ȩ�������Ȩ����·�������е��Ȩ���컨��
//������ͼ��Ѱ��·����������Ϊ���ǵõ���һ���컨�壬���Ե�Ȩ��������컨��ĵ�Ͳ���ѡ
//Ѱ��·��ҲӦ�������·����Ϊ����Ѫ��������Ҫ�ҵ���Ѫ���ٵ�·��
//Ҫ���ҵ������·���ϵĿ�Ѫ�ܺ���Ȼ��������ô�����ҵ��ĵ�Ȩ������Ч�ģ��������϶��֣������Ȩ��Χ
//Ҫ�ǲ���������ô�ֳ��ĵ�Ȩ������Ч�ģ��������¶��֣���С��Ȩ��Χ��
int main()
{
    scanf("%d%d%d", &n, &m, &hp);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &f[i]);
        u[i] = f[i]; // ע��
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        addEdge(a, b, c);
        addEdge(b, a, c);
    }
    //��ʼ����
    sort(u + 1, u + n + 1);
    //������һ���жϣ������Ȩ��С�ڲ������Ƶ�����£���Ȼ�޷�������Ѫ��С��hp��·����ֱ�ӽ�������
    if (!check(inf))
    {
        printf("AFK\n");
        return 0;
    }
    int l = 1, r = n; //�õ���Ȩ���ϵ�����
    int mid;
    int ans = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(u[mid]))
        {
            ans = u[mid];
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    //������ɺ����õľ���������Ҫ��min(  f(a1)  f(a2)  f(a3) ... )
    printf("%d\n", ans);
    return 0;
}
