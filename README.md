##Getting Started:
If you already have XCode along with its corresponding command-line tools installed on your machine then you should have everything.

Otherwise, you'll want to install XCode from the app store. After installation, open XCode's Preference menu, select Downloads, highlight Command Line Tools and then click "Install".

##To build:
From the root of the project,
```bash
xcodebuild -target Test
```
That should generate both the TTT++ and Test executables and place them in a build/Release directory.

##To run tests:
From build directory,
```bash
cd Release
./Test
```

##To play:
From build directory,
```bash
cd Release
./TTT++
```
