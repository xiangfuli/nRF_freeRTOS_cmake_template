CMake Template of project using nRF52840 with FreeRTOS (temprarily without SofeDevice)
==

This project is based on [nRF5 SDK v17.1.0](https://infocenter.nordicsemi.com/index.jsp?topic=%2Fsdk_nrf5_v16.0.0%2Fnrfx_migration_user_guide.html) and [FreeRTOS LTS 202012.05](https://www.freertos.org/a00104.html), you can download the SDK source code and the offline codes on the [official website](https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v17.x.x/).

Directories in nRF5 SDK
==

Before we start to explain the directories in this CMake template, let's first explore what's inside in the nRF5 SDK.

nRF SDK directory tree
--

```
├── components
│   ├── ......
│   ├── libraries           ->        high-level application abstraction codes using nRFx and HAL library, independent of hardware
├── config                  ->        different config files for different nRF5 chip, no need to know how to use it for now because it's duplicated with the files in nRFx module
├── documentation           ->        docs of SDK API reference
├── examples                ->        enumerous app implication using the nRF5 SDK
├── external_tools
├── integration             ->        how to integrate nRFx in your project if you want to use the new nRFx library, basicly reimplment the file in modules/nRFx/templates/nRFx_glue.h
│   └── nrfx
└── modules
    └── nrfx                ->        files of nRFx library, this is basically an independent library. You may use it without any other files in the nRF SDK directory
```

Directories in template project
--

```
Directory
├── compile_files                         ->          LD scripts used in linking procedure of compiling process
├── debug_files                           ->          nRF register specification
├── include
│   ├── commons                           ->          (provided by users) common files that could be shared among different modules
│   ├── devices
│   │   └── mcus
│   │       ├── nrf52840
│   │       │   ├── boot                  ->          start up files needed by nrf52840
│   │       │   └── it                    ->          interrupt declaration files
│   │       └── nrf_commons               ->          nRF mcu commonly shared files
│   ├── drivers
│   │   ├── hal                           ->          nRF hardware access layer functions
│   │   └── nrfx                          ->          low-level driver package
│   │       └── prs
│   ├── freeRTOS                          ->          free RTOS files
│   │   ├── freeRTOS_port                 ->          macros used by different compilers
│   └── system                            ->          (provided by users)
└── src
    ├── commons
    ├── devices
    │   └── mcus
    │       ├── nrf52840
    │       │   ├── boot
    │       │   └── freeRTOS_port
    │       └── nrf_commons
    ├── drivers
    │   ├── hal
    │   └── nrfx
    │       └── prs
    ├── freeRTOS
    └── system
```

Build
==

Tools required
--

1. Command line tools
   1. nrfjprog executable - tool for programming through SEGGER J-LINK programmers and debuggers, you can download this tool from the official website: [nRF Command Line Tools](https://www.nordicsemi.com/Products/Development-tools/nrf-command-line-tools/download)
2. Program tools
   1. J-Link


Compile
--

```
mkdir build & make
```

Flash
--

After you have compile the whole project, using following command to flash the executable files

```
cd build & make flash
```




