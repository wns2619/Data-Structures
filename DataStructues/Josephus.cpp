#include "Josephus.h"
#include <iostream>
#include "Queue.h"
using namespace std;

void Josephus::Run()
{
	int n = 7, k = 3; // set n and k to the desired values

	Queue<int> q(n + 1);
	q.SetDebugFlag(false);

	// ó���� n�� �߰� (1, 2, ..., n)
	for (int i = 1; i <= n; i++)
		q.Enqueue(i);
	q.Print();

	// ������ �� ���� ���� ������ �ݺ�
	while (q.Size() != 1)
	{
		// k-1 ���� �� �տ��� �ڷ� ������
		for (int i = 0; i < k - 1; ++i)
		{
			int value = q.Front();
			q.Dequeue();
			q.Enqueue(value);
		}

		// k ��° ��� ó��
		cout << "Executed " << q.Front() << endl;
		q.Dequeue();
	}

	// ������ ������ ��ȣ
	cout << "Survivor: " << q.Front() << endl;
}
