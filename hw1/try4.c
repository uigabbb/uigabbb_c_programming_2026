#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 승패 판정
int getWinner(int p1, int p2) {
    if (p1 == p2) return 0;
    if ((p1 == 1 && p2 == 3) ||
        (p1 == 2 && p2 == 1) ||
        (p1 == 3 && p2 == 2)) return 1;
    return 2;
}

// 현재 라운드 이름 출력
void printRound(int roundSize) {
    if (roundSize == 8) printf("\n📢 [8강]\n");
    else if (roundSize == 4) printf("\n📢 [4강]\n");
    else if (roundSize == 2) printf("\n📢 [결승]\n");
}

// 안전한 입력 처리
int getPlayerInput() {
    int input, result;

    while (1) {
        printf("가위(1), 바위(2), 보(3) 중 선택: ");
        result = scanf("%d", &input);

        if (result != 1) {
            printf("⚠️ 숫자를 입력하세요!\n");
            while (getchar() != '\n');
            continue;
        }

        if (input >= 1 && input <= 3) return input;
        else printf("⚠️ 1, 2, 3 중에서 다시 입력하세요!\n");
    }
}

int getComputerInput() {
    return rand() % 3 + 1;
}

// 플레이어 경기
int playerMatch(int comp, int roundSize) {
    int p, c, result;

    printf("\n=================================\n");
    printf("🎮 [%d강] 플레이어 vs 컴퓨터%d\n", roundSize, comp);
    printf("=================================\n");

    while (1) {
        p = getPlayerInput();
        c = getComputerInput();

        printf("👉 플레이어: %d / 컴퓨터%d: %d\n", p, comp, c);

        result = getWinner(p, c);

        if (result == 0) {
            printf("🤝 비겼습니다! 재경기 진행!\n");
        }
        else if (result == 1) {
            printf("✅ 플레이어 승리!\n");
            return 0;
        }
        else {
            printf("❌ 컴퓨터%d 승리!\n", comp);
            return 1;
        }
    }
}

// 컴퓨터 경기 (출력 없음)
int computerMatch() {
    int c1, c2, result;

    while (1) {
        c1 = getComputerInput();
        c2 = getComputerInput();
        result = getWinner(c1, c2);

        if (result != 0) return result;
    }
}

int main() {
    srand(time(NULL));

    printf("=================================\n");
    printf("🎯 가위바위보 토너먼트 시작!\n");
    printf("총 8명 참가 (플레이어 포함)\n");
    printf("👉 3번 이기면 최종 우승!\n");
    printf("=================================\n");

    int players[8] = {0,1,2,3,4,5,6,7};
    int roundSize = 8;

    while (roundSize > 1) {
        int next[8];
        int idx = 0;

        printRound(roundSize);  // 🔥 여기서 "8강" 출력

        for (int i = 0; i < roundSize; i += 2) {
            int p1 = players[i];
            int p2 = players[i+1];

            if (p1 == 0 || p2 == 0) {
                int comp = (p1 == 0) ? p2 : p1;
                int result = playerMatch(comp, roundSize);

                if (result == 0) next[idx++] = 0;
                else next[idx++] = comp;
            }
            else {
                int result = computerMatch();

                if (result == 1) next[idx++] = p1;
                else next[idx++] = p2;
            }
        }

        for (int i = 0; i < idx; i++) {
            players[i] = next[i];
        }

        roundSize = idx;
    }

    printf("\n=================================\n");
    printf("🏆 최종 결과\n");
    printf("=================================\n");

    if (players[0] == 0)
        printf("🎉 우승! 플레이어가 최종 승리했습니다!\n");
    else
        printf("💻 우승! 컴퓨터%d가 최종 승리했습니다!\n", players[0]);

    return 0;
}