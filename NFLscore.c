#include <stdio.h>
int main() {
    int score;
    while (1){
        printf("Please enter a number: ");
        scanf("%d", &score);

        if (score == 0 || score == 1) {
            break; 
        } else {
            for (int td2 = 0; td2 <= score / 8; td2++) {
                for (int td1 = 0; td1 <= score / 7; td1++) {
                    for (int td = 0; td <= score / 6; td++) {
                        for (int fg = 0; fg <= score / 3; fg++) {
                            for (int saf = 0; saf <= score / 2; saf++) {
                                int total = score - (td2 * 8 + td1 * 7 + td * 6 + fg * 3 + saf * 2);
                                if (total == 0) {
                                printf("%d TD + 2pt, %d TD + FG, %d RD, %d FG, %d Safety\n", td2, td1, td, fg, saf);
                            }
                        }
                    }
                }
            }

        }
    }

    }

    return 0;
}
