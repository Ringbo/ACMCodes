/**************************************
**	author:jily
**	update:3/1/2017
**	˵��
**	Ϊ����ЭPOJ��һϵ��OJƽ̨������
**		ģ�岻����C++11�Ժ��������
**			���Ķ���̫�����Ա�����Ը�û��м�����
**	ͼ�ṹ�ı�ʾĬ�ϲ����ڽӾ���
**************************************/

#include <vector>
using namespace std;

int const INF = 0x3f3f3f3f;

//���鼯Union-Find�㷨
//���Ⱥϲ�
	//��Ϊά���ɱ�
		//��·��ѹ��
void init_set(vector<int> &s, vector<int> &rank)
{
	for (int i = 0; i < s.size(); ++i) s[i] = i;
	for (int i = 0; i < rank.size(); ++i) rank[i] = 1;	//�����Լ��ٺ��ڵĲ���
}
int find_key(vector<int> const &s, int x)
{
	while (x != s[x]) x = s[x];	//������
	return x;
}
void union_set(vector<int> &s, vector<int> &rank, int x, int y)
{
	if (find_key(s, x) == find_key(s, y)) return;
	if (rank[x] > rank[y]) s[y] = x;
	else if (rank[x] == rank[y])	//�ȸ߼�������
	{
		s[x] = y;
		++rank[y];
	}
	else s[x] = y;
}



//Prim�㷨�����С������(ȫ��Ȩֵ)
//ģ����POJ1251
//��л����http://www.cnblogs.com/Veegin/archive/2011/04/29/2032388.html�ṩ���������
int prim(vector<vector<int> > const &g)
{
	int n = g.size();	//������
	int sum = 0;
	vector<bool> vst(n, false);	//visited�����Ѿ�������
	vector<int> closest(n);
	vst[0] = true;
	int pos = 0;
	for (int i = 1; i < n; ++i)
	{
		closest[i] = g[0][i];	//��ʼ����������
									//�������㵼��key��Ա�������ǵ�������Ͼ������д
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int min = INF;
		for (int j = 0; j < n; ++j)
		{
			if (!vst[j] && closest[j] < min)
			{
				min = closest[j];
				pos = j;
			}
		}
		vst[pos] = true;	//�ֶ����������pos
								//���Կ���һ��priority_queue��ôд��������
									//�㵼��쳲��������������Լ�Ҳ˵����һ�����۵�׷�������˰�
		sum += min;	//������Ȩֵ��Ϊ���
						//�����Ҫ���Ļ�����ط�Ӧ������������
		for (int j = 0; j < n; ++j)
		{
			if (!vst[j] && closest[j] > g[j][pos])
			{
				closest[j] = g[j][pos];	//��������������µĵ�
			}
		}
	}
	return sum;
}