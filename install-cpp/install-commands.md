## Install C++ and its compiler G++

To install C++ and the GNU Compiler Collection (g++) on your system, follow these general steps based on the operating system you are using.
We have listed steps for Linux, MacOS and Windows.

### For Linux (Ubuntu/Debian):

1. **Open Terminal:**
   - Open a terminal window by pressing CTRL + ALT + T keys simultaneously.

2. **Update Package Lists:**
   ```bash
   sudo apt update
   ```

3. **Install C++ Compiler:**
   ```bash
   sudo apt install g++
   ```

4. **Verify Installation:**
   ```bash
   g++ --version
   ```

### For macOS:

1. **Install Xcode Command Line Tools:**
   - Open Terminal by pressing COMMAND and T keys simultaneously and run the following command:
     ```bash
     xcode-select --install
     ```

2. **Install Homebrew (Optional but recommended):**
   - If not installed, you can install [Homebrew](https://brew.sh/), a package manager for macOS.

3. **Install C++ Compiler:**
   ```bash
   brew install gcc
   ```

4. **Verify Installation:**
   ```bash
   g++ --version
   ```

### For Windows:

1. **Install MinGW-W64:**
   - Download and install [MinGW-W64](https://www.mingw-w64.org/downloads/) (Minimalist GNU for Windows).
   - During installation, ensure to select options for C++.

2. **Add MinGW-W64 to System Path:**
   - Add the MinGW-W64 `bin` directory to your system's PATH environment variable.
3. Open command line:

   - Open Windows search and type "CMD" followed by ENTER key 

4. **Verify Installation:**
   ```bash
   g++ --version
   ```

These steps provide a basic setup for compiling C++ code on different operating systems.
Keep in mind that specific details may vary based on your system's configuration.
Refer to the documentation or resources relevant to your operating system for more detailed instructions or email us at `team@opengenus.org` for further guidance.
