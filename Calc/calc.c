#include<stdio.h>
#include<math.h>

int main(void)
{
	float num1, num2;
	char op;

	printf("�Է�: ");
	scanf("%f", &num1);
	getchar();			//���� ����

	do {
		printf("�Է�: ");
		scanf("%c", &op);
		getchar();

		if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q') {
			printf("�����ڸ� �Է��ؾ� �մϴ�.\n");
		}
	} while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q');

	while (1) { // ������

		if (op == '+') {	// ���ϱ� ����
			printf("�Է�: ");
			scanf("%f", &num2);
			getchar();
			num1 = num1 + num2;
			printf("%f\n", num1); //��� �� ���

			do {	// ���� ���� �ִ� ���¿��� ������ �Է¹ޱ�
				printf("�Է�: ");
				scanf("%c", &op);
				getchar();

				if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q') { //������ Ȥ�� q�� �Է����� �������
					printf("�����ڸ� �Է��ؾ� �մϴ�.\n");
				}
				else if (op == 'q')	// q�� �Է��� ��� ���� �ݺ��� Ż��
				{
					break;
				}

			} while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q'); //������ Ȥ�� q�� �Է��� ������ �ݺ�

		}

		else if (op == '-') { // ���� ����
			printf("�Է�: ");
			scanf("%f", &num2);
			getchar();
			num1 = num1 - num2;
			printf("%f\n", num1);
			do {

				printf("�Է�: ");
				scanf("%c", &op);
				getchar();

				if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q') {
					printf("�����ڸ� �Է��ؾ� �մϴ�.\n");
				}
				else if (op == 'q')
				{
					break;
				}

			} while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q');

		}

		else if (op == '*') { // ���ϱ� ����
			printf("�Է�: ");
			scanf("%f", &num2);
			getchar();
			num1 = num1 * num2;
			printf("%f\n", num1);
			do {
				printf("�Է�: ");
				scanf("%c", &op);
				getchar();

				if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q') {
					printf("�����ڸ� �Է��ؾ� �մϴ�.\n");
				}
				else if (op == 'q') {
					break;
				}

			} while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q');
		}
		else if (op == '/') { // ������ ����
			printf("�Է�: ");
			scanf("%f", &num2);
			getchar();

			if (num2 == 0) { // 0 �Է� ó��
				printf("0���� ���������ϴ�.\n");
			}
			else {
				num1 = num1 / num2;
				printf("%f\n", num1);
			}

			do {
				printf("�Է�: ");
				scanf("%c", &op);
				getchar();

				if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q') {
					printf("�����ڸ� �Է��ؾ� �մϴ�.\n");
				}
				else if (op == 'q') {
					break;
				}
			} while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q');

		}
		else if (op == 'p') { // �ŵ� ���� ����
			printf("�Է�: ");
			scanf("%f", &num2);
			getchar();
			num1 = pow(num1, num2);
			printf("%f\n", num1);
			do {
				printf("�Է�: ");
				scanf("%c", &op);
				getchar();

				if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q') {
					printf("�����ڸ� �Է��ؾ� �մϴ�.\n");
				}
				else if (op == 'q') {
					break;
				}
			} while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q');
		}
		else if (op == 's') { // ������ ����
			num1 = sqrt(num1);
			printf("%f\n", num1);
			do {
				printf("�Է�: ");
				scanf("%c", &op);
				getchar();

				if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q') {
					printf("�����ڸ� �Է��ؾ� �մϴ�.\n");
				}
				else if (op == 'q') {
					break;
				}
			} while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'p' && op != 's' && op != 'q');
		}
		else if (op == 'q') { // ����
			break;
		}

	}
}