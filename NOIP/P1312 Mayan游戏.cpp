#include <bits/stdc++.h>
using namespace std;

const int N = 5;
const int M = 7;

int maxstep, chess[N][M];
int cnt[11];
int answer[5][3];

void init() {
    cin >> maxstep;
    for (int i = 0; i < N; i++) {
        int j = 0, x;
        cin >> x;
        while (x != 0) {
            chess[i][j] = x;
            j++;
            cin >> x;
        }
    }
}

void fall()  //����󷽿�����
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (chess[i][j] != 0) continue;
            int k;
            for (k = j + 1; k < M; k++)
                if (chess[i][k] != 0) {
                    swap(chess[i][j], chess[i][k]);
                    break;
                }
            if (k == M) break;
        }
}

void printans()  //���
{
    for (int i = 0; i < maxstep; i++)
        printf("%d %d %d\n", answer[i][0], answer[i][1], answer[i][2]);
    return;
}

bool clear()  //�������
{
    bool empty[N][M];
    memset(empty, false, sizeof(empty));
    for (int i = 0; i < N - 2; i++)
        for (int j = 0; j < M; j++)
            if (chess[i][j] != 0 && chess[i][j] == chess[i + 1][j] &&
                chess[i + 1][j] == chess[i + 2][j]) {
                empty[i][j] = empty[i + 1][j] = empty[i + 2][j] = true;
            }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M - 2; j++)
            if (chess[i][j] != 0 && chess[i][j] == chess[i][j + 1] &&
                chess[i][j + 1] == chess[i][j + 2]) {
                empty[i][j] = empty[i][j + 1] = empty[i][j + 2] = true;
            }

    bool hasChange = false;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (empty[i][j]) {
                chess[i][j] = 0;
                hasChange = true;
            }
    return hasChange;
}

bool isempty()  // �ж������Ƿ�Ϊ��
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (chess[i][j] != 0) return false;
    return true;
}

bool judge()  //�ж��Ƿ���һ����ɫ�Ŀ�����Ϊ1��2
{
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) cnt[chess[i][j]]++;
    for (int i = 1; i <= 10; i++)
        if (cnt[i] == 1 || cnt[i] == 2) return false;
    return true;
}

bool dfs(int step)  //����
{
    if (isempty())  //����һ���
    {
        printans();
        return true;
    }
    if (step >= maxstep || !judge())  //��֦���������
        return false;

    int now[N][M];               // ��¼��ǰ״̬������ʱ����
    for (int i = 0; i < N; i++)  //��������
        for (int j = 0; j < M; j++) now[i][j] = chess[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)  //ö��ÿһ������
        {
            //����
            if (i != N - 1 && chess[i][j] != 0 &&
                chess[i][j] != chess[i + 1][j]) {
                swap(chess[i][j], chess[i + 1][j]);
                answer[step][0] = i;
                answer[step][1] = j;
                answer[step][2] = 1;
                fall();
                while (clear()) fall();
                if (dfs(step + 1)) return true;
            }

            for (int k1 = 0; k1 < N; k1++)
                for (int k2 = 0; k2 < M; k2++) chess[k1][k2] = now[k1][k2];

            //����
            if (i != 0 && chess[i][j] != 0 && chess[i - 1][j] == 0) {
                swap(chess[i][j], chess[i - 1][j]);
                answer[step][0] = i;
                answer[step][1] = j;
                answer[step][2] = -1;
                fall();
                while (clear()) fall();
                if (dfs(step + 1)) return true;
            }

            for (int k1 = 0; k1 < N; k1++)
                for (int k2 = 0; k2 < M; k2++) chess[k1][k2] = now[k1][k2];
        }
    return false;
}

/*
����+��֦
��֦ԭ��
1������������ͬ��ɫ�Ŀ�û�����塣
2�����һ����ɫ�Ŀ�����Ϊ1��2����ǰ�����޽⡣
3����ΪҪ���ֵ�����С�Ľ⣬����һ����������Ϊ��ʱ��������
���������з��飬��ô����i-1��ʱ�������ƣ�����i��ʱ�����ǵ�Ч�ģ��ʿ��Լ�֦��
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    if (!dfs(0)) cout << -1 << endl;
    return 0;
}
