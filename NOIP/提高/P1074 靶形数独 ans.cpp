#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 12;
const int score[10][10] = {
    {6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 7, 7, 7, 7, 7, 7, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 9, 10, 9, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 7, 7, 7, 7, 7, 7, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6}};

bool rowBook[MAXN][MAXN];  // rowBook[i][j] ��i����j�Ƿ����ֹ�
bool colBook[MAXN][MAXN];  // colBook[i][j] ��i����j�Ƿ����ֹ�
bool area[MAXN][MAXN];     // area[i][j] ��i��С�Ź���j�Ƿ����ֹ�
int sdk[MAXN][MAXN];       // sudoku ����
int row_cnt[MAXN], col_cnt[MAXN];  // ÿһ�� ÿһ�����˼�����
int cnt;                           // һ�����˼�����
int ans = -1;

inline int id(int i, int j)  // ����С�Ź�������
{
    if (0 <= i && i < 3 && 0 <= j && j < 3) return 0;
    if (3 <= i && i < 6 && 0 <= j && j < 3) return 3;
    if (6 <= i && i < 9 && 0 <= j && j < 3) return 6;
    if (0 <= i && i < 3 && 3 <= j && j < 6) return 1;
    if (3 <= i && i < 6 && 3 <= j && j < 6) return 4;
    if (6 <= i && i < 9 && 3 <= j && j < 6) return 7;
    if (0 <= i && i < 3 && 6 <= j && j < 9) return 2;
    if (3 <= i && i < 6 && 6 <= j && j < 9) return 5;
    return 8;
}

inline int calc()  // �����ܵ÷�
{
    int sum = 0;
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j) {
            sum += score[i][j] * sdk[i][j];
        }
    return sum;
}

void dfs(int r, int c) {
    if (cnt == 81) {
        ans = max(ans, calc());
        return;
    }

    for (int k = 1; k <= 9; k++) { // ��1~9�⼸�����ɹ�ѡ��
        if (rowBook[r][k] || colBook[c][k] || area[id(r, c)][k]) continue;

        // ����
        sdk[r][c] = k;
        rowBook[r][k] = true;
        colBook[c][k] = true;
        area[id(r, c)][k] = true;
        row_cnt[r]++;
        col_cnt[c]++;
        cnt++;

        // �ҳ���һ��������ȷ���ĵ�
        int maxr = -1, nxt_r = 0;
        for (int i = 0; i < 9; ++i)
            if (row_cnt[i] > maxr && row_cnt[i] < 9) {
                maxr = row_cnt[i];
                nxt_r = i;
            }

        int maxc = -1, nxt_c = 0;
        for (int j = 0; j < 9; ++j)
            if (col_cnt[j] > maxc && sdk[nxt_r][j] == 0) {
                maxc = col_cnt[j];
                nxt_c = j;
            }

        dfs(nxt_r, nxt_c);

        // ����
        sdk[r][c] = 0;  // һ��Ҫ���㣬����������sdk[nxt_r][j]==0
        rowBook[r][k] = false;
        colBook[c][k] = false;
        area[id(r, c)][k] = false;
        row_cnt[r]--;
        col_cnt[c]--;
        cnt--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> sdk[i][j];
            if (sdk[i][j] != 0) {
                rowBook[i][sdk[i][j]] = true;
                colBook[j][sdk[i][j]] = true;
                area[id(i, j)][sdk[i][j]] = true;
                row_cnt[i]++;
                col_cnt[j]++;
                cnt++;
            }
        }
    }
    // �ҳ������׵���ʼ��
    int maxr = -1, r;
    for (int i = 0; i < 9; i++)
        if (row_cnt[i] > maxr && row_cnt[i] < 9) {
            maxr = row_cnt[i];
            r = i;
        }

    int maxc = -1, c;
    for (int j = 0; j < 9; j++)
        if (col_cnt[j] > maxc && sdk[r][j] == 0) {
            maxc = col_cnt[j];
            c = j;
        }

    dfs(r, c);
    cout << ans << endl;

    return 0;
}
