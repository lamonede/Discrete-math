#include <stdio.h>
#include <stdbool.h>

bool reflextion(int pair[], int aggregation[], int size_of_pair, int size_of_aggregation);
bool symmetric(int pair[], int size_of_pair);
bool transitive(int pair[], int size_of_pair);

int main(){
    int array[] = {1, 2, 3, 4};
    int ordered_pair[12] = {1, 1,/**/ 1, 2,/**/ 2, 1,/**/ 2, 2,/**/ 3, 3,/**/ 4, 4};
    int size_pair = (sizeof(ordered_pair)/4);
    int size_aggregation = (sizeof(array)/4);

    if(reflextion(ordered_pair, array, size_pair, size_aggregation)){   //Reflextion
        printf("Reflexive relation\n\n");
    } else {
        printf("Not Reflexive relation\n\n");
    }

    if(symmetric(ordered_pair, size_pair)){                             //Symmetric
        printf("Symmetric relation\n\n");
    } else {
        printf("Not Symmetric relation\n\n");
    }

    if(transitive(ordered_pair, size_pair)){                            //Transitive
        printf("Transitive relation\n\n");
    }   else {
        printf("Not Transitive relation\n\n");
    }

    if((reflextion(ordered_pair, array, size_pair, size_aggregation)) && (symmetric(ordered_pair, size_pair)) && (transitive(ordered_pair, size_pair))){
        printf("Equivalence relation");
    } else {
        printf("Not Equivalence relation");
    }
    

    return 0;
}

bool symmetric(int pair[], int size_of_pair){
    int i, j = 0; 
    int TF = 0;
    for (i = 0; i < size_of_pair; i = i + 2){
        for(j = 0; j < size_of_pair; j = j + 2){
            if(pair[i] != pair[i+1]){   //if (pair isn't reflexive relation)
                if((pair[i+1] == pair[j]) && (pair[i] == pair[j+1])){ // True, Symmerty relation
                    TF++;
                    //printf("Corret! : (%d, %d) With (%d, %d)\n", pair[j], pair[j+1], pair[i], pair[i+1]);
                    break;
                } else {
                    //printf("Not Corret! : (%d, %d) With (%d, %d)\n", pair[j], pair[j+1], pair[i], pair[i+1]);
                }
            } else { //reflexive relation
                TF++;
                //printf("Pair (%d, %d) is Reflexive!\n", pair[i], pair[i+1]);
                break;
            }
        }
        //printf("\n");
    }
    if((size_of_pair/2 - TF)%2 == 1){ //나머지가 홀수라면
        //printf("\n\n");
        return false;
    } else {                          //나머지가 짝수라면
        //printf("\n\n");
        return true;
    }
}

bool reflextion(int pair[], int aggregation[], int size_of_pair, int size_of_aggregation){ //순서쌍,집합, 순서쌍의 크기, 집합의 크기
    int i, j = 0;
    int TF = 0; //True False, if TF value over num_aggregation
    for(i = 0; i < size_of_aggregation; i++){ //집합
        for(int j = 0; j < size_of_pair; j = j + 2){
            if((pair[j] == pair[j+1]) && (pair[j+1] == aggregation[i])){ //순서쌍 j번 == 순서쌍 j+1번 && 순서쌍 j+1번 == 집합 i번
                TF++;
                //printf("Corret! : (%d, %d), %d\n", pair[j], pair[j+1], aggregation[i]);
                break;
            } else{
                //printf("Not Correct! : (%d, %d), %d\n", pair[j], pair[j+1], aggregation[i]);
            }
        }
    }
    if(TF == size_of_aggregation){
        return true;
    } else {
        return false;
    }
}

bool transitive(int pair[], int size_of_pair){
    int i, j, k, l = 0;
    int tmp_x, tmp_y = 0;
    int TF = 1;
    for(i = 0; i < size_of_pair; i = i + 2){
        for(j = 0; j < size_of_pair; j = j + 2){
            if(i != j){ //Detect location, Same location -> End loop
                //printf("Other location!: (%d, %d), (%d, %d)\n", pair[i], pair[i+1], pair[j], pair[j+1]);
                if(pair[i+1] == pair[j]){ //ex: (x,y), (y,z) detect y
                    tmp_x = pair[i];
                    tmp_y = pair[j+1]; //tmp_x,y is need to find.
                    for(k = 0; k < size_of_pair; k = k +2){
                        if(TF < size_of_pair/2){
                            if(((tmp_x == pair[k]) && (tmp_y == pair[k+1]))){
                                //printf("Find! : (%d, %d) With (%d, %d), (%d, %d)\n", tmp_x, tmp_y, pair[i], pair[i+1], pair[j], pair[j+1]);
                                TF = 0;
                                break;
                            } else {
                                //printf("Can't Find!\n");
                                TF++;
                            }
                        } else {
                            return false;
                        }
                    }
                }

            } else {
                //printf("Same location! : (%d, %d), (%d, %d)\n", pair[i], pair[i+1], pair[j], pair[j+1]);
                break;
            }
        }
    }
}