#include <stdio.h>
enum Scale {
    CELSIUS,
	FAHRENHEIT
};
union Temperature{
	float celsius;
	float fahrenheit;
};
struct TemperatureData {
    union Temperature value;
    enum Scale scale;
};

void convertTemp(struct TemperatureData data) {
    float convertedTemp;
    if (data.scale == CELSIUS) {
		float fahrenheit = (data.value.celsius*9/5+32);
        printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n",data.value.celsius, fahrenheit);
    } else {
		convertedTemp = (data.value.fahrenheit - 32)*5/9;
		float celsius = (data.value.fahrenheit-32)*5/9;
        printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n",data.value.fahrenheit,celsius);
    }
}

int main() {
    struct TemperatureData tempData;
    printf("Enter temperature value: ");
    scanf("%f", &tempData.value.celsius);
    printf("Choose scale (0 for Celsius, 1 for Fahrenheit): ");
    scanf("%d", (int*)&tempData.scale);
    if (tempData.scale != CELSIUS && tempData.scale != FAHRENHEIT) {
        printf("Invalid scale choice.\n");
        return 1;
    }
    convertTemp(tempData);
    return 0;
}
