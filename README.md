CMake Template of project using nRF52840 with FreeRTOS (temprarily without SofeDevice)
==

This project is based on [nRF5 SDK v17.1.0](https://infocenter.nordicsemi.com/index.jsp?topic=%2Fsdk_nrf5_v16.0.0%2Fnrfx_migration_user_guide.html), you can download the SDK source code and the offline codes on the [official website](https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v17.x.x/).

Directories in nRF5 SDK
==

Before we start to explain the directories in this CMake template, let's first explore what's inside in the nRF5 SDK.

nRF SDK directory tree
--

```
├── components
│   ├── ......
│   ├── libraries           ->        high-level application abstraction codes using nrfx and HAL library, independent of hardware
├── config                  ->        different config files for different nRF5 chip, no need to know how to use it for now because it's duplicated with the files in nrfx module
├── documentation           ->        docs of SDK API reference
├── examples                ->        enumerous app implication using the nRF5 SDK
├── external_tools
├── integration             ->        how to integrate nRFx in your project if you want to use the new nRFx library, basicly reimplment the file in modules/nrfx/templates/nrfx_glue.h
│   └── nrfx
└── modules
    └── nrfx                ->        files of nrfx library, this is basically an independent library. You may use it without any other files in the nRF SDK directory
```

Directories in template project
--

```
Directory
├── compile_files
├── debug_files
├── include
│   ├── commons
│   ├── devices
│   │   └── mcus
│   │       ├── nrf52840
│   │       │   ├── boot
│   │       │   ├── freeRTOS_port
│   │       │   └── it
│   │       └── nrf_commons
│   ├── drivers
│   │   ├── hal
│   │   └── nrfx
│   │       └── prs
│   ├── freeRTOS
│   └── system
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