# STM32 Environment Setup

## Programs / Utilities

Required programs :

- **ARM GNU Toolchain** : Includes the cross-compiler, binutils, linker and the associated headers and libraries.
- [**GNU Make**](https://www.gnu.org/software/make/) : All sample codes use make as the build system.
- [**OpenOCD**](https://openocd.org/doc/html/About.html) : Provides remote GDB server to flash and debug the microcontroller.
- Editor : An editor of your choice. Recommended is [Visual Studio Code](https://code.visualstudio.com/download) by Microsoft.

REMARK : The instructions will guide you through setting up the whole environment using VSCode only, since it provides the quickest setup using it's wide library of extensions.

You can create similar experience using (neo)vim, but currently I am not including any instructions here.

Supplemetary programs :

- Clangd : Provides LSP server for C/C++ language linting and intellisense for autocompletions.
- Bear : Clangd requires compilation database to provide it's features, bear generates the `compile_commands.json` file required by clangd.

---

## ARM GNU Toolchain

First download the [ARM GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)  for your platform. 

The webpage provides different configurations cross toolchains based on host and target.

For example, if you are running Windows on an Intel/AMD machine select from "**Windows (mingw-w64-i686) hosted cross toolchains**".

If you are running macOS on Apple silicon(arm64) select from "**macOS (Apple silicon) hosted cross toolchains**".

The target here is specified by a triplet `<arch>`-`<vendor>`-`[kernel]-<eabi>`

- `arm-none-eabi-` Targets arm/aarch32 ie, 32-bit arm processors, has no vendor (none) and uses, does not target an OS and complies with the ARM Embedded ABI.
- `arm-none-linux-gnueabi-` : Targets arm/aarch32 processor, has no vendor, creates binaries that run on Linux OS, and the GNU Embedded ABI.

The key difference is the calling convention and availability of system calls for the C library to use (All these toolchains use Newlib as the C library). The `arm-none-linux-gnueabi` would use Linux system C library to make calls to the kernel.

We are interested in bare-metal programming of STM32 line of SoCs which, as the name suggests, uses a 32-bit ARM processor, so select `arm-none-eabi-` toolchain.

Download the toolchain and extract/install into a directory of your choice (.pkg installer will install in /Applications on macOS).

---

## Linux setup

- Create an appropriate environment variable and add the bin directory to PATH

```cpp
echo "export ARM32_TOOLCHAIN=/Path/to/Toolchain" >> $HOME/.bashrc
echo "export PATH=$ARM32_TOOLCHAIN/bin:$PATH" >> $HOME/.bashrc
source $HOME/.bashrc
```

- Check the binaries

```cpp
arm-none-eabi-gcc --version
```

- Install tools

Debian/Ubuntu systems :

```cpp
sudo apt install make openocd bear clangd
```

Fedora/RHEL based systems :

```cpp
sudo dnf install make openocd bear clang-tools-extra
```

Arch Linux :

```cpp
sudo pacman install make openocd bear clangd
```

## Windows

Install WSL2 :) and repeat the steps in Linux setup section.

For interacting with hardware, you would need to use USB-IPD, since WSL2 does not support USB passthrough.

---

## macOS

clangd and make will be installed automatically with XCode installation or command-line-tools.

Homebrew :

```cpp
brew install open-ocd bear
```

MacPorts :

```cpp
sudo port install openocd bear
```

If you wish to go with a Linux flow, I recommend [UTM](https://github.com/utmapp/UTM) or [OrbStack](https://orbstack.dev)

