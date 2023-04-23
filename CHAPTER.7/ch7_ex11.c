#include <stdio.h>
#include<unistd.h>
/* cost in $ per pound */
#define artichokes 2.05
#define beets 1.15
#define carrots 1.09
/* for order of $100 or above */
#define discount 0.95
/* shipping */
#define cost1 6.50 /* 0-5 pounds */
#define cost2 14.00 /* 5-20 pounds */
/* above 20 pounds costs $14.00 + 
$0.50 for any additional pound */
int main(void){
    char bin;
    int choice, qartichokes = 0, qbeets = 0, qcarrots = 0, quantity, pounds = 0;
    float delivery;
    do
    {
        printf("\n\t\tThis is your cart");
        printf("\n****************************************************");
        printf("\nEnter the number corresponding with desired product:");
        printf("\n");
        printf("\n1) Artichokes\t\t\t\t    x %d"
        "\n2) Beets\t\t\t\t    x %d"
        "\n3) Carrots\t\t\t\t    x %d" 
        " \n\n4) CHECKOUT"
        "\n5) CANCEL ORDER", qartichokes, qbeets, qcarrots);
        printf("\n****************************************************\n");
        printf("\n\t\t\t\tTotal pounds: %d\n", pounds);
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter pounds of artichokes: ");
            scanf("%d", &quantity);
            qartichokes += quantity;
            pounds += quantity;
            break;
        case 2:
            printf("\nEnter pounds of beets: ");
            scanf("%d", &quantity);
            qbeets += quantity;
            pounds += quantity;
            break; 
        case 3:
            printf("\nEnter pounds of carrots: ");
            scanf("%d", &quantity);
            qcarrots += quantity;            
            pounds += quantity;
            break;       
        /* CHECKOUT */
        case 4:
            printf("\n\n\t\t     CHECKOUT");
            printf("\n****************************************************");
            printf("\nArticle:\t\tPounds:\t\tCost:");
            qartichokes > 0 ? printf("\nArtichokes\t\tx %d\t\t$%0.2f",
            qartichokes, qartichokes * artichokes): sleep(0);
            qbeets > 0 ? printf("\nBeets\t\t\tx %d\t\t$%0.2f",
            qbeets, qbeets * beets): sleep(0);
            qcarrots > 0 ? printf("\nCarrots\t\t\tx %d\t\t$%0.2f",
            qcarrots, qcarrots * carrots): sleep(0);
            printf("\n****************************************************");
            if (pounds < 5)
                delivery = cost1;
            else if (pounds <20)
                delivery = cost2;
            else
                delivery = cost2 + (pounds - 20) * 0.50;
            
            printf("\nDelivery\t\t\t\t$%0.2f", delivery);
            printf("\n\t\t\t\tTotal: $%0.2f", qartichokes * artichokes + qbeets * beets +
             qcarrots * carrots + delivery);
            printf("\nDo you confirm order?");
            printf("\n1) Yes");
            printf("\n2) No\n\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\nThank you for shopping!!\n\n");
                return 0;
            case 2:
                continue;
            default:
                printf("\nERROR! WRONG DECLARATION!");
                while((bin = getchar()) != '\n');
                continue;
            }

        /* CANCEL ORDER */
        case 5:
            printf("\nDo you want to quit?");
            printf("\n1) Yes");
            printf("\n2) No\n\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\nBYE!\n\n");
                return 0;
            case 2:
                continue;
            default:
                printf("\nERROR! WRONG DECLARATION!");
                while((bin = getchar()) != '\n');
                continue;
            }
            break;
        default:
            printf("\nERROR! WRONG DECLARATION!");
            while((bin = getchar()) != '\n');
            continue;
        }        





    } while (1);
    
    return 0;
}