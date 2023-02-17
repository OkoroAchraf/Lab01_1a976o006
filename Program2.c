#include <stdio.h>


void print_combination(int eight, int seven, int six, int three, int two){
    printf("%d TD + 2pt. %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", eight, seven , six, three, two);
}

void find_combinations(int score, int eight, int seven, int six, int three, int two, int order) {
  if(score < 0) {
    return;
  }
  if(score == 0){
      print_combination(eight, seven, six, three, two);
      return;
  }

  if(order >= 8) {
    find_combinations(score - 8, eight + 1, seven, six, three, two, 8);
  }
  if(order >= 7) {
    find_combinations(score - 7, eight , seven+ 1, six, three, two, 8);
  }
  if(order >= 6){
    find_combinations(score-6, eight , seven, six+ 1, three, two, 8);
  }
  if(order >= 3){
    find_combinations(score-3, eight, seven, six, three + 1, two, 8);
  }
  if(order >= 2){
    find_combinations(score-2, eight, seven, six, three, two + 1, 8);
  }
}

int main(){
    int score;
    printf("Enter 0 or 1 to STOP\n");
    while(1){
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if(score<=1)break;
        printf("possible combinations of scoring plays:\n");

        find_combinations(score, 0, 0, 0, 0, 0, 8);
    }
    return 0;
}
