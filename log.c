#include <stdio.h>
#include <string.h>
#include "walk.h"
#include "log.h"



int loadData(Walk *w) {
    int count = 0, i = 0;
    FILE *fp;
    char line[100];
    if((fp = fopen("walk.txt", "rt")) == NULL) {
        printf("\n=> 파일 없음\n");
        return 0;
    };
    for(i=0 ; i<100 ; i++){
        if(feof(fp)) break;
        fscanf(fp, "%s %d %d %[^\n]s", w[i].day, &w[i].time, &w[i].weather, w[i].place);
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return i;
}

void saveData(Walk *w, int count) {
    FILE *fp;
    fp = fopen("walk.txt", "wt");
    for(int i=0 ; i<count-1 ; i++) {
        if(w[i].time == -1) continue;
        fprintf(fp, "%s %d %d %s\n", w[i].day, w[i].time, w[i].weather, w[i].place);
    }
    fprintf(fp, "%s %d %d %s", w[count-1].day, w[count-1].time, w[count-1].weather, w[count-1].place);
    fclose(fp);
    printf("=> 저장됨!\n");
}
