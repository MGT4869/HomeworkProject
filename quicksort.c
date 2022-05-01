#include <stdio.h>
#include <stdlib.h>


int quicksort(int*a, int len){
    quicksort_r(a,0,len-1);
    return 0;
}
int quicksort_r(int* a,int start,int end){
    if (start>=end) {
        return 0;
    }
    int pivot=a[end];
    int swp;
    //set a pointer to divide array into two parts
    //one part is smaller than pivot and another larger
    int pointer=start;
    int i;
    for (i=start; i<end; i++) {
        if (a[i]<pivot) {
            if (pointer!=i) {
                //swap a[i] with a[pointer]
                //a[pointer] behind larger than pivot
                swp=a[i];
                a[i]=a[pointer];
                a[pointer]=swp;
            }
            pointer++;
        }
    }
    //swap back pivot to proper position
    swp=a[end];
    a[end]=a[pointer];
    a[pointer]=swp;
    quicksort_r(a,start,pointer-1);
    quicksort_r(a,pointer+1,end);
    return 0;
}

int main(){
    int a[50];
    int len=NULL;
    printf("정렬할 숫자 갯수를 입력해주세요.\n");
    scanf("%d",&len);
    printf("숫자를 %d개만큼 입력해주세요. 주의 최대 40개 숫자까지만 가능합니다.\n",len);
    for(int j=0;j<len;j++)
    {
        scanf("%d",&a[j]);
    }
    quicksort(a,len);
    printf("정렬된 결과는 아래와 같습니다.\n");
    int i;
    for (i=0; i<len; i++) {
        printf("%d  ",a[i]);
    }
    printf("\n");
    return 0;
}