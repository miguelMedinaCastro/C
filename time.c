#include <stdio.h>

int main() {
    
    int n;
    printf("Enter the number of seconds: ");
    scanf("%d", &n);
    int hours = n / 3600; 
    int min = (n % 3600) / 60;
    int seg = n % 60;
        
    printf("%d:%d:%d\n", hours, min, seg);

    return 0;
}
