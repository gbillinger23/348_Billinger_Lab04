#include <stdio.h>

// Conversion Functions
float celsius_to_fahrenheit(float celsius){
	float fahrenheit;
	fahrenheit = ((celsius*(9.0/5.0)) + 32.00);
	return fahrenheit;
}

float fahrenheit_to_celsius(float fahrenheit){
	float celsius;
	celsius = ((fahrenheit - 32.00)*(5.0/9.0));
	return celsius;
}

float celsius_to_kelvin(float celsius){
	float kelvin;
	kelvin = celsius + 273.15;
	return kelvin;
}

float kelvin_to_celsius(float kelvin){
	float celsius;
	celsius = kelvin - 273.15;
	return celsius;
}

// This function saves some range checks later.
int inRange(int value) {
	// Handle range error
	if ((value > 3) || (value < 0)){
		int i = 0;
		while (i == 0) {
			printf("Invalid range input. Please retry (1-3): ");
			scanf("%d", &value);
			getchar();
			if ((value < 4) && (value > 0)) {
				i = 1;
			}
		}
	}
	return value;
}

// Grab weather category!
void categorize_temperature(float celsius){
	if (celsius < 0){
		printf("Temperature category: Freezing\n");
		printf("Weather advisory: Stay inside.");
	}
	else if ((celsius > -1) && (celsius < 11)){
		printf("Temperature category: Cold\n");
		printf("Weather advisory: Wear layers.");
	}
	else if ((celsius > 10) && (celsius < 26)){
		printf("Temperature category: Comfortable\n");
		printf("Weather advisory: Go outside! It's a beautiful day!");
	}
	else if ((celsius > 25) && (celsius < 36)){
		printf("Temperature category: Hot\n");
		printf("Weather advisory: Drink plenty of water.");
	}
	else if (celsius > 35){
		printf("Temperature category: Extreme Heat\n");
		printf("Weather advisory: Avoid the outdoors.");
	}
}

// It helps if the inputs are separate functions.
float temp_input(){
	float temp;
	printf("Provide temperature: ");
	scanf("%f", &temp);
	getchar(); //I gotta kill the newline every time.
	return temp;
}

int scale_input(){
	int scale;
	printf("Provide the scale (1) Celsius (2) Fahrenheit (3) Kelvin: ");
	scanf("%d", &scale);
	getchar();
	scale = inRange(scale);
	return scale;
}

int convert_input(){
	int convert;
	printf("Provide the conversion (1) Celsius (2) Farenheit (3) Kelvin: ");
	scanf("%d", &convert);
	getchar();
	convert = inRange(convert); // Make sure convert is 1-3.
	return convert;
}

int main(){
	// Declare input variables
	float temp;
	int scale;
	int convert;

	// First step. Grab temperature.
	temp = temp_input();
	scale = scale_input();
	scale = inRange(scale);

	// Error checking time...
	int j = 0;
	while (j == 0){
		j = 1;
		// Handle extreme temp values.
		if ((temp < 0) && (scale == 3)){ // Kelvin case
			int i = 0;
			while (i == 0){
				printf("Kelvin cannot be negative. Pick another temperature scale (1-2): ");
				scanf("%d", &scale);
				getchar();
				scale = inRange(scale);
				if ((scale < 3)) {
					i = 1;
				}
			}
		}	
		else if ((temp < -273) && (scale == 1)){ //Celsius case
			int i = 0;
			while (i == 0){
				printf("Celsius cannot be below -273°C. Pick another temperature scale (2): ");
				scanf("%d", &scale);
				getchar();
				scale = inRange(scale);
				if (scale == 2){
					i = 1;
				}
			}
		}
		else if ((temp < -459.66) && (scale == 2)){
			int i = 0;
			while (i == 0){
				printf("Fahrenheit can not be below -459.66F. Provide different temp value: ");
				scanf("%f", &temp);
				getchar();
				if (temp > -459.67){
					i = 1;
				}
			}
			// In this case we need to re-check for errors..
			j = 0; // This flips our while loop back on.
		}
	}

	convert = convert_input();

	// Handle same conversion error.
	if (scale == convert) {
		int i = 0;
		while (i == 0){
			printf("Can not convert to same scale. Pick different conversion (1-3): ");
			scanf("%d", &convert);
			getchar();
			convert = inRange(convert);
			if (convert != scale) {
					i = 1;
			}
		}
	}
	
	// With that errors should be handled!

	// First let's grab the celsius value of temp because we need to have it regardless.
	float celsius;
	if (scale == 1) {
		celsius = temp;
	}
	else if (scale == 2) {
		celsius = fahrenheit_to_celsius(temp);
	}
	else if (scale == 3) {
		celsius = kelvin_to_celsius(temp);
	}
	
	if (scale == 1) { // A switch case might have been better...oh well.
		if (convert == 2) {
			temp = celsius_to_fahrenheit(temp);
			printf("Converted temperature: %.2fF\n", temp);
		}
		else if (convert == 3) {
			temp = celsius_to_kelvin(temp);
			printf("Converted temperature: %.2fK\n", temp);
		}
	}
	else if (scale == 2) {
		if (convert == 1) {
			temp = celsius;
			printf("Converted temperature: %.2f°C\n", temp);
		}
		else if (convert == 3) {
			temp = celsius_to_kelvin(celsius);
			printf("Converted temperature: %.2fK\n", temp);
		}
	}
	else if (scale == 3) {
		if (convert == 1) {
			temp = celsius;
			printf("Converted temperature: %.2fC\n", temp);
		}
		else if (convert == 2) {
			temp = celsius_to_fahrenheit(celsius);
			printf("Converted temperature: %.2fF\n", temp);
		}
	}
	// Print the weather status stuff
	categorize_temperature(celsius);
	return 0;
}
