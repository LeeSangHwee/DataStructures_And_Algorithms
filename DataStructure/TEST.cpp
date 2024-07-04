#include <iostream>
#include <cmath>

int main()
{
	// 테스트 케이스, T의 갯수 입력
	int T = 0;	
	std::cin >> T;

	// 골드바흐의 수, n을 T의 갯수만큼 입력
	int* n = new int[T];
	for (int i = 0; i < T; i++)
	{
		// 4이상 10000이하의 골드바흐의 수, 짝수 n입력
		n[i] = 5;
		while ((4 <= n[i] && n[i] <= 10000) && !(n[i] % 2 == 0))
			std::cin >> n[i];
	}
	
	// 테스트 케이스의 갯수(T)만큼 골드바흐의 수(n)의 파티션을 구하는 알고리즘
	for (int i = 0; i < T; i++)
	{
		// 초기화
		int a = 2, b = n[i] - a;
		int print_data[3] = { a + b, a, b };

		// 골드바흐의 파티션을 구하는 알고리즘
		while (a <= n[i] - 2)
		{
			// 소수 구하는 알고리즘
			for (int sqrt_a = 2; sqrt_a <= sqrt(a); sqrt_a++)
				if (a % sqrt_a == 0)
					goto REPEAT_ALGORITHM;
			for (int sqrt_b = 2; sqrt_b <= sqrt(b); sqrt_b++)
				if (b % sqrt_b == 0)
					goto REPEAT_ALGORITHM;

			// 위에서 구한 소수끼리의 차이 값과 기존에 있던 소수의 가장 작은 차이 값을 비교해서 바꾸는 알고리즘
			if (print_data[0] > abs(a - b))
			{
				print_data[0] = a + b;
				print_data[1] = a;
				print_data[2] = b;
			}

		REPEAT_ALGORITHM:
			// 위에서 구한 두 소수의 차이가 0일 경우 더 이상 반복물을 돌 필요가 없으므로 반복문을 탈출하는 알고리즘
			if (a - b == 0) break;			
			// 계속 반복해야 한다면 반복할 때마다 알고리즘 값 변경
			else ++a, b = n[i] - a;
		}
		// 골드바흐의 파티션을 구하는 알고리즘에서 파티션을 구한 후 출력
		printf("%d %d\n", print_data[1], print_data[2]);
	}
	return 0;
}