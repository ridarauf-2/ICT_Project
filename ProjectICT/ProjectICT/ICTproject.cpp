#include<iostream>
using namespace std;
// Function to calculate and display heart rate zones
void HR_Zones(int RestingHR, int MaxHR, int CurrentHR) {
	// Calculating the boundaries for each zone
	int WarmUp = RestingHR + 0.5 * (MaxHR - RestingHR);
	int FatBurn = RestingHR + 0.6 * (MaxHR - RestingHR);
	int Cardio = RestingHR + 0.7 * (MaxHR - RestingHR);
	int Peak = RestingHR + 0.85 * (MaxHR - RestingHR);

	// Displaying the user's heart rate zone
	cout << "\n---------------------------------";
	if (CurrentHR >= WarmUp && CurrentHR <= FatBurn) {
		cout << "\n50%-60% of Target Heart Rate.\nYou are in the Warm-Up Zone.\nFocus on light activities.";
	}
	else if (CurrentHR > FatBurn && CurrentHR <= Cardio) {
		cout << "\n60%-70% of Target Heart Rate.\nYou are in the Fat-Burning Zone.\nGreat for weight loss.";
	}
	else if (CurrentHR > Cardio && CurrentHR <= Peak) {
		cout << "\n70%-85% of Target Heart Rate.\nYou are in the Cardio Zone.\nImproves endurance and heart health.";
	}
	else if (CurrentHR > Peak && CurrentHR <= MaxHR) {
		cout << "\n85%-100% of Target Heart Rate.\nYou are in the Peak Zone.\nFor high-intensity workouts.";
	}
	else {
		cout << "\nInvalid heart rate.";
	}
	cout << "\n---------------------------------\n";
}


int main() {
	int Age, RestingHR, CurrentHR, MaxHR;

	// Greeting the user
	cout << "-------------------------------------------\n";
	cout << "|Welcome to the Heart Rate Zone Calculator|\n";
	cout << "-------------------------------------------\n";

	// Asking for user inputs
	cout << "\nEnter your Age: ";
	cin >> Age;

	do {
		cout << "\nEnter your Resting Heart Rate (60-100 BPM): ";
		cin >> RestingHR;
		if (RestingHR < 60 || RestingHR > 100) {
			cout << "\nInvalid Resting Heart Rate. Please enter a value between 60 and 100 BPM.\n";
		}
	} while (RestingHR < 60 || RestingHR > 100);

	cout << "\nEnter your Current Heart Rate: ";
	cin >> CurrentHR;

	// Calculate MaxHR and validate CurrentHR
	MaxHR = 220 - Age;
	while (CurrentHR < 0 || CurrentHR > MaxHR) {
		cout << "\nInvalid Heart Rate. Please enter a value between 0 and " << MaxHR << " BPM: ";
		cin >> CurrentHR;
	}

	// Call the function to determine the heart rate zone
	HR_Zones(RestingHR, MaxHR, CurrentHR);

	return 0;

}