#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 가위바위보 판정 함수
int play(int user, int computer) {
    if (user == computer) return 0; // 비김

    if ((user == 1 && computer == 3) ||
        (user == 2 && computer == 1) ||
        (user == 3 && computer == 2)) return 1; // 승리

    return -1; // 패배
}

// 입력 함수
int get_input() {
    int n;
    while (1) {
        printf("가위(1) 바위(2) 보(3) 입력: ");
        scanf("%d", &n);

        if (n >= 1 && n <= 3) return n;

        printf("잘못된 입력입니다. 다시 입력하세요.\n");
    }
}

int main() {
    srand(time(NULL));

    int players = 8;
    int round = 1;

    printf("=== 가위바위보 토너먼트 시작 ===\n");

    while (players > 1) {
        printf("\n--- %d라운드 (%d명) ---\n", round, players);

        for (int i = 0; i < players / 2; i++) {
            printf("\n[%d번째 경기]\n", i + 1);

            while (1) {
                int user = get_input();
                int computer = rand() % 3 + 1;

                printf("상대의 선택: %d\n", computer);

                int result = play(user, computer);

                if (result == 0) {
                    printf("비겼습니다! 재경기 진행\n");
                }
                else if (result == 1) {
                    printf("승리!\n");
                    break; // 다음 경기로
                }
                else {
                    printf("패배... 게임 종료\n");
                    exit(0); // 🔥 여기 추가됨 (지는 순간 프로그램 종료)
                }
            }
        }

        players /= 2;
        round++;
    }

    printf("\n=== 최종 우승! ===\n");

    return 0;
}