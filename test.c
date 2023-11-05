#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

#define min(a, b) \
((a) < (b) ? (a) : (b))

// typedef 

void trim(char *s) {

    if (NULL == s) {
        return;
    }

    int len = strlen(s);
    if (0 == len) {
        return ;
    }

    int i = len - 1;
    while(s[i] <= 0x20 || s[i] > 0x7E) {
        s[i] = '\0';
        i--;
    }

    return ;
}

typedef struct _tmp_ {
    int idx;
    char name[32];
    int score;
}MAN;

int cmp(const void *p1, const void *p2) {
    MAN *a = (MAN *)p1;
    MAN *b = (MAN *)p2;

    // 分数升序
    int ret = a->score - b->score;
    if (ret != 0)
    {
        return ret;
    }

    // 分数相同时, 按照索引降序排列
    ret = b->idx - a->idx;

    return ret;
}

int main(int argc, char *argv[])
{
    int msgCnt = 0;
    char buff[BUFF_SIZE];

    fgets(buff, BUFF_SIZE, stdin);
    msgCnt = atoi(buff);

    MAN *a = (MAN *)malloc(msgCnt * sizeof(MAN));
    memset(a, 0x00, msgCnt * sizeof(MAN));

    int cnt = 0;

    while(1) {

        if (cnt >= msgCnt) {
            break;
        }

        memset(buff, 0x00, BUFF_SIZE * sizeof(char));
        fgets(buff, BUFF_SIZE, stdin);
        trim(buff);
        if (0 == strlen(buff)) {
            break;
        }

        char *tk = strtok(buff, " ");
        a[cnt].idx = cnt;
        strcpy(a[cnt].name, tk);

        tk = strtok(NULL, " ");
        a[cnt].score = atoi(tk);

        cnt++;
    }

    qsort(a, msgCnt, sizeof(MAN), cmp);

    int mid = (msgCnt + 1) / 2 - 1;
    int anchor = a[mid].score;

    int t = mid;
    while((t > 0) && (a[t - 1].score == anchor)) {
        t--;
    }

    printf("results:\n");
    while((t < msgCnt) && (a[t].score == anchor)) {
        printf("%s %d\n", a[t].name, a[t].score);
        t++;
    }

    if (a != NULL) {
        free(a);
        a = NULL;
    }

    return 0;
}