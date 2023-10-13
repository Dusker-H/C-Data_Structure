# C lang assignment

## 문제 : 

간단한 계산기를 만들어보자. 처음에는 실수를 입력 받고, 그 이후로는 연산자, 실수, 연 산자, 실수… 순으로 입력 받는다. 연산은 +, -, *, /, p (거듭제곱 - power 함수를 사용), s(제 곱근 - sqrt 함수를 사용)의 총 6개이다. ‘실수1’ ‘연산자’ ‘실수2’ 까지 총 3개를 입력 받았다면, 해당 연산을 수행한 후 결과가 출력 된다. 예를 들어 입력이 ‘1’ ‘+’ ‘2’ 라면 3이 계산된 후 출력된다. 그러나 제곱근 함수의 경 우에는 ‘실수1’ ‘연산자’ 총 2개만 입력되면 결과가 출력되어야 한다. 그 후에는 ‘연산자(제곱근 제외)’ → ‘실수’ → … 혹은 ‘연산자(제곱근)’ → … 순으로 입력을 받아야 한다. 예를 들어 현재까지 계산된 값이 3인데, 그 후로 ‘-‘ ‘1’을 입력 받았다면 2가 계산된 후 출력되어야 한다. 마찬가지로 제곱근 함수의 경우에는 연산자가 입력되면 바로 계산 후 출력된다. 현재까지 계산된 값이 있는 상태에서 연산자가 아닌 실수 값을 입력 받을 경우 “연산자 를 입력해야 합니다” 라는 메시지를 출력한 후 다시 입력을 받아야 한다. 제곱근이 아닌 연산자가 입력된 후 실수가 입력될 차례에 또다시 연산자가 입력될 경우 는 고려하지 않는다 (에러 처리를 하지 않아도 상관 없음) ‘/’ 후 ‘0’을 입력할 경우 “0으로 나누었습니다”라는 메시지를 출력한 후 다시 입력을 받아 야 한다. 연산자를 입력할 차례에 사용자가 ‘q’ 를 입력하면 종료한다. 예를 들어 실행 화 면은 다음과 같다. 

(빨간 글씨는 사용자 입력이다.) (50점) 

입력: 5.6 

입력: + 

입력: 4.2 9.8 

입력: s 3.130495 

입력: / 입력: 0 

0으로 나누었습니다. 

입력: - 

입력: 3 0.130495 

입력: 3 

연산자를 입력해야 합니다. 

입력: q

### 이번 문제에서 알아야할 내용은 논리연산이다 연산자 '&&'를 사용해서 해당 연산자 입력 이외에 값을 처리하는 과정이 문제 풀이에 핵심이다.

- 또한 do-while 문을 사용해서 올바른 값이 입력될 때까지 

```c
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
```

