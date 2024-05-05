#include <stdio.h>
#define PI 3.14

int main()
{
    float cube_length, cube_area, cube_volume;
    float prism_length, prism_height, prism_width, prism_area, prism_volume;
    float radius, syphere_area, syphere_volume;
    float cone_radius, cone_height, cone_area, cone_volume;

    printf("Enter the edge length for cube:");//cube
    scanf("%f", &cube_length);
    cube_area = cube_length * cube_length * 6;
    cube_volume = cube_length * cube_length * cube_length;
    printf("Surface Area = %.2f, Volume = %.2f\n", cube_area, cube_volume);

    printf("Enter side length for rectangular prism:");//prism
    scanf("%f", &prism_length);
    printf("Enter side width:");
    scanf("%f", &prism_width);
    printf("Enter side height:");
    scanf("%f", &prism_height);
    prism_area = 2 * ((prism_height * prism_length) + (prism_length * prism_width) + (prism_height * prism_width));
    prism_volume = prism_height * prism_length * prism_width;
    printf("Surface Area = %.2f, Volume = %.2f\n", prism_area, prism_volume);

    printf("Enter the radius for sphere:");//syphere
    scanf("%f", &radius);
    syphere_area = 4 * PI * radius * radius;
    syphere_volume = (4 * PI * radius * radius * radius)/3;
    printf("Surface Area = %.2f, Volume = %.2f\n", syphere_area, syphere_volume);

    printf("Enter the radius for cone:");//cone
    scanf("%f", &cone_radius);
    printf("Enter the height:");
    scanf("%f", &cone_height);
    cone_area = (PI * cone_radius) * (cone_height + cone_radius);
    cone_volume =  (PI * cone_radius * cone_radius)/3;
    printf("Surface Area = %.2f, Volume = %.2f\n", cone_area, cone_volume);

    float bmi,body_height,body_weight;
    
    printf("Please enter weight and height:");
    scanf("%f",&body_weight);
    scanf("%f",&body_height);
    bmi= body_weight/(body_height*body_height);

    if(bmi<18.5) printf("Underweight\n");
    else if(bmi>=18.5 && bmi<=24.9 ) printf("Average Weight\n");
    else if(bmi<25 && bmi<=29.9 ) printf("Overweight\n");
    else if(bmi>=30) printf("Obese\n");


return 0;

}