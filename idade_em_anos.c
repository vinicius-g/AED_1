#include <stdio.h>
 
int main() {
    int dias_tot, anos, meses, dias;
    
    scanf("%d", &dias_tot);
    
    anos = dias_tot / 365;
    meses = (dias_tot - (365 * anos)) / 30;
    dias = (dias_tot - (365 * anos)) - (meses * 30);
    
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n",  anos, meses, dias);
 
    return 0;
}
