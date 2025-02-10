#include <stdio.h>
#include <math.h>

int main() {
    int D, VF, VG;

    while (scanf("%d %d %d", &D, &VF, &VG) != EOF) {
        double Tf = 12.0 / VF;
        double Dg = sqrt(D * D + 144);
        double Tg = Dg / VG;

        if (Tg <= Tf) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
}