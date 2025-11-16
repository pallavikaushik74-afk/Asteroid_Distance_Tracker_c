#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    double distance;  // million km from Earth
    double diameter;  // km
    int isHazardous;
} Asteroid;

void displayAsteroids(Asteroid asteroids[], int count);
void findNearest(Asteroid asteroids[], int count);
void checkHazardous(Asteroid asteroids[], int count);

int main() {
    Asteroid asteroids[6] = {
        {"Apophis", 31.0, 0.37, 1},
        {"Bennu", 85.0, 0.49, 1},
        {"Eros", 22.0, 16.8, 0},
        {"Ryugu", 95.0, 0.90, 0},
        {"Didymos", 10.5, 0.78, 0},
        {"Toutatis", 18.0, 4.5, 1}
    };
    
    int choice;
    printf("    ASTEROID DISTANCE TRACKER\n");
    
    do {
        printf("\n1. View All Asteroids\n");
        printf("2. Find Nearest Asteroid\n");
        printf("3. Show Hazardous Asteroids\n");
        printf("4. Exit\n");
        printf("\nChoice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                displayAsteroids(asteroids, 6);
                break;
            case 2:
                findNearest(asteroids, 6);
                break;
            case 3:
                checkHazardous(asteroids, 6);
                break;
            case 4:
                printf("\nStay safe! Keep watching the skies.\n\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice != 4);
    
    return 0;
}

void displayAsteroids(Asteroid asteroids[], int count) {
    printf("         TRACKED ASTEROIDS\n");
    
    for(int i = 0; i < count; i++) {
        printf("\n%d. %-12s", i+1, asteroids[i].name);
        printf("Distance: %6.1f M km  ", asteroids[i].distance);
        printf("Size: %5.2f km", asteroids[i].diameter);
        
        if(asteroids[i].isHazardous) {
            printf("  [HAZARDOUS]");
        }
        printf("\n");
    }
    
    printf("\nNote: Moon distance = 0.38 M km\n");
}

void findNearest(Asteroid asteroids[], int count) {
    int nearest = 0;
    
    for(int i = 1; i < count; i++) {
        if(asteroids[i].distance < asteroids[nearest].distance) {
            nearest = i;
        }
    }
    printf("      NEAREST ASTEROID TO EARTH\n");
    printf("Name: %s\n", asteroids[nearest].name);
    printf("Distance: %.1f million km\n", asteroids[nearest].distance);
    printf("Diameter: %.2f km\n", asteroids[nearest].diameter);
    printf("Status: %s\n", 
           asteroids[nearest].isHazardous ? "Potentially Hazardous" : "Safe");
    
    double moonDist = 0.384;
    printf("\nThat's %.1fx farther than the Moon!\n", 
           asteroids[nearest].distance / moonDist);
}

void checkHazardous(Asteroid asteroids[], int count) {
    printf("     POTENTIALLY HAZARDOUS ASTEROIDS\n");
    
    int hazardCount = 0;
    
    for(int i = 0; i < count; i++) {
        if(asteroids[i].isHazardous) {
            hazardCount++;
            printf("\n%d. %s\n", hazardCount, asteroids[i].name);
            printf("   Distance: %.1f million km\n", asteroids[i].distance);
            printf("   Size: %.2f km\n", asteroids[i].diameter);
        }
    }
    
    printf("\n%d out of %d asteroids are hazardous.\n", hazardCount, count);
    printf("\nThese are monitored by NASA and ESA.\n");
}