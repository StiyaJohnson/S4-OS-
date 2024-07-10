#include<stdio.h>
#include<string.h>

struct process {
    int AT, BT, WT, TT, status, left;
    char pname[10];
} p[10], temp;

struct gantt {
    int ST, CT;
    char pname[10];
} g[50];

void main() {
    int n, i = 0, j = 0, k = 0, m, idle = 0, flag, ls = 0, num = 0;
    float wait = 0, turn = 0;

    printf("Enter the number of process\n");
    scanf("%d", &n);

    for (m = 0; m < n; m++) {
        printf("Enter name, AT, BT\n");
        scanf("%s%d%d", p[m].pname, &p[m].AT, &p[m].BT);
        p[m].status = 0;
        p[m].left = p[m].BT;
    }

    while (ls < n) {
        flag = 0;
        for (j = 0; j < n; j++) {
            if ((p[j].status == 0) && (p[j].AT <= i) && (flag == 0)) {
                k = j;
                flag++;
            }
            if ((p[j].status == 0) && (p[j].AT <= i) && (flag > 0)) {
                if (p[j].left < p[k].left) {
                    k = j;
                }
            }
        }

        if ((flag == 0) && (idle == 0)) {
            strcpy(g[num].pname, "idle");
            g[num].ST = i;
            idle = 1;
            i++;
        } else if (flag > 0) {
            if (idle == 1) {
                g[num].CT = i;
                idle = 0;
                num++;
            }
            strcpy(g[num].pname, p[k].pname);
            g[num].ST = i;
            if (p[k].left <= 1) {
                g[num].CT = i + p[k].left;
                i = g[num].CT;
                p[k].TT = g[num].CT - p[k].AT;
                p[k].WT = p[k].TT - p[k].BT;
                p[k].status = 1;
                num++;
                ls++;
            } else {
                g[num].CT = i + 1;
                i = i + 1;
                p[k].left = p[k].left - 1;
                num++;
            }
        } else {
            i++;
        }
    }

    printf("Name\tAT\tBT\tTT\tWT\n");
    for (m = 0; m < n; m++) {
        printf("%s\t%d\t%d\t%d\t%d\n", p[m].pname, p[m].AT, p[m].BT, p[m].TT, p[m].WT);
        wait = wait + p[m].WT;
        turn = turn + p[m].TT;
    }

    printf("\nGantt chart\n");
    printf("\n---------------------------------------------------------------------------\n");
    printf("|");
    for (m = 0; m < num; m++) {
        if (strcmp(g[m].pname, g[m + 1].pname) == 0) {
            continue;
        } else {
            printf("%s\t|", g[m].pname);
        }
    }
    printf("\n---------------------------------------------------------------------------\n");
    printf("%d\t", g[0].ST);
    for (m = 0; m < num; m++) {
        if (strcmp(g[m].pname, g[m + 1].pname) == 0) {
            continue;
        } else {
            printf("%d\t", g[m].CT);
        }
    }

    printf("\nAverage waiting time = %f", wait / n);
    printf("\nAverage turnaround time = %f\n", turn / n);
}