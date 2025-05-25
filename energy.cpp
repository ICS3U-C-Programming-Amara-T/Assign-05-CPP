// Copyright (c) 2025 Amara Tie All rights reserved.
//
// Created by: Amara Tie
// Date: May 22, 2025
// This is a program calculates energy!
#include <cmath>
#include <iostream>
#include <string>

float energy(float massFloat) {
    const float c = 299792458;

    // Calculate the energy
    return massFloat * pow(c, 2);
}

float mass2(float energy2Float) {
    const float c = 299792458;

    // Calculate the mass
    return energy2Float / pow(c, 2);
}
int main() {
    float massFloat;
    std::string energy2;
    std::string choice;
    std::string unit;
    std::string mass;
    float energy2Float;

    // Greeting.
    std::cout
        << "Hello! Let's find energy using Einstein's equation!" << std::endl;

    // Get the mass from the user
    while (true) {
        std::cout << "Enter mass (positive number): ";
        std::cin >> mass;
        // Convert mass from a string to a float
        try {
            massFloat = std::stof(mass);

            if (massFloat < 0) {
                std::cout << "Mass must be positive. Try again.\n";
                continue;
            }

            // Ask for Units
            while (true) {
                std::cout << "Enter unit: ";
                std::cin >> unit;
                // Check if the units is kg
                if (unit == "kg") {
                    break;
                } else {
                    std::cout
                    << "Invalid unit! In Physics, we measure mass in kg.\n";
                    continue;
                }
            }
            break;
        } catch (std::invalid_argument) {
            std::cout << "That was not a number. \n";
        }
    }

        // Call the function
        float answer = energy(massFloat);

        // Display the energy
        std::cout << "Energy = " << answer << "J" << std::endl;

        // Calculate the mass using Einstein's equation.
        std::cout <<
        "Would you like to calculate your mass? (Yes or No)"
        << std::endl;
        std::cin >> choice;

        if (choice == "Yes") {
            // Display new rearranged formula
            std::cout << "Your new formula is m = E/c^2" << std::endl;
            // User enters energy to calculate the mass
            std::cout << "Please enter your Energy (J): ";
            std::cin >> energy2;
            // Convert the input to a float
            try {
                energy2Float = std::stof(energy2);

                // Call function
                float answer2 = mass2(energy2Float);
                std::cout << "mass = " << answer2 << "kg" << std::endl;
            } catch (std::invalid_argument) {
                std::cout << "That was not a number.";
            }
        } else if (choice == "No") {
            std::cout << "Alright, Thanks for playing!" << std::endl;
        } else {
            std::cout << "Invalid Input. Enter Yes or No!" << std::endl;
        }
    }
