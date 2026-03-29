#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 숫자를 가위/바위/보로 변환
char* rps(int n) {
    if (n == 1) return "가위";
    if (n == 2) return "바위";
    return "보";
}

// 승패 판정
int play(int p1, int p2) {
    if (p1 == p2) return 0;

    if ((p1 == 1 && p2 == 3) ||
        (p1 == 2 && p2 == 1) ||
        (p1 == 3 && p2 == 2)) return 1;

    return -1;
}

// 입력 받기
int get_input() {
    int n;
    while (1) {
        printf("👉 1(가위) 2(바위) 3(보) 입력: ");
        scanf("%d", &n);

        if (n >= 1 && n <= 3) return n;

        printf("❌ 잘못된 입력입니다. 다시 입력하세요.\n");
    }
}

// 컴퓨터 선택
int computer_choice() {
    return rand() % 3 + 1;
}

// 한 경기 진행 (UI 포함)
int match(int p1, int p2, int round, int match_num) {
    while (1) {
        printf("\n[ %d강 %d경기 ]\n", round, match_num);
        printf("P1: %s vs P2: %s\n", rps(p1), rps(p2));

        int result = play(p1, p2);

        if (result == 1) {
            printf("👉 P1 승리!\n");
            return p1;
        }
        else if (result == -1) {
            printf("👉 P2 승리!\n");
            return p2;
        }

        // 무승부
        printf("⚠️ 비겼습니다! 재경기 진행...\n");
        // 같은 선택 유지 (조건 충족)
    }
}

int main() {
    srand(time(NULL));

    int players[8];

    printf("=================================\n");
    printf("   🎮 8명 토너먼트 가위바위보 🎮\n");
    printf("=================================\n");

    // 사용자 입력
    printf("\n당신의 선택을 입력하세요.\n");
    players[0] = get_input();

    // 나머지 컴퓨터
    for (int i = 1; i < 8; i++) {
        players[i] = computer_choice();
    }

    // 8강
    int round4[4];
    printf("\n========== 🏁 8강 ==========\n");
    for (int i = 0; i < 4; i++) {
        round4[i] = match(players[i * 2], players[i * 2 + 1], 8, i + 1);
    }

    // 4강
    int final[2];
    printf("\n========== 🏁 4강 ==========\n");
    for (int i = 0; i < 2; i++) {
        final[i] = match(round4[i * 2], round4[i * 2 + 1], 4, i + 1);
    }

    // 결승
    printf("\n========== 🏆 결승 ==========\n");
    int winner = match(final[0], final[1], 2, 1);

    printf("\n=================================\n");
    printf("🏆 최종 우승: %s !!!\n", rps(winner));
    printf("=================================\n");

    return 0;
}