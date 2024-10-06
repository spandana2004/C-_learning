#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Test {
  float driver_bar_mass, slip_table_mass, armature_mass;
  float ms, mr;
  char PCD[10];
};

void sine_and_random_force_lateral_test(struct Test *t, float weight, float fixture_mass,float max_acc_sine_test, float max_acc_random_test);

void sine_and_random_force_longitudinal_test(struct Test *t, float weight, float fixture_mass,float max_acc_sine_test, float max_acc_random_test);

void lateral_axis_test(struct Test *t,float weight, float fixture_mass,float max_acc_sine_test, 
float max_acc_random_test,float max_dis,float sine_force_rating[],float random_force_rating[],float slip_table_displacement[],int shaker[]);

void longitudinal_axis_test(struct Test *t,float weight, float fixture_mass,float max_acc_sine_test,
 float max_acc_random_test,float max_dis,float sine_force_rating[],float random_force_rating[],float armature_displacement[],int shaker[]);

int main() 
{
  int test_choice;

  float weight, fixture_mass, max_acc_sine_test, max_dis, max_acc_random_test;

  struct Test t[6];

  t[0].driver_bar_mass = 0.0;
  t[0].slip_table_mass = 90.0;
  t[0].armature_mass = 22.7;

  t[1].driver_bar_mass = 18.14;
  t[1].slip_table_mass = 92.5;
  t[1].armature_mass = 61.3;

  t[2].driver_bar_mass = 30.35;
  t[2].slip_table_mass = 257.27;
  t[2].armature_mass = 45.45;

  t[3].driver_bar_mass = 23.0;
  t[3].slip_table_mass = 139.5;
  t[3].armature_mass = 49.5;

  t[4].driver_bar_mass = 32.0;
  t[4].slip_table_mass = 368.5;
  t[4].armature_mass = 49.5;

  t[5].driver_bar_mass = 50.0;
  t[5].slip_table_mass = 192.0;
  t[5].armature_mass = 100.0;

  float sine_force_rating[] = {2722, 5500, 6400, 10700, 10700, 15000};
  float random_force_rating[] = {2722, 5500, 5680, 10700, 10700, 15000};
  float slip_table_displacement[] = {25.4, 6, 7, 22.5, 20, 6};
  float armature_displacement[] = {25.4, 25, 10, 25.4, 25.4, 8};
  int shaker[] = {2, 6, 8, 10, 10, 16};


  printf("The following the the test:\nEnter 1 for lateral axis test\nEnter 2 "
         "for longitudinal axis test\n");
  printf("Enter your choice of test:");
  scanf("%d", &test_choice);

  if (test_choice == 1) {
    lateral_axis_test(t, weight, fixture_mass, max_acc_sine_test, max_acc_random_test, max_dis,sine_force_rating,
                        random_force_rating,slip_table_displacement,shaker);
  }
  else if(test_choice == 2){
    longitudinal_axis_test(t, weight, fixture_mass, max_acc_sine_test, max_acc_random_test, max_dis, sine_force_rating, 
                        random_force_rating, armature_displacement, shaker);
  }
  else
    printf("The test choice is incorrect!\n");
    
  return 0;
}

void sine_and_random_force_lateral_test(struct Test *t, float weight, float fixture_mass,
                           float max_acc_sine_test, float max_acc_random_test) {
  for (int i = 0; i < 6; i++) {
    t[i].ms = (weight + fixture_mass + t[i].driver_bar_mass +
               t[i].slip_table_mass + t[i].armature_mass) *
              max_acc_sine_test;
    t[i].mr = (weight + fixture_mass + t[i].driver_bar_mass +
               t[i].slip_table_mass + t[i].armature_mass) *
              max_acc_random_test;
  }
}

void sine_and_random_force_longitudinal_test(struct Test *t, float weight, float fixture_mass,
                           float max_acc_sine_test, float max_acc_random_test) {
  for (int i = 0; i < 6; i++) {
    t[i].ms = (weight + fixture_mass + t[i].armature_mass) * max_acc_sine_test;
    t[i].mr = (weight + fixture_mass + t[i].driver_bar_mass + t[i].slip_table_mass) * max_acc_random_test;
  }
}

void lateral_axis_test(struct Test *t,float weight, float fixture_mass,float max_acc_sine_test, float max_acc_random_test,
                        float max_dis,float sine_force_rating[],float random_force_rating[],float slip_table_displacement[],int shaker[])
{
  printf("\n------------------------ENTER THE TEST DETAILS-------------------------\n");
  printf("enter weight of the package (in kg):");
    scanf("%f", &weight);
    printf("enter fixture mass of the package (in kg) in lateral test:");
    scanf("%f", &fixture_mass);
    printf("enter the maximum acceleration (in 'g') for sine test:");
    scanf("%f", &max_acc_sine_test);
    printf("enter the maximum displacement (in mm) for sine test:");
    scanf("%f", &max_dis);
    printf("enter maximum acceleration for the random test ('g in rms'):");
    scanf("%f", &max_acc_random_test);
    int i;
  
  printf("\n---------------------THE SUITABLE SHAKER ARE------------------------\n");
    for (i = 0; i < 6; i++) {
      sine_and_random_force_lateral_test(t, weight, fixture_mass, max_acc_sine_test,
                            max_acc_random_test);

      if ((t[i].ms < sine_force_rating[i]) &&
             (t[i].mr < random_force_rating[i]) &&
             (max_dis < slip_table_displacement[i]))
        printf("%d ton\n", shaker[i]);
    }
}

void longitudinal_axis_test(struct Test *t,float weight, float fixture_mass,float max_acc_sine_test, 
float max_acc_random_test,float max_dis,float sine_force_rating[],float random_force_rating[],float armature_displacement[],int shaker[])
{
  printf("\n------------------------ENTER THE TEST DETAILS-------------------------\n");
  printf("enter weight of the package (in kg):");
    scanf("%f", &weight);
    printf("enter fixture mass of the package (in kg) in longitudinal test:");
    scanf("%f", &fixture_mass);
    printf("enter the maximum acceleration (in 'g') for sine test:");
    scanf("%f", &max_acc_sine_test);
    printf("enter the maximum displacement (in mm) for sine test:");
    scanf("%f", &max_dis);
    printf("enter maximum acceleration for the random test ('g in rms'):");
    scanf("%f", &max_acc_random_test);
    int i;
  printf("\n---------------------THE SUITABLE SHAKER ARE-----------------------\n");
    for (i = 0; i < 6; i++) {
      sine_and_random_force_longitudinal_test(t, weight, fixture_mass, max_acc_sine_test,
                            max_acc_random_test);

      if ((t[i].ms < sine_force_rating[i]) &&
             (t[i].mr < random_force_rating[i]) &&
             (max_dis < armature_displacement[i]))
        printf("%d ton\n", shaker[i]);
    }
}