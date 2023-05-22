#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playRPS();
int mentalArithmetic(int level);

int main() {
    srand(time(0));
    int balance = 5000;
    int bet = 0;
    int RPSresult, calculationResult;
    int calculationLevel;

    while (balance > 0 && balance < 9000) {
        printf("현재 잔액: %d\n", balance);
        do {
            printf("배팅 금액을 입력하세요(100원 단위): ");
            scanf("%d", &bet);
        } while (bet % 100 != 0);

        RPSresult = playRPS();

        if (RPSresult == 1) { // 가위바위보에서 이겼을 때
            printf("암산을 하시겠습니까? (1: 네, 2: 아니오): ");
            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                printf("암산 난이도를 선택하세요. (1: 한자리, 2: 두자리, 3: 세자리): ");
                scanf("%d", &calculationLevel);
                calculationResult = mentalArithmetic(calculationLevel);

                if (calculationResult == 1) { // 암산에서 이겼을 때
                    balance += bet * 2; // 배팅액의 2배를 획득
                }
                else { // 암산에서 졌을 때
                    balance -= bet * 2; // 배팅액의 2배를 잃음
                }
            }
            else { // 암산을 안 할 경우
                balance += bet; // 배팅액을 획득
            }
        }
        else { // 가위바위보에서 졌을 때
            printf("암산 난이도를 선택하세요. (1: 한자리, 2: 두자리, 3: 세자리): ");
            scanf("%d", &calculationLevel);
            calculationResult = mentalArithmetic(calculationLevel);

            if (calculationResult == 0) { // 암산에서 졌을 때
                balance -= bet; // 배팅액을 잃음
            }
            // 암산에서 이겼을 경우, 배팅액을 잃지 않음

        }
    }

    printf("게임이 끝났습니다. 최종 잔액은 %d원 입니다.\n", balance);

    return 0;
}

int playRPS() {
    int playerChoice, computerChoice;

    printf("가위바위보를 선택하세요. (1: 가위, 2: 바위, 3: 보): ");
    scanf("%d", &playerChoice);

    computerChoice = rand() % 3 + 1;

    if (playerChoice == computerChoice) {
        printf("비겼습니다! 다시 가위바위보를 합니다.\n");
        return playRPS();
    }
    else if ((playerChoice == 1 && computerChoice == 3) || (playerChoice == 2 && computerChoice == 1) || (playerChoice == 3 && computerChoice == 2)) {
        printf("이겼습니다!\n");
        return 1;
    }
    else {
        printf("졌습니다...\n");
        return 0;
    }
}

int mentalArithmetic(int level) {
    int num1, num2, correctAnswer, playerAnswer;
    char operators[] = { '+', '-', '*', '/' };
    char chosenOperator = operators[rand() % 4];

    if (level == 1) {
        num1 = rand() % 10;
        num2 = rand() % 10;
    }
    else if (level == 2) {
        num1 = rand() % 100;
        num2 = rand() % 100;
    }
    else if (level == 3) {
        num1 = rand() % 1000;
        num2 = rand() % 1000;
    }

    if (chosenOperator == '+') {
        correctAnswer = num1 + num2;
    }
    else if (chosenOperator == '-') {
        correctAnswer = num1 - num2;
    }
    else if (chosenOperator == '*') {
        correctAnswer = num1 * num2;
    }
    else if (chosenOperator == '/') {
        correctAnswer = num1 / num2;
    }

    printf("다음의 문제를 푸세요: %d %c %d = ? ", num1, chosenOperator, num2);
    scanf("%d", &playerAnswer);

    if (playerAnswer == correctAnswer) {
        printf("정답입니다!\n");
        return 1;
    }
    else {
        printf("오답입니다...\n");
        return 0;
    }
}
