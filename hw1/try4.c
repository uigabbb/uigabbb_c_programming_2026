#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 가위바위보 출력
char* rps(int n) {
    if (n == 1) return "가위";
    if (n == 2) return "바위";
    return "보";
}

// 승패 판단
int play(int p1, int p2) {
    if (p1 == p2) return 0;

    if ((p1 == 1 && p2 == 3) ||
        (p1 == 2 && p2 == 1) ||
        (p1 == 3 && p2 == 2)) return 1;

    return -1;
}

// 사용자 입력
int get_input() {
    int n;
    while (1) {
        printf("👉 1(가위) 2(바위) 3(보) 입력: ");
        scanf("%d", &n);

        if (n >= 1 && n <= 3) return n;
        printf("❌ 다시 입력하세요.\n");
    }
}

// 컴퓨터 선택
int computer_choice() {
    return rand() % 3 + 1;
}

// 경기 진행
int match(int round, int match_num, int isUserMatch) {
    int p1, p2;

    while (1) {
        if (isUserMatch) {
            printf("\n당신의 차례입니다!\n");
            p1 = get_input();
        } else {
            p1 = computer_choice();
        }

        p2 = computer_choice();

        if (round == 2)
            printf("\n[ 결승 ]\n");
        else
            printf("\n[ %d강 %d경기 ]\n", round, match_num);

        printf("P1: %s vs P2: %s\n", rps(p1), rps(p2));

        int result = play(p1, p2);

        if (result == 1) {
            printf("👉 P1 승리!\n");
            return 1;
        }
        else if (result == -1) {
            printf("👉 P2 승리!\n");
            return 0;
        }

        printf("⚠️ 비겼습니다! 재경기 진행...\n");
    }
}

int main() {
    srand(time(NULL));

    printf("=================================\n");
    printf("   🎮 8명 토너먼트 가위바위보 🎮\n");
    printf("=================================\n");

    int players[8] = {1,0,0,0,0,0,0,0}; // 1 = 사용자

    int next[4];

    // ===== 8강 =====
    printf("\n========== 🏁 8강 ==========\n");

    for (int i = 0; i < 4; i++) {
        int isUserMatch = players[2*i] || players[2*i+1];
        int winner = match(8, i+1, isUserMatch);

        if (winner == 1)
            next[i] = players[2*i];
        else
            next[i] = players[2*i+1];
    }

    int next2[2];

    // ===== 4강 =====
    printf("\n========== 🏁 4강 ==========\n");

    for (int i = 0; i < 2; i++) {
        int isUserMatch = next[2*i] || next[2*i+1];
        int winner = match(4, i+1, isUserMatch);

        if (winner == 1)
            next2[i] = next[2*i];
        else
            next2[i] = next[2*i+1];
    }

    // ===== 결승 =====
    printf("\n========== 🏆 결승 ==========\n");

    int isUserMatch = next2[0] || next2[1];
    int winner = match(2, 1, isUserMatch);

    int finalWinner;
    if (winner == 1)
        finalWinner = next2[0];
    else
        finalWinner = next2[1];

    printf("\n=================================\n");
    if (finalWinner)
        printf("🏆 당신이 우승했습니다!!!\n");
    else
        printf("🏆 컴퓨터가 우승했습니다.\n");
    printf("=================================\n");

    return 0;
}