#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[100001];
int N, cnt;
int minh[100001]; // 联通块中y的最小值
int maxh[100001]; // 联通块中y的最大值
int main()
{
	// freopen("moop.in", "r", stdin);
	// freopen("moop.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &a[i].first, &a[i].second);

	// 将所有点按照坐标排序后，每个联通块都是一段连续的区间
	sort(a + 1, a + N + 1); // 如果first相等，判断second

	for (int i = 1; i <= N; i++)
	{
		cnt++; // 连通块数加1
		minh[cnt] = a[i].second;
		maxh[cnt] = a[i].second;
		// 因为最后一个连通块中只要有一个点比倒数第二个连通块中的一个点x,y值都大，两个连通块就能合并掉
		// 联通块的数量 > 1 && 最右边的两个联通块中，最后1个联通块中y的最大值 >= 倒数第2个中y的最小值
		while (cnt > 1 && maxh[cnt] >= minh[cnt - 1])
		{
			// 将最右边的两个联通块合并到一起
			minh[cnt - 1] = min(minh[cnt - 1], minh[cnt]);  // 联通块中y的最小值
			maxh[cnt - 1] = max(maxh[cnt - 1], maxh[cnt]);  // 联通块中y的最大值
			cnt--;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
