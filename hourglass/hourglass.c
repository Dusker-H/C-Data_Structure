#include<stdio.h>

int main() {

	int height;

	while (1) {
		printf("ũ�⸦ �Է��Ͻÿ�: "); //ũ�� �Է�

		while (scanf("%d", &height) != 1) { // ũ���Է�, �����Է� ����ó��
			// �߸��� �Է� �޽������
			printf("�߸��� �Է��Դϴ�. ������ �ƴմϴ�.\n");

			while (getchar() != '\n'); //���� �����

			printf("ũ�⸦ �Է��ϼ���:");
		}

		if (height < 3) {
			printf("3�̻��� ������ �Է��ϼ���.\n");
			break;
		}
		else if(height<'a' || 'z'<height) {

		}

		int odd = 1; //�ʱ� Ȧ ���� �Է�


		if (height % 2 == 0) { //¦���� ��� ������ �����.
			height = height - 1;
			odd = 0;
		}

		// �߰� ����� *����, & ���� �˷��ִ� ����
		int center = (height + 1) / 2;

		// Ȧ���� ���
		if (odd == 1)
		{
			for (int i = 1; i <= height; i++) {

				if (i == 1 || i == height) { // ù°�� ������ �� ���
					for (int j = 1; j <= height; j++) {
						printf("*");
						if (j == height) {
							//printf("\n");
						}
					}

				}
				else if (1 < i && i < (height / 2 + 1)) //�ι�° �ٺ��� ��� �� �������� ��� 
				{
					if (i % 2 == 0) { //¦�� Layer 
						for (int j = 1; j <= height; j++) {
							if (j == i || j == height - i + 1) {
								printf("&");
							}
							else {
								printf(" ");
							}
						}
					}
					else { // Ȧ�� Layer
						for (int k = 1; k <= height; k++) {
							if (k == i || k == height - i + 1) {
								printf("*");
							}
							else {
								printf(" ");
							}
						}
					}
				}
				// �߰� & ���
				else if (i == (height / 2 + 1)) {
					for (int i = 0; i < height / 2; i++)
						printf(" ");
					if (center % 2 == 0)
						printf("&");
					else
						printf("*");
				}

				else { // �ι�° �ٺ��� ������ �� �������� ���
					if (i % 2 == 0) { //¦�� Layer 
						for (int j = 1; j <= height; j++) {
							if (j == i || j == height - i + 1) {
								printf("&");
							}
							else {
								printf(" ");
							}
						}
					}
					else { // Ȧ�� Layer
						for (int k = 1; k <= height; k++) {
							if (k == i || k == height - i + 1) {
								printf("*");
							}
							else {
								printf(" ");
							}
						}
					}

				}
				printf("\n");

			}

		}
		// ¦���� ���
		else {

			for (int i = 1; i <= height; i++) { //ù��° �� ������ �� ���
				if (i == 1 || i == height) {
					for (int j = 1; j <= height + 1; j++)
						printf("*");
				}
				else if (1 < i && i < (height / 2 + 1)) // �ι�° �� ���� ��� �� �������� ���
				{
					if (i % 2 == 0) { //¦�� Layer 
						for (int j = 1; j <= height + 1; j++) {
							if (j == i || j == height + 2 - i) {
								printf("&");
							}
							else {
								printf(" ");
							}
						}
					}
					else { // Ȧ�� Layer
						for (int k = 1; k <= height + 1; k++) {
							if (k == i || k == height + 2 - i) {
								printf("*");
							}
							else {
								printf(" ");
							}
						}
					}
				}
				// �߰� ���
				else if (i == (height / 2 + 1)) {
					// ����
					for (int i = 0; i < (height + 1) / 2 - 1; i++)
						printf(" ");
					if (center % 2 == 0)
						printf("&&");
					else
						printf("**");
				}
				else { //��� �� ���� ������ �� �������� ���
					if (i % 2 == 0) { //¦�� Layer 
						for (int j = 1; j <= height + 1; j++) {
							if (j == i + 1 || j == height + 1 - i) {
								printf("&");
							}
							else {
								printf(" ");
							}
						}
					}
					else { // Ȧ�� Layer
						for (int k = 1; k <= height + 1; k++) {
							if (k == i + 1 || k == height + 1 - i) {
								printf("*");
							}
							else {
								printf(" ");
							}
						}
					}

				}
				printf("\n");
			}
		}

	}
	return 0;
}