#include <stdio.h>
#include <conio.h>

  int main(){
    int n, s;
    int t1 = 0, t2 = 1;
    int tt = t1 + t2;
    printf("Numero de termos: ");
    scanf("%d", &n );
    for (s = 3 ; s <= n ; ++s){
        printf("%d", tt);
        t1 = t2;
        t2 = tt;
        tt = t1 + t2;
          if (s < n)
            printf(",");
          else
            printf(".");
    }
    getch();
    return 0;
}
