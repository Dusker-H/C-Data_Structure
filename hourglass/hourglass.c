#include<stdio.h>

int main() {

	int height;

	while (1) {
		printf("크기를 입력하시오: "); //크기 입력

		while (scanf("%d", &height) != 1) { // 크기입력, 문자입력 예외처리
			// 잘못된 입력 메시지출력
			printf("잘못된 입력입니다. 정수가 아닙니다.\n");

			while (getchar() != '\n'); //버퍼 지우기

			printf("크기를 입력하세요:");
		}

		if (height < 3) {
			printf("3이상의 정수를 입력하세요.\n");
			break;
		}
		else if(height<'a' || 'z'<height) {

		}

		int odd = 1; //초기 홀 수값 입력


		if (height % 2 == 0) { //짝수인 경우 높히를 맞춘다.
			height = height - 1;
			odd = 0;
		}

		// 중간 출력이 *인지, & 인지 알려주는 변수
		int center = (height + 1) / 2;

		// 홀수인 경우
		if (odd == 1)
		{
			for (int i = 1; i <= height; i++) {

				if (i == 1 || i == height) { // 첫째줄 마지막 줄 출력
					for (int j = 1; j <= height; j++) {
						printf("*");
						if (j == height) {
							//printf("\n");
						}
					}

				}
				else if (1 < i && i < (height / 2 + 1)) //두번째 줄부터 가운데 줄 전까지의 출력 
				{
					if (i % 2 == 0) { //짝수 Layer 
						for (int j = 1; j <= height; j++) {
							if (j == i || j == height - i + 1) {
								printf("&");
							}
							else {
								printf(" ");
							}
						}
					}
					else { // 홀수 Layer
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
				// 중간 & 출력
				else if (i == (height / 2 + 1)) {
					for (int i = 0; i < height / 2; i++)
						printf(" ");
					if (center % 2 == 0)
						printf("&");
					else
						printf("*");
				}

				else { // 두번째 줄부터 마지막 줄 전까지의 출력
					if (i % 2 == 0) { //짝수 Layer 
						for (int j = 1; j <= height; j++) {
							if (j == i || j == height - i + 1) {
								printf("&");
							}
							else {
								printf(" ");
							}
						}
					}
					else { // 홀수 Layer
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
		// 짝수인 경우
		else {

			for (int i = 1; i <= height; i++) { //첫번째 줄 마지막 줄 출력
				if (i == 1 || i == height) {
					for (int j = 1; j <= height + 1; j++)
						printf("*");
				}
				else if (1 < i && i < (height / 2 + 1)) // 두번째 줄 부터 가운데 줄 전까지의 출력
				{
					if (i % 2 == 0) { //짝수 Layer 
						for (int j = 1; j <= height + 1; j++) {
							if (j == i || j == height + 2 - i) {
								printf("&");
							}
							else {
								printf(" ");
							}
						}
					}
					else { // 홀수 Layer
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
				// 중간 출력
				else if (i == (height / 2 + 1)) {
					// 띄어쓰기
					for (int i = 0; i < (height + 1) / 2 - 1; i++)
						printf(" ");
					if (center % 2 == 0)
						printf("&&");
					else
						printf("**");
				}
				else { //가운데 줄 부터 마지막 줄 전까지의 출력
					if (i % 2 == 0) { //짝수 Layer 
						for (int j = 1; j <= height + 1; j++) {
							if (j == i + 1 || j == height + 1 - i) {
								printf("&");
							}
							else {
								printf(" ");
							}
						}
					}
					else { // 홀수 Layer
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