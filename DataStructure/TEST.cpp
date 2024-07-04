#include <iostream>
#include <cmath>

int main()
{
	// �׽�Ʈ ���̽�, T�� ���� �Է�
	int T = 0;	
	std::cin >> T;

	// �������� ��, n�� T�� ������ŭ �Է�
	int* n = new int[T];
	for (int i = 0; i < T; i++)
	{
		// 4�̻� 10000������ �������� ��, ¦�� n�Է�
		n[i] = 5;
		while ((4 <= n[i] && n[i] <= 10000) && !(n[i] % 2 == 0))
			std::cin >> n[i];
	}
	
	// �׽�Ʈ ���̽��� ����(T)��ŭ �������� ��(n)�� ��Ƽ���� ���ϴ� �˰���
	for (int i = 0; i < T; i++)
	{
		// �ʱ�ȭ
		int a = 2, b = n[i] - a;
		int print_data[3] = { a + b, a, b };

		// �������� ��Ƽ���� ���ϴ� �˰���
		while (a <= n[i] - 2)
		{
			// �Ҽ� ���ϴ� �˰���
			for (int sqrt_a = 2; sqrt_a <= sqrt(a); sqrt_a++)
				if (a % sqrt_a == 0)
					goto REPEAT_ALGORITHM;
			for (int sqrt_b = 2; sqrt_b <= sqrt(b); sqrt_b++)
				if (b % sqrt_b == 0)
					goto REPEAT_ALGORITHM;

			// ������ ���� �Ҽ������� ���� ���� ������ �ִ� �Ҽ��� ���� ���� ���� ���� ���ؼ� �ٲٴ� �˰���
			if (print_data[0] > abs(a - b))
			{
				print_data[0] = a + b;
				print_data[1] = a;
				print_data[2] = b;
			}

		REPEAT_ALGORITHM:
			// ������ ���� �� �Ҽ��� ���̰� 0�� ��� �� �̻� �ݺ����� �� �ʿ䰡 �����Ƿ� �ݺ����� Ż���ϴ� �˰���
			if (a - b == 0) break;			
			// ��� �ݺ��ؾ� �Ѵٸ� �ݺ��� ������ �˰��� �� ����
			else ++a, b = n[i] - a;
		}
		// �������� ��Ƽ���� ���ϴ� �˰��򿡼� ��Ƽ���� ���� �� ���
		printf("%d %d\n", print_data[1], print_data[2]);
	}
	return 0;
}