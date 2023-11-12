#include "Stdafx.h"
#include "Kruskal.h"

//   0   1   2   3   4
//   5   6   7   8   9
//   10  11  12  13  14
//   15  16  17  18  19
//
// ��� 20��
// ���� 31��
// ���õǴ� ������ ������ 19��
// �Ÿ��� ª�� ������� ���Խ�Ų�� -> vector��  �ֱ�
// ����Ŭ�� ������ �ʴ´�. -> ����Ŭ�� ����� ������ ���� �ʴ´�.
//
// ������ ������ ���� 16���� �̴´�.
// �������� ���� ������ ���� ������ ��� ���� 10, ���� 20 �� ����ġ�� ���Ϳ� �����Ѵ�.
// �˰����� ���� ����Ŭ�� ���� �ʴ� ���θ� �����Ѵ�.
// �� ���� �κа�, �� �κ�, ���� ���κп� ������ ���̹����� ����ϰԲ��ϰ�
// �������� �̺�Ʈ �� ���� ���� �����Ͽ� �� �̹����� �����Ѵ�.
int Kruskal::findParent(vector<int>& parent, int node)
{
	if (parent[node] == node)
	{
		if (parent[node] == node)
		{
			return node;
		}
	}

	return parent[node] = findParent(parent, parent[node]);
}

vector<Edge> Kruskal::kruskal(vector<Edge>& edges, int numNodes)
{
	vector<Edge> minimumSpanningTree;
	vector<int> parent(numNodes);

	for (int i = 0; i < numNodes; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < edges.size(); i++)
	{
		int rootFromX = findParent(parent, edges[i].fromX);
		int rootFromY = findParent(parent, edges[i].fromY);
		int rootToX = findParent(parent, edges[i].toX);
		int rootToY = findParent(parent, edges[i].toY);

		if (rootFromX != rootToX)
		{
			if(rootFromY != rootToY)
			minimumSpanningTree.push_back(edges[i]);
			parent[rootFromX] = rootToX;
			parent[rootFromY] = rootToY;
		}
	}

	return minimumSpanningTree;
}

int Kruskal::generateMap(int nodeNumber)
{
	int numNodes = nodeNumber;
	vector<Edge> edges;

	edges.push_back(Edge(0, 1, 0, 2, 10));
	edges.push_back(Edge(0, 2, 0, 3, 10));
	edges.push_back(Edge(0, 2, 1, 2, 10));
	edges.push_back(Edge(1, 2, 1, 3, 10));
	edges.push_back(Edge(1, 2, 2, 2, 10));
	edges.push_back(Edge(2, 2, 3, 2, 10));
	edges.push_back(Edge(3, 2, 3, 3, 10));
	edges.push_back(Edge(3, 3, 3, 4, 10));

	vector<Edge> minimumSpanningTree = kruskal(edges, numNodes);

	return 0;
}
