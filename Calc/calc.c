#include<stdio.h>
#include<math.h>

int main(void)
{
	float num1, num2;
	char op;

	printf("입력: ");
	scanf("%f", &num1);
	getchar();			//버퍼 제거

	do {
		printf("입력: ");
		scanf("%c", &op);
		getchar();

		if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q') {
			printf("연산자를 입력해야 합니다.\n");
		}
	} while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q');

	while (1) { // 계산시작

		if (op == '+') {	// 더하기 연산
			printf("입력: ");
			scanf("%f", &num2);
			getchar();
			num1 = num1 + num2;
			printf("%f\n", num1); //결과 값 출력

			do {	// 계산된 값이 있는 상태에서 연산자 입력받기
				printf("입력: ");
				scanf("%c", &op);
				getchar();

				if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q') { //연산자 혹은 q를 입력하지 않을경우
					printf("연산자를 입력해야 합니다.\n");
				}
				else if (op == 'q')	// q를 입력할 경우 현재 반복문 탈출
				{
					break;
				}

			} while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q'); //연산자 혹은 q를 입력할 때까지 반복

		}

		else if (op == '-') { // 빼기 연산
			printf("입력: ");
			scanf("%f", &num2);
			getchar();
			num1 = num1 - num2;
			printf("%f\n", num1);
			do {

				printf("입력: ");
				scanf("%c", &op);
				getchar();

				if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q') {
					printf("연산자를 입력해야 합니다.\n");
				}
				else if (op == 'q')
				{
					break;
				}

			} while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q');

		}

		else if (op == '*') { // 곱하기 연산
			printf("입력: ");
			scanf("%f", &num2);
			getchar();
			num1 = num1 * num2;
			printf("%f\n", num1);
			do {
				printf("입력: ");
				scanf("%c", &op);
				getchar();

				if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q') {
					printf("연산자를 입력해야 합니다.\n");
				}
				else if (op == 'q') {
					break;
				}

			} while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q');
		}
		else if (op == '/') { // 나누기 연산
			printf("입력: ");
			scanf("%f", &num2);
			getchar();

			if (num2 == 0) { // 0 입력 처리
				printf("0으로 나누었습니다.\n");
			}
			else {
				num1 = num1 / num2;
				printf("%f\n", num1);
			}

			do {
				printf("입력: ");
				scanf("%c", &op);
				getchar();

				if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q') {
					printf("연산자를 입력해야 합니다.\n");
				}
				else if (op == 'q') {
					break;
				}
			} while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q');

		}
		else if (op == 'p') { // 거듭 제곱 연산
			printf("입력: ");
			scanf("%f", &num2);
			getchar();
			num1 = pow(num1, num2);
			printf("%f\n", num1);
			do {
				printf("입력: ");
				scanf("%c", &op);
				getchar();

				if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q') {
					printf("연산자를 입력해야 합니다.\n");
				}
				else if (op == 'q') {
					break;
				}
			} while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q');
		}
		else if (op == 's') { // 제곱근 연산
			num1 = sqrt(num1);
			printf("%f\n", num1);
			do {
				printf("입력: ");
				scanf("%c", &op);
				getchar();

				if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q') {
					printf("연산자를 입력해야 합니다.\n");
				}
				else if (op == 'q') {
					break;
				}
			} while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q');
		}
		else if (op == 'q') { // 종료
			break;
		}

	}
}