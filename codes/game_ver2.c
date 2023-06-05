#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 암산 문제를 생성하는 함수
int generateMathProblem(int difficulty) {
    srand((unsigned int)time(0));

    int num1, num2, answer;
    char operator_ = '+';

    switch (difficulty) {
    case 1:
        num1 = rand() % 9 + 1;
        num2 = rand() % 9 + 1;
        break;
    case 2:
        num1 = rand() % 90 + 10;
        num2 = rand() % 90 + 10;
        break;
    case 3:
        num1 = rand() % 900 + 100;
        num2 = rand() % 900 + 100;
        break;
    }

    switch (rand() % 4) {
    case 0:
        operator_ = '+';
        answer = num1 + num2;
        break;
    case 1:
        operator_ = '-';
        if (num1 < num2) {  // num1이 항상 num2보다 크거나 같게 함
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
        answer = num1 - num2;
        break;
    case 2:
        operator_ = '*';
        answer = num1 * num2;
        break;
    case 3:
        operator_ = '/';
        num2 = (num2 == 0) ? 1 : num2;  // 0으로 나누는 경우를 방지
        num1 = num1 * num2;  // 결과가 정수가 되도록 num1을 조정
        answer = num1 / num2;
        break;
    }

    printf("문제: %d %c %d = ?\n", num1, operator_, num2);
    return answer;
}



int main() {
    srand((unsigned int)time(0));

    int money = 5000;
    int betAmount;
    int userChoice, compChoice;
    int difficulty, answer, userAnswer;
    printf("Press any key to start game\n");

    while (1) {
        printf("\nYour balance: %d\n", money);
        do {
            printf("Input your bet (100원 단위): ");
            scanf_s("%d", &betAmount);
            if (betAmount % 100 != 0)
                printf("배팅액은 100원 단위로만 가능합니다.\n");
        } while (betAmount % 100 != 0);

        printf("Choose Rock(1), Scissor(2), Paper(3)  \n\nRock Scissor Paper!\n ");
        scanf_s("%d", &userChoice);

        compChoice = rand() % 3 + 1;

        if (userChoice == compChoice) {
            printf("비겼습니다. 다시 가위바위보 게임을 시작합니다.\n");
            continue;
        }
        else if ((userChoice == 1 && compChoice == 2) || (userChoice == 2 && compChoice == 3) || (userChoice == 3 && compChoice == 1)) {
            printf("You Lose!\n");
            printf("Your balance: %d\n", money);

            printf("Choose Level (1: 한 자리 수, 2: 두 자리 수, 3: 세 자리 수): ");
            scanf_s("%d", &difficulty);

            answer = generateMathProblem(difficulty);
            printf("Your answer : ");
            scanf_s("%d", &userAnswer);

            if (userAnswer == answer) {
                printf("Correct.\n");
            }
            else {
                printf("wrong\n");
                money -= betAmount;
            }
        }
        else {
            printf("You Win!\n");
            printf("Your balance: %d\n", money);
            printf("1: calculate 2: RSC ", money);
            scanf_s("%d", &userChoice);
            if (userChoice == 1)
            {
                printf("Choose Level (1: 한 자리 수, 2: 두 자리 수, 3: 세 자리 수): ");
                scanf_s("%d", &difficulty);

                answer = generateMathProblem(difficulty);
                printf("Your answer : ");
                scanf_s("%d", &userAnswer);

                if (userAnswer == answer) {
                    printf("Correct. 배팅 금액을 두배로 얻습니다.\n");
                    money += betAmount*2;
                }
                else {
                    printf("틀렸습니다. 배팅 금액을 잃습니다.\n");
                    money -= betAmount*2;
                }
            }
            else
            {
                money += betAmount;
            }

        }

        if (money <= 0) {
            printf("Loser!\n");
            break;
        }
        if (money >= 9000) {
            printf("Winner!\n");
            break;
        }
    }

    return 0;
}
