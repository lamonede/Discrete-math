#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arr;
    int size;

    printf("만들고 싶은 정수 배열의 크기를 입력하세요: ");
    scanf("%d", &size);

    arr = (int*)malloc(sizeof(int) * size);
    if (arr == NULL) {
        printf("메모리 할당 오류\n");
        return 1;
    }

    printf("배열에 저장할 %d개의 숫자를 입력하세요:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("입력된 숫자들: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}