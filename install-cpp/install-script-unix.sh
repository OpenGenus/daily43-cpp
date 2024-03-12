#!/bin/bash

# Function to check if a command is available
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Check if g++ is already installed
if command_exists g++; then
    echo "g++ is already installed."
else
    # Install g++
    sudo apt update
    sudo apt install g++
    
    # Check if installation was successful
    if command_exists g++; then
        echo "g++ has been successfully installed."
    else
        echo "Failed to install g++."
        exit 1
    fi
fi